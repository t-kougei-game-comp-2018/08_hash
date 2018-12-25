#include <stdio.h>
#include <string.h>

#define HASH_SIZE 10
#define DATA_SIZE 258

void trim(char* str)
{
	char *p;
	p = strchr(str, '\n');
	if (p != NULL) {
		*p = '\0';
	}
}


int isOpen(char hashTable[][DATA_SIZE], int hashNum)
{
	if (hashTable[hashNum][0] == '\0')
	{
		return 1;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	//èâä˙âª
	char str[DATA_SIZE];
	char hashTable[HASH_SIZE][DATA_SIZE];
	for (int i = 0; i < HASH_SIZE; hashTable[i][0] = '\0', i++);

	while (fgets(str, sizeof(str), stdin))
	{
		trim(str);


		//àÍóóï\é¶
		if (str[0] == '\0')
		{
			for (int i = 0; i < HASH_SIZE; i++)
			{
				if (i != 0)
				{
					printf(",");
				}

				for (char *p = hashTable[i]; *p != '\0'; *p++) printf("%c", *p);
			}
			printf("\n");
		}

		//HASH TABLEÇ÷ÇÃí«â¡
		else
		{

			int hashNum = 0;
			char *p = str;
			for (; *p != '\0'; hashNum += (int)*p++);
			hashNum %= 10;


			for (int i = 0; i < HASH_SIZE; i++)
			{
				if (isOpen(hashTable, hashNum))
				{
					strcpy(hashTable[hashNum], str);
					break;
				}
				else
				{
					hashNum = (hashNum + 1) % 10;
				}
			}
		}

	}
	return 0;
}
