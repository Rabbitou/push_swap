/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:40:07 by ychennaf          #+#    #+#             */
/*   Updated: 2021/06/03 13:54:52 by ychennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# define BUFFER_SIZE 1

typedef enum e_type
{
	NONE,
	SA,
	SB
}					t_type;

typedef struct s_stack
{
	t_list			*node;
	t_list			*chunk;
	t_list			*chunk_size;
	t_type			type_swap;
	unsigned int	size;
	int				*pivot;
}					t_stack;

int					*alloc_size(int size);
int					*list_to_tab(t_list *lst);
void				get_chunk_a(t_stack *stack, int size);
void				get_chunk(t_stack *stack, int size);
int					is_desc(t_list *lst);
int					*get_pivot(t_list *lst);
int					check_less_pivot(t_list *lst, int pivot);
int					check_greater_pivot(t_list *lst, int pivot);
int					get_closestless2(int *tab, int size, int pivot, int type);
int					*get_closestless(t_stack *stack, int pivot);
int					total_chunks(t_stack *stack);
void				check_rot(t_stack *stack_a, t_stack *stack_b);
int					push_a_to_b(t_stack *stack_a, t_stack *stack_b);
void				push_less_pivot_to_b(t_stack *a, t_stack *b,
						int *p_c, int *s_chunk_a);
void				push_greater_pivot_to_a(t_stack *a, t_stack *b,
						int rot, int *s_chunk_a);
int					handle_upper_chunk_b(t_stack *stack_a, t_stack *stack_b);
int					handle_upper_chunk_a(t_stack *a, t_stack *b,
						int *s_chunk_a, int *p_c);
int					new_pivot_if_no_less(t_stack *stack_a,
						t_stack *stack_b, int *push_count);
void				handle_new_chunk_in_a(t_stack *a, t_stack *b,
						int *s_chunk_a);
int					sort_stack2(t_stack *stack_a, t_stack *stack_b,
						int size_b, int s_chunk_a);
void				sort_stack(t_stack *stack_a, t_stack *stack_b);
void				small_sort(t_stack *stack_a, t_stack *stack_b);
void				init_stack(t_stack *head, char **ret);
int					ft_lstsize(t_list *lst);
void				push(t_stack *stack, int item);
int					pop(t_stack *stack);
void				swap(t_stack *stack);
void				rotate(t_stack *stack);
void				r_rotate(t_stack *stack);
void				free_stacks(t_list *stack_a, t_list *stack_b);
int					ft_strcmp(char *s1, char *s2);
void				raise_error(t_list *node, char **tab, char **tab2);
int					check_wr(char **argv, int i);
void				exec_ins(char *line, t_stack *stack_a, t_stack *stack_b);
void				check_ins(char *line, t_stack *stack_a, t_stack *stack_b);
int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *str);
char				*ft_strchr(const char *s, int c);
char				*cpy_n(char *buf);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
int					check_sorted(t_stack *stack_a);
char				**check_errors(char **argv);
int					ft_countdigit(long int i);
t_stack				*copy_stack(t_stack *stack);
void				print_times(char c, int times);
char				**tab_join(char **tab, char *line);
int					table_len_2d(char **tab);
void				free_table(char **tab);
int					len_table(char **tab);
void				quicksort(int arr[], int low, int high);
void				print_list(t_list *lst, char *line);
void				deletefirstnode(t_list **lst);
int					*get_closestgreater(t_stack *stack, int pivot);
#endif
