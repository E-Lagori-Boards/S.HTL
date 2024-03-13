/*******************************************************************************
* \file Mux_CapSense_Configuration.h
* \version 7.10
*
* \brief
*   This file provides the customizer parameters definitions.
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

#if !defined(CY_SENSE_Mux_CapSense_CONFIGURATION_H)
#define CY_SENSE_Mux_CapSense_CONFIGURATION_H

#include <cytypes.h>
#include <cyfitter.h>

/*******************************************************************************
* Customizer-generated defines
*******************************************************************************/
#define Mux_CapSense_ENABLE                             (1u)
#define Mux_CapSense_DISABLE                            (0u)

#define Mux_CapSense_THIRD_GENERATION_BLOCK             (1u)
#define Mux_CapSense_FOURTH_GENERATION_BLOCK            (2u)

#define Mux_CapSense_GENERATION_BLOCK_VERSION           (1u)

/*******************************************************************************
* HW IP block global defines
*******************************************************************************/

#if (Mux_CapSense_GENERATION_BLOCK_VERSION == Mux_CapSense_THIRD_GENERATION_BLOCK)
    #define Mux_CapSense_CSDV1                          (Mux_CapSense_ENABLE)

    #ifdef CYIPBLOCK_m0s8csd_VERSION
        #if (0u == CYIPBLOCK_m0s8csd_VERSION)
            #define Mux_CapSense_CSDV1_VER1             (Mux_CapSense_ENABLE)
            #define Mux_CapSense_CSDV1_VER2             (Mux_CapSense_DISABLE)
        #else
            #define Mux_CapSense_CSDV1_VER1             (Mux_CapSense_DISABLE)
            #define Mux_CapSense_CSDV1_VER2             (Mux_CapSense_ENABLE)
        #endif
    #else
        #error "HW IP block version is not specified"
    #endif
#else
    #define Mux_CapSense_CSDV1                          (Mux_CapSense_DISABLE)
    #define Mux_CapSense_CSDV1_VER1                     (Mux_CapSense_DISABLE)
    #define Mux_CapSense_CSDV1_VER2                     (Mux_CapSense_DISABLE)
#endif

#if (Mux_CapSense_GENERATION_BLOCK_VERSION == Mux_CapSense_FOURTH_GENERATION_BLOCK)
    #define Mux_CapSense_CSDV2                          (Mux_CapSense_ENABLE)

    #ifdef CYIPBLOCK_m0s8csdv2_VERSION
        #if (1u == CYIPBLOCK_m0s8csdv2_VERSION)
            #define Mux_CapSense_CSDV2_VER1             (Mux_CapSense_ENABLE)
        #else
            #define Mux_CapSense_CSDV2_VER1             (Mux_CapSense_DISABLE)
        #endif
        #if (2u == CYIPBLOCK_m0s8csdv2_VERSION)
            #define Mux_CapSense_CSDV2_VER2             (Mux_CapSense_ENABLE)
        #else
            #define Mux_CapSense_CSDV2_VER2             (Mux_CapSense_DISABLE)
        #endif
    #else
        #error "HW IP block version is not specified"
    #endif
#else
    #define Mux_CapSense_CSDV2                          (Mux_CapSense_DISABLE)
    #define Mux_CapSense_CSDV2_VER1                     (Mux_CapSense_DISABLE)
    #define Mux_CapSense_CSDV2_VER2                     (Mux_CapSense_DISABLE)
#endif

/*******************************************************************************
* Project-global defines
*******************************************************************************/

#define Mux_CapSense_2000_MV                            (2000u)

#ifdef CYDEV_VDDA_MV
    #define Mux_CapSense_CYDEV_VDDA_MV                  (CYDEV_VDDA_MV)
#else
    #ifdef CYDEV_VDD_MV
        #define Mux_CapSense_CYDEV_VDDA_MV              (CYDEV_VDD_MV)
    #endif
#endif

#define Mux_CapSense_BAD_CONVERSIONS_NUM                (1u)
#define Mux_CapSense_RESAMPLING_CYCLES_MAX_NUMBER       (1u)


/*******************************************************************************
* Enabled Scan Methods
*******************************************************************************/
#define Mux_CapSense_CSD_EN                             (1u)
#define Mux_CapSense_CSX_EN                             (0u)
#define Mux_CapSense_ISX_EN                             (0u)
#define Mux_CapSense_CSD_CSX_EN                         (Mux_CapSense_CSD_EN && Mux_CapSense_CSX_EN)

#define Mux_CapSense_MANY_SENSE_MODES_EN                ((Mux_CapSense_CSD_EN && Mux_CapSense_CSX_EN) || \
                                                             (Mux_CapSense_CSD_EN && Mux_CapSense_ISX_EN) || \
                                                             (Mux_CapSense_CSX_EN && Mux_CapSense_ISX_EN) || \
                                                             (Mux_CapSense_SELF_TEST_EN))

#define Mux_CapSense_MANY_WIDGET_METHODS_EN             ((Mux_CapSense_CSD_EN && Mux_CapSense_CSX_EN) || \
                                                             (Mux_CapSense_CSD_EN && Mux_CapSense_ISX_EN) || \
                                                             (Mux_CapSense_CSX_EN && Mux_CapSense_ISX_EN))

#define Mux_CapSense_CSD2X_EN                           (0u)
#define Mux_CapSense_CSX2X_EN                           (0u)

/*******************************************************************************
* Definitions for number of widgets and sensors
*******************************************************************************/
#define Mux_CapSense_TOTAL_WIDGETS                      (1u)
#define Mux_CapSense_TOTAL_CSD_WIDGETS                  (1u)
#define Mux_CapSense_TOTAL_CSD_SENSORS                  (8u)
#define Mux_CapSense_TOTAL_CSX_WIDGETS                  (0u)
#define Mux_CapSense_TOTAL_ISX_WIDGETS                  (0u)
#define Mux_CapSense_TOTAL_CSX_NODES                    (0u)
#define Mux_CapSense_TOTAL_ISX_NODES                    (0u)

