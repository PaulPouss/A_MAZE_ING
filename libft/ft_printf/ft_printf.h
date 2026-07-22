/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:14:27 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/17 14:39:29 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

/* ************************************************************************** */
/*                            OUTPUT FUNCTIONS                                */
/* ************************************************************************** */

/** ft_printf - write output to stdout according to a format that specifies
 * how subsequent arguments are converted for output
 * @param - format: The string to output
 * @return - the number of bytes printed
 */
int		ft_printf(int fd, const char *format, ...);

/** ft_putstr_fd - Outputs the string ’s’ to the given file descriptor
 * @param - s: The string to output.
 * fd: The file descriptor
 * @return - the number of bytes printed
 */
int		ft_putstr_fd_print(char *s, int fd);

/** ft_putnbr_fd - Outputs the integer ’n’ to the given file descriptor
 * @param - n: The integer to output.
 * fd: The file descriptor
 * @return - the number of bytes printed
 */
int		ft_putnbr_fd_print(int n, int fd);

/** ft_putchar_fd - Outputs the character ’c’ to the given file descriptor
 * @param - c: The character to output
 * fd: The file descriptor 
 * @return - the number of bytes printed
 */
int		ft_putchar_fd_print(char c, int fd);

/** ft_putnbr_hex - convert ’n’ to the base and output the result
 * @param - n: the unsigned integer to output.
 * base: the base to convert to
 * @return - the number of bytes printed
 */
int		ft_putnbr_hex_print(unsigned int n, char *base);

/** ft_unsigned_putnbr_fd - Outputs the unsigned integer n to the given
 * file descriptor
 * @param - n: The unsigned integer to output.
 * fd: The file descriptor
 * @return - the number of bytes printed
 */
int		ft_unsigned_putnbr_fd_print(unsigned int n, int fd);

/** print_address - Outputs the memory address of the pointer received
 * @param - ptr: the pointer which address will be print
 * fd: The file descriptor
 * @return - the number of bytes printed
 */
int		ft_print_address_print(void *ptr, int fd);

int		ft_printfloat_fd_print(double number, int fd);
/* ************************************************************************** */
/*                            STRING FUNCTIONS                                */
/* ************************************************************************** */

/** ft_strchr - locate the first occurrence of the c in the string s
 * @param : s : the string to search
 * c : the character to locate
 * @return - a pointer to the character found or NULL
 */
char	*ft_strchr_print(const char *s, int c);

#endif
