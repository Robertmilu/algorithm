#include <stdio.h>

int cnt = 0;//交換回数

void selectionSort(int* a, int n)//選択ソート関数(各位置から最後まで最小値を探して今の位置と交換するソート)
{
    int i,j,minj,tmp;//i,j for loop 、 minjは各ループのj最小値の位置、 tmpは交換の臨時変数

    for(i = 0; i < n; i++)//最初から最後まで
    {
        minj = i;//最小値位置を今のループの最初位置として初期化
        for(j = i; j < n; j++)//iから最後まで最小値を探し、最小値の位置minjに代入する
        {
            if(a[j] < a[minj])
            {
                minj = j;
            }
        }
        if(a[i] != a[minj])//もしa[i]の後の最小値がa[i]と異なるなら、交換する
        {
        tmp = a[i];
        a[i] = a[minj];
        a[minj] = tmp;
        cnt++;//交換回数+1
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

    selectionSort(a, n);//選択ソートする

    for(i = 0; i < n; i++)
    {
        if(i == n-1)    printf("%d",a[i]);
        else    printf("%d ",a[i]);
    }
    printf("\n");

    printf("%d\n",cnt);//出力


    return 0;
}