/*******************************************************************************
* Total number of CSD sensors + CSX nodes
*******************************************************************************/
#define Mux_CapSense_TOTAL_SENSORS            (Mux_CapSense_TOTAL_CSD_SENSORS + \
                                                   Mux_CapSense_TOTAL_CSX_NODES+ \
                                                   Mux_CapSense_TOTAL_ISX_NODES)

/*******************************************************************************
* Total number of scan slots (used only when dual-channel scan is enabled)
*******************************************************************************/
#define Mux_CapSense_TOTAL_SCAN_SLOTS         (8u)

/*******************************************************************************
* Defines widget IDs
*******************************************************************************/
#define Mux_CapSense_MATRIXBUTTONS0_WDGT_ID     (0u)

/*******************************************************************************
* Defines sensor IDs
*******************************************************************************/

/* MatrixButtons0 sensor names */
#define Mux_CapSense_MATRIXBUTTONS0_COL0_ID     (0u)
#define Mux_CapSense_MATRIXBUTTONS0_COL1_ID     (1u)
#define Mux_CapSense_MATRIXBUTTONS0_COL2_ID     (2u)
#define Mux_CapSense_MATRIXBUTTONS0_COL3_ID     (3u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_ID     (4u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_ID     (5u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_ID     (6u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_ID     (7u)

/* MatrixButtons0 sensor element IDs */
#define Mux_CapSense_MATRIXBUTTONS0_SNS0_ID     (0u)
#define Mux_CapSense_MATRIXBUTTONS0_SNS1_ID     (1u)
#define Mux_CapSense_MATRIXBUTTONS0_SNS2_ID     (2u)
#define Mux_CapSense_MATRIXBUTTONS0_SNS3_ID     (3u)
#define Mux_CapSense_MATRIXBUTTONS0_SNS4_ID     (4u)
#define Mux_CapSense_MATRIXBUTTONS0_SNS5_ID     (5u)
#define Mux_CapSense_MATRIXBUTTONS0_SNS6_ID     (6u)
#define Mux_CapSense_MATRIXBUTTONS0_SNS7_ID     (7u)



/*******************************************************************************
* Enabled widget types
*******************************************************************************/
#define Mux_CapSense_BUTTON_WIDGET_EN         (0u)
#define Mux_CapSense_SLIDER_WIDGET_EN         (0u)
#define Mux_CapSense_MATRIX_WIDGET_EN         (1u)
#define Mux_CapSense_PROXIMITY_WIDGET_EN      (0u)
#define Mux_CapSense_TOUCHPAD_WIDGET_EN       (0u)
#define Mux_CapSense_ENCODERDIAL_WIDGET_EN    (0u)

#define Mux_CapSense_CSD_MATRIX_WIDGET_EN     (1u)
#define Mux_CapSense_CSD_TOUCHPAD_WIDGET_EN   (0u)

#define Mux_CapSense_CSX_MATRIX_WIDGET_EN     (0u)
#define Mux_CapSense_CSX_TOUCHPAD_WIDGET_EN   (0u)

/*******************************************************************************
* Centroid APIs
*******************************************************************************/
#define Mux_CapSense_CENTROID_EN              (0u)
#define Mux_CapSense_TOTAL_DIPLEXED_SLIDERS   (0u)
#define Mux_CapSense_TOTAL_LINEAR_SLIDERS     (0u)
#define Mux_CapSense_TOTAL_RADIAL_SLIDERS     (0u)
#define Mux_CapSense_TOTAL_TOUCHPADS          (0u)
#define Mux_CapSense_MAX_CENTROID_LENGTH      (0u)
#define Mux_CapSense_SLIDER_MULT_METHOD       (0u)
#define Mux_CapSense_TOUCHPAD_MULT_METHOD     (0u)

/*******************************************************************************
* Enabled sensor types
*******************************************************************************/
#define Mux_CapSense_REGULAR_SENSOR_EN        (1u)
#define Mux_CapSense_PROXIMITY_SENSOR_EN      (0u)

/*******************************************************************************
* Sensor ganging
*******************************************************************************/
#define Mux_CapSense_GANGED_SNS_EN            (0u)
#define Mux_CapSense_CSD_GANGED_SNS_EN        (0u)
#define Mux_CapSense_CSX_GANGED_SNS_EN        (0u)

/*******************************************************************************
* Max number of sensors used among all the widgets
*******************************************************************************/
#define Mux_CapSense_MAX_SENSORS_PER_WIDGET   (8u)
#define Mux_CapSense_MAX_SENSORS_PER_5X5_TOUCHPAD (1u)

/*******************************************************************************
* Total number of all used electrodes (NOT unique)
*******************************************************************************/
#define Mux_CapSense_TOTAL_ELECTRODES         (8u)
/* Obsolete */
#define Mux_CapSense_TOTAL_SENSOR_IOS         Mux_CapSense_TOTAL_ELECTRODES

/*******************************************************************************
* Total number of used physical IOs (unique)
*******************************************************************************/
#define Mux_CapSense_TOTAL_IO_CNT             (8u)

/*******************************************************************************
* Array length for widget status registers
*******************************************************************************/
#define Mux_CapSense_WDGT_STATUS_WORDS        \
                        (((uint8)((Mux_CapSense_TOTAL_WIDGETS - 1u) / 32u)) + 1u)


