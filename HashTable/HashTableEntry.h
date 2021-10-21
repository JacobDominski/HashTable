#pragma once
#include <iostream>
#include <string>

using namespace std;

struct HashTableEntry {
    int k;
    string v;
    HashTableEntry* n;

    HashTableEntry(int k, string v) {
        this->k = k;
        this->v = v;
        this->n = nullptr;
    }
}