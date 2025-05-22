#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(int agrc, char* argv[]) {
    int n = atoi(argv[1]);
    int n_max = atoi(argv[2]);
    
    clock_t start, end;
    double tempo = 0.0;
    int resultado;

    for(size_t i = 0; i<n_max; i++){
        start = clock();
        resultado = fibonacci(n);
        end = clock();
        tempo +=((double)(end-start))/CLOCKS_PER_SEC;
        printf("Progresso: %.2f%% concluído.\n", ((i+1)/(double)n_max)*100);
    }

    printf("Fibonacci na posicao %d is %d\n", n, resultado);
    printf("Tempo médio: %f µs\n", (tempo/n_max)*1e6);
    return 0;
}