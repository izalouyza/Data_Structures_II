#include <stdio.h>
#include <time.h>

unsigned long long fibonacci(int n) {
    if (n <= 1)
        return 1;

    unsigned long long a = 1, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b; // Calcula o próximo número de Fibonacci
        a = b;     // Atualiza a para o próximo valor
        b = c;     // Atualiza b para o próximo valor
    }
    return b; // Retorna o n-ésimo número de Fibonacci
}

int main() {
    int n = 26;           // Valor de n (pode ser ajustado para valores maiores)
    int NMax = 100000;   // Número de repetições aumentado para melhor medição
    double total_time = 0;

    for (int i = 0; i < NMax; i++) {
        clock_t start = clock();
        unsigned long long result = fibonacci(n);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo medio p = %d: %.12f segundos\n", n, total_time / NMax);

    return 0;
}
