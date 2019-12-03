/*
** PERSONAL PROJECT, 2019
** largest
** File description:
** main largest
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static char *get_number(void)
{
    return ("7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450");
}

static char *get_mul(char *extract)
{
    char *temp = NULL;
    char *tempc = NULL;
    char *res = my_strdup("1");

    for (uint i = 0; extract[i]; i++) {
        tempc = ctos(extract[i]);
        temp = my_infinmul(res, tempc);
        free(res);
        res = my_strdup(temp);
        free2(temp, tempc);
    }
    return (res);
}

static void largest_product(int digit)
{
    char *number = get_number();
    char *biggest = NULL;
    char *extract = NULL;
    char *mul = NULL;

    for (int i = 0; i < 1000 - digit; i++) {
        extract = my_cut_str(number, i, i + digit - 1);
        mul = get_mul(extract);
        if (my_strcmpi(mul, biggest) == 1) {
            free(biggest);
            biggest = my_strdup(mul);
        }
        free2(extract, mul);
    }
    printf("Largest product in a %d series: %s\n", digit, biggest);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        printf("USAGE\n\t%s [x-digit series]\n", av[0]);
        return (FAILURE);
    }
    if (atoi(av[1]) <= 0) {
        printf("USAGE\n\t%s [x-digit series]\n", av[0]);
        return (FAILURE);
    }
    largest_product(atoi(av[1]));
    return (SUCCESS);
}
