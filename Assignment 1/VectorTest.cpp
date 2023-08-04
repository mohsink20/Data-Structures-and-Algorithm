#include <iostream>

#include "Vector.h"

void TestDefaultConstructor();
void TestConstructorWithSize();
void TestConstructorWithSizeAndValue();
void TestCopyConstructor();
void TestAssignmentOperator();
void TestPushBack();
void TestPopBack();
void TestInsert();
void TestErase();
void TestClear();
void TestResize();
void TestReserve();
void TestException();


void TestDefaultConstructor()
{
    std::cout << "-- Testing Default Constructor --\n";
    Vector<int> vec;
    std::cout << "Size: " << vec.Size() << std::endl;
    std::cout << "Capacity: " << vec.Capacity() << std::endl;
    std::cout << "Is Empty: " << (vec.IsEmpty() ? "Yes" : "No") << std::endl;
}

void TestConstructorWithSize()
{
    std::cout << "-- Testing Constructor with Size --\n";
    Vector<int> vec(5);
    std::cout << "Size: " << vec.Size() << std::endl;
    std::cout << "Capacity: " << vec.Capacity() << std::endl;
    std::cout << "Is Empty: " << (vec.IsEmpty() ? "Yes" : "No") << std::endl;
}

void TestConstructorWithSizeAndValue()
{
    std::cout << "-- Testing Constructor with Size and Value --\n";
    Vector<int> vec(5, 10);
    std::cout << "Size: " << vec.Size() << std::endl;
    std::cout << "Capacity: " << vec.Capacity() << std::endl;
    std::cout << "Is Empty: " << (vec.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Elements: ";
    for (size_t i = 0; i < vec.Size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void TestCopyConstructor()
{
    std::cout << "-- Testing Copy Constructor --\n";
    Vector<int> vec1(5, 10);
    Vector<int> vec2(vec1);
    std::cout << "Original vector: ";
    for (size_t i = 0; i < vec1.Size(); ++i)
    {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Copied vector: ";
    for (size_t i = 0; i < vec2.Size(); ++i)
    {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;
}

void TestAssignmentOperator()
{
    std::cout << "-- Testing Assignment Operator --\n";
    Vector<int> vec1(5, 10);
    Vector<int> vec2;
    vec2 = vec1;
    std::cout << "Original vector: ";
    for (size_t i = 0; i < vec1.Size(); ++i)
    {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Assigned vector: ";
    for (size_t i = 0; i < vec2.Size(); ++i)
    {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;
}

void TestPushBack()
{
    std::cout << "-- Testing Push Back --\n";
    Vector<int> vec;
    vec.PushBack(1);
    vec.PushBack(2);
    vec.PushBack(3);
    std::cout << "Size: " << vec.Size() << std::endl;
    std::cout << "Capacity: " << vec.Capacity() << std::endl;
    std::cout << "Elements: ";
    for (size_t i = 0; i < vec.Size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void TestPopBack()
{
    std::cout << "-- Testing Pop Back --\n";
    Vector<int> vec(5);
    vec.PopBack();
    std::cout << "Size: " << vec.Size() << std::endl;
    std::cout << "Capacity: " << vec.Capacity() << std::endl;
    std::cout << "Is Empty: " << (vec.IsEmpty() ? "Yes" : "No") << std::endl;
}

void TestInsert()
{
    std::cout << "-- Testing Insert --\n";
    Vector<int> vec(3, 10);
    vec.Insert(5, 1);
    std::cout << "Size: " << vec.Size() << std::endl;
    std::cout << "Capacity: " << vec.Capacity() << std::endl;
    std::cout << "Elements: ";
    for (size_t i = 0; i < vec.Size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void TestErase()
{
    std::cout << "-- Testing Erase --\n";
    Vector<int> vec(5, 10);
    vec.Erase(2);
    std::cout << "Size: " << vec.Size() << std::endl;
    std::cout << "Capacity: " << vec.Capacity() << std::endl;
    std::cout << "Elements: ";
    for (size_t i = 0; i < vec.Size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void TestClear()
{
    std::cout << "-- Testing Clear --\n";
    Vector<int> vec(5, 10);
    vec.Clear();
    std::cout << "Size: " << vec.Size() << std::endl;
    std::cout << "Capacity: " << vec.Capacity() << std::endl;
    std::cout << "Is Empty: " << (vec.IsEmpty() ? "Yes" : "No") << std::endl;
}

void TestResize()
{
    std::cout << "-- Testing Resize --\n";
    Vector<int> vec(5, 10);
    vec.Resize(8);
    std::cout << "Size: " << vec.Size() << std::endl;
    std::cout << "Capacity: " << vec.Capacity() << std::endl;
    std::cout << "Elements: ";
    for (size_t i = 0; i < vec.Size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void TestReserve()
{
    std::cout << "-- Testing Reserve --\n";
    Vector<int> vec(5, 10);
    vec.Reserve(10);
    std::cout << "Size: " << vec.Size() << std::endl;
    std::cout << "Capacity: " << vec.Capacity() << std::endl;
    std::cout << "Elements: ";
    for (size_t i = 0; i < vec.Size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void TestException()
{
    std::cout << "-- Testing Exception Handling --\n";
    try
    {
        Vector<int> vec;
        vec.Erase(0);
    }
    catch (const std::exception& ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
    }
}

int main()
{
    TestDefaultConstructor();
    std::cout << std::endl;

    TestConstructorWithSize();
    std::cout << std::endl;

    TestConstructorWithSizeAndValue();
    std::cout << std::endl;

    TestCopyConstructor();
    std::cout << std::endl;

    TestAssignmentOperator();
    std::cout << std::endl;

    TestPushBack();
    std::cout << std::endl;

    TestPopBack();
    std::cout << std::endl;

    TestInsert();
    std::cout << std::endl;

    TestErase();
    std::cout << std::endl;

    TestClear();
    std::cout << std::endl;

    TestResize();
    std::cout << std::endl;

    TestReserve();
    std::cout << std::endl;

    TestException();

    return 0;
}

