
//Timer and counter in CTC Mode

#include <Arduino.h>
volatile uint16_t counter = 0;

void setup() 
{
//Timer Initialize
  TCCR0A = 0b00000010;   //CTC Mode
  TCCR0B = 0b10000011;
  OCR0A = 124; 
  SREG = (1 << 7);
  TIMSK0 = 0b00000010;
  DDRB = (1 << 4);

}
void loop() 
  {}

ISR (TIMER0_COMPA_vect)
{
    counter++;
  if(counter==2000)
 {
    PORTB ^= (1 << 4);
    counter = 0;
 }
}

// M Haider Iqbal
