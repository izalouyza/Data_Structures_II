#include <stdio.h>
#include <math.h>
#include <time.h>

unsigned long long fibonacci_closed(int n) {
    const double phi = (1 + sqrt(5)) / 2;
    const double psi = (1 - sqrt(5)) / 2;
    return (unsigned long long)round((pow(phi, n) - pow(psi, n)) / sqrt(5));
}

int main() {
    int n = 26;            // Valor de n
    int NMax = 100000;    // Número de repetições aumentado
    double total_time = 0;

    unsigned long long result = 0; // Para guardar o resultado e evitar otimização

    for (int i = 0; i < NMax; i++) {
        clock_t start = clock();
        result = fibonacci_closed(n);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo médio: %.12f segundos\n", total_time / NMax);

    return 0;
}
