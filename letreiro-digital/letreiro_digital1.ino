#include <LiquidCrystal.h>
LiquidCrystal lcd (7,6,5,4,3,2);

void setup()
{
  lcd.begin(16,2);
}

void loop()
{
  lcd.setCursor(4,0);
  lcd.print("ETEC DRC");
  lcd.setCursor(5,1);
  lcd.print("2DS2 SE");
  
  for (int i=0;i<4;i++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }
  
  for (int i=0;i<8;i++)
  {
    lcd.scrollDisplayRight();
    delay(300);
  }
  
  for (int i=0;i<4;i++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }
}