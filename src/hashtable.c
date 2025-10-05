#include <stdio.h>
#include <stdlib.h>
#include "filing.h"



// Table size = number of lines of toxic_words.txt
// constant hence defined
#define TABLE_SIZE 10


// Node* next because linklist created and maintained incase of collision
// when key is hashed
typedef struct{
    char* key;
    int val;
    Node* next;
} Node;



// HashTable contains arr of node ptrs
// easier to create linklist and check for collisions
// all values initiliased to NULL when table created
typedef struct{
    Node* table[TABLE_SIZE];
} HashTable;

// http://www.cse.yorku.ca/~oz/hash.html
// djb2 hashing algorithm

unsigned int hash(unsigned char *str){
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash % TABLE_SIZE;
}


Node *create_node(const char* key, int val){

    // malloc used to created newnode
    // will need to free later
    // todo: create system to handle errors
    Node *newnode = malloc(sizeof(Node));
    if(!newnode){
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    newnode->key = key;
    newnode->val = val;
    newnode->next = NULL;
    return newnode;
}

HashTable *init_hashtable(){
    HashTable *hashtable = malloc(sizeof(HashTable));
    if(!hashtable){
        perror("malloc error while creating hashtable\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < TABLE_SIZE; i++){
        hashtable->table[i] = NULL;
    }
    return hashtable;
}

void insert_hashtable(HashTable* hashtable, char* key, int val){
    // hashes key to get index
    // checks if there is already an item in index
    // if there is nothing it just adds
    // else creates / maintains a linked list
    unsigned int index = hash(key);
    Node* head = hashtable->table[index];

    for(Node *curr = head; curr; curr = curr->next){
        if(strcmp(curr->key, key) == 0){
            curr->val = val;
            return;
        }
    }

    Node *newnode = create_node(key, val);
    newnode->next = head;
    hashtable->table[index] = newnode;
}

int *find_hashtable(HashTable* hashtable, const char *key){
    // returns reference to val of item so val can be changed
    unsigned int index = hash(key);
    for(Node* curr = hashtable->table[index]; curr; curr = curr->next){
        if(strcmp(curr->key, key) == 0){
            return &curr->val;
        }
    }
    return NULL;
}

void find_inc_hashtable(HashTable* hashtable, const char *key){
    // incremant val
    unsigned int index = hash(key);
    for(Node* curr = hashtable->table[index]; curr; curr = curr->next){
        if(strcmp(curr->key, key) == 0){
            curr->val++;
        }
    }
}

void free_hashtable(HashTable* hashtable){
    for(int i = 0; i < TABLE_SIZE; i++){
        Node* curr = hashtable->table[i];
        while(curr){
            Node *tmp = curr;
            curr = curr->next;
            free(tmp->key);
            free(tmp);
        }
    }

    free(hashtable);
}

HashTable* create_hashtable(char* file_name){
    // loads toxic.txt file and creates a hashtable

    FILE* fileptr = open_file(file_name);
    char buff[64];

    HashTable *hashtable = init_hashtable();
    while(fgets(buff, sizeof(buff), fileptr)){
        // todo remove chars(",/,\n, ,') from buff
        insert_hashtable(hashtable, buff, 0);   
    }

    return hashtable;
}