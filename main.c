#include <stdio.h>
#include <string.h>

#define HASH_SIZE 10
#define DATA_SIZE 258




/*
	input3.txtの1行目は256文字？?
	

	条件
	ハッシュテーブルのサイズは10とします。それ以上に追加しようとしても何も処理されないものとします。
	各文字列の文字数は255文字を超えません。

*/



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
	//初期化
	char str[DATA_SIZE];
	char hashTable[HASH_SIZE][DATA_SIZE];
	for (int i = 0; i < HASH_SIZE; hashTable[i][0] = '\0', i++);

	while (fgets(str, sizeof(str), stdin))
	{
		trim(str);


		//一覧表示
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

		//HASH TABLEへの追加
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
					strcpy_s(hashTable[hashNum], sizeof(char) * DATA_SIZE, str);
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
