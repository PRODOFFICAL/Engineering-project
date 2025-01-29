// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// variable to store the timer value
unsigned long startTime = 0;
bool timerRunning = true;
const int buttonPin = 2; // button connected to GPIO pin 2

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello, World!");

  // initialize the button pin as input
  pinMode(buttonPin, INPUT_PULLUP);

  // record the start time
  startTime = millis();
}

void loop() {
  // read the state of the button
  int buttonState = digitalRead(buttonPin);

  // if the button is pressed, stop the timer
  if (buttonState == LOW) {
    timerRunning = false;
  }

  // update the display if the timer is running
  if (timerRunning) {
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
    // print the number of seconds since reset
    lcd.print((millis() - startTime) / 1000);
  }
}
