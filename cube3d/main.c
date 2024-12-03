#include "headerfile.h"
#include <string.h>

int comparaison2(char *str)
{
    char *pool = ft_strtrim(str);
    if(pool[0] == '1' || pool[0] == '0') 
        return -1;
    return 1;
}
char **doubleptr_strim(char **str, int end)
{
    char **map;
    int i = 0;
    int size = 0;
    int start = 0;
    while(str[i] && comparaison2(str[i]) == 1)
    {
        size++;
        i++;
    }
    start = size--;
    if(str[end] == NULL)
        end --;
        i = end;
    while(end > start && comparaison2(str[i]) == 1)
    {
        end--;
        i--;
    }
    int q = 0;
    while(start <= end)
    {
        map[q] = ft_strdup(str[start]);
        start++;
        q++;
    }
     map[q] = NULL;
    return map;
}
int comparaison(char *str)
{
    if(str[0] == ' ' || str[0] == '1' ||str[0] == '\n' || str[0] == '0')
        return -1;
    char **str1 = ft_split(str,' ');
    if(ft_strncmp(str1[0], "NO", 3) == 0)
        return (1);
    else if(ft_strncmp(str1[0], "SO", 3) == 0)
        return (1);
    else if(ft_strncmp(str1[0], "WE", 3) == 0)
        return (1);
    else if(ft_strncmp(str1[0], "EA", 3) == 0)
        return (1);
    else if(ft_strncmp(str1[0], "C", 2) == 0)
        return (1);
    else if(ft_strncmp(str1[0], "F", 2) == 0)
        return (1);
    else
        return (-1);
}

char **fill_map(char **str)
{
    int i = 0;
    int j = 0;
    char **tmp;
    while(str[i])
        i++;
    tmp = ft_calloc(i,1);
    if(!tmp)
        return 0;
    i -= 1;
    int end = i;
    while(i >= 0 && comparaison(str[i]) == -1)
        i--;
    i++;
    while(str[i])
    {
        tmp[j] = str[i];
        i++;
        j++;
    }
    tmp[j] = NULL;
    return (doubleptr_strim(tmp,j - 1));
    // return tmp;
}

char	**map_to_doublepointer(int fd)
{
	char	*s1;
	char	*l;
	char	**map;
	int		i;

	l = get_next_line(fd);
	if (l == NULL)
		printf("Error\nempty file \n");
	s1 = calloc(1, 1);
	while (l != NULL)
	{
        if(l[0] == '\n')
		    s1 = str_join(s1, "  \n");
        else
		    s1 = str_join(s1, l);
		free(l);
		l = get_next_line(fd);
	}
	map = ft_split(s1, '\n');
	free(s1);
	return (map);
}

int main(int ac, char **av)
{
    int fd;
    char **file_content;
    char **map;
    
    if(ac != 2)
        return (printf("check your arguments\n"),1);
    if(checkextention(av[1]) == -1)//*******   must add the one from my laptop
        error_print("extiontion error \n");
	fd = open(av[1], O_RDWR);
	if (fd == -1 || !fd)
		error_print("Error::can not open the file\n");
	file_content = map_to_doublepointer(fd);
    if(check_elements(file_content) == -1)
        error_print("the elements are not correct \n");
    map = fill_map(file_content);
        // int p = fill_map(file_content);
    // int i = 0;
    // while(file_content[i])
    // {
    //     printf("%s\n",file_content[i]);
    //     i++;
    // }
    int i = 0;
    while(map[i])
    {
        printf("%s\n",map[i]);
        i++;
    }
}