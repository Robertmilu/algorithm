#include<stdio.h>
#include<string.h>

#define M 1000001//n≤1,000,000、Mが素数であるから
#define L 14

char H[M][L]; /* Hash Table */

int getChar(char ch){
  if ( ch == 'A') return 1;
  else if ( ch == 'C') return 2;
  else if ( ch == 'G') return 3;
  else if ( ch == 'T') return 4;
}//アルファベットを整数に変換

/* convert a string into an integer value */
long long getKey(char str[]){
  long long sum = 0, p = 1, i;
  for ( i = 0; i < strlen(str); i++ ){
    sum += p*(getChar(str[i]));
    p *= 5;//五進数の考え方で、文字列を一つの整数に変換し、keyとして使う
  }
  return sum;
}

int h1(int key){ return key % M; }
int h2(int key){ return (key % (M - 1)) + 1; }//ダブルハッシュの関数を定義する

int find(char str[]){
	int key, x, y;
	x = 0;//衝突回数
	key = getKey(str);//keyを取得する
	while(1)
	{
		y = (h1(key) + x * h2(key)) % M;//ハッシュ値yを計算する
		if ( strcmp(H[y],str ) == 0)//もしyのところにstrが存在したら１を返す
		{
			return 1;
		}
		else if( strlen(H[y] ) == 0)//もしyのところに何もないなら0を返す
		{
			return 0;
		}
		x++;//衝突回数増加
	}
	return 0;
}

int insert(char str[]){
	int key, x, y;
	x = 0;//衝突回数
	key = getKey(str);//keyを取得する
	while(1)
	{
		y = (h1(key) + x * h2(key)) % M;//ハッシュ値yを計算する
		if ( strcmp(H[y],str ) == 0)//もしyのところにstrが存在したら１を返す
		{
			return 1;
		}
		else if( strlen(H[y] ) == 0)//もしyのところに何もないなら、そこにstrを入れる
		{
			strcpy(H[y], str);
			return 0;
		}
		x++;//衝突回数増加
	}
	return 0;
}

int main(){
    int i, n, h;
    char str[L], com[9];//comは命令の文字列、strはACGTの文字列
    for ( i = 0; i < M; i++ ) H[i][0] = '\0';//ハッシュテーブルの文字列部分の初期化
    
    scanf("%d", &n);//命令数を読み込む
    
    for ( i = 0; i < n; i++ ){
	scanf("%s %s", com, str);
	
	if ( com[0] == 'i' ){//insertなら辞書に入れる
	    insert(str);
	} else {
	    if (find(str)){//findなら辞書の中で探す
		printf("yes\n");
	    } else {
		printf("no\n");
	    }
	}
    }

    return 0;
}