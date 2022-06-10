#include<stdio.h>

int main(void)
{
	int n1,n2;
	int left,right,mid,i;
	int cnt = 0;//変数を定義する
	
	scanf("%d",&n1);
	
	int s[n1];
	for(i = 0; i < n1 ; i++)
	{
		scanf("%d",&s[i]);
	}
	
	
	scanf("%d",&n2);
	int t[n2];
	
	for(i = 0; i < n2 ; i++)
	{
		scanf("%d",&t[i]);
	}
	
	//データの読み込み
	
	
	for(i = 0; i < n2; i++)
	{
		left = 0;
		right = n1;
		while(left < right)
		{
			mid = (left + right) / 2;
			if(s[mid] == t[i])
			{
				cnt++;
				break;
			}
			else if(t[i] < s[mid])
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
	}//配列tの各数字に対して、二分探索を実行し、同じ数字が配列sに存在すれば、cntがい増える
	
	printf("%d\n",cnt);
	return 0;
}