//#include <Wire.h>
#include <LiquidCrystal_I2C.h> //https://blogmasterwalkershop.com.br/arquivos/libs/NewliquidCrystal.zip

#define sensor A0

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //ENDEREÇO DO I2C E DEMAIS INFORMAÇÕES

void setup()
{
  lcd.begin(16, 2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  lcd.setBacklight(HIGH);
}

void loop()
{
  int value = analogRead(sensor);
  Serial.println(value);
  if (value <= 400)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hoje eu :");
    lcd.setCursor(0, 1);
    lcd.print(" To MT Feliz =D");
  }
  else if (value >= 700)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hoje eu :");
    lcd.setCursor(0, 1);

    lcd.print(" To  Triste =(");
  }
  else if (400 < value < 700)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hoje eu :");
    lcd.setCursor(0, 1);
    lcd.print(" To  Feliz =)");
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("Error");
  }
  delay(2 * 1000);
}