#include "Wire.h"                    //special dec for lcd
#include "LiquidCrystal_I2C.h"       //special dec for lcd
LiquidCrystal_I2C lcd(0x27, 16, 2);  //special dec for lcd
#include <Adafruit_LiquidCrystal.h>  //lcd library
Adafruit_LiquidCrystal lcd_1();      //special dec for lcd
#include <Keypad.h>
#define passwordLength 5
const char Gled = 4;  //pin of green led
const char Rled = 3;  //pin of red led
#define Buzzer 6      //pin of Buzzer
unsigned char flag;
const byte rows = 4;  //number of rows,
const byte cols = 4;  //and columns of the keypad
unsigned char count = 0;
char hexaKeys[rows][cols] =  //initialize the keypad values
  {
    { '1', '2', '3', 'A' },
    { '4', '5', '6', 'B' },
    { '7', '8', '9', 'C' },
    { '*', '0', '#', 'D' }
  };

byte rowPins[rows] = { A0, A1, A2, A3 };  //pins of the keypad rows
byte colPins[cols] = { 9, 10, 11, 12 };   //pins of the keypad columns

//create objects of the keypad and lcd
Keypad kp = Keypad(makeKeymap(hexaKeys), rowPins, colPins, rows, cols);
char currentCursor = 6;                   //the position of the password character to be entered on the lcd
char data[passwordLength];                //array to hold the password input by the user
char dataCount = 0;                       //variable to keep track of how many characters entered so far
char password[passwordLength] = "13135";  //the password saved on the system to be compared to the user input

void BuzzCorrect()  //function used to buzz when the user enter password correctly
{
  tone(Buzzer, 10000, 200);
  delay(200);
  noTone(Buzzer);
}

void BuzzWrong()  //function used to buzz when the user enter password wrong
{
  tone(Buzzer, 1000, 200);
  delay(200);
  noTone(Buzzer);
  delay(200);
}

void Blink(char led)  //function used to blink any led
{
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
}

void openLock() {
  //replace with code to open lock
}

void closeLock() {
  //replace with code to close lock
}

void setup() {
  Serial.begin(9600);
  lcd.init();  //initialize lcd
  lcd.backlight();
  lcd.clear();            //clear lcd
  pinMode(Gled, OUTPUT);  //Set pinmode i\o of the components
  pinMode(Rled, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  //lcd will begin to ask to enter the password
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
  lcd.setCursor(currentCursor, 1);


  char key = kp.getKey();  //used to fetch the inputs of the keypad
  if (key)                 //if a key is pressed
  {
    data[dataCount] = key;  //add the character entered to the array of data
    lcd.print(key);         //display the character on the lcd
    currentCursor++;        //increment the cursor position to point to the next empty cell
    dataCount++;            //increment how many characters have been entered so far
  }
  if (dataCount == passwordLength)  //if the user entered a complete password
  {
    flag = 0;
    lcd.clear();          //it clears the lcd
    lcd.setCursor(0, 0);  //then compare the password entered with the actual password
    for (int i = 0; password[i]; ++i) {
      if (password[i] != data[i])
        flag = 1;
    }
    if (!flag)  //if the password is entered correctly
    {
      lcd.print("Password Correct!");  //display correct on the lcd,
      BuzzCorrect();                   //Buzzer buzz for nearly 1 second,
      Blink(Gled);                     //green led blinks as a sign of correct password,
      openLock();                      //and the lock opens
      lcd.clear();                     //it clears the lcd
    } else                             //if the password is entered wrong
    {
      count++;
      lcd.print("Password Wrong!");  //display wrong on the lcd,
      lcd.setCursor(0, 1);
      lcd.print("Try Again!");
      BuzzWrong();  //Buzzer buzz for nearly 2 seconds,
      Blink(Rled);  //red led blinks as a sign of correct password
      lcd.clear();  //it clears the lcd
      if (count > 2) {
        while (count != 10) {
          lcd.setCursor(0, 0);
          lcd.print("Not Allowed");
          lcd.setCursor(6, 1);
          lcd.print("To Enter!!");
          BuzzWrong();  //Buzzer buzz for nearly 2 seconds,
          Blink(Rled);
          count++;
        }
        lcd.clear();
        count = 0;
        lcd.setCursor(0, 0);
        lcd.print("Wait : ");
        for (int j = 15; j > 0; --j) {
          lcd.setCursor(7, 0);
          lcd.print(j);
          delay(1000);
          lcd.setCursor(7, 0);
          lcd.print("   ");
        }
        count = 0;
      }
    }

    //Set the variables and lcd data to the initial data
    currentCursor = 6;
    data[passwordLength] = {};
    dataCount = 0;
    lcd.setCursor(0, 0);
    lcd.print("Enter Password:");
    lcd.setCursor(currentCursor, 1);
  }
}
