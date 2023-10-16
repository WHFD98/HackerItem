#include<iostream>
#include<windows.h>



using namespace std;

//输入行数,第一行有一个,第二行有两个,第三行有三个...
int main(void){
	int row;
	int column;
	cout << "请输入行数:"<<endl;
	cin >> row;

	for(int i=1;i<=row;i++){
		for(int j=0;j<i;j++){
			cout<<"*";
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}