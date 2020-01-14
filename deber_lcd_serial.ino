#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 7, 6, 5, 4);
String dat;
String ing_pal;
int i = 0;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);// inicia lcd


}

void loop() {
  lcd.setCursor(0, 0);// setea esa ubicacion
  lcd.print("Ingreso palabra");// verificacion datos vacios
  if (Serial.available() > 0) {
    dat = Serial.readString(); //lectura de datos ingresados
    lcd.setCursor(0, 0);
    lcd.print("               ");
    lcd.setCursor(0, 0);
    for (i = 0; i < dat.length(); i++) {
      ing_pal = ing_pal + dat.substring(i, i + 1);
    }
    lcd.print(ing_pal);//impresion palabra ingresada
    delay(2000);
    for (; i <= 16 ; i++) {     //ciclo repetitivo de conteo de espacios movidos por la palabra ingresada
      lcd.scrollDisplayRight();
      delay(100);
    }
    for (; i >= 16 ; i++) {
      lcd.scrollDisplayLeft();
      delay(100);
    }
  }
  
}
