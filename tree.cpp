#include <iostream>

struct treeNode{
    int data;
    struct treeNode* parent;
    struct treeNode* left;
    struct treeNode* right;
};

typedef struct treeNode* TREENODEPTR;

TREENODEPTR getTreeNode(){
    TREENODEPTR p;
    p = (TREENODEPTR)malloc(sizeof(struct treeNode));
    return p;
}

TREENODEPTR initTree(int root){
    TREENODEPTR p;
    p = getTreeNode();
    p->data = root;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void setLeft(TREENODEPTR p, int data){
    if(p == NULL){
        printf("void insertion\n");
        exit(1);
    } else if(p->left != NULL){
        printf("invalid insertion\n");
        exit(1);
    } else {
        p->left = initTree(data);
    }
}

void setRight(TREENODEPTR p, int data){
    if(p == NULL){
        printf("void insertion\n");
        exit(1);
    } else if(p->right != NULL){
        printf("invalid insertion\n");
        exit(1);
    } else {
        p->right = initTree(data);
    }
}

//Tarama
//DLR
void preorderTrav(TREENODEPTR root){
    if(root != NULL){
        printf("%d\n", root->data);
        preorderTrav(root->left);
        preorderTrav(root->right);
    }
}

//LDR
void inorderTrav(TREENODEPTR root){
    if(root != NULL){
        preorderTrav(root->left);
        printf("%d\n", root->data);
        preorderTrav(root->right);
    }
}

//LRD
void postorderTrav(TREENODEPTR root){
    if(root != NULL){
        preorderTrav(root->left);
        preorderTrav(root->right);
        printf("%d\n", root->data);
    }
}

//Girilen sayilari binary tree'ye yerlestiren kod
int main(){
    TREENODEPTR ptree, p, q;
    int number;

    scanf("%d", &number);
    ptree = initTree(number);
    while(scanf("%d", &number) != EOF){
        p = q = ptree;
        while(number != p->data && q!= NULL){
            p = q;
            if(number < p->data){
                q = p->left;
            } else {
                q = p->right;
            }
        }

        if(number == p->data){
            printf("%d is duplicate\n", number);
        } else if(number < p ->data){
            setLeft(p, number);
        } else {
            setRight(p, number);
        }
    }
    return 0;
}