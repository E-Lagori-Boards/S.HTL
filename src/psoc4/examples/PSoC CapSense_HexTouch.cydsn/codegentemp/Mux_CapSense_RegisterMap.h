/***************************************************************************//**
* \file Mux_CapSense_RegisterMap.h
* \version 7.10
*
* \brief
*   This file provides the definitions for the Component data structure register.
*
* \see Mux_CapSense v7.10 Datasheet
*
*//*****************************************************************************
* Copyright (2016-2019), Cypress Semiconductor Corporation.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*******************************************************************************/

#if !defined(CY_SENSE_Mux_CapSense_REGISTER_MAP_H)
#define CY_SENSE_Mux_CapSense_REGISTER_MAP_H

#include <cytypes.h>
#include "Mux_CapSense_Configuration.h"
#include "Mux_CapSense_Structure.h"

/*****************************************************************************/
/* RAM Data structure register definitions                                   */
/*****************************************************************************/
#define Mux_CapSense_CONFIG_ID_VALUE                        (Mux_CapSense_dsRam.configId)
#define Mux_CapSense_CONFIG_ID_OFFSET                       (0u)
#define Mux_CapSense_CONFIG_ID_SIZE                         (2u)
#define Mux_CapSense_CONFIG_ID_PARAM_ID                     (0x87000000u)

#define Mux_CapSense_DEVICE_ID_VALUE                        (Mux_CapSense_dsRam.deviceId)
#define Mux_CapSense_DEVICE_ID_OFFSET                       (2u)
#define Mux_CapSense_DEVICE_ID_SIZE                         (2u)
#define Mux_CapSense_DEVICE_ID_PARAM_ID                     (0x8B000002u)

#define Mux_CapSense_HW_CLOCK_VALUE                         (Mux_CapSense_dsRam.hwClock)
#define Mux_CapSense_HW_CLOCK_OFFSET                        (4u)
#define Mux_CapSense_HW_CLOCK_SIZE                          (2u)
#define Mux_CapSense_HW_CLOCK_PARAM_ID                      (0x86000004u)

#define Mux_CapSense_TUNER_CMD_VALUE                        (Mux_CapSense_dsRam.tunerCmd)
#define Mux_CapSense_TUNER_CMD_OFFSET                       (6u)
#define Mux_CapSense_TUNER_CMD_SIZE                         (2u)
#define Mux_CapSense_TUNER_CMD_PARAM_ID                     (0xA1000006u)

#define Mux_CapSense_SCAN_COUNTER_VALUE                     (Mux_CapSense_dsRam.scanCounter)
#define Mux_CapSense_SCAN_COUNTER_OFFSET                    (8u)
#define Mux_CapSense_SCAN_COUNTER_SIZE                      (2u)
#define Mux_CapSense_SCAN_COUNTER_PARAM_ID                  (0x85000008u)

#define Mux_CapSense_STATUS_VALUE                           (Mux_CapSense_dsRam.status)
#define Mux_CapSense_STATUS_OFFSET                          (12u)
#define Mux_CapSense_STATUS_SIZE                            (4u)
#define Mux_CapSense_STATUS_PARAM_ID                        (0xCB00000Cu)

#define Mux_CapSense_WDGT_ENABLE0_VALUE                     (Mux_CapSense_dsRam.wdgtEnable[0u])
#define Mux_CapSense_WDGT_ENABLE0_OFFSET                    (16u)
#define Mux_CapSense_WDGT_ENABLE0_SIZE                      (4u)
#define Mux_CapSense_WDGT_ENABLE0_PARAM_ID                  (0xE6000010u)

#define Mux_CapSense_WDGT_STATUS0_VALUE                     (Mux_CapSense_dsRam.wdgtStatus[0u])
#define Mux_CapSense_WDGT_STATUS0_OFFSET                    (20u)
#define Mux_CapSense_WDGT_STATUS0_SIZE                      (4u)
#define Mux_CapSense_WDGT_STATUS0_PARAM_ID                  (0xCC000014u)

#define Mux_CapSense_SNS_STATUS0_VALUE                      (Mux_CapSense_dsRam.snsStatus[0u])
#define Mux_CapSense_SNS_STATUS0_OFFSET                     (24u)
#define Mux_CapSense_SNS_STATUS0_SIZE                       (1u)
#define Mux_CapSense_SNS_STATUS0_PARAM_ID                   (0x48000018u)

#define Mux_CapSense_CSD0_CONFIG_VALUE                      (Mux_CapSense_dsRam.csd0Config)
#define Mux_CapSense_CSD0_CONFIG_OFFSET                     (26u)
#define Mux_CapSense_CSD0_CONFIG_SIZE                       (2u)
#define Mux_CapSense_CSD0_CONFIG_PARAM_ID                   (0xAA80001Au)

#define Mux_CapSense_MOD_CSD_CLK_VALUE                      (Mux_CapSense_dsRam.modCsdClk)
#define Mux_CapSense_MOD_CSD_CLK_OFFSET                     (28u)
#define Mux_CapSense_MOD_CSD_CLK_SIZE                       (1u)
#define Mux_CapSense_MOD_CSD_CLK_PARAM_ID                   (0x6F80001Cu)

