#include <stdio.h>
#include <time.h>

#define MAX_N 1000

int NMax = 100000; // Exemplo padrão para n=20

int memo[MAX_N]; // Array para memoização

// Fibonacci com recursão e memoização
int x(int n) {
    if (n <= 1)
        return 1;

    if (memo[n] != 0)
        return memo[n];

    memo[n] = x(n - 1) + x(n - 2);
    return memo[n];
}

int main() {
    int n = 26; // Valor de n
    double total_time = 0;

    clock_t start, end;

    start = clock();

    for (int i = 0; i < NMax; i++) {
        // Zera o memo para garantir que cada execução seja "do zero"
        for (int j = 0; j <= n; j++) {
            memo[j] = 0;
        }

        x(n);
    }

    end = clock();

    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    double tempo_medio = total_time / NMax;

    printf("Tempo medio = %.12f segundos\n", tempo_medio);

    return 0;
}
