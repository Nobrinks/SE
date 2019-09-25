void setup() {
  // put your setup code here, to run once:
  //WGM0/ OCR0A used to manipulate the counter resolution
  //TCNT0==OCR0A, counter sets zero
  //OCR0A defines the ceil value for counter
  // --------------CTC-----------------
  TCCR0A=0; //zerando o TCCR0A
  TCCR0A |=(1 << WGM01);    //setting CTC

  //--------------Prescaler-----------------
  TCCR0B=0;
  TCCR0B |= (1 << CA01)|(1 << CS00); //64 bits prescaler
  //---------------Counter----------------
//compare match register = [16,000,000Hz/(prescaler*desired interrupt frequency)]-1
  TCNT0=0;
  OCR0A=254; //comparador
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
}


/*bool ligado=1;
void setup() {
  DDRD |= (1<<3);
  PORTD=0;
  cli(); //stop interrupts
  // put your setup code here, to run once:
  //WGM0/ OCR0A used to manipulate the counter resolution
  //TCNT0==OCR0A, counter sets zero
  //OCR0A defines the ceil value for counter
  // --------------CTC-----------------
  
  //TCCR1A=0; //zerando o TCCR0A
  //TCCR0A |=(1 << WGM01);    //setting CTC

  //--------------Prescaler-----------------
  TCCR1B=0;
  TCCR1B |= (1<<WGM12);
  TCCR1B |= (1 << CS12)|(1 << CS10); //1024 bits prescaler 
  //---------------Counter----------------
//compare match register = [16,000,000Hz/(prescaler*desired interrupt frequency)]-1
//1HZ
  TCNT1=0;
  OCR1A=15624; //comparador
  //TIMSK1=0;
  TIMSK1 |= (1 <<OCIE1A);
  sei();//allow interrupts
  
}
ISR(TIMER0_COMPA_vect){ //timer0 interrupt 1Hz 
  if(ligado){
    ligado=0;
    PORTD |= (1<<3);
  }
  else{
    ligado=1;
    PORTD &= ~(1<<3);
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  
}*/
