   /*UNIVERSIDDAD TÉCNICA DEL NORTE
            FICA CIERCOM
   NOMBRE:MAX CÓNDOR
   DEBER POWER
   Realizar un programa que cada 5 segundos el sistema desactiva 
   el conversor análogo digital,  cada 8 segundos la comunicación
   serial y cada 12 segundos desactivación total.
   Esta información debe verse en una LCD. 
   
*/

#include <LowPower.h>
#include <avr/wdt.h>
#include <EEPROM.h>
#include<avr/sleep.h>
#include <MsTimer2.h>
#include <TimerOne.h>
#include <avr/power.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);

int var = EEPROM.read(0);
int con = 0;
int dat;
int pLcd = 6;

void setup() {
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(conteo);
  power_all_enable();
  lcd.begin(16, 2);
  var = 0;
}

void loop() {
  Serial.println(var);
  dormir();
  lcd.setCursor(6, 1);
  lcd.print("Tiempo:" + String(con));
  dat = analogRead(0);
  lcd.setCursor(0, 1);
  lcd.print(dat);
}
void conteo() {
  con++;
}

void dormir() {
  if (con == 5) {
    var = var + 1;
    lcd.setCursor(0, 0);
    lcd.print("CAD DESACTIVADO");
    power_adc_disable();

  }
  if (con == 8) {
    lcd.setCursor(0, 0);
    lcd.print("                     ");
    lcd.setCursor(0, 0);
    lcd.print("COM DESACTIVADO");
    power_spi_disable();
  }
  if (con == 12) {
    lcd.setCursor(0, 0);
    lcd.print("                    ");
    lcd.setCursor(0, 0);
    lcd.print("DESACTIVADO");
    power_all_disable();
  }
  if (EEPROM.read(0) > 12) {
    var = 0;
    power_all_enable();
    EEPROM.write(0, var);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("REINICIO");
    lcd.setCursor(0, 1);
    lcd.print("DEL SISTEMA");
    digitalWrite(pLcd, HIGH);
    delay(10);
    wdt_enable(WDTO_1S);

  }
}
