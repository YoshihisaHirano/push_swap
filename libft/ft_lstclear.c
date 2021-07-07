#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*temp_next;

	temp = *lst;
	while (temp)
	{
		temp_next = temp->next;
		free(temp);
		temp = temp_next;
	}
	*lst = NULL;
}
