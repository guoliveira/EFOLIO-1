#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int test(void) {
    char casa[80];
    char *resultado[3]={"Casa invalida","Casa valida"};

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
          printf("%s",resultado[1]) ; 
        }
      }


    return 0;
}