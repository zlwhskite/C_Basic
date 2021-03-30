#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int getRandom(int stage);
int showScreen(int stage, int num1, int num2);


int main_function(void){

  srand(time(NULL));
  int count = 0;

  for(int i = 1; i < 6; i++){
    
    int num1 = getRandom(i);
    int num2 = getRandom(i);
    showScreen(i, num1, num2);

    int answer = -1;
    scanf("%d", &answer);
    if(answer == -1){
      printf("\n\n종료하겠습니다.\n");
      exit(0);
    }
    else if(answer == num1 * num2){
      printf("\n\n정답입니다!!\n");
      count++;
    }
    else{
      printf("\n\n틀렸습니다..\n");
    }   
  }
  
  printf("\n당신은 5개의 문제에서 %d개를 맞쳤습니다!!\n", count);

  return 0;
}


int getRandom(int stage){
  return rand() % (stage * 7) + 1;
}
int showScreen(int stage, int num1, int num2){
  printf("\n\n@@@@@@@ %d번 문제입니다. @@@@@@@\n\n", stage);
  printf("\n\n\t\t%d X %d = ??     \n\n", num1, num2);
  printf("\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
  printf("\n\n@@@@@@종료 ------>>>>> -1@@@@@@\n\n");
}
