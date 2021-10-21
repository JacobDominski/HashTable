#include "HashMapTable.h"

using namespace std;

HashMapTable::HashMapTable() {
    ht = new HashTableEntry * [T_S];
    for (int i = 0; i < T_S; i++) {
        ht[i] = NULL;
    }
}

int HashMapTable::HashFunc(int key) {
    //hash algorithm
    return key % T_S;
}

void HashMapTable::Insert(int k, string v) {
    int hash_v = HashFunc(k);
    HashTableEntry* p = NULL;
    HashTableEntry* en = ht[hash_v];

    while (en != NULL) {
        p = en;
        en = en->n;
    }
    if (en == NULL) {
        en = new HashTableEntry(k, v);
        if (p == NULL) {
            ht[hash_v] = en;
        } else {
            p->n = en;
        }
    } else {
        en->v = v;
    }
}

void HashMapTable::SearchKey(int k) {
    int hash_v = HashFunc(k);
    bool flag = false;

    HashTableEntry* en = ht[hash_v];
    if(en != NULL) {
        while (en != NULL)  {
            if (en->k == k) {
                flag = true;
            }
            if ( flag ) {
                cout << "Element found at key " << k << ": " << en->v << endl;
            }
            en = en->n;
        }
    }
    if(!flag) {
        cout << "Element not found with key " << k << endl;
    }
}

HashMapTable::~HashMapTable() {
    delete[] ht;

}

void HashMapTable::Remove(int k) {
    int hash_v = HashFunc(k);
    HashTableEntry* en = ht[hash_v];
    HashTableEntry* p = NULL;
    if (en == NULL || en->k != k) {
        cout << "No Element found at key " << k << endl;
        return;
    }
    while (en->n != NULL) {
        p = en;
        en = en->n;
    }
    if (p != NULL) {
        p->n = en->n;
    }
    delete en;
    cout << "Element Deleted" << endl;
}