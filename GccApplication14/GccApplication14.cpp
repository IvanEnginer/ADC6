#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned long ADCdata;

ISR(ADC_vect)
{
	ADCdata = ADCW;
}

int main(void)
{
	int v;
	int u;
	DDRB = 0xFF;
	ADCSRA |= (1 <<ADEN)
	|(1 << ADSC)
	|(1 << ADATE)
	|(1 << ADPS2)|(1 << ADPS1)|(1 << ADPS0)
	|(1 << ADIE); 
	

	
	sei();
	while(1)
	{

		
			ADMUX |= (1 << REFS1)|(1<< REFS0)
			|(0 << MUX3)|(0 << MUX2)|(0 << MUX1)|(0 << MUX0);

			_delay_ms(500);
			
			ADCdata = v;
			

			
			ADMUX |= (1 << REFS1)|(1<< REFS0)
			|(0 << MUX3)|(0 << MUX2)|(0 << MUX1)|(1 << MUX0);

			_delay_ms(500);
			
			ADCdata = u;
			
			
		PORTB = v;
		
			_delay_ms(500);
		
		PORTB = u;				
	}
}
