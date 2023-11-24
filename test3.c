
#include <stdio.h>
#include <stdlib.h>
#define element int
#define maxsize 10

typedef struct queue{
    element rear;
    element front;
    element data[maxsize];
}queue;

void queue_first(queue *ung){
    ung->rear = 0;
    ung->front = 0;
    //ung->data[maxsize] = 0;
}

void insert_ung(queue *ung,element value){
    /*
    if(ung->rear == maxsize){
        ung->rear = ung->front;
    }
    */
    ung->data[ung->rear % maxsize] = value;
    ung->rear = ung->rear+1;
    for(int i=ung->rear % maxsize -1;i>=ung->front;i--){
        printf("<-%d",ung->data[i]);
    }
}

void delete_ung(queue *ung){
    ung->front++;
    for(int i=ung->rear % maxsize -1;i>=ung->front;i--){
        printf("<-%d",ung->data[i]);
    }
}

int main(void){
    int user,value;
    queue ung;

    queue_first(&ung);

    while(1){
        printf("\n1.삽입 2.삭제 : ");
        scanf("%d",&user);
        switch(user){
            case 1:{
                printf("입력하신 수를 큐에 넣습니다.\n");
                printf("입력 : ");
                scanf("%d",&value);
                insert_ung(&ung,value);
                break;
            }

            case 2:{
                printf("가장 오래된 원소를 1개 삭제합니다.\n");
                delete_ung(&ung);
                break;
            }

            default :{
                printf("잘못된 입력으로 종료합니다!\n");
                break;
            }

        }
    }
}
