#include "cube3d.h"
#include <string.h>

void ft_parse_u1_t(char *nb, t_u1 expected, t_bool success)
{
    t_u1 out;
    t_bool ret;

    ret = ft_parse_u1(nb, &out);
    if (success)
        printf("EXPECTED: %d GOT: %d - %s\n", (int)expected, (int)out, out == expected ? "GOOD" : "BAD");
    else
        printf("%s EXPECTED TO FAIL : %s\n", nb, success == FALSE ? "GOOD" : "FALSE");
}

void    ft_strtrim_end_t(char *str)
{
    char *s = strdup(str);
    printf("STR TO TEST: [%s] - ", s);
    ft_strtrim_end(s);
    printf("[%s]\n", s);
    free(s);
}

int main(int ac, char **av)
{
   ft_strtrim_end_t("aaa        \n");
   ft_strtrim_end_t("aaa");
   ft_strtrim_end_t("\n");
   ft_strtrim_end_t(" ");
   ft_strtrim_end_t("");
}