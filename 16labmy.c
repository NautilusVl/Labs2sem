#include <stdio.h>
#include <stdlib.h>

#define NIL -1

// Структура элемента однонаправленного списка
typedef struct SingleListNode {
    int info;
    struct SingleListNode *next;
} SingleListNode;

// Структура элемента трехнаправленного списка
typedef struct Node {
    int info1;
    int info2;
    struct SingleListNode *firstList;
    struct SingleListNode *secondList;
    struct Node *next;
    struct Node *prev;
} Node;
char getMove(); // Объявление прототипа функции getMove()
// Функция для создания элемента однонаправленного списка
SingleListNode *createSingleListNode(int info) {
    SingleListNode *node = (SingleListNode*)malloc(sizeof(SingleListNode));
    node->info = info;
    node->next = NULL;
    return node;
}

// Функция для создания элемента трехнаправленного списка
Node *createNode(int info1, int info2) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->info1 = info1;
    node->info2 = info2;
    node->firstList = NULL;
    node->secondList = NULL;
    node->next = NULL;
    return node;
}

// Функция для построения списочной структуры
Node *buildListStructure(int *seq) {
    Node *head = NULL;
    Node *curr = NULL;
    SingleListNode *currFirstList = NULL;
    SingleListNode *currSecondList = NULL;
    
    int i = 0;
    while (seq[i] != 0) {
        Node *newNode = createNode(seq[i], seq[i+1]);
        i += 2;

        if (head == NULL) {
            head = newNode;
            curr = newNode;
        } else {
            curr->next = newNode;
            curr = newNode;
        }

        int j = 0, n = 0;
        int isOdd = 0; // флаг, обозначающий нечетность N

        while (seq[i] != 0) {
            SingleListNode *elem = createSingleListNode(seq[i]);
            if (j % 2 == 0) {
                if (n % 2 == 0) {
                    if (currFirstList == NULL) {
                        currFirstList = elem;
                        curr->firstList = elem;
                    } else {
                        currFirstList->next = elem;
                        currFirstList = elem;
                    }
                } else {
                    if (currSecondList == NULL) {
                        currSecondList = elem;
                        curr->secondList = elem;
                    } else {
                        currSecondList->next = elem;
                        currSecondList = elem;
                    }
                }
            }
            j++;
            n++;
            i++;
        }

        if (n % 2 != 0) {
            isOdd = 1;
            n++;
            SingleListNode *nilNode = createSingleListNode(NIL);
            if (j % 2 == 0) {
                currFirstList->next = nilNode;
            } else {
                currSecondList->next = nilNode;
            }
        }

        if (isOdd) {
            SingleListNode *nilNode = createSingleListNode(NIL);
            currSecondList->next = nilNode;
            currSecondList = nilNode;
        }
    }
    return head;
}

// Функция для освобождения памяти
void freeMemory(Node *head) {
    while (head != NULL) {
        SingleListNode *currFirstList = head->firstList;
        SingleListNode *currSecondList = head->secondList;
        SingleListNode *temp;
        while (currFirstList != NULL) {
            temp = currFirstList;
            currFirstList = currFirstList->next;
            free(temp);
        }
        while (currSecondList != NULL) {
            temp = currSecondList;
            currSecondList = currSecondList->next;
            free(temp);
        }
        Node *tempNode = head;
        head = head->next;
        free(tempNode);
    }
}

// Функция для вывода списочной структуры
void printListStructure(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        printf("(%d, %d) -> ", curr->info1, curr->info2);
        SingleListNode *currFirstList = curr->firstList;
        SingleListNode *currSecondList = curr->secondList;
        
        printf("[");
        while (currFirstList != NULL && currFirstList->info != NIL) {
            printf("%d, ", currFirstList->info);
            currFirstList = currFirstList->next;
        }
        printf("NIL] -> ");
        
        printf("[");
        while (currSecondList != NULL && currSecondList->info != NIL) {
            printf("%d, ", currSecondList->info);
            currSecondList = currSecondList->next;
        }
        printf("NIL]\n");
        
        curr = curr->next;
        
    }
    char move;
    while (1) {
    move = getMove();
    
    if (move == 'a' || move == 'd') {
        if (head == NULL) {
            printf("List is empty!\n");
            break;
        }
        
        moveList(&curr, move);
        
        if (curr != NULL) {
            printf("(%d, %d) -> ", curr->info1, curr->info2);
            SingleListNode *currFirstList = curr->firstList;
            SingleListNode *currSecondList = curr->secondList;
        
            printf("[");
            while (currFirstList != NULL && currFirstList->info != NIL) {
                printf("%d, ", currFirstList->info);
                currFirstList = currFirstList->next;
            }
            printf("NIL] -> ");
        
            printf("[");
            while (currSecondList != NULL && currSecondList->info != NIL) {
                printf("%d, ", currSecondList->info);
                currSecondList = currSecondList->next;
            }
            printf("NIL]\n");
        } else {
            printf("List is empty or you have reached the end.\n");
            break;
        }
    } else {
        break;
    }
}
    /*while(1){
        char move;
    struct Node *current = head;
    while (current != NULL) {
        printf("Текущий элемент: %d\n", current->next);
        printf("В какую сторону двигаться (r - вправо): ");
        scanf(" %c", &move);

        if (move == 'r' && current->next != NULL) {
            current = current->next;
        } else {
            printf("Некорректное направление\n");
        }
    }
    }*/
}
char getMove() {
    printf("Press 'a' to move left or 'd' to move right, any other key to exit: ");
    char move;
    scanf(" %c", &move); // Leading space in format string to ignore whitespace characters
    return move;
}

void moveList(Node **curr, char direction) {
    if (direction == 'a' && (*curr)->prev != NULL) {
        *curr = (*curr)->prev;
    } else if (direction == 'd' && (*curr)->next != NULL) {
        *curr = (*curr)->next;
    } else {
        printf("You are on the end of the list!\n");
    }
}
int main() {
    int count,i = 0;
    //int seq[] = {1, 2, 3, 4, 5, 6, 0, 2, 3, 4, 5, 0};
    int seq[100]={0};
    printf("Enter numbers, 0 to skip note\n");
    while(1){
        int new;
        scanf("%d",&new);
        seq[i]=new;
        i++;
        if(new == 0){
        count++;
        if(count==2){
            break;
        } 
    }
    }
    
    Node *list = buildListStructure(seq);
    printListStructure(list);
    freeMemory(list);

    return 0;
}