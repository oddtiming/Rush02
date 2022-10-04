#include "rush02.h"

/**
 * @brief Remove whitespaces from before and after delimiter
 * 
 * @param entry raw entry
 * @return char* sanitized entry
 */
char	*get_clean_entry(char *entry, size_t clean_len)
{
	char	*clean;
	size_t	pos;

	clean = malloc(clean_len + 1);
	if (!clean)
		return (NULL);
	clean_len = 0;
	pos = 0;
	while (ft_isspace(entry[pos]) && entry[pos] != ':')
	{
		clean[clean_len++] = entry[pos++];
	}
	while (ft_isspace(entry[pos]))
		pos++;
	clean[clean_len++] = entry[pos++];
	while (ft_isspace(entry[pos]))
		pos++;
	while (entry[pos])
	{
		clean[clean_len++] = entry[pos++];
	}
	clean[clean_len] = '\0';
	return (clean);
}

char	*get_line(int fd)
{
	char	buf[BUF_SIZE];
	char	*line;
	size_t	len;

	len = 0;
	while (1)
	{
		if (read(fd, (buf + len), 1) < 1 || buf[len] == '\n')
			break ;
		len++;
	}
	if (len == 0 && buf[len++] != '\n')
		return (NULL);
	line = malloc(len);
	if (!line)
		return (NULL);
	line[len] = '\0';
	while (len--)
	{
		line[len] = buf[len];
	}
	return (line);
}
