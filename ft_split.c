#include "minishel.h"
#include "ft_split.h"


void	ft_split(t_shell *shell, char *line)
{
	t_split	split;
	int	i;
	int	a;

	i = 0;
	a = 0;
	init_split_struct(&split);
	word_count(&split, line);
	while (a < split.word_count)
	{
		set_quotation(&split, line[i]);
		while (line[i] && line)
	}

}

int main()
{
	t_split	split;
	init_split_struct(&split);
	word_count(&split, "hello    \" world hahahha test \" ivan    ");
	printf("%d", split.word_count);
}