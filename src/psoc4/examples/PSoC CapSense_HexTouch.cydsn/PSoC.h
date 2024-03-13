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
#include "stdlib.h"
#include "stdio.h"

#ifndef PSOC_H
#define PSOC_H

#define TIMEOUT 1000
#define ADC_MODE 0
#define DAC_MODE 1

#define BLE 1
#define USB 0
    
#define LOW   0
#define HIGH  1

#define ON  0
#define OFF 1

#define C1   11
#define C2   12
#define C3   13
#define C4   14
#define C5   15
#define C6   16
#define C7   17
#define C8   18
#define C9   19
#define C10 110
#define C11 111
#define C12 112
#define C13 113
#define C14 114
#define C15 115
#define C16 116

#define C_A  11
#define C_B  12
#define C_C  13
#define C_D  14
#define C_E  15
#define C_F  16
#define C_G  17
#define C_H  18
#define C_I  19
#define C_J 110
#define C_K 111
#define C_L 112
#define C_M 113
#define C_N 114
#define C_O 115
#define C_P 116

# define O1  0
# define O2  1
# define O3  2
# define O4  3
# define O5  4
# define O6  5
# define O7  6
# define O8  7
# define O9  8
# define O10 9
# define O11 10
# define O12 11
# define O13 12
# define O14 13
# define O15 14
# define O16 15

# define I1  0
# define I2  1
# define I3  2
# define I4  3
# define I5  4
# define I6  5
# define I7  6
# define I8  7
# define I9  8
# define I10 9
# define I11 10
# define I12 11
# define I13 12
# define I14 13
# define I15 14
# define I16 15

#define MISO 59
#define MOSI 58
#define SCLK 60

#define SCL 12
#define SDA 13

#define AMOSI 38
#define AMISO 37

#define ANALOG_IO 8
#define R_LED 64
#define G_LED 15
#define B_LED 6
    

    
struct PSC_McM_6_00{
    uint8 A_Dstate;
    uint32 A_D_period;
    struct boardconf{
        uint8 reserved;
        uint8 brdtype;
        uint8 brdno;
    }b;
    uint8_t con_, sync_;
    struct {
        uint8 timer;// = 6;
        uint freq;// = 5000;
        uint res;//  = 12;
    }dac;
    struct {
        uint32_t device_id;
    }flash;
    struct{
        char ssid[100];
        char password[100];
        char mac[20];
    }bleWiFi;
};

void setmux(struct PSC_McM_6_00 *p, int a){
    switch(a){
        case  I1:    S3_Write(0);   S2_Write(0);    S1_Write(0);    S0_Write(0);     break;
        case  I2:    S3_Write(0);   S2_Write(0);    S1_Write(0);    S0_Write(1);     break;
        case  I3:    S3_Write(0);   S2_Write(0);    S1_Write(1);    S0_Write(0);     break;
        case  I4:    S3_Write(0);   S2_Write(0);    S1_Write(1);    S0_Write(1);     break;
        case  I5:    S3_Write(0);   S2_Write(1);    S1_Write(0);    S0_Write(0);     break;
        case  I6:    S3_Write(0);   S2_Write(1);    S1_Write(0);    S0_Write(1);     break;
        case  I7:    S3_Write(0);   S2_Write(1);    S1_Write(1);    S0_Write(0);     break;
        case  I8:    S3_Write(0);   S2_Write(1);    S1_Write(1);    S0_Write(1);     break;
        case  I9:    S3_Write(1);   S2_Write(0);    S1_Write(0);    S0_Write(0);     break;
        case I10:    S3_Write(1);   S2_Write(0);    S1_Write(0);    S0_Write(1);     break;
        case I11:    S3_Write(1);   S2_Write(0);    S1_Write(1);    S0_Write(0);     break;
        case I12:    S3_Write(1);   S2_Write(0);    S1_Write(1);    S0_Write(1);     break;
        case I13:    S3_Write(1);   S2_Write(1);    S1_Write(0);    S0_Write(0);     break;
        case I14:    S3_Write(1);   S2_Write(1);    S1_Write(0);    S0_Write(1);     break;
        case I15:    S3_Write(1);   S2_Write(1);    S1_Write(1);    S0_Write(0);     break;
        case I16:    S3_Write(1);   S2_Write(1);    S1_Write(1);    S0_Write(1);     break;
    }
}

void delay(int val){
    CyDelay(val);
}

void switchTo(uint8 val){
    uint16 timeout=10000;
    while(UART_SpiUartGetTxBufferSize() != 0 && timeout){timeout--;};
    UART_SpiUartClearTxBuffer();
    UART_SpiUartClearRxBuffer();
    CTRL_Write(val);
}

