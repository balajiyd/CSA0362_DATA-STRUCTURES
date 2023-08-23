#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define PRIME 7

struct Node {
    int key;
    int value;
    struct Node *next;
};

struct HashTableLinearProbing {
    int key[TABLE_SIZE];
    int value[TABLE_SIZE];
};

struct HashTableChaining {
    struct Node *table[TABLE_SIZE];
};

struct HashTableDoubleHashing {
    int key[TABLE_SIZE];
    int value[TABLE_SIZE];
};

// Linear Probing
struct HashTableLinearProbing *createHashTableLinearProbing() {
    struct HashTableLinearProbing *hashTable = (struct HashTableLinearProbing *)malloc(sizeof(struct HashTableLinearProbing));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->key[i] = -1;
        hashTable->value[i] = -1;
    }
    return hashTable;
}

int hashFunctionLinearProbing(int key) {
    return key % TABLE_SIZE;
}

void insertLinearProbing(struct HashTableLinearProbing *hashTable, int key, int value) {
    int index = hashFunctionLinearProbing(key);

    while (hashTable->key[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }

    hashTable->key[index] = key;
    hashTable->value[index] = value;
}

int searchLinearProbing(struct HashTableLinearProbing *hashTable, int key) {
    int index = hashFunctionLinearProbing(key);

    while (hashTable->key[index] != -1) {
        if (hashTable->key[index] == key) {
            return hashTable->value[index];
        }
        index = (index + 1) % TABLE_SIZE;
    }

    return -1; // Not found
}

// Chaining
struct HashTableChaining *createHashTableChaining() {
    struct HashTableChaining *hashTable = (struct HashTableChaining *)malloc(sizeof(struct HashTableChaining));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

int hashFunctionChaining(int key) {
    return key % TABLE_SIZE;
}

void insertChaining(struct HashTableChaining *hashTable, int key, int value) {
    int index = hashFunctionChaining(key);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable->table[index];

    hashTable->table[index] = newNode;
}

int searchChaining(struct HashTableChaining *hashTable, int key) {
    int index = hashFunctionChaining(key);

    struct Node *current = hashTable->table[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    return -1; // Not found
}

// Double Hashing
struct HashTableDoubleHashing *createHashTableDoubleHashing() {
    struct HashTableDoubleHashing *hashTable = (struct HashTableDoubleHashing *)malloc(sizeof(struct HashTableDoubleHashing));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->key[i] = -1;
        hashTable->value[i] = -1;
    }
    return hashTable;
}

int hashFunctionDoubleHashing(int key, int attempt) {
    return (key % TABLE_SIZE + attempt * (PRIME - (key % PRIME))) % TABLE_SIZE;
}

void insertDoubleHashing(struct HashTableDoubleHashing *hashTable, int key, int value) {
    int attempt = 0;
    int index;

    do {
        index = hashFunctionDoubleHashing(key, attempt);
        if (hashTable->key[index] == -1) {
            hashTable->key[index] = key;
            hashTable->value[index] = value;
            return;
        }
        attempt++;
    } while (attempt < TABLE_SIZE);

    printf("HashTable is full, cannot insert.\n");
}

int searchDoubleHashing(struct HashTableDoubleHashing *hashTable, int key) {
    int attempt = 0;
    int index;

    do {
        index = hashFunctionDoubleHashing(key, attempt);
        if (hashTable->key[index] == key) {
            return hashTable->value[index];
        }
        attempt++;
    } while (hashTable->key[index] != -1 && attempt < TABLE_SIZE);

    return -1; // Not found
}

int main() {
    // Linear Probing
    struct HashTableLinearProbing *hashTableLinearProbing = createHashTableLinearProbing();
    insertLinearProbing(hashTableLinearProbing, 10, 100);
    insertLinearProbing(hashTableLinearProbing, 20, 200);
    int searchKeyLP = 20;
    int searchResultLP = searchLinearProbing(hashTableLinearProbing, searchKeyLP);
    if (searchResultLP != -1) {
        printf("Linear Probing: Value for key %d: %d\n", searchKeyLP, searchResultLP);
    } else {
        printf("Linear Probing: Key %d not found.\n", searchKeyLP);
    }

    // Chaining
    struct HashTableChaining *hashTableChaining = createHashTableChaining();
    insertChaining(hashTableChaining, 10, 100);
    insertChaining(hashTableChaining, 20, 200);
    int searchKeyChaining = 20;
    int searchResultChaining = searchChaining(hashTableChaining, searchKeyChaining);
    if (searchResultChaining != -1) {
        printf("Chaining: Value for key %d: %d\n", searchKeyChaining, searchResultChaining);
    } else {
        printf("Chaining: Key %d not found.\n", searchKeyChaining);
    }

    // Double Hashing
    struct HashTableDoubleHashing *hashTableDoubleHashing = createHashTableDoubleHashing();
    insertDoubleHashing(hashTableDoubleHashing, 10, 100);
    insertDoubleHashing(hashTableDoubleHashing, 20, 200);
    int searchKeyDH = 20;
    int searchResultDH = searchDoubleHashing(hashTableDoubleHashing, searchKeyDH);
    if (searchResultDH != -1) {
        printf("Double Hashing: Value for key %d: %d\n", searchKeyDH, searchResultDH);
    } else {
        printf("Double Hashing: Key %d not found.\n", searchKeyDH);
    }

    return 0;
}
38.	Hashing (All methods) 
