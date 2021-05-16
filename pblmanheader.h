#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct tu tu;
struct tu
{
	char data[256]; // 4 part of a word from dictionary
	char type[256];
	char meaning[256];
	struct tu *next;
};

int hash(char *str)
{
	unsigned long hash = 5381;
	int c;
	while (c = *str++)
		hash = ((hash << 5) + hash) + c;
	return hash % 10000;
}

tu *fromfile(char temp_word[256], char temp_type[256], char temp_meaning[256], tu *ptr)
{
	if (ptr == NULL)
	{
		ptr = (tu *)malloc(sizeof(tu));
		strcpy(ptr->data, temp_word);
		strcpy(ptr->type, temp_type);
		strcpy(ptr->meaning, temp_meaning);
		ptr->next = NULL;
		return ptr;
	}
	ptr->next = fromfile(temp_word, temp_type, temp_meaning, ptr->next);
	return ptr;
}

void adddata(tu **a)
{
	FILE *f = fopen("test.txt", "a+");
	char t1[256], t2[256], t3[256];
	while (fgets(t1, 255, f))
	{
		fgets(t2, 255, f);
		fgets(t3, 255, f);
		a[hash(t1)] = fromfile(t1, t2, t3, a[hash(t1)]);
	}
}

void viewdic(tu **a)
{
	int i, len1, len2, len3;
	char temp1[256];
	char temp2[256];
	char temp3[256];

	for (i = 0; i < 10000; i++)
	{
		if (a[i] == NULL)
			continue;
		else
		{
			strcpy(temp1, a[i]->data);
			strcpy(temp2, a[i]->type);
			strcpy(temp3, a[i]->meaning);
			len1 = strlen(temp1);
			len2 = strlen(temp2);
			len3 = strlen(temp3);
			temp1[len1 - 1] = '\0';
			temp2[len2 - 1] = '\0';
			temp3[len3 - 1] = '\0';
			printf("\n%s\t%s\t%s", temp1, temp2, temp3);
		}
	}
}

void search(tu *a, char word[256])
{
	int len1, len2, len3;
	char temp1[256];
	char temp2[256];
	char temp3[256];
	if (a != NULL)
	{
		if(strcmp(word,a->data)!=0) return search(a->next,word);
		strcpy(temp1, a->data);
		strcpy(temp2, a->type);
		strcpy(temp3, a->meaning);
		len1 = strlen(temp1);
		len2 = strlen(temp2);
		len3 = strlen(temp3);
		temp1[len1 - 1] = '\0';
		temp2[len2 - 1] = '\0';
		temp3[len3 - 1] = '\0';
		printf("\nWORD\tTYPE\tMEAN");
		printf("\n%s\t%s\t%s", temp1, temp2, temp3);
	}
	else
		printf("\nTu ban can tim khong co trong tu dien");
}
void append(tu *temp)
{
	FILE *f = fopen("test.txt", "a");
	char tu[256];
	char str1[256], str2[256];
	fprintf(f, "%s", temp->data);
	fprintf(f, "%s", temp->type);
	fprintf(f, "%s", temp->meaning);
	fclose(f);
}
tu *addword(char temp_word[256], char temp_type[256], char temp_meaning[256], tu *ptr)
{
	if (ptr == NULL)
	{
		ptr = (tu *)malloc(sizeof(tu));
		strcpy(ptr->data, temp_word);
		strcpy(ptr->type, temp_type);
		strcpy(ptr->meaning, temp_meaning);
		append(ptr);
		ptr->next = NULL;
		return ptr;
	}
	ptr->next = addword(temp_word, temp_type, temp_meaning, ptr->next);
	return ptr;
}

int console()
{
	float choose;
	do
	{
		printf("\n============== Word  -  Game ==============\n");
		printf("*   1. View dictionary                    *\n");
		printf("*   2. Play                               *\n");
		printf("*   3. Search a word                      *\n");
		printf("*   4. Add a new word to dictionary       *\n");
		printf("*   5. Delete a word in dictionary        *\n");
		printf("*   6. Exit                               *\n");
		printf("*******************************************\n");
		printf("Choose your option: ");
		fflush(stdin);
		scanf("%f", &choose);
		if (!((choose == (int)choose) && (choose <= 6 && choose >= 1)))
		{
			system("cls");
			printf("\nFailed! Please choose again\n");
		}
		else
			break;
	} while (!((choose == (int)choose) && (choose <= 6 && choose >= 1)));
	return choose;
}