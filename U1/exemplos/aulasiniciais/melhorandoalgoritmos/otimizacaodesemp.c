#include <stdio.h>
#include <time.h>

#define MAX 1000
int memo[MAX];

int x(int n) {
    if (n <= 1) return 1;
    if (memo[n] != -1) return memo[n];
    memo[n] = x(n - 1) + x(n - 2);
    return memo[n];
}

int main() {
    int n = 45;           // Pode testar até valores bem maiores agora
    int NMax = 1000;
    double total_time = 0;

    for (int i = 0; i < NMax; i++) {
        // Zera o cache antes de cada execução
        for (int j = 0; j < MAX; j++) memo[j] = -1;

        clock_t start = clock();
        x(n);
        clock_t end = clock();

        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo médio para n = %d: %f segundos\n", n, total_time / NMax);
    return 0;
}