void PSC_McM_6_00_init(struct PSC_McM_6_00 *p){
    UART_Start();
    switchTo(USB);
}

//ble+wifi

int sendCmd(struct PSC_McM_6_00 *p, char *cmd, char *rec_data, int len, unsigned long long timeout, uint8_t Delay){

    switchTo(BLE);
    
    int i=0, temp=0;
    char *ptr = rec_data;
    unsigned long long to = timeout;
    UART_UartPutString(cmd);
      
    if(Delay) delay(1000);
    
    for(;;)
    {
        to--;
        if(!to) {temp = -2; break;}
       
        if((UART_SpiUartGetRxBufferSize() != 0) && i<len)
        {
            rec_data[i] = UART_SpiUartReadRxData();

            if ((i>4) && (strncmp(ptr-5, "\r\nOK\r\n",6)==0))     {temp = i-6; break;}
            if ((i>7) && (strncmp(ptr-8, "\r\nERROR\r\n",9)==0))  {temp =  -1; break;}
          
            i++; ptr++;
        }
    }
    
    switchTo(USB);

    return temp;
}

int ble_mac(struct PSC_McM_6_00 *p, char *mac)
{
    uint8_t result=0, j=0;
    char cmd[20] = "AT+BLEMAC?\r\n";
    char rec_data[65];
    char *ptr = rec_data;

    result = sendCmd(p, cmd, rec_data, 65, 10000, 0);

    if(result>=0)
    {
        while(*ptr != ':')  ptr++;
        ptr++;
      
        while(*ptr != '\r')
        {
            mac[j] = *ptr;
            j++; ptr++;
        }
    }

    if(result>=0) return 0;
    return -1;
}

int ble_checkRFpower(struct PSC_McM_6_00 *p)
{
    int8_t result;
    char rec_data[60],*ptr;
    char cmd[18] = "AT+BLERFPWR?\r\n";

    delay(1000);
    
    result = sendCmd(p, cmd, rec_data, 60, 100000, 0);
    ptr = &rec_data[60];
    if (result>=0)
    {
        while(*ptr != ':')  ptr--;
        ptr++;
        return(atof(ptr));
    }
    return -1;
}

int ble_setRFpower(struct PSC_McM_6_00 *p, int val)
{        
    char rec_data[60];
    int result;
    char buffer[20], cmd[15] = "AT+BLERFPWR=";

    if(val<0) return -2;

    sprintf(buffer, "%s%d\r\n", cmd, val);
    
    result = sendCmd(p, buffer, rec_data, 60, 1000000, 0);
    
    if(result >= 0) return 0;
    return -1;
}

int ble_status(struct PSC_McM_6_00 *p)
{    
    uint8_t result, i;
    char rec_data[40],*ptr;
    char cmd[15] = "AT+BLEMODE?\r\n";

    UART_UartPutString("9: BLE is OFF.\n0: BLE is configured in Slave Mode.\n1: BLE is configured in Host Mode.\n\n");
    result = sendCmd(p, cmd, rec_data, 40, 100000, 0);
    ptr = rec_data;
    if (result>=0)
    {
        while(*ptr != ':')  ptr++;
        ptr++;
        return (atoi(ptr));
    }
    return -1;
}

int ble_OFF(struct PSC_McM_6_00 *p)
{    
    int status;
    status = ble_status(p);
    if(status == 9) return 9;
    
    char rec_data[25],*ptr;
    int result;
    char cmd[18] = "AT+BLEMODE=9\r\n";
    
    result = sendCmd(p, cmd, rec_data, 25, 100000, 0);
    ptr = rec_data;
    if (result>=0)
    {
        while(*ptr != '=')  ptr++;
        ptr++;
        return (atoi(ptr));
    }
    return -1;
}

int bleON_host(struct PSC_McM_6_00 *p)
{
    int status;
    status = ble_status(p);
    if (status == 1) return 1;
    
    char rec_data[25],*ptr;
    int result;
    char cmd[18] = "AT+BLEMODE=1\r\n";
    
    result = sendCmd(p, cmd, rec_data, 100, 1000000, 0);
    ptr = rec_data;
    if (result>=0)
    {
        while(*ptr != '=')  ptr++;
        ptr++;
        return (atoi(ptr));
    }
    return -1;
}

int bleON_slave(struct PSC_McM_6_00 *p)
{    
    int status;
    status = ble_status(p);
    if (status == 0) return 0;
    
    char rec_data[25],*ptr;
    int result;
    char cmd[18] = "AT+BLEMODE=0\r\n";
    
    result = sendCmd(p, cmd, rec_data, 25, 1000000, 0);
    ptr = rec_data;
    if (result>=0)
    {
        while(*ptr != '=')  ptr++;
        ptr++;
        return(atoi(ptr));
    }
    return -1;
}

