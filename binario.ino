#define btn1 6
#define btn2 7
int leds[6] = {8,9,10,11,12,13};
int i =0;
int cont=0;
void setup() {
     
      for(i=0;i<6;i++){
        pinMode(leds[i], OUTPUT); 
        }
        i=0;
        pinMode(btn1, INPUT);
       

}

void loop() {

  if (digitalRead(btn1)== HIGH){
      cont=cont+1;
      delay(300);
  
              int i=0, j=0;
        
            if(cont>=0 && cont<=64){
              for(j=0;j<6;j++){
                if(((cont>>j)&1)==1){
                  digitalWrite(leds[j], HIGH);
                  }
                    else digitalWrite (leds[j], LOW);
                }
                  delay(300);
            } 
            }
 
}
