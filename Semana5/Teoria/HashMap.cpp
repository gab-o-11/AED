

template<typename T, typename T2>
struct HashItem {
    T key;
    T2* value;
    HashItem(){}
};

template<typename T,typename T2>
class HashTable {
private:
    HashItem<T,T2> item;
public:
    HashTable(){}
    void HashFunction() {

    }
    ~HashTable(){}
};