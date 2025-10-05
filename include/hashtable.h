#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include "filing.h"

#define TABLE_SIZE 10

typedef struct{
    char* key;
    int val;
    Node* next;
} Node;

typedef struct{
    Node* table[TABLE_SIZE];
} HashTable;

unsigned int hash(unsigned char *str);

Node *create_node(const char* key, int val);

HashTable *init_hashtable();

void insert_hashtable(HashTable* hashtable, char* key, int val);

int *find_hashtable(HashTable* hashtable, const char *key);

void find_inc_hashtable(HashTable* hashtable, const char *key);

void free_hashtable(HashTable* hashtable);

HashTable* create_hashtable(char* file_name);



#endif