#include "headerfile.h"

int	checkextention(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if(len <= 4)
		return (-1);
	if (ft_strncmp(".cub", str + len - 4, 4) != 0)
		return (-1);
	return (1);
}

void	check_for_textures_extension(t_lmardhadi *lmard)
{
	if (ft_strncmp(lmard->SO + ft_strlen(lmard->SO) - 4, ".xpm", 4) != 0)
		error_print("Error\nSO texture must be a .xpm file\n");
	if (ft_strncmp(lmard->NO + ft_strlen(lmard->NO) - 4, ".xpm", 4) != 0)
		error_print("Error\nNO texture must be a .xpm file\n");
	if (ft_strncmp(lmard->WE + ft_strlen(lmard->WE) - 4, ".xpm", 4) != 0)
		error_print("Error\nWE texture must be a .xpm file\n");
	if (ft_strncmp(lmard->EA + ft_strlen(lmard->EA) - 4, ".xpm", 4) != 0)
		error_print("Error\nEA texture must be a .xpm file\n");
}


void	check_for_unwanted_chars(t_lmardhadi *lmard)
{
	int	i;
	int	j;
	int l;

	i = 0;
	while (lmard->map[i])
	{
		j = 0;
		if(ft_strlen(ft_strtrim(lmard->map[i])) == 0)
				error_print("empty line in the map\n");
		while (lmard->map[i][j])
		{
			if (lmard->map[i][j] != '1' && lmard->map[i][j] != '0'
				&& lmard->map[i][j] != 'N' && lmard->map[i][j] != 'S'
				&& lmard->map[i][j] != 'W' && lmard->map[i][j] != 'E'
				&& lmard->map[i][j] != ' ')
				error_print("Error\nUnwanted character in map\n");
			j++;
		}
		i++;
	}
}
void	check_walls(t_lmardhadi *lmard)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(lmard->map[i])
	{
		j = 0;
		while(lmard->map[i][j])
		{
			if(lmard->map[i][j] == '0' 
				&& (j == 0 || lmard->map[i][j + 1] == '\0' || lmard->map[i - 1][j] == ' '
				|| lmard->map[i + 1][j] == ' '|| lmard->map[i][j - 1] == ' ' || lmard->map[i][j + 1] == ' '))
			{
				error_print("check ur walls pls\n");
			}
			if(lmard->map[i][j] == '0' 
				&& (!lmard->map[i][j + 1] || !lmard->map[i - 1][j]
				|| !lmard->map[i + 1][j]|| !lmard->map[i][j - 1]))
			{
				error_print("check ur walls pls2\n");
			}
			j++;
		}
		i++;
	}
}