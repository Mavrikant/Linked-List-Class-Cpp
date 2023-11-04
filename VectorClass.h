#include<iostream>
using namespace std;

// Vector Class
template <class anyType>
class vector{
    private:
        anyType* data;
        int capacity;
        int index;
    public:
        vector(){
            capacity = 1;
            index = 0;
            data = NULL;
            data = new anyType[capacity];
        }
        int get_capacity()const{return capacity;}
        
        int get_index()const{return index;}

        void push_back(anyType var){
            if(index == capacity){
                int newCapacity = capacity * 2;
                anyType* tempData = new anyType[newCapacity];
                for(int i = 0 ; i < index ; i++){
                    tempData[i] = data[i];
                }
                delete[] data;
                data = tempData;
                capacity = newCapacity;
            }
            data[index] = var;
            index++;
        }

        void push_front(anyType var)
        {
            if(index == capacity)
            {
                int newCapacity = capacity * 2;
                anyType* tempData = new anyType[newCapacity];
                tempData[0] = var;
                for(int i = 0 ; i < index ; i++)
                {
                    tempData[i+1] = data[i];
                }
                delete[] data;
                data = tempData;
                capacity = newCapacity;
            }
            else
            {
                anyType* tempData = new anyType[capacity];
                tempData[0] = var;
                for(int i = 0 ; i < index ; i++)
                {
                    tempData[i+1] = data[i];
                }
                delete[] data;
                data = tempData;
            }
            index++;
        }

        void pop_back()
        {
            if(index != 0){
                index--;
            }
            if(index < capacity / 2){
                int newCapacity = capacity /2;
                if(newCapacity < 1){
                capacity = 1;
                }
                else{
                    anyType* tempData = new anyType[newCapacity];
                    for(int i = 0 ; i < index ; i++){
                        tempData[i] = data[i];
                    }
                    delete[] data;
                    data = tempData;
                    capacity = newCapacity;
                }
            }
        }

        bool isFind (anyType var){
            bool find = false;
            for(int i = 0 ; i < index ; i++){
               if(data[i] == var)
               {
                    find = true;
               }
            }
            return find;
        }

        void print_vector(){
            cout<<"Vector: "<<endl;
            for(int i = 0 ; i < index ; i ++){
                cout<<i<<". "<<data[i]<<endl;
            }
        }

        anyType getValueInIndex(int ind)
        {
            if(ind >= 0 && ind <= index - 1)
            {
                return data[ind];
            }
            else{
                return 0;
            }
        }

        anyType getFirstItem()
        {
            if(index > 0){
                return data[0];
            }
            else{return NULL;}
        }

        anyType getLastItem()
        {
            if(index > 0){
                return data[index-1];
            }
            else{return NULL;}
        }

        int sizeVector(){
            return sizeof(anyType)*index;
        }

        anyType* returnBeginAddress(){
            return data;
        }

        anyType* returnLastElementAddress(){
            return data + index;
        }

        void printWithAddress(){
            anyType* first = returnBeginAddress();
            anyType* last = returnLastElementAddress();
            while(first != last){
                cout<<*first<<endl;
                first++;
            }
        }

        anyType& indexValueChange(int ind){
            return data[ind];
        }

        void insertUsingIndex();

};
