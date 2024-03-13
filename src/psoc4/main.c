/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "stdio.h"
#include "PSoC.h"

 /********************************
 ***START printf() ACCOMODATION***
 *********************************/
 int _write(int file, char *ptr, int len)
 {
     (void) file ;
     int i ;
     for (i = 0 ; i < len ; i++) {
         UART_UartPutChar(*ptr++) ;
     }
     return len ;
 }
/********************************
 ****END printf() ACCOMODATION****
 *********************************/

int main(void){
   
    CyGlobalIntEnable;
    
    struct PSC_McM_6_00 proc1;
    uint32 pos, k=0;
    uint8 i=0, state=1;
    char rec_data[300];
    unsigned long prev = Counter_micros_ReadCounter();
    
    Counter_micros_Start();
    
    UART_Start();
    CTRL_Write(0);
    
    EZI2C_Start();
    
    EZI2C_EzI2CSetBuffer1(sizeof(Mux_CapSense_dsRam), 
                          sizeof(Mux_CapSense_dsRam),
                         (uint8 *)&Mux_CapSense_dsRam);
    
    Mux_CapSense_Start();
    
    delay(1000);
    
    ble_disconnect(&proc1);
    delay(20);
    ble_OFF(&proc1);
    delay(20);
    bleON_host(&proc1);
    delay(20);
    ble_connect(&proc1, "7cb94c3876b8");    //MAC
    
    for(;;)
    {   
        k=0;
        
        if(Mux_CapSense_NOT_BUSY == Mux_CapSense_IsBusy())
        {
            Mux_CapSense_ProcessAllWidgets();
            
            Mux_CapSense_RunTuner();      
            
            Mux_CapSense_ScanAllWidgets();
        }
        
        if(Mux_CapSense_IsSensorActive(0, 4))
        {
            if(Mux_CapSense_IsSensorActive(0, 0))
            {
                k++;
                if(k==1) ble_sendData(&proc1, "R\r\n");
            }
        }
        
        if(Mux_CapSense_IsSensorActive(0, 4))
        {
            if(Mux_CapSense_IsSensorActive(0, 1))
            {
                k++;
                if(k==1) ble_sendData(&proc1, "G\r\n");
            }
        }
        
        if(Mux_CapSense_IsSensorActive(0, 4))
        {
            if(Mux_CapSense_IsSensorActive(0, 2))
            {
                k++;
                if(k==1) ble_sendData(&proc1, "B\r\n");
            }
        }
        
        if(Mux_CapSense_IsSensorActive(0, 4))
        {
            if(Mux_CapSense_IsSensorActive(0, 3))
            {
                k++;
                if(k==1) ble_sendData(&proc1, "W\r\n");
            }
        }
        
        if(Mux_CapSense_IsSensorActive(0, 5))
        {
            if(Mux_CapSense_IsSensorActive(0, 0))
            {
                k++;
                if(k==1) ble_sendData(&proc1, "C\r\n");
            }
        }
        
        if(Mux_CapSense_IsSensorActive(0, 5))
        {
            if(Mux_CapSense_IsSensorActive(0, 1))
            {
                k++;
                if(k==1) ble_sendData(&proc1, "M\r\n");
            }
        }
        
        if(Mux_CapSense_IsSensorActive(0, 5))
        {
            if(Mux_CapSense_IsSensorActive(0, 2))
            {
                k++;
                if(k==1) ble_sendData(&proc1, "Y\r\n");
            }
        }
        
        
        
        if(Counter_micros_ReadCounter() - prev > 200000)
        {
            Pin_Green_Write(state);
            state = ~state;
            prev = Counter_micros_ReadCounter();
        }
        
        
        
        if(Mux_CapSense_IsSensorActive(0, 7))
        {
            if(Mux_CapSense_IsSensorActive(0, 1))
            {
                k++;
                if(k==1) ble_disconnect(&proc1);
            }
        }
        
        if(Mux_CapSense_IsSensorActive(0, 7))
        {
            if(Mux_CapSense_IsSensorActive(0, 2))
            {
                k++;
                if(k==1) ble_connect(&proc1, "7cb94c3876b8");
            }
        }
    }
}

/* [] END OF FILE */