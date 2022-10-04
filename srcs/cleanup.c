#include "rush02.h"

void	free_dict(t_dict *dict)
{
	size_t	i;

	i = 0;
	while (i < NB_ENTRIES)
	{
		free(dict->entries[i++]);
	}
	if (dict->extra_entries)
	{
		while (dict->nb_extra_entries)
		{
			free(dict->extra_entries[--dict->nb_extra_entries]);
		}
		free(dict->extra_entries);
	}
	free(dict);
}
