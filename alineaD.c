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
        return 0; 
    // Avaliar se a primeira char fica entre a e f
    else if (casa[0]<'a'||casa[0]>'f')
        return 0;  
    // Avaliar se a segunda char fica entre 1 e 5
    else if (casa[1]<'1'||casa[1]>'5')
        return 0; 
    else
        return 1; 
}


//Função que recebe um string com espacos, separa-o e devolve um vector string
char** separar_casas(char casas[])
{
    static char *localizacao[100];
    char *casa_sem_espacos = strtok(casas, " ");
    int c;

    c=0;
    while (casa_sem_espacos != NULL)
        {
        localizacao[c]=casa_sem_espacos;
        c++;
        casa_sem_espacos = strtok(NULL, " ");
        }
    return localizacao;

}   

char* criar_tabuleiro()
{
    static char posicoes[50];
    int i;
    for (i=0;i<36;i++)
      posicoes[i]='.';
    
    return posicoes;
}

int converte_localizacao_em_numero(char casa[])
{
    int i;
    char *numero[50]={"0","1","2","3","4","5"};
    char *letra[50]={"a","b","c","d","e","f"};
  
    if (verificar_posicao(casa)==1)
      for (i=0;i<36;i++)
        if((casa[0]==*letra[i%6])&&(casa[1]==*numero[5-i/6]))
          return i;
  
    return -1;
}


void inserir_pecas(char casas[],char tabuleiro[])
{
    int i,c;  
    char *pecas[15]={"R","r","P","P","P","P","P","P","p","p","p","p","p","p"};
    char **localizacao=separar_casas(casas);


    for (c=0;c<14;c++)
      for (i=0;i<36;i++)
            if (converte_localizacao_em_numero(localizacao[c])==i)
                {
                tabuleiro[i]=*pecas[c];
                }       
}

int validar_movimento_peca(char *origem, char *destino, char tabuleiro[])
{
  int de_int=converte_localizacao_em_numero(origem);
  int para_int=converte_localizacao_em_numero(destino);

  if (verificar_posicao(origem)==0||verificar_posicao(destino)==0)
    return 0;
  else if (tabuleiro[de_int]=='.')
    return 0;
  else if (tabuleiro[de_int]=='p')
      {
      if (tabuleiro[para_int]=='R')
        return -1;
      else if (tabuleiro[para_int]=='P'&&( para_int-de_int==7||para_int-de_int==5))
        return 1;
      else if (tabuleiro[de_int]=='.'&&para_int-de_int==6)
        return 1;
      else
        return 0;
      }
  else if (tabuleiro[de_int]=='P')
      {
      if (tabuleiro[para_int]=='r')
        return -1;
      else if (tabuleiro[para_int]=='p'&&( de_int-para_int==7||de_int-para_int==5))
        return 1;
      else if (tabuleiro[para_int]=='.'&&de_int-para_int==6)
        return 1;
      else
        return 0;
      }
  else if (tabuleiro[de_int]=='r')
    {
    if (tabuleiro[para_int]=='R'&&(de_int-para_int==1||para_int-de_int==1||de_int-para_int==6||para_int-de_int==6||de_int-para_int==7||para_int-de_int==7||de_int-para_int==5||para_int-de_int==5))
      return -1;
    else if (tabuleiro[para_int]=='p')
      return 0;
    else if (de_int-para_int==1||para_int-de_int==1||de_int-para_int==6||para_int-de_int==6||de_int-para_int==7||para_int-de_int==7||de_int-para_int==5||para_int-de_int==5)
      return 1;
    else
      return 0;
    }
  else if (tabuleiro[de_int]=='R')
    {
    if (tabuleiro[para_int]=='r'&&(de_int-para_int==1||para_int-de_int==1||de_int-para_int==6||para_int-de_int==6||de_int-para_int==7||para_int-de_int==7||de_int-para_int==5||para_int-de_int==5))
      return -1;
    else if (tabuleiro[para_int]=='P')
      return 0;
    else if (de_int-para_int==1||para_int-de_int==1||de_int-para_int==6||para_int-de_int==6||de_int-para_int==7||para_int-de_int==7||de_int-para_int==5||para_int-de_int==5)
      return 1;
    else
      return 0;
    }
  else 
     return 1;

}

void regras_JA(char tabuleiro[])
{
  int rei[2];
  int peao[8][2];
  int i,j=0,k=0;

    // As casas pretas estão no [0] e o branco no [1]

  for (i=0;i<36;i++)
    if (tabuleiro[i]=='r')
      rei[0]=i;
    else if (tabuleiro[i]=='R')
      rei[1]=i;
    else if (tabuleiro[i]=='p')
      {
      peao[j][0]=i;
      j++;
      }
    else if (tabuleiro[i]=='P')
      {
      peao[k][1]=i;
      k++;
      }
    else 
      tabuleiro[i]='.';

    for (j=0;j<6;j++)
      for (k=0;k<6;k++)
        {
        if (peao[k][1]-peao[j][0]==6)
          {
          if (tabuleiro[peao[j][0]-1]=='p')
            {
            tabuleiro[peao[j][0]-1]='.';
            tabuleiro[peao[k][1]]='p';
            printf("");
            }
           else {
            tabuleiro[peao[j][0]+1]='.';
            tabuleiro[peao[k][1]]='p';
            printf("");
           }
          }
        }

    for (j=0;j<6;j++)
        if (rei[1]-peao[j][0]==6)
        {
            tabuleiro[peao[j][0]]='.';
            tabuleiro[peao[j][0]+5]='p';
        }

}


int mover_pecas(char casas[], char tabuleiro[])
{
  int i;
  static int jogadas;
  char peca;
  char *origem,*destino;

  
  
  
  for (i=14;separar_casas(casas)[i]!=0;i++)
    {
    if (separar_casas(casas)[i+1]!=0)
    {
    if (separar_casas(casas)[i][0]=='J')
      {
      regras_JA(tabuleiro);
      jogadas++;
      }

    else if (validar_movimento_peca(separar_casas(casas)[i],separar_casas(casas)[i+1],tabuleiro)==0)
     break;
    else     
    {
    origem=separar_casas(casas)[i];
    destino=(separar_casas(casas)[i+1]);

    peca=tabuleiro[converte_localizacao_em_numero(origem)];
    tabuleiro[converte_localizacao_em_numero(origem)]='.';
    tabuleiro[converte_localizacao_em_numero(destino)]=peca;
    i++;
    jogadas++;
    if (validar_movimento_peca(origem,destino,tabuleiro)==-1)
        break;
    }
    }
    else
      break;
    }

return jogadas;

}


char* imprimir_output(char tabuleiro[])
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
    char casas[200];
    char *tabuleiro;
    int j;
    int jogadas;
    char *vencedor;

    gets(casas);

    //criar tabuleiro
    tabuleiro=criar_tabuleiro();

    // Verificar a posição inicial dos dois reis
    if (verificar_posicao(separar_casas(casas)[0])==0||(verificar_posicao(separar_casas(casas)[1])==0))
      printf("Posicao Invalida.");
    else
    {
      inserir_pecas(casas,tabuleiro);
      jogadas=mover_pecas(casas,tabuleiro);
      imprimir_output(tabuleiro);
      if (jogadas%2==0) {
      vencedor="pretas";
      }
      else {
      vencedor="brancas";
      }
      printf("\nGanham as %s. Partida com %d jogadas validas.",vencedor,jogadas);
      
    }

    return 0;
}
   