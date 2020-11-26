#include <iostream>

/**
 * 	QUEUE DEFINITION
 * --------------------------------------------------
 */
#define MAXSIZE 100
#define INT 1
#define FLOAT 2
#define STRING 3

//		Queue'ya eklenecek her elementin birbirinden bagimsiz veri
//	tipine sahip olmasini saglar
struct queueElement{
	int type;
	union{
		int iVal;
		float fVal;
		char *pVal;
	} element;
};

struct queue{
	int front;
    int rear;
	struct queueElement* elements = new queueElement[MAXSIZE];
};
/**
 * 	--------------------------------------------------
 */

/**
 * 	UTILITY FUNCTIONS
 * 	--------------------------------------------------
 */
//		Eger queue'nun baslangıcı ve sonu -1'e esit ise queue bos demektir
//	Bu -1 degeri, queue olusturuldugu zaman atanmalıdır
//	OOP kullanılsaydı constructor ile bu islem yapilabilirdi.
int isEmpty(struct queue* q){
	if(q->front == -1 && q->rear == -1){
		return 1;
	}

	return 0;
};

//		Array indisi 0'dan basladigi icin queue'nun arkasi
// 	maksimum boyuttan 1 eksik ise queue dolu demektir.
int isFull(struct queue* q){
	if(q->rear == MAXSIZE -1){
		return 1;
	}

	return 0;
}

/**
 * 	CREATE
 * --------------------------------------------------
 */
//		Queue'ya integer deger ekleme
void enqueueInt(struct queue* q, int data){
	if(isFull(q)){
        printf("Queue overflow");
        exit(1);
    } else if(isEmpty(q)){
        q->rear = 0;
        q->front = 0;
    } else {
        q->rear++;
    }

    q->elements[q->rear].type=1;
	q->elements[q->rear].element.iVal = data;
};

//		Queue'ya float deger ekleme
void enqueueFloat(struct queue* q, float data){
	if(isFull(q)){
        printf("Queue overflow");
        exit(1);
    } else if(isEmpty(q)){
        q->rear = 0;
        q->front = 0;
    } else {
        q->rear++;
    }

    q->elements[q->rear].type=2;
	q->elements[q->rear].element.fVal = data;
};

//		Queue'ya pointer kullanarak char deger ekleme
void enqueueChar(struct queue* q, char* data){
	if(isFull(q)){
        printf("Queue overflow");
        exit(1);
    } else if(isEmpty(q)){
        q->rear = 0;
        q->front = 0;
    } else {
        q->rear++;
    }

    q->elements[q->rear].type=3;
	q->elements[q->rear].element.pVal = data;
};
/**
 * 	--------------------------------------------------
 */


/**
 * 	READ
 * 	--------------------------------------------------
 */
//		Queue'daki herhangi bir elemani dondurur (return eder)
//	Daha sonra printQueueElement fonksiyonu kullanılarak bu eleman
//	ekrana yazdırılabilir.
queueElement peek(struct queue*q, int position){
	if(isEmpty(q)){
		printf("Queue underflow\n");
		exit(1);
	}

	return q->elements[position];
}

//		Herhangi bir stack elementini ekrana yazdirma
void printQueueElement(queueElement *qe){
	switch(qe->type){
		case 1:
			printf("%d ", qe->element.iVal);
			break;
		case 2:
			printf("%f ", qe->element.fVal);
			break;
		case 3:
			printf("%s ", qe->element.pVal);
			break;
	}
};

void printAllQueueElements(struct queue*q){
	if(isEmpty(q)){
		printf("Queue underflow");
		exit(1);
	} else {
		for(int i = q->front; i <= q->rear; i++){
			printQueueElement(&(q->elements[i]));
		}
	}
}
/**
 * 	--------------------------------------------------
 */


/**
 * 	UPDATE
 * 	--------------------------------------------------
 */
