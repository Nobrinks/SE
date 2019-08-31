#define BUT_DC 11
#define BUT_AC 10
#define LED_OUT 7
int fim, inicio=0, intervalo=1000,butPressac=0, butPressdc=0, tempiEst=0, tempfEst=0, but_ac=0, but_dc=0, estado=1;
void setup() {
  // put your setup code here, to run once:
  pinMode(BUT_AC, INPUT);
  pinMode(BUT_DC, INPUT);
  pinMode(LED_OUT, OUTPUT);
  Serial.begin(9600);
}

void frequencia(int f){
  if(f &&(intervalo>=500)){
    Serial.println("Decrementa");
    intervalo-=250;
  }
  else if((!f)&&(intervalo<=3000)){
    Serial.println("Incrementa");
    intervalo+=250;
  }
}
//estado 1
void loop(){  
  switch(estado){
    case 1: //estado1(){
      Serial.println("ESTADO 1");
      fim=millis();
      if((fim-inicio)>intervalo){
        digitalWrite(LED_OUT, HIGH);
        inicio=millis();
        estado=2;
      }
      else if(!digitalRead(BUT_AC) && (!butPressac)){
        butPressac = !butPressac;
        estado=3;
        tempiEst=millis();
      }
      else if(!digitalRead(BUT_DC) && (!butPressdc)){
        butPressdc = !butPressdc;
        estado=3;
        tempiEst=millis();
      }
      else if(digitalRead(BUT_AC) && butPressac){
        butPressac = !butPressac;
        frequencia(1);
      }
      else if(digitalRead(BUT_DC) && butPressdc){
        butPressdc = !butPressdc;
        frequencia(0);
      }
      break;
    case 2: //estado2(){
      Serial.println("ESTADO 2");
      fim=millis();
      if((fim-inicio)>intervalo){
        digitalWrite(LED_OUT, LOW);
        inicio=millis();
        estado=1;
      }
      else if(!digitalRead(BUT_AC) && (!butPressac)){
        butPressac = !butPressac;
        estado=4;
        tempiEst=millis();
      }
      else if(!digitalRead(BUT_DC) && (!butPressdc)){
        butPressdc = !butPressdc;
        estado=4;
        tempiEst=millis();
      }
      else if(digitalRead(BUT_AC) && butPressac){
        butPressac = !butPressac;
        frequencia(1);
      }
      else if(digitalRead(BUT_DC) && butPressdc){
        butPressdc = !butPressdc;
        frequencia(0);
      }
      break;
    case 3: //estado3(){
      Serial.println("ESTADO 3");
      fim=millis();
      tempfEst=millis();
      if((fim-inicio)>intervalo){
        digitalWrite(LED_OUT, HIGH);
        inicio=millis();
        estado=4;
      }
      else if(!digitalRead(BUT_AC) && (!butPressac)){
        butPressac = !butPressac;
        estado=5;
        tempiEst=millis();
      }
      else if(!digitalRead(BUT_DC) && (!butPressdc)){
        butPressdc = !butPressdc;
        estado=5;
        tempiEst=millis();
      }
      else if(digitalRead(BUT_AC) && butPressac){
        butPressac = !butPressac;
        estado=1;
        frequencia(1);
      }
      else if(digitalRead(BUT_DC) && butPressdc){
        butPressdc = !butPressdc;
        estado=1;
        frequencia(0);
      }
      else if((tempfEst-tempiEst)>500){
         tempiEst=millis();
         estado=1; 
      }
      break;
    case 4: //estado4(){
      Serial.println("ESTADO 4");
      fim=millis();
      tempfEst=millis();
      if((fim-inicio)>intervalo){
        digitalWrite(LED_OUT, LOW);
        inicio=millis();
        estado=3;
      }
      else if(!digitalRead(BUT_AC) && (!butPressac)){
        butPressac = !butPressac;
        estado=5;
        tempiEst=millis();
      }
      else if(!digitalRead(BUT_DC) && (!butPressdc)){
        butPressdc = !butPressdc;
        estado=5;
        tempiEst=millis();
      }
      else if(digitalRead(BUT_AC) && butPressac){
        butPressac = !butPressac;
        estado=2;
        frequencia(1);
      }
      else if(digitalRead(BUT_DC) && butPressdc){
        butPressdc = !butPressdc;
        estado=2;
        frequencia(0);
      }
      else if((tempfEst-tempiEst)>500){
         tempiEst=millis();
         estado=2; 
      }
      break;
    case 5: //estado5(){
      while(1);
  }
}
