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

//*************************************************************************************** */

// void fill_elements(char **str, t_elements **elements, int type)
// {

//         if(type == 1)
//         else if(type == 2)
//             (*elements)->SO = ft_strdup(str[1]);
//         else if(type == 3)
//             (*elements)->WE = ft_strdup(str[1]);
//         else if(type == 4)
//             (*elements)->EA = ft_strdup(str[1]);
//         else if(type == 5) 
//             (*elements)->F = ft_strdup(str[1]);
//         else if(type == 6) 
//             (*elements)->C = ft_strdup(str[1]);

// }

void compare_texture(char **str, t_elements **elements)
{
    if(ft_strncmp(str[0], "NO", ft_strlen(str[0])) == 0)
    {
        
        (*elements)->NO += 1;
    }
    else if(ft_strncmp(str[0], "SO", ft_strlen(str[0])) == 0)
    {
        // (*lmard)->SO = ft_strdup(str[1]);
        (*elements)->SO += 1;
    }
    else if(ft_strncmp(str[0], "WE", ft_strlen(str[0])) == 0)
    {
        // (*lmard)->WE = ft_strdup(str[1]);
        (*elements)->WE += 1;
    }
    else if(ft_strncmp(str[0], "EA", ft_strlen(str[0])) == 0)
    {
        // (*lmard)->EA = ft_strdup(str[1]);
        (*elements)->EA += 1;
    }
}

void compare_floorcellingColor(char **str, t_elements **elements)
{
    // printf("%s\n",str[0]);
    if(ft_strncmp(str[0], "F", ft_strlen(str[0])) == 0)
    {
        // (*lmard)->F = ft_strdup(str[1]);
        (*elements)->F += 1;
    }
    if(ft_strncmp(str[0], "C", ft_strlen(str[0])) == 0)
    {
        // (*lmard)->C = ft_strdup(str[1]);
        (*elements)->C += 1;
    }
}

int check_elementsNumber(t_elements *elements)
{
    if(elements->EA == 1 && elements->WE == 1 && elements->SO == 1 &&
        elements->NO == 1 && elements->F == 1 && elements->C == 1)
        return (1);
    return (-1);
}

int check_elements(char **map, t_elements **elements)
{
    char *tmp1;
    char **tmp;
    int i;
    int p;

    i = 0;
    (*elements)->C = 0;
    (*elements)->NO = 0;
    (*elements)->WE = 0;
    (*elements)->SO = 0;
    (*elements)->EA = 0;
    (*elements)->F = 0;
    while(map[i])
    {
        tmp1 = ft_strtrim(map[i]);
        if(tmp1[0] != '\0')
        {
            tmp = ft_split(tmp1,' ');
            if(elements_are_mixed(tmp[0]) == -1)
                break;
            compare_texture(tmp,elements);
            compare_floorcellingColor(tmp,elements);
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

        return (check_elementsNumber(*elements));
}