#define Mux_CapSense_MATRIXBUTTONS0_RESOLUTION_VALUE        (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.resolution)
#define Mux_CapSense_MATRIXBUTTONS0_RESOLUTION_OFFSET       (30u)
#define Mux_CapSense_MATRIXBUTTONS0_RESOLUTION_SIZE         (2u)
#define Mux_CapSense_MATRIXBUTTONS0_RESOLUTION_PARAM_ID     (0xAB80001Eu)

#define Mux_CapSense_MATRIXBUTTONS0_FINGER_TH_VALUE         (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.fingerTh)
#define Mux_CapSense_MATRIXBUTTONS0_FINGER_TH_OFFSET        (32u)
#define Mux_CapSense_MATRIXBUTTONS0_FINGER_TH_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_FINGER_TH_PARAM_ID      (0xAB800020u)

#define Mux_CapSense_MATRIXBUTTONS0_NOISE_TH_VALUE          (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.noiseTh)
#define Mux_CapSense_MATRIXBUTTONS0_NOISE_TH_OFFSET         (34u)
#define Mux_CapSense_MATRIXBUTTONS0_NOISE_TH_SIZE           (1u)
#define Mux_CapSense_MATRIXBUTTONS0_NOISE_TH_PARAM_ID       (0x6F800022u)

#define Mux_CapSense_MATRIXBUTTONS0_NNOISE_TH_VALUE         (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.nNoiseTh)
#define Mux_CapSense_MATRIXBUTTONS0_NNOISE_TH_OFFSET        (35u)
#define Mux_CapSense_MATRIXBUTTONS0_NNOISE_TH_SIZE          (1u)
#define Mux_CapSense_MATRIXBUTTONS0_NNOISE_TH_PARAM_ID      (0x69800023u)

#define Mux_CapSense_MATRIXBUTTONS0_HYSTERESIS_VALUE        (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.hysteresis)
#define Mux_CapSense_MATRIXBUTTONS0_HYSTERESIS_OFFSET       (36u)
#define Mux_CapSense_MATRIXBUTTONS0_HYSTERESIS_SIZE         (1u)
#define Mux_CapSense_MATRIXBUTTONS0_HYSTERESIS_PARAM_ID     (0x62800024u)

#define Mux_CapSense_MATRIXBUTTONS0_ON_DEBOUNCE_VALUE       (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.onDebounce)
#define Mux_CapSense_MATRIXBUTTONS0_ON_DEBOUNCE_OFFSET      (37u)
#define Mux_CapSense_MATRIXBUTTONS0_ON_DEBOUNCE_SIZE        (1u)
#define Mux_CapSense_MATRIXBUTTONS0_ON_DEBOUNCE_PARAM_ID    (0x64800025u)

#define Mux_CapSense_MATRIXBUTTONS0_LOW_BSLN_RST_VALUE      (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.lowBslnRst)
#define Mux_CapSense_MATRIXBUTTONS0_LOW_BSLN_RST_OFFSET     (38u)
#define Mux_CapSense_MATRIXBUTTONS0_LOW_BSLN_RST_SIZE       (1u)
#define Mux_CapSense_MATRIXBUTTONS0_LOW_BSLN_RST_PARAM_ID   (0x6E800026u)

#define Mux_CapSense_MATRIXBUTTONS0_IDAC_MOD0_VALUE         (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.idacMod[0u])
#define Mux_CapSense_MATRIXBUTTONS0_IDAC_MOD0_OFFSET        (39u)
#define Mux_CapSense_MATRIXBUTTONS0_IDAC_MOD0_SIZE          (1u)
#define Mux_CapSense_MATRIXBUTTONS0_IDAC_MOD0_PARAM_ID      (0x4E000027u)

#define Mux_CapSense_MATRIXBUTTONS0_ROW_IDAC_MOD0_VALUE     (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.rowIdacMod[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW_IDAC_MOD0_OFFSET    (40u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW_IDAC_MOD0_SIZE      (1u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW_IDAC_MOD0_PARAM_ID  (0x47000028u)

#define Mux_CapSense_MATRIXBUTTONS0_IDAC_GAIN_INDEX_VALUE   (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.idacGainIndex)
#define Mux_CapSense_MATRIXBUTTONS0_IDAC_GAIN_INDEX_OFFSET  (41u)
#define Mux_CapSense_MATRIXBUTTONS0_IDAC_GAIN_INDEX_SIZE    (1u)
#define Mux_CapSense_MATRIXBUTTONS0_IDAC_GAIN_INDEX_PARAM_ID (0x4C800029u)

#define Mux_CapSense_MATRIXBUTTONS0_SNS_CLK_VALUE           (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.snsClk)
#define Mux_CapSense_MATRIXBUTTONS0_SNS_CLK_OFFSET          (42u)
#define Mux_CapSense_MATRIXBUTTONS0_SNS_CLK_SIZE            (2u)
#define Mux_CapSense_MATRIXBUTTONS0_SNS_CLK_PARAM_ID        (0xA580002Au)

#define Mux_CapSense_MATRIXBUTTONS0_ROW_SNS_CLK_VALUE       (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.rowSnsClk)
#define Mux_CapSense_MATRIXBUTTONS0_ROW_SNS_CLK_OFFSET      (44u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW_SNS_CLK_SIZE        (2u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW_SNS_CLK_PARAM_ID    (0xA880002Cu)

