/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** 
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int my_put_nbr(int nb);

int my_putstr(char *str);

int my_unsigned_put_nbr(unsigned int nb);

void my_putchar(char c);

int deci_to_octa(int decimal)
{
	int octal = 0;
	int temp = 1;
	
	while (decimal != 0) {
		octal = (decimal % 8) * temp;
		decimal = decimal / 8;
		temp = temp * 10;
	}
	my_put_nbr(octal);
	return (decimal);
}

int deci_to_bin(int decimal2)
{
	int binary = 0;
	int i = 1;

        while (decimal2 != 0)
        {
                binary = (decimal2 % 2) * i;
                decimal2 = decimal2 / 2;
                i = i * 10;
        }
        my_put_nbr(binary);
	return (decimal2);
}

int my_printf(const char *flag, ...)
{
	va_list ap;
	int i = 0;

	va_start(ap, flag);

	while(flag[i] != '\0'){	     
		if (flag[i] == '%') {
			switch (flag[i + 1]) {
			case 's':
				my_putstr(va_arg(ap, char *));
				break;	        
			case 'i':
				my_put_nbr(va_arg(ap, int));
				break;
			case 'u':
				my_unsigned_put_nbr(va_arg(ap, int));
				break;
			case 'd':
				my_put_nbr(va_arg(ap, int));
				break;
			case 'b':
				deci_to_bin(va_arg(ap,int));
				break;				    
			case 'c':
				my_putchar(va_arg(ap, int));
				break;
			case '%':
				my_putchar('%');
				break;
			case 'o':
				deci_to_octa(va_arg(ap,int));
				break;			
			default :
				my_putstr(flag);
			}
			i = i + 2;
		}
		if(flag[0] != '%') {
			my_putchar(flag[i]);
			i++;
		}
        }
	va_end(ap);
	return (0);
}
