 /*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include <unistd.h>

void my_putchar(char c);

int my_unsigned_put_nbr(unsigned int nb)
{
	unsigned  int i;

        i = nb;
        if (i > 0)
        {
                my_putchar('-');
                i = i * -1;
        }
        if (i >= 10)
        {
                my_unsigned_put_nbr(i / 10);
        }
        i = i % 10 + '0';
        my_putchar(i);
	return (nb);
}
