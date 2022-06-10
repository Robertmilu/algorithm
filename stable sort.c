#include <stdio.h>
#include <stdlib.h>

typedef struct//cardの構造体の定義
{
    int value;//カードの数字
    char patt;//pattern of card
}card_t;



void selectionSort(card_t* a, int n)//選択ソート関数(各位置から最後まで最小値を探して今の位置と交換するソート)
{
    int i,j,minj;
    card_t tmp;//i,j for loop 、 minjは各ループのj最小値の位置、 tmpは交換の臨時変数

    for(i = 0; i < n; i++)//最初から最後まで
    {
        minj = i;//最小値位置を今のループの最初位置として初期化
        for(j = i; j < n; j++)//iから最後まで最小値を探し、最小値の位置minjに代入する
        {
            if(a[j].value < a[minj].value)
            {
                minj = j;
            }
        }
        if(a[i].value != a[minj].value)//もしa[i]の後の最小値がa[i]と異なるなら、交換する
        {
        tmp = a[i];
        a[i] = a[minj];
        a[minj] = tmp;
        }
    }
}

void bubbleSort(card_t* a, int n)//バブルソート関数、n 個の要素を含む配列 a
{
    int j;
    card_t tmp;//tmpは交換の臨時変数,j for loop
    int flag = 1;// 逆の隣接要素が存在する
    while(flag)// 逆の隣接要素が存在すれば
    {
        flag = 0;
        for(j = n - 1; j >= 1; j-- )//最後から第二個まで
        {
            if(a[j].value < a[j-1].value)//左の方が大きなら交換
            {
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                flag = 1;//逆の隣接要素が存在する
            }
        }
    }
}

void isStable(card_t* a, int n, card_t* std)//stableかどうかの判定関数,aは判定したい配列,stdは標準配列(bubble sorted)、バブルソートと同じならstable
{
    int flag = 0;//stableなら0,not stableなら１
    for(int i = 0; i < n ; i++)
    {
        if(a[i].patt != std[i].patt)
        {
            flag = 1;//stdと異なるならnot stable
        }
    }

    if(flag == 1)   printf("Not stable\n");
    else    printf("Stable\n");

}


int main(void)
{
    int i,n;//i for loop, n 個の要素
    char space;//for space of input
    
    scanf("%d",&n);//nを読み込む
    scanf("%c",&space);//改行を取り除く

    card_t *a = malloc(sizeof(card_t) * n);
    card_t *b = malloc(sizeof(card_t) * n);
    card_t *c = malloc(sizeof(card_t) * n);//配列を初期化、メモリ配布

    for(i = 0; i < n; i++)
    {
       scanf("%c%d%c",&a[i].patt,&a[i].value,&space);
    }//配列に読み込む,三つ目の%cは空白のために

    for(i = 0; i < n; i++)
    {
        c[i].patt = b[i].patt = a[i].patt;
        c[i].value = b[i].value = a[i].value;
    }//入力内容のコピー

    selectionSort(b, n);//bを選択ソートする
    bubbleSort(c, n);//cをバブルソートする

    for(i = 0; i < n; i++)
    {
        if(i == n-1)    printf("%c%d",c[i].patt,c[i].value);
        else    printf("%c%d ",c[i].patt,c[i].value);
    }
    printf("\n");
    printf("Stable\n");//C(bubble sort)の中身を出力、安定であると出力

    for(i = 0; i < n; i++)
    {
        if(i == n-1)    printf("%c%d",b[i].patt,b[i].value);
        else    printf("%c%d ",b[i].patt,b[i].value);
    }
    printf("\n");
    isStable(b,n,c);//b(selection sort)の中身を出力、安定かどうかを判断し出力

    free(a);
    free(b);
    free(c);
    a = NULL;
    b = NULL;
    c = NULL;//メモリ解放

    return 0;
}