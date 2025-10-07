#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

// todo : implement quicksort for arrays, convert hashtable to array first

// convert hashtable to arr
HashTable* con_hashtable_arr(HashTable* hashtable){
    HashTable* hash_arr;
    int c = 0;
    for(int i = 0; i < TABLE_SIZE; i++){
        Node* curr = hashtable->table[i];
        while(curr){
            hash_arr->table[c] = curr;
            c++;
        }
    }
    return hash_arr;
}

// swaps Nodes
void swap_node(Node* a, Node* b) {
    Node tmp = *a;
    *a = *b;
    *b = tmp;
}


int partition(HashTable* hashtable, int high, int low){
    int p = hashtable->table[low];
    int i = low;
    int j = high;


     while (i < j) {

        // Find the first element greater than
        // the pivot (from starting)
        while (hashtable->table[i] <= p && i <= high - 1) {
            i++;
        }

        // Find the first element smaller than
        // the pivot (from last)
        while (hashtable->table[j] > p && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(hashtable->table[i], hashtable->table[j]);
        }
    }

    swap(hashtable->table[low], hashtable->table[j]);
    return j;
}


void quickSort_hashtable(HashTable* hashtable, int low, int high) {
    if (low < high) {

        // call partition function to find Partition Index
        int pi = partition(hashtable, low, high);

        // Recursively call quickSort() for left and right
        // half based on Partition Index
        quickSort_hashtable(hashtable, low, pi - 1);
        quickSort_hashtable(hashtable, pi + 1, high);
    }
}