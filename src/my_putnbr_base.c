/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/
#include <unistd.h>
#include <stdio.h>

void my_putchar(char c);

int my_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i = i + 1;
	return (i);
}

int  my_putnbr_base(int nbr, char *base)
{
       	if (nbr < 0)
        {
		nbr = nbr * -1;
		my_putchar('-');
	}
	else if (nbr == 0) {	
		my_putnbr_base((nbr / my_strlen(base)), base);
		my_putchar(base[nbr % my_strlen(base)]);
	}
	return (nbr);
}
