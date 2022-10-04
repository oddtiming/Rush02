#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <limits.h>

// FIXME: to remove
# include <stdio.h>
// end of remove

# define BUF_SIZE 65536
# define DICT_PATH "dict/numbers.dict"
# define NB_ENTRIES 42
# define DIGITS_INDEX 0
# define TENS_INDEX 10
# define DECADES_INDEX 20
# define HUNDRED_INDEX 28
# define LARGE_NUMBERS_INDEX 29

typedef struct s_dict
{
	char	*entries[NB_ENTRIES];
	char	**extra_entries;
	size_t	nb_extra_entries;
}	t_dict;

typedef struct s_rush02
{
	char	*input;
	t_dict	dict;
}	t_rush02;

// cleanup.c
void	free_dict(t_dict *dict);

// dict.c
int		add_dict_entry(t_dict *dict, char *entry);

// dict_utils.c
void	add_extra_entry(t_dict *dict, char *entry);
void	add_entry_at(t_dict *dict, char *entry, int dict_index);

// parse.c
char	*parse_input(char *input);
t_dict	*parse_dict(char *path);
char	*parse_dict_entry(char *entry);

// parse_utils.c
char	*get_line(int fd);
char	*get_clean_entry(char *entry, size_t clean_len);

// print_number.c
void	print_number(t_dict *dict, char *nb);

// utils.c
size_t	ft_strlen(char *str);
int		ft_putstr_fd(char *str, int fd);
char	*read_user_input(char *buf);
bool	ft_isspace(char c);
bool	ft_isdigit(char c);

// utils.c
char	*ft_strdup(char *str);
int		ft_atoi(const char *str);

#endif // RUSH02_H