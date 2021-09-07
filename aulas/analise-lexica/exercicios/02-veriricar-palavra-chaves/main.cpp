#include <iostream>
#include <string>
#include <set>
#include <locale.h>
#include "constantes.h"

using namespace std;

set<string> palavraChave;
string palavras[T_MAX] = {"se", "senao", "para"};

void palavrasReservadas()
{
    /// inserir as palavras reservadas
    palavraChave.insert("se");
    palavraChave.insert("sn");
    palavraChave.insert("enquanto");
    palavraChave.insert("para");
}

bool ehPalavraReservada(string palavra){
    /*bool resultado = palavraChave.find(palavras[i])
        == palavraChave.end();
    return resultado;*/

    return (palavraChave.find(palavra)
                != palavraChave.end());
}

void imprimeTexto(string palavra)
{
    cout << FRASE_PADRAO_ERROR << endl;
    /*cout << "A palavra " << palavra;
    cout << " não é uma palavra reservada";
    cout << " Pode ser então um id" << endl;*/
}

// Objetivo é controlar o fluxo
int main()
{
    setlocale(LC_ALL, "portuguese");

    palavrasReservadas();

    for(int i = 0; i < T_MAX; i++){
        if(ehPalavraReservada(palavras[i])) {
           cout << "A palavra " << palavras[i] << " é reservada";
            /// early return
            continue;
        }
        imprimeTexto(palavras[i]);
    }

    // getchar();
    return 0;
}
