/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:36:11 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/13 11:42:06 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

/* ************************************************************************** */
/*				CHARACTER FUNCTIONS			      */
/* ************************************************************************** */

/** ft_isalpha - checks for an alphabetic character
* @param - character to convert
* @return - converted character or c if it is neither lowercase or uppercase
*/
int			ft_isalpha(int c);

/** ft_isdigit - checks for a digit (0 through 9)
 * @param -  character to check
 * @return - 1 if c is numeric or 0 if it is not
 */
int			ft_isdigit(int c);

/** ft_isalnum - checks for an alphanumeric character
 * @param - character to check
 * @return - 1 if c is numeric or 0 if it is not
 */
int			ft_isalnum(int c);

/** ft_isascii - checks whether c is a 7-bit unsigned char value 
 * @param - character to check
 * @return - 1 if c is numeric or 0 if it is not
 */
int			ft_isascii(int c);

/** ft_isprint - checks for any printable character including space.
 * @param - character to check
 * @return - 1 if c is numeric or 0 if it is not
 */
int			ft_isprint(int c);

/** ft_toupper - convert lowercase letters to uppercase
 * @param - character to check
 * @return - convert character or c if it is not lowercase
 */
int			ft_toupper(int c);

/** ft_tolower - convert uppercase letters to lowercase
 * @param - character to check
 * @return - convert character or c if it is not uppercase
 */
int			ft_tolower(int c);

/* ************************************************************************** */
/*                            STRING FUNCTIONS                                */
/* ************************************************************************** */

/** ft_strlen - calculate the length of a string
 * @param - the original string
 * @return - the number of bytes in the string pointed to by s
 */
size_t		ft_strlen(const char *s);

/**ft_strlcpy - copies up to size
 * @params - dst : the copy string
 * src : the original string
 * size : the size to copy
 * @return - the total length of the string it try to create
 */
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

/** ft_strlcat - concatenate strings up to size
 * @params - dst : the concatenate string
 * src : the original string 
 * size : the size to copy
 * @return - the total length of the string it try to create
 */
size_t		ft_strlcat(char *dst, const char *src, size_t size);

/** ft_strchr - returns a pointer to the first occurrence of the character
 * in the string
 * @param : s : the original string
 * c : the character to find
 * @return - a pointer to the matched character or NULL
 */
char		*ft_strchr(const char *s, int c);

/** ft_strrchr - returns a pointer to the last occurrence of the character
 * in the string
 * @param : s : the original string
 * c : the character to find
 * @return - a pointer to the matched character or NULL
 */
char		*ft_strrchr(const char *s, int c);

/** ft_strncmp - compares the two strings up to size
 * @param - s1 : the first string
 * s2 : the second string
 * n : the size to compare
 * @return -  an integer indicating the result of the comparison
 * @note : values are interpreted as type unsigned char to determined
 * the difference
 */
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/** ft_strnstr - locates the first occurrence of the string little in the
 * string big, where not more than len characters are searched
 * @param - big : the string to search
 * little : the string to find
 * len : the size to search
 * @return - If little is an empty string, big is returned; if little occurs
 * nowhere in big, NULL is returned; otherwise a pointer to the first character
 * of the first occurrence of little is returned.
 */
char		*ft_strnstr(const char *big, const char *little, size_t len);

/* *ft_strdup - returns a pointer to a new string which is a duplicate
 * of the string s
 * @param : The string to copy
 * @return - a pointer to the duplicated string or NULL if insufficient memory
 */
char		*ft_strdup(const char *s);

/** ft_substr - Allocates memory (using malloc(3)) and returns a substring
 * @param - s: The original string from which to create the substring.
 * start: The starting index of the substring within ’s’.
 * len: The maximum length of the substring.
 * @return The substring or NULL if the allocation fails.
 */
char		*ft_substr(char const *s, unsigned int start, size_t len);

