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
		printf("them tu vao? co dien 1, khong thi dien 0\n");
		printf("danh tu la so 1, dong tu la so 2, tinh tu la so 3, trang tu la so 4, gioi tu la so 5\nvd 1\nsun\n1\nmat troi\n");
		scanf("%d",&c);
		if(c==1){
			char t1[256],t3[256];
			int t2;
			fgets(t1,255,stdin);
			scanf("%d",&t2);
			getchar();
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
