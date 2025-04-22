#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
//#include <time.h>
#define TRUE 1

/*int random(int rate)
{
	srand(time(NULL));
    int random = 0;
    
	random = rand() % 9 + 1;
    if (random > rate)
    {
        printf("%d+ SUCCESS\n", rate);
		return 1;
	}
    else
    {
        printf("%d+ FAIL\n", rate);
        return -1;
	}
} 
*/

int main(void)

{
	FILE *fp = NULL;
	fp = fopen("TEST.txt", "a+");
	if(fp == NULL)
	{
		printf("파일 안열림");
		return -1;
	}
	
	
	char ID[100];
	char PW[100];
	int UID;
	char NAME[100];
	int rate = 0;
	int coin = 0;
	
	
	char buffer[100];
	int num, num2, i, command, CON;
	
	
	while(TRUE)
	{
		FILE *fp = NULL;
		fp = fopen("TEST.txt", "a+");
		if(fp == NULL)
		{
		printf("파일 안열림");
		return -1;
		}
		
		
		printf("LOGIN(1) / SIGN UP(2) / END(3)\n");
		scanf("%d", &command);
		
		
		if(command == 1)
		{
			printf("ID : ");
			scanf("%s", &ID);
			while(!feof(fp))
			{
				num++;
				
				fgets(buffer, 100, fp);
				if(strstr(buffer, ID) != NULL)
				{
					fgets(buffer, 100, fp);
					
					printf("PW : ");
					scanf("%s", &PW);
					
					if(strstr(buffer, PW) != NULL)
					{
						fgets(buffer, 100, fp);
						printf("%s\n", buffer);
						break;
					}
					else
					{
						printf("FALSE\n");
						break;
					}
				}
				else if(feof(fp) && strstr(buffer, ID) == NULL)
				{
					printf("NO ID\n");
				}
			}	
		}
		else if(command == 2)
		{
			printf("ID : ");
			scanf("%s", ID);
			for(i = 1; EOF; i = i * 2)
			{
				fgets(buffer, 100, fp);
				if(strstr(buffer, ID) != NULL)
				{
					printf("ONN");
				}
			}
			printf("PW : ");
			scanf("%s", PW);
			printf("NAME : ");
			scanf("%s", NAME);
		
			fputs("ID : ", fp);
			fputs(ID, fp);
			fputs("\n", fp);
			fputs("PW : ", fp);
			fputs(PW, fp);
			fputs("\n", fp);
			fputs("NAME : ", fp);
			fputs(NAME, fp);
			fputs("\n", fp);
			fputs("--------------------\n", fp);
			fclose(fp);
		} 
		else if(command == 3)
		{
			printf("END");
			break;
		}
		else
		{
			printf("RE\n");
		}
	
	}
	fclose(fp);
	return 0;
}
