/*******************************************************************************
* File Name: PWM3_P_2.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PWM3_P_2_ALIASES_H) /* Pins PWM3_P_2_ALIASES_H */
#define CY_PINS_PWM3_P_2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PWM3_P_2_0			(PWM3_P_2__0__PC)
#define PWM3_P_2_0_PS		(PWM3_P_2__0__PS)
#define PWM3_P_2_0_PC		(PWM3_P_2__0__PC)
#define PWM3_P_2_0_DR		(PWM3_P_2__0__DR)
#define PWM3_P_2_0_SHIFT	(PWM3_P_2__0__SHIFT)
#define PWM3_P_2_0_INTR	((uint16)((uint16)0x0003u << (PWM3_P_2__0__SHIFT*2u)))

#define PWM3_P_2_INTR_ALL	 ((uint16)(PWM3_P_2_0_INTR))


#endif /* End Pins PWM3_P_2_ALIASES_H */


/* [] END OF FILE */