#define Mux_CapSense_MATRIXBUTTONS0_SNS_CLK_SOURCE_VALUE    (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.snsClkSource)
#define Mux_CapSense_MATRIXBUTTONS0_SNS_CLK_SOURCE_OFFSET   (46u)
#define Mux_CapSense_MATRIXBUTTONS0_SNS_CLK_SOURCE_SIZE     (1u)
#define Mux_CapSense_MATRIXBUTTONS0_SNS_CLK_SOURCE_PARAM_ID (0x4780002Eu)

#define Mux_CapSense_MATRIXBUTTONS0_ROW_SNS_CLK_SOURCE_VALUE (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.rowSnsClkSource)
#define Mux_CapSense_MATRIXBUTTONS0_ROW_SNS_CLK_SOURCE_OFFSET (47u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW_SNS_CLK_SOURCE_SIZE (1u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW_SNS_CLK_SOURCE_PARAM_ID (0x4180002Fu)

#define Mux_CapSense_MATRIXBUTTONS0_POS_COL_VALUE           (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.posCol)
#define Mux_CapSense_MATRIXBUTTONS0_POS_COL_OFFSET          (48u)
#define Mux_CapSense_MATRIXBUTTONS0_POS_COL_SIZE            (1u)
#define Mux_CapSense_MATRIXBUTTONS0_POS_COL_PARAM_ID        (0x40000030u)

#define Mux_CapSense_MATRIXBUTTONS0_POS_ROW_VALUE           (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.posRow)
#define Mux_CapSense_MATRIXBUTTONS0_POS_ROW_OFFSET          (49u)
#define Mux_CapSense_MATRIXBUTTONS0_POS_ROW_SIZE            (1u)
#define Mux_CapSense_MATRIXBUTTONS0_POS_ROW_PARAM_ID        (0x46000031u)

#define Mux_CapSense_MATRIXBUTTONS0_POS_SNS_ID_VALUE        (Mux_CapSense_dsRam.wdgtList.matrixbuttons0.posSnsId)
#define Mux_CapSense_MATRIXBUTTONS0_POS_SNS_ID_OFFSET       (50u)
#define Mux_CapSense_MATRIXBUTTONS0_POS_SNS_ID_SIZE         (1u)
#define Mux_CapSense_MATRIXBUTTONS0_POS_SNS_ID_PARAM_ID     (0x4C000032u)

#define Mux_CapSense_MATRIXBUTTONS0_COL0_RAW0_VALUE         (Mux_CapSense_dsRam.snsList.matrixbuttons0[0u].raw[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL0_RAW0_OFFSET        (52u)
#define Mux_CapSense_MATRIXBUTTONS0_COL0_RAW0_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_COL0_RAW0_PARAM_ID      (0x89000034u)

#define Mux_CapSense_MATRIXBUTTONS0_COL0_BSLN0_VALUE        (Mux_CapSense_dsRam.snsList.matrixbuttons0[0u].bsln[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL0_BSLN0_OFFSET       (54u)
#define Mux_CapSense_MATRIXBUTTONS0_COL0_BSLN0_SIZE         (2u)
#define Mux_CapSense_MATRIXBUTTONS0_COL0_BSLN0_PARAM_ID     (0x85000036u)

#define Mux_CapSense_MATRIXBUTTONS0_COL0_BSLN_EXT0_VALUE    (Mux_CapSense_dsRam.snsList.matrixbuttons0[0u].bslnExt[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL0_BSLN_EXT0_OFFSET   (56u)
#define Mux_CapSense_MATRIXBUTTONS0_COL0_BSLN_EXT0_SIZE     (1u)
#define Mux_CapSense_MATRIXBUTTONS0_COL0_BSLN_EXT0_PARAM_ID (0x42000038u)

#define Mux_CapSense_MATRIXBUTTONS0_COL0_DIFF_VALUE         (Mux_CapSense_dsRam.snsList.matrixbuttons0[0u].diff)
#define Mux_CapSense_MATRIXBUTTONS0_COL0_DIFF_OFFSET        (58u)
#define Mux_CapSense_MATRIXBUTTONS0_COL0_DIFF_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_COL0_DIFF_PARAM_ID      (0x8600003Au)

#define Mux_CapSense_MATRIXBUTTONS0_COL0_NEG_BSLN_RST_CNT0_VALUE (Mux_CapSense_dsRam.snsList.matrixbuttons0[0u].negBslnRstCnt[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL0_NEG_BSLN_RST_CNT0_OFFSET (60u)
#define Mux_CapSense_MATRIXBUTTONS0_COL0_NEG_BSLN_RST_CNT0_SIZE (1u)
#define Mux_CapSense_MATRIXBUTTONS0_COL0_NEG_BSLN_RST_CNT0_PARAM_ID (0x4300003Cu)

#define Mux_CapSense_MATRIXBUTTONS0_COL0_IDAC_COMP0_VALUE   (Mux_CapSense_dsRam.snsList.matrixbuttons0[0u].idacComp[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL0_IDAC_COMP0_OFFSET  (61u)
#define Mux_CapSense_MATRIXBUTTONS0_COL0_IDAC_COMP0_SIZE    (1u)
#define Mux_CapSense_MATRIXBUTTONS0_COL0_IDAC_COMP0_PARAM_ID (0x4500003Du)

