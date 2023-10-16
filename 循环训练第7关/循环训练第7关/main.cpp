//输出指定项的斐波那契数列
//1,1,2,3,5,8,13,21,....
//具体输出多少项,由用户决定
//n为50的时候,出BUG了,范围爆掉了,超出Int的范围了.溢出了
#include<iostream>
#include<Windows.h>
using namespace std;

int main(void){
	int n =0;
	long long a=1;
	long long b=1;
	long long value;
	cout<<"请输入斐波那契数列的个数:"<<endl;
	cin>>n;
	if(n<=0){
		cout<<"要求是大于0的正数"<<endl;
		return 1;
	
	}
	if(n==1){
		cout<<1<<endl;
		system("pause");
		return 0;
	}
	if(n==2){
		cout<<"1 1"<<endl;
		system("pause");
		return 0;
	}
	cout<<"1 1 ";
	for(int i=3;i<=n;i++){
		value=a+b;
		a=b;
		b=value;
		cout<<value<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}