/** ft_strjoin - Allocates memory (using malloc(3)) and returns a new string
 * @param - s1: The prefix string
 * s2: The suffix string
 * @return The new string or NULL if the allocation fails.
 * @note - Check for null pointer.
 */
char		*ft_strjoin(char const *s1, char const *s2);

/** ft_strtrim - Allocates memory (using malloc(3)) and returns a new string 
 * @param - s1: The string to be trimmed.
 * set: The string containing the set of characters to be removed 
 * from the beginning and the end
 * @return The trimmed string or NULL if the allocation fails
 * @note - Check for null pointer.
 */
char		*ft_strtrim(char const *s1, char const *set);

/** ft_split - Allocates memory (using malloc(3)) and returns an array
 * of strings
 * @param - s: The string to be split
 * c: The delimiter character
 * @return The array of new strings or NULL if the allocation fails.
 */
char		**ft_split(char const *s, char c);

/** ft_strmapi - Allocates memory (using malloc(3)) and applies the function f
 * to each character of the string s
 * @param - s: The string to iterate over
 * f: The function to apply to each character
 * @return - The string created from the successive applications of ’f’.
 * Returns NULL if the allocation fails
 */
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/** ft_striteri - Applies the function ’f’ to each character of the string
 * passed as argument
 * @param - s: The string to iterate over
 * f: The function to apply to each character
 * @return - none
 */
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

/* ************************************************************************** */
/*                            MEMORY FUNCTIONS                                */
/* ************************************************************************** */

/** ft_memset - fills the first n bytes of the memory area pointed to by s with
 * the constant byte c
 * @param - s : The string to fill
 * c : the byte 
 * @return - a pointer to the memory area s
 * @note - do not check for null pointers
 */
void		*ft_memset(void *s, int c, size_t n);

/**  ft_bzero - erases the data in the n bytes of the memory starting at the
 * location pointed to by s
 * @param - The string to erase data
 * n : the size to remove
 * @return - none
 * @note - do not check for null pointers
 */
void		ft_bzero(void *s, size_t n);

/** ft_memcpy - copies n bytes from memory area src to memory area dest.
 * @param - src : the original string
 * dest : the update string
 * n : the size to copy
 * @return : returns a pointer to dest
 * @note : the memory areas may not overlap
 * do not check for null pointers
 */
void		*ft_memcpy(void *dest, const void *src, size_t n);

/** ft_memmove - copies n bytes from memory area src to memory area dest.
 * @param - src : the original string
 * dest : the update string
 * n : the size to copy
 * @return : returns a pointer to dest
 * @note : the memory areas may overlap
 * do not check for null pointers
 */
void		*ft_memmove(void *dest, const void *src, size_t n);

/** ft_memchr - scans  the initial n bytes of the memory area pointed to by s
 * for the first instance of c.
 * @param - s : the string to scan
 * c : the character to find
 * n : the size to search
 * @return - return a pointer to the matching  byte  or  NULL  if  the
 * character does not occur in the given memory area.
 * @note - do not check for null pointers
 */
void		*ft_memchr(const void *s, int c, size_t n);

/** ft_memcmp - compare the first n bytes of two string
 * @param - s1 : the first string
 * s2 : the second string
 * n : the size to compare
 * @return - returns an integer less than, equal to, or  greater  than  zero
 * @note - do not check for null pointers
 */
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/** ft_calloc - allocates memory for an array of nmemb elements of size bytes
 * each and returns a pointer to the allocated memory. The memory is set to zero
 * @param : nmemb : the number of elements
 * size : the size of each elements
 * @return - returns a pointer to the allocated memory or NULL
 */
void		*ft_calloc(size_t nmemb, size_t size);

/* ************************************************************************** */
/*                          CONVERSION FUNCTIONS                              */
/* ************************************************************************** */

/* ft_atoi - converts the initial portion of the string pointed to int
 * @param - nptr : the string to convert
 * @result - The converted value or 0 on error
 */
long int	ft_atoi(const char *nptr);