int ble_connect(struct PSC_McM_6_00 *p, char *mac){
    int result;
    char rec_data[100];
    char buffer[40];
    
    sprintf(buffer, "AT+BLECONNECT=%s\r\n", mac);
    result = sendCmd(p, buffer, rec_data, 100, 1000000, 0);
    if(result >= 0) return 0;
    return -1;
}

int ble_disconnect(struct PSC_McM_6_00 *p)
{
    int result;
    char rec_data[10];
    char cmd1[5] = "+++";
    char cmd2[18] = "AT+BLEDISCON\r\n";
    
    sendCmd(p, cmd1, rec_data, 10, 100000, 0);
    result = sendCmd(p, cmd2, rec_data, 10, 100000, 0);
    
    if(result) return 0;
    return -1;
}

int ble_sendData(struct PSC_McM_6_00 *p, char *send)
{
    char buffer[1000];
    
    sprintf(buffer, "%s%s", send, "\r\n");
    switchTo(BLE);
    UART_UartPutString(buffer);
    delay(1);
    switchTo(USB);
    return 0;
}

//int ble_receiveData(struct PSC_McM_6_00 *p)
//{
//    char rec_data = 0;
//    switchTo(BLE);
//    if(UART_SpiUartGetRxBufferSize() != 0)
//        rec_data = UART_SpiUartReadRxData();
//    delay(1);
//    switchTo(USB);
//    return rec_data;
//}





int WiFi_mac(struct PSC_McM_6_00 *p, char *mac)
{
    char rec_data[60],*ptr;
    int result, j=0;
    char cmd[25] = "AT+CIPSTAMAC_DEF?\r\n";
    
    result = sendCmd(p, cmd, rec_data, 60, 100000, 0);
    ptr = rec_data;
    if (result>=0)
    {
        while(*ptr != ':')  ptr++;
        ptr++;

        while(*ptr != '\r')
        {
          mac[j] = *ptr;
          j++; ptr++;
        }
    }
    if(result>=0)  return 0;
    return -1;
}

int WiFi_status(struct PSC_McM_6_00 *p)
{    
    uint8_t result;
    char rec_data[25],*ptr;
    char cmd[15] = "AT+WMODE?\r\n";

    UART_UartPutString("0: WiFi is OFF.\n1: WiFi is configured as STA.\n2: WiFi is configured AP.\n3: WiFi is configured AP+STA.\n\n");
    
    result = sendCmd(p, cmd, rec_data, 25, 100000, 0);
    ptr = rec_data;
    if (result>=0)
    {
        while(*ptr != ':')  ptr++;
        ptr++;
        return (atoi(ptr));
    }
    return -1;
}

int WiFi_OFF(struct PSC_McM_6_00 *p)
{    
    char rec_data[30],*ptr;
    int result;
    char cmdRst[10] = "AT+RST\r\n";
    char cmdWoff[18] = "AT+WMODE=0,0\r\n";
    
    result = sendCmd(p, cmdRst, rec_data, 30, 10000, 0);
    delay(800);
    UART_SpiUartClearRxBuffer();
    result = sendCmd(p, cmdWoff, rec_data, 30, 100000, 0);
    
    if(result >= 0)  return 0;
    return -1;    
}

int WiFiON_STA(struct PSC_McM_6_00 *p)
{    
    char rec_data[25],*ptr;
    int result;
    char cmd[18] = "AT+WMODE=1,0\r\n";
    
    result = sendCmd(p, cmd, rec_data, 25, 100000, 0);
    ptr = rec_data;
    if (result>=0)
    {
        while(*ptr != ',')  ptr++;
        ptr--;
        return (atoi(ptr));
    }
    return -1;   
}

int WiFiON_AP(struct PSC_McM_6_00 *p)
{    
    char rec_data[25],*ptr;
    int result;
    char cmd[18] = "AT+WMODE=2,0\r\n";
    
    result = sendCmd(p, cmd, rec_data, 25, 100000, 0);
    ptr = rec_data;
    if (result>=0)
    {
        while(*ptr != ',')  ptr++;
        ptr--;
        return (atoi(ptr));
    }
    return -1;   
}

int WiFiON_AP_STA(struct PSC_McM_6_00 *p)
{    
    char rec_data[25],*ptr;
    int result;
    char cmd[18] = "AT+WMODE=3,0\r\n";
    
    result = sendCmd(p, cmd, rec_data, 25, 100000, 0);
    ptr = rec_data;
    if (result>=0)
    {
        while(*ptr != ',')  ptr++;
        ptr--;
        return (atoi(ptr));
    }
    return -1;   
}

