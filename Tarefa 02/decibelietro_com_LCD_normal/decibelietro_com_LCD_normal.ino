#define inputCLK 4
#define inputDT 5

#define ledCW 8
#define ledCCW 9
int counter=0, currentStateCLK, previousStateCLK;
String encdir="";

#include<math.h>
#define PinoSensor A1 //pino analógico
#define red 9 // pino conectado ao LED vermelho
#define green 10 // pino conectado ao LED verde
#define blue 11 // pino conectado ao LED azul

int ValorSensor = 0;
int valorMaior = 0;
float tensao = 0;
int dB = 0;

int fim=0, inicio=0, intervalo=1000, estado=1, acende=0;
void setup(){
  pinMode(inputCLK, INPUT);
  pinMode(inputDT, INPUT);

  pinMode(ledCW, OUTPUT);
  pinMode(ledCCW, OUTPUT);
  previousStateCLK=digitalRead(inputCLK);
  analogWrite(blue, 255);
  
  Serial.begin(9600);
  pinMode(red, OUTPUT); // define o pino 9 como saída
  pinMode(green, OUTPUT); // define o pino 10 como saída
  pinMode(blue, OUTPUT); // define o pino 11 como saída
}

void loop(){
  switch(estado){
    //ESTADO 1
    case 1:
    while(dB<=50){
      //LEITURA DE SOM NA PORTA ANALÓGICA
      ValorSensor = analogRead(PinoSensor);
      if(ValorSensor > valorMaior){
        valorMaior = ValorSensor;//essas duas linhas seguintes não exisiam    
      }
      tensao = (valorMaior/1024.0)*4.53;
      dB = 17.1*tensao - 5.4;//87.1 75.4
      //ENCODER
      //read the current state of inputCLK
      currentStateCLK=digitalRead(inputCLK);
      //if the previous and the current state of the inputCLK are different then a pulse has occurred
      if(currentStateCLK!=previousStateCLK){
        //if the inputDT state is different than the iputCLK state then
        //the encoder is rotating counterclockwise
        if(digitalRead(inputDT) != currentStateCLK){
          intervalo-=250;  
          Serial.println("CCW");
        }
        else{
           //encoder is rotating clockwise
          intervalo+=250;
          Serial.println("CW");
        }   
      }
      previousStateCLK=currentStateCLK;
      //INTERVALO
      fim=millis();
      if((fim-inicio)>intervalo){
        Serial.print("Decibeis: ");
        Serial.println(dB);
        inicio=millis();
        Serial.println("BLUE");
        valorMaior=0;
      }
      if(dB>50 && dB<=100){
        analogWrite(blue, 0);
        analogWrite(green, 255);
        estado=2;
      }
      else if(dB>100){
        analogWrite(blue, 0);
        analogWrite(red, 255);
        estado=3;
        break;
      }
    }
    break;
    //ESTADO 2
    case 2:
    while(dB>50 && dB<=100){
      //LEITURA DE SOM NA PORTA ANALÓGICA
      ValorSensor = analogRead(PinoSensor);
      if(ValorSensor > valorMaior){
        valorMaior = ValorSensor;//essas duas linhas seguintes não exisiam
      }
      tensao = (valorMaior/1024.0)*4.53;
      dB = 17.1*tensao - 5.4;//87.1 75.4
      //ENCODER
      //read the current state of inputCLK
      currentStateCLK=digitalRead(inputCLK);
      //if the previous and the current state of the inputCLK are different then a pulse has occurred
      if(currentStateCLK!=previousStateCLK){
        //if the inputDT state is different than the iputCLK state then
        //the encoder is rotating counterclockwise
        if(digitalRead(inputDT) != currentStateCLK){
          intervalo-=250;  
          Serial.println("CCW");
        }
        else{
           //encoder is rotating clockwise
          intervalo+=250;
          Serial.println("CW");
        }   
      }
      previousStateCLK=currentStateCLK;
      //INTERVALO
      fim=millis();
      if((fim-inicio)>intervalo){
        Serial.print("Decibeis: ");
        Serial.println(dB);
        inicio=millis();
        Serial.println("GREEN");
        valorMaior=0;
      }
      if(dB<=50){
        analogWrite(green, 0);
        analogWrite(blue, 255);
        estado=1;
      }
      else if(dB>100){
        analogWrite(green, 0);
        analogWrite(red, 255);
        estado=3; 
      }
    }
    break;
    //ESTADO 3
    case 3:
    while(dB>100){
      //LEITURA DE SOM NA PORTA ANALÓGICA
      ValorSensor = analogRead(PinoSensor);
      if(ValorSensor > valorMaior){
        valorMaior = ValorSensor;//essas duas linhas seguintes não exisiam
      }
      tensao = (valorMaior/1024.0)*4.53;
      dB = 17.1*tensao - 5.4;//87.1 75.4
      //ENCODER
      //read the current state of inputCLK
      currentStateCLK=digitalRead(inputCLK);
      //if the previous and the current state of the inputCLK are different then a pulse has occurred
      if(currentStateCLK!=previousStateCLK){
        //if the inputDT state is different than the iputCLK state then
        //the encoder is rotating counterclockwise
        if(digitalRead(inputDT) != currentStateCLK){
          intervalo-=250;  
          Serial.println("CCW");
        }
        else{
           //encoder is rotating clockwise
          intervalo+=250;
          Serial.println("CW");
        }   
      }
      previousStateCLK=currentStateCLK;
      //INTERVALO
      fim=millis();
      if((fim-inicio)>intervalo){
        Serial.print("Decibeis: ");
        Serial.println(dB);
        inicio=millis();
        Serial.println("RED");
        valorMaior=0;
      }
      if(dB>50 && dB<=100){
        analogWrite(red, 0);
        analogWrite(green, 255);
        estado=2;
      }
      else if(dB<=50){
        analogWrite(red, 0);
        analogWrite(blue, 255);
        estado=1;  
      }
    }
    break;
  }
}
