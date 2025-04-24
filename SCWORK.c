#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
//#include <time.h>
#define TRUE 1
#define ONFILE "TEST.txt"

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

int check(char ID[100])
{

	
	FILE *fp = NULL;
	fp = fopen(ONFILE, "r");
	if(fp == NULL)
	{
	printf("파일 안열림");
	return -1;
	}
	
	
	char buffer[100];
	int i = 0;
	
	while(EOF)
	{
		i++;
		fgets(buffer, 100, fp);
		if(i % 4 == 2 || i == 2)
		{
			
			if(strstr(buffer, ID) != NULL)
			{
				
				return 1;  // 이미 존재함  
			}
			else
			{
				
				return 0; // 존재하지 않음  
			}
		}
	}
}


void signup(char ID[100], char PW[100], char NAME[100])
{
	FILE *fp = NULL;
	fp = fopen(ONFILE, "a");
	if(fp == NULL)
	{
		printf("파일 안열림");
		return -1;
	}
	
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


int login(char buffer[100], char ID[100], char PW[100] )
{
	FILE *fp = NULL;
	fp = fopen(ONFILE, "r");
	if(fp == NULL)
	{
		printf("파일 안열림");
		return -1;
	}	
		
	while(!feof(fp))
	{
		
				
		fgets(buffer, 100, fp);
		if(strstr(buffer, ID) != NULL)
		{
			fgets(buffer, 100, fp);
			
			if(strstr(buffer, PW) != NULL)
			{
				fgets(buffer, 100, fp);
				printf("%s\n", buffer);
				fclose(fp);
				return 1;
			}
			else
			{
				printf("WRONG PASSWORD\n");
				fclose(fp);
				return 2;
			}
		}
		else if(feof(fp) && strstr(buffer, ID) == NULL)
		{
			printf("NO ID\n");
			fclose(fp);
			return 3;
		}
	}		
}

int main(void)

{
	
	
	
	char ID[100];
	char PW[100];
//	int UID;
	char NAME[100];
//	int rate = 0;
//	int coin = 0;
	int command;
	
	char buffer[100];
//	int num, num2;
	
	
	while(TRUE)
	{
		
		printf("END(0) / LOGIN(1) / SIGN UP(2) \n");
		scanf("%d", &command);
		
		if(command == 0)
		{
			printf("END");
			break;
		}
		
		else if(command == 1)
		{
			printf("ID : ");
			scanf("%s", &ID);
			printf("PW : ");
			scanf("%s", &PW);
			
			login(buffer, ID, PW);
			
		}
		else if(command == 2)
		{
			printf("ID : ");
			scanf("%s", ID);
			
			if(check(ID) == 1)
			{
				printf("EXIST\n");
				
			}
			else if(check(ID) == 0)
			{
				printf("PW : ");
				scanf("%s", PW);
				printf("NAME : ");
				scanf("%s", NAME);
				signup(ID, PW, NAME);
			}
			else
			{
				printf("ERROR\n");
			}
			
		
			
		} 
		
		else
		{
			printf("RE\n");
		}
	
	}
	return 0;
}
