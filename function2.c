#include"function2.h"
#include"function.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


char *ft_substr(char const *s, unsigned int start,size_t len)
{

 size_t a= ft_strlen(s);   

size_t i;

i=0;

if(start>a)
return NULL;

char*p = malloc(len+1);

if(!p)
return NULL;

while(i<len && s[start+i]!='\0')

{
  
     p[i]=s[start+i];

     i++;
}

p[i]='\0';

return p;

}

char *ft_strjoin(char const *s1, char const *s2)
{
  size_t  i;
  i=0;
  size_t len1 = ft_strlen(s1);
  size_t len2 = ft_strlen(s2);

  size_t total = len1+len2;

  char*p = malloc(total+1);
   if(!p)
   return NULL;

  while(i<len1)
 {
   p[i]=s1[i];
   i++;

 }
 i=0;
 while (i<len2)
 {
    p[len1+i]=s2[i];
    i++;
 }
 p[len1+i]='\0';

 return p;
 

}

int ft_isinset(char c, char const *set)
{
    size_t i = 0;

    while (set[i])
    {
        if (set[i] == c)
            return 1;
        i++;
    }
    return 0;
}

char *ft_strtrim(char const *s1, char const *set)
{
   size_t start;
    size_t end;
    size_t len;
    char*  p;
    size_t i;

    start = 0;
    while(s1[start] && ft_isinset(s1[start],set))
    start++;

    end = ft_strlen(s1);

    while(end > start && ft_isinset(s1[end - 1], set))
    end--;

    len = end - start;

    p = malloc(len + 1);
    if (!p)
        return NULL;

         i = 0;
    while (i < len)
    {
        p[i] = s1[start + i];
        i++;
    }
    p[i] = '\0';

    return p;
}
/*
 size_t kac_tane(char const* s , char c )
 {
   size_t a;
   size_t kelime;

   kelime = 0;
   a=0;

   while(s[a])
   {
     if(s[a]== c && s[a+1]!=c && s[a+1]!='\0')
         kelime++;

      a++;
   }
  return kelime;

 }
 char* kelime(const char*s , char c ,size_t *i)
 {
   size_t start ;
   size_t len;
   
    char*p;
    
    while(s[*i])
    {
       while(s[*i]==c)
       {
        i++;
       }
       
       if(s[*i] != '\0')
       {
        start=*i;

        while(s[*i]!=c && s[*i]!='\0')
         {
           (*i)++;

         } 
         len = *i-start;
         
         p=malloc(len+1);
         if(!p)
         return NULL;

         size_t a=0;

         while(a<len)
         {
          p[a]=s[start];
          start++;
          a++;

         }
         p[len]='\0';

         return p;
         
       }

      


       i++;
    }
 }

char **ft_split(char const *s, char c)
{
    size_t k;
    size_t i;
    size_t sayi;
    size_t start;
    size_t len;
    char **res;

    // 1. kelime sayısını bul
    // 2. malloc yap
    // 3. stringi gez
    // 4. kelime bulunca kopyala
    // 5. NULL koy
  
    sayi = kac_tane(s,c);

    res = (char **)malloc(sizeof(char*)*(sayi+1));
    if(!res)
    return NULL;
    
    k=0;
    i=0;

    while(k<sayi)
    {
       res[k] = kelime(s,c,&i);
       k++;

    }

    res[sayi] = NULL;

    return res;



}
 */

 static void kac_tane_kelime_var(const char* s , char c , size_t *j)
 {
   size_t i;
   i=0;

   while(s[i])
   {
    if(s[i]!=c && i==0)
    (*j)++;

    if(s[i]==c && s[i+1]!=c && s[i+1]!='\0')
    (*j)++;

    i++;
   }

 }
 static char* kelime (const char* s , char c ,size_t *a)
 {
   
   size_t start;
   size_t len;
   size_t m;
   char* res;
   
   
   while(s[*a])
   {
     while(s[*a]==c)
     (*a)++;
 
     if(s[*a]=='\0')
     {
       break;
     }
  
    start= *a;
    
      while(s[*a]!=c && s[*a]!='\0')
        (*a)++;
      
      len = *a - start;
     
      res= malloc(len+1);
      if(!res)
      return NULL;
     

      m=0;
      while(m<len)
      {
        res[m]=s[start];
        m++;
        start++;
      }
        res[len]='\0';
        return res;

   }
   return NULL;   

 }

 char **ft_split(char const *s, char c)
 {
  size_t i;
  size_t kac_tane;
  char**p;
  size_t a;
  
  kac_tane = 0;

  kac_tane_kelime_var( s , c , &kac_tane );
  
  p = malloc(sizeof(char*) * ( kac_tane +1 ));
  if(!p)
  return NULL;
 
  a=0;
  i=0;
  while(i<kac_tane)
  {
    p[i] = kelime(s,c,&a);
    i++;
  }

  p[i]=NULL;

  return p;

 
}



static size_t basamak(int n)
{
  size_t i;

  i=0;

  if(n<0)
   n = -n;

  while(n != 0)
  {
    n = n / 10 ;
    i++;
  }
  if(i==0)
  return 1;

  return i;
}

char *ft_itoa(int n)
{
  size_t size;
  size_t i;

  if(n>=0)
  {
    size= basamak(n);

    char*p = malloc(size+1);

    if(!p)
    return NULL;

    if (size == 1)
            p[0] = '0';

    i=size-1;
   while(n!=0)
   {
    
    p[i] = (n%10)+'0';
    
    n=n/10;
    
    i--;

   }

  p[size]='\0';
  return p;
  }

  else
  {
   size= basamak(n);
   char*p = malloc(size+2);

   n=-n;

   if(!p)
    return NULL;

   p[0]='-';

    i=size;
  while(n!=0)
  {
    
    p[i] = (n%10)+'0';
    
    n=n/10;
    
    i--;
 
  }
   p[size+1]='\0';
   return p;
  }
}
 
 char up(unsigned int a , char c)
 {
  (void)a;
     return c;


 }

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
  size_t i;
  size_t len = ft_strlen(s);
  i=0;

  char*p=malloc(len+1);
  if(!p)
  return NULL;

  while(s[i])
  {
   p[i] = f(i,s[i]);
    i++;
  }
  p[i]='\0';
 return p;
}
void itarete(unsigned int i , char* c)
{
  (void)i;
  if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

void ft_striteri(char *s, void (*f)(unsigned int,char*))
{
  unsigned int i;

  i=0;
  
  while(s[i])
  {
    f(i,&s[i]);
    i++;
  }

}

void ft_putchar_fd(char c, int fd)
{
  write(fd,&c,1);
}

void ft_putstr_fd(char *s, int fd)
{
  if(!s)
  return ;
  write(fd,s,ft_strlen(s));
}

void ft_putendl_fd(char *s, int fd)
{
  if(!s)
  return ;
 

  write(fd,s,ft_strlen(s));
  write(fd,"\n",1);
}

void ft_putnbr_fd(int n, int fd)
{
 
  char p[12];
  size_t i;

  if(n == 0)

  {
    write(fd,"0",1);
    return;
  }


   i=0;

 if(n>0)
 {
   
   while(n)
   {

    p[i]=(n%10)+'0';

    n = n/10 ;
    i++;

   } 
   while(i--)
    write(fd,&p[i],1);
 }

 else
 {
   write(fd,"-",1);
   n=-n;

   while(n)
   {

     p[i]=(n%10)+'0';

    n = n/10 ;
    i++;

   }
   while(i--)
     write(fd,&p[i],1);
 }
  
}


