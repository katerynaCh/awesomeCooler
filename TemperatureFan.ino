#include <Wire.h>
#include "rgb_lcd.h"

int fanPin=4;

rgb_lcd lcd;
int colorR = 0;
int colorG = 255;
int colorB = 0; 

int tempPin = 1; 
void setup()
{
    pinMode(fanPin, OUTPUT);
    Serial.begin(9600);

    lcd.begin(16,2);
    delay(100);
    lcd.setRGB(colorR, colorG, colorB);
   
    // Print a message to the LCD.
    lcd.setCursor(0,0);
    delay(100);
    lcd.clear();
    lcd.print("Welcome!");
    delay(1000);
   
 
    //delay(1000);
}
 
void loop()
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
   // lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    //lcd.print(millis()/1000);
    
    float temp = analogRead(tempPin);//getting the voltage reading from the
    //temperature sensor
    temp = (float)(1023 - temp)*10000/temp;
    temp = 1/(log(temp/10000)/3975+1/298.15)-273.15; 
    lcd.clear();
    if(temp>25)//check button is pressed or not
    {
      lcd.setRGB(255,0,0);
      lcd.println("Temperature:");
      lcd.setCursor(0,1);
      lcd.println(temp);
      digitalWrite(fanPin,HIGH);
      }
      else
      {
        lcd.setRGB(0,0,255);
        lcd.println("Temperature:");
        lcd.setCursor(0,1);
        lcd.println(temp);
        digitalWrite(fanPin, LOW);
        }
    delay(5000);
}
