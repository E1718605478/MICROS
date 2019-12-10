//Realizar el siguiente ejercicio (Interrupciones)
//(1)Ingreso de datos y (2) ordenamiento
//(1)Al ingresar la palabra solo pueden ser números por comunicación serial.
//(2) Una vez ingresados lo números, ordenarlos de menor a mayor e imprimir por comunicación serial.
int est  = 0;
int tipo = 0;
int ext;
String vec;
String cont;
int pas;
int i = 0;

void setup() {
  attachInterrupt(0, bt1, LOW); //
  attachInterrupt(1, bt2, LOW);
  Serial.begin(9600);
  Serial.println("ORDEN DE VECTORES");
  Serial.println("Presione ingresar");
}
void loop() {
  if (est == 1 && tipo == 1) {
    if (Serial.available() > 0) {
      vec = Serial.readString();
      Serial.println("");
      Serial.println("El numero ingresado es: ");
      Serial.println(vec);
      delay(60);
      Serial.println("Presione ingresar para ordenar el numero");
    }
  }
  else if (tipo == 2 && vec != "") {       //Condición para no iniciar sin tener números
    int num[vec.length()];                 //vector donde se guarda que guardará el dato
    for (i = 0; i < vec.length(); i++) {   //creacion y definicion del tamaño del vector
      cont = vec.substring(i, (i + 1));    //Registra los datos ingresados
      num[i] = cont.toInt();                //Guarda los datos individualmente convertidos en enteros
    }
    do {                                    //Código para ordenar los números
      pas = 0;
      for (i = 0; i < vec.length(); i++) { //lectura de datos ingresados
        if (num[i] > num[i + 1]) {          //comparacion de posiciones 
          pas = 1;
          ext = num[i];
          num[i] = num[i + 1];
          num[i + 1] = ext;
        }
      }
    }
    while (pas);
    for (i = 0; i < vec.length(); i++) { //impresion del vector ordenado
      Serial.print(num[i]);
    }
    Serial.println(" ");
    vec = "";
  }
}
void bt1() {
  switch (tipo) {
    case 0:
      Serial.println("Presione ordenar y digite un numero");
      tipo++;
      break;
    case 1:
      Serial.println("Vector ordenado");
      tipo++;;
      break;
    default:
      tipo = 0;
      est = 0;
      break;
  }
}
void bt2() {
  if (tipo == 1) {
    Serial.println("Escribir numero");
    est++;
  }
}
