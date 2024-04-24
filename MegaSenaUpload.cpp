#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int jogo[1902][6] = {};

int main () {
    
    FILE *file;
    char filename[256];
    int sorteio[61] = {0};  
    int i, j;

    
    printf("Digite o nome do arquivo CSV: ");
    scanf("%255s", filename);

    
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

   
    for (i = 0; i < 1902 && !feof(file); i++) {
        fscanf(file, "%d,%d,%d,%d,%d,%d", &jogo[i][0], &jogo[i][1], &jogo[i][2], &jogo[i][3], &jogo[i][4], &jogo[i][5]);
    }
    fclose(file);

   
    for (i = 0; i < 1902; i++) {
        for (j = 0; j < 6; j++) {
            if (jogo[i][j] > 0 && jogo[i][j] <= 60) {
                sorteio[jogo[i][j]]++;
            }
        }
    }

    
    printf("\n\n");
    for (i = 1; i <= 60; i++) {
        printf("\n %i: %i", i, sorteio[i]);
    }
	for (i=1; i<=60; i++)
    sorteio[i] = 0;

	for (i=0; i<1902; i++)
    for (j=0; j<6; j++)
      switch (jogo[i][j]) {
        case 1 : sorteio[1]++ ; break;
        case 2 : sorteio[2]++ ; break;
        case 3 : sorteio[3]++ ; break;
        case 4 : sorteio[4]++ ; break;
        case 5 : sorteio[5]++ ; break;
        case 6 : sorteio[6]++ ; break;
        case 7 : sorteio[7]++ ; break;
        case 8 : sorteio[8]++ ; break;
        case 9 : sorteio[9]++ ; break;
        case 10 : sorteio[10]++ ; break;
        case 11 : sorteio[11]++ ; break;
        case 12 : sorteio[12]++ ; break;
        case 13 : sorteio[13]++ ; break;
        case 14 : sorteio[14]++ ; break;
        case 15 : sorteio[15]++ ; break;
        case 16 : sorteio[16]++ ; break;
        case 17 : sorteio[17]++ ; break;
        case 18 : sorteio[18]++ ; break;
        case 19 : sorteio[19]++ ; break;
        case 20 : sorteio[20]++ ; break;
        case 21 : sorteio[21]++ ; break;
        case 22 : sorteio[22]++ ; break;
        case 23 : sorteio[23]++ ; break;
        case 24 : sorteio[24]++ ; break;
        case 25 : sorteio[25]++ ; break;
        case 26 : sorteio[26]++ ; break;
        case 27 : sorteio[27]++ ; break;
        case 28 : sorteio[28]++ ; break;
        case 29 : sorteio[29]++ ; break;
        case 30 : sorteio[30]++ ; break;
        case 31 : sorteio[31]++ ; break;
        case 32 : sorteio[32]++ ; break;
        case 33 : sorteio[33]++ ; break;
        case 34 : sorteio[34]++ ; break;
        case 35 : sorteio[35]++ ; break;
        case 36 : sorteio[36]++ ; break;
        case 37 : sorteio[37]++ ; break;
        case 38 : sorteio[38]++ ; break;
        case 39 : sorteio[39]++ ; break;
        case 40 : sorteio[40]++ ; break;
        case 41 : sorteio[41]++ ; break;
        case 42 : sorteio[42]++ ; break;
        case 43 : sorteio[43]++ ; break;
        case 44 : sorteio[44]++ ; break;
        case 45 : sorteio[45]++ ; break;
        case 46 : sorteio[46]++ ; break;
        case 47 : sorteio[47]++ ; break;
        case 48 : sorteio[48]++ ; break;
        case 49 : sorteio[49]++ ; break;
        case 50 : sorteio[50]++ ; break;
        case 51 : sorteio[51]++ ; break;
        case 52 : sorteio[52]++ ; break;
        case 53 : sorteio[53]++ ; break;
        case 54 : sorteio[54]++ ; break;
        case 55 : sorteio[55]++ ; break;
        case 56 : sorteio[56]++ ; break;
        case 57 : sorteio[57]++ ; break;
        case 58 : sorteio[58]++ ; break;
        case 59 : sorteio[59]++ ; break;
        case 60 : sorteio[60]++ ; break;
      }
  printf("\n\n");
  for (i=1; i<=60; i++)
    printf("\n %i: %i",i, sorteio[i]);

  // grafico
  int OndeParou; char alt = 219;
  printf("\n\n    ^");
  for (i=34; i>=0; i--) {
    printf("\n %i|", 157+i*2);
    OndeParou = 1;
    for (j=1; j<=60; j++)
      if (sorteio[j] >= 157+i*2) {
        for (int k=OndeParou; k<j; k++)
          printf(" ");
        printf("%c",alt);
        OndeParou = j+1;
      }
  }
  printf("\n");
  for (i=1; i<70; i++) printf("_");
  printf(">\n     ");

  for (i=1; i<=60; i++)
    if (i<10) printf("0");
    else if (i<20) printf("1");
    else if (i<30) printf("2");
    else if (i<40) printf("3");
    else if (i<50) printf("4");
    else if (i<60) printf("5");
    else printf("6");
  printf("\n     ");
  for (j=1; j<7; j++)
    for (i=1; i<=10; i++)
      if (i==10) printf("0");
      else printf("%i", i);
  printf("\n\n\n Quantos numeros deseja identificar? ");
  int Qtd;
  scanf("%d", &Qtd);
  int maior[Qtd], menor[Qtd];
  for (i=1; i<=Qtd; i++) {
    maior[0] = sorteio[1];
    menor[0] = sorteio[1];
    for (j=1; j<=60; j++) {
      if ((sorteio[j] > maior[0])) {
        maior[i] = j;
        maior[0] = sorteio[j];
      }
      if ((sorteio[j] < menor[0]) && (sorteio[j] != -1)) {
        menor[i] = j;
        menor[0] = sorteio[j];
      }
    }
    sorteio[maior[i]] = -1;
    sorteio[menor[i]] = -1;
  }
  printf("\n\n As %i dezenas MAIS sorteadas foram: \n", Qtd);
  for (i=1; i<=Qtd; i++)
    printf(" %i,", maior[i]);
  printf("\n\n As %i dezenas MENOS sorteadas foram: \n", Qtd);
  for (i=1; i<=Qtd; i++)
    printf(" %i,", menor[i]);

  int Usuario[6];
  printf("\n\n\n Informe um jogo \n\n");
  for (i=1; i<=6; i++) {
    printf(" %i. Dezena: ",i);
    scanf("%i", &Usuario[i]);
  }
  int acerto;
	for (i=0; i<1902; i++) {
	  if (acerto == 6)
      break;
    else
      acerto = 0;
    for (j=0; j<6; j++) {
      for (int y=1; y<=6; y++)
        if (Usuario[y] == jogo[i][j])
          acerto++;
      if (acerto == 6) {
        printf("Caceta vei!!! Vc acertou o sorteio numero: %i ",i);
        break;
      }
    }
  }
  if (acerto < 6)
    printf("\n\n Desculpe, mas esse jogo nunca foi sorteado!");

  getch();
}