//		Queue'daki herhangi bir elemanı yeni bir integer degeri
//	kullanarak guncelleme
void updateQueueElementWithInt(struct queue*q, int position, int newInt){
	q->elements[position].type = 1;
	q->elements[position].element.iVal = newInt;
}

//		Queue'daki herhangi bir elemanı yeni bir float degeri
//	kullanarak guncelleme
void updateQueueElementWithFloat(struct queue*q, int position, float newFloat){
	q->elements[position].type = 2;
	q->elements[position].element.fVal = newFloat;
}

//		Queue'daki herhangi bir elemanı yeni bir char pointer degeri
//	kullanarak guncelleme
void updateQueueElementWithChar(struct queue*q, int position, char* newCharPointer){
	q->elements[position].type = 3;
	q->elements[position].element.pVal = newCharPointer;
}
/**
 *	--------------------------------------------------
 */


/**
 * 	DELETE
 * 	--------------------------------------------------
 */
//		Queue'nun başında yer alan (front) elemani queue'dan silme
// 	Bu fonksiyon ayrica deger olarak silinen elemani dondurur
queueElement dequeue(struct queue* q){
    queueElement qe;
	if(isEmpty(q)){
		printf("Queue underflow\n");
		exit(1);
	} else if(q->front == q->rear){
        //There is only 1 element in queue
        qe = q->elements[q->front]; // OR q->elements[q->rear]
        //Queue should be empty after dequeueing
        q->front = -1;
        q->rear = -1;
    } else {
        //There are multiple elements in queue
        qe = q->elements[q->front];
        q->front++;
    }

    return qe;
};
/**
 * 	--------------------------------------------------
 */

/**
 * 	MENU FUNCTIONS
 * 	--------------------------------------------------
 */
void printMenu(){
	printf("\n\nWhat operation do you want to perform? Enter 0 to exit.\n");
	printf("1. Enqueue (Add new element to queue)\n");
	printf("2. Dequeue (Remove first element from queue)\n");
	printf("3. Check if queue is empty\n");
	printf("4. Check if queue is full\n");
	printf("5. View how many elements are in the queue\n");
	printf("6. View all elements in the queue\n");
}

int main(){
	//Bos stack olustur
	struct queue q;
    q.rear = -1;
    q.front = -1;

	//Menu
	int option = -1;
	do
	{
		printMenu();
		scanf(" %d", &option);
		switch (option)
		{
			case 1: {
				int typeOption = -1;
				printf("What type of data do you want to add to queue?\n");
				printf("1. Integer\n");
				printf("2. Float\n");
				printf("3. Char\n");
				scanf(" %d", &typeOption);
				if(typeOption == 1){
					//Int
					int iInput;
					printf("Enter an integer to add to queue:");
					scanf(" %d", &iInput);
					enqueueInt(&q, iInput);
					break;
				} if(typeOption == 2){
					//Float
					float fInput;
					printf("Enter a float to add to queue:");
					scanf(" %f", &fInput);
					enqueueFloat(&q, fInput);
					break;
				} if(typeOption == 3){
					//Char
					char pInput[256];
					printf("Enter a char to add to queue:");
					scanf(" %s", pInput);
					printf(pInput);
					enqueueChar(&q, pInput);
					break;
				} else {
					printf("invalid input");
					break;
				}
			}
			case 2: {
				struct queueElement qeToRemove = dequeue(&q);
				printf("Following element has been removed from queue:\n");
				printQueueElement(&qeToRemove);
				break;
			}
			case 3: {
				if(isEmpty(&q)){
					printf("Queue is empty");
					break;
				} else {
					printf("Queue is not empty");
					break;
				}
			}
			case 4: {
				if(isFull(&q)){
					printf("Queue is full");
					break;
				} else {
					printf("Queue is not full");
					break;
				}
			}
			case 5:{
				printf("There are %d elements in the stack", (q.rear - q.front) + 1);
				break;
			}
			case 6:{
				printAllQueueElements(&q);
				break;
			}
		}
	} while (option != 0);

	return 0;
}