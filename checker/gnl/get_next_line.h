#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

int		get_next_line(int fd, char **line);
int		ft_strchr_gnl(char *s, char c);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif
