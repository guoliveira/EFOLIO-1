#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int verificar_posicao (char casa[])
  {
    if(strlen(casa)>2)
        return 0 ; 
    else
      {
      // Avaliar se a primeira char fica entre a e f
      if (casa[0]<'a'||casa[0]>'f')
        return 0 ;  
      else
        {
        // Avaliar se a segunda char fica entre 1 e 5
         if (casa[1]<'1'||casa[1]>'5')
          {
          return 0; 
          }
         else
          return 1; 
        }
      }
  }
  
char* criar_tabuleiro()
{
   static char posicoes[50];
   int i;
   for (i=0;i<36;i++)
                posicoes[i]='.';
    
    return posicoes;

}

void inserir_peca(char casas[],char tabuleiro[])
{
    int i;  
    char *numero[50]={"0","1","2","3","4","5"};
    char *letra[50]={"a","b","c","d","e","f"};
    char *pecas[14]={"R","r","P","P","P","P","P","P","p","p","p","p","p"};
    int c;
    char *localizacao[50];
    char delim[] = " ";


    char *ptr = strtok(casas, " ");
    c=0;
    while (ptr != NULL)
	  {
      localizacao[c]=ptr;
      c++;
      ptr = strtok(NULL, " ");
      
    }

    for (c=0;c<2;c++)
    for (i=0;i<36;i++)
            if ((localizacao[c][0]==*letra[i%6])&&(localizacao[c][1]==*numero[5-i/6]))
                {
                tabuleiro[i]=*pecas[c];
                }
      
              
}

char* imprimir_tabuleiro(char tabuleiro[])
{          
    int i,j,l;

    l=0;
    for (i=5;i>0;i--)
      {   
        for (j=6;j>0;j--)
          {
            if (l%6==0)
              printf("%d:",5-l/6); 
            printf("%c",tabuleiro[l]);
          l++;
          }
        printf("\n");
      }
    printf("  abcdef");
       return 0;
}


int main(void) {
    char casas[80];
    char *resultado[3]={"Casa invalida.","Casa valida.\n"};
    int c;
    char *tabuleiro;

    gets(casas);
    //scanf("%s", casa);


    //criar tabuleiro
    tabuleiro=criar_tabuleiro();
    inserir_peca(casas,tabuleiro);
  
    //imprimir o tabuleiro
    imprimir_tabuleiro(tabuleiro);

    
  

    return 0;
}
   
