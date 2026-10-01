#include <iostream>
#include <random>

#define TAM 30

using namespace std;


/*
Escreva uma função template maior que recebe um vetor de N elementos de qualquer tipo
numérico e retorna o maior valor do vetor. Use-a para encontrar a maior nota em um vetor de
notas (float) de uma turma de 30 alunos.
*/

template <typename T>
T maior(T vetor[], int n)
{
    int maior = vetor[0];
    for (int i = 0; i < n; i++)
    {
        if(vetor[i] > maior)
        {
            maior = vetor[i];
        }
    }
    return maior;
}

int main() {
    float notas[TAM];
    for (int i = 0; i < TAM; i++)
    {
        notas[i] = 1 + (rand() % 10);
        cout << "Nota " << i + 1 << ": " << notas[i] << endl;
    }

    cout << "Maior nota: " << maior(notas, TAM) << endl;

}