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
