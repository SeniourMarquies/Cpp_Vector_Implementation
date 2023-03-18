// Cpp_Vector_Implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "./Vector.h"


int main()
{
    Vector<float> v;
    v.PushBack(10);
    v.PushBack(20);
    v.PushBack(30);
    v.PushBack(40);
    v.PushBack(50);
    v.PushBack(60);
    v.PushBack(70);
    v.PushBack(80);
    v.PushBack(90);
    v.PushBack(100);
    v.PopBack();
    v.Erase(0);

    Vector<float> w = { 10,0 };

    for (int i = 0; i < v.Size(); i++)
    {
        std::cout << "items[" << i << "] = " << v[i] << std::endl;

    }
    std::cout << "Size = " << v.Size() << ", Capacity = " << v.Capacity() << std::endl;

    for (int i = 0; i < w.Size(); i++)
    {
        std::cout << "items[" << i << "] = " << w[i] << std::endl;

    }
    std::cout << "Size = " << w.Size() << ", Capacity = " << w.Capacity() << std::endl;

    w = v;
    for (int i = 0; i < w.Size(); i++)
    {
        std::cout << "items[" << i << "] = " << w[i] << std::endl;

    }
    std::cout << "Size = " << w.Size() << ", Capacity = " << w.Capacity() << std::endl;
    std::cout << "Let's empty vector. " << std::endl;
    v.Clear();
    std::cout << "is vector empty ? = " << w.IsEmpty() << std::endl;
  
}
