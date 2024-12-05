#include "headerfile.h"
#include <string.h>

int fill_otherelements(char **file_content3, t_lmardhadi **lmard)
{
    char *tmp1;
    char **tmp;
    int i;
    int p;

    i = 0;
    while(file_content3[i])
    {
        tmp1 = ft_strtrim(file_content3[i]);
        if(tmp1[0] != '\0')
        {
            tmp = ft_split(tmp1,' ');
            if(ft_strncmp(tmp[0], "NO", ft_strlen(tmp[0])) == 0)
            {
                if(ft_doublepointerlen(tmp) != 2)
                    return (-1);
                (*lmard)->NO = ft_strdup(tmp[1]);
            }
            else if(ft_strncmp(tmp[0], "SO", ft_strlen(tmp[0])) == 0)
            {
                if(ft_doublepointerlen(tmp) != 2)
                    return (-1);
                (*lmard)->SO = ft_strdup(tmp[1]);
            }
            else if(ft_strncmp(tmp[0], "WE", ft_strlen(tmp[0])) == 0)
            {
                if(ft_doublepointerlen(tmp) != 2)
                    return (-1);
                (*lmard)->WE = ft_strdup(tmp[1]);
            }
            else if(ft_strncmp(tmp[0], "EA", ft_strlen(tmp[0])) == 0)
            {
                if(ft_doublepointerlen(tmp) != 2)
                    return (-1);
                (*lmard)->EA = ft_strdup(tmp[1]);
            }
            else if(ft_strncmp(tmp[0], "F", ft_strlen(tmp[0])) == 0)
            {
                if(ft_doublepointerlen(tmp) != 2)
                    return (-1);
                (*lmard)->F = ft_strdup(tmp[1]);
            }
            else if(ft_strncmp(tmp[0], "C", ft_strlen(tmp[0])) == 0)
            {
                if(ft_doublepointerlen(tmp) != 2)
                    return (-1);
                (*lmard)->C = ft_strdup(tmp[1]);
            }
                int yu = 0;
                while(tmp[yu])
                {
                    free(tmp[yu]);
                    yu++;
                }
                free(tmp);
        }

        i++;
        free(tmp1);
    }
    return 1;
}



char	**doublepointercopy(char **map)
{
	int		i;
	char	**test;

	i = 0;
	while (map[i])
	{
		i++;
	}
	test = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map[i])
	{
		test[i] = ft_strdup(map[i]);
		i++;
	}
	test[i] = NULL;
	return (test);
}

// int comparaison2(char *str)
// {
//     char *pool = ft_strtrim(str);
//     if(pool) 
//         return -1;
//     return 1;
// }

int comparaison2(char *str)
{
    if(ft_strncmp(ft_strtrim(str), "NO", 2) == 0)
        return -1;
    if(ft_strncmp(ft_strtrim(str), "SO", 2) == 0)
        return -1;
    if(ft_strncmp(ft_strtrim(str), "WE", 2) == 0)
        return -1;
    if(ft_strncmp(ft_strtrim(str), "EA", 2) == 0)
        return -1;
    if(ft_strncmp(ft_strtrim(str), "F", 1) == 0)
        return -1;
    if(ft_strncmp(ft_strtrim(str), "C", 1) == 0)
        return -1;
    return 1;
}

char **doubleptr_strim(char **str, int end)
{
    char **map;
    int i = 0;
    int size = 0;
    int start = 0;

    while (str[i] && (comparaison2(str[i]) == -1 || ft_strncmp(ft_strtrim(str[i]), "\0",2) == 0))
    {
        // printf("==================>%s\n",str[i]);
        size++;
        i++;
    }
    start = size;

    // Adjust the ending index
    if (str[end] == NULL)
        end--;
    i = end;
    while (end > start && ft_strncmp(ft_strtrim(str[i]), "\0",2) == 0)
    {
        end--;
        i--;
    }

    // Allocate memory for the map
    map = malloc((end - start + 2) * sizeof(char *));
    if (!map)
        return NULL;

    // Copy strings from start to end
    int q = 0;
    while (start <= end)
    {
        map[q] = ft_strdup(str[start]); // Duplicate string
        start++;
        q++;
    }
    map[q] = NULL; // Null-terminate the array
    return map;
}
int comparaison(char *str)
{
    if(ft_strncmp(ft_strtrim(str), "NO", 2) != 0)
        return -1;
    if(ft_strncmp(ft_strtrim(str), "SO", 2) != 0)
        return -1;
    if(ft_strncmp(ft_strtrim(str), "WE", 2) != 0)
        return -1;
    if(ft_strncmp(ft_strtrim(str), "EA", 2) != 0)
        return -1;
    if(ft_strncmp(ft_strtrim(str), "F", 1) != 0)
        return -1;
    if(ft_strncmp(ft_strtrim(str), "C", 1) != 0)
        return -1;
    return 1;
}
char **fill_map(char **str)
{
    int i = 0;
    int j = 0;
    char **tmp;

    // Calculate the size of the input array
    while (str[i])
        i++;
    int original_size = i;

    // Allocate memory for tmp
    tmp = malloc((original_size + 1) * sizeof(char *));
    if (!tmp)
        return NULL;

    // Find the starting index
    i -= 1;
    int end = i;
    while (i >= 0 && comparaison(str[i]) == -1)
        i--;
    i++;

    // Copy elements to tmp
    while (str[i])
    {
        tmp[j] = ft_strdup(str[i]); // Duplicate string
        i++;
        j++;
    }
    tmp[j] = NULL; // Null-terminate tmp

    // Trim and return the result
    char **result = doubleptr_strim(tmp, j - 1);

    // Free tmp (if necessary)
    for (int k = 0; k < j; k++)
        free(tmp[k]);
    free(tmp);

    return result;
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
    close(fd);
}

int main(int ac, char **av)
{
    int fd;
    char **file_content;
    char **file_content2;
    char **file_content3;
    t_elements *elements;
    t_lmardhadi *lmard;
    elements = (t_elements *)calloc(1, sizeof(t_elements));
    if (elements == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }
       lmard = (t_lmardhadi *)calloc(1, sizeof(t_lmardhadi));
    if (lmard == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }
    if(ac != 2)
        return (printf("check your arguments\n"),1);
    if(checkextention(av[1]) == -1)
        error_print("extiontion error \n");
	fd = open(av[1], O_RDWR);
	if (fd == -1 || !fd)
		error_print("Error::can not open the file\n");
	file_content = map_to_doublepointer(fd);
	fd = open(av[1], O_RDWR);
    file_content2 = map_to_doublepointer(fd);
	fd = open(av[1], O_RDWR);
    file_content3 = map_to_doublepointer(fd);
    if(check_elements(file_content,&elements) == -1)
        error_print("the elements are not correct \n");
    elements->map = fill_map(file_content2);
    if(fill_otherelements(file_content3,&lmard) == -1)
        error_print("check the top of your map \n");
    lmard->map = doublepointercopy(elements->map);
    check_for_textures_extension(lmard);
    check_for_unwanted_chars(lmard);
    int i = 0;
    while(lmard->map[i])
    {
        printf("%s\n", lmard->map[i]);
        i++;
    }
    check_walls(lmard);
    printf("%s\n",lmard->NO);
    printf("%s\n",lmard->C);
    printf("%s\n",lmard->WE);
    printf("%s\n",lmard->SO);
    printf("%s\n",lmard->EA);
    printf("%s\n",lmard->F);
    return 0;
}
