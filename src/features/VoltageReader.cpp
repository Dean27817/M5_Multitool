#include <iostream>
#include <Arduino.h>
#include <M5StickCPlus.h>

class VoltageReader
{
    public:
    //shows the starting display that has the instructions on how to use the tool
    void initDisplay()
    {
        M5.Lcd.fillScreen(0);
        M5.Lcd.drawString("Voltage", 70, 10);
        M5.Lcd.drawString("Reader", 70, 40);
        M5.Lcd.drawString("Press A", 70, 70);
        M5.Lcd.drawString("To Exit", 70, 100);
        M5.Lcd.drawString("Use Pin", 70, 130);
        M5.Lcd.drawString("G26 and", 70, 160);
        M5.Lcd.drawString("GND", 70, 190, 1);
        delay(4000);
    }



    //reads the analog input and calculates the voltage from that
    //has to update every frame. I don't like it, but it does
    void ShowReadings()
    {
        while(!M5.BtnA.read())
        {
            M5.Lcd.fillScreen(0);
            M5.Lcd.drawString("Voltage", 70, 10);
            M5.Lcd.drawString("Reader", 70, 40);
            M5.Lcd.drawString("Volts", 70, 200);
            M5.Lcd.setTextSize(5);
            float volts = analogRead(G36)/565;
            M5.Lcd.drawFloat(volts, 2, 70, 90);
            M5.Lcd.setTextSize(2);
        }
    }
};

