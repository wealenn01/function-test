#ifndef T
#define T
#include<stdio.h>
int ft_isalpha   (char * mess);
int ft_isdigit   (int num[] , int size);
int ft_isalnum   (char str);
int ft_isascii   (int c);
int ft_isprint   (char t);
size_t ft_strlen    (const char * mess);
void* ft_memset  (void* space , int anything , size_t value);
void* ft_bzero   (void* pt , size_t value);
void* ft_memcpy  (void* data , void* ptr , size_t value);
void* ft_memmove (void* data , const void* ptr , size_t value);
size_t ft_strlcpy(void* mess , const void* m , size_t value );
size_t ft_strlcat(char* dest , const char* m , size_t size);
int ft_toupper(int cha);
int ft_tolower(int cha);
char* ft_strchr(const char* mess , int word);
char* ft_strrchr(const char* mess , int word);
int ft_strncmp(const char* s1 , const char* s2,size_t n);
void* ft_memchr(const void* s , int n , size_t by);
int ft_memcmp(const void* s1 , const void* s2 , size_t size);
void* ft_strnstr(const void* s1 , const void* s2 , size_t size);
int ft_atoi(const char* s);
void* ft_calloc(size_t data, size_t size);
char* ft_strdup(const char* data);
char *ft_substr(char const *s, unsigned int start,size_t len);

#endif