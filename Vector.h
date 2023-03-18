#pragma once
const int DEFAULT_VECTOR_SIZE = 10;
template<typename T>
class Vector
{
private:
    int size; // holds size of vector
    int capacity; // holds capacity of vector
    T* elements; // hold element of vector

public:
    Vector() {
        size = 0;
        capacity = DEFAULT_VECTOR_SIZE;
        elements = new T[DEFAULT_VECTOR_SIZE];
    }                       // Vector<float> v;
    Vector(int n, const T& value) {
        size = n;
        capacity = n * 2;
        elements = new T[capacity]; // just like malloc.

        for (int i = 0; i < size; i++)
        {
            elements[i] = value; // by doing that we set all value in vector for a specific T;
        }

    }  // Vector<float> v(10,0);
    // Copy another vector to this new instance using constructor.
    Vector(const Vector& rhs) {
        size = rhs.size;
        capacity = rhs.capacity;
        elements = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            elements[i] = rhs.elements[i];
        }


    }      // Vector<float> v(W); --holds another vector

    ~Vector() {
        delete[] elements; // free in C language so we do not have a memory leak.
    }

    // getters
    int Size() const {
        return size;
    }               // v.Size();
    int Capacity() const {
        return capacity;
    }            // v.Capacity();
    bool IsEmpty() const {
       
        return size == 0 ? "False" : "True";
       
    }             // v.IsEmpty();

    // Operators
    // if we do not return anything and modify anything then we should add 2 const.
    T& operator [](int index) {
        return elements[index];
    }                 // v[i] = x;  -- modifying
    const T& operator[](int index) const {
        return elements[index];
    }   //   x = v[i];
    Vector& operator=(const Vector& rhs) {
    
        if (rhs.size > size)
        {
            delete[] elements;
            capacity = rhs.size * 2;
            elements = new T[capacity];
        }
        for (int i = 0; i < rhs.size; i++)
        {
            elements[i] = rhs.elements[i];
        }
        size = rhs.size;
        return *this;
    
    
    }     //   v = w;

        // Methods
        void PushBack(const T& object)
    {
        if (size == capacity)
        {
            T* newArr = new T[capacity * 2];
            for (int i = 0; i < size; i++)
            {
                newArr[i] = elements[i];
            }
            delete[] elements;
            elements = newArr;
            capacity = capacity * 2;

        }
        elements[size] = object;
        size++;
    }           // v.Pushback("A");
    void PopBack() {
        if(size > 0 ) size--; // ex : 8 becomes 7.
    }                             // v.Popback();
    void Erase(int index) {
        if (size > 0)
        {
            for (int i = index; i < size - 1; i++)
            {
                elements[i] = elements[i + 1]; // shifting from left to right then do size--
            }
            size--; // if we want to delete 3th element, then we loopping from 3 to size of the vector making shifting.
            // by deleting index and we do size-- ex: 3,4,5,6 = 4,5,6,0 and size-- so 4,5,6

        }
    }                     // v.Erase(0);
    void Insert(int index, T value); // Exercise!            // v.Insert(0,"A");
    void Clear() {
        size = 0; // it is enough to clear all data.
    }                              // v.Clear();


};



