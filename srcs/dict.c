#include "rush02.h"

static void	add_0_to_999(t_dict *dict, char *entry, size_t delim_pos)
{
	int	dict_index;
	int	val;

	val = ft_atoi(entry);
	if ((val > 100) || (val > 20 && val % 10))
		return (add_extra_entry(dict, entry));
	else if (val < 10)
		dict_index = DIGITS_INDEX + val;
	else if (val < 20)
		dict_index = TENS_INDEX + (val - 10);
	else
		dict_index = DECADES_INDEX + (val / 10 - 2);
	add_entry_at(dict, entry + delim_pos + 1, dict_index);
}

static void	add_999_plus(t_dict *dict, char *entry, size_t delim_pos)
{
	int		dict_index;
	size_t	pos;

	pos = 0;
	if (entry[pos] == '1')
		pos++;
	while (entry[pos] == '0')
		pos++;
	dict_index = pos / 3 - 1;
	if (pos < 4 || entry[pos] != ':' || (pos - 1) % 3 || dict_index > 12)
		return (add_extra_entry(dict, entry));
	dict_index += LARGE_NUMBERS_INDEX;
	add_entry_at(dict, entry + delim_pos + 1, dict_index);
}

int	add_dict_entry(t_dict *dict, char *entry)
{
	size_t	int_len;

	if (entry[0] == '\n')
		return (EXIT_SUCCESS);
	printf("initial =\t'%s'\n", entry);
	entry = parse_dict_entry(entry);
	if (!entry)
		return (EXIT_FAILURE);
	printf("sanitized =\t'%s'\n", entry);
	int_len = 0;
	while (entry[int_len] != ':')
		int_len++;
	if (int_len < 4)
		add_0_to_999(dict, entry, int_len);
	else
		add_999_plus(dict, entry, int_len);
	free(entry);
	return (EXIT_SUCCESS);
}
