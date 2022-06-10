#include<stdio.h>
#include<limits.h>//maxprofitの初期化が必要

int main(void)
{
	int i,n;
	scanf("%d",&n);//価格の数を読み込む
	
	int a[n];
	int maxprofit,min;
	
	
	for(i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);//価格を配列に読み込む
	}
	
	maxprofit = INT_MIN;//最大利益を最も小さい数で初期化する
	min = a[0];//ループで既に使った数の中で最も小さい数を保存する変数
	
	for(i = 1;i < n; i++)//1からn-1まで
	{
		if(maxprofit < a[i] - min)
		{
			maxprofit = a[i] - min;//a[i] - minはa[i]時点で売る最大利益、他の時点で売る最大利益と比較して、大きい方が新しい最大利益になる
		}
		
		if(min > a[i])
		{
			min = a[i];//　a[i]　と　a[0]からa[i-1]までの最小値　を比較して、小さい方が新しい最小値になる
		}
	}
	
	printf("%d\n",maxprofit);
	return 0;
}