//输出所有水仙花数
//水仙花数:3为数字,各位的立方之和,等于这个数本身
//说明:严格的说只有3位的整数,才可能是水仙花数
#include<iostream>
#include<Windows.h>
using namespace std;




int main(void){

	int a, b, c;
	for(int i=100;i<=999;i++){
	
		a=i%10;
		b=i/10%10;
		c=i/100%10;

		if(a*a*a+b*b*b+c*c*c==i){
			cout<<i<<endl;
		}

	}

	system("pause");
	return 0;
}
