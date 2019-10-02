#include <stdio.h>
int m, n;

/*
[ 5 0 2 3 ]
[ 1 3 4 2 ]
[ 7 6 9 0 ]
*/

int main(){
    //variabbili iterazione 
    int i, j, l, f, g;
    //variabili controllo
    float tmp, mult;
    
    
    //assegnazione grandezza matrice
    printf("inserire la grandezza della matrice quadrata\n");
    scanf("%d", &m);
    n=m+1;
    //creazione matrice
    float mat[m][n];
    //ciclo assegnazione 
    for(i=0; i<m; i++)
	{
        for(j=0; j<n; j++)
		{
            printf("inserire il coef. della colonna %d e riga %d\n", j+1, i+1);
            scanf("%f", &mat[i][j]);
        }
    }
	
	/*stampa matrice
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }*/
	
    //risoluzione
    for(j=0; j<n; j++)
	{
        //cerco estremo (non possono esserci tutti 0)
		i=j;
		while(mat[i][j]==0)
		{
			i++;
		}
		//scambio riga j con i
		for(l=0; l<n; l++)
		{
			tmp=mat[j][l];
			mat[j][l]=mat[i][l];
			mat[i][l]=tmp;
		}
		//sottraggo riga j da tutte le altre
		//cerca se riga sotto i diversa da j
		for(i=j+1; i<m; i++)
		{
			if(mat[i][j]!=0)
			{
				mult=mat[i][j]/mat[j][j];
				for(l=j; l<n; l++)
				{
					mat[i][l]-=mat[j][l]*mult;
				}
			}
		}
    }
    
	//togli indici
	for(i=m-1; i>0; i--)
	{
		for(j=1; j<=i; j++)
		{
			mult=mat[i-j][i]/mat[i][i];
			mat[i-j][i]-=mat[i][i]*mult;
			mat[i-j][n-1]-=mat[i][n]*mult;	
		}
	}
    
    //divisione finale
    for(i=0; i<m; i++)
    {
    	if(mat[i][i]!=1)
    	{
    		mat[i][n-1]=mat[i][n-1]/mat[i][i];
    		mat[i][i]=1;
		}
	}
	
	//stampa matrice
    for(i=0; i<m; i++)
	{
        for(j=0; j<n; j++)
		{
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }
}
