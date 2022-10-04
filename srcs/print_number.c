#include "rush02.h"

int	get_triplet(char *nb, int triplet_len)
{
	int	triplet;
	
	triplet = nb[0] - '0';
	if (triplet_len > 1)
	{
		triplet *= 10;
		triplet += nb[1] - '0';
	}
	if (triplet_len > 2)
	{
		triplet *= 10;
		triplet += nb[2] - '0';
	}
	return (triplet);
}

void	print_triplet(t_dict *dict, int triplet)
{
	int	dict_index;

	if (triplet >= 100)
	{
		ft_putstr_fd(dict->entries[triplet / 100], 1);
		ft_putstr_fd(" ", 1);
		ft_putstr_fd(dict->entries[HUNDRED_INDEX], 1);
		ft_putstr_fd(" ", 1);
	}
	if (triplet % 100 < 20 && triplet % 100)
	{
		ft_putstr_fd(dict->entries[triplet % 100], 1);
		ft_putstr_fd(" ", 1);
	}
	else if (triplet % 100)
	{
		dict_index = DECADES_INDEX + (triplet % 100) / 10 - 2;
		ft_putstr_fd(dict->entries[dict_index], 1);
		if (triplet % 10)
		{
			ft_putstr_fd("-", 1);
			ft_putstr_fd(dict->entries[triplet % 10], 1);
		}
		ft_putstr_fd(" ", 1);
	}
}

void	print_magnitude(t_dict *dict, size_t nb_len)
{
	int	dict_index;
	
	dict_index = nb_len / 3 - 1;
	dict_index += LARGE_NUMBERS_INDEX;
	if (dict_index >= NB_ENTRIES)
		return ;
	ft_putstr_fd(dict->entries[dict_index], 1);
	ft_putstr_fd(" ", 1);
}

void	print_number(t_dict *dict, char *nb)
{
	size_t	nb_len;
	int		triplet;
	int		triplet_len;

	nb_len = ft_strlen(nb);
	if (nb_len == 1 && nb[0] == '0')
	{
		ft_putstr_fd(dict->entries[0], STDIN_FILENO);
		return ;
	}
	while (nb_len)
	{
		triplet_len = 3;
		if (nb_len % 3)
			triplet_len = nb_len % 3;
		triplet = get_triplet(nb, triplet_len);
		// printf("\ntriplet = %d\n", triplet);
		print_triplet(dict, triplet);
		if ((nb_len - 1) / 3 && triplet)
			print_magnitude(dict, nb_len);
		nb += triplet_len;
		nb_len -= triplet_len;
	}
	ft_putstr_fd("\n", 1);
	// print_last_triplet(dict, triplet);
}