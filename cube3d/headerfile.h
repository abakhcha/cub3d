#ifndef HEADERFILE_H
#define  HEADERFILE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "get_next_line.h"

int	checkextention(char *av);
// int ft_strlen(char *str);
void	error_print(char *str);
char	*ft_substr(char *s, int start, size_t len);
int	ft_strncmp(char *s1, char *s2, size_t n);
char	**ft_split(char *s, char c);
int check_elements(char **map);
char	*ft_strtrim(char *s1);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strdup(char *s1);

typedef struct s_elements
{
    int NO;
    int SO;
    int WE;
    int EA;
    int F;
    int C;
}t_elements;

// typedef struct s_elements
// {
//     char **file_content;
//     char **map;
//     char *NO;
//     char *SO;
//     char *WE;
//     char *EA;
//     char *F;
//     char *C;
// }t_elements;

#endif