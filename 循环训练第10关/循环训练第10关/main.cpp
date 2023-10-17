//输入一个字符串,然后将这个字符串逆转输出
#include<iostream>
#include<windows.h>
#include<string>


using namespace std;



int main(void){
	string str;
	
	cout<<"请输入字符串:"<<endl;
	cin >> str;
	int i = 0;
	int j =  str.length()-1;
	while(i<j){
		char tmp ;
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	cout<<str<<endl;
	system("pause");
	return 0;
}