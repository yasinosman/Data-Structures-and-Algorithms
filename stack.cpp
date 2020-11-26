#include <iostream>

/**
 * 	STACK DEFINITION
 * --------------------------------------------------
 */
#define MAXSIZE 100
#define INT 1
#define FLOAT 2
#define STRING 3

//		Stack'e eklenecek her elementin birbirinden bagimsiz veri
//	tipine sahip olmasini saglar
struct stackElement{
	int type;
	union{
		int iVal;
		float fVal;
		char *pVal;
	} element;
};

struct stack{
	int top;
	struct stackElement* elements = new stackElement[MAXSIZE];
};
/**
 * 	--------------------------------------------------
 */

/**
 * 	UTILITY FUNCTIONS
 * 	--------------------------------------------------
 */
//		Eger stack'in en ustundeki element -1'e esit ise stack bos demektir
//	Bu -1 degeri, stack olusturuldugu zaman atanmalıdır
//	OOP kullanılsaydı constructor ile bu islem yapilabilirdi.
int isEmpty(struct stack* s){
	if(s->top == -1){
		return 1;
	}

	return 0;
};

//		Array indisi 0'dan basladigi icin stack'in en ustundeki elementin sirasi
// 	stack boyutundan 1 eksik ise stack dolu demektir.
int isFull(struct stack* s){
	if(s->top == MAXSIZE -1){
		return 1;
	}

	return 0;
}

/**
 * 	CREATE
 * --------------------------------------------------
 */
//		Stack'e integer deger ekleme
void pushIntToStack(struct stack* s, int data){
	if(isFull(s)){
		printf("Stack overflow\n");
		exit(1);
	}

	s->elements[++s->top].type = 1;
	s->elements[s->top].element.iVal = data;
};

//		Stack'e float deger ekleme
void pushFloatToStack(struct stack*s, float data){
	if(isFull(s)){
		printf("Stack overflow\n");
		exit(1);
	}
	s->elements[++s->top].type=2;
	s->elements[s->top].element.fVal = data;
};

//		Stack'e pointer kullanarak char deger ekleme
void pushCharToStack(struct stack*s, char* data){
	if(isFull(s)){
		printf("Stack overflow\n");
		exit(1);
	}

	s->elements[++s->top].type = 3;
	s->elements[s->top].element.pVal = data;
};
/**
 * 	--------------------------------------------------
 */


/**
 * 	READ
 * 	--------------------------------------------------
 */
//		Stack'teki herhangi bir elemani dondurur (return eder)
//	Daha sonra printStackElement fonksiyonu kullanılarak bu eleman
//	ekrana yazdırılabilir.
stackElement peek(struct stack*s, int position){
	if(isEmpty(s)){
		printf("Stack underflow\n");
		exit(1);
	}

	return s->elements[position];
}

//		Herhangi bir stack elementini ekrana yazdirma
void printStackElement(stackElement *se){
	switch(se->type){
		case 1:
			printf("%d \n", se->element.iVal);
			break;
		case 2:
			printf("%f \n", se->element.fVal);
			break;
		case 3:
			printf("%s \n", se->element.pVal);
			break;
	}
};

