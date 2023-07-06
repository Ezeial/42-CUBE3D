#include "cube3d.h"

t_bool  ft_validate_datas(t_data *data)
{
    if (!ft_validate_character(data))
        return (FALSE);
    if(!ft_is_map_closed(data))
        return (FALSE);
    return (TRUE);
}