/*******************************************************************************
* Auto-tuning mode selection
*******************************************************************************/
#define Mux_CapSense_CSD_SS_DIS         (0x00ul)
#define Mux_CapSense_CSD_SS_HW_EN       (0x01ul)
#define Mux_CapSense_CSD_SS_TH_EN       (0x02ul)
#define Mux_CapSense_CSD_SS_HWTH_EN     (Mux_CapSense_CSD_SS_HW_EN | \
                                             Mux_CapSense_CSD_SS_TH_EN)

#define Mux_CapSense_CSD_AUTOTUNE       Mux_CapSense_CSD_SS_DIS


/*******************************************************************************
* General settings
*******************************************************************************/

#define Mux_CapSense_AUTO_RESET_METHOD_LEGACY (0u)
#define Mux_CapSense_AUTO_RESET_METHOD_SAMPLE (1u)

#define Mux_CapSense_MULTI_FREQ_SCAN_EN       (0u)
#define Mux_CapSense_SENSOR_AUTO_RESET_EN     (0u)
#define Mux_CapSense_SENSOR_AUTO_RESET_METHOD (0u)
#define Mux_CapSense_NUM_CENTROIDS            (1u)
#define Mux_CapSense_4PTS_LOCAL_MAX_EN        (0u)
#define Mux_CapSense_OFF_DEBOUNCE_EN          (0u)
#define Mux_CapSense_CUSTOM_DS_RAM_SIZE       (0u)

/* Defines power status of HW block after scanning */
#define Mux_CapSense_BLOCK_OFF_AFTER_SCAN_EN  (0u)

/* Defines number of scan frequencies */
#if (Mux_CapSense_DISABLE != Mux_CapSense_MULTI_FREQ_SCAN_EN)
    #define Mux_CapSense_NUM_SCAN_FREQS       (3u)
#else
    #define Mux_CapSense_NUM_SCAN_FREQS       (1u)
#endif /* #if (Mux_CapSense_DISABLE != Mux_CapSense_MULTI_FREQ_SCAN_EN) */

/* Data size for thresholds / low baseline reset */
#define Mux_CapSense_SIZE_8BITS               (8u)
#define Mux_CapSense_SIZE_16BITS              (16u)

#define Mux_CapSense_THRESHOLD_SIZE           Mux_CapSense_SIZE_16BITS
typedef uint16 Mux_CapSense_THRESHOLD_TYPE;

#if (Mux_CapSense_AUTO_RESET_METHOD_LEGACY == Mux_CapSense_SENSOR_AUTO_RESET_METHOD)
    #define Mux_CapSense_LOW_BSLN_RST_SIZE        Mux_CapSense_SIZE_8BITS
    typedef uint8 Mux_CapSense_LOW_BSLN_RST_TYPE;
#else
    #define Mux_CapSense_LOW_BSLN_RST_SIZE    (16u)
    typedef uint16 Mux_CapSense_LOW_BSLN_RST_TYPE;
#endif /* #if (Mux_CapSense_AUTO_RESET_METHOD_LEGACY == Mux_CapSense_SENSOR_AUTO_RESET_METHOD) */

/* Coefficient to define touch threshold for proximity sensors */
#define Mux_CapSense_PROX_TOUCH_COEFF         (300u)

/*******************************************************************************
* General Filter Constants
*******************************************************************************/

/* Baseline algorithm options */
#define Mux_CapSense_IIR_BASELINE                 (0u)
#define Mux_CapSense_BUCKET_BASELINE              (1u)

#define Mux_CapSense_BASELINE_TYPE                Mux_CapSense_IIR_BASELINE

/* IIR baseline filter algorithm for regular sensors*/
#define Mux_CapSense_REGULAR_IIR_BL_TYPE          Mux_CapSense_IIR_FILTER_PERFORMANCE

/* IIR baseline coefficients for regular sensors */
#define Mux_CapSense_REGULAR_IIR_BL_N             (1u)
#define Mux_CapSense_REGULAR_IIR_BL_SHIFT         (8u)

/* IIR baseline filter algorithm for proximity sensors*/
#define Mux_CapSense_PROX_IIR_BL_TYPE             Mux_CapSense_IIR_FILTER_PERFORMANCE

/* IIR baseline coefficients for proximity sensors */
#define Mux_CapSense_PROX_IIR_BL_N                (1u)
#define Mux_CapSense_PROX_IIR_BL_SHIFT            (8u)


/* IIR filter constants */
#define Mux_CapSense_IIR_COEFFICIENT_K            (256u)

/* IIR filter type */
#define Mux_CapSense_IIR_FILTER_STANDARD          (1u)
#define Mux_CapSense_IIR_FILTER_PERFORMANCE       (2u)
#define Mux_CapSense_IIR_FILTER_MEMORY            (3u)

/* Regular sensor raw count filters */
#define Mux_CapSense_REGULAR_RC_FILTER_EN         (0u)
#define Mux_CapSense_REGULAR_RC_IIR_FILTER_EN     (0u)
#define Mux_CapSense_REGULAR_RC_MEDIAN_FILTER_EN  (0u)
#define Mux_CapSense_REGULAR_RC_AVERAGE_FILTER_EN (0u)
#define Mux_CapSense_REGULAR_RC_CUSTOM_FILTER_EN  (0u)
#define Mux_CapSense_REGULAR_RC_ALP_FILTER_EN     (0u)

/* Proximity sensor raw count filters */
#define Mux_CapSense_PROX_RC_FILTER_EN            (0u)
#define Mux_CapSense_PROX_RC_IIR_FILTER_EN        (0u)
#define Mux_CapSense_PROX_RC_MEDIAN_FILTER_EN     (0u)
#define Mux_CapSense_PROX_RC_AVERAGE_FILTER_EN    (0u)
#define Mux_CapSense_PROX_RC_CUSTOM_FILTER_EN     (0u)
#define Mux_CapSense_PROX_RC_ALP_FILTER_EN        (0u)

