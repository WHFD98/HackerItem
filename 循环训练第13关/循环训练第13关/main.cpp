/*输入一句话,然后把这个字符串以单词为单位,逆转输出
比如将"Alice call Jack"转换为"Jack call Alice"
实现速度最快,移动最少
			123 45 678
	方法1	最终678 45 123												方法2			第一步:先以单词为单位反一次,   321 54 876
			初步876 54 321																第二步:再把整个句子再反一遍.   678 45 123
			先反过来,再以每个单词为单位,再反一次.
*/
#include<iostream>
#include<Windows.h>
#include<string>

using namespace std;
//用方法2
int main(void){
	char str[256];
	int i = 0;
	cout<<"请输入一句话(英文)"<<endl;
	gets_s(str,sizeof(str));
	while(str[i]){
		//跳过前面的空格
		//该循环结束后,str[i]是下一个单词的第一个字母
		while(str[i] == ' ')i++;
		int j = i;
		//该循环结束之后,str[j]是这个单词后面的下一个位置
		while(str[j] != ' ' && str[j])j++;
		//逆转这个单词
		for(int k1=i,k2=j-1;k1<k2;k1++,k2--){
			char tmp = str[k1];
			str[k1] = str[k2];
			str[k2] = tmp;
		}
		i = j;//把i引向下一个单词的位置
	}
	for(int k1 = 0,k2=i-1;k1<k2;k1++,k2--){
			char tmp = str[k1];
			str[k1] = str[k2];
			str[k2] = tmp;
	}
	cout<<str<<endl;
	system("pause");
	return 0;
}