void printAllStackElements(struct stack*s){
	if(isEmpty(s)){
		printf("Stack underflow");
		exit(1);
	} else {
		for(int i = 0; i <= s->top; i++){
			printStackElement(&(s->elements[s->top - i]));
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
//		Stack'teki herhangi bir elemanı yeni bir integer degeri
//	kullanarak guncelleme
void updateStackElementWithInt(struct stack*s, int position, int newInt){
	s->elements[position].type = 1;
	s->elements[position].element.iVal = newInt;
}

//		Stack'teki herhangi bir elemanı yeni bir float degeri
//	kullanarak guncelleme
void updateStackElementWithFloat(struct stack*s, int position, float newFloat){
	s->elements[position].type = 2;
	s->elements[position].element.fVal = newFloat;
}

//		Stack'teki herhangi bir elemanı yeni bir char pointer degeri
//	kullanarak guncelleme
void updateStackElementWithChar(struct stack*s, int position, char* newCharPointer){
	s->elements[position].type = 3;
	s->elements[position].element.pVal = newCharPointer;
}
/**
 *	--------------------------------------------------
 */


/**
 * 	DELETE
 * 	--------------------------------------------------
 */
//		Stack'in en ustundeki elemani stack'den silme
// 	Bu fonksiyon ayrica deger olarak cikarilan elemani dondurur
stackElement popElementFromStack(struct stack* s){
	if(isEmpty(s)){
		printf("Stack underflow\n");
		exit(1);
	}

	return s->elements[s->top--];
};
/**
 * 	--------------------------------------------------
 */

//		Add singly linked list definition
struct node {
	struct stackElement data;
	node* next;
};
typedef struct node* NODEPTR;

NODEPTR getNode(){
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return p;
};

void insertAfter(NODEPTR p, stackElement data){
    if (p == NULL) {
		printf("Void insertion\n");
		exit(1);
	}

    NODEPTR q;
	q = getNode();
	q->data = data;
	q->next = p->next;
	p->next = q;
}

//      Butun node'ları yazdirma
void printAllNodes(NODEPTR p) {
	NODEPTR i = p;
	while (i != NULL) {
		printStackElement(&i->data);
		i = i->next;
	}
}

/**
 * 	MENU FUNCTIONS
 * 	--------------------------------------------------
 */
void printMenu(){
	printf("\n\nWhat operation do you want to perform? Enter 0 to exit.\n");
	printf("1. Push new element to stack\n");
	printf("2. Pop last element from stack\n");
	printf("3. Check if stack is empty\n");
	printf("4. Check if stack is full\n");
	printf("5. View a stack element\n");
	printf("6. View how many elements are in the stack\n");
	printf("7. Update a stack element\n");
	printf("8. View all items in the stack\n");
	printf("9. Move all the items to a singly linked list\n");
}

int main(){
	//Bos stack olustur
	struct stack s;
	s.top = -1;

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
				printf("What type of data do you want to push to stack?\n");
				printf("1. Integer\n");
				printf("2. Float\n");
				printf("3. Char\n");
				scanf(" %d", &typeOption);
				if(typeOption == 1){
					//Int
					int iInput;
					printf("Enter an integer to add to stack:");
					scanf(" %d", &iInput);
					pushIntToStack(&s, iInput);
					break;
				} if(typeOption == 2){
					//Float
					float fInput;
					printf("Enter a float to add to stack:");
					scanf(" %f", &fInput);
					pushFloatToStack(&s, fInput);
					break;
				} if(typeOption == 3){
					//Char
					char pInput[256];
					printf("Enter a char to add to stack:");
					scanf(" %s", pInput);
					printf(pInput);
					pushCharToStack(&s, pInput);
					break;
				} else {
					printf("invalid input");
					break;
				}
			}
			case 2: {
				struct stackElement seToPop = popElementFromStack(&s);
				printf("Following element has been popped:\n");
				printStackElement(&seToPop);
				break;
			}
			case 3: {
				if(isEmpty(&s)){
					printf("Stack is empty");
					break;
				} else {
					printf("Stack is not empty");
					break;
				}
			}
			case 4: {
				if(isFull(&s)){
					printf("Stack is full");
					break;
				} else {
					printf("Stack is not full");
					break;
				}
			}
			case 5: {
				int elementPosition = -1;
				printf("\nEnter the index of the element you wish to see:");
				scanf(" %d", &elementPosition);
				struct stackElement seToPeek = peek(&s, elementPosition);
				printStackElement(&seToPeek);
				break;
			}
			case 6:{

				printf("There are %d elements in the stack", s.top - 1);
				break;
			}
			case 7: {
				int updateTypeOption = -1;
				int updatePosition = -1;
				printf("\nWhich element do you wish to update?\n");
				scanf(" %d", &updatePosition);
				printf("What will be the type of the new data?\n");
				printf("1. Integer\n");
				printf("2. Float\n");
				printf("3. Char\n");
				scanf(" %d", &updateTypeOption);
				if(updateTypeOption == 1){
					//Int
					int iInput;
					printf("Enter an integer to change %d'th element of stack:", updatePosition);
					scanf(" %d", &iInput);
					updateStackElementWithInt(&s, updatePosition, iInput);
					break;
				} if(updateTypeOption == 2){
					//Float
					float fInput;
					printf("Enter a float to change %d'th element of stack:", updatePosition);
					scanf(" %f", &fInput);
					updateStackElementWithFloat(&s, updatePosition, fInput);
					break;
				} if(updateTypeOption == 3){
					//Char
					char pInput[256];
					printf("Enter a char to change %d'th element of stack:", updatePosition);
					scanf(" %s", pInput);
					printf(pInput);
					updateStackElementWithChar(&s, updatePosition, pInput);
					break;
				} else {
					printf("invalid input");
					break;
				}
			}
			case 8:{
				printAllStackElements(&s);
				break;
			}
			case 9:{
				NODEPTR head;
				head = getNode();

				head->data = popElementFromStack(&s);
				head->next = NULL;

				for(int i = 0; i <= s.top; i++){
					NODEPTR temp = NULL;
					temp = head;
					while (temp->next != NULL) {
						temp = temp->next;
					}
					insertAfter(temp, popElementFromStack(&s));
				};
				printAllNodes(head);
				break;
			}
		}
	} while (option != 0);

	return 0;
}