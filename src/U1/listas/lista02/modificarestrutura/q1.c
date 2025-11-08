//Implemente a estrutura de dados para a árvore binária de busca.

typedef struct Aluno {
    char nome[50];           
    int matricula;          
    float nota;              
    struct Aluno *esquerdo;  
    struct Aluno *direito;  
} Aluno;
