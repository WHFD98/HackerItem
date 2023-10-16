#include<iostream>
#include<Windows.h>
using namespace std;
int main(void){
	//打印金字塔
	int row;
	cout<<"请输入行数:"<<endl;
	cin >> row;
	
	for(int i=1;i<=row;i++){
		//打印空格
		for(int j=0;j<row-i;j++){
		cout<<" ";
		}
		//打印星号
		for(int j=0;j<2*i-1;j++){
			cout<<"*";	
		}
		cout<<endl;
	}
	system("pause");
	return 0;

}