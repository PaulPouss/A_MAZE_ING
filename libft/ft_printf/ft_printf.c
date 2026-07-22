/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:26:33 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/17 14:46:29 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dispatch(int fd, char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar_fd_print((va_arg(*args, int)), fd));
	else if (c == 's')
		return (ft_putstr_fd_print((char *)(va_arg(*args, char *)), fd));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr_fd_print((va_arg(*args, int)), fd));
	else if (c == 'x')
		return (ft_putnbr_hex_print(va_arg(*args, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_hex_print(va_arg(*args, unsigned int),
				"0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_print_address_print(va_arg(*args, void *), fd));
	else if (c == 'u')
		return (ft_unsigned_putnbr_fd_print(va_arg(*args, unsigned int), fd));
	else if (c == '%')
		return (ft_putchar_fd_print('%', fd));
	else if (c == 'f')
		return (ft_printfloat_fd_print((va_arg(*args, double)), fd));
	return (0);
}

int	ft_printf(int fd, const char *format, ...)
{
	size_t		i;
	char		*conversion;
	const char	*specifiers;
	va_list		args;
	int			count;

	va_start(args, format);
	specifiers = "cspdiuxXf%";
	i = 0;
	count = 0;
	while (format[i])
	{
		conversion = ft_strchr_print(specifiers, (int)format[i + 1]);
		if (format[i] == '%' && conversion)
		{
			count += dispatch(fd, conversion[0], &args);
			i++;
		}
		else
			count += ft_putchar_fd_print((char)format[i], fd);
		i++;
	}
	va_end(args);
	return (count);
}

/*
#include <stdio.h>
#include "ft_printf.h"
#include "limits.h"

int	main(void)
{
	int	clone;
	int	origin;

	//CHAR
	clone = ft_printf("clone c: %c - fin\n", 'A');
        origin = printf("origi c: %c - fin\n", 'A');
	ft_printf("count clone %d\n", clone);
	printf("count origin %d\n", origin);
	
	//%	
	clone = ft_printf("clone %%: %% - fin\n");
     	origin = printf("origi %%: %% - fin\n");
	
	ft_printf("count clone %d\n", clone);
           printf("count origin %d\n", origin);

	//String
	clone = ft_printf("clone s: %s %s - fin\n", "hola", "mundo");
	origin = printf("origi s: %s %s - fin\n", "hola", "mundo");
	
	ft_printf("count clone %d\n", clone);
        printf("count origin %d\n", origin);
	//Integer
	clone = ft_printf("clone i: %i - fin\n", INT_MIN);
        origin =   printf("origi i: %i - fin\n", INT_MIN);

	        ft_printf("count clone %d\n", clone);
           printf("count origin %d\n", origin);

	//hex
	clone = ft_printf("clone x: %x - fin\n", INT_MIN);
        origin = printf("origi x: %x - fin\n", INT_MIN);

	        ft_printf("count clone %d\n", clone);
           printf("count origin %d\n", origin);

	//HEX
	clone = ft_printf("clone x: %X - fin\n", INT_MAX);
        origin = printf("origi x: %X - fin\n", INT_MAX);

	        ft_printf("count clone %d\n", clone);
           printf("count origin %d\n", origin);

	//Pointer address
	clone = ft_printf("clone p: %p - fin\n", "address");
        origin = printf("origi p: %p - fin\n", "address");

	        ft_printf("count clone %d\n", clone);
           printf("count origin %d\n", origin);

	//Integer decimal?
	   unsigned int    num = 4294965;
	clone = ft_printf("clone d: %d - fin\n", num);
        origin = printf("origi d: %d - fin\n", num);

	        ft_printf("count clone %d\n", clone);
           printf("count origin %d\n", origin);

	//unsigned
	unsigned int	max = 0;
	clone = ft_printf("clone u: %u - fin\n", max);
        origin = printf("origi u: %u - fin\n", max);

	        ft_printf("count clone %d\n", clone);
           printf("count origin %d\n", origin);

	return (0);
}
*/
