#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int arrayAnimal[4][5]; //카드지도 20장카드
int checkAnimal[4][5];//뒤집혀졌는지 여부확인
char *strAnimal[10];

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void pirntAnimal();
void printQuestion();
int foundAllAnimals();


int main_m_array(void){

  srand(time(NULL));

  initAnimalArray();
  initAnimalName();

  shuffleAnimal();

  int failCount = 0;

  while(1){

    int select1 = 0; // 사용자가 선택한 처음 수
    int select2 = 0; // 사용자가 선택한 두번째 수

    pirntAnimal(); //동물 위치 출력
    printQuestion();  //문제출력 (카드지도)
    printf("뒤집을 카드를 2개 고르세요  :  ");
    scanf("%d %d", &select1, &select2);

    if(select1 == select2)
      continue;


      //정수 좌표를 (x, y)로 변환
    int firstSelect_x = conv_pos_x(select1);
    int firstSelect_y = conv_pos_y(select1);

    int secondSelect_x = conv_pos_x(select2);
    int secondSelect_y = conv_pos_y(select2);

    if((checkAnimal[firstSelect_x][firstSelect_y] == 0 && checkAnimal[secondSelect_x][secondSelect_y] == 0) && (arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y])){

      printf("\n\n빙고!! : %s 발견\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);

      checkAnimal[firstSelect_x][firstSelect_y] = 1;
      checkAnimal[secondSelect_x][secondSelect_y] = 1;


    }else{

      printf("\n\n땡!! (틀렸거나, 이미 뒤집힌 카드입니다)\n");
      printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
      printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
      printf("\n\n");

      failCount++;

    }
      
  if(foundAllAnimals() == 1){
    
    printf("\n\n 축하합니다!! 모든 동물을 다 찾았네요. \n");
    printf("지금까지 총 %d번 실수 하였습니다.\n", failCount);
    break;

  }

  }

  return 0;
}


void initAnimalArray(){

  for(int i = 0; i < 4; i++){

    for(int j = 0; j < 5; j++){
      arrayAnimal[i][j] = -1;
    }
  }
}


void initAnimalName(){

  strAnimal[0] = "하마";
  strAnimal[1] = "수달";
  strAnimal[2] = "낙타";
  strAnimal[3] = "퓨마";
  strAnimal[4] = "여우";
  strAnimal[5] = "악어";
  strAnimal[6] = "기린";
  strAnimal[7] = "토끼";
  strAnimal[8] = "치타";
  strAnimal[9] = "돼지";

}


void shuffleAnimal(){

  for(int i = 0; i < 10; i++){

    for(int j = 0; j < 2; j++){

      int pos = getEmptyPosition();
      int x = conv_pos_x(pos);
      int y = conv_pos_y(pos);

      arrayAnimal[x][y] = i; 

    }
  }
}

//좌표에서 빈 공간 찾기
int getEmptyPosition(){

  while(1){
    int randPos = rand() % 20; //0~19사이의숫자반환

    int x = conv_pos_x(randPos);
    int y = conv_pos_y(randPos);

    if(arrayAnimal[x][y] == -1){
      return randPos;
    }    
  }
  return 0;
}


int conv_pos_x(int x){

  return x / 5;

}


int conv_pos_y(int y){

  return y % 5;

}

//동물 위치 출력
void pirntAnimal(){

  printf("\n=================정답=================\n\n");

  for(int i = 0; i < 4; i++){

    for(int j = 0; j < 5; j++){

      printf("%8s", strAnimal[arrayAnimal[i][j]]);

    }
    printf("\n");
  }
  printf("\n======================================\n\n");
}

//문제출력(카드지도))
void printQuestion(){

  printf("\n\n<문제>\n");

  int seq = 0; //카드선택할수있도록 카드번호 임시로 부여

  for(int i = 0; i < 4; i++){

    for(int j = 0; j < 5; j++){

      if(checkAnimal[i][j] != 0){
        printf("%8s", strAnimal[arrayAnimal[i][j]]);
      }else{
        printf("%8d", seq);
      }
      seq++;      
    }
    printf("\n");
  }
}


int foundAllAnimals(){

  for(int i = 0; i < 4; i++){

    for(int j = 0; j < 5; j++){

      if(checkAnimal[i][j] == 0){
        return 0;
      }        
    }
  }
  return 1; //모두 다 찾음
}
