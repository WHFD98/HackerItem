//输入一个2进制正数,把它转换为10进制输出
//计算机无法直接输入二进制数,所以以字符串输入的方法输入

#include<iostream>
#include<windows.h>
#include<string>
using namespace std;


int main(void){
	string str;
	int p = 1;
	int s = 0;
	cout<<"请输入一个二进制数:"<<endl;
	cin>>str;
	for(int i=str.length()-1;i>=0;i--){
		int x = str[i]-'0';//'0'-'0'=0;'1'-'0'=1;将字符转化为整数
		s += x * p;
		p *= 2;
	}
	cout<<s<<endl;
	system("pause");
	return 0;
}