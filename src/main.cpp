//prebuilt librarys
#include <Arduino.h>
#include <WiFi.h>
#include <M5StickCPlus.h>
#include <string>

//custom extra files
#include "features/Server.cpp"
#include "OnboardMenues.cpp"
#include "features/VoltageReader.cpp"

//the login credentials for the wifi
const char* ssid     = "Samsung Galaxy S24 Ultra Hotspot";
const char* password = "WhyWouldYouGuessThis";

// Set web server port number to 80
WiFiServer server(80);

//the object created to controll the display on the M5
OnboardMenues display;

//used to communicate what the user wants to do
int chosenFunction = 0;

void setup() {
    M5.begin();
    //display settings
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(GREEN, BLACK);
    M5.Lcd.setTextDatum(TC_DATUM);
    //opening screen
    display.startingScreen();
    //desplays the starting menue to let people decide what they need to use
    //returns an int to indicate what the rest of the code needs to do
    chosenFunction = display.startingMenu();


    //if the user chose the wifi function, this sets up the server
    if(chosenFunction == 0)
    {
      //starts the wifi server
      WiFi.softAP(ssid, password);
      //gets the ip address from softAP and prints it to the screen
      IPAddress IP = WiFi.softAPIP();
      display.ServerStart(IP);
      //starts the local server
      server.begin();
    }
}

void loop() {
  //if the user wants to use the wifi, this serves them the html file
  if(chosenFunction == 0)
  {
    WifiManager wifiObject;
    while(!M5.BtnA.read())
    {
      wifiObject.initializeServer(server);
    }    
    setup();
  }
  else if(chosenFunction == 1)
  {
    VoltageReader volts;
    volts.initDisplay();
    volts.ShowReadings();
    setup();
  }
  else
  {
    display.FeatureNotDone();
    delay(6000);
    setup();
  }
}