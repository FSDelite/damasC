//JOGO DE DAMAS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	int tab[10][10], i, j, aux=0, a,b,c,p,auxI,auxJ,pretas=1, brancas=1; //Tabuleiro 10X10, auxiliares

   // CRIAÇÃO E IMPRESSÃO DO TABULEIRO
   // UTILIZA UMA VARIÁVEL AUXILIAR PARA QUE AS PEÇAS SEJAM DISPOSTAS DE MANEIRA SIM/NAO/SIM
   // PARA ISSO É UTILIZADO SISTEMA DE PAR OU ÍMPAR
	for(j=0;j<4;j++)
	{
		if(j%2==0)
		{
			aux=1;
		}
		else
		{
			aux=0;
		}
		for(i=0;i<10;i++,aux++)
		{
			if(aux % 2 == 0)
			{
				tab[i][j] = 1;
			}
			else
			{
				tab[i][j] = 0;
			}}}
	for(j=4;j<6;j++)
	{
		for(i=0;i<10;i++)
		{
			tab[i][j]=0;
		}}

	for(j=6;j<10;j++)
	{
		if(j%2==0)
		{
			aux=1;
		}
		else
		{
			aux=0;
		}
		for(i=0;i<10;i++, aux++)
		{
			if(aux % 2 == 0)
			{
				tab[i][j] = 2;
			}
			else
			{
				tab[i][j] = 0;
			}}}
	//IMPRESSÃO DO TABULEIRO:
    printf("    0  1  2  3  4  5  6  7  8  9");
    printf("\n  _________________________________\n");
	for(j=0;j<10;j++)
	{
        printf("%d |", j);
		for(i=0;i<10;i++)
		{
			printf(" %d ", tab[i][j]);
			if(i == 9)
			{
                 	printf("  |%d \n", j);
             }
		}
		printf("  |                                |\n");
	}
	printf("  |________________________________|\n");
    printf("    0  1  2  3  4  5  6  7  8  9");

	//MOVIMENTO DAS PEÇAS:
    //A CONDIÇÃO PARA O MOVIMENTO DAS PEÇAS É DE QUE A LINHA E COLUNA DEVEM VARIAR APENAS UMA POSIÇÃO E NAO DEVE TER NENHUMA PEÇA NO LUGAR.
    //É USADO UM LAÇO EM LOOP INFINITO ATÉ QUE O JOGADOR FAÇA O MOVIMENTO. O TABULEIRO É LIMPO A CADA MOVIMENTO VÁLIDO.
    //POR HORA É UTILIZADO UM LAÇO POR FORA PARA QUE OS MOVIMENTOS SE REPITAM INDEFINIDAMENTE.
    //A PRIMEIRA VERIFICAÇÃO NO LAÇO 2 É UTILIZADA PARA CASOS DE CAPTURA, ASSIM ELE VERIFICA SE HÁ PEÇAS EM QUALQUER DIREÇÃO E REALIZA O PULO, TAMBEM SERVE PARA CAPTURAR PARA TRÁS!!!

	while(pretas!=0 && brancas != 0)
	{

	while(1)
	{
		printf("\n\nJogador 1 \n");
		scanf("%d %d", &j, &i);
		scanf("%d %d", &b, &a);


		//DAMA MOVIMENTO:
		if(        (((tab[i][j]==3)  && (((a+b)==(i+j)) || (abs(a-b)==(abs(i-j))))) && (tab[a][b]==0))        )
		{
                   auxI=i;
                   auxJ=j;
                   c=0;
                   p=0;
			if( a>i )
			{
				for(i,j;i<10, j>0;i++,j--)
				{
					if(tab[i][j]%2!=0)
					{
                        c++;
    					break;
					}
					if(      (tab[i][j]==0 ||   (((tab[i][j]==2) || (tab[i][j]==4)) && (tab[i+1][j-1]==0)))              )
					{
						continue;
					}
					else
					{
                        p++;
                    }
				}
				if(c==0 && p==0)
				{
                        for(auxI,auxJ;auxI<10, auxJ>0;i++,j--)
                        {
                                               tab[auxI][auxJ]=0;
                        }
                        tab[a][b]=3;
                }
			}
			if( a<i )
			{
				for(i,j;i>0, j<10;i--,j++)
				{
					if(tab[i][j]%2!=0)
					{
                        c++;
    					break;
					}
					if(  (tab[i][j]==0 ||   (((tab[i][j]==2) || (tab[i][j]==4)) && (tab[i-1][j+1]==0)))             )
					{
						continue;
					}
					else
					{
                        p++;
                    }
				}
				if(c==0 && p==0)
				{
                        for(auxI,auxJ;auxI>0, auxJ<10;i--,j++)
                        {
                                               tab[auxI][auxJ]=0;
                        }
                        tab[a][b]=3;
                }
			}



		}



		//CAPTURA
		if( (((((a == i+2) || (a == i-2)) && (( a >= 0 ) && (a < 10))) &&  (((b == j+2) || (b == j-2)) && (( b >= 0 ) && (b < 10))))  && tab[i][j] == 1) && tab[a][b] ==0 )
		{
		    if((tab[i-1][j-1] == 2) || (tab[i-1][j-1] == 4))
            {
            	tab[i-1][j-1] =0;
            }
            if((tab[i+1][j-1] == 2) || (tab[i+1][j-1] == 4))
            {
                 tab[i+1][j-1] = 0;
            }
            if((tab[i+1][j+1] == 2) || (tab[i+1][j+1] == 4))
            {
                 tab[i+1][j+1] = 0;
            }
            if((tab[i-1][j+1] == 2) || (tab[i-1][j+1] == 4))
            {
                 tab[i-1][j+1] = 0;
            }

            tab[i][j] = 0;
            tab[a][b] = 1;

            break;
      }
      //MOVIMENTO
		if( ((((((a == i+1) || (a == i-1)) && (( a >= 0 ) && (a < 10))) &&  (((b == j+1) || (b == j-1)) && (( b >= 0 ) && (b < 10)))) && tab[a][b]==0) && tab[i][j] == 1) )
		{
		    tab[i][j] = 0;
            tab[a][b] = 1;
            break;
      }
      else
      {
          printf("movimento invalido");
          continue;
      }
      }
        system("CLS");

        //VERIFICA SE VIROU DAMA:
        for(i=0;i<10;i++)
        {
			if(tab[i][9]==1)
			{
				tab[i][0]=3;
			}
		}


		//IMPRESSÃO DO TABULEIRO:
    printf("    0  1  2  3  4  5  6  7  8  9");
    printf("\n  _________________________________\n");
	for(j=0;j<10;j++)
	{
        printf("%d |", j);
		for(i=0;i<10;i++)
		{
			printf(" %d ", tab[i][j]);
			if(i == 9)
			{
                 	printf("  |%d \n", j);
             }
		}
		printf("  |                                |\n");
	}
	printf("  |________________________________|\n");
    printf("    0  1  2  3  4  5  6  7  8  9");



		while(1)
	{
		printf("\n\nJogador 2 \n");
		scanf("%d %d", &j, &i);

		scanf("%d %d", &b, &a);

		//DAMA MOVIMENTO:
		if(        (((tab[i][j]==4)  && (((a+b)==(i+j)) || (abs(a-b)==(abs(i-j))))) && (tab[a][b]==0))        )
		{
                   auxI=i;
                   auxJ=j;
                   c=0;
                   p=0;
			if( a>i )
			{
				for(i,j;i<10, j>0;i++,j--)
				{
					if(tab[i][j]==2 || tab[i][j] == 4)
					{
                        c++;
    					break;
					}
					if(      (tab[i][j]==0 ||   (((tab[i][j]==1) || (tab[i][j]==3)) && (tab[i+1][j-1]==0)))              )
					{
						continue;
					}
					else
					{
                        p++;
                    }
				}
				if(c==0 && p==0)
				{
                        for(auxI,auxJ;auxI<10, auxJ>0;i++,j--)
                        {
                                               tab[auxI][auxJ]=0;
                        }
                        tab[a][b]=4;
                }
			}
			if( a<i )
			{
				for(i,j;i>0, j<10;i--,j++)
				{
					if(tab[i][j]==2 || tab[i][j] == 4)
					{
                        c++;
    					break;
					}
					if(  (tab[i][j]==0 ||   (((tab[i][j]==1) || (tab[i][j]==3)) && (tab[i-1][j+1]==0)))             )
					{
						continue;
					}
					else
					{
                        p++;
                    }
				}
				if(c==0 && p==0)
				{
                        for(auxI,auxJ;auxI>0, auxJ<10;i--,j++)
                        {
                                               tab[auxI][auxJ]=0;
                        }
                        tab[a][b]=4;
                }
			}



		}

		//CAPTURA:
		if( ((((((a == i+2) || (a == i-2)) && (( a >= 0 ) && (a < 10))) &&  (((b == j+2) || (b == j-2)) && (( b >= 0 ) && (b < 10))))) && tab[i][j] == 2) && tab[a][b] ==0 )
		{

 			if((tab[i-1][j-1] == 1) || (tab[i-1][j-1] == 3))
            {
            	tab[i-1][j-1] =0;
            }
            if((tab[i+1][j-1] == 1) || (tab[i+1][j-1] == 3))
            {
                 tab[i+1][j-1] = 0;
            }
            if((tab[i+1][j+1] == 1) || (tab[i+1][j+1] == 3))
            {
                 tab[i+1][j+1] = 0;
            }
            if( (tab[i-1][j+1] == 1) || (tab[i-1][j+1] == 3) )
            {
                 tab[i-1][j+1] = 0;
            }

            tab[i][j] = 0;
            tab[a][b] = 2;
            break;
      }
      //MOVIMENTO:
		else if( ((((((a == i+1) || (a == i-1)) && (( a >= 0 ) && (a < 10))) &&  (((b == j+1) || (b == j-1)) && (( b >= 0 ) && (b < 10)))) && tab[a][b]==0) && tab[i][j] == 2) )
		{
		    tab[i][j] = 0;
            tab[a][b] = 2;
            break;
      }
      else
      {
          printf("movimento invalido");
          continue;
      }
      }
       system("CLS");

       //VERIFICA SE VIROU DAMA
       for(i=0;i<10;i++)
        {
			if(tab[i][0]==2)
			{
				tab[i][9]=4;
			}
		}

	//IMPRESSÃO DO TABULEIRO:
    printf("    0  1  2  3  4  5  6  7  8  9");
    printf("\n  _________________________________\n");
	for(j=0;j<10;j++)
	{
        printf("%d |", j);
		for(i=0;i<10;i++)
		{
			printf(" %d ", tab[i][j]);
			if(i == 9)
			{
                 	printf("  |%d \n", j);
             }
		}
		printf("  |                                |\n");
	}
	printf("  |________________________________|\n");
    printf("    0  1  2  3  4  5  6  7  8  9");

    //VERIFICA SE AINDA EXISTEM PEÇAS DOS JOGADORES:
    		for(pretas=0,brancas=0,j=0;j<10;j++)
		{
			for(i=0;i<10;i++)
			{
				if(tab[i][j]==1 || tab[i][j]==3)
				{
					pretas++;
					continue;
				}
				if(tab[i][j]==2 || tab[i][j]==4)
				{
					brancas++;
				}
			}}
  }


  if(brancas==0)
  {
		printf("JOGADOR 1 VENCEU! PARABENS!!");
  }
  if(pretas==0)
  {
		printf("JOGADOR 2 VENCEU! PARABENS!!");
  }



	getch();
	return 0;
}
