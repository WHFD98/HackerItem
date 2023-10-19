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
	//设置终端窗口大小
	//mode con cols=40 lines=5
	char cmd[128];
	sprintf(cmd,"mode con cols=%d lines=%d",WIDTH,HETGHT);
	system(cmd);
}

void inputPwd(char pwd[],int size){
	char c;
	int i = 0;
	//请输入密码:123456
	while(1){
		c = getch();//不会回显
		//如果读到回车符,返回'\r',用getch()读的时候,用'\r',一般用的是'\n'
		if(c == '\r'){
			pwd[i]=0;//是为了确保密码字符串正确终止，以便后续处理.
			//因为它告诉程序在哪里字符串结束。如果字符串没有正确终止，那么字符串处理函数会继续读取内存，直到遇到 null 字符，这可能导致未定义行为或内存访问错误。
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
	cout<<"请输入用户名:"<<endl;
	cin>>name;
	cout<<"请输入密码:"<<endl;
	inputPwd(pwd,sizeof(pwd));

	if(name == "WHFD98" && !strcmp(pwd,  "123456")){
		return;
	}else{
		cout<<"用户名或密码错误!请重新输入."<<endl;
		}
	}
}
//加一个居中函数
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
	cout<<"1:网站404攻击"<<endl;
	cout<<"2:网站篡改攻击"<<endl;
	cout<<"3:网站攻击修复"<<endl;
	cout<<"4:查看攻击记录"<<endl;
	cout<<"5:退出"<<endl;
	*/
	string menu[]={
		"1:网站404攻击",
		"2:网站篡改攻击",
		"3:网站攻击修复",
		"4:查看攻击记录",
		"5:退出"
	};
	//计算菜单项的最大长度
	int max = 0;
	int menuCount = sizeof(menu)/sizeof(menu[0]);//计算数组里的元素个数,5个元素.
	for(int i=0;i<menuCount;i++){
		if(menu[i].length()>max){
			max = menu[i].length();	
		}
	}
	system("cls");
	//垂直方向上也居中显示
	 int verticalPadding = (HETGHT - menuCount) / 2;
    
    // 打印垂直空行
    for (int i = 0; i < verticalPadding; i++) {
        cout << endl;
    }
	//打印标题
	printInMiddle("---黑客攻击系统---");
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
		cout<<"请选择:";
		cin>>n;
		if(cin.fail()){
			cin.clear();
			cin.sync();
			cout<<"无效输入,请重新输入."<<endl;
			system("pause");
		}else{
			break;
		}
	}
	return n;
}
void attack404(void){
	
	//int hk_404(char *id, char *response) ;

	char id[64];//网站的ID
	char response[4096];//攻击后,从服务器返回的结果
	system("cls");
	printInMiddle("---网站404攻击---");
	cout<<"请输入准备攻击的网站ID:";
	scanf_s("%s",id,sizeof(id));

	cout<<"正在执行404攻击..."<<endl;
	//发起攻击
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
	printInMiddle("---网站篡改攻击---");
	scanf_s("%s",id,sizeof(id));
	cout<<"请输入你要写入的内容:";
	cin>>attackText;
	cout<<"正在执行网站篡改攻击..."<<endl;
	//把本地的GBK编码转换成UTF-8编码
	//因为网站用的是UTF-8编码
	GBKToUTF8(attackText);
	hk_tamper(id,(char*)attackText.c_str(),response);//因为头文件里用的是C语言的字符串,而我们用C++的string定义的字符串,所以要用.c_str转换成c语言的字符串
	string retStr = UTF8ToGBK(response);
	cout<<retStr<<endl;
	system("pause");
}
void siteRepair(void){
	char id[64];//网站的ID
	char response[4096];//攻击后,从服务器返回的结果
	system("cls");
	printInMiddle("---网站攻击修复---");
	cout<<"请输入准备修复的网站ID:";
	scanf_s("%s",id,sizeof(id));

	cout<<"正在执行攻击修复..."<<endl;
	//网站修复
	hk_restore(id,response);
	string retStr = UTF8ToGBK(response);
	cout<<retStr<<endl;
	system("pause");

	
}
void attackRecord(void){
	char id[64];//网站的ID
	char response[4096];//攻击后,从服务器返回的结果
	system("cls");
	printInMiddle("---查看攻击记录---");
	cout<<"请输入查看攻击记录的网站ID:";
	scanf_s("%s",id,sizeof(id));

	cout<<"正在查看攻击记录..."<<endl;
	//查看攻击记录
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
		cout<<"无效输入,请重新输入."<<endl;
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
