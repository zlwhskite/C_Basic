#include <time.h>
#include <stdlib.h>
#include <stdio.h>


int level;
int arrayFish[6];
int *cursor;

void initDate();
void printfFish();
void decreaseWater(long elapsedTime);
int checkFishAlive();


int main(void){

  long startTime = 0;
  long totalElapsedTime = 0;
  long prevElapsedTime = 0;

  int num;
  initDate();

  cursor = arrayFish;

  startTime = clock();

  while(1){

    printfFish();
    printf("몇 번 어항에 물을 주시겠어요? ");
    scanf("%d", &num);

    if(num < 1 || num > 6){
      printf("\n입력값이 잘못되었습니다.\n");
      continue;
    }
    
    totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
    printf("총 경과 시간 : %ld 초\n", totalElapsedTime);

    //물을 주고 이후에 흐른 시간
    prevElapsedTime = totalElapsedTime - prevElapsedTime;
    printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);

    //어항의 물 증발
    decreaseWater(prevElapsedTime);

    //물 주기
    if(cursor[num - 1] <= 0){
      printf("%d번 물고기는 이미 죽었습니다..\n", num);
    }
    else if(cursor[num - 1] + 1 <= 100){
      printf("%d번 어항에 물을 줍니다.\n\n", num);
      cursor[num - 1] += 1;
    }

    //레벨업
    if(totalElapsedTime / 20 > level - 1){
      level++;
      printf(" *** 축 레벨업!! 기존 %d레벨에서 %d레벨로 업그레이드 *** \n\n", level - 1, level);

      if(level == 5){
        printf("\n\n축하합니다!! 최고 레벨을 달성하였습니다. 게임을 종료합니다.\n\n");
        exit(0);
      }      
    }

    //모든 물고기 생존 확인
    if(checkFishAlive() == 0){
      printf("모든 물고기가 죽었습니다....\n");
      exit(0);
    }else{
      printf("물고기가 아직 살아있어요!!\n"); //최소 1마리 이상의 물고기 살아있음.
    }
    prevElapsedTime = totalElapsedTime;    
  }

  return 0;
}

void initDate(){

  level = 1;

  for(int i = 0; i < 6; i++){    
    arrayFish[i] = 100; //어항의 물 높이
  }
}


void printfFish(){

  printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);

  for(int i = 0; i < 6; i++){
    printf(" %4d ", arrayFish[i]);
  }
  printf("\n\n");
}

void decreaseWater(long elapsedTime){

  for(int i = 0; i < 6; i++){

    arrayFish[i] -= (level * 3 * (int)elapsedTime);

    if(arrayFish[i] < 0){      
      arrayFish[i] = 0;
    }    
  }
}


int checkFishAlive(){

  for(int i = 0; i < 6; i++){

    if(arrayFish[i] > 0){
      return 1;
    }
  }
  return 0;
}