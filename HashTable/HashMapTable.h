#pragma once
#include "HashTableEntry.h"

using namespace std;

const int T_S = 200;

class HashMapTable {
public:
    HashTableEntry** ht, ** top;
    HashMapTable();
    int HashFunc(int key);
    void Insert(int k, string, v);
    void SearchKey(int k);
    void Remove(int k);
    ~HashMapTable();
};