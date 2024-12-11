
#include <LCD-I2C.h>
#include <Wire.h>

LCD_I2C lcd(0x27, 16, 2);

/* It is a good idea to use the macro F(String literal).
* This tells the compiler to store the string array in the flash memory
* instead of the ram memory. Usually you have more spare flash than ram.*/

uint8_t happy[8] =
{
    0b00000,
    0b11111,
    0b00000,
    0b00000,
    0b10001,
    0b01110,
    0b00000,
    0b00000,
};

void setup() {
  Wire.begin();
  lcd.begin(&Wire);
  lcd.display();
  lcd.backlight();
}

void loop()
{
    lcd.createChar(0, happy);
				lcd.write(0);
				delay(5000);
/*----------**********-----------*/
				//Autoscroll
    lcd.setCursor(5, 0);
    lcd.print(F("Autoscrolling"));
    lcd.setCursor(10, 1);
			delay(1500);
    lcd.autoscroll();
				
/*-------------**********---------------*/
			//print numbers
    for (int i = 0; i < 10; i++)
    {
        lcd.print(i);
        delay(200);
    }
    lcd.autoscrollOff();
    lcd.clear();
				
/*-------------***********-------------*/
    // Scroll left
    lcd.setCursor(10, 0);
    lcd.print(F("To the left!"));
    for (int i = 0; i < 10; i++)
    {
     lcd.scrollDisplayLeft();
     delay(200);
    }
			
    lcd.clear();
				
/*----------------********---------------*/			//scroll right
    lcd.print(F("To the right!"));
    for (int i = 0; i < 10; i++)
    {
     lcd.scrollDisplayRight();
     delay(200);
    }
				
    lcd.clear();
/*-------------**********---------------*/
    //Cursor
    lcd.setCursor(0, 0);
    lcd.cursor();
    lcd.print(F("Cursor")); //store in flas memory
     delay(3000);
				lcd.clear();
/*------------************------------*/
    //Cursor blink
    lcd.setCursor(0, 0);
    lcd.blink();
    lcd.print(F("Cursor blink"));
    delay(3000);
    lcd.clear();
/*-----------**********-----------------*/
    //Blink without cursor
    lcd.setCursor(0, 0);
    lcd.cursorOff();
    lcd.print(F("Just blink"));
    delay(3000);
    lcd.blinkOff();
    lcd.clear();
}
