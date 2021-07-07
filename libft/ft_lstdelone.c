#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	del(lst->content);
	free(lst);
}
