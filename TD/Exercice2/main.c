#include <stdio.h>
#include <time.h>
#include "prime.h"

int main() {
    int n;
    printf("Entrez un nombre n : ");
    scanf("%d", &n);

    clock_t start, end;
    double time_naive, time_efficient;

    // Mesure de la version naïve
    start = clock();
    int count_naive = prime_numbers_naive(n);
    end = clock();
    time_naive = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Mesure de la version efficace
    start = clock();
    int count_efficient = prime_numbers_efficient(n);
    end = clock();
    time_efficient = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nRésultats :\n");
    printf("Naive      : %d nombres premiers trouvés en %.6f secondes\n", count_naive, time_naive);
    printf("Efficient  : %d nombres premiers trouvés en %.6f secondes\n", count_efficient, time_efficient);

    if (time_naive < time_efficient)
        printf("\n La méthode naïve est plus rapide (étrange, mais possible pour petits n)\n");
    else if (time_naive > time_efficient)
        printf("\n La méthode efficace (crible) est plus rapide\n");
    else
        printf("\n Les deux méthodes ont le même temps d'exécution\n");

    return 0;
}
