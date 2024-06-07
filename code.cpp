#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

const int tempSensorPin = A0;
const int pHSensorPin = A1;
const int oxygenSensorPin = A2;
const int salinitySensorPin = A3;
const int buzzerPin = 8;

float temperature;
float pH;
float oxygen;
float salinity;

int displayState = 0;

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  int tempValue = analogRead(tempSensorPin);
  temperature = (tempValue * (5.0 / 1023.0) - 0.5) * 100.0;

  int pHValue = analogRead(pHSensorPin);
  pH = pHValue * (14.0 / 1023.0);

  int oxygenValue = analogRead(oxygenSensorPin);
  oxygen = oxygenValue * (20.0 / 1023.0);

  int salinityValue = analogRead(salinitySensorPin);
  salinity = salinityValue * (50.0 / 1023.0);

  lcd.clear();

  switch (displayState)
  {
  case 0:
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C");
    lcd.setCursor(0, 1);
    if (temperature < 0)
    {
      lcd.print(" (baixa)");
    }
    else if (temperature > 30)
    {
      lcd.print(" (alta)");
    }
    else
    {
      lcd.print(" (OK)");
    }
    break;
  case 1:
    lcd.setCursor(0, 0);
    lcd.print("pH: ");
    lcd.print(pH);
    if (pH < 6)
    {
      lcd.print(" (baixo)");
    }
    else if (pH > 8)
    {
      lcd.print(" (alto)");
    }
    else
    {
      lcd.print(" (OK)");
    }
    break;
  case 2:
    lcd.setCursor(0, 0);
    lcd.print("O2: ");
    lcd.print(oxygen);
    if (oxygen < 5)
    {
      lcd.print(" (baixo)");
    }
    else if (oxygen > 12)
    {
      lcd.print(" (alto)");
    }
    else
    {
      lcd.print(" (OK)");
    }
    break;
  case 3:
    lcd.setCursor(0, 0);
    lcd.print("Sal: ");
    lcd.print(salinity);
    if (salinity < 30)
    {
      lcd.print(" (baixa)");
    }
    else if (salinity > 40)
    {
      lcd.print(" (alta)");
    }
    else
    {
      lcd.print(" (OK)");
    }
    break;
  }

  displayState++;
  if (displayState > 3)
  {
    displayState = 0;
  }

  if (temperature < 0 || temperature > 30 || pH < 6 || pH > 8 || oxygen < 5 || oxygen > 12 || salinity < 30 || salinity > 40)
  {
    tone(buzzerPin, 1000);
    delay(500);
    noTone(buzzerPin);
  }
  delay(2000);
}
