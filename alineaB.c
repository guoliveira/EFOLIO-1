#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* imprimir_tabuleiro(char casa[])
{          
    char *numero[50]={"0","1","2","3","4","5"};
    char *letra[50]={"a","b","c","d","e","f"};
    int i,j,l;
  
           l=0;
           for (i=5;i>0;i--)
              {   
                for (j=6;j>0;j--)
                  {
                   if (l%6==0)
                      printf("%d:",5-l/6); 
                   if ((casa[0]==*letra[l%6])&&(casa[1]==*numero[5-l/6]))
                    printf("X");
                   else
                    printf(".");
                  l++;

                  }
                printf("\n");
              }
            printf("  abcdef");
          return 0;
}


int main(void) {
    char casa[50];
    char *resultado[3]={"Casa invalida.","Casa valida.\n"};
    
    scanf("%s", casa);

    // Avaliar o tamanho da string
    if(strlen(casa)>2)
        printf("%s",resultado[0]) ; 
    else
      {
      // Avaliar se a primeira char fica entre a e f
      if (casa[0]<'a'||casa[0]>'f')
        printf("%s",resultado[0]) ;  
      else
        {
        // Avaliar se a segunda char fica entre 1 e 5
         if (casa[1]<'1'||casa[1]>'5')
          {
          printf("%s",resultado[0]) ; 
          }
         else
         { 
           //imprimir o tabuleiro
           imprimir_tabuleiro(casa);
              }
          }
        
      }
      
   



    return 0;
}