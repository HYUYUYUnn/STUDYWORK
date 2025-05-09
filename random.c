#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define TRUE 1

int main(void)
{
    int coin = 0;
	int addcoin, usedcoin, i;
    int con;
    int succ = 0;
    int fail = 0;
    int nsucc = 0;
    int nfail = 0;
    srand(time(NULL));
    int random = 0;
    int rate = 0;
    

    while (TRUE)
    {
    	printf("\n");
        printf("COIN : %d\n", coin);
        printf("\nCOMMAND : ");
        scanf("%d", &con);
        printf("\n");
        if (con == 0)
        {
        	printf("----------------------\n\n");
            printf("RATING : %d+\n", rate);
            printf("TOTAL COUNT : %d\n", succ + fail);
            printf("SUCCESS COUNT : %d\n", succ);
            printf("FAILED COUNT : %d\n", fail);
            printf("USED COIN : %d\n", usedcoin);
            printf("LEFT COIN : %d\n", coin);
            printf("\n----------------------\n");
            return 0;
        }
        
        else if (con == 1)
		{
			printf("INSERT COIN : ");
			scanf("%d", &addcoin);
			coin = coin + addcoin;
		}
		 
        else if (con == 2)
        {
            if (coin >= 500)
            {
                coin -= 500;
                random = rand() % 9 + 1;
                if (random > rate)
                {
                    rate++;
                    printf("----------------------\n\n");
                    printf("SUCCESS\n");
                    printf("%d+ RATE\n", rate);
					printf("\n----------------------\n");
					succ++;

                }
                else
                {
                    rate--;
                    printf("----------------------\n\n");
                    printf("FAIL\n");
                    printf("%d+ RATE\n", rate);
                    printf("\n----------------------\n");
                    fail++;

                }
                usedcoin += 500;

            }
            else
            {
            	printf("----------------------\n\n");
                printf("코인이 %d개 부족하다.\n", 500 - coin);
                printf("\n----------------------\n");
            }
        }
        
        else if(con == 3)
        {
        	if (coin >= 5000)
            {
                coin -= 5000;
                for(i = 0; i < 10; i++)
                {
					
	                random = rand() % 9 + 1;
	                if (random > rate)
	                {
	                    rate++;
	                    
	                    nsucc++;
	
	                }
	                else
	                {
	                    rate--;
	                    
	                    nfail++;
	
	                }
	                usedcoin += 5000;
				}
				printf("----------------------\n\n");
				printf("%d+ SUCCESS\n", nsucc);
				printf("%d+ FAIL\n", nfail);
				printf("%d+ RATE\n", rate);
				printf("\n----------------------\n");
				
				succ = nsucc + succ;
				fail = nfail + fail;
				nsucc = 0;
				nfail = 0;
            }
            else
            {
            	printf("----------------------\n\n");
                printf("코인이 %d개 부족하다.\n", 500 - coin);
                printf("\n----------------------\n");
            }
		}
		else if(con == 4)
		{
			break;
		}
		
        else
        {
            printf("WRONG INPUT\n");
            continue;
        }
    }
}
