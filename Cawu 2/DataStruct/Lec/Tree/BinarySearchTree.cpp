#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//  Declare Node
struct Node {
    char data;
    Node *left;
    Node *right;
};

// Create Node
Node *createNode(char value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//  Check if the character is an operator
int isOperator(char c){
    return(c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Infix tree
Node* buildInfixTree(char *InfixEquation, int *position){
    for (int i = 1; i < strlen(InfixEquation); i++){
        if (isOperator(InfixEquation[i])) {
            Node *root = createNode(InfixEquation[i]);
            root->left = createNode(InfixEquation[i-1]);
            root->right = createNode(InfixEquation[i+1]);
            return root;
            *position = i + 1;
            break;
        }
        
    }
}

// Postfix Tree
Node* buildPostfixTree(char *PostfixEquation){
    Node* stack[105];
    int top = -1;
    for (int i = 0; i < strlen(PostfixEquation); i++){
        Node *newNode = createNode(PostfixEquation[i]);
        if(isdigit(PostfixEquation[i])){
            stack[++top] = newNode;
        }else if (isOperator(PostfixEquation[i])) {
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
    }
    return stack[top];
}

// Prefix Tree
Node* buildPrefixTree(Node **root, char *PrefixEquation, int *position){
    if(*root == NULL){
        *root = createNode(PrefixEquation[*position]);
    }
    if(isOperator(PrefixEquation[*position])){
        *position = *position + 1;
        (*root)->left = createNode(PrefixEquation[*position]);
        buildPrefixTree(&((*root)->left), PrefixEquation, position);
        *position = *position + 1;
        (*root)->right = createNode(PrefixEquation[*position]);
        buildPrefixTree(&((*root)->right), PrefixEquation, position);
    }
    return *root;
}

// Infix
void inOrder(Node *root){
    if(root != NULL){
        if (isOperator(root->data)){
            putchar('(');
        }
        inOrder(root->left);
        printf("%c", root->data);
        inOrder(root->right);
        if (isOperator(root->data)){
            putchar(')');
        }
    }
}

// Prefix
void preOrder(Node *root){
    if(root != NULL){
        printf("%c ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Postfix
void postOrder(Node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%c ", root->data);
    }
}

// Hasil perhitungan
int evaluate(Node *root){
    if (root == NULL){
        return 0;
    }

    int left = evaluate(root->left);
    int right = evaluate(root->right);

    if(root->data == '+'){
        return left + right;
    } else if(root->data == '-'){
        return left - right;
    }else if(root->data == '*'){
        return left * right;
    }else if(root->data == '/'){
        return left / right;
    }else if(root->data == '^'){
        return pow(left, right);
    } else {
        return root->data - '0';
    }
}

int main(){
    char InfixEquation[105] = "3+2*5-4";
    char PostfixEquation[105] = "32+54-*";
    char PrefixEquation[105] = "*+32-54";

    int position = 0;
    // Infix
    Node *rootInfix = NULL;
    rootInfix = buildInfixTree(InfixEquation, &position);
    printf("Infix Result: %d\n", evaluate(rootInfix));
    inOrder(rootInfix);
    printf("\n");

    // Postfix
    Node* rootPostfix = buildPostfixTree(PostfixEquation);
    printf("\nPostfix Result: %d\n", evaluate(rootPostfix));
    postOrder(rootPostfix);
    printf("\n");

    position = 0;
    // Prefix
    Node* rootPrefix = buildPrefixTree(&rootPrefix, PrefixEquation, &position);
    printf("\nPrefix Result: %d\n", evaluate(rootPrefix));
    preOrder(rootPrefix);


    return 0;
}