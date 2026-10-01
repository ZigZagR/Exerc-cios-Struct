#include <iostream>

using namespace std;

struct TData {
    int dia, mes, ano;
};

struct Pessoa {
    TData aniversario;
    string nome;
};

bool bissexto(int ano)
{
    if(ano % 400 == 0) return true;
    if(ano % 100 == 0) return false;
    return ano % 4 == 0;
}

bool dataValida(TData data)
{
    switch (data.mes)
    {
        case 1:  case 3:  case 5:  case 7:  case 8:  case 10:  case 12:
            return data.dia >= 1 && data.dia <= 31;
        case 4:  case 6:  case 9:  case 11:
            return data.dia >= 1 && data.dia <= 30;
        case 2:
            if (bissexto(data.ano))
                return data.dia >= 1 && data.dia <= 29;
            else
                return data.dia >= 1 && data.dia <= 28;
    }
    return false;
}

int calculaIdade(TData D, TData Datual)
{
    if (D.mes > Datual.mes || (D.mes == Datual.mes && D.dia > Datual.dia))
    {
        return Datual.ano - D.ano - 1;
    }
    return Datual.ano - D.ano;
}

void criaData(TData &D)
{
    D.mes = 1 + (rand() % 12);
    D.ano = 1940 + (rand() % 74);
    D.dia = 1 + (rand() % 30);
}

int main()
{
    Pessoa pessoas[10];

    for (int i = 0; i < 10; i++) 
    {
        criaData(pessoas[i].aniversario);
        if (!dataValida(pessoas[i].aniversario)) return 1;
        cout << "nome: ";
        cin  >> pessoas[i].nome;
    }

    for (int i = 0; i < 10; i++) 
    {
        cout << pessoas[i].nome << " : " << pessoas[i].aniversario.dia << "/" << pessoas[i].aniversario.mes << "/" << pessoas[i].aniversario.ano << endl;
        cout << pessoas[i].nome << " : " << calculaIdade(pessoas[i].aniversario, {1, 10, 2026}) << endl;
    }


    
    return 0;
}