#include <Keyboard.h>

#include <MsTimer2.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, A0, A1, A2, A3); //RS, Enable, D4, D5, D6, D7
// config teclado
#include <Keypad.h>     // libreria para llamar y utilizar el teclado matricial
const byte fil = 4;     // define numero de filas
const byte col = 4;    // define numero de columnas
char keys[fil][col] = {    // define la distribucion de teclas
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pinFil[fil] = {11, 10, 9, 8}; // pines asignados a las filas
byte pinCol[col] = {7, 6, 5, 4}; // pines asignados a las columnas
Keypad teclado = Keypad(makeKeymap(keys), pinFil, pinCol, fil, col);  // creacion del objeto (matriz)
char cont;
String dato ;
int dat = 0;
int c = 0;
void setup() {
  MsTimer2::set(1000, lectura);
  MsTimer2::start();
  lcd.begin(16, 2);
  lcd.print("INGRESE NUMERO");
  lcd.setCursor(0, 1);
}

void loop() {
  cont = teclado.getKey();
  if (cont) {

    //validaciones a espacios sobrantes del teclado para inicio
    if (cont == 'A' || cont == 'C' || cont == 'D' || cont == '#' || cont == '*') { 
      c = 1 - c;
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(9, 1);
      lcd.print("       ");
      lcd.setCursor(0, 0);
      lcd.print("CUENTA REGRESIVO");
    }
    else if (cont == 'B') {
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("REINICIO");
      delay(2000);
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("INGRESE CONTEO");
      lcd.setCursor(0, 1);
      cont = ' ';
      dato = " ";
      c = 0;
      dat = 0;
    }
    else {
      lcd.print(cont);
      dato = dato + cont;
    }
    dat = dato.toInt();
  }
}
void lectura() {
  if (c == 1 ) {
    if (dat > 0) {
      lcd.setCursor(9, 1);
      lcd.print("      ");
      lcd.setCursor(9, 1);
      lcd.print(dat);
      dat--;
    }
    else if (dat == 0) {
      lcd.setCursor(9, 1);
      lcd.print("    ");
      lcd.setCursor(9, 1);
      lcd.print(dat);
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print("FIN CONTEO");
    }
  }
}
