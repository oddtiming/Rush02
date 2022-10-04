#include "rush02.h"

void	add_extra_entry(t_dict *dict, char *entry)
{
	char	**new_entries;
	size_t	i;

	dict->nb_extra_entries++;
	new_entries = malloc(sizeof(char *) * dict->nb_extra_entries);
	i = 0;
	while (i < dict->nb_extra_entries - 1)
	{
		new_entries[i] = dict->extra_entries[i];
		i++;
	}
	new_entries[i] = ft_strdup(entry);
	free(dict->extra_entries);
	dict->extra_entries = new_entries;
}

void	add_entry_at(t_dict *dict, char *entry, int dict_index)
{
	printf("in add_entry_at, dict_index = %d for '%s'\n", dict_index, entry);
	if (dict_index < 0 || dict_index > NB_ENTRIES)
		return ;
	if (dict->entries[dict_index])
		return ;
	dict->entries[dict_index] = ft_strdup(entry);
}
