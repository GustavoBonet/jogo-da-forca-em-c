//JOGO DA FORCA

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char palavra [10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
  char letrasErradas [5];
  int achou=0,erros=0, contatamanho=-1, acertos=0;

  //Lendo a palavra da forca
  printf("Digite a palavra: ");
  scanf(" %s",palavra);

  //Contando a quantidade de letras na palavra digitada
  for(int i=0;i<10;i++){
    if(palavra[i] != ' '){
      contatamanho ++;
    }
  }

  char forca[contatamanho],letra;
  char auxiliar[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};

  //Populando o vetor da forca com a palavra digitada pelo usuário
  for(int i=0;i<contatamanho;i++){
    forca[i] = palavra[i];
  }

  //Mostrando na tela a quantidade de letras da palavra digitada e os riscos
  printf("%i letras\n",contatamanho);
  for(int i=0;i<contatamanho;i++){
    printf("_ ");
  }
//Insere o código em looping até o usuário acertar a palavra ou erras 5x
  while(erros<5 && acertos<contatamanho){
    // Solicitando para o usuário digitar a letra desejada
    printf("\nDigite a letra: ");
    scanf(" %c",&letra);
    // Limpando a tela do usuário
    system("clear");
    //Percorrendo um for do tamanho da palavra digitada
    for(int i=0;i<contatamanho;i++){
      //Verificando se a letra digitada consta no índice atual da palavra
      if(letra == forca[i]){
      // Caso verdadeiro, popula o vetor auxiliar com a letra, conta os acertos do usuário e popula a váriavel auxiliar achou
        auxiliar[i] = letra;
        acertos++;
        achou = 1;
      } else if (auxiliar[i] == ' '){
        // Caso negativo, se o índice do vetor auxiliar estiver nulo, preenche com o risco
        auxiliar[i] = '_';
      } 
    }
    // verifica através da variável auxiliar achou se o usuário digitou uma letra correta ou não
    if(achou==0){
      //caso seja igual a 0, conta um erro para o usuário e armazena a letra errada
      letrasErradas[erros] = letra;
      erros++;
    }else{
      // caso não seja 0, seta a variável auxiliar achou como 0 novamente para a próxima execução
      achou=0;
    }
    // printa o vetor auxiliar
    for(int i=0;i<contatamanho;i++){
      printf("%c",auxiliar[i]);
    }
    //printa as letras erradas
    printf("\n Letras erradas: %i\n",erros);
    for(int i=0;i<erros;i++){
      printf("%c -",letrasErradas[i]);
    }
    //verifica se o usuário errou 5 letras
    if(erros==5){
      printf("\nPerdeu");
    }
    //verifica se o usuário acertou todas as letras
    if(acertos==contatamanho){
      printf("\nParabéns!");
    }
  }
  
  return 0;
}


