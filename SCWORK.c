#include <stdio.h>
#include <string.h>


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
	
	
	char buffer[100];
	int num, num2, i, command, CON;
	
	
	while(CON)
	{
		printf("1 / 2 / 3\n");
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
						printf("TRUE");
					}
					else
					{
						printf("FALSE");
					}
				}
				else if(feof(fp) && strstr(buffer, ID) == NULL)
				{
					printf("NOOOO\n");
				}
			}	
		}
		else if(command == 2)
		{
			printf("ID : ");
			scanf("%s", ID);
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
			fputs("--------------------\n", fp);
		} 
		else if(command == 3)
		{
			printf("END");
			CON = 0;
		}
		else
		{
			printf("RE\n");
		}
	
	}
	fclose(fp);
	return 0;
}

