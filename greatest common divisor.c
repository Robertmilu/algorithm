#include<stdio.h>

int main(void)
{
	int x,y;
	scanf("%d %d",&x,&y);//二つの数字を読み込む
	
	int z = 0;//剰余を保存する変数の初期化
	while(y != 0)//剰余が０でなければ続く
	{
		z = x % y;//剰余をzに代入
		x = y;
		y = z;//yをxに、zをyに代入
	}
	
	printf("%d\n",x);//xを出力
	
	return 0;
}