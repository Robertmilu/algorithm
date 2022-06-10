#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
  unsigned int key;
  struct node *next;
  struct node *prev;
};//node構造体の定義

typedef struct node * NodePointer;//node構造体のポインタの定義

NodePointer nil;//番兵のnode

NodePointer listSearch(int key){

  NodePointer x;
  x = nil->next;//nilの次は一番目のnode。
  while( x != nil && x->key != key)
  {
      x = x->next;
  }
  return x;
}//一番目のnodeからnilまで(最悪の場合)keyを探す

void init(){
  nil = malloc(sizeof(struct node));
  nil->next = nil;
  nil->prev = nil;
}//番兵の初期化

void printList(){
  NodePointer cur = nil->next;//最初のnodeをcurに代入
  int isf = 1;//出力の空白のための変数,勉強になった！
  while(1){
    if ( cur == nil ) break;
    if ( isf == 0)  printf(" ");
    printf("%d", cur->key);
    cur = cur->next;
    isf = 0;
  }
  printf("\n");
}

void deleteNode(NodePointer t){
  if ( t == nil ) return;//番兵なら何もしない
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
  t = NULL;//tのnextとprevを双方向に連結し、tのメモリを解放
}

void deleteFirst(){
  NodePointer t = nil->next;//nilのnextは最初のnode
  if ( t == nil ) return;//番兵なら何もしない
  deleteNode(t);//tの削除
}

void deleteLast(){
  NodePointer t = nil->prev;//nilのprevは最後のnode
  if ( t == nil ) return;//番兵なら何もしない
  deleteNode(t);//tの削除
}

void delete(int key){
  deleteNode(listSearch(key));//keyと等しいkeyを持っているnodeを削除
}


void insert(int key){
  NodePointer x;
  x = malloc(sizeof(struct node));
  x->key = key;//keyを代入
  x->next = nil->next;
  nil->next->prev = x;//xのnextのnodeと双方向連結
  nil->next = x;
  x->prev = nil;//xとnilの双方向連結
}

int main(){
  int key, n, i;
  int size = 0;
  char com[20];
  int np = 0, nd = 0;
  scanf("%d", &n);
  init();
  for ( i = 0; i < n; i++ ){
    scanf("%s%d", com, &key);
    if ( com[0] == 'i' ) {insert(key); np++; size++;}//if command is insert
    else if ( com[0] == 'd' ) {
      if (strlen(com) > 6){//if command is deletexxxx
	if ( com[6] == 'F' ) deleteFirst();
	else if ( com[6] == 'L' ) deleteLast();
      } else {//if command is delete (key)
	delete(key); nd++; 
      }
      size--;
    }
  }

  printList();//出力する
  return 0;
}