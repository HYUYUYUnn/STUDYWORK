#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1

int main(void)
{
    int coin, addcoin, usedcoin;
    int con;
    int succ = 0;
    int fail = 0;
    srand(time(NULL));
    int random = 0;
    int rate = 0;
    printf("COIN : ");
    scanf("%d", &coin);

    while (TRUE)
    {
        printf("LEFT : %d\n", coin);
        printf("COMMAND : ");
        scanf("%d", &con);
        printf("\n");
        if (con == 1)
        {
            if (coin >= 500)
            {
                coin -= 500;
                random = rand() % 9 + 1;
                if (random > rate)
                {
                    rate++;
                    printf("%d+ SUCCESS\n", rate);
                    succ++;

                }
                else
                {
                    rate--;
                    printf("%d+ FAIL\n", rate);
                    fail++;

                }
                usedcoin += 500;

            }
            else
            {
                printf("ADD COIN : ");
                scanf("%d", &addcoin);
                coin = coin + addcoin;
            }
        }
        else if (con == 2)
        {
            printf("RATING : %d+\n", rate);
            printf("TOTAL COUNT : %d\n", succ + fail);
            printf("SUCCESS COUNT : %d\n", succ);
            printf("FAILED COUNT : %d\n", fail);
            printf("USED COIN : %d\n", usedcoin);
            printf("LEFT COIN : %d\n", coin);
            return 0;
        }
        else
        {
            continue;
        }
    }
}
