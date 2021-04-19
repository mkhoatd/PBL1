#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct tu tu;
struct tu {
	char data[256];
	int type;
	char meaning[256];
	int pos;
	struct tu* next;
};
int countline();
void adddata();
int append(tu* temp);
int hash(char* str);
tu* themtu(char temp[256],int tempB_type,char temp_meaning[256], tu* ptr);
tu* themtutufile(char temp_word[256],int temp_type,char temp_meaning[256],int temp_pos, tu* ptr);
void test(tu* ptr,int *count);
void freetable(tu* ptr);
int append(tu* temp) {
	FILE *f=fopen("./dictionary.txt","a");
	char tu[256];
	char str1[256],str2[256];
	int pos=countline()+1;
	fprintf(f,"@w@%s",temp->data);
	fprintf(f,"@t@%d\n",temp->type);
	fprintf(f,"@m@%s",temp->meaning);                                             
	fclose(f);
	return pos;
}
int hash(char* str) {
	unsigned long hash = 5381;
	int c;
	while (c = *str++)
		hash = ((hash << 5) + hash) + c;
	return hash % 10000;
}
tu* themtu(char temp_word[256],int temp_type, char temp_meaning[256], tu* ptr) {
	if (ptr == NULL) {
		ptr = (tu*)malloc(sizeof(tu));
		strcpy(ptr->data, temp_word);
		ptr->type=temp_type;
		strcpy(ptr->meaning, temp_meaning);
		ptr->pos=append(ptr);
		ptr->next = NULL;
		return ptr;
	}
	ptr->next=themtu(temp_word, temp_type, temp_meaning, ptr->next);
	return ptr;
}
tu* themtutufile(char temp_word[256],int temp_type,char temp_meaning[256],int temp_pos, tu* ptr) {
	if (ptr == NULL) {
		ptr = (tu*)malloc(sizeof(tu));
		strcpy(ptr->data, temp_word);
		ptr->type = temp_type;
		strcpy(ptr->meaning, temp_meaning);  
		ptr->pos=temp_pos;  
		ptr->next = NULL;
		return ptr;
	}
	ptr->next = themtutufile(temp_word,temp_type,temp_meaning,temp_pos, ptr->next);
	return ptr;

}
void test(tu* ptr,int *count) {
	if (ptr) {
		printf("%s",ptr->data);
		printf("%d\n",ptr->pos);
		if (ptr->next) {
			test(ptr->next,count);
		}
	}
}
void freetable(tu* ptr) {
	if (ptr->next!=NULL) freetable(ptr->next);
	free(ptr);
}
void addata(tu **a){
	FILE* f = fopen("./dictionary.txt", "a+");
	char t1[256],t2[256],t3[256];
	int i=1;
	while (fgets(t1, 255, f)) {
		strcpy(t1, t1+3);
		fgets(t2, 255, f);
		strcpy(t2, t2 + 3);
		fgets(t3, 255, f);
		strcpy(t3, t3 + 3);
		a[hash(t1)] = themtutufile(t1, atoi(t2), t3,i, a[hash(t1)]);
		i+=3;
	}
}
int countline(){
	FILE* f = fopen("./dictionary.txt", "r");
	char c;
	int i=0;
	    for (c = getc(f); c != EOF; c = getc(f))
        if (c == '\n')
            i++;
	fclose(f);		
	return i;
}