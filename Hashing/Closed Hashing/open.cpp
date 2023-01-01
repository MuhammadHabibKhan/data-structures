#include <iostream>
#include <string>

using namespace std;
int groupSize = 2;
int prime_numbers[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

class item{
    public:
        int key;
        string value;
        // constructor
        item(int k, string v){
            this->key = k;
            this->value = v;
        }
};

class HashTable{
    private:
        item** table;
    public:
        //constructor
        HashTable(){
            table = new item* [groupSize]{NULL};
        }
        int hashFunction(int key){
            return key % groupSize;
        }
        void insertItem(int k, string v){
            this->reHashing();
            int hashValue = hashFunction(k);
            //group not empty and key found not the same so do collision handling
            while (table[hashValue] != NULL && table[hashValue]->key != k){
                cout << "Collision Handling" << endl;
                hashValue = hashFunction(hashValue + 1);
                //+1 yields the next index (linear probing)
            }
            //not empty and key same so delete and replace
            if (table[hashValue] != NULL){
                cout << "Key Exists. Value Replaced" << endl;
                delete table[hashValue];
            }
            table[hashValue] = new item(k, v);
            cout << "Item Inserted" << endl;
        }
        string searchItem(int k){
            int hashValue = hashFunction(k);
            while (table[hashValue] != NULL && table[hashValue]->key != k){
                hashValue = hashFunction(hashValue+1);
                //automatically circulates as mod repeates the values after max
            }
            if (table[hashValue] == NULL){
                cout << "Key not found" << endl;
                return "NULL";
            }
            else return table[hashValue]->value;
        }
        void removeItem(int k){
            int hashValue = hashFunction(k);
            while (table[hashValue] != NULL){
                if (table[hashValue]->key == k)
                    break;
                hashValue = hashFunction(hashValue + 1);
            }
            if (table[hashValue] == NULL){
                cout << "Item not found" << endl;
                return;
            }
            else{
                delete table[hashValue];
                table[hashValue] = NULL;
            }
            cout << "Item Deleted" << endl;
        }
        void printTable(){
            for (int i{}; i<groupSize; i++){
                if (table[i] == NULL) continue;
                cout << "Key: " << table[i]->key << " | Value: " << table[i]->value << endl;
            }
        }
        float calculateLoad(){
            int count{};
            for (int i{}; i<groupSize; i++){
                if (table[i] != NULL){
                    count++;
                }  
            }
            float load = float(count)/(groupSize);
            cout << "load: " << load << endl;
            return load;
        }
        void reHashing(){
            float load = this->calculateLoad();
            if (load < 0.5) return;
            int size = groupSize * 2;
            int size_temp = groupSize;
            for (int i{}; i < 25; i++){
                if (prime_numbers[i] > size){
                    int lower = prime_numbers[i-1];
                    int upper = prime_numbers[i];
                    int diff_lower = abs(lower-size);
                    int diff_upper = abs(upper-size);
                    if (diff_lower > diff_upper) groupSize = upper;
                    else groupSize = lower;
                    break;
                }
            }
            item** new_table = new item* [groupSize]{NULL};
            for (int i{}; i<size_temp; i++){
                if (table[i] != NULL){
                    int k = table[i]->key;
                    string v = table[i]->value;
                    new_table[i] = new item(k, v);
                    //new_table[i]->value = v;
                }
            }
            //this->~HashTable();
            delete[] table;
            table = new_table; 
        }
        //destructor
        ~HashTable(){
            for (int i{}; i<groupSize; i++){
                if (table[i] != NULL) delete table[i];
            }
            delete[] table;
        }
};


int main(){
    HashTable HT;
    HT.insertItem(900,"Habib");
    //HT.insertItem(900,"Areefa");
    HT.insertItem(901,"Maham");
    HT.insertItem(902,"Abdullah");
    //string i = HT.searchItem(901);
    //cout << i << endl;
    //HT.removeItem(901);
    // i = HT.searchItem(901);
    // cout << i << endl;
    // HT.removeItem(910);
    cout << "---------------------------" << endl;
    HT.printTable();
    cout << "---------------------------" << endl;
    return 0;
}