
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
        printf("\n1.���� 2.���� : ");
        scanf("%d",&user);
        switch(user){
            case 1:{
                printf("�Է��Ͻ� ���� ť�� �ֽ��ϴ�.\n");
                printf("�Է� : ");
                scanf("%d",&value);
                insert_ung(&ung,value);
                break;
            }

            case 2:{
                printf("���� ������ ���Ҹ� 1�� �����մϴ�.\n");
                delete_ung(&ung);
                break;
            }

            default :{
                printf("�߸��� �Է����� �����մϴ�!\n");
                break;
            }

        }
    }
}
