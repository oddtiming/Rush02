#include "rush02.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr_fd(char *str, int fd)
{
	return (write(fd, str, ft_strlen(str)));
}

char	*read_user_input(char *buf)
{
	ssize_t	ret;
	char	*dup;

	ret = read(STDIN_FILENO, buf, BUF_SIZE);
	dup = malloc(sizeof(char) * ret);
	dup[ret] = 0;
	while (ret--)
	{
		if (dup[ret] == '\n')
			continue ;
		dup[ret] = buf[ret];
	}
	return (dup);
}

bool	ft_isspace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (true);
	return (false);
}

bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}
