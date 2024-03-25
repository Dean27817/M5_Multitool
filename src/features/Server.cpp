#include <iostream>
#include <Arduino.h>
#include <M5StickCPlus.h>
#include <wifi.h>


//I literally have no idea what this does

class WifiManager
{
    public:
    void initializeServer(WiFiServer& server)
    {
        WiFiClient client = server.available();   // Listen for incoming clients

        //checks if the client is connected before starting the server
        if (client) 
        {
            M5.Lcd.fillScreen(0);
            M5.Lcd.drawString("Client", 70, 10);
            M5.Lcd.drawString("Connected", 70, 40, 1);
            IPAddress IP = WiFi.softAPIP();
            M5.Lcd.drawString("AP IP", 70, 140, 1);
            M5.Lcd.drawString("address: ", 70, 170, 1);
            M5.Lcd.setCursor(1, 200);
            M5.Lcd.print(IP);

            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1>");
            client.println("</body></html>");
        }
    }
};