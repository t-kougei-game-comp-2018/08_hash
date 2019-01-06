#include <stdio.h>
#include <string.h>

void trim(char* str)
{
	char *p;
	p = strchr(str, '\n');
	if (p != NULL) {
		*p = '\0';
	}
}


int isOpen(char hash[][258], int Num)
{
	if (hash[Num][0] == '\0')
	{
		return 1;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	char str[258];
	char hash[10][258];
	for (int i = 0; i < 10; hash[i][0] = '\0', i++);

	while (fgets(str, sizeof(str), stdin))
	{
		trim(str);
        
		if (str[0] == '\0')
		{
			for (int i = 0; i < 10; i++)
			{
				if (i != 0)
				{
					printf(",");
				}

				for (char *p = hash[i]; *p != '\0'; *p++) printf("%c", *p);
			}
			printf("\n");
		}
        
		else
		{

			int Num = 0;
			char *p = str;
			for (; *p != '\0';Num += (int)*p++);
			Num %= 10;
            
			for (int i = 0; i < 10; i++)
			{
				if (isOpen(hash, Num))
				{
					strcpy(hash[Num], str);
					break;
				}
				else
				{
					Num = (Num + 1) % 10;
				}
			}
		}

	}
	return 0;
}
