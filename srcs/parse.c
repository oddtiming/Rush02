#include "rush02.h"

static t_dict	*new_dict(void)
{
	t_dict	*dict;
	size_t	i;

	dict = malloc(sizeof(t_dict));
	if (!dict)
		return (NULL);
	i = 0;
	while (i < NB_ENTRIES)
		dict->entries[i++] = NULL;
	dict->extra_entries = NULL;
	dict->nb_extra_entries = 0;
	return (dict);
}

/**
 * Checks that entry format is:
 * 		 [uint][0_to_n_whitespace]:[0_to_n_whitespaces][any printable characters]
 * 
 */
char	*parse_dict_entry(char *entry)
{
	size_t	clean_len;
	size_t	pos;

	pos = 0;
	while (ft_isdigit(entry[pos]) && entry[pos] != ':' && entry[pos])
		pos++;
	if (!pos)
		return (NULL);
	clean_len = pos;
	while (ft_isspace(entry[pos]) && entry[pos] != ':' && entry[pos])
		pos++;
	if (entry[pos] != ':')
		return (NULL);
	while (ft_isspace(entry[pos]) && entry[pos])
		pos++;
	if (!entry[pos])
		return (NULL);
	while (entry[pos])
	{
		pos++;
		clean_len++;
	}
	printf("clean_len = %lu\n", clean_len);
	return (get_clean_entry(entry, clean_len));
}

static	t_dict	*check_if_dict_is_complete(t_dict *dict)
{
	int	i;

	i = 0;
	while (i < NB_ENTRIES)
	{
		//FIXME: to remove
		printf("entry[%d]:%s\n", i, dict->entries[i]);
		// end of remove
		if (!dict->entries[i])
		{
			free_dict(dict);
			return (NULL);
		}
		i++;
	}
	return (dict);
}

t_dict	*parse_dict(char *path)
{
	t_dict	*dict;
	char	*entry;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	dict = new_dict();
	if (!dict)
		return (NULL);
	entry = get_line(fd);
	while (entry)
	{
		if (add_dict_entry(dict, entry))
		{
			free(entry);
			free_dict(dict);
			return (NULL);
		}
		free(entry);
		entry = get_line(fd);
	}
	close(fd);
	//FIXME: to remove
	return (dict);
	return (check_if_dict_is_complete(dict));
}

/**
 * @brief parses input, removing leading or trailing whitespaces
 * 
 * @param input should be a positive integer
 * @return char* : malloced copy of sanitized input
 */
char	*parse_input(char *input)
{
	int		i;
	char	*copy;

	while (ft_isspace(*input))
		input++;
	if (*input == '+')
		input++;
	i = 0;
	while (ft_isdigit(input[i]))
		i++;
	copy = input + i;
	while (ft_isspace(input[i]))
		i++;
	if (input[i])
		return (NULL);
	i = copy - input;
	copy = malloc(i);
	if (!copy)
		return (NULL);
	copy[i] = '\0';
	while (i--)
		copy[i] = input[i];
	return (copy);
}
