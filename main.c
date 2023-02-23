#include "includes/lib/includes.h"

int main()
{
    char *str = "this, is, a, test";
    char **map = my_str_split(str, ", ");
    for (int i = 0; map[i]; i++)
        my_debug('S', map[i]);
    for (int i = 0; map[i]; i++)
        free(map[i]);
    free(map);
}