#define Mux_CapSense_ALP_FILTER_EN                (0u)
#define Mux_CapSense_REGULAR_RC_ALP_FILTER_COEFF  (2u)
#define Mux_CapSense_PROX_RC_ALP_FILTER_COEFF     (2u)

/* Raw count filters */
#define Mux_CapSense_RC_FILTER_EN                 (Mux_CapSense_REGULAR_RC_FILTER_EN || Mux_CapSense_PROX_RC_FILTER_EN)

/* IIR raw count filter algorithm for regular sensors */
#define Mux_CapSense_REGULAR_IIR_RC_TYPE          (Mux_CapSense_IIR_FILTER_STANDARD)

/* IIR raw count filter coefficients for regular sensors */
#define Mux_CapSense_REGULAR_IIR_RC_N             (128u)
#define Mux_CapSense_REGULAR_IIR_RC_SHIFT         (0u)

/* IIR raw count filter algorithm for proximity sensors*/
#define Mux_CapSense_PROX_IIR_RC_TYPE             (Mux_CapSense_IIR_FILTER_STANDARD)

/* IIR raw count filter coefficients for proximity sensors */
#define Mux_CapSense_PROX_IIR_RC_N                (128u)
#define Mux_CapSense_PROX_IIR_RC_SHIFT            (0u)

/* Median filter constants */

/* Order of regular sensor median filter */
#define Mux_CapSense_REGULAR_MEDIAN_LEN           (2u)

/* Order of proximity sensor median filter */
#define Mux_CapSense_PROX_MEDIAN_LEN              (2u)

/* Average filter constants*/
#define Mux_CapSense_AVERAGE_FILTER_LEN_2         (1u)
#define Mux_CapSense_AVERAGE_FILTER_LEN_4         (3u)

/* Order of regular sensor average filter */
#define Mux_CapSense_REGULAR_AVERAGE_LEN          (Mux_CapSense_AVERAGE_FILTER_LEN_4)

/* Order of proximity sensor average filter */
#define Mux_CapSense_PROX_AVERAGE_LEN             (Mux_CapSense_AVERAGE_FILTER_LEN_4)

/* Widget baseline coefficient enable */
#define Mux_CapSense_WD_BSLN_COEFF_EN             (0u)

/* Centroid position filters */
#define Mux_CapSense_POSITION_FILTER_EN           (0u)
#define Mux_CapSense_POS_MEDIAN_FILTER_EN         (0u)
#define Mux_CapSense_POS_IIR_FILTER_EN            (0u)
#define Mux_CapSense_POS_ADAPTIVE_IIR_FILTER_EN   (0u)
#define Mux_CapSense_POS_AVERAGE_FILTER_EN        (0u)
#define Mux_CapSense_POS_JITTER_FILTER_EN         (0u)
#define Mux_CapSense_BALLISTIC_MULTIPLIER_EN      (0u)
#define Mux_CapSense_CENTROID_3X3_CSD_EN          (0u)
#define Mux_CapSense_CENTROID_5X5_CSD_EN          (0u)
#define Mux_CapSense_CSD_5X5_MAX_FINGERS          (1u)

#define Mux_CapSense_POS_IIR_COEFF                (128u)
#define Mux_CapSense_POS_IIR_RESET_RADIAL_SLIDER  (35u)

#define Mux_CapSense_CSX_TOUCHPAD_UNDEFINED       (40u)

/* IDAC options */

/* Third-generation HW block IDAC gain */
#define Mux_CapSense_IDAC_GAIN_4X                 (4u)
#define Mux_CapSense_IDAC_GAIN_8X                 (8u)

/* Fourth-generation HW block IDAC gain */
#define Mux_CapSense_IDAC_GAIN_LOW                (0uL)
#define Mux_CapSense_IDAC_GAIN_MEDIUM             (1uL)
#define Mux_CapSense_IDAC_GAIN_HIGH               (2uL)

#define Mux_CapSense_IDAC_SOURCING                (0u)
#define Mux_CapSense_IDAC_SINKING                 (1u)

/* Shield tank capacitor precharge source */
#define Mux_CapSense_CSH_PRECHARGE_VREF           (0u)
#define Mux_CapSense_CSH_PRECHARGE_IO_BUF         (1u)

/* Shield electrode delay */
#define Mux_CapSense_NO_DELAY                     (0u)

#if(Mux_CapSense_ENABLE == Mux_CapSense_CSDV2)
    #define Mux_CapSense_SH_DELAY_5NS             (1u)
    #define Mux_CapSense_SH_DELAY_10NS            (2u)
    #define Mux_CapSense_SH_DELAY_20NS            (3u)
#else
    #if(Mux_CapSense_ENABLE == Mux_CapSense_CSDV1_VER2)
        #define Mux_CapSense_SH_DELAY_10NS        (3u)
        #define Mux_CapSense_SH_DELAY_50NS        (2u)
    #else
        #define Mux_CapSense_SH_DELAY_1CYCLES     (1u)
        #define Mux_CapSense_SH_DELAY_2CYCLES     (2u)
    #endif /* (Mux_CapSense_ENABLE == Mux_CapSense_CSDV1_VER2) */
#endif /* (Mux_CapSense_ENABLE == Mux_CapSense_CSDV2) */

/* Inactive sensor connection options */
#define Mux_CapSense_SNS_CONNECTION_GROUND        (0x00000000u)
#define Mux_CapSense_SNS_CONNECTION_HIGHZ         (0x00000001u)
#define Mux_CapSense_SNS_CONNECTION_SHIELD        (0x00000002u)
#define Mux_CapSense_SNS_CONNECTION_UNDEFINED     (0x00000003u)

