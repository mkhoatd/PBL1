#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "pblmanheader.h"

int main()
{
	int i;
	char yes;
	char word[256], mean[256], type[256];
	FILE *f = fopen("test.txt", "a+");
	tu *a[10000] = {NULL}; // gán null de khong bi loi trong qua trinh nhap xuat
	adddata(a);			   // dua file vao va khoi tao du lieu ban dau cho mang a

	/*	for(i=0;i<=10000;i++) {
		if( a[i]== NULL) continue;
		else printf("%s",a[i]->data); 
	} */

	//for(i=0;i<=10000;i++) printf("%d",a[i]); dòng này se in ra các dia chi duoc luu trong mang a

	// menu
	fclose(f);
	int tc;
MENU:
	system("cls");
	tc = console();
	system("cls");
	switch (tc)
	{
	case 1:
	{
	VIEW:			   // View dictionary
		FILE *f = fopen("test.txt", "a+");
		system("cls"); // xoa man hinh de khi back lai no khong con cai lan truoc
		printf("********  VIEW DICTIONARY  *********");
		printf("\nWORD\tTYPE\tMEAN");
		viewdic(a);
		printf("\n\nPress y to continue!\nPress b to back to menu!\nPress any key to exit! ");
		fflush(stdin);
		getchar();
		yes = getchar();
		fclose(f);
		if (yes == 'y')
			goto VIEW;
		if (yes == 'b')
			goto MENU;
		break;
	}
	case 2:
	{
		//PLAY:                           // Play chac phai lam ham rieng
		printf("chon 2");
		break;
	}
	case 3:
	{
	SEARCH: // Search a word // search xong tra ve cc gì :))?
		FILE *f = fopen("test.txt", "a+");
		system("cls");
		printf("********  SEARCHING  *********");
		printf("\nEnter the word you want to find: ");
		fgets(word, 255, stdin); // word này có bi gi ko neu case 4 van dung
		search(a[hash(word)], word);
		printf("\n\nPress y to continue!\nPress b to back to menu!\nPress any key to exit! ");
		fflush(stdin);
		yes = getchar();
		fclose(f);
		if (yes == 'y')
			goto SEARCH;
		if (yes == 'b')
			goto MENU;
		break;
	}
	case 4:
	{
	ADD: // Add a new word to dictionary
		FILE *f = fopen("test.txt", "a+");
		system("cls");
		printf("********  ADD A NEW WORD  *********");
		printf("\nEnter a word: ");
		getchar();
		fgets(word, 255, stdin);
		if(fastfind(a[hash(word)],word)){
			printf("Tu da co trong tu dien");
		}
		else{
			fflush(stdin);
			printf("\nEnter its type: ");
			fgets(type, 255, stdin);
			fflush(stdin);
			printf("\nEnter its meaning: ");
			fgets(mean, 255, stdin);
			a[hash(word)] = addword(word, type, mean, a[hash(word)]);
			printf("\nSuccess");
		}
		printf("\n\nPress y to continue!\nPress b to back to menu!\nPress any key to exit! ");
		fflush(stdin);
		yes = getchar();
		fclose(f);
		if (yes == 'y')
			goto ADD;
		if (yes == 'b')
			goto MENU;
		break;
	}
	case 5:
	{
	DELETE: // xoa chua lam xong
		FILE *f = fopen("test.txt", "a+");
		system("cls");
		printf("********  DELETE  *********");
		printf("\nEnter the word you want to delete: ");
		fflush(stdin);
		fgets(word,255,stdin);
		printf("word: %s", word);
		if(fastfind(a[hash(word)],word)){
			delete_a(a[hash(word)],word);
			printf("SUCCESS");
		}
		else printf("Tu can xoa khong co trong tu dien");
		printf("\n\nPress y to continue!\nPress b to back to menu!\nPress any key to exit! ");
		fflush(stdin);
		yes = getchar();
		fclose(f);
		if (yes == 'y')
			goto DELETE;
		if (yes == 'b')
			goto MENU;
		break;
	}
	case 6:
	{ // Exit
		break;
	}
	}

	//system("cls");
	printf("\nGOOD BYE AND SEE YOU LATER!");
	// end game :))
	getch();
	fclose(f);
	return 0;
}