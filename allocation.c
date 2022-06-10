#include<stdio.h>

int main(void)
{
	int n,k,p;//nー荷物の数、kー車の数、pー最大積載量
	scanf("%d %d",&n,&k);
	int new_k = k;//kの値を保存する（計算の時値が変わるから）
	
	int i,sum,w[n];//　変数　i　はループ用、sumは荷物の総重量、w[]は重量の配列
	
	for( i = 0; i < n; i++)
	{
		scanf("%d", &w[i]);
		sum += w[i];
	}//重量を読み込む
	
	i = 0;
	
	int min = sum / k;//最大積載量は必ずminの以上であるから、計算時間が減らせる
	
	int new_p = min;//最大積載量を保存する変数（min_kと同じ）
	
	while(1)//無限ループ
	{
		while(k > 0)//車が残る限り
		{
			p = new_p;
			while(p - w[i] >= 0)//この車がまだ載せるなら
			{
				p = p - w[i];//積載量を更新
				i++;//indexを次の荷物に更新
				if(i >= n)//終了条件！！！荷物を全部載せたら、出力と終了
				{
					printf("%d\n",new_p);
					return 0;
				}
			}
			k--;//次の車に載せる
		}
		i = 0;
		k = new_k;//変数を初期化
		new_p++;//最大積載量を増加
	}
}