/* Sense clock selection options */
#if defined(Mux_CapSense_TAPEOUT_STAR_USED)
    #define Mux_CapSense_CSDV2_REF9P6UA_EN            (0u)
#else
    #define Mux_CapSense_CSDV2_REF9P6UA_EN            (0u)
#endif /* defined(Mux_CapSense_TAPEOUT_STAR_USED) */

#define Mux_CapSense_CLK_SOURCE_DIRECT            (0x00000000Lu)

#define Mux_CapSense_CLK_SOURCE_SSC1              (0x01u)
#define Mux_CapSense_CLK_SOURCE_SSC2              (0x02u)
#define Mux_CapSense_CLK_SOURCE_SSC3              (0x03u)
#define Mux_CapSense_CLK_SOURCE_SSC4              (0x04u)

#define Mux_CapSense_CLK_SOURCE_PRS8              (0x05u)
#define Mux_CapSense_CLK_SOURCE_PRS12             (0x06u)
#define Mux_CapSense_CLK_SOURCE_PRSAUTO           (0xFFu)

#define Mux_CapSense_MFS_IMO                      (0u)
#define Mux_CapSense_MFS_SNS_CLK                  (1u)

/* Defines scan resolutions */
#define Mux_CapSense_RES6BIT                      (6u)
#define Mux_CapSense_RES7BIT                      (7u)
#define Mux_CapSense_RES8BIT                      (8u)
#define Mux_CapSense_RES9BIT                      (9u)
#define Mux_CapSense_RES10BIT                     (10u)
#define Mux_CapSense_RES11BIT                     (11u)
#define Mux_CapSense_RES12BIT                     (12u)
#define Mux_CapSense_RES13BIT                     (13u)
#define Mux_CapSense_RES14BIT                     (14u)
#define Mux_CapSense_RES15BIT                     (15u)
#define Mux_CapSense_RES16BIT                     (16u)

/* Fourth-generation HW block: Initialization switch resistance */
#define Mux_CapSense_INIT_SW_RES_LOW              (0x00000000Lu)
#define Mux_CapSense_INIT_SW_RES_MEDIUM           (0x00000001Lu)
#define Mux_CapSense_INIT_SW_RES_HIGH             (0x00000002Lu)

/* Fourth-generation HW block: Initialization switch resistance */
#define Mux_CapSense_SCAN_SW_RES_LOW              (0x00000000Lu)
#define Mux_CapSense_SCAN_SW_RES_MEDIUM           (0x00000001Lu)
#define Mux_CapSense_SCAN_SW_RES_HIGH             (0x00000002Lu)

/* Fourth-generation HW block: CSD shield switch resistance */
#define Mux_CapSense_SHIELD_SW_RES_LOW            (0x00000000Lu)
#define Mux_CapSense_SHIELD_SW_RES_MEDIUM         (0x00000001Lu)
#define Mux_CapSense_SHIELD_SW_RES_HIGH           (0x00000002Lu)
#define Mux_CapSense_SHIELD_SW_RES_LOW_EMI        (0x00000003Lu)

/* Fourth-generation HW block: CSD shield switch resistance */
#define Mux_CapSense_INIT_SHIELD_SW_RES_LOW       (0x00000000Lu)
#define Mux_CapSense_INIT_SHIELD_SW_RES_MEDIUM    (0x00000001Lu)
#define Mux_CapSense_INIT_SHIELD_SW_RES_HIGH      (0x00000002Lu)
#define Mux_CapSense_INIT_SHIELD_SW_RES_LOW_EMI   (0x00000003Lu)

/* Fourth-generation HW block: CSD shield switch resistance */
#define Mux_CapSense_SCAN_SHIELD_SW_RES_LOW       (0x00000000Lu)
#define Mux_CapSense_SCAN_SHIELD_SW_RES_MEDIUM    (0x00000001Lu)
#define Mux_CapSense_SCAN_SHIELD_SW_RES_HIGH      (0x00000002Lu)
#define Mux_CapSense_SCAN_SHIELD_SW_RES_LOW_EMI   (0x00000003Lu)

/* Sensing method */
#define Mux_CapSense_SENSING_LEGACY               (0x00000000Lu)
#define Mux_CapSense_SENSING_LOW_EMI              (0x00000001Lu)
#define Mux_CapSense_SENSING_FULL_WAVE            (0x00000002Lu)


/*******************************************************************************
* CSD/CSX Common Settings
*******************************************************************************/

#define Mux_CapSense_BLOCK_ANALOG_WAKEUP_DELAY_US (0u)

#define Mux_CapSense_MFS_METHOD                   (0u)
#define Mux_CapSense_IMO_FREQUENCY_OFFSET_F1      (20u)
#define Mux_CapSense_IMO_FREQUENCY_OFFSET_F2      (20u)

/*******************************************************************************
* CSD Specific Settings
*******************************************************************************/

