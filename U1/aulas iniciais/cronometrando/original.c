#include <stdio.h>
#include <time.h>

int x(int n) {
    if (n <= 1) return 1;
    return x(n - 1) + x(n - 2);
}

int main() {
    int n = 38;             // Valor de n
    int NMax = 1000;        // Número de repetições
    double total_time = 0;

    for (int i = 0; i < NMax; i++) {
        clock_t start = clock();
        x(n);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo médio: %f segundos\n", total_time / NMax);
    return 0;
}
