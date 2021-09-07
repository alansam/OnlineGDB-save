
#include <stdio.h>

int main()
{
    int i, p;
    float pr;
    printf("donner le poucentage des condidats inscrit? ");
    scanf("%d", &i);
    printf("nombre de condidats inscrits = %d\n", i);
    printf("donner le poucentage des condidats present? ");
    scanf("%d", &p);
    printf("nombre de condidats present = %d\n", p);
    pr = (float) p / i * 100;
    printf("poucentage de presences = %.1f%%\n", pr);

    return 0;
}
