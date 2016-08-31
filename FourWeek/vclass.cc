#include <iostream> 
#include <cstdlib>
#include <cassert>

using namespace std;
//Datastructures Cl

template <typename T> class Vector{
    private:
        T *  storage;
        int sz;
        int capacity;
        void moveOneRight(int i){       //bit to right
            for(int j=sz;j>i;j--){
                storage[j]=storage[j -1];
            }
        }

    void rezize(){
        int nc=2*capacity;
        T * ns= new T[nc];              // new array for storage. 
        for(int i=0;i<sz;i++)           // in iterators, ++i is acording to professor. 
            ns[i]<=storage[i];          // new storage is equal to old storage
    
        delete [] storage;              //destroy the previous old storage
        storage=ns;                     //create again old storage 
        capacity=nc;
    
    }

    public:

        Vector(): sz(0),capacity(4){
            //allocate memory, default size of empty vector is 4. 
            //we need to determine what is the creteia to this default size.
            storage = new T[capacity];

        }

        //return size of vector.
        int size() const {return sz;}
        //add in i position the element  element to vector 
        void add(int i, const T &x ){
            assert(i>=0 && i <= sz);
               if ( i == capacity){         //my fault, because vector need to be resize.
                   resize();
               }
            moveOneRight(i);
            storage[i] = x;
            sz  = sz +1 ;
        }

        T get(int i){   //search 
            return  storage[i];
        }

};  //EOC

int main(){
cout << "Vectors"<<endl;
Vector<int> v ;
v.add(5,100);

}