/* CSD scan method settings */
#define Mux_CapSense_CSD_IDAC_AUTOCAL_EN          (1u)
#define Mux_CapSense_CSD_IDAC_GAIN                (Mux_CapSense_IDAC_GAIN_4X)
#define Mux_CapSense_CSD_SHIELD_EN                (0u)
#define Mux_CapSense_CSD_SHIELD_TANK_EN           (1u)
#define Mux_CapSense_CSD_CSH_PRECHARGE_SRC        (Mux_CapSense_CSH_PRECHARGE_VREF)
#define Mux_CapSense_CSD_SHIELD_DELAY             (Mux_CapSense_NO_DELAY)
#define Mux_CapSense_CSD_TOTAL_SHIELD_COUNT       (0u)
#define Mux_CapSense_CSD_SCANSPEED_DIVIDER        (2u)
#define Mux_CapSense_CSD_COMMON_SNS_CLK_EN        (0u)
#define Mux_CapSense_CSD_SNS_CLK_SOURCE           (Mux_CapSense_CLK_SOURCE_PRSAUTO)
#define Mux_CapSense_CSD_SNS_CLK_DIVIDER          (8u)
#define Mux_CapSense_CSD_INACTIVE_SNS_CONNECTION  (Mux_CapSense_SNS_CONNECTION_GROUND)
#define Mux_CapSense_CSD_IDAC_COMP_EN             (1u)
#define Mux_CapSense_CSD_IDAC_CONFIG              (Mux_CapSense_IDAC_SOURCING)
#define Mux_CapSense_CSD_RAWCOUNT_CAL_LEVEL       (85u)
#define Mux_CapSense_CSD_DUALIDAC_LEVEL           (50u)
#define Mux_CapSense_CSD_PRESCAN_SETTLING_TIME    (5u)
#define Mux_CapSense_CSD_SNSCLK_R_CONST           (1000u)
#define Mux_CapSense_CSD_VREF_MV                  (1200u)

#define Mux_CapSense_CSD_CALIBRATION_ERROR        (10u)
#define Mux_CapSense_CSD_IDAC_AUTO_GAIN_EN        (1u)
#define Mux_CapSense_CSD_IDAC_GAIN_INDEX_DEFAULT  (0u)
#define Mux_CapSense_CSD_IDAC_MIN                 (20u)
#define Mux_CapSense_CSD_COL_ROW_IDAC_ALIGNMENT_EN      (1u)

/* The macro is obsolete and should not be used */
#define Mux_CapSense_CSD_DEDICATED_IDAC_COMP_EN   (1u)
/* CSD settings - Fourth-generation HW block */
#define Mux_CapSense_CSD_ANALOG_STARTUP_DELAY_US  (10u)
#define Mux_CapSense_CSD_FINE_INIT_TIME           (10u)
#define Mux_CapSense_CSD_AUTO_ZERO_EN             (0u)
#define Mux_CapSense_CSD_AUTO_ZERO_TIME           (15Lu)
#define Mux_CapSense_CSD_NOISE_METRIC_EN          (0u)
#define Mux_CapSense_CSD_NOISE_METRIC_TH          (1Lu)
#define Mux_CapSense_CSD_INIT_SWITCH_RES          (Mux_CapSense_INIT_SW_RES_MEDIUM)
#define Mux_CapSense_CSD_SENSING_METHOD           (0)
#define Mux_CapSense_CSD_SHIELD_SWITCH_RES        (Mux_CapSense_SHIELD_SW_RES_MEDIUM)
#define Mux_CapSense_CSD_GAIN                     (31Lu)

#define Mux_CapSense_CSD_MFS_DIVIDER_OFFSET_F1    (1u)
#define Mux_CapSense_CSD_MFS_DIVIDER_OFFSET_F2    (2u)

/*******************************************************************************
* CSX Specific Settings
*******************************************************************************/

/* CSX scan method settings */
#define Mux_CapSense_CSX_SCANSPEED_DIVIDER        (2u)
#define Mux_CapSense_CSX_COMMON_TX_CLK_EN         (0u)
#define Mux_CapSense_CSX_TX_CLK_SOURCE            (Mux_CapSense_CLK_SOURCE_DIRECT)
#define Mux_CapSense_CSX_TX_CLK_DIVIDER           (80u)
#define Mux_CapSense_CSX_INACTIVE_SNS_CONNECTION  (Mux_CapSense_SNS_CONNECTION_GROUND)
#define Mux_CapSense_CSX_MAX_FINGERS              (1u)
#define Mux_CapSense_CSX_MAX_LOCAL_PEAKS          (5u)
#define Mux_CapSense_CSX_IDAC_AUTOCAL_EN          (0u)
#define Mux_CapSense_CSX_IDAC_BITS_USED           (8u)
#define Mux_CapSense_CSX_RAWCOUNT_CAL_LEVEL       (40u)
#define Mux_CapSense_CSX_IDAC_GAIN                (Mux_CapSense_IDAC_GAIN_4X)
#define Mux_CapSense_CSX_CALIBRATION_ERROR        (20u)
#define Mux_CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES (0u)
#define Mux_CapSense_CSX_MULTIPHASE_TX_EN         (0u)
#define Mux_CapSense_CSX_MAX_TX_PHASE_LENGTH      (0u)

/* CSX settings - Fourth-generation HW block */
#define Mux_CapSense_CSX_ANALOG_STARTUP_DELAY_US  (10u)
#define Mux_CapSense_CSX_AUTO_ZERO_EN             (0u)
#define Mux_CapSense_CSX_AUTO_ZERO_TIME           (15u)
#define Mux_CapSense_CSX_FINE_INIT_TIME           (4u)
#define Mux_CapSense_CSX_NOISE_METRIC_EN          (0u)
#define Mux_CapSense_CSX_NOISE_METRIC_TH          (1u)
#define Mux_CapSense_CSX_INIT_SWITCH_RES          (Mux_CapSense_INIT_SW_RES_MEDIUM)
#define Mux_CapSense_CSX_SCAN_SWITCH_RES          (Mux_CapSense_SCAN_SW_RES_LOW)
#define Mux_CapSense_CSX_INIT_SHIELD_SWITCH_RES   (Mux_CapSense_INIT_SHIELD_SW_RES_HIGH)
#define Mux_CapSense_CSX_SCAN_SHIELD_SWITCH_RES   (Mux_CapSense_SCAN_SHIELD_SW_RES_LOW)

#define Mux_CapSense_CSX_MFS_DIVIDER_OFFSET_F1    (1u)
#define Mux_CapSense_CSX_MFS_DIVIDER_OFFSET_F2    (2u)

