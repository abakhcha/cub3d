#include "headerfile.h"

int elements_are_mixed(char *str)
{
    if(ft_strncmp(str, "NO", 2) == 0)
        return (1);
    else if(ft_strncmp(str, "SO", 2) == 0)
        return (1);
    else if(ft_strncmp(str, "WE", 2) == 0)
        return (1);
    else if(ft_strncmp(str, "EA", 2) == 0)
        return (1);
    else if(str[0] == 'F' && str[1] == '\0')
        return (1);
    else if(str[0] == 'C' && str[1] == '\0')
        return (1);
    return (-1);
}

void compare_texture(char *str, t_elements *elements)
{
    if(ft_strncmp(str, "NO", 2) == 0)
        elements->NO += 1;
    else if(ft_strncmp(str, "SO", 2) == 0)
        elements->SO += 1;
    else if(ft_strncmp(str, "WE", 2) == 0)
        elements->WE += 1;
    else if(ft_strncmp(str, "EA", 2) == 0)
        elements->EA += 1;
}

void compare_floorcellingColor(char *str, t_elements *elements)
{
    if(str[0] == 'F' && str[1] == '\0')
        elements->F += 1;
    else if(str[0] == 'C' && str[1] == '\0')
        elements->C += 1;
}

int check_elementsNumber(t_elements *elements)
{
    if(elements->EA == 1 && elements->WE == 1 && elements->SO == 1 &&
        elements->NO == 1 && elements->F == 1 && elements->C == 1)
        return (1);
    return (-1);
}

int check_elements(char **map)
{
    char *tmp1;
    char **tmp;
    t_elements *elements;
    int i;
    int p;

    i = 0;
    elements = malloc(sizeof(t_elements));
    if (!elements)
        return -1;
    elements->C = 0;
    elements->NO = 0;
    elements->WE = 0;
    elements->SO = 0;
    elements->EA = 0;
    elements->F = 0;
    while(map[i])
    {
        tmp1 = ft_strtrim(map[i]);
        if(tmp1[0])
        {
            tmp = ft_split(tmp1,' ');
            if(elements_are_mixed(tmp[0]) == -1)
                break;//what if i call fill the map here
            compare_texture(tmp[0],elements);
            compare_floorcellingColor(tmp[0],elements);
            free(tmp);
        }
        i++;
        free(tmp1);
    }
        return (check_elementsNumber(elements));
}
