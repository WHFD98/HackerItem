#include<iostream>
#include<Windows.h>
#include <string>
#include"hacker.h"
#include<conio.h>
using namespace std;
#define WIDTH 40
#define HETGHT 15
#define MAXSIZE 4096



void init(void){
	//�����ն˴��ڴ�С
	//mode con cols=40 lines=5
	char cmd[128];
	sprintf(cmd,"mode con cols=%d lines=%d",WIDTH,HETGHT);
	system(cmd);
}

void inputPwd(char pwd[],int size){
	char c;
	int i = 0;
	//����������:123456
	while(1){
		c = getch();//�������
		//��������س���,����'\r',��getch()����ʱ��,��'\r',һ���õ���'\n'
		if(c == '\r'){
			pwd[i]=0;//��Ϊ��ȷ�������ַ�����ȷ��ֹ���Ա��������.
			//��Ϊ�����߳����������ַ�������������ַ���û����ȷ��ֹ����ô�ַ����������������ȡ�ڴ棬ֱ������ null �ַ�������ܵ���δ������Ϊ���ڴ���ʴ���
			break;
		}else{
			pwd[i] = c;
			i++;
			cout<<"*";
		}
	}
	cout<<endl;
}
void login(void){
	string name;
	//string password;
	char pwd[32];
	while(1){
	cout<<"�������û���:"<<endl;
	cin>>name;
	cout<<"����������:"<<endl;
	inputPwd(pwd,sizeof(pwd));

	if(name == "WHFD98" && !strcmp(pwd,  "123456")){
		return;
	}else{
		cout<<"�û������������!����������."<<endl;
		}
	}
}
//��һ�����к���
void printInMiddle(string msg){
	int leftSpace =(WIDTH-msg.length())/2;
	for(int i=0;i<leftSpace;i++){
		cout<<" ";
	}
	cout<<msg<<endl;
}
void menuShow(void){
	/*
	system("cls");
	cout<<"1:��վ404����"<<endl;
	cout<<"2:��վ�۸Ĺ���"<<endl;
	cout<<"3:��վ�����޸�"<<endl;
	cout<<"4:�鿴������¼"<<endl;
	cout<<"5:�˳�"<<endl;
	*/
	string menu[]={
		"1:��վ404����",
		"2:��վ�۸Ĺ���",
		"3:��վ�����޸�",
		"4:�鿴������¼",
		"5:�˳�"
	};
	//����˵������󳤶�
	int max = 0;
	int menuCount = sizeof(menu)/sizeof(menu[0]);//�����������Ԫ�ظ���,5��Ԫ��.
	for(int i=0;i<menuCount;i++){
		if(menu[i].length()>max){
			max = menu[i].length();	
		}
	}
	system("cls");
	//��ֱ������Ҳ������ʾ
	 int verticalPadding = (HETGHT - menuCount) / 2;
    
    // ��ӡ��ֱ����
    for (int i = 0; i < verticalPadding; i++) {
        cout << endl;
    }
	//��ӡ����
	printInMiddle("---�ڿ͹���ϵͳ---");
	int leftSpace =(WIDTH-max)/2;
	for(int i=0;i<menuCount;i++){
		for(int i=0;i<leftSpace;i++){
			cout<<" ";
		}
	
		cout<<menu[i]<<endl;
	}
}

int menuChoise(void){
	int n = 0;
	while(1){
		cout<<"��ѡ��:";
		cin>>n;
		if(cin.fail()){
			cin.clear();
			cin.sync();
			cout<<"��Ч����,����������."<<endl;
			system("pause");
		}else{
			break;
		}
	}
	return n;
}
void attack404(void){
	
	//int hk_404(char *id, char *response) ;

	char id[64];//��վ��ID
	char response[4096];//������,�ӷ��������صĽ��
	system("cls");
	printInMiddle("---��վ404����---");
	cout<<"������׼����������վID:";
	scanf_s("%s",id,sizeof(id));

	cout<<"����ִ��404����..."<<endl;
	//���𹥻�
	hk_404(id,response);
	string retStr = UTF8ToGBK(response);
	cout<<retStr<<endl;
	system("pause");
}
void siteEdit(void){
	char id[64];
	char response[MAXSIZE];
	string attackText;

	system("cls");
	printInMiddle("---��վ�۸Ĺ���---");
	scanf_s("%s",id,sizeof(id));
	cout<<"��������Ҫд�������:";
	cin>>attackText;
	cout<<"����ִ����վ�۸Ĺ���..."<<endl;
	//�ѱ��ص�GBK����ת����UTF-8����
	//��Ϊ��վ�õ���UTF-8����
	GBKToUTF8(attackText);
	hk_tamper(id,(char*)attackText.c_str(),response);//��Ϊͷ�ļ����õ���C���Ե��ַ���,��������C++��string������ַ���,����Ҫ��.c_strת����c���Ե��ַ���
	string retStr = UTF8ToGBK(response);
	cout<<retStr<<endl;
	system("pause");
}
void siteRepair(void){
	char id[64];//��վ��ID
	char response[4096];//������,�ӷ��������صĽ��
	system("cls");
	printInMiddle("---��վ�����޸�---");
	cout<<"������׼���޸�����վID:";
	scanf_s("%s",id,sizeof(id));

	cout<<"����ִ�й����޸�..."<<endl;
	//��վ�޸�
	hk_restore(id,response);
	string retStr = UTF8ToGBK(response);
	cout<<retStr<<endl;
	system("pause");

	
}
void attackRecord(void){
	char id[64];//��վ��ID
	char response[4096];//������,�ӷ��������صĽ��
	system("cls");
	printInMiddle("---�鿴������¼---");
	cout<<"������鿴������¼����վID:";
	scanf_s("%s",id,sizeof(id));

	cout<<"���ڲ鿴������¼..."<<endl;
	//�鿴������¼
	hk_record(id,response);
	string retStr = UTF8ToGBK(response);
	cout<<retStr<<endl;
	system("pause");

}
int menuCase(void){
	int n = menuChoise();
	switch(n){
	case 1:
		attack404();
		break;
	case 2:
		siteEdit();
		break;
	case 3:
		siteRepair();
		break;
	case 4:
		attackRecord();
		break;
	case 5:
		exit(0);
	default:
		cout<<"��Ч����,����������."<<endl;
		system("pause");
		break;
	}
	
}
int main(void){
	init();
	login();
	
	while(1){
		menuShow();
		menuCase();	
	}
	//system("pause");
	return 0;
}
