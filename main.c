#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>

int main()
{
  setlocale(LC_ALL, "Portuguese");
  const int INTER = 0, GREMIO = 1, CHAPE = 2, OUTROS = 3, SEMTIME = 4;

  int aTimes[5] = {0, 0, 0, 0, 0};
  int iTimeEscolhido, iPodeContinuar, iSomaTorcedores = 0, iContador, iSomaIdade = 0, iIdade = 0, iIdadeMenor = 100, iIdadeMaior = -100;
  float fPercentualPessoasSemTime, fMediaIdade;
  char cContinuar;

  do{
    system("cls");
    printf("\nInforme o time que você torce: 1 - Internacional, 2 - Grêmio, 3 - Chapecoense, 4 - Outros times, 5 - Sem time definido.\n");
    scanf("%i", &iTimeEscolhido);
    iPodeContinuar = 1;
    switch (iTimeEscolhido)
    {
      case 1:{
        aTimes[INTER]++;
        break;
      }

      case 2:{
        aTimes[GREMIO]++;
        break;
      }

      case 3:{
        aTimes[CHAPE]++;
        break;
      }

      case 4:{
        aTimes[OUTROS]++;
        break;
      }

      case 5:{
        aTimes[SEMTIME]++;
        break;
      }

      default:{
        printf("\nEscolha inválida!");
        iPodeContinuar = 0;
        break;
      }
    }

    if (iPodeContinuar) {
      printf("\nInforme sua idade:");
      scanf("%i", &iIdade);
      if (iTimeEscolhido == 1 || iTimeEscolhido == 2 || iTimeEscolhido == 3)
        iSomaIdade += iIdade;
      if (iIdade < iIdadeMenor)
        iIdadeMenor = iIdade;
      if (iIdade > iIdadeMaior)
        iIdadeMaior = iIdade;
    }

   printf("\nDeseja continuar (S/N)?");
   fflush(stdin);
   cContinuar = getchar();
  } while(toupper(cContinuar) == 'S');

  for (iContador = 0; iContador <= sizeof(aTimes)/sizeof(aTimes[0]) - 1; iContador++){
    iSomaTorcedores += aTimes[iContador];
  }
  fPercentualPessoasSemTime = (float)aTimes[SEMTIME] * 100 / iSomaTorcedores;
  fMediaIdade = iSomaIdade / (aTimes[INTER] +  aTimes[GREMIO] + aTimes[CHAPE]);

  system("cls");
  printf("\nQuantidade de torcedores: Internacional = %i, Grêmio = %i, Chapecoense = %i, Outros times = %i e Sem time definido = %i", aTimes[INTER], aTimes[GREMIO], aTimes[CHAPE], aTimes[OUTROS], aTimes[SEMTIME]);
  printf("\nPercentual de pessoas entrevistadas que não torcem para nenhum time: %.2f%%", fPercentualPessoasSemTime);
  printf("\nMedia de idade dos torcedores do 3 time principais: %.2f", fMediaIdade);
  printf("\nIdade do torcedor mais novo: %i, idade do torcedor mais velho: %i", iIdadeMaior, iIdadeMenor);

  return 0;
}
