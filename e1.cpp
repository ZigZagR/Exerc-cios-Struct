#include <iostream>

using namespace std;

/*
Elabore um programa que leia do usuário uma data (crie o tipo data, com dia, mês e ano). Para
a verificação da data, faça uma função que receba a data e retorne verdadeiro se ela é válida e
falso caso contrário. Anos bissextos são dados pelas seguintes regras (segundo o calendário
Gregoriano):
i) De 4 em 4 anos é ano bissexto.
ii) De 100 em 100 anos não é ano bissexto.
iii) De 400 em 400 anos é ano bissexto.
iv) Prevalecem as últimas regras sobre as primeiras.
A título de curiosidade, o ano de 1900 foi o último ano em que a regra ii foi aplicada (não é
bissexto). A próxima vez será em 2100.
*/

struct Data {
    int data;
    int mes;
    int ano;
};

bool bissexto(int ano)
{
    if(ano % 400 == 0) return true;
    if(ano % 100 == 0) return false;
    return ano % 4 == 0;
}

bool dataValida(Data data)
{
    switch (data.mes)
    {
        case 1:  case 3:  case 5:  case 7:  case 8:  case 10:  case 12:
            return data.data >= 1 && data.data <= 31;
        case 4:  case 6:  case 9:  case 11:
            return data.data >= 1 && data.data <= 30;
        case 2:
            if (bissexto(data.ano))
                return data.data >= 1 && data.data <= 29;
            else
                return data.data >= 1 && data.data <= 28;
    }
    return false;
}


int main()
{
    Data d1;
    cout << "Insira data: ";
    cin >> d1.data >> d1.mes >> d1.ano;

    cout << "Data 1: " << (dataValida(d1) ? "valida" : "invalida") << endl;
    cout << "Ano bissexto: " << (bissexto(d1.ano) ? "sim" : "nao") << endl;
}

