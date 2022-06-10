#include <stdio.h>

int solve(int i, int goal, int* nums, int n)//配列nums[i]の後ろの要素でgoalを作れるかどうかを判断する関数(nはnumsの長さ)
{
    int result;

    if(goal == 0)   return 1;//goal == 0ならgoalを作れるという意味で(goal - nums[x] - nums[y]... = 0 --> x,y,...でgoalを作れる)
    if(i >= n)  return 0;//サイズに達したらnums[i]=nums[n],nums[n]が存在しないで、nums[0]からnums[n-1]まで一つ合格な組み合わせもないことを意味している

    result = solve(i + 1, goal, nums, n) || solve(i + 1, goal - nums[i], nums, n);
    /*nums[i]を使うかどうかで二つの道を分けて、使うならgoalをgoal-a[i]で更新し、論理演算子「or」を使うと、もし全ての道(可能性)の中で1が存在すれば,
    resultが1になる、全部0であれば、resultが0になる*/
    
    return result;
}

int main(void)
{
    int n1,n2;//与えられた配列のサイズ
    int i,j;//for loop
    int goal;//目標値
    int result;//存在するかどうか

    scanf("%d", &n1);
    int nums[n1];//数字を保存する配列

    for( i = 0; i < n1; i++ )
    {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &n2);

    for( i = 0; i < n2; i++ )//各目標値に対して
    {
        scanf("%d", &goal);
        result = solve(0, goal, nums, n1);//全ての組み合わせでこの目標値と等しい場合が存在するかどうかを判断
        if(result)  printf("yes\n");//存在すればyes
        else    printf("no\n");//存在しないならno
    }

    

    return 0;
}