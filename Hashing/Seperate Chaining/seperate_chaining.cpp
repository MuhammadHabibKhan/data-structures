#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int groupSize = 2;
int prime_numbers[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

class item{
    public:
        int key;
        string value;
        item* next{};
        item* head{};
        // constructor
        item(int k, string v){
            this->key = k;
            this->value = v;
            this->next = NULL;
            this->head = NULL;
        }
        //int givePrime(int n);
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

        int givePrime(int n){
            bool isPrime;
            if (n == 0 || n == 1)
                isPrime = false;
            for (int i=2; i<=(n/2); ++i){  // n = 7 ,i = 2, 2<3, 
                if (n%i == 0)
                    isPrime = false;
                else{
                    isPrime = true;
                }
            }
            if (isPrime == true)
                return n;
            else{
                return givePrime(n+1);
            }
        }

        void insertItem(int k, string v){
            this->reHashing();
            int hashValue = hashFunction(k);

            if (table[hashValue] == NULL){
                table[hashValue] = new item(k, v);
                table[hashValue]->head = table[hashValue];
                cout << "Item Inserted" << endl;
                return;
            }

            bool keyExists = false;
            item* temp = table[hashValue]->head;
            item* temp_extra;
            while (temp != NULL){
                if (temp->key == k){
                    keyExists = true;
                    temp->value = v;
                    cout << "Key Exists. Value Replaced" << endl;
                    break;
                }
                if (temp->next == NULL){
                    temp_extra = temp;
                }
                temp = temp->next;
            }
            if (!keyExists){
                temp_extra->next = new item(k, v);
                //cout << table[hashValue]->next;
                cout << "Linked List Append " << endl;
            }
        }

        string searchItem(int k){
            int hashValue = hashFunction(k);
            
            if (table[hashValue] == NULL){
                cout << "Key does not exist" << endl;
                return "NULL";
            }
            item* temp = table[hashValue]->head;
            while (temp != NULL){
                if (temp->key == k){
                    cout << "Key found" << endl;
                    return temp->value;
                }
                else if (temp->key != k){
                    temp = temp->next;
                }
            }
            cout << "Key does not exist" << endl;
            return "NULL";
        }
        void removeItem(int k){
            int hashValue = hashFunction(k);

            if (table[hashValue] == NULL){
                cout << "Key does not exist. Item not removed" << endl;
                return;
            }
            bool keyExists = false;
            item* temp = table[hashValue]->head;
            item* temp2 = table[hashValue]->head;
            while (temp != NULL){
                if (temp->key == k){
                    if (temp == table[hashValue]->head){
                        item* t = table[hashValue]->head;
                        table[hashValue]->head = table[hashValue]->next;
                        delete t;
                        return;
                    }
                    keyExists = true;
                    item* t = temp; 
                    //item* t2 = t->next;
                    temp2->next = temp->next;
                    delete t;
                    cout << "Item found and Deleted!" << endl;
                    return;
                }
                temp2 = temp;
                temp = temp->next;
            }
            // if (temp->key == k){
            //     keyExists = true;
            //     item* t = temp->next;
            //     temp->next = t->next;
            //     delete t;
            //     cout << "Item Found and Deleted!" << endl;
            // }
            if (!keyExists){
                cout << "Key does not exist. Item not removed" << endl;
            }

        }
        void printTable(){
            for (int i{}; i<groupSize; i++){
                if (table[i] == NULL) continue;
                item* temp = table[i]->head;
                while(temp != NULL){
                    cout << "Key: " << temp->key << " | Value: " << temp->value << endl;
                    temp = temp->next;
                }
            }
        }
        float calculateLoad(){
            vector<int> maxCount;

            for (int i{}; i<groupSize; i++){
                int count{};
                if (table[i] == NULL) continue;
                item* temp = table[i]->head;
                while(temp != NULL){
                    count++;
                    temp = temp->next;
                }
                maxCount.push_back(count);
            }
            if (maxCount.size() == 0) return 0.1;
            auto it = max_element(begin(maxCount), end(maxCount));
            float load = float(*it)/(groupSize);
            cout << "load: " << load << endl;
            return load;
        }
        void reHashing(){
            float load = this->calculateLoad();
            if (load < 1) return;
            int size = groupSize * 2;
            //int size_temp = groupSize;
            int size_temp{};
            for (int i{}; i < 25; i++){
                if (prime_numbers[i] > size){
                    int lower = prime_numbers[i-1];
                    int upper = prime_numbers[i];
                    int diff_lower = abs(lower-size);
                    int diff_upper = abs(upper-size);
                    if (diff_lower > diff_upper) size_temp = upper;
                    else size_temp = lower;
                    break;
                }
            }
            item** new_table = new item* [size_temp]{NULL};
            for (int i{}; i<groupSize; i++){
                if (table[i] == NULL) continue;
                item* temp = table[i]->head;
                item* new_temp;
                while (temp != NULL){
                    if (temp == table[i]->head){
                        int k = temp->key;
                        string v = temp->value;
                        new_table[i] = new item(k, v);
                        new_table[i]->head = new_table[i];
                        new_temp = new_table[i];
                    }
                    else{
                        new_temp->next = new item(temp->key, temp->value);
                        new_temp = new_temp->next;
                    }
                    temp = temp->next;
                }
            }
            this->~HashTable();
            groupSize = size_temp;
            //delete[] table;
            table = new_table; 
        }
        //destructor
        ~HashTable(){
            for (int i{}; i<groupSize; i++){
                if (table[i] == NULL) continue;
                item* temp = table[i]->head;
                while(temp != NULL){
                    item* temp2 = temp;
                    //if (temp2->next == NULL) break;
                    temp = temp->next;
                    delete temp2; 
                }
            }
            delete[] table;
        }
};


int main(){
    HashTable HT;
    HT.insertItem(900,"Habib");
    HT.insertItem(910,"Abdullah");
    HT.insertItem(920,"Maarib");
    //HT.calculateLoad();
    string i = HT.searchItem(910);
    cout << i << endl;
    HT.removeItem(920);
    //HT.calculateLoad();
    //HT.reHashing();
    //HT.calculateLoad();
    cout << "---------------------------" << endl;
    HT.printTable();
    cout << "---------------------------" << endl;
    return 0;
}