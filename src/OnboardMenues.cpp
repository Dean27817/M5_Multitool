//creates the displays for the menues on the MtStick C+ hardware
#include <iostream>
#include <Arduino.h>
#include <M5StickCPlus.h>
#include <wifi.h>
class OnboardMenues
{
    public:
    //the opening screen. will only be displayed for a fer seconds
    void startingScreen()
    {
        M5.Lcd.fillScreen(0);
        M5.Lcd.drawString("M5", 70, 30);
        M5.Lcd.drawString("Digital", 70, 60);
        M5.Lcd.drawString("Multitool", 70, 90);
        M5.Lcd.drawString("Created by:", 70, 120);
        M5.Lcd.drawString("Dean Morgan", 70, 150);
        delay(4000);
    }

    //the menue that will let you choose what functions you need
    int startingMenu()
    {
        //sets screen to blank
        M5.Lcd.fillScreen(0);
        int chosenFunction = 0;
        //displays the options for the list
        M5.Lcd.setTextColor(RED, BLACK);
        M5.Lcd.drawString(options[0], 70, 30);
        M5.Lcd.setTextColor(GREEN, BLACK);
        for(int i = 1; i < optionNum; i++)
        {
            M5.Lcd.drawString(options[i], 70, (i+1)*30);
        }
        //loop called to wait for someone to select an option
        while(!M5.BtnA.read())
        {
            if(M5.BtnB.read())
            {
                //resets the privios option
                M5.Lcd.setTextColor(GREEN, BLACK);
                M5.Lcd.drawString(options[chosenFunction], 70, (chosenFunction+1)*30);
                //changes the colors to show wich object is selected
                M5.Lcd.setTextColor(RED, BLACK);
                chosenFunction++;
                if(chosenFunction >= optionNum)
                {
                    chosenFunction = 0;
                }
                M5.Lcd.drawString(options[chosenFunction], 70, (chosenFunction+1)*30);
            }
            delay(180);
        }
        M5.Lcd.setTextColor(GREEN, BLACK);
        return chosenFunction;
    }
    void ServerStart(IPAddress IP)
    {
        M5.Lcd.fillScreen(0);
        M5.Lcd.drawString("M5", 70, 10);
        M5.Lcd.drawString("MITM", 70, 40, 1);
        M5.Lcd.drawString("Starting", 70, 190, 1);
        M5.Lcd.drawString("Server", 70, 210, 1);
        delay(3000);
        M5.Lcd.fillScreen(0);
        M5.Lcd.drawString("Server", 70, 10);
        M5.Lcd.drawString("Started", 70, 40, 1);
        M5.Lcd.drawString("Server IP", 70, 140, 1);
        M5.Lcd.drawString("address: ", 70, 170, 1);
        M5.Lcd.setCursor(1, 200);
        M5.Lcd.print(IP);
    }

    void FeatureNotDone()
    {
        M5.Lcd.fillScreen(0);
        M5.Lcd.drawString("Feature", 70, 70);
        M5.Lcd.drawString("Not", 70, 100);
        M5.Lcd.drawString("Done", 70, 130);
        
    }

    private:
    const int optionNum = 7;
    String options[7] = 
    {
        "WIFI",
        "voltage",
        "I2C",
        "SPI",
        "Ohms",
        "Freq",
        "IR"
    };
};