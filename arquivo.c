#include <stdio.h>

// Função principal do programa
int S(const char *input, int *pos);
int A(const char *input, int *pos);
int B(const char *input, int *pos);
int C(const char *input, int *pos);

int S(const char *input, int *pos) {
    int i = *pos;
    // acBabA
    if (input[i] == 'a' && input[i + 1] == 'c') { 
        *pos = i + 2;
        int j = *pos;
        if (B(input, pos) && input[j + 1] == 'a' && input[j + 2] == 'b') {
            *pos = j + 3;
            if(A(input, pos)) {
                return 1; 
            }
        }
    }

    *pos = i;
    // bcBcC
    if (input[i] == 'b' && input[i + 1] == 'c') { 
        *pos = i + 2;
        int j = *pos;
        if (B(input, pos) && input[j + 1] == 'c') {
            *pos = j + 2;
            if(C(input, pos)) {
                return 1;
            }
        }
    }

    *pos = i;
    // cbC
    if (input[i] == 'c' && input[i + 1] == 'b') { 
        *pos = i + 2;
        if (C(input, pos)) return 1; 
    }

    *pos = i;
    return 0;
}

int A(const char *input, int *pos) {
    int i = *pos;
    // abaC
    if (input[i] == 'a' && input[i + 1] == 'b' && input[i + 2] == 'a') { 
        *pos = i + 3;
        if (C(input, pos)) return 1; 
    }

    *pos = i;
    // baB
    if (input[i] == 'b' && input[i + 1] == 'a') { 
        *pos = i + 2; 
        if (B(input, pos)) return 1; 
    }

    *pos = i;
    // cb
    if (input[i] == 'c' && input[i + 1] == 'b') { 
        *pos = i + 2; 
        return 1; 
    }

    *pos = i;
    return 0;
}

int B(const char *input, int *pos) {
    int i = *pos;
    // cC
    if (input[i] == 'c') { 
        *pos = i + 1; 
        if (C(input, pos)) return 1; 
    }
    *pos = i;
    // abA
    if (input[i] == 'a' && input[i + 1] == 'b') { 
        *pos = i + 2; 
        if (A(input, pos)) return 1; 
    }
    *pos = i;
    // b
    if (input[i] == 'b') { 
        *pos = i + 1;  
        return 1; 
    }
    *pos = i;
    return 0;
}

int C(const char *input, int *pos) {
    int i = *pos;
    // aaB
    if (input[i] == 'a' && input[i + 1] == 'a') { 
        *pos = i + 2; 
        if (B(input, pos)) return 1; 
    }
    *pos = i;
    // cA
    if (input[i] == 'c') { 
        *pos = i + 1; 
        if (A(input, pos)) return 1; 
    }
    *pos = i;
    // ba
    if (input[i] == 'b' && input[i + 1] == 'a') { 
        *pos = i + 2; 
        return 1; 
    }
    *pos = i;
    return 0;
}

int main() {
    char input[1002]; // 1000 caracteres + '\n' + '\0'
    int i = 0, length = 0;
    int pos = 0; // Altera para uma variável inteira
    char c;

    // Ler a entrada do usuário caractere por caractere
    while (i < 1000 && (c = getchar()) != '\n' && c != EOF) {
        input[i++] = c;
        length++;
    }

    input[length + 1] = '\0'; // Adiciona o terminador nulo para a string

    if (S(input, &pos) && pos == length) printf("sim\n");
    else printf("nao\n");
    
    return 0;
}
