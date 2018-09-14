#include "../includes/asm.h"

//int ft_get_distance(t_application *app, t_token *t)
//{
//	ft_get_target_label
//}

//void	ft_convert_labels(t_application *app)
//{
//	t_token *t;
//
//	if (!(t = app->tokens))
//		ft_error(ET_UNDEFINED_ERROR, NULL);
//	while (t)
//	{
//		if (t->type_of_token == TT_ARGUMENT &&
//		(t->arg_type == AT_DIRECT_LABEL ||
//		t->arg_type == AT_INDIRECT_LABEL))
//		{
//			if (t->arg_size == AS_TWO)
//				t->two_b_val = ft_get_distance(app, t);
//			else if (t->arg_size == AS_FOUR)
//				t->four_b_val = ft_get_distance(app, t);
//		}
//		t = t->next;
//	}
//}