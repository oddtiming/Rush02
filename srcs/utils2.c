#include "rush02.h"

char	*ft_strdup(char *str)
{
	char	*new;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	new = malloc(len + 1);
	new[len] = 0;
	while (len--)
		new[len] = str[len];
	return (new);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	value;

	i = 0;
	value = 0;
	while (ft_isdigit(str[i]))
	{
		value = 10 * value + (str[i] - '0');
		if (value < INT_MIN || value > INT_MAX)
			return (0);
		i++;
	}
	return ((int)(value));
}
