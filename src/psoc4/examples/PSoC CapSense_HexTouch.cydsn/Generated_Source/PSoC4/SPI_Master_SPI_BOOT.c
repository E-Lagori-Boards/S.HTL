/***************************************************************************//**
* \file SPI_Master_SPI_BOOT.c
* \version 4.0
*
* \brief
*  This file provides the source code of the bootloader communication APIs
*  for the SCB Component SPI mode.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPI_Master_BOOT.h"
#include "SPI_Master_SPI_UART.h"

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_Master_SPI_BTLDR_COMM_ENABLED)

/*******************************************************************************
* Function Name: SPI_Master_SpiCyBtldrCommStart
****************************************************************************//**
*
*  Starts the SPI component.
*
*******************************************************************************/
void SPI_Master_SpiCyBtldrCommStart(void)
{
    SPI_Master_Start();
}


/*******************************************************************************
* Function Name: SPI_Master_SpiCyBtldrCommStop
****************************************************************************//**
*
*  Disables the SPI component.
*
*******************************************************************************/
void SPI_Master_SpiCyBtldrCommStop(void)
{
    SPI_Master_Stop();
}


/*******************************************************************************
* Function Name: SPI_Master_SpiCyBtldrCommReset
****************************************************************************//**
*
*  Resets the receive and transmit communication buffers.
*
*******************************************************************************/
void SPI_Master_SpiCyBtldrCommReset(void)
{
    /* Clear RX and TX buffers */
    SPI_Master_SpiUartClearRxBuffer();
    SPI_Master_SpiUartClearTxBuffer();
}


/*******************************************************************************
* Function Name: SPI_Master_SpiCyBtldrCommRead
****************************************************************************//**
*
*  Allows the caller to read data from the bootloader host (the host writes the
*  data). The function handles polling to allow a block of data to be completely
*  received from the host device.
*
*  \param pData: Pointer to storage for the block of data to be read from the
*   bootloader host
*  \param size: Number of bytes to be read.
*  \param count: Pointer to the variable to write the number of bytes actually
*   read.
*  \param timeOut: Number of units in 10 ms to wait before returning
*   because of a timeout.
*
* \return
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem. For more information refer to the
*  "Return Codes" section of the System Reference Guide.
*
*******************************************************************************/
cystatus SPI_Master_SpiCyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;
    uint32 byteCount;
    uint32 timeoutMs;
    uint32 i;

    status = CYRET_BAD_PARAM;

    if ((NULL != pData) && (size > 0u))
    {
        status = CYRET_TIMEOUT;
        timeoutMs = ((uint32) 10u * timeOut); /* Convert from 10mS check to 1mS checks */

        /* Wait with timeout 1mS for packet start */
        byteCount = 0u;
        do
        {
            /* Check packet start */
            if (0u != SPI_Master_SpiUartGetRxBufferSize())
            {
                /* Wait for packet end */
                do
                {
                    byteCount = SPI_Master_SpiUartGetRxBufferSize();
                    CyDelayUs(SPI_Master_SPI_BYTE_TO_BYTE);
                }
                while (byteCount != SPI_Master_SpiUartGetRxBufferSize());

                /* Disable data reception into RX FIFO */
                SPI_Master_RX_FIFO_CTRL_REG |= SPI_Master_RX_FIFO_CTRL_FREEZE;

                byteCount = SPI_Master_BYTES_TO_COPY(byteCount, size);
                *count = (uint16) byteCount;
                status = CYRET_SUCCESS;

                break;
            }

            CyDelay(SPI_Master_WAIT_1_MS);
            --timeoutMs;
        }
        while (0u != timeoutMs);

        /* Get data from the RX buffer into bootloader buffer */
        for (i = 0u; i < byteCount; ++i)
        {
            pData[i] = (uint8) SPI_Master_SpiUartReadRxData();
        }
    }

    return (status);
}


/*******************************************************************************
* Function Name: SPI_Master_SpiCyBtldrCommWrite
****************************************************************************//**
*
*  Allows the caller to read data from the bootloader host (the host writes the
*  data). The function handles polling to allow a block of data to be completely
*  received from the host device.
*
*  \param pData: Pointer to the block of data to be written to the bootloader
*   host.
*  \param size: Number of bytes to be written.
*  \param count: Pointer to the variable to write the number of bytes actually
*   written.
*  \param timeOut: Number of units in 10 ms to wait before returning
*   because of a timeout.
*
*  \return
*   Returns CYRET_SUCCESS if no problem was encountered or returns the value
*   that best describes the problem. For more information refer to the
*   "Return Codes" section of the System Reference Guide.
*
*******************************************************************************/
cystatus SPI_Master_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;
    uint32 timeoutMs;

    status = CYRET_BAD_PARAM;

    if ((NULL != pData) && (size > 0u))
    {
        status = CYRET_TIMEOUT;
        timeoutMs = ((uint32) 10u * timeOut); /* Convert from 10mS check to 1mS checks */

        /* Put data into TX buffer */
        SPI_Master_SpiUartPutArray(pData, (uint32) size);

        /* Wait with timeout 1mS for packet end */
        do
        {
            /* Check for packet end */
            if ((0u == SPI_Master_SpiUartGetTxBufferSize()) &&
                (0u == (SPI_Master_SPI_STATUS_REG & SPI_Master_SPI_STATUS_BUS_BUSY)) &&
                (0u == (SPI_Master_TX_FIFO_STATUS_REG & SPI_Master_TX_FIFO_SR_VALID)))
            {
                *count = size;
                status = CYRET_SUCCESS;

                break;
            }

            CyDelay(SPI_Master_WAIT_1_MS);
            --timeoutMs;
        }
        while (0u != timeoutMs);

        /* Enable data reception into RX FIFO */
        SPI_Master_SpiUartClearRxBuffer();
        SPI_Master_RX_FIFO_CTRL_REG &= (uint32) ~SPI_Master_RX_FIFO_CTRL_FREEZE;
    }

    return (status);
}

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (SPI_Master_SPI_BTLDR_COMM_ENABLED) */


/* [] END OF FILE */
