#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int s1;
int i=0,j=0;
int count;
char temp[50];

struct Unit {
	char word[50];
	char note[50];
	int wrong;
};
Unit unit[10000],tem,t;

void show() {
	FILE *fp1;
	if((fp1=fopen("d:\\���ʿ�.txt","rb+"))==NULL) {
		printf("ERROR!");
		system("pause");
		exit(0);
	}
	i=1;
	while(!feof(fp1)) {
		fread(&unit[i],sizeof(Unit),1,fp1);
		i++;
	}
	j=i;
	fclose(fp1);
	printf("��ǰ�ʿ��д���%d����\n",j-2);
	printf("\t%-30s%-50s%-30s\n","����","ע��","�������");
	for(i=1; i<j-1; i++) {
		printf("\t%-30s%-50s%-30d\n",unit[i].word,unit[i].note,unit[i].wrong);
	}
}

void add() {
	FILE *fp1;
	if((fp1=fopen("d:\\���ʿ�.txt","rb+"))==NULL) {
		printf("ERROR!");
		system("pause");
		exit(0);
	}
	i=1;
	while(!feof(fp1)) {
		fread(&unit[i],sizeof(Unit),1,fp1);
		i++;
	}
	fclose(fp1);
	j=i;
	printf("�����뵥��\n");
	getchar();
	int add_key=1;
	gets(temp);
	for(i=1; i<=j-2; i++) {
		if(strcmp(temp,unit[i].word)==0) {
			printf("�ʿ������е��� %s\n",unit[i].word);
			add_key=0;
			break;
		}
	}
	if(add_key==1) {
		strcpy(unit[j-1].word,temp);
		printf("�����뺺��ע��\n");
		gets(unit[j-1].note);
		unit[j-1].wrong=0;
		printf("��ӵ��ʳɹ�\n");
		if((fp1=fopen("d:\\���ʿ�.txt","wb+"))==NULL) {
			printf("ERROR!");
			system("pause");
			exit(0);
		}
		for(i=1; i<j; i++)
			fwrite(&unit[i],sizeof(Unit),1,fp1);
		fclose(fp1);
	}
}

void del() {
	FILE *fp1;
	if((fp1=fopen("d:\\���ʿ�.txt","rb+"))==NULL) {
		printf("ERROR!");
		system("pause");
		exit(0);
	}
	i=1;
	while(!feof(fp1)) {
		fread(&unit[i],sizeof(Unit),1,fp1);
		i++;
	}
	j=i;
	fclose(fp1);
	printf("��������Ҫɾ���ĵ��ʣ�\n");
	getchar();
	gets(temp);
	int k;
	int key=0;
	for(i=1; i<j-1; i++) {
		if(strcmp(temp,unit[i].word)==0) {
			key=1;
			for(k=i; k<j-1; k++) {
				if(k==j-2) {
					unit[k]=tem;
					break;
				}
				strcpy(unit[k].word,unit[k+1].word);
				strcpy(unit[k].note,unit[k+1].note);
				unit[k].wrong=unit[k+1].wrong;
			}
			printf("��ɾ������ %s ����ע��\n",temp);
		}
	}
	if(key==0) {
		printf("���޴˴ʣ�\n");
	}
	if(key==1) {
		if((fp1=fopen("d:\\���ʿ�.txt","wb+"))==NULL) {
			printf("ERROR!");
			system("pause");
			exit(0);
		}
		for(i=1; i<j-2; i++)
			fwrite(&unit[i],sizeof(Unit),1,fp1);
		fclose(fp1);
	}
}

