#include "get_next_line.h"
#include "../checker.h"

void	static	free_line(char **str)
{
	free(*str);
	*str = NULL;
}

void	static	add_to_static(char **s_str, char *src, int ret)
{
	char	*joined;

	src[ret] = '\0';
	if (!(*s_str))
		*s_str = ft_strdup(src);
	else
	{
		joined = ft_strjoin_gnl(*s_str, src);
		if (*s_str)
			free(*s_str);
		*s_str = joined;
	}
	free(src);
}

int	static	read_line(int fd, char **s_str)
{
	char	*buf;
	int		ret;

	ret = 1;
	while (ret)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (-1);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buf);
			return (-1);
		}
		add_to_static(s_str, buf, ret);
		if (ft_strchr_gnl(*s_str, '\n'))
			break ;
	}
	if (ret == 0)
		return (0);
	return (1);
}

int static	append_line(char **src, char **dst)
{
	size_t	len;
	char	*temp;

	len = 0;
	while ((*src)[len] != '\n' && (*src)[len])
		len++;
	*dst = ft_substr(*src, 0, len);
	if (!(*dst))
		return (-1);
	temp = ft_substr((*src) + len, 1, ft_strlen(*src) - len - 1);
	if (!temp)
		return (-1);
	if (*src)
		free(*src);
	*src = temp;
	temp = NULL;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*s_str;
	int			output;
	int			read_res;

	if (ft_strchr_gnl(s_str, '\n'))
		output = append_line(&s_str, line);
	else
	{
		read_res = read_line(fd, &s_str);
		if (read_res == 1)
			output = append_line(&s_str, line);
		else if (read_res == 0 && s_str)
		{
			*line = ft_substr(s_str, 0, ft_strlen(s_str));
			if (!(*line))
				return (-1);
			free_line(&s_str);
			output = 0;
		}
		else if (read_res == -1)
			output = -1;
		else
			output = 0;
	}
	return (output);
}