/* Gesture parameters */
#define Mux_CapSense_GES_GLOBAL_EN                (0u)

/*******************************************************************************
* ISX Specific Settings
*******************************************************************************/

/* ISX scan method settings */
#define Mux_CapSense_ISX_SCANSPEED_DIVIDER        (2u)
#define Mux_CapSense_ISX_LX_CLK_DIVIDER           (80u)
#define Mux_CapSense_ISX_IDAC_AUTOCAL_EN          (0u)
#define Mux_CapSense_ISX_IDAC_BITS_USED           (7u)
#define Mux_CapSense_ISX_RAWCOUNT_CAL_LEVEL       (30u)
#define Mux_CapSense_ISX_IDAC_GAIN                (Mux_CapSense_IDAC_GAIN_4X)
#define Mux_CapSense_ISX_SKIP_OVSMPL_SPECIFIC_NODES (0u)
#define Mux_CapSense_ISX_MAX_TX_PHASE_LENGTH      (0u)
#define Mux_CapSense_ISX_PIN_COUNT_LX             (u)
/* ISX settings - Fourth-generation HW block */
#define Mux_CapSense_ISX_AUTO_ZERO_EN             (0u)
#define Mux_CapSense_ISX_AUTO_ZERO_TIME           (15u)
#define Mux_CapSense_ISX_FINE_INIT_TIME           (20u)
#define Mux_CapSense_ISX_NOISE_METRIC_EN          (0u)
#define Mux_CapSense_ISX_NOISE_METRIC_TH          (1u)
#define Mux_CapSense_ISX_INIT_SWITCH_RES          (Mux_CapSense_INIT_SW_RES_MEDIUM)
#define Mux_CapSense_ISX_SCAN_SWITCH_RES          (Mux_CapSense_SCAN_SW_RES_LOW)
#define Mux_CapSense_ISX_INIT_SHIELD_SWITCH_RES   (Mux_CapSense_INIT_SHIELD_SW_RES_HIGH)
#define Mux_CapSense_ISX_SCAN_SHIELD_SWITCH_RES   (Mux_CapSense_SCAN_SHIELD_SW_RES_LOW)
#define Mux_CapSense_ISX_SAMPLE_PHASE_DEG         (30u)

/*******************************************************************************
* Global Parameter Definitions
*******************************************************************************/

/* Compound section definitions */
#define Mux_CapSense_ANY_NONSS_AUTOCAL ((0u != Mux_CapSense_CSX_IDAC_AUTOCAL_EN) || \
                                       (0u != Mux_CapSense_ISX_IDAC_AUTOCAL_EN) || \
                                      ((Mux_CapSense_CSD_AUTOTUNE == Mux_CapSense_CSD_SS_DIS) && (0u != Mux_CapSense_CSD_IDAC_AUTOCAL_EN)))
#define Mux_CapSense_ANYMODE_AUTOCAL (((0u != Mux_CapSense_CSX_IDAC_AUTOCAL_EN) \
                                       || (0u != Mux_CapSense_ISX_IDAC_AUTOCAL_EN)) \
                                       || (0u != Mux_CapSense_CSD_IDAC_AUTOCAL_EN))
/* RAM Global Parameters Definitions */
#define Mux_CapSense_CONFIG_ID                  (0xA548u)
#define Mux_CapSense_DEVICE_ID                  (0x0000u)
#define Mux_CapSense_HW_CLOCK                   (0x1770u)
#define Mux_CapSense_CSD0_CONFIG                (0x0000u)

/*******************************************************************************
* MatrixButtons0 initialization values for FLASH data structure
*******************************************************************************/
#define Mux_CapSense_MATRIXBUTTONS0_STATIC_CONFIG (10241u)
#define Mux_CapSense_MATRIXBUTTONS0_NUM_COLS    (4u)
#define Mux_CapSense_MATRIXBUTTONS0_NUM_ROWS    (4u)

/*******************************************************************************
* MatrixButtons0 initialization values for RAM data structure
*******************************************************************************/
#define Mux_CapSense_MATRIXBUTTONS0_RESOLUTION  (Mux_CapSense_RES12BIT)
#define Mux_CapSense_MATRIXBUTTONS0_FINGER_TH   (100u)
#define Mux_CapSense_MATRIXBUTTONS0_NOISE_TH    (40u)
#define Mux_CapSense_MATRIXBUTTONS0_NNOISE_TH   (40u)
#define Mux_CapSense_MATRIXBUTTONS0_HYSTERESIS  (10u)
#define Mux_CapSense_MATRIXBUTTONS0_ON_DEBOUNCE (3u)
#define Mux_CapSense_MATRIXBUTTONS0_LOW_BSLN_RST (30u)
#define Mux_CapSense_MATRIXBUTTONS0_IDAC_MOD0   (32u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW_IDAC_MOD0 (32u)
#define Mux_CapSense_MATRIXBUTTONS0_IDAC_GAIN_INDEX (0u)
#define Mux_CapSense_MATRIXBUTTONS0_SNS_CLK     (8u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW_SNS_CLK (8u)
#define Mux_CapSense_MATRIXBUTTONS0_SNS_CLK_SOURCE (0u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW_SNS_CLK_SOURCE (0u)
#define Mux_CapSense_MATRIXBUTTONS0_POS_COL     (0xFFu)
#define Mux_CapSense_MATRIXBUTTONS0_POS_ROW     (0xFFu)
#define Mux_CapSense_MATRIXBUTTONS0_POS_SNS_ID  (0u)

