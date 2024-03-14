/*******************************************************************************
* File Name: PWM0_P_1.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "PWM0_P_1.h"

static PWM0_P_1_BACKUP_STRUCT  PWM0_P_1_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: PWM0_P_1_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet PWM0_P_1_SUT.c usage_PWM0_P_1_Sleep_Wakeup
*******************************************************************************/
void PWM0_P_1_Sleep(void)
{
    #if defined(PWM0_P_1__PC)
        PWM0_P_1_backup.pcState = PWM0_P_1_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            PWM0_P_1_backup.usbState = PWM0_P_1_CR1_REG;
            PWM0_P_1_USB_POWER_REG |= PWM0_P_1_USBIO_ENTER_SLEEP;
            PWM0_P_1_CR1_REG &= PWM0_P_1_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(PWM0_P_1__SIO)
        PWM0_P_1_backup.sioState = PWM0_P_1_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        PWM0_P_1_SIO_REG &= (uint32)(~PWM0_P_1_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: PWM0_P_1_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to PWM0_P_1_Sleep() for an example usage.
*******************************************************************************/
void PWM0_P_1_Wakeup(void)
{
    #if defined(PWM0_P_1__PC)
        PWM0_P_1_PC = PWM0_P_1_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            PWM0_P_1_USB_POWER_REG &= PWM0_P_1_USBIO_EXIT_SLEEP_PH1;
            PWM0_P_1_CR1_REG = PWM0_P_1_backup.usbState;
            PWM0_P_1_USB_POWER_REG &= PWM0_P_1_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(PWM0_P_1__SIO)
        PWM0_P_1_SIO_REG = PWM0_P_1_backup.sioState;
    #endif
}


/* [] END OF FILE */
