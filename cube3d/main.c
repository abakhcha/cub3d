#include "headerfile.h"
#include <string.h>

    void palyer_exists(t_lmardhadi *lmard)
    {
        int i = 0;
        int j;
        int p = 0;
        int playeri;
        int playerj;

        while(lmard->map[i])
        {
           j = 0;
           while(lmard->map[i][j])
           {
                if(lmard->map[i][j] == 'N' || lmard->map[i][j] == 'S'
                    || lmard->map[i][j] == 'W'|| lmard->map[i][j] == 'E')
                    {
                        p += 1;
                        playeri = i;
                        playerj = j;
                    }
                    j++;
           }
            i++;
        }
            if(p != 1)
                error_print("check the players number\n");
			if((lmard->map[playeri][playerj] == 'E' || lmard->map[playeri][playerj] == 'W' || lmard->map[playeri][playerj] == 'N' || lmard->map[playeri][playerj] == 'S') 
				&& (lmard->map[playeri][playerj + 1] == '1' && lmard->map[playeri - 1][playerj] == '1'
				&& lmard->map[playeri + 1][playerj] == '1'&& lmard->map[playeri][playerj - 1] == '1'))
                {
				    error_print("the player is surronded\n");
                }
			if(playeri == 0 || playeri == i - 1 || !lmard->map[playeri][playerj + 1] || !lmard->map[playeri - 1][playerj]
				|| !lmard->map[playeri + 1][playerj]|| !lmard->map[playeri][playerj - 1])
                {
				    error_print("check the player position\n");
                }
    }

void check_textures_extention(t_lmardhadi *lmard)
{
    if( open(lmard->NO, O_RDWR) == -1)
        error_print("check ur textures files\n");
    else if( open(lmard->SO, O_RDWR) == -1)
        error_print("check ur textures files\n");
    else if( open(lmard->WE, O_RDWR) == -1)
        error_print("check ur textures files\n");
    else if( open(lmard->EA, O_RDWR) == -1)
        error_print("check ur textures files\n");

}

int	ft_atoi(char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
} 

void check_fc(t_lmardhadi *lmard)
{
    char **tmp = ft_split(lmard->C, ',');
    if(ft_doublepointerlen(tmp) != 3)
        error_print("elements problem\n");
    if(ft_atoi(tmp[0]) < 0 || ft_atoi(tmp[0]) > 255 || ft_atoi(tmp[1]) < 0 || ft_atoi(tmp[1]) > 255 || ft_atoi(tmp[2]) < 0 || ft_atoi(tmp[2]) > 255)
        error_print("elements problem\n");
    char **tmp2 = ft_split(lmard->F, ',');
    if(ft_doublepointerlen(tmp2) != 3)
        error_print("elements problem\n");
    if(ft_atoi(tmp2[0]) < 0 || ft_atoi(tmp2[0]) > 255 || ft_atoi(tmp2[1]) < 0 || ft_atoi(tmp2[1]) > 255 || ft_atoi(tmp2[2]) < 0 || ft_atoi(tmp2[2]) > 255)
        error_print("elements problem\n");
}

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
    if (str[end] == NULL)
        end--;
    i = end;
    while (end > start && ft_strncmp(ft_strtrim(str[i]), "\0",2) == 0)
    {
        end--;
        i--;
    }
    map = malloc((end - start + 2) * sizeof(char *));
    if (!map)
        return NULL;
    int q = 0;
    while (start <= end)
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
    
    while (str[i])
        i++;
    int original_size = i;
    tmp = malloc((original_size + 1) * sizeof(char *));
    if (!tmp)
        return NULL;
    i -= 1;
    int end = i;
    while (i >= 0 && comparaison(str[i]) == -1)
        i--;
    i++;
    while (str[i])
    {
        tmp[j] = ft_strdup(str[i]);
        i++;
        j++;
    }
    tmp[j] = NULL;
    char **result = doubleptr_strim(tmp, j - 1);
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
    check_fc(lmard);
    check_textures_extention(lmard);
    // int i = 0;
    // while(lmard->map[i])
    // {
    //     printf("%s\n", lmard->map[i]);
    //     i++;
    // }
    check_walls(lmard);
    palyer_exists(lmard);

    // printf("%s\n",lmard->NO);
    // printf("%s\n",lmard->C);
    // printf("%s\n",lmard->WE);
    // printf("%s\n",lmard->SO);
    // printf("%s\n",lmard->EA);
    // printf("%s\n",lmard->F);
    return 0;
}
