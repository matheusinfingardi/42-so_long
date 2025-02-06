#include "../libs/so_long.h"

int     main(int argc, char **argv)
{
    t_data  *data;

    if (argc != 2)
    {
        print_error_message("Invalid number of arguments, it should be two.\n", NULL);
        return (1);
    }
    check_file(argv[1]);
    value_initialize(&data);
    check_utils(argv[1], data);
    show_intro(data);
    free_all(data);
    return (0);
}

void    value_initialize(t_data **data)
{
    *data = ft_calloc(sizeof(t_data), 1);
    if (!*data)
        ft_printf("Memory allocation failed", NULL);
    (*data)->map_data = ft_calloc(sizeof(t_map_data), 1);
    if (!(*data)->map_data)
        ft_printf("Memory allocation failed", *data);
    (*data)->content = ft_calloc(sizeof(t_content), 1);
    if (!(*data)->content)
        ft_printf("Memory allocation failed", *data);
    (*data)->content->player = 0;
    (*data)->content->collectible = 0;
    (*data)->content->exit = 0;
    (*data)->map_data->lines = 0;
    (*data)->map_data->columns = 0;
    (*data)->map_data->map = NULL;
    (*data)->map_data->player_position[0] = 0;
    (*data)->map_data->player_position[1] = 0;
    (*data)->map_data->moves = 0;
}

void    print_error_message(char *message, t_data *data)
{
    ft_printf("Error\n%s", message);
    if (data != NULL)
    {
        free_all(data);
        data = NULL;
    }
    exit(1);
}