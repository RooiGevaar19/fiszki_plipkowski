#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clrscr()
{
	system("clear");
}

void test10()
{
	int command;
	FILE *zestaw;
	char leer[20];
	clrscr();
	do
	{
		clrscr();
		printf("TEST 10\n");
		printf("Wybierz zestaw: \n");
		printf(" 1 - Czasowniki\n");
		printf(" 2 - Rzeczowniki\n");
		printf(" 3 - Przymiotniki\n");
		printf(" 4 - Spojniki\n");
		printf(" 5 - Przyimki\n");
		printf(" 0 - Powrot do menu\n");
		scanf("%d", &command);
		switch (command)
		{
			case 1 : {
				zestaw = fopen("czasowniki","r");
				break;
			}
			case 2 : {
                                zestaw = fopen("rzeczowniki","r");
                                break;
                        }
			case 3 : {
                                zestaw = fopen("przymiotniki","r");
                                break;
                        }
			case 4 : {
                                zestaw = fopen("spojniki","r");
                                break;
                        }
			case 5 : {
                                zestaw = fopen("przyimki","r");
                                break;
                        }
			case 0 : {
				clrscr();
				printf("BACK TO MENU XD\n");
				break;
			}
			default : printf("FATAL ERROR XD\n"); break;
		}
		if (command != 0)
		{		
			//test xd
			int comang;
			do
			{
				clrscr();				
				printf(" 1 - Polski - Angielski");
				printf("\n 2 - Angielski - Polski\n");
				scanf("%d", &comang);
			}
			while ((comang != 1)&&(comang != 2));
			clrscr();
			int i, j, m, wanted, control, result=0;
			int index; char pol[30]; 
			char ang[30];
			char test[30];
			while (!feof(zestaw))
			{
				fscanf(zestaw, "%d\t%s\t%s\t%d", &index, pol, ang, &control);
				m = index;
			}
			fclose(zestaw);
			/*
			printf("Jest %d wyrazow.", m);
			getchar();
			getchar();
			*/
			
			srand(time(NULL));
			for (i = 1; i <= 10; i++)
			{
				switch (command)
				{
					case 1 : {
						zestaw = fopen("czasowniki","r");
						break;
					}
					case 2 : {
                                                zestaw = fopen("rzeczowniki","r");
                                                break;
                                        }
					case 3 : {
                                		zestaw = fopen("przymiotniki","r");
                               	 		break;
                        		}
					case 4 : {
                                		zestaw = fopen("spojniki","r");
                                		break;
                        		}
					case 5 : {
                               			zestaw = fopen("przyimki","r");
                                		break;
                        		}
					default : printf("FATAL ERROR XD\n"); break;
				}				
				wanted = rand()%(m+1);
				while (!feof(zestaw))
				{
					fscanf(zestaw, "%d\t%s\t%s\t%d", &index, pol, ang, &control);
					if (index == wanted)
					{
						if (comang == 1)
						{
							clrscr();
							printf("Slowko: %s \n", pol);
							printf("Podaj slowko po angielsku: ");
							scanf("%s", test);
							if (strcoll(ang, test) == 0)
							{
								printf("Dobrze !\n");
								result++;
							}
							else
							{
								printf("Zle - poprawnie jest %s. \n", ang);
							}
							getchar();
							getchar();
						}
						else
						{
							clrscr();
							printf("Slowko: %s \n", ang);
							printf("Podaj slowko po polsku: ");
							scanf("%s", test);
							if (strcoll(pol, test) == 0)
							{
								printf("Dobrze !\n");
								result++;
							}
							else
							{
								printf("Zle - poprawnie jest %s. \n", pol);
							}
							getchar();
							getchar();
						}						
						break;
					}
				}
				fclose(zestaw);					
			}
			clrscr();
			printf("Odgadles %d na 10 slowek!", result);
			getchar();
		}
	}
	while (command != 0);
}

int main()
{
	int command;
	do
	{
		clrscr();
		printf("FISZKI !!!!!!!!1\n");
		printf("polski - Angielski & English - Polish\n");
		printf("Wybierz polecenie: \n");
		printf(" 1 - Test 10\n");
		//printf(" 2 - Pokaz baze slowek\n");
		//printf(" 3 - Dodaj slowko do bazy\n");
		//printf(" 4 - Usun slowko do bazy\n");
		printf(" 0 - Wyjdz\n");
		scanf("%d", &command);
		switch (command)
		{
			case 1 : {
				test10();
				break;
			}
			case 0 : {
				clrscr();
				printf("BYE BYE :)\n");
				break;
			}
			default : printf("FATAL ERROR XD\n"); break;
		}
	}
	while (command != 0);
	return 0;
}
