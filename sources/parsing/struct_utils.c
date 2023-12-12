#include "../../headers/minishel.h"

void	init_parsing_struct(t_tokens *tok)
{
	tok->isq = 0;
	tok->idq = 0;
	tok->start = 0;
	tok->end = 0;
}