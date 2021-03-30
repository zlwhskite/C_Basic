#include <stdio.h>
#include <string.h>
#include <conio.h>


//fputs, fgets -> 문자열
//fprintf, fscanf -> 전형화된파일


#define MAX 10000



int main(void){

    char line[MAX];
    char contents[MAX]; //일기장에 입력할 내용
    char password[20];
    char c; //비밀번호 키값 확인

    printf("'비밀일기'에 오신 것을 환영합니다.\n");
    printf("비밀번호를 입력하세요  :  ");

    //get char()  /  getch()의 차이점
    //getchar() : 엔터를 입력받아여 동작을 함
    //getch() : 키 입력 시 바로바로 동작을 함

    int i = 0;

    while(1){

        c = getch();

        if(c == 13){
            //13은 엔터 -> 비밀번호 입력 종료
            password[i] = '\0';
            break;

        }else{//비밀번호 입력중
            printf("*");
            password[i] = c;

        }
        i++;


    }

    printf("\n\n === 비밀번호 확인 중 ===\n\n");
    if(strcmp(password, "qlalf") == 0){
        printf(" === 비밀번호 확인 완료 === \n\n");
        char *fileName = "c\\secretdiary.txt";
        File * file = fopen(fileName, "a+b"); //파일이 없으면 생성하고 파일이 있으면 append를 한다.
        if(file == NULL){
            printf("파일 열기 실패\n");
            return 1;
        }
        
        while (fgets(line, MAX, file) != NULL)
        {
            printf("%s", line);
            
        }
        
        printf("\n\n내용을 계속 작성하세요! 종료하시려면 EXIT를 입력하세요.\n");

        while(1){
            scanf("%[^\n]", contents); //새줄(\n)이 나오기 전까지 읽어들임
            getchar();

            if(strcmp(contents, "EXIT") == 0){

                printf("비밀일기 입력을 종료합니다.\n\n");
                break;
            }
            fputs(contents, file);
            fputs("\n", file);
    }
    fclose(file);

    }

    return 0;
}