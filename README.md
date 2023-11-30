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

### Constructors and Destructors

- `Vec()`: Default constructor.
- `~Vec()`: Destructor.
- `Vec(std::initializer_list<T> init_list)`: Initializer_list constructor.
- `Vec(size_t new_size, T val = T{})`: Parameterized constructor with an initial size and optional default value.
- `Vec(const Vec& other)`: Copy constructor.
- `Vec(Vec&& other) noexcept`: Move constructor.

### Assignment Operators

- `Vec& operator=(const Vec& other)`: Copy assignment operator.
- `Vec& operator=(Vec&& other) noexcept`: Move assignment operator.

### Accessors

- `T& operator[](int ind) const`: Subscript operator overload.
- `size_t Size() const`: Returns the current size of the vector.
- `size_t Max_size() const`: Returns the maximum number of elements the vector can hold.
- `size_t Capacity() const`: Returns the current capacity of the vector.
- `bool Empty() const`: Returns true if the vector is empty.

### Modifiers

- `void Reserve(size_t new_size)`: Reserves memory for the specified size.
- `void shrink_to_fit()`: Reduces the vector's capacity to fit its size.
- `void assign(int amount, T val = T{})`: Assigns a specified amount of elements with an optional default value.
- `void push_back(const T& val)`: Adds a new element at the end of the vector.
- `void pop_back()`: Removes the last element in the vector.
- `void insert(int ind, const T& val)`: Inserts an element at the specified index.
- `void erase(int ind)`: Erases the element at the specified index.
- `void swap(Vec& other)`: Exchanges the content of the vector with another vector.
- `void clear()`: Removes all elements from the vector.
- `void emplace_back(Args&&... args)`: Inserts a new element at the end of Vec into the container constructed in-place with the given args
- `void emplace(int ind, Args&&... args)`: Inserts a new element into the container at index(ind) constructed in-place with the given args

### Element Access

- `T& at(int ind) const`: Returns a reference to the element at the specified position.
- `T& front() const`: Returns a reference to the first element in the vector.
- `T& back() const`: Returns a reference to the last element in the vector.
- `T* data() const noexcept`: Returns a direct pointer to the memory array used internally by the vector.

### Output Stream Operator

- `std::ostream& operator<<(std::ostream& os, const Vec<T>& obj)`: Overloads the << operator for easy printing.

*************************************************************************

# Vec Template bool specialization Class

`Vec<bool>` is a specialized template class for managing boolean values efficiently using a custom vector implementation. This template is designed to handle the unique challenges associated with boolean values in C++.

## Features

- **Efficient Storage**: The class utilizes an internal representation using `size_t` to optimize storage for boolean values.
- **Reference Handling**: The nested `reference` class provides a convenient interface for working with individual boolean values.
- **Initializer List Support**: The class supports initialization using `std::initializer_list<bool>` for easy initialization of boolean vectors.

# Public Member Functions for Vec<bool>

### Constructors and Destructors (Vec<bool>)
- `Vec()`: Default constructor.
- `Vec(int new_size)`: Parameterized constructor with an initial size 
- `Vec(const std::initializer_list<bool>& list)`: Initializer_list constructor.
- `~Vec()`: Destructor.
- `Vec(const Vec& other)`: Copy constructor.
- `Vec(Vec&& other) noexcept`: Move constructor.

  ### Accessors
- `size_t Size() const`:	 Returns the current size of the vector(amount of bits).
-	`size_t Capacity() const`:  Returns the current capacity of the vector(amount of bits).
- `reference operator[](size_t index)`: Subscript operator overload, which works with help of nested class reference
  








