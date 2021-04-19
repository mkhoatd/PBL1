#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dictionary.h"
int main()
{
	FILE* f = fopen("./dictionary.txt", "a+");
	tu* a[10000] = { NULL };
	addata(a);
	int c=0;
	do {
		printf("them tu vao?");
		scanf("%d",&c);
		getchar();
		if(c==1){
			char t1[256],t3[256];
			int t2;
			fgets(t1,255,stdin);
			scanf("%d\n",&t2);
			fgets(t3,255,stdin);
			a[hash(t1)]=themtu(t1,t2,t3,a[hash(t1)]);
		}
	}
	while(c==1);
	int count=0;
	for(int i=0;i<10000;i++){
		if(a[i]) test(a[i],&count);
	}
	for (int i = 0; i < 10000; i++) {
		if(a[i]) freetable(a[i]);
	}
	return 0;
}
