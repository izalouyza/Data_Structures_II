#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int fib[1600] = {0};


int fibonacci2(int n){
    if(n<=1){
        return n;
    }
   if(fib[n] != 0){
    return fib[n];
   }
   fib[n] = fibonacci2(n-1) + fibonacci2(n-2);
   return fib[n];
}

int main(int agrc, char* argv[]) {
    int n = atoi(argv[1]);
    int n_max = atoi(argv[2]);
    
    clock_t start, end;
    double tempo = 0.0;
    int resultado;

    for(size_t i = 0; i<n_max; i++){
        start = clock();
        resultado = fibonacci2(n);
        end = clock();
        tempo +=((double)(end-start))/CLOCKS_PER_SEC;
        printf("Progresso: %.2f%% concluído.\n", ((i+1)/(double)n_max)*100);
    }

    printf("Fibonacci na posicao %d is %d\n", n, resultado);
    printf("Tempo médio: %f µs\n", (tempo/n_max)*1e6);
    return 0;
}