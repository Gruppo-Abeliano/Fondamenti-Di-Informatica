/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// constraints
#define MAXT 1000000


int cmpfunc(const void *a, const void *b);

// input data
int T, i;
int N[MAXT];
int copia[MAXT];

int main() {
  int sommaBin;
  int sommaTre;
  int numeroDaConvertireDue,numeroDaConvertireTre;
  int quantiCeNeSono;
  int max;

//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));
    for(i=0; i<T; i++)
        assert(1 == scanf("%d", &N[i]));

    for(int s=0;s<T;s++)
    {
      copia[s] = N[s];
    }

    qsort(copia,T,sizeof(int),cmpfunc);
    max = copia[0];

    int quandoCambia[max];
    int cambiatore=0;
    quandoCambia[0] = 1;

    for(int k=0;k<T;k++)
    {
      quantiCeNeSono = 0;
      for(int j=1;j<=N[k];j++)
      {
        if(j <= quandoCambia[cambiatore])
        {
          quantiCeNeSono = cambiatore+1;
          ++cambiatore;
        }
        else {
          sommaBin = 0;
          sommaTre = 0;
          numeroDaConvertireDue = j;
          numeroDaConvertireTre = j;
          while(numeroDaConvertireDue!=0 || numeroDaConvertireTre!=0)
          {
            sommaBin += numeroDaConvertireDue%2;
            sommaTre += numeroDaConvertireTre%3;

            numeroDaConvertireDue = numeroDaConvertireDue/2;
            numeroDaConvertireTre = numeroDaConvertireTre/3;
          }
          if(sommaBin==sommaTre) quantiCeNeSono++;
          if(quantiCeNeSono > cambiatore+1) quandoCambia[cambiatore++] = j;
        }
      }
      printf("%d ",quantiCeNeSono);
    }
    printf("\n");
    return 0;
}

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}
