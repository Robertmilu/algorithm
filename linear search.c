#include<stdio.h>

int main(void)
{
	int n1,n2;
	int i,j;
	int cnt = 0;//変数を初期化する
	
	scanf("%d",&n1);
	
	int s[n1];
	for(i = 0; i < n1 ; i++)
	{
		scanf("%d",&s[i]);
	}
	
	scanf("%d",&n2);
	int t[n2];
	
	for(i = 0; i < n1 ; i++)
	{
		scanf("%d",&t[i]);
	}//入力から読み込む
	
	
	for(i = 0; i < n2; i++)
	{
		for(j = 0; j < n1; j++)
		{
			if(s[j] == t[i])
			{
				cnt++;
				break;
			}
		}
	}//配列tの各数字を配列sで探して、sに含まれているなら変数cntが１増える
	
	printf("%d\n",cnt);//cntを出力する
	return 0;
}