void revise() {
	FILE *fp1;
	if((fp1=fopen("d:\\���ʿ�.txt","rb+"))==NULL) {
		printf("ERROR!");
		system("pause");
		exit(0);
	}
	i=1;
	while(!feof(fp1)) {
		fread(&unit[i],sizeof(Unit),1,fp1);
		i++;
	}
	j=i;
	fclose(fp1);
	printf("\t%-30s%-50s%-30s\n","����","ע��","�������");
	for(i=1; i<j-1; i++) {
		printf("\t%-30s%-50s%-30d\n",unit[i].word,unit[i].note,unit[i].wrong);
	}
	printf("����������Ҫ�޸ĵĵ���:\n");
	getchar();
	gets(temp);
	for(i=1; i<j-1; i++) {
		if(strcmp(temp,unit[i].word)==0) {
			printf("��Ϊ���ҵ�����Ҫ�޸ĵĵ���:%s\n",unit[i].word);
			printf("���˵����޸�Ϊ:");
			gets(temp);
			strcpy(unit[i].word,temp);
			printf("���˵��ʵ�ע���޸�Ϊ:");
			gets(temp);
			strcpy(unit[i].note,temp);
			printf("�޸ĳɹ���\n");
			break;
		}
		if(i==j-2) printf("�ʿ���û�д˵��ʣ�\n");
	}
	if((fp1=fopen("d:\\���ʿ�.txt","wb+"))==NULL) {
		printf("ERROR!");
		system("pause");
		exit(0);
	}
	for(i=1; i<j-1; i++)
		fwrite(&unit[i],sizeof(Unit),1,fp1);
	fclose(fp1);
}

void recite() {
	FILE *fp1;
	if((fp1=fopen("d:\\���ʿ�.txt","rb+"))==NULL) {
		printf("ERROR!");
		system("pause");
		exit(0);
	}
	i=1;
	while(!feof(fp1)) {
		fread(&unit[i],sizeof(Unit),1,fp1);
		i++;
	}
	j=i;
	fclose(fp1);
	for(i=1; i<j-2; i++) {
		for(int k=1; k<=j-2-i; k++) {
			if(unit[k].wrong<unit[k+1].wrong) {
				t=unit[k];
				unit[k]=unit[k+1];
				unit[k+1]=t;
			}
		}
	}
	char go[1];
	go[0]='1';
	i=1;
	if(i==1)
		getchar();
	while(go[0]=='1'&&i!=j-1) {
		printf("%s\n",unit[i].note);
		gets(temp);
		if(strcmp(temp,unit[i].word)==0) {
			printf("��ϲ������ˣ�\n");
			Sleep(1000);
			cout<<endl;
		} else {
			if(unit[i].wrong>=5) {
				printf("����%d�����㻹�ܴ�����NB��\n",unit[i].wrong);
				printf("��ȷ��Ϊ��%s\n",unit[i].word);
			} else {
				printf("���ź�������ˣ�\n��ȷ��Ϊ��%s\n",unit[i].word);
			}
			Sleep(500);
			cout<<endl;
			unit[i].wrong++;
		}
		if(i%5==0) {
			printf("�ٱ�����ʣ�(����1ȷ�������������˳�)");
			cin>>go[0];
			getchar();
		}
		i++;
	}
	if((fp1=fopen("d:\\���ʿ�.txt","wb+"))==NULL) {
		printf("ERROR!");
		system("pause");
		exit(0);
	}
	for(i=1; i<j-1; i++)
		fwrite(&unit[i],sizeof(Unit),1,fp1);
	fclose(fp1);
}

void menu() {
	do {
		printf("------------------------Welcome to FreeReciting0.3.0---------------------------------------\n");
		printf("1.�鿴�ʿ�\n");
		printf("2.������\n");
		printf("3.�޸ĵ��ʼ���ע��\n");
		printf("4.ɾ������\n");
		printf("5.������\n");
		printf("6.�˳�\n");
		scanf("%d",&s1);
		switch(s1) {
			case 1:
				show();
				break;
			case 2:
				add();
				break;
			case 3:
				revise();
				break;
			case 4:
				del();
				break;
			case 5:
				recite();
				break;
			case 6:
				printf("ллʹ�ã��ټ���\n");
				break;
			default:
				fflush(stdin);
				printf("��������\n");
				break;
		}
		system("pause");
		system("cls");
	} while(s1!=6);
}

int main() {
	menu();
	return 0;
}
