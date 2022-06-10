#include <stdio.h>
#include <stdlib.h>
#define LEN 100005

typedef struct process{
  char name[100];
  int t;
}P;//プロセスを新しい型Pとして定義する

P Queue[LEN+1];//待ち行列を定義する
int head, tail;//待ち行列の必要変数を定義する

int head = 0;
int tail = 0;

int isEmpty()
{
	if(head == tail)
	{
		return 1; 
	}
	else
	{
		return 0;
	}
}//待ち行列が空なら1を、そうでなければ0を返す

int isFull()
{
	if(head == (tail + 1) % LEN)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}//待ち行列が満杯なら1を、そうでなければ0を返す

void enqueue(P x){
	if(isFull() == 1)
	{
		printf("full\n");
	}
	else
	{
		Queue[tail] = x;
		if(tail + 1 == LEN)
		{
			tail = 0;
		}
		else
		{
			tail++;
		}
	}
}//待ち行列が満杯でなければ、プロセスxを待ち行列に入れて、tailを更新する

P dequeue(){
	P x;
	if(isEmpty() == 1)
	{
		printf("empty\n");
	}
	else
	{
		x = Queue[head];
		if(head + 1 == LEN)
		{
			head = 0;
		}
		else
		{
			head++;
		}
	}
	
	return x;
}//待ち行列が空でなければ、head位置のプロセスを返して、headを更新する


int main(void) {
  int n, i, q;
  int alltime = 0;
  P u;
  scanf("%d %d", &n, &q);

  for ( i = 1; i <= n; i++){
    scanf("%s", u.name);
    scanf("%d", &u.t);
    enqueue(u);
  }//入力を読み込む
  
  while(isEmpty() == 0)//待ち行列が空になるまで続く
  {
  	u = dequeue();
  	if(u.t > q)
  	{
  		u.t = u.t - q;
  		enqueue(u);
  		alltime += q;
  	}//プロセスの処理時間がクオンタムより長いなら、クオンタムで引いて、待ち行列に入れて、経過時間をクオンタムだけ増やす
  	else
  	{
  		printf("%s %d\n",u.name,u.t+alltime);
  		alltime += u.t;
  	}//プロセスの処理時間がクオンタムより短いなら、プロセスを出力して、経過時間をプロセスの処理時間だけ増やす
  }

  
  return 0;
}