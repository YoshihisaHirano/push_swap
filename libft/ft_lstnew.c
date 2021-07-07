#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*elt;

	elt = malloc(sizeof(t_list));
	if (!elt)
		return (NULL);
	elt->content = content;
	elt->score = 0;
	elt->next = NULL;
	return (elt);
}
