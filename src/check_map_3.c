#include "../libs/so_long.h"

void    find_player_and_exit_position(char **map, t_data *data)
{
    int     i;
    int     j;

    i = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] == 'P')
            {
                data->map_data->player_position[0] = i;
                data->map_data->player_position[1] = j;
            }
            else if (map[i][j] == 'E')
            {
                data->map_data->exit_position[0] = i;
                data->map_data->exit_position[1] = j;
            }
            j++;
        }
        i++;
    }
}

void    flood_fill(char **map, int i, int j, t_data *data)
{
    if (i < 0 || j < 0 || i >= data->map_data->lines || j >= data->map_data->columns)
        return ;
    if (map[i][j] == '1' || map[i][j] == 'J')
        return ;
    map[i][j] = 'J';
    flood_fill(map, i + 1, j, data);
    flood_fill(map, i - 1, j, data);
    flood_fill(map, i, j + 1, data);
    flood_fill(map, i, j - 1, data);
}

int     check_dummy_map(char **map)
{
    int     i;
    int     j;

    i = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'E')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}