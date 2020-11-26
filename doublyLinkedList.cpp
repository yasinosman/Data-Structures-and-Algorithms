#include <iostream>

#define INT 1
#define FLOAT 2
#define STRING 3

/**
 * 	LINKED LIST NODE DEFINITION
 * --------------------------------------------------
 */
struct nodeElement{
     int type;

    union{
		int iVal;
		float fVal;
		char *pVal;
	} element;
};

struct node {
    struct nodeElement data;
    node* right;
    node* left;
};

//      Daha sonra kullanim kolayligi icin typedef 
typedef struct node* NODEPTR;

/**
 *  UTILITY FUNCTIONS
 *  --------------------------------------------------
 */
//      Bir dugum silme (Ram'i temizleme)
void freeNode(NODEPTR p){
    free(p);
}

//      Yeni bir dugum icin ram'de yer olusturma
NODEPTR getNode(){
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return p;
}


/**
 * 	CREATE
 * --------------------------------------------------
 */
//      Bir dugum ekleme
void insertAfter(NODEPTR p, nodeElement data){
    if (p == NULL) {
		printf("Void insertion\n");
		exit(1);
	}

    NODEPTR q, r;
	q = getNode();
    r = p->right;
    r->left = q;
    q->right = r;
    q->left = p;
    p->right = q;
}
/**
 *	--------------------------------------------------
 */

/**
 * 	READ
 * 	--------------------------------------------------
 */
NODEPTR searchInt(NODEPTR head, int dataToFind){
    NODEPTR p;
    for(p = head; p != NULL; p = p->right){
        if(p->data.element.iVal == dataToFind){
            return p;
        }
    }

    return NULL;
}

NODEPTR searchFloat(NODEPTR head, float dataToFind){
    NODEPTR p;
    for(p = head; p != NULL; p = p->right){
        if(p->data.element.fVal == dataToFind){
            return p;
        }
    }

    return NULL;
}

NODEPTR searchChar(NODEPTR head, char* dataToFind){
    NODEPTR p;
    for(p = head; p != NULL; p = p->right){
        if(p->data.element.pVal == dataToFind){
            return p;
        }
    }

    return NULL;
}

//      Butun node'ları yazdirma
void printAllNodes(NODEPTR p) {
	NODEPTR i = p;
	while (i != NULL) {
		printNode(&i->data);
		i = i->right;
	}
}

void printNode(nodeElement* ne){
    switch (ne->type)
	{
	case 1:
		printf("%d\n", ne->element.iVal);
		break;
	case 2:
		printf("%f\n", ne->element.fVal);
		break;
	case 3:
		printf("%s\n", ne->element.pVal);
		break;
	}
}
/**
 *	--------------------------------------------------
 */

/**
 * 	DELETE
 * 	--------------------------------------------------
 */
void deleteNode(NODEPTR p){
    if (p == NULL) {
		printf("Void deletion\n");
		exit(1);
	}

    NODEPTR q, r;
	q = p->left;
    r = p->right;
    q->right = r;
    r->left = q;
	freeNode(p);
}
/**
 *	--------------------------------------------------
 */


int main(){
    return 0;
}