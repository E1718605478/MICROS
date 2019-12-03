



String pal;
String juego1;
String juego2;
String juego3;
String juego4;



void setup() {

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);

  Serial.println("Ingrese una combinacion al juego de luces ");


  Serial.println(" ACBF = juego luces 1");
  Serial.println(" ACGF = juego luces 2");
  Serial.println(" ADBF = juego luces 3");
  Serial.println(" ADBH = juego luces 4");
  Serial.println(" para ello debera ingresar la cadena de caracteres mostrada en pantalla");

  delay(300);
}

void   juegoLeds(boolean a, boolean b, boolean c, boolean d, boolean e)
{
  digitalWrite(8, a);
  digitalWrite(9, b);
  digitalWrite(10, c);
  digitalWrite(11, d);
  digitalWrite(12, e);

}

void loop() {


  if (Serial.available() > 0) {
    pal = Serial.readString();
    Serial.println("\n");
    Serial.println(pal);
    if (pal == "ACBF") {
      Serial.println("vam bien 1"); //primer juego de luz
      juegoLeds(0, 0, 1, 0, 0);
      delay(500);
      juegoLeds(0, 1, 0, 1, 0);
      delay(500);
      juegoLeds(1, 1, 0, 1, 1);
      delay(500);
      juegoLeds(0, 0, 1, 0, 0);
      delay(500);
      juegoLeds(0, 1, 0, 1, 0);
      delay(500);
      juegoLeds(1, 1, 0, 1, 1);
      delay(500);
      juegoLeds(1, 1, 1, 1, 1);
      delay(500);
      juegoLeds(0, 0, 0, 0, 0);
      delay(500);
    }
    if (pal == "ACGF") {
      Serial.println("vam bien 2"); //segundo juego de luz
      juegoLeds(1, 0, 0, 0, 0);
      delay(500);
      juegoLeds(1, 1, 0, 0, 0);
      delay(500);
      juegoLeds(1, 1, 1, 0, 0);
      delay(500);
      juegoLeds(1, 1, 1, 1, 0);
      delay(500);
      juegoLeds(1, 1, 1, 1, 1);
      delay(500);
      juegoLeds(1, 1, 1, 1, 0);
      delay(500);
      juegoLeds(1, 1, 1, 0, 0);
      delay(500);
      juegoLeds(1, 1, 0, 0, 0);
      delay(500);
      juegoLeds(1, 0, 0, 0, 0);
      delay(500);
      juegoLeds(1, 1, 1, 1, 1);
      delay(500);
      juegoLeds(0, 0, 0, 0, 0);
      delay(500);
    }
    if (pal == "ADBF") {
      Serial.println("vam bien 3"); // tercer juego de luz
      juegoLeds(1, 0, 1, 0, 1);
      delay(500);
      juegoLeds(0, 1, 0, 1, 0);
      delay(500);
      juegoLeds(1, 0, 1, 0, 1);
      delay(500);
      juegoLeds(0, 1, 0, 1, 0);
      delay(500);
      juegoLeds(1, 1, 1, 1, 1);
      delay(500);
      juegoLeds(0, 1, 1, 1, 0);
      delay(500);
      juegoLeds(1, 1, 1, 0, 0);
      delay(500);
      juegoLeds(0, 0, 0, 1, 1);
      delay(500);
      juegoLeds(1, 0, 0, 0, 1);
      delay(500);
      juegoLeds(1, 1, 1, 1, 1);
      delay(500);
      juegoLeds(0, 0, 0, 0, 0);
      delay(500);
    }
      if (pal == "ADBH") {
      Serial.println("vam bien 4"); // cuarto juego de luz
      juegoLeds(1, 0, 0, 0, 0);
      delay(500);
      juegoLeds(0, 0, 1, 0, 0);
      delay(500);
      juegoLeds(0, 0, 0, 0, 1);
      delay(500);
      juegoLeds(0, 0, 1, 0, 0);
      delay(500);
      juegoLeds(1, 0, 0, 0, 0);
      delay(500);
      juegoLeds(0, 1, 0, 0, 0);
      delay(500);
      juegoLeds(0, 0, 1, 0, 0);
      delay(500);
      juegoLeds(0, 0, 0, 1, 0);
      delay(500);
      juegoLeds(0, 0, 0, 0, 1);
      delay(500);
      juegoLeds(1, 1, 1, 1, 1);
      delay(500);
      juegoLeds(0, 0, 0, 0, 0);
      delay(500);
    }
      else {
                              // quinto juego de luz error
      juegoLeds(1, 1, 1, 1, 1);
      delay(500);
      juegoLeds(0, 0, 0, 0, 0);
      delay(500);
      juegoLeds(1, 1, 1, 1, 1);
      delay(500);
      juegoLeds(0, 0, 0, 0, 0);
      delay(500);
      juegoLeds(1, 1, 1, 1, 1);
      delay(500);
      juegoLeds(0, 0, 0, 0, 0);
       delay(500);
    }
    
      

    }
  
      
    
  }
