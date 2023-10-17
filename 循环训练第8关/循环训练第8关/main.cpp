//输入一个10进制的正整数,把它转换为2进制输出
//使用倒除法
#include<iostream>
#include<Windows.h>


using namespace std;
int main(void){
	int ret[32];
	int n;
	int i;
	cout<<"请输入一个正整数:"<<endl;
	cin>>n;
	if(n<=0){
		cout<<"错误!请正确输入一个正整数:"<<endl;
		system("pause");
		return 0;
	}
	i=0;
	while(n!=0){
		ret[i]=n%2;
		n=n/2;
		i++;
	}
	for(i--;i>=0;i--){//之所以是i--是因为前面循环完,i++多往后了一格,所以要i--再退回来
	
	cout<<ret[i];
	
	}
	cout<<endl;
	system("pause");
	return 0;

}