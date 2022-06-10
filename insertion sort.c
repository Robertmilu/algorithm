#include<stdio.h>

int main(void)
{
	int i,v,j,x,n;//変数の初期化
	
	scanf("%d",&n);//数字の数を読み込む
	
	int a[n];//配列の初期化
	
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);//数字を配列に読み込む
	}
	
	for(x = 0;x < n;x++)//配列の内容を出力する
	{
		if(x < n-1)
		{
			printf("%d ",a[x]);//最後の数字じゃなかったら数字＋空白
		}
		
		else
		{
			printf("%d\n",a[x]);//最後の数字なら数字＋¥n
		}
	}

	
	for(i=1;i<n;i++)
	{
		v = a[i];//挿入したい数字をvに代入
		j = i-1;
		while(j >= 0 && a[j] > v)
		{
			a[j+1] = a[j];
			j--;
			a[j+1] = v;
		}//vの前の数字がvより大きいなら入れ替える
		
		for(x = 0;x < n;x++)//配列の内容を出力する
		{
			if(x < n-1)
			{
				printf("%d ",a[x]);//最後の数字じゃなかったら数字＋空白
			}
		
			else
			{
				printf("%d\n",a[x]);//最後の数字なら数字＋¥n
			}
		}
	}
	return 0;
}