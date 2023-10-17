/*
输入一个英文字符串(一句话),统计输入的单词个数
*/
#include<iostream>
#include<Windows.h>
#include<string>

using namespace std;
//跳过连续空格 跳过非空格组合 跳过连续空格
int main(void){

	char line[256];
	int i = 0;
	int count = 0;
	cout<<"请输入一句话:";
	gets_s(line,sizeof(line));
	//跳过前面的空格
	while(line[i] == ' '){
		i++;
	}
	//跳过连续空格
	while(line[i]!='\0'){//'0'=0,这句话等效于while(line[i])因为你不等于'\0'就相当于不等于0
		//那不就是非吗,所以可以这么写.
		//跳过连续的多个非空格组合(就是单词)
		while(line[i]!='\0'&&line[i]!= ' '){//也可以这么写,while(line[i]&&line[i]!=' '原理同上)
			i++;
		}
		while(line[i] == ' '){
			i++;
	    }	
		count++;
	}
	cout<<"一共有:"<<count<<"个单词"<<endl;
	system("pause");
	return 0;
}