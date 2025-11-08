#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 255

typedef struct {
    int matricula;
    char nome[100];
    float nota;
} Aluno;


typedef struct {
    Aluno *tabela[TABLE_SIZE];
} HashTable;

unsigned int hash(const char chave) {
    return (unsigned)chave % TABLE_SIZE;
}

HashTable *create_table() {
    HashTable *table = (HashTable*)malloc(sizeof(HashTable));
    if (table) {
        for (int i = 0; i < TABLE_SIZE; i++)
            table->tabela[i] = NULL;
    }
    return table;
}

void insert(HashTable *table, Aluno *aluno) {
    try{
        unsigned int idx = hash(aluno->matricula);
        if(table->tabela[idx] != NULL) {
            throw(table, idx);
        }else{
            table->tabela[idx] = aluno;
        }
    }catch(unsigned int idx) {
        printf("Colisao na posicao %u\n", idx);
    }
    return;
}

Aluno *search(HashTable *table, const char chave) {
    unsigned int idx = hash(chave);
    if (table->tabela[idx] != NULL && table->tabela[idx]->matricula == chave) {
        return table->tabela[idx];
    }else{
        //Considerar que o aluno não foi encontrado na posição base mas pode estar em outra posição devido a colisões
    }
    return NULL;
}

void free_table(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->tabela[i] != NULL) {
            free(table->tabela[i]);
        }
    }
    free(table);
}

int main() {

    Aluno *joao = (Aluno*)malloc(sizeof(Aluno));
    joao->matricula = 10;
    strcpy(joao->nome, "Joao");
    joao->nota = 8.5;
    Aluno *maria = (Aluno*)malloc(sizeof(Aluno));
    maria->matricula = 20;
    strcpy(maria->nome, "Maria");
    maria->nota = 9.0;

    HashTable *table = create_table();
    insert(table, joao);
    insert(table, maria);
    insert(table, joao);

    Aluno *v = search(table, joao->matricula);
    if (v) 
        printf("Valor de joao: %d\n", v->matricula);
    return 0;
}