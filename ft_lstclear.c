//#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	ft_lasrclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	aux = *lst;
	if (lst)
	{
		while (*lst)
		{
			aux = aux->next;
			ft_lstdelone(*lst, del);
			(*lst) = aux;
		}
	}
}