#define Mux_CapSense_MATRIXBUTTONS0_COL1_RAW0_VALUE         (Mux_CapSense_dsRam.snsList.matrixbuttons0[1u].raw[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL1_RAW0_OFFSET        (62u)
#define Mux_CapSense_MATRIXBUTTONS0_COL1_RAW0_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_COL1_RAW0_PARAM_ID      (0x8700003Eu)

#define Mux_CapSense_MATRIXBUTTONS0_COL1_BSLN0_VALUE        (Mux_CapSense_dsRam.snsList.matrixbuttons0[1u].bsln[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL1_BSLN0_OFFSET       (64u)
#define Mux_CapSense_MATRIXBUTTONS0_COL1_BSLN0_SIZE         (2u)
#define Mux_CapSense_MATRIXBUTTONS0_COL1_BSLN0_PARAM_ID     (0x8A000040u)

#define Mux_CapSense_MATRIXBUTTONS0_COL1_BSLN_EXT0_VALUE    (Mux_CapSense_dsRam.snsList.matrixbuttons0[1u].bslnExt[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL1_BSLN_EXT0_OFFSET   (66u)
#define Mux_CapSense_MATRIXBUTTONS0_COL1_BSLN_EXT0_SIZE     (1u)
#define Mux_CapSense_MATRIXBUTTONS0_COL1_BSLN_EXT0_PARAM_ID (0x4E000042u)

#define Mux_CapSense_MATRIXBUTTONS0_COL1_DIFF_VALUE         (Mux_CapSense_dsRam.snsList.matrixbuttons0[1u].diff)
#define Mux_CapSense_MATRIXBUTTONS0_COL1_DIFF_OFFSET        (68u)
#define Mux_CapSense_MATRIXBUTTONS0_COL1_DIFF_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_COL1_DIFF_PARAM_ID      (0x8B000044u)

#define Mux_CapSense_MATRIXBUTTONS0_COL1_NEG_BSLN_RST_CNT0_VALUE (Mux_CapSense_dsRam.snsList.matrixbuttons0[1u].negBslnRstCnt[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL1_NEG_BSLN_RST_CNT0_OFFSET (70u)
#define Mux_CapSense_MATRIXBUTTONS0_COL1_NEG_BSLN_RST_CNT0_SIZE (1u)
#define Mux_CapSense_MATRIXBUTTONS0_COL1_NEG_BSLN_RST_CNT0_PARAM_ID (0x4F000046u)

#define Mux_CapSense_MATRIXBUTTONS0_COL1_IDAC_COMP0_VALUE   (Mux_CapSense_dsRam.snsList.matrixbuttons0[1u].idacComp[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL1_IDAC_COMP0_OFFSET  (71u)
#define Mux_CapSense_MATRIXBUTTONS0_COL1_IDAC_COMP0_SIZE    (1u)
#define Mux_CapSense_MATRIXBUTTONS0_COL1_IDAC_COMP0_PARAM_ID (0x49000047u)

#define Mux_CapSense_MATRIXBUTTONS0_COL2_RAW0_VALUE         (Mux_CapSense_dsRam.snsList.matrixbuttons0[2u].raw[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL2_RAW0_OFFSET        (72u)
#define Mux_CapSense_MATRIXBUTTONS0_COL2_RAW0_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_COL2_RAW0_PARAM_ID      (0x88000048u)

#define Mux_CapSense_MATRIXBUTTONS0_COL2_BSLN0_VALUE        (Mux_CapSense_dsRam.snsList.matrixbuttons0[2u].bsln[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL2_BSLN0_OFFSET       (74u)
#define Mux_CapSense_MATRIXBUTTONS0_COL2_BSLN0_SIZE         (2u)
#define Mux_CapSense_MATRIXBUTTONS0_COL2_BSLN0_PARAM_ID     (0x8400004Au)

#define Mux_CapSense_MATRIXBUTTONS0_COL2_BSLN_EXT0_VALUE    (Mux_CapSense_dsRam.snsList.matrixbuttons0[2u].bslnExt[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL2_BSLN_EXT0_OFFSET   (76u)
#define Mux_CapSense_MATRIXBUTTONS0_COL2_BSLN_EXT0_SIZE     (1u)
#define Mux_CapSense_MATRIXBUTTONS0_COL2_BSLN_EXT0_PARAM_ID (0x4100004Cu)

#define Mux_CapSense_MATRIXBUTTONS0_COL2_DIFF_VALUE         (Mux_CapSense_dsRam.snsList.matrixbuttons0[2u].diff)
#define Mux_CapSense_MATRIXBUTTONS0_COL2_DIFF_OFFSET        (78u)
#define Mux_CapSense_MATRIXBUTTONS0_COL2_DIFF_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_COL2_DIFF_PARAM_ID      (0x8500004Eu)

