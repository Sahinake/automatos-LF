Programa que consiste em receber uma string do usuário, que usará apenas caracteres no alfabeto da equipe, 
e deve determinar se ela está na linguagem da gramática
da equipe.

Nosso alfabeto e gramática:
### Alfabeto: 
Σ ={a,b,c}
### Gramática:
S —> acBabA | bcBcC | cbC

A —> abaC | baB | cb

B —> cC | abA | b

C —> aaB | cA | ba

O programa recebe uma string através da entrada padrão (teclado) e imprime a resposta na saída padrão (tela). 
A entrada consistirá apenas de caracteres contidos no alfabeto da equipe. A entrada
terá tamanho de no mínimo zero caracteres (string vazia) e de no máximo 1000 caracteres. Esse limite
desconsidera os caracteres de controle ao final da string da linguagem C, como o ‘\0’ ou o ‘\n’. 
A saída consiste apenasna string “sim\n” caso a string de entrada esteja na linguagem da gramática
da equipe, ou “nao\n” caso contrário. Após imprimir a saída, o programa finaliza a sua execução.
