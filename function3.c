#include "libft.h"
#include<stdio.h>
#include "function.h"
#include <stdlib.h>

t_list *ft_lstnew(void *content)
{
   t_list *p;


   p = malloc(sizeof(t_list));

   if(!p)
   return NULL;

   p->next = NULL;
   p->content = content;

   

    return p;
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
    new->next = *lst;
    *lst=new;
    
}

int ft_lstsize(t_list *lst)
{
    int i;
   
    
    i=1;

    while(lst)
    {
        i++;
        lst = lst->next;
        
        
    }
    return i;
}

t_list *ft_lstlast(t_list *lst)
{
    //A-B-C-D
    if(!lst)
    return NULL;

  while(lst->next)
  {

    lst=lst->next;

  }
  return lst;
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *p;

     p=*lst;

     if (*lst == NULL)
    {
        *lst = new;
        return;
    }

      while(p->next)
    {
        p = p->next;
    }
    p->next = new;
    new->next = NULL;
}

void fre(void* lst)
{
   
    free(lst);
   
}

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    del(lst->content);
    free(lst);
}

void delete(void* cont)
{
   
   free(cont);
}

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *p;
    
    while(*lst)
     {
        p = (*lst)->next;

         del((*lst)->content);

         free(*lst);
         
         *lst = p;
         
     }  
    
}

void funca(void * cont)
{
    printf("%s\n", (char *)cont);
}

void ft_lstiter(t_list *lst, void (*f)(void *))
{
    while(lst)
    {
      
        f(lst->content);

        lst = lst->next;
    }
}

void *func(void* cont)
{
     char*s = (char*)cont;

     size_t len;
     size_t i;
     char*p;

     len = ft_strlen(s);
     p= malloc(len+1);
     if(!p)
     return NULL;

     i = 0;

     while(i<len)
     {
        p[i]=s[i];
        i++;
     }
     p[len] = '\0';
     return p;
    
}


t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *)) // cok zor üstteki functionu ben yazdım

{
    (void)del;
     t_list *new_list = NULL;
    t_list *new_node;
    void   *new_content;

    while (lst)
    {
        new_content = f(lst->content);
        

        new_node = ft_lstnew(new_content);
       

        ft_lstadd_back(&new_list, new_node);
        lst = lst->next;
    }

    return new_list;
}

