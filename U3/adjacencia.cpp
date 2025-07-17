#include <iostream>

void inicializarMatriz(int** matriz, int numVertices) {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            matriz[i][j] = 0;
        }
    }
}

void adicionarAresta(int** matriz, int origem, int destino, int numVertices) {
    if (origem >= 0 && origem < numVertices && destino >= 0 && destino < numVertices) {
        matriz[origem][destino] = 1;
        matriz[destino][origem] = 1; 
    }
}

void mostrarMatriz(int** matriz, int numVertices) {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int totalVertices = 5;
    int** matrizAdj = (int**)malloc(totalVertices * sizeof(int*));
    for (int i = 0; i < totalVertices; ++i) {
        matrizAdj[i] = (int*)malloc(totalVertices * sizeof(int));
    }

    inicializarMatriz(matrizAdj, totalVertices);

    adicionarAresta(matrizAdj, 0, 1, totalVertices);
    adicionarAresta(matrizAdj, 0, 4, totalVertices);
    adicionarAresta(matrizAdj, 1, 2, totalVertices);
    adicionarAresta(matrizAdj, 1, 3, totalVertices);
    adicionarAresta(matrizAdj, 1, 4, totalVertices);
    adicionarAresta(matrizAdj, 2, 3, totalVertices);
    adicionarAresta(matrizAdj, 3, 4, totalVertices);

    printf("Matriz de Adjacência do Grafo:\n");
    mostrarMatriz(matrizAdj, totalVertices);

    for (int i = 0; i < totalVertices; ++i) {
        delete[] matrizAdj[i];
    }
    delete[] matrizAdj;

    return 0;
}
