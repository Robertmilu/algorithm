#include <stdio.h>
#include <stdlib.h>

int max = 200;//スタックの容量を定義する
int stack[200];//スタックの配列を定義する
int top = -1;

int isempty() {
   if(top == -1)
      return 1;
   else
      return 0;
}//スタックが空であるかどうかを判断する関数、空なら１を、そうでなければ０を返す

int isfull() {
   if(top == max)
      return 1;
   else
      return 0;
}//スタックが満杯であるかどうかを判断する関数、満杯なら１を、そうでなければ０を返す

int pop() {
   int x;

   if(isempty() == 0) {
      x = stack[top];
      top = top - 1;   
      return x;
   } 
   else {
      printf("empty.\n");
   }
}//スタックの一番上の数字を返す

void push(int x) {
   if(isfull() == 0) {
      top = top + 1;   
      stack[top] = x;
   } else {
      printf("full.\n");
   }
}//数字をスタックの一番上に保存する

int main(){
  int x;
  int a,b,result;
  char s[100];

  while( scanf("%s", s) != EOF ){
    if ( s[0] == '+' ){
    	a = pop();
    	b = pop();
    	result = a + b;
    	push(result);
    } //文字列が＋なら、スタックの上から二つの数字を取り出して、和を計算して、結果をスタックの一番上に入れる
    else if ( s[0] == '-' ){
    	a = pop();
    	b = pop();
    	result = b - a;
    	push(result);
    } //文字列がーなら、スタックの上から二つの数字を取り出して、差を計算して、結果をスタックの一番上に入れる
    else if ( s[0] == '*' ){
    	a = pop();
    	b = pop();
    	result = a * b;
    	push(result);
    } //文字列が＊なら、スタックの上から二つの数字を取り出して、積を計算して、結果をスタックの一番上に入れる
    else {
    	x = atoi(s);
    	push(x);
    }//文字列が数字なら、数字をint型に変換して、スタックの一番上にいれる
  }

  printf("%d\n",stack[0]);//スタックに残った数字は答えになるので、それを出力する
  return 0;
}