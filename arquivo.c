#include <stdio.h>

int S(const char *input, int *pos), A(const char *input, int *pos), B(const char *input, int *pos), C(const char *input, int *pos);

int S(const char *input, int *pos) {
    int i = *pos;
    if (input[i] == 'a' && input[i + 1] == 'c') { *pos += 2; if (B(input, pos) && input[*pos] == 'a' && input[*pos + 1] == 'b') { *pos += 2; return A(input, pos); } }
    *pos = i; if (input[i] == 'b' && input[i + 1] == 'c') { *pos += 2; if (B(input, pos) && input[*pos] == 'c') { *pos += 1; return C(input, pos); } }
    *pos = i; if (input[i] == 'c' && input[i + 1] == 'b') { *pos += 2; return C(input, pos); }
    *pos = i; return 0;
}

int A(const char *input, int *pos) {
    int i = *pos;
    if (input[i] == 'a' && input[i + 1] == 'b' && input[i + 2] == 'a') { *pos += 3; return C(input, pos); }
    *pos = i; if (input[i] == 'b' && input[i + 1] == 'a') { *pos += 2; return B(input, pos); }
    *pos = i; if (input[i] == 'c' && input[i + 1] == 'b') { *pos += 2; return 1; }
    *pos = i; return 0;
}

int B(const char *input, int *pos) {
    int i = *pos;
    if (input[i] == 'c') { *pos += 1; return C(input, pos); }
    *pos = i; if (input[i] == 'a' && input[i + 1] == 'b') { *pos += 2; return A(input, pos); }
    *pos = i; if (input[i] == 'b') { *pos += 1; return 1; }
    *pos = i; return 0;
}

int C(const char *input, int *pos) {
    int i = *pos;
    if (input[i] == 'a' && input[i + 1] == 'a') { *pos += 2; return B(input, pos); }
    *pos = i; if (input[i] == 'c') { *pos += 1; return A(input, pos); }
    *pos = i; if (input[i] == 'b' && input[i + 1] == 'a') { *pos += 2; return 1; }
    *pos = i; return 0;
}

int main() {
    char input[1002]; int i = 0, length = 0, pos = 0; char c;
    while (i < 1000 && (c = getchar()) != '\n' && c != EOF) input[i++] = c; 
    input[length = i] = '\0'; 
    if (S(input, &pos) && pos == length) printf("sim\n");
    else printf("nao\n");
    return 0;
}
