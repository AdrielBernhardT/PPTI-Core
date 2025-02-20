#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student{
    int id;
    char name[101];
    struct Student *next, *prev;
};

struct Student* CreateNewStudent(int id, const char *name){
    Student *newStudent = (struct Student*)malloc(sizeof(struct Student));
    (newStudent)->id = id;
    strcpy((newStudent)->name, name);
    (newStudent)->next = NULL;
    (newStudent)->prev = NULL;
    return newStudent;
}

struct Student *insert(struct Student *root, int id, const char *name){
    if(root == NULL){
        return CreateNewStudent(id, name);
    }
    if(id > root->id){
        root->next = insert(root->next, id, name);
    }else{
        root->prev = insert(root->prev, id, name);
    }
    return root;
}

void inorder(struct Student *root){
    if(root == NULL){
        return;
    }
    inorder(root->prev); // Kiri
    printf("%d %s\n", root->id, root->name); // Print
    inorder(root->next); // Kanan
}

void postorder(struct Student *root){
    if(root == NULL){
        return;
    }
    postorder(root->prev); // Kiri
    postorder(root->next); // Kanan
    printf("%d %s\n", root->id, root->name); // Print
}

void preorder(struct Student *root){
    if(root == NULL){
        return;
    }
    printf("%d %s\n", root->id, root->name); // Print
    preorder(root->prev); // Kiri
    preorder(root->next); // Kanan
}

struct Student *search(struct Student *root, int id){
    if(root == NULL){
        printf("Not Found\n");
        return NULL;
    } 
    if(root->id == id){
        puts("Found");
        return root;
    } else if(id > root->id){
        return search(root->next, id);
    }else{
        return search(root->prev, id);
    }
}

struct Student *update(struct Student *root, int id, const char *newName){
    if(root == NULL){
        printf("Not Found\n");
        return NULL;
    } 
    if(root->id == id){
        puts("Found");
        strcpy(root->name, newName);
        return root;
    } else if(id > root->id){
        return update(root->next, id, newName);
    }else{
        return update(root->prev, id, newName);
    }
}

int main(){
    struct Student *root = NULL;

    puts("Inserting...\n");
    // Insert
    root = insert(root, 5, "Anto");
    root = insert(root, 10, "Budi");
    root = insert(root, 3, "Caca");
    root = insert(root, 13, "Dedi");
    root = insert(root, 1, "Elos");

    puts("Traversal...\n");
    // inorder traversal
    inorder(root);
    // Search
    struct Student *searchStudent = search(root, 10);
    if (searchStudent != NULL){
        printf("ID: %d\nName: %s\n\n", searchStudent->id, searchStudent->name);
    }
    // preorder traversal
    preorder(root);
    // Update
    struct Student *updateStudent = update(root, 10, "Budi Santoso");
    // postorder traversal
    postorder(root);

    return 0;
}

/*
// Preorder
1. print
2. left
3. right

// postorder
1. left
2. right
3. print
*/