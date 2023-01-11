#include<bits/stdc++.h>
using namespace std;
#define MAX_LEN 1000

  void takeStringInput(char str[],int MAX_SIZE){
    int i=0;
    char tmp;
    while(tmp=getchar(),tmp!='\n'){
      if(i==MAX_SIZE){
        printf("STRING TOO LONG\n");
        return;
      }
      str[i++]=tmp;
    }
  }
  void performSwap(char str[]);
  void removeX(char str[]){
    if(str[0]=='\0'){
      return;
    }
    if(str[0]=='x'){
      performSwap(str);
      removeX(str);
    }
    removeX(str+1);

  }

  void performSwap(char str[]){
    if(str[0]=='\0'){
      return;
    }
    str[0]=str[1];
    performSwap(str+1);
  }


  int Length(char str[]){
    if(str[0]=='\0'){
      return 0;
    }
    else return 1+Length(str+1);
  }

int main(void){
  char str[1000];
  takeStringInput(str,MAX_LEN);
  printf("%s: %d",str,Length(str));
  removeX(str);
  puts(str);
  printf("%s: %d",str,Length(str));
  return 0;
}
