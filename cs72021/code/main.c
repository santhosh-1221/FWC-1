#include <avr/io.h>
#include<util/delay.h>
#include<stdbool.h>

int main(void)
{
        bool A,B,P,Q;
        bool C,R;
        DDRB=0b11110000;
        DDRD=0b00001100;
while(1){
        A=(PINB & (1 << PINB0)) == (1 << PINB0);
        B=(PINB & (1 << PINB1)) == (1 << PINB1);
        P=(PINB & (1 << PINB2)) == (1 << PINB2);
        Q=(PINB & (1 << PINB3)) == (1 << PINB3);

        C=((!(!A && (A || B))) || B);
        R=!Q || (!P && (P || Q));


        PORTD = (C << 2);
        PORTD |= (R << 3);

        }
return 0;
}