#define Mux_CapSense_MATRIXBUTTONS0_COL2_NEG_BSLN_RST_CNT0_VALUE (Mux_CapSense_dsRam.snsList.matrixbuttons0[2u].negBslnRstCnt[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL2_NEG_BSLN_RST_CNT0_OFFSET (80u)
#define Mux_CapSense_MATRIXBUTTONS0_COL2_NEG_BSLN_RST_CNT0_SIZE (1u)
#define Mux_CapSense_MATRIXBUTTONS0_COL2_NEG_BSLN_RST_CNT0_PARAM_ID (0x47000050u)

#define Mux_CapSense_MATRIXBUTTONS0_COL2_IDAC_COMP0_VALUE   (Mux_CapSense_dsRam.snsList.matrixbuttons0[2u].idacComp[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL2_IDAC_COMP0_OFFSET  (81u)
#define Mux_CapSense_MATRIXBUTTONS0_COL2_IDAC_COMP0_SIZE    (1u)
#define Mux_CapSense_MATRIXBUTTONS0_COL2_IDAC_COMP0_PARAM_ID (0x41000051u)

#define Mux_CapSense_MATRIXBUTTONS0_COL3_RAW0_VALUE         (Mux_CapSense_dsRam.snsList.matrixbuttons0[3u].raw[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL3_RAW0_OFFSET        (82u)
#define Mux_CapSense_MATRIXBUTTONS0_COL3_RAW0_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_COL3_RAW0_PARAM_ID      (0x83000052u)

#define Mux_CapSense_MATRIXBUTTONS0_COL3_BSLN0_VALUE        (Mux_CapSense_dsRam.snsList.matrixbuttons0[3u].bsln[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL3_BSLN0_OFFSET       (84u)
#define Mux_CapSense_MATRIXBUTTONS0_COL3_BSLN0_SIZE         (2u)
#define Mux_CapSense_MATRIXBUTTONS0_COL3_BSLN0_PARAM_ID     (0x8E000054u)

#define Mux_CapSense_MATRIXBUTTONS0_COL3_BSLN_EXT0_VALUE    (Mux_CapSense_dsRam.snsList.matrixbuttons0[3u].bslnExt[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL3_BSLN_EXT0_OFFSET   (86u)
#define Mux_CapSense_MATRIXBUTTONS0_COL3_BSLN_EXT0_SIZE     (1u)
#define Mux_CapSense_MATRIXBUTTONS0_COL3_BSLN_EXT0_PARAM_ID (0x4A000056u)

#define Mux_CapSense_MATRIXBUTTONS0_COL3_DIFF_VALUE         (Mux_CapSense_dsRam.snsList.matrixbuttons0[3u].diff)
#define Mux_CapSense_MATRIXBUTTONS0_COL3_DIFF_OFFSET        (88u)
#define Mux_CapSense_MATRIXBUTTONS0_COL3_DIFF_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_COL3_DIFF_PARAM_ID      (0x8D000058u)

#define Mux_CapSense_MATRIXBUTTONS0_COL3_NEG_BSLN_RST_CNT0_VALUE (Mux_CapSense_dsRam.snsList.matrixbuttons0[3u].negBslnRstCnt[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL3_NEG_BSLN_RST_CNT0_OFFSET (90u)
#define Mux_CapSense_MATRIXBUTTONS0_COL3_NEG_BSLN_RST_CNT0_SIZE (1u)
#define Mux_CapSense_MATRIXBUTTONS0_COL3_NEG_BSLN_RST_CNT0_PARAM_ID (0x4900005Au)

#define Mux_CapSense_MATRIXBUTTONS0_COL3_IDAC_COMP0_VALUE   (Mux_CapSense_dsRam.snsList.matrixbuttons0[3u].idacComp[0u])
#define Mux_CapSense_MATRIXBUTTONS0_COL3_IDAC_COMP0_OFFSET  (91u)
#define Mux_CapSense_MATRIXBUTTONS0_COL3_IDAC_COMP0_SIZE    (1u)
#define Mux_CapSense_MATRIXBUTTONS0_COL3_IDAC_COMP0_PARAM_ID (0x4F00005Bu)

#define Mux_CapSense_MATRIXBUTTONS0_ROW0_RAW0_VALUE         (Mux_CapSense_dsRam.snsList.matrixbuttons0[4u].raw[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_RAW0_OFFSET        (92u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_RAW0_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_RAW0_PARAM_ID      (0x8C00005Cu)

#define Mux_CapSense_MATRIXBUTTONS0_ROW0_BSLN0_VALUE        (Mux_CapSense_dsRam.snsList.matrixbuttons0[4u].bsln[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_BSLN0_OFFSET       (94u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_BSLN0_SIZE         (2u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_BSLN0_PARAM_ID     (0x8000005Eu)

#define Mux_CapSense_MATRIXBUTTONS0_ROW0_BSLN_EXT0_VALUE    (Mux_CapSense_dsRam.snsList.matrixbuttons0[4u].bslnExt[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_BSLN_EXT0_OFFSET   (96u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_BSLN_EXT0_SIZE     (1u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_BSLN_EXT0_PARAM_ID (0x48000060u)

