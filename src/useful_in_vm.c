


/*
** tok->codage == unsigned char value
** arg -> argument position from left to right
*/
static void ft_set_codage(t_token *tok, int arg, t_arg_type t)
{

	if (arg == 0)
		tok->codage = tok->codage | t << 6;
	else if (arg == 1)
		tok->codage = tok->codage | t << 4;
	else if (arg == 2)
		tok->codage = tok->codage | t << 2;
	else if (arg == 3)
		tok->codage = tok->codage | t;
}

/*
 * Little-endian to big-endian
 */
int 	ft_to_big_endian(int n)
{
	int nv;

	nv = (((n << 8) & 0xFF00FF00) | ((n >> 8) & 0xFF00FF));
	return ((nv << 16) | ((nv >> 16) & 0xFFFF));
}

short 	ft_to_big_sendian(short n)
{
	return ((n << 8) | ((n >> 8) & 0xFF));
}