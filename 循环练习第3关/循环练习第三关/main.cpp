#include<iostream>
#include<Windows.h>
using namespace std;

int main(void){
	int row;
	cout<<"请输入行数:"<<endl;
	cin>>row;
	/*第一种方法for(int i=0;i<row;i++){
		for(int j=row;j>i;j--){
			cout<<"*";
		}
	cout<<endl;
	}*/
	//第二种方法
	for (int i=0;i<row;i++){
	for(int j=0;j<row-i;j++){
	cout<<"*";
	}
	cout<<endl;
}
	system("pause");
	return 0;
}
