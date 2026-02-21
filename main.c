#include<stdio.h>
#include<bsd/string.h> // -lbsd
#include "function.h"
#include"function2.h"
#include "function3.h"
#include "libft.h"

int main(void)
{
int i=0;
  
int*p = ft_calloc(5,sizeof(int));

while(i<5)
{
  printf("%d ",p[i]);
}
 return 0;


}