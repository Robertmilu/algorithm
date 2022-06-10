#include<stdio.h>
#include<stdbool.h>//flagが必要
#include<math.h>//sqrt()メソッドが必要

int main(void)
{
	int n,x;
	scanf("%d",&n);//数字の数を読み込む
	
	bool flag = true;//約数の個数が２であるかどうかを記録する変数
	int cnt = 0;//素数の総数を記録する変数
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		for(int j=2;j<=sqrt(x);j++)//判断したい数の平方根まででOK
		{
			if(x%j==0)
			{
				flag = false;
			}
		}
		
		if(flag == true)
		{
			cnt++;
		}
		
		flag=true;
	}
	printf("%d\n",cnt);
	return 0;
}
