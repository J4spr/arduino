#include <Keypad.h>

// start keyapd layout
const byte rowCount = 4;
const byte colCount = 4;

char keypadLayout[rowCount][colCount] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};
byte rowPins[rowCount] = {9, 8, 7, 6};
byte colPins[colCount] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keypadLayout), rowPins, colPins, rowCount, colCount);
int ledPin = 10; 
// Define ledPin to a valid pin number
// End Keypad Layout

// BEGIN: ed8c6549bwf9
void setup()
{
  Serial.begin(9600);

  for (int i = 2; i <= 9; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  char keyPressed = keypad.getKey();
  if (keyPressed != NO_KEY)
  {
    Serial.print("Your pressed key: ");
    Serial.println(keyPressed);

    registerKey(keyPressed);
    outputToLed(keyPressed, ledPin);
  }
}

void registerKey(int key)
{
  if (key == 35)
  {
    outputToLed(key, ledPin);
    return;
  }
}

void outputToLed(char keyPressed, int ledPin)
{
  int num = keyPressed - '0';
  for (int i = 0; i < num; i++)
  {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}