/* RAM Sensor Parameters Definitions */
#define Mux_CapSense_MATRIXBUTTONS0_COL0_IDAC_COMP0 (32u)
#define Mux_CapSense_MATRIXBUTTONS0_COL1_IDAC_COMP0 (32u)
#define Mux_CapSense_MATRIXBUTTONS0_COL2_IDAC_COMP0 (32u)
#define Mux_CapSense_MATRIXBUTTONS0_COL3_IDAC_COMP0 (32u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW0_IDAC_COMP0 (32u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW1_IDAC_COMP0 (32u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW2_IDAC_COMP0 (32u)
#define Mux_CapSense_MATRIXBUTTONS0_ROW3_IDAC_COMP0 (32u)



/*******************************************************************************
* ADC Specific Macros
*******************************************************************************/
#define Mux_CapSense_ADC_RES8BIT                  (8u)
#define Mux_CapSense_ADC_RES10BIT                 (10u)

#define Mux_CapSense_ADC_FULLRANGE_MODE           (0u)
#define Mux_CapSense_ADC_VREF_MODE                (1u)

#define Mux_CapSense_ADC_MIN_CHANNELS             (1u)
#define Mux_CapSense_ADC_EN                       (0u)
#define Mux_CapSense_ADC_STANDALONE_EN            (0u)
#define Mux_CapSense_ADC_TOTAL_CHANNELS           (1u)
#define Mux_CapSense_ADC_RESOLUTION               (Mux_CapSense_ADC_RES10BIT)
#define Mux_CapSense_ADC_AMUXB_INPUT_EN           (0u)
#define Mux_CapSense_ADC_SELECT_AMUXB_CH          (0u)
#define Mux_CapSense_ADC_AZ_EN                    (1Lu)
#define Mux_CapSense_ADC_AZ_TIME                  (5u)
#define Mux_CapSense_ADC_VREF_MV                  (2133u)
#define Mux_CapSense_ADC_GAIN                     (17Lu)
#define Mux_CapSense_ADC_IDAC_DEFAULT             (15u)
#define Mux_CapSense_ADC_MODCLK_DIV_DEFAULT       (2u)
#define Mux_CapSense_ADC_MEASURE_MODE             (Mux_CapSense_ADC_FULLRANGE_MODE)
#define Mux_CapSense_ADC_ANALOG_STARTUP_DELAY_US  (5u)
#define Mux_CapSense_ADC_ACQUISITION_TIME_US      (10u)

/*******************************************************************************
* Built-In Self-Test Configuration
*******************************************************************************/
#define Mux_CapSense_SELF_TEST_EN                   (0Lu)
#define Mux_CapSense_TST_GLOBAL_CRC_EN              (0Lu)
#define Mux_CapSense_TST_WDGT_CRC_EN                (0Lu)
#define Mux_CapSense_TST_BSLN_DUPLICATION_EN        (0Lu)
#define Mux_CapSense_TST_BSLN_RAW_OUT_RANGE_EN      (0Lu)
#define Mux_CapSense_TST_SNS_SHORT_EN               (0Lu)
#define Mux_CapSense_TST_SNS_CAP_EN                 (0Lu)
#define Mux_CapSense_TST_SH_CAP_EN                  (0Lu)
#define Mux_CapSense_TST_EXTERNAL_CAP_EN            (0Lu)
#define Mux_CapSense_TST_VDDA_EN                    (0Lu)


#define Mux_CapSense_GLOBAL_CRC_AREA_START          (0u)
#define Mux_CapSense_GLOBAL_CRC_AREA_SIZE           (0u)
#define Mux_CapSense_WIDGET_CRC_AREA_START          (0u)
#define Mux_CapSense_WIDGET_CRC_AREA_SIZE           (0u)

/* The resolution for sensor capacity measurement */
#define Mux_CapSense_TST_SNS_CAP_RESOLUTION         (12u)

/* VDDA measurement test configuration */
/* The resolution for VDDA measurement */
#define Mux_CapSense_TST_VDDA_RESOLUTION            (10u)
/* The ModClk divider for external capacitor capacity measurement */
#define Mux_CapSense_TST_VDDA_MOD_CLK_DIVIDER       (1u)

#define Mux_CapSense_TST_VDDA_VREF_MV               (0u)
#define Mux_CapSense_TST_VDDA_VREF_GAIN             (0u)
#define Mux_CapSense_TST_VDDA_IDAC_DEFAULT          (0u)

#define Mux_CapSense_TST_FINE_INIT_TIME             (10u)
#define Mux_CapSense_TST_ANALOG_STARTUP_DELAY_US    (23u)

#define Mux_CapSense_TST_IDAC_AUTO_GAIN_EN          (1u)
#define Mux_CapSense_TST_SNS_CAP_RAW_ERROR          (10u)
#define Mux_CapSense_TST_IDAC_GAIN_INDEX            (0xFFu)
#define Mux_CapSense_TST_RAW_TARGET                 (85u)

#define Mux_CapSense_TST_SNS_SHORT_TIME             (2u)

#define Mux_CapSense_SNS_CAP_CSD_INACTIVE_CONNECTION        (Mux_CapSense_SNS_CONNECTION_GROUND)
#define Mux_CapSense_SNS_CAP_CSX_INACTIVE_CONNECTION        (Mux_CapSense_SNS_CONNECTION_GROUND)
#define Mux_CapSense_SHIELD_CAP_INACTIVE_CONNECTION         (Mux_CapSense_SNS_CONNECTION_GROUND)


/*******************************************************************************
* Gesture Configuration
*******************************************************************************/
#define Mux_CapSense_TIMESTAMP_INTERVAL             (1Lu)
#define Mux_CapSense_GESTURE_EN_WIDGET_ID           (0Lu)
#define Mux_CapSense_BALLISTIC_EN_WIDGET_ID         (0Lu)


#endif /* CY_SENSE_Mux_CapSense_CONFIGURATION_H */


/* [] END OF FILE */
