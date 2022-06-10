#include <stdio.h>

int cnt = 0;//交換回数

void bubbleSort(int* a, int n)//バブルソート関数、n 個の要素を含む配列 a
{
    int j,tmp;//tmpは交換の臨時変数,j for loop
    int flag = 1;// 逆の隣接要素が存在する
    while(flag)// 逆の隣接要素が存在すれば
    {
        flag = 0;
        for(j = n - 1; j >= 1; j-- )//最後から第二個まで
        {
            if(a[j] < a[j-1])//左の方が大きなら交換
            {
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                cnt++;//交換回数+1
                flag = 1;//逆の隣接要素が存在する
            }
        }
    }
}

int main(void)
{
    int i,n;//i for loop, n 個の要素
    
    scanf("%d",&n);//nを読み込む

    int a[n];//配列を初期化
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }//数字を配列に読み込む

    bubbleSort(a, n);//バブルソートする

    for(i = 0; i < n; i++)
    {
        if(i == n-1)    printf("%d",a[i]);
        else    printf("%d ",a[i]);
    }
    printf("\n");

    printf("%d\n",cnt);//出力


    return 0;
}