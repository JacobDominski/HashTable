#include "HashMapTable.h"


int main() {
    HashMapTable hash;
    int k;
    string v;
    int c;
    while (1) {
        cout << "1.Insert element into the table" << endl;
        cout << "2.Search element from the key" << endl;
        cout << "3.Delete element at a key" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> c;
        switch (c) {
        case 1:
            cout << "Enter element to be inserted: ";
            cin >> v;
            cout << "Enter key at which element to be inserted: ";
            cin >> k;
            hash.Insert(k, v);
            break;
        case 2:
            cout << "Enter key of the element to be searched: ";
            cin >> k;
            hash.SearchKey(k);
            break;
        case 3:
            cout << "Enter key of the element to be deleted: ";
            cin >> k;
            hash.Remove(k);
            break;
        case 4:
            exit(1);
        default:
            cout << "\nEnter correct option\n";
        }
    }
    return 0;
}