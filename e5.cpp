#include <iostream>

#define TAM 3

using namespace std;

/*Crie uma struct chamada Livro, com os campos titulo (string), autor (string) e paginas (int).
Declare um vetor de 15 Livros e escreva uma função que recebe o vetor preenchido e um número
de páginas, e retorna a quantidade de livros com mais páginas do que o valor informado.
*/

struct Livro
{
    string titulo;
    string autor;
    int paginas;
};

int procuraLivros(Livro livros[], int n, int paginas)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (livros[i].paginas > paginas) count++;
    }
    return count;
}

int main() 
{
    Livro livros[TAM];
    livros[0] = {"LOTM", "FISH", 1000};
    livros[1] = {"SS", "THREE", 2000};
    livros[2] = {"RI", "CHINA", 4000};

    cout << "Livros com mais de 900 paginas: " << procuraLivros(livros, TAM, 900) << endl;
    cout << "Livros com mais de 1000 paginas: " << procuraLivros(livros, TAM, 1000) << endl;
    cout << "Livros com mais de 2000 paginas: " << procuraLivros(livros, TAM, 2000) << endl;

    return 0;
}

