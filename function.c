
#include "function.h"
#include <stdio.h>
#include <stdlib.h>

int ft_isalpha(char * mess)
{
 
 int j=0,a=1;
 
 while(mess[j]!='\0'){
  if(!(mess[j] >='a'&& mess[j] <='z'))
  {
    a=0;

    break;
  }
  j++;
 }
 return a;
 }

 int ft_isdigit(int num[],int size)
 {
  int j=0,b=1;

  while(j<size)
  {
    if(num[j]<0|| num[j]>9)
    b=0;
    j++;
  } 
return b;
}
int ft_isalnum(char str)
{

  if((str >='a' && str <= 'z')||(str >= 'A' && str <= 'Z') || (str >='0' && str <= '9'))
  {
    return 1;
  }
 
    
   return 0;
} 
int ft_isascii(int c)
{
  
 if((unsigned char)c <= 127 && (unsigned char)c > 0)
 {
  return 1;
 }
  
 return 0;

}
int ft_isprint(char u)
{
 
  if(u >= 32 && u <= 126)
 return 1;
 return 0;

}
size_t ft_strlen(const char * mess)
{
 size_t    j;
   
   j=0;

  while(mess[j] != '\0')
  {
   
    j++;

  }
  return j;
} 
void* ft_memset(void* ptr , int b , size_t value)
{
  size_t   i;
   
   i=0;

 char*a;
 a = (char*)ptr;

  while(i<value)
  {
    a[i]=b;
    i++;
  }
  return ptr;

}
void* ft_bzero(void*pt , size_t value)
{
   size_t    i;
   
   i=0;

   char*a=(char*)pt;
   while(i<value)
   {
    a[i]=0;
    i++;
   }
return pt;
}
void* ft_memcpy(void* data, void* ptr, size_t value)
{
    size_t     i;

    char*a;

    a = (char*) data;

    char*b = (char*) ptr;
   
    i = 0;
    while (i < value )
    {
       a[i] = b[i];
       i++;
    }
   
    return data;
}

void* ft_memmove(void* data , const void* ptr , size_t value)
{

  char *dest = (char *)data;
    const char *src = (const char *)ptr;
    size_t i;

    if (dest > src)
    {
        i = value;
        while (i > 0)
        {
            i--;
            dest[i] = src[i];
        }
    }
    else
    {
        i = 0;
        while (i < value)
        {
            dest[i] = src[i];
           
            i++;
        }
    }

    return data;
   
}

size_t ft_strlcpy(void* mess , const void* m , size_t size )
{

   char*a = (char*)mess;
   const char*b = (const char*)m;

  size_t   i;

  i=0;
  
  if(size >0)
  {
   while(i < size-1  && b[i])
   {
    a[i]=b[i];
    i++;
   }

   a[i]='\0';
    
  }

   return ft_strlen(b);
}

size_t ft_strlcat(char* dest , const char* m , size_t size)
{

  size_t   i ;
  i=0;
  size_t b= ft_strlen(dest);
  size_t c= ft_strlen(m);
  if(size>b){
   
    size_t a = size-b;
 
  while(i<a-1 && m[i]){
    dest[b+i]=m[i];
    i++;
  }
  dest[b+i]='\0';

  }
  if(b>=size)
   return size+c;
 
 return b+c;
}
int ft_toupper(int cha)
{

  if(cha>=97 && cha <=122){
    cha = cha -32;
  }
  return cha;
}

int ft_tolower(int cha)
{

if(cha >='A' && cha <= 'Z' ){
  cha+=32;
}
return cha;

}

char* ft_strchr(const char* mess , int word)
{

  size_t  i;
  i=0 ;
  
  

  while(i<ft_strlen(mess))
  {

    if(mess[i]==word)
    {
     return (char*)&mess[i];
    }
    i++;
  }
 return NULL;
}

char* ft_strrchr(const char* mess , int word)
{
 
int   i;
i=ft_strlen(mess)-1;
while(i!=-1){

  if(mess[i]==word){
    return (char*)&mess[i];
  }
  i--;
}
 return NULL;
}


int ft_strncmp(const char* s1 , const char* s2,size_t n)
{
 size_t  i;

 i = 0;
 
 while(i<n && (s1[i] != '\0' || s2[i] != '\0'))
 {

  if( s1[i] != s2[i] )
  {
     return s1[i]-s2[i];

  }
  i++;
  
 }
   return 0;

}
void* ft_memchr(const void* s , int n , size_t by)
{
 size_t  i;
 
 i=0;

 const char*a = (const char*)s;
 
  while(i<by)
  {
    
    if(a[i]==n)
    
    return (char*)&a[i];
   i++;
  }
  return NULL;
}
int ft_memcmp(const void* s1 , const void* s2 , size_t size)
{
 size_t  i;

 i=0;
 const unsigned char* a1 = (const unsigned char*)s1;
  const char* a2 = (const char*)s2;


 while (i!=size)
 {
   if (a1[i] != a2[i])
   {
    return a1[i]-a2[i];
   }
   i++;
 }
 return 0;
}

void* ft_strnstr(const void* s1 , const void* s2 , size_t size)
{
  size_t    i,j;

  const char* a1 = (const char*)s1;
  const char* a2 = (const char*)s2;
  i=0;
  
  if (!a2[0])
    return (char*)a1;


  while(i<size && a1[i])
  {
    j=0; 

    while (a1[i + j] == a2[j] && (i + j) < size)
        {
            j++;
        }
        if(a2[j] == '\0')
        return (char*)& a1[i];
    i++;
  }
  return NULL;
}

int ft_atoi( const char* s)
{
 int    i,toplam,islem;
 (void)islem;

 i=0, toplam = 0 , islem  = 1 ;

   while(s[i]==' ')
   {
     i++;
   }
      
    
   
    if(s[i] == '-')
    {
      
      islem=-1;
      
      i++;
    }
      
  while(s[i]>='0' && s[i]<='9')
  {

  toplam = (s[i]-'0') + 10 * toplam ;
   i++;
  }  
  
return toplam;

}

void* ft_calloc(size_t data, size_t size)
{
  size_t i ;
  size_t total= data * size;
  i=0;

 char*p= malloc (total);

  if(!p)
  return NULL;

  while(i<total)
  {
    p[i]=0;
i++;
  }
 return p;

}


char* ft_strdup(const char* data){

  size_t    i;

 
  i=0;


  size_t len = ft_strlen(data);

  char*p=malloc((len+1)*sizeof(char));

   if(!p)
 return NULL;

  while(i<len)
  {
    p[i]=data[i];

    i++;

  }

  p[i]='\0';

  return (char*)p;
}






  



 
     
