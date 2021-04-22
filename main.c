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
		scanf("%d",&c);
		getchar();
		if(c==1){
			char t1[256],t3[256];
			int t2;
			do{
				printf("nhap tu: ");
				fgets(t1,255,stdin);
			}
			while(!check(t1));
			chuyenthanhchuthuong(t1);
			do{
				printf("nhap so, 1 la danh tu, 2 la dong tu, 3 la tinh tu, 4 la trang tu, 5 la gioi tu, khong nhap so khac\n");
				scanf("%d",&t2);
				getchar();
			}
			while(!(t2>=1&&t2<=5));
			do{
				printf("nhap nghia cua tu");
				fgets(t3,255,stdin);
			}
			while(!check(t3));
			chuyenthanhchuthuong(t3);
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
