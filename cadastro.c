#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Aluno{
    char nome[100];
    int idade;
    float nota1;
    float nota2;
    float media;
};

void mostrarAluno(struct Aluno aluno) {
    printf("Nome: %s\n", aluno.nome);
    printf("Idade: %d\n", aluno.idade);
    printf("Nota 1: %.2f\n", aluno.nota1);
    printf("Nota 2: %.2f\n", aluno.nota2);
    printf("Media: %.2f\n", aluno.media);
    printf("-------------\n");
}

void cadastraAluno(struct Aluno alunos[], int *total){
    printf("1. Cadastrar aluno\n");
    
    printf("Digite o nome do aluno: ");
    fflush(stdin);
    fgets(alunos[*total].nome, 100, stdin);
    alunos[*total].nome[strcspn(alunos[*total].nome, "\n")] = '\0';
    
    printf("Digite a idade do aluno: ");
    scanf("%d", &alunos[*total].idade);
    
    printf("Digite as notas do aluno: ");
    scanf("%f %f", &alunos[*total].nota1, &alunos[*total].nota2);
    
    alunos[*total].media = (alunos[*total].nota1 + alunos[*total].nota2) / 2;
    
    (*total)++;
}

void listarAlunos(struct Aluno alunos[], int total){
    printf("2. Listar alunos\n\n");

    if(total == 0){
        printf("Nenhum aluno cadastrado ainda.\n");
        return;
    }

    for ( int i = 0; i < total; i++){
        printf("Aluno %d:\n", i + 1);
        mostrarAluno(alunos[i]);
    }                
}

void buscarAluno(struct Aluno Alunos[], int total){
    char buscarNome[100];
    int encontrado = 0;
    int i;

    printf("3. Buscar aluno por nome\n");
    
    printf("Digite o nome do aluno: ");
    fflush(stdin);
    fgets(buscarNome, 100, stdin);
    buscarNome[strcspn(buscarNome, "\n")] = '\0';
    
    for ( i = 0; i < total; i++){
        if(strcmp(buscarNome, Alunos[i].nome) == 0){
            mostrarAluno(Alunos[i]);
            encontrado = 1;
            break;
        }
    }
    if(!encontrado){
        printf("Aluno nao encontrado.\n");
    }
}

int main(){
    int opcao;
    int TotalAlunos = 0;
    struct Aluno nomes[100];

    setlocale(LC_ALL, "");
    
    do{
        printf("\n---MENU---\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Listar alunos\n");
        printf("3. Buscar aluno por nome\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao){
            case 1:
            cadastraAluno(nomes, &TotalAlunos);
            break;
            case 2:
            listarAlunos(nomes, TotalAlunos);
            break;
            case 3:
            buscarAluno(nomes, TotalAlunos);
            break;
            case 4:
                printf("4. Sair\n");
                printf("Saindo do programa.");
            break;
            default:
                printf("Opcao invalida. Tente novamente.");
            break;
            }
    } while (opcao != 4);

    system("pause");
    return 0;
}