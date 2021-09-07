#include <stdio.h>
#include <stdlib.h>

#define MAX_CARAC 6

int main()
{
    char primeiroTexto[MAX_CARAC], segundoTexto[MAX_CARAC];

    pegarValorUsuario(primeiroTexto);
    pegarValorUsuario(segundoTexto);

    if(verificaLetrasEmComum(primeiroTexto, segundoTexto))
    {
        // early return
        printf("Ha letras em comum");
        return 0;
    }

    printf("Nao ha letras em comum");
    return 0;
}

void pegarValorUsuario(char *t1)
{
    printf("Informe um texto com ate 5 caracteres\n");
    scanf("%s", t1);
}

int verificaLetrasEmComum(char *t1, char *t2) {
     //  0 1 2 3 4 5
    /// ->T E X T O \0
    /// ->J U K F E        4          5
    for(int i = 0; i < MAX_CARAC-1 ; i++) {
        for(int k = 0; k < MAX_CARAC - 1; k++) {
            if(t1[i] == t2[k]) {
                return 1;
            }
        }
    }
    return 0;
}

int verificaLetrasEmComumWhile(char *t1, char *t2) {
    size_t i = 0, k = 0;
    while(t1[i] != '\0'){
        while(t2[k] != '\0') {
            if(t1[i] == t2[k]) return 1;
            k++;
        }
        i++;
    }
    return 0;
}
