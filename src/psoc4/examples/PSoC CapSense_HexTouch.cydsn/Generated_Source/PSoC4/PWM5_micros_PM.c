/*******************************************************************************
* File Name: PWM5_micros_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM5_micros.h"

static PWM5_micros_BACKUP_STRUCT PWM5_micros_backup;


/*******************************************************************************
* Function Name: PWM5_micros_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM5_micros_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM5_micros_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM5_micros_Sleep(void)
{
    if(0u != (PWM5_micros_BLOCK_CONTROL_REG & PWM5_micros_MASK))
    {
        PWM5_micros_backup.enableState = 1u;
    }
    else
    {
        PWM5_micros_backup.enableState = 0u;
    }

    PWM5_micros_Stop();
    PWM5_micros_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM5_micros_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM5_micros_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM5_micros_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM5_micros_Wakeup(void)
{
    PWM5_micros_RestoreConfig();

    if(0u != PWM5_micros_backup.enableState)
    {
        PWM5_micros_Enable();
    }
}


/* [] END OF FILE */
