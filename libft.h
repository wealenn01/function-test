#ifndef LIBFT_H
#define LIBFT_H

typedef struct s_list
{
  void *content; // düğümde bulunan veri
  struct s_list *next; // sonraki düğümün adresi, yoksa NULL 

}t_list;

#endif