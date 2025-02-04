// Imports of libraries 
#include <LiquidCrystal.h>

// LCD and pin definitions
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
const int buttonPin = 0;
const int redLedPin = 3;
const int greenLedPin = 5;

// Set up loop runs once 
void setup() {
  // Start LCD
  lcd.begin(16, 2);
  // Clears LCD 
  lcd.clear();

  Serial.begin(9600);
  // First LCD Usage 
  Serial.println("Luck O' Meter");

// Setting Up Pins 
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  // Startup Animation with title
  lcd.print("Luck O' Meter");
  delay(1000);
  lcd.clear();
// Animation 
  for (int i = 0; i < 16; i++) {
    lcd.setCursor(i, 0);
    lcd.print("/");
    delay(50);
    lcd.setCursor(i, 0);
    lcd.print("-");
    delay(50);
    lcd.setCursor(i, 0);
    lcd.print("\\");
    delay(50);
    lcd.setCursor(i, 0);
    lcd.print("|");
    delay(50);
  }
}


// Main loop that runs more than once 
void loop() {
  int buttonState = digitalRead(buttonPin);
// Reads button state 
  if (buttonState == LOW) {
    // Turn on all LEDs
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, HIGH);

    // Number cycling animation
    for (int i = 0; i <= 100; i += 10) {
      lcd.setCursor(0, 0);
      lcd.print("Number: ");
      lcd.print(i);
      delay(100);
    }

    int randomNumber = random(0, 101);

    // Random number display animation
    animateRandomNumberDisplay(randomNumber);

    // Display as percentage
    lcd.setCursor(0, 0);
    lcd.print("Luck: ");
    lcd.print(randomNumber);
    lcd.print("%");

    // LED control
    if (randomNumber > 80) {
      digitalWrite(greenLedPin, HIGH);
      digitalWrite(redLedPin, LOW);
    } else {
      digitalWrite(greenLedPin, LOW);
      digitalWrite(redLedPin, HIGH);
    }

    delay(500); // Display the result for a short time
    digitalWrite(redLedPin, LOW);  // Turn off LEDs
    digitalWrite(greenLedPin, LOW);
    delay(200); // Debounce
  }
}


// Function Animates Random Number Display 
void animateRandomNumberDisplay(int number) {
  int animationSteps = 10;
  lcd.clear();

  for (int i = 0; i <= animationSteps; i++) {
    int displayedNumber = random(0, 101);
    lcd.setCursor(0, 0);
    lcd.print("Luck: ");  
    // Keep the "Luck: " prefix
    lcd.print(displayedNumber);
    lcd.print("%"); 
    // Keep the "%" sign
    delay(50);
  }
  lcd.setCursor(0, 0);
  // Keep the "Luck: " prefix
  lcd.print("Luck: "); 
  lcd.print(number);
  // Keep the "%" sign
  lcd.print("%"); 
}
