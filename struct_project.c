#include <time.h>
#include <stdlib.h>
#include <stdio.h>


//강아지
typedef struct{
    char *name;
    int age;
    char *character;
    int level;
} DOG;

//현재까지 보유한 강아지
int collection[5] = {0, 0, 0, 0, 0};

DOG dogs[5];

void initDogs();
void printDog(int selected);
int checkCollection();


int main(void){

    srand(time(NULL));

    initDogs();

    while (1)
    {
        printf("두근 두근~! 어느 강아지의 주인이 될까요?\n아무 키나 눌러서 확인하세요!");
        getchar();

        int selected = rand() % 5;
        printDog(selected); //강아지 정보 출력
        collection[selected] = 1; //강아지 뽑기 처리

        int collectAll = checkCollection();

        if(collectAll == 1){
            break;
        }

    }
    

    return 0;
}


void initDogs(){

    dogs[0].name = "장군이";
    dogs[0].age = 3;
    dogs[0].character = "용맹함";
    dogs[0].level = 2;

    dogs[1].name = "멍군이";
    dogs[1].age = 1;
    dogs[1].character = "온순함";
    dogs[1].level = 1;

    dogs[2].name = "제키";
    dogs[2].age = 3;
    dogs[2].character = "까칠함";
    dogs[2].level = 5;

    dogs[3].name = "장군이";
    dogs[3].age = 1;
    dogs[3].character = "늘 잠만 잠";
    dogs[3].level = 3;

    dogs[4].name = "밍키";
    dogs[4].age = 5;
    dogs[4].character = "늘 배고픔";
    dogs[4].level = 4;
}


void printDog(int selected){

    printf("\n\n === 당신은 이 강아지의 주인이 되었어요!! === \n\n");
    printf(" 이름  :  %s\n", dogs[selected].name);
    printf(" 나이  :  %d\n", dogs[selected].age);
    printf(" 특징  :  %s\n", dogs[selected].character);
    printf(" 레벨  :  ");

    for(int i = 0; i < dogs[selected].level; i++){

        printf("%s", "★ ");
    }
    printf("\n\n");
}

int checkCollection(){

    int collectAll = 1;

    printf("\n\n === 보유한 강아지 목록이에요. === \n\n");
    for(int i = 0; i < 5; i++){

        if(collection[i] == 0){
            printf("%10s", "(빈 박스)"); //강아지 수집x
            collectAll = 0;
        }else{
            printf("%10s", dogs[i].name); //강아지 수집o
        }
    }
    printf("\n=========================================\n\n");

    if(collectAll){
        printf("\n\n 축하합니다!! 모든 강아지들을 다 모았어요. 열심히 키워주세요.\n\n"); //모든강아지모았을경우
    }

    return collectAll;
}