/** ft_itoa - Allocates memory (using malloc(3))  and returns a string
 * representing the integer received
 * @param - n : The integer to convert
 * @return - The string representing the integer or NULL if the allocation fails.
 */
char		*ft_itoa(int n);

/* ************************************************************************** */
/*                            OUTPUT FUNCTIONS                                */
/* ************************************************************************** */

/** ft_printf - write output to stdout according to a format that specifies
 * how subsequent arguments are converted for output
 * @param - format: The string to output
 * @return - the number of bytes printed
 */
int			ft_printf(int fd, const char *format, ...);

/** ft_putchar_fd - Outputs the character ’c’ to the specified file descriptor
 * @param - c: The character to output
 * fd: The file descriptor on which to write
 * @return - none
 */
void		ft_putchar_fd(char c, int fd);

/** ft_putstr_fd - Outputs the string ’s’ to the specified file descriptor
 * @param - s: The string to output.
 * fd: The file descriptor on which to write
 * @return - none
 */
void		ft_putstr_fd(char *s, int fd);

/** ft_putendl_fd - Outputs the string ’s’ to the specified file descriptor
 * followed by a newline
 * @param - s: The string to output.
 * fd: The file descriptor on which to write
 * @return - none
 */
void		ft_putendl_fd(char *s, int fd);

/** ft_putnbr_fd - Outputs the integer ’n’ to the specified file descriptor
 * @param - s: The integer to output.
 * fd: The file descriptor on which to write
 * @return - none
 */
void		ft_putnbr_fd(int n, int fd);
/* ************************************************************************** */
/*                   	       LIST FUNCTIONS 	                              */
/* ************************************************************************** */

/** ft_lstnew - Allocates memory (using malloc(3)) and returns
a new node. 
 * @param - content: The content to store in the new node
 * @return - a pointer to the new node
 * @note - content can be NULL
 */
t_list		*ft_lstnew(void *content);

/** ft_lstadd_front - Adds the node ’new’ at the beginning of the list
 * @param - lst: The address of a pointer to the first node of a list
 * new: The address of a pointer to the node to be added
 * @return - none
 */
void		ft_lstadd_front(t_list **lst, t_list *new);

/** ft_lstadd_back - Adds the node ’new’ at the end of the list
 * @param - lst: The address of a pointer to the first node of a list
 * new: The address of a pointer to the node to be added
 * @return - none
 */
void		ft_lstadd_back(t_list **lst, t_list *new);

/** ft_lstsize - Counts the number of nodes in the list
 * @param - lst: The beginning of the list
 * @return - The length of the list
 */
int			ft_lstsize(t_list *lst);

/** ft_lstlast - Returns the last node of the list
 * @param - lst: The beginning of the list
 * @return - last node of the list
 */
t_list		*ft_lstlast(t_list *lst);

/** ft_lstdelone - Takes a node as parameter and frees its content using
 * the function ’del’
 * @param : lst: The node to free.
 * del: The address of the function used to delete the content.
 * @return - none
 */
void		ft_lstdelone(t_list *lst, void (*del)(void*));

/** ft_lstclear - Deletes and frees the given node and all its successor
 * @param - lst: The address of a pointer to a node. 
 * del: The address of the function used to delete the content of the node.
 * @return - none
 */
void		ft_lstclear(t_list **lst, void (*del)(void*));

/** ft_lstiter - Iterates through the list ’lst’ and applies the function ’f’
 * to the content of each node
 * @param - lst: The address of a pointer to a node.
 * f: The address of the function to apply to each node’s content.
 * @return - none
 */
void		ft_lstiter(t_list *lst, void (*f)(void *));

/** ft_lstmap - Iterates through the list ’lst’, applies the function ’f’
 * to each node’s content, and creates a new list
 * @param - lst: The address of a pointer to a node.
 * f: The address of the function applied to each node’s content.
 * del: The address of the function used to delete a node’s content if needed
 * @return - The new list or NULL if the allocation fails
 */
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