int WiFi_scan(struct PSC_McM_6_00 *p, char *rec_data)
{
    int result, i=0;
    char *ptr;
    char cmd[12] = "AT+WSCAN\r\n";

    UART_UartPutString("Scanning...");
    result = sendCmd(p, cmd, rec_data, 1000, 80000000, 0);
    ptr = rec_data;

    while(*ptr != '+')  ptr++;
    while(strncmp(ptr, "\r\nOK\r\n", 6) != 0)
    {
      rec_data[i] = *ptr;
      i++; ptr++;
    }
    rec_data[i] = 0;
    UART_UartPutString("Scanning Complete.");
    
    if(result >= 0)  return 0;
    return -1;
}

int WiFi_connect(struct PSC_McM_6_00 *p, char* ssid, char* password)
{
    char buffer[100],rec_data[200];
    int result;

    UART_UartPutString("Trying to connect with ");
    UART_UartPutString(ssid);UART_UartPutString("...\n");
    sprintf(buffer, "AT+WJAP=%s,%s\r\n", ssid,  password);
    result = sendCmd(p, buffer, rec_data, 200, 100000000, 0);
    if(result >= 0)  {UART_UartPutString("Connected\n"); return 0;}
    UART_UartPutString("Connection failed\n"); return -1;
}

int WiFi_disconnect(struct PSC_McM_6_00 *p)
{
    int result;
    char rec_data[200];
    char cmd[10] = "AT+RST\r\n";
    
    result = sendCmd(p, cmd, rec_data, 200, 1000000, 0);
    if(result >= 0)  return 0;
    return -1;
}

int WiFi_whoRu(struct PSC_McM_6_00 *p, char *ssid)
{
    int result, i=0;
    char rec_data[200], *ptr;
    char cmd[13] = "AT+WJAP?\r\n";
    
    result = sendCmd(p, cmd, rec_data, 200, 1000000, 0);
    ptr = rec_data;

    if(result >= 0)
    {
      while(*ptr != ',')  ptr++;
      ptr++;
      
      while(*ptr != ',')
      {
        ssid[i] = *ptr;
        i++; ptr++;
      }
      ssid[i] = 0;
    }
    
    if(result >= 0)  return 0;
    return -1;
}

int WiFi_sendData(struct PSC_McM_6_00 *p, char *trans_type, char *opt, char *host, char *path, int data)
{    
    int type, optype, port, result;
    char buffer[200], rec_data[200];
    
    if((strcmp(trans_type,"HTTP")==0)  ||  (strcmp(trans_type,"http")==0)) {type = 1; port = 80 ;}
    if((strcmp(trans_type,"HTTPS")==0) || (strcmp(trans_type,"https")==0)) {type = 2; port = 443;}
    if((strcmp(opt,"GET")==0)  ||  (strcmp(opt,"get")==0)) optype = 2;
    if((strcmp(opt,"POST")==0) || (strcmp(opt,"post")==0)) optype = 3;
    
    sprintf(buffer, "AT+HTTTPCLIENTLINE=%d,%d,application/json,%s,%d,%s,%d\r\n", type, optype, host, port, path, data);
    result = sendCmd(p, buffer, rec_data, 200, 100000000, 0);
    
    if(result>=0)  return 0;
    return -1;
}

int WiFi_receiveData(struct PSC_McM_6_00 *p, char *trans_type, char *opt, char *host, char *path, char *readData)
{    
    int type, optype, port, result, i=0, j=0;
    char buffer[200], rec_data[500];
    
    if((strcmp(trans_type,"HTTP")==0)  ||  (strcmp(trans_type,"http")==0)) {type = 1; port = 80 ;}
    if((strcmp(trans_type,"HTTPS")==0) || (strcmp(trans_type,"https")==0)) {type = 2; port = 443;}
    if((strcmp(opt,"GET")==0)  ||  (strcmp(opt,"get")==0)) optype = 2;
    if((strcmp(opt,"POST")==0) || (strcmp(opt,"post")==0)) optype = 3;
    
    sprintf(buffer, "AT+HTTTPCLIENTLINE=%d,%d,application/json,%s,%d,%s\r\n", type, optype, host, port, path);
    result = sendCmd(p, buffer, rec_data, 500, 10000000, 0);

    while(rec_data[i] != '{')  i++;
    while(rec_data[i] != '\n')
    {
      readData[j] = rec_data[i];
      if(rec_data[i] == ',')
      {
        j++;
        readData[j] = '\n';
      }
      i++; j++;
    }
    while(readData[j] != '}')  j--;
    readData[j+1] = 0;

    UART_UartPutString("Getting data. Please wait...");
    delay(40000);
    UART_UartPutString("Just a bit longer...\n");
    delay(10000);
    
    if(readData[j] == '}')  return 0;
    return -1;
}

    
#endif
/* [] END OF FILE */
