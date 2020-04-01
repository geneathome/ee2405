#include "mbed.h"
#include "uLCD_4DGL.h"


uLCD_4DGL uLCD(D1, D0, D2);

PwmOut PWM1(D6);
AnalogIn Ain(A0);
Serial pc( USBTX, USBRX );
float ADCdata[128];

int sample = 128;


int main()
{

        PWM1.period(0.001);
        
        int i;
        float j = 0;
        float k = 0.1;

        for(i = 0; i < sample; i ++){
            PWM1 = j;
            ADCdata[i] = PWM1;
            j = j + k;
            if(j == 1 ){
                k = -0.1;
            }
            if(j == 0 ){
                k = 1;
            }
            wait(1./sample);
        }

        for (i = 0; i < sample; i++){
            pc.printf("%1.3f\r\n", ADCdata[i]);
            wait(0.1);
        }



        // for(i = 0; i <= 1; i = i + 0.1){
        //     PWM1 = i;
        // }
        // for(i = 1; i >= 0; i = i - 0.1){
        //     PWM1 = i;
        // }
        uLCD.printf("\n106061146\n"); //Default Green on black text
        uLCD.line(30, 30 , 30, 60, RED);
        uLCD.line(30, 60 , 60, 60, RED);
        uLCD.line(60, 60 , 60, 30, RED);
        uLCD.line(60, 30 , 30, 30, RED);




    //   wait(30);
}