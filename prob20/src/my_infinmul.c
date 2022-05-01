/*
** PERSONAL PROJECT, 2019
** personal
** File description:
** infinite multiplicator
*/

#include <stdlib.h>

unsigned short my_str_isnum(char const *str);
char *my_utoa(unsigned int nb);
char *my_strcpy(char *dest, char const *src);
char *my_evil_str(const char *str);
int ctoi(char const c);
char itoc(int const i);
int my_getnbr(char const *str);
unsigned int my_strlen(char const *str);

static char *resize_res(char *res, char *tmp)
{
    uint newlen = (res ? my_strlen(res) + 2 : my_strlen(tmp) + 1);
    char *newres = malloc(sizeof(char) * (newlen + 1));
    uint i = 0;

    for (; i < newlen; i++)
        newres[i] = '0';
    newres[i] = 0;
    if (res)
        my_strcpy(newres, res);
    free(res);
    return (newres);
}

static char *add_up(char *res, char *tmp)
{
    int temp = 0;
    int carry = 0;
    uint i = 0;

    res = resize_res(res, tmp);
    for (int temp2 = 0; i < my_strlen(tmp); i++) {
        temp = ctoi(tmp[i]);
        temp2 = (res[i] ? ctoi(res[i]) : 0);
        if (temp + temp2 + carry > 9) {
            temp = (temp + temp2) - 10 + carry;
            carry = 1;
        } else {
            temp += temp2 + carry;
            carry = 0;
        }
        res[i] = itoc(temp);
    }
    res[i] = (carry ? itoc(carry) : 0);
    return (res);
}

static char *get_temp(char *n1, int mul, uint pow)
{
    char *temp = malloc(sizeof(char) * (my_strlen(n1) + pow + 2));
    int tmp = 0;
    int carry = 0;
    uint i = 0;
    uint j = 0;

    for (; j <= my_strlen(n1) + pow + 1; j++)
        temp[j] = 0;
    for (j = 0; j < pow; j++)
        temp[j] = '0';
    for (j = pow; n1[i]; i++) {
        tmp = ctoi(n1[i]) * mul + carry;
        carry = tmp / 10;
        tmp %= 10;
        temp[j] = itoc(tmp);
        j++;
    }
    temp[j] = (carry ? itoc(carry) : 0);
    return (temp);
}

char *my_infinmul(char *n1, char *n2)
{
    char *res = NULL;
    char *tmp = NULL;

    if (!n1 || !n2)
        return (NULL);
    if (!my_str_isnum(n1) || !my_str_isnum(n2) || n1[0] == '-' || n2[0] == '-')
        return (NULL);
    if (my_strlen(n1) + my_strlen(n2) < 10)
        return (my_utoa(my_getnbr(n1) * my_getnbr(n2)));
    my_evil_str(n1);
    my_evil_str(n2);
    for (uint i = 0; n2[i]; i++) {
        free(tmp ? tmp : NULL);
        tmp = get_temp(n1, ctoi(n2[i]), i);
        res = add_up(res, tmp);
    }
    free(tmp ? tmp : NULL);
    my_evil_str(res);
    return (res);
}
