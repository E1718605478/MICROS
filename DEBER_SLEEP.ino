/* UNIVERSIDAD TÉCNICA DEL NORTE
          FICA CIEROM
   NOMBRE: MAX CÓNDOR
   DEBER SLEEP
   Realizar un ejercicio que cada 2 segundos el sistema se encuentre
   activado y cada 10 segundos
   el sistema baje su consumo de corriente.
   Envíe mensajes de comunicación serial para mostrar el resultado.
*/
#include<TimerOne.h>
#include<avr/sleep.h>
#include<avr/power.h>
#include <avr/wdt.h>
#include<EEPROM.h>

int est;
int con= 0;


void setup() {
  Serial.begin(9600);
  est = EEPROM.read(0);
  EEPROM.write(0, 1);
  attachInterrupt(0, wakeup1, LOW);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(conteo);
  set_sleep_mode(SLEEP_MODE_IDLE);   // modo sleep usado modo IDLE
  Serial.begin(9600);               
  Serial.println(est);


}

void loop() {
  activar();
  dormir();

}

void conteo() {
  con++;

}

void wakeup1() {
  sleep_disable();
  Serial.println("DESPERTAR");
  con = 0;
}
void activar() {
  if (con == 2 ) {
    Serial.println("MODO ACTIVO");
    Serial.println(con);
  }
}
void dormir() {
  if (con == 4) {
    Serial.println("SLEEP..");
    EEPROM.update(0, 0);
    sleep_mode();
    sleep_enable();
  } if (con == 10) {
    sleep_disable();
    con = 0;
  }
}
