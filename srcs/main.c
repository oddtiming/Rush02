#include "rush02.h"

int	main(int argc, char *argv[])
{
	char		buf[BUF_SIZE];
	char		*input;
	t_dict		*dict;

	if (argc < 2)
		input = read_user_input(buf);
	else
		input = argv[1];
	input = parse_input(input);
	if (!input)
		return (ft_putstr_fd("Error\n", STDERR_FILENO));
	if (argc > 2)
		dict = parse_dict(argv[2]);
	else
		dict = parse_dict(DICT_PATH);
	if (!dict)
		return (free(input), ft_putstr_fd("Dict Error\n", STDERR_FILENO));
	for (int i = 0; i < NB_ENTRIES; i++)
		printf("entry[%d]:%s\n", i, dict->entries[i]);	
	print_number(dict, input);
	free(input);
	free_dict(dict);
	return (0);
}
