# SecuritySystemProject
⦿ Excited to introduce "Security System Project" that is integration between Embadded Systems and PCB Design!
⦿ Project Name: "Security System Project"
⦿ Components Used: - Arduino Uno
                 - LCD 16X2 I2C
                 - 2 LEDS (RED, GREEN)
                 - BUZZER 5V
                 - KEYPAD 4X4
                 - 2 RESISTORS 220 Ohm
                 
⦿ Software Used: - Eagle Cad Autodesk
               - Wokwi Website for online Siumulation
               - Arduino IDE for verification
               
⦿ How It Works: User must enter the five password numbers in exitence of Keypad and LCD. LCD shows: Enter the password, shows the numbers entered by the user thus there are two cases for the password entered:
1) If the password entered is correct, LCD shows: "Password Correct!", Buzzer will rung high frequency tone, Green led turns on, both for nearly 1 sec.
2) If the password entered is Wrong, LCD shows: "Password Wrong!" "Try Again!" for 3 tries, each try Buzzer will rung low frequency tone, Red led turns on, both for nearly 1 sec. If the password entered is Wrong in all tries, LCD shows: "Not Allowed To Enter!!" ,Buzzer will rung security police tone and the red led will blinking both for 10 Sec after that user will wait for 15 Sec for trying again the two above cases,  LCD shows: "Wait: // Seconds counted 15 to 1 //".

                                                             *Don't worry there are an Example Scenario Video*
⦿ PCB Part: PCB 15x14cm Designed in EagleCad software with best accuracy as much as i can.

