/**
 * @class Vector
 * @brief
 *
 *
 *
 *
 * @author Mohsin Ali Khan
 * @version 02
 * @date 11/06/2023
 *
 * @bug No known bugs to the best of my knowledge
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T>
class Vector
{
private:
    T* m_data;           /**< Pointer to the dynamic array */
    size_t m_size;       /**< Number of elements in the vector */
    size_t m_capacity;   /**< Capacity of the vector */

public:
    /**
     * @brief Default constructor for the Vector class.
     */
    Vector();

    /**
     * @brief Constructor for the Vector class.
     * @param initialSize The initial size of the vector.
     */
    Vector(size_t initialSize);

    /**
     * @brief Constructor for the Vector class.
     * @param initialSize The initial size of the vector.
     * @param value The value to initialize all elements with.
     */
    Vector(size_t initialSize, const T& value);

    /**
     * @brief Copy constructor for the Vector class.
     * @param other The vector to be copied.
     */
    Vector(const Vector& other);

    /**
     * @brief Assignment operator for the Vector class.
     * @param other The vector to be assigned.
     * @return Reference to the assigned vector.
     */
    Vector& operator=(const Vector& other);

    /**
     * @brief Destructor for the Vector class.
     */
    ~Vector();

    /**
     * @brief Returns the number of elements in the vector.
     * @return The size of the vector.
     */
    size_t Size() const;

    /**
     * @brief Returns the capacity of the vector.
     * @return The capacity of the vector.
     */
    size_t Capacity() const;

    /**
     * @brief Checks if the vector is empty.
     * @return True if the vector is empty, false otherwise.
     */
    bool IsEmpty() const;

    /**
     * @brief Accesses the element at the specified index.
     * @param index The index of the element to access.
     * @return Reference to the element at the specified index.
     */
    T& operator[](size_t index) const;

    /**
     * @brief Adds an element to the end of the vector.
     * @param value The value to be added.
     */
    void PushBack(const T& value);

    /**
     * @brief Removes the last element from the vector.
     */
    void PopBack();

    /**
     * @brief Inserts an element at the specified position.
     * @param value The value to be inserted.
     * @param position The position at which the value should be inserted.
     */
    void Insert(const T& value, size_t position);

    /**
     * @brief Removes an element at the specified position.
     * @param position The position of the element to be removed.
     */
    void Erase(size_t position);

    /**
     * @brief Clears the vector.
     */
    void Clear();

    /**
     * @brief Resizes the vector to the specified size.
     * @param newSize The new size of the vector.
     */
    void Resize(size_t newSize);

    /**
     * @brief Resizes the capacity of the vector to accommodate a specified number of elements.
     * @param newCapacity The new capacity of the vector.
     */
    void Reserve(size_t newCapacity);

private:
    /**
     * @brief Copies the elements from the source vector to the destination vector.
     * @param source The source vector.
     * @param destination The destination vector.
     */
    void CopyElements(const Vector& source, Vector& destination);
};

template<typename T>
Vector<T>::Vector() : m_data(nullptr), m_size(0), m_capacity(0) {}

template<typename T>
Vector<T>::Vector(size_t initialSize) : m_data(nullptr), m_size(initialSize), m_capacity(initialSize)
{
    m_data = new T[m_capacity];
}

template<typename T>
Vector<T>::Vector(size_t initialSize, const T& value) : m_data(nullptr), m_size(initialSize), m_capacity(initialSize)
{
    m_data = new T[m_capacity];
    for (size_t i = 0; i < m_size; ++i)
    {
        m_data[i] = value;
    }
}

template<typename T>
Vector<T>::Vector(const Vector& other) : m_data(nullptr), m_size(other.m_size), m_capacity(other.m_capacity)
{
    m_data = new T[m_capacity];
    CopyElements(other, *this);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    if (this != &other)
    {
        Vector<T> temp(other);
        std::swap(m_data, temp.m_data);
        m_size = temp.m_size;
        m_capacity = temp.m_capacity;
    }
    return *this;
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] m_data;
}

template<typename T>
size_t Vector<T>::Size() const
{
    return m_size;
}

template<typename T>
size_t Vector<T>::Capacity() const
{
    return m_capacity;
}

template<typename T>
bool Vector<T>::IsEmpty() const
{
    return m_size == 0;
}

template<typename T>
T& Vector<T>::operator[](size_t index) const
{
    return m_data[index];
}

template<typename T>
void Vector<T>::PushBack(const T& value)
{
    if (m_size == m_capacity)
    {
        Reserve(m_capacity == 0 ? 1 : m_capacity * 2);
    }

    m_data[m_size] = value;
    ++m_size;
}

template<typename T>
void Vector<T>::PopBack()
{
    if (m_size > 0)
    {
        --m_size;
    }
}

template<typename T>
void Vector<T>::Insert(const T& value, size_t position)
{
    if (position > m_size)
    {
        throw std::out_of_range("Invalid position");
    }

    if (m_size == m_capacity)
    {
        Reserve(m_capacity == 0 ? 1 : m_capacity * 2);
    }

    for (size_t i = m_size; i > position; --i)
    {
        m_data[i] = m_data[i - 1];
    }

    m_data[position] = value;
    ++m_size;
}

template<typename T>
void Vector<T>::Erase(size_t position)
{
    if (position >= m_size)
    {
        throw std::out_of_range("Invalid position");
    }

    for (size_t i = position; i < m_size - 1; ++i)
    {
        m_data[i] = m_data[i + 1];
    }

    --m_size;
}

template<typename T>
void Vector<T>::Clear()
{
    m_size = 0;
}

template<typename T>
void Vector<T>::Resize(size_t newSize)
{
    if (newSize > m_capacity)
    {
        Reserve(newSize);
    }

    if (newSize > m_size)
    {
        for (size_t i = m_size; i < newSize; ++i)
        {
            m_data[i] = T();
        }
    }

    m_size = newSize;
}

template<typename T>
void Vector<T>::Reserve(size_t newCapacity)
{
    if (newCapacity > m_capacity)
    {
        Vector<T> temp(newCapacity);
        CopyElements(*this, temp);
        std::swap(m_data, temp.m_data);
        m_capacity = newCapacity;
    }
}

template<typename T>
void Vector<T>::CopyElements(const Vector& source, Vector& destination)
{
    for (size_t i = 0; i < source.m_size; ++i)
    {
        destination.m_data[i] = source.m_data[i];
    }
}

#endif // VECTOR_H
