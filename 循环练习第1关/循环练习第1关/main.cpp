#include<iostream>
#include<Windows.h>
using namespace std;

int main(void){
//用户选择输入行数跟列数:5行8列
	int row;
	int column;
	cout<<"请输入您想要的行数:"<<endl;
	cin>>row;
	cout<<"请输入您想要的列数:"<<endl;
	cin>>column;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
		
			cout<<"*";
		}	
		cout<<endl;
	}

	system("pause");
	return 0;
}