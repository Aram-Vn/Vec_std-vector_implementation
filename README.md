# Vec_std-vector_implementation


*********************************************************************

## Table of Contents

- [Introduction](#introduction)
- [Public Member Functions](#public-member-functions)

*********************************************************************
## introduction

Vec is a C++ template class that provides a dynamic array implementation with various functionalities. It allows you to create, manipulate, and manage dynamic arrays efficiently.

*********************************************************************
# Public Member Functions

- [Constructors and Destructors](#constructors-and-destructors)
- [Assignment Operators](#assignment-operators)
- [Accessors](#accessors)
- [Modifiers](#modifiers)
- [Element Access](#element-access)
- [Output Stream Operator](#output-stream-operator)

## Constructors and Destructors

- `Vec()`: Default constructor.
- `~Vec()`: Destructor.
- `Vec(std::initializer_list<T> init_list)`: initializer_list constructor
- `Vec(size_t new_size, T val = 0)`: Parameterized constructor with an initial size and optional default value.
- `Vec(const Vec& other)`: copy constructor 
- `Vec(Vec&& other) noexcept`: move constructor
- `Vec(const Vec& other)`: Copy constructor.
- `Vec(Vec&& other) noexcept`: Move constructor.

*********************************************************************

## Assignment Operators

- `Vec& operator=(const Vec& other)`: Copy assignment operator.
- `Vec& operator=(Vec&& other) noexcept`: Move assignment operator.

*********************************************************************

## Accessors

- `T& operator[](int ind) const`: Subscript operator overload.
- `size_t Size() const`: Returns the current size of the vector.
- `size_t Max_size() const`: Returns the maximum number of elements the vector can hold.
- `size_t Capacity() const`: Returns the current capacity of the vector.
- `bool Empty() const`: Returns true if the vector is empty.

*********************************************************************

## Modifiers

- `void Reserve(size_t new_size)`: Reserves memory for the specified size.
- `void shrink_to_fit()`: Reduces the vector's capacity to fit its size.
- `void assign(int amount, T val = 0)`: Assigns a specified amount of elements with an optional default value.
- `void push_back(const T& val)`: Adds a new element at the end of the vector.
- `void pop_back()`: Removes the last element in the vector.
- `void insert(int ind, const T& val)`: Inserts an element at the specified index.
- `void erase(int ind)`: Erases the element at the specified index.
- `void swap(Vec& other)`: Exchanges the content of the vector with another vector.
- `void clear()`: Removes all elements from the vector.

*********************************************************************

## Element Access

- `T& at(int ind) const`: Returns a reference to the element at the specified position.
- `T& front() const`: Returns a reference to the first element in the vector.
- `T& back() const`: Returns a reference to the last element in the vector.
- `T* data() const noexcept`: Returns a direct pointer to the memory array used internally by the vector.

*********************************************************************

## Output Stream Operator

- `friend std::ostream& operator<<(std::ostream& os, const Vec<T>& obj)`: Overloads the << operator for easy printing.


