#include "libft.h"

static void	keep_content(void *content)
{
	(void)content;
}

static void	*uppercase_copy(void *content)
{
	char	*copy;
	size_t	i;

	copy = ft_strdup(content);
	if (!copy)
		return (NULL);
	i = 0;
	while (copy[i])
	{
		copy[i] = ft_toupper((unsigned char)copy[i]);
		i++;
	}
	return (copy);
}

static void	print_list(char *label, t_list *list)
{
	ft_putstr_fd(label, 1);
	while (list)
	{
		ft_putstr_fd(list->content, 1);
		if (list->next)
			ft_putchar_fd(' ', 1);
		list = list->next;
	}
	ft_putchar_fd('\n', 1);
}

static int	valid_content(t_list *list)
{
	if (!list)
		return (0);
	while (list)
	{
		if (!list->content)
			return (0);
		list = list->next;
	}
	return (1);
}

int	main(void)
{
	t_list	*original;
	t_list	*second;
	t_list	*mapped;
	int		success;

	original = ft_lstnew("hello");
	second = ft_lstnew("world");
	if (!original || !second)
	{
		ft_lstclear(&original, keep_content);
		ft_lstclear(&second, keep_content);
		return (1);
	}
	ft_lstadd_back(&original, second);
	mapped = ft_lstmap(original, uppercase_copy, free);
	success = valid_content(mapped);
	if (success)
	{
		print_list("original: ", original);
		print_list("mapped:   ", mapped);
	}
	ft_lstclear(&original, keep_content);
	ft_lstclear(&mapped, free);
	return (!success);
}
