#include <time.h>
#include <stdlib.h>
#include <stdio.h>


int main_array(void){

  srand(time(NULL)); 
  printf("\n\n === 아빠는 대머리 게임 === \n\n");

  int answer;
  int treatment = rand() % 4;

  int cntShowBottle = 0; //게임에 보여줄 병의 갯수
  int prevCntShowBottle = 0; //앞게임에 보여준 병의 갯수
  
  for(int i = 1; i <= 3; i++){

    int bottle[4] = {0, 0, 0, 0};
    do{
      cntShowBottle = rand() % 2 + 2; //2 ~ 3개랜덤으로 보여줌
    }while(cntShowBottle == prevCntShowBottle);


    int isIncluded = 0;//보여준병에 발모제가있냐없냐여부
    printf(" > %d번째 시도 : ", i);


    //보여줄병종류선택
    for(int j = 0; j < cntShowBottle; j++){
      int randBottle = rand() % 4;
      if(bottle[randBottle] == 0){        
        bottle[randBottle] = 1;
        if(randBottle == treatment){
          isIncluded = 1;
        }

      }else{
        j--;
      }
    }


    //사용자에게 문제표시
    for(int k = 0; k < 4; k++){

      if(bottle[k] == 1){

        printf("%d ", k + 1);
      }
    }

    printf(" 물약을 머리에 바릅니다\n\n");
    
    if(isIncluded == 1){
      printf("  >> 성공 ! 머리가 났어요!! \n");
    }else{
      printf("  >> 실패 ! 머리가 나지 않았어요!! \n");
    }

    printf("\n ..... 계속 하려면 아무키나 누르세요 .....\n");
    getchar(); //입력값잡아줌
  }

  printf("\n\n발모제는 몇 번일까요? ");
  scanf("%d", &answer);

  if(answer == treatment + 1){
    printf("\n >> 정답입니다!\n");
  }else{
    printf("\n >> 땡! 틀렸습니다. 정답은 %d입니다.", treatment + 1);
  }


  return 0;
}