#define Mux_CapSense_MATRIXBUTTONS0_ROW0_DIFF_VALUE         (Mux_CapSense_dsRam.snsList.matrixbuttons0[4u].diff)
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_DIFF_OFFSET        (98u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_DIFF_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_DIFF_PARAM_ID      (0x8C000062u)

#define Mux_CapSense_MATRIXBUTTONS0_ROW0_NEG_BSLN_RST_CNT0_VALUE (Mux_CapSense_dsRam.snsList.matrixbuttons0[4u].negBslnRstCnt[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_NEG_BSLN_RST_CNT0_OFFSET (100u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_NEG_BSLN_RST_CNT0_SIZE (1u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_NEG_BSLN_RST_CNT0_PARAM_ID (0x49000064u)

#define Mux_CapSense_MATRIXBUTTONS0_ROW0_IDAC_COMP0_VALUE   (Mux_CapSense_dsRam.snsList.matrixbuttons0[4u].idacComp[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_IDAC_COMP0_OFFSET  (101u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_IDAC_COMP0_SIZE    (1u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_IDAC_COMP0_PARAM_ID (0x4F000065u)

#define Mux_CapSense_MATRIXBUTTONS0_ROW1_RAW0_VALUE         (Mux_CapSense_dsRam.snsList.matrixbuttons0[5u].raw[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_RAW0_OFFSET        (102u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_RAW0_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_RAW0_PARAM_ID      (0x8D000066u)

#define Mux_CapSense_MATRIXBUTTONS0_ROW1_BSLN0_VALUE        (Mux_CapSense_dsRam.snsList.matrixbuttons0[5u].bsln[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_BSLN0_OFFSET       (104u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_BSLN0_SIZE         (2u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_BSLN0_PARAM_ID     (0x82000068u)

#define Mux_CapSense_MATRIXBUTTONS0_ROW1_BSLN_EXT0_VALUE    (Mux_CapSense_dsRam.snsList.matrixbuttons0[5u].bslnExt[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_BSLN_EXT0_OFFSET   (106u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_BSLN_EXT0_SIZE     (1u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_BSLN_EXT0_PARAM_ID (0x4600006Au)

#define Mux_CapSense_MATRIXBUTTONS0_ROW1_DIFF_VALUE         (Mux_CapSense_dsRam.snsList.matrixbuttons0[5u].diff)
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_DIFF_OFFSET        (108u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_DIFF_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_DIFF_PARAM_ID      (0x8300006Cu)

#define Mux_CapSense_MATRIXBUTTONS0_ROW1_NEG_BSLN_RST_CNT0_VALUE (Mux_CapSense_dsRam.snsList.matrixbuttons0[5u].negBslnRstCnt[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_NEG_BSLN_RST_CNT0_OFFSET (110u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_NEG_BSLN_RST_CNT0_SIZE (1u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_NEG_BSLN_RST_CNT0_PARAM_ID (0x4700006Eu)

#define Mux_CapSense_MATRIXBUTTONS0_ROW1_IDAC_COMP0_VALUE   (Mux_CapSense_dsRam.snsList.matrixbuttons0[5u].idacComp[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_IDAC_COMP0_OFFSET  (111u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_IDAC_COMP0_SIZE    (1u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_IDAC_COMP0_PARAM_ID (0x4100006Fu)

#define Mux_CapSense_MATRIXBUTTONS0_ROW2_RAW0_VALUE         (Mux_CapSense_dsRam.snsList.matrixbuttons0[6u].raw[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_RAW0_OFFSET        (112u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_RAW0_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_RAW0_PARAM_ID      (0x85000070u)

#define Mux_CapSense_MATRIXBUTTONS0_ROW2_BSLN0_VALUE        (Mux_CapSense_dsRam.snsList.matrixbuttons0[6u].bsln[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_BSLN0_OFFSET       (114u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_BSLN0_SIZE         (2u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_BSLN0_PARAM_ID     (0x89000072u)

#define Mux_CapSense_MATRIXBUTTONS0_ROW2_BSLN_EXT0_VALUE    (Mux_CapSense_dsRam.snsList.matrixbuttons0[6u].bslnExt[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_BSLN_EXT0_OFFSET   (116u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_BSLN_EXT0_SIZE     (1u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_BSLN_EXT0_PARAM_ID (0x4C000074u)

#define Mux_CapSense_MATRIXBUTTONS0_ROW2_DIFF_VALUE         (Mux_CapSense_dsRam.snsList.matrixbuttons0[6u].diff)
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_DIFF_OFFSET        (118u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_DIFF_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_DIFF_PARAM_ID      (0x88000076u)

#define Mux_CapSense_MATRIXBUTTONS0_ROW2_NEG_BSLN_RST_CNT0_VALUE (Mux_CapSense_dsRam.snsList.matrixbuttons0[6u].negBslnRstCnt[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_NEG_BSLN_RST_CNT0_OFFSET (120u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_NEG_BSLN_RST_CNT0_SIZE (1u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_NEG_BSLN_RST_CNT0_PARAM_ID (0x4F000078u)

#define Mux_CapSense_MATRIXBUTTONS0_ROW2_IDAC_COMP0_VALUE   (Mux_CapSense_dsRam.snsList.matrixbuttons0[6u].idacComp[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_IDAC_COMP0_OFFSET  (121u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_IDAC_COMP0_SIZE    (1u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_IDAC_COMP0_PARAM_ID (0x49000079u)

#define Mux_CapSense_MATRIXBUTTONS0_ROW3_RAW0_VALUE         (Mux_CapSense_dsRam.snsList.matrixbuttons0[7u].raw[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_RAW0_OFFSET        (122u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_RAW0_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_RAW0_PARAM_ID      (0x8B00007Au)

#define Mux_CapSense_MATRIXBUTTONS0_ROW3_BSLN0_VALUE        (Mux_CapSense_dsRam.snsList.matrixbuttons0[7u].bsln[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_BSLN0_OFFSET       (124u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_BSLN0_SIZE         (2u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_BSLN0_PARAM_ID     (0x8600007Cu)

#define Mux_CapSense_MATRIXBUTTONS0_ROW3_BSLN_EXT0_VALUE    (Mux_CapSense_dsRam.snsList.matrixbuttons0[7u].bslnExt[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_BSLN_EXT0_OFFSET   (126u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_BSLN_EXT0_SIZE     (1u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_BSLN_EXT0_PARAM_ID (0x4200007Eu)

#define Mux_CapSense_MATRIXBUTTONS0_ROW3_DIFF_VALUE         (Mux_CapSense_dsRam.snsList.matrixbuttons0[7u].diff)
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_DIFF_OFFSET        (128u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_DIFF_SIZE          (2u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_DIFF_PARAM_ID      (0x84000080u)

#define Mux_CapSense_MATRIXBUTTONS0_ROW3_NEG_BSLN_RST_CNT0_VALUE (Mux_CapSense_dsRam.snsList.matrixbuttons0[7u].negBslnRstCnt[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_NEG_BSLN_RST_CNT0_OFFSET (130u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_NEG_BSLN_RST_CNT0_SIZE (1u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_NEG_BSLN_RST_CNT0_PARAM_ID (0x40000082u)

#define Mux_CapSense_MATRIXBUTTONS0_ROW3_IDAC_COMP0_VALUE   (Mux_CapSense_dsRam.snsList.matrixbuttons0[7u].idacComp[0u])
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_IDAC_COMP0_OFFSET  (131u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_IDAC_COMP0_SIZE    (1u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_IDAC_COMP0_PARAM_ID (0x46000083u)

#define Mux_CapSense_SNR_TEST_WIDGET_ID_VALUE               (Mux_CapSense_dsRam.snrTestWidgetId)
#define Mux_CapSense_SNR_TEST_WIDGET_ID_OFFSET              (132u)
#define Mux_CapSense_SNR_TEST_WIDGET_ID_SIZE                (1u)
#define Mux_CapSense_SNR_TEST_WIDGET_ID_PARAM_ID            (0x66000084u)

#define Mux_CapSense_SNR_TEST_SENSOR_ID_VALUE               (Mux_CapSense_dsRam.snrTestSensorId)
#define Mux_CapSense_SNR_TEST_SENSOR_ID_OFFSET              (133u)
#define Mux_CapSense_SNR_TEST_SENSOR_ID_SIZE                (1u)
#define Mux_CapSense_SNR_TEST_SENSOR_ID_PARAM_ID            (0x60000085u)

#define Mux_CapSense_SNR_TEST_SCAN_COUNTER_VALUE            (Mux_CapSense_dsRam.snrTestScanCounter)
#define Mux_CapSense_SNR_TEST_SCAN_COUNTER_OFFSET           (134u)
#define Mux_CapSense_SNR_TEST_SCAN_COUNTER_SIZE             (2u)
#define Mux_CapSense_SNR_TEST_SCAN_COUNTER_PARAM_ID         (0x89000086u)

#define Mux_CapSense_SNR_TEST_RAW_COUNT0_VALUE              (Mux_CapSense_dsRam.snrTestRawCount[0u])
#define Mux_CapSense_SNR_TEST_RAW_COUNT0_OFFSET             (136u)
#define Mux_CapSense_SNR_TEST_RAW_COUNT0_SIZE               (2u)
#define Mux_CapSense_SNR_TEST_RAW_COUNT0_PARAM_ID           (0x86000088u)

#define Mux_CapSense_SCAN_CSD_ISC_VALUE                     (Mux_CapSense_dsRam.scanCsdISC)
#define Mux_CapSense_SCAN_CSD_ISC_OFFSET                    (138u)
#define Mux_CapSense_SCAN_CSD_ISC_SIZE                      (1u)
#define Mux_CapSense_SCAN_CSD_ISC_PARAM_ID                  (0x4200008Au)

#define Mux_CapSense_SCAN_CURRENT_ISC_VALUE                 (Mux_CapSense_dsRam.scanCurrentISC)
#define Mux_CapSense_SCAN_CURRENT_ISC_OFFSET                (139u)
#define Mux_CapSense_SCAN_CURRENT_ISC_SIZE                  (1u)
#define Mux_CapSense_SCAN_CURRENT_ISC_PARAM_ID              (0x4400008Bu)


/*****************************************************************************/
/* Flash Data structure register definitions                                 */
/*****************************************************************************/
#define Mux_CapSense_MATRIXBUTTONS0_PTR2SNS_FLASH_VALUE     (Mux_CapSense_dsFlash.wdgtArray[0].ptr2SnsFlash)
#define Mux_CapSense_MATRIXBUTTONS0_PTR2SNS_FLASH_OFFSET    (0u)
#define Mux_CapSense_MATRIXBUTTONS0_PTR2SNS_FLASH_SIZE      (4u)
#define Mux_CapSense_MATRIXBUTTONS0_PTR2SNS_FLASH_PARAM_ID  (0xD1000000u)

#define Mux_CapSense_MATRIXBUTTONS0_PTR2WD_RAM_VALUE        (Mux_CapSense_dsFlash.wdgtArray[0].ptr2WdgtRam)
#define Mux_CapSense_MATRIXBUTTONS0_PTR2WD_RAM_OFFSET       (4u)
#define Mux_CapSense_MATRIXBUTTONS0_PTR2WD_RAM_SIZE         (4u)
#define Mux_CapSense_MATRIXBUTTONS0_PTR2WD_RAM_PARAM_ID     (0xD0000004u)

#define Mux_CapSense_MATRIXBUTTONS0_PTR2SNS_RAM_VALUE       (Mux_CapSense_dsFlash.wdgtArray[0].ptr2SnsRam)
#define Mux_CapSense_MATRIXBUTTONS0_PTR2SNS_RAM_OFFSET      (8u)
#define Mux_CapSense_MATRIXBUTTONS0_PTR2SNS_RAM_SIZE        (4u)
#define Mux_CapSense_MATRIXBUTTONS0_PTR2SNS_RAM_PARAM_ID    (0xD3000008u)

#define Mux_CapSense_MATRIXBUTTONS0_PTR2FLTR_HISTORY_VALUE  (Mux_CapSense_dsFlash.wdgtArray[0].ptr2FltrHistory)
#define Mux_CapSense_MATRIXBUTTONS0_PTR2FLTR_HISTORY_OFFSET (12u)
#define Mux_CapSense_MATRIXBUTTONS0_PTR2FLTR_HISTORY_SIZE   (4u)
#define Mux_CapSense_MATRIXBUTTONS0_PTR2FLTR_HISTORY_PARAM_ID (0xD200000Cu)

#define Mux_CapSense_MATRIXBUTTONS0_PTR2DEBOUNCE_VALUE      (Mux_CapSense_dsFlash.wdgtArray[0].ptr2DebounceArr)
#define Mux_CapSense_MATRIXBUTTONS0_PTR2DEBOUNCE_OFFSET     (16u)
#define Mux_CapSense_MATRIXBUTTONS0_PTR2DEBOUNCE_SIZE       (4u)
#define Mux_CapSense_MATRIXBUTTONS0_PTR2DEBOUNCE_PARAM_ID   (0xD4000010u)

#define Mux_CapSense_MATRIXBUTTONS0_STATIC_CONFIG_VALUE     (Mux_CapSense_dsFlash.wdgtArray[0].staticConfig)
#define Mux_CapSense_MATRIXBUTTONS0_STATIC_CONFIG_OFFSET    (20u)
#define Mux_CapSense_MATRIXBUTTONS0_STATIC_CONFIG_SIZE      (4u)
#define Mux_CapSense_MATRIXBUTTONS0_STATIC_CONFIG_PARAM_ID  (0xD5000014u)

#define Mux_CapSense_MATRIXBUTTONS0_TOTAL_NUM_SNS_VALUE     (Mux_CapSense_dsFlash.wdgtArray[0].totalNumSns)
#define Mux_CapSense_MATRIXBUTTONS0_TOTAL_NUM_SNS_OFFSET    (24u)
#define Mux_CapSense_MATRIXBUTTONS0_TOTAL_NUM_SNS_SIZE      (2u)
#define Mux_CapSense_MATRIXBUTTONS0_TOTAL_NUM_SNS_PARAM_ID  (0x99000018u)

#define Mux_CapSense_MATRIXBUTTONS0_TYPE_VALUE              (Mux_CapSense_dsFlash.wdgtArray[0].wdgtType)
#define Mux_CapSense_MATRIXBUTTONS0_TYPE_OFFSET             (26u)
#define Mux_CapSense_MATRIXBUTTONS0_TYPE_SIZE               (1u)
#define Mux_CapSense_MATRIXBUTTONS0_TYPE_PARAM_ID           (0x5D00001Au)

#define Mux_CapSense_MATRIXBUTTONS0_NUM_COLS_VALUE          (Mux_CapSense_dsFlash.wdgtArray[0].numCols)
#define Mux_CapSense_MATRIXBUTTONS0_NUM_COLS_OFFSET         (27u)
#define Mux_CapSense_MATRIXBUTTONS0_NUM_COLS_SIZE           (1u)
#define Mux_CapSense_MATRIXBUTTONS0_NUM_COLS_PARAM_ID       (0x5B00001Bu)

#define Mux_CapSense_MATRIXBUTTONS0_NUM_ROWS_VALUE          (Mux_CapSense_dsFlash.wdgtArray[0].numRows)
#define Mux_CapSense_MATRIXBUTTONS0_NUM_ROWS_OFFSET         (28u)
#define Mux_CapSense_MATRIXBUTTONS0_NUM_ROWS_SIZE           (1u)
#define Mux_CapSense_MATRIXBUTTONS0_NUM_ROWS_PARAM_ID       (0x5000001Cu)


#endif /* End CY_SENSE_Mux_CapSense_REGISTER_MAP_H */


/* [] END OF FILE */
