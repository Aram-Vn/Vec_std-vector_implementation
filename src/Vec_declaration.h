#ifndef VEC_DECLARATION_CPP
#define VEC_DECLARATION_CPP

#include <initializer_list>
#include <iostream>
#include <limits>

template <class T>
class Vec
{
public:
    class const_iterator // nested const iterator class for const Vec objects
    {
    public:
        const_iterator();              // Default constructor
        const_iterator(const T* ptr1); // const_iterators parameterized constructor

        const_iterator& operator=(const const_iterator& other); // copy assignment operator

        const T& operator*() const;  // Dereference operator to access the value of the vector
        const T* operator->() const; // Arrow operator

        const_iterator& operator++();   // Prefix increment operato
        const_iterator operator++(int); // Postfix increment operator

        const_iterator& operator--();   // Prefix decrement operator
        const_iterator operator--(int); // Postfix decrement operator

        const_iterator operator+(const int n) const; // Addition operator
        const_iterator operator-(const int n) const; // Subtraction operator

        const_iterator& operator+=(const int n); // Addition assignment operator
        const_iterator& operator-=(const int n); // Subtraction assignment operator

        bool operator==(const const_iterator& other) const; // Equality operator
        bool operator!=(const const_iterator& other) const; // Inequality operator
        bool operator>(const const_iterator& other) const;  // Greater than operator
        bool operator<(const const_iterator& other) const;  // Less than operator
        bool operator>=(const const_iterator& other) const; // Greater than or equal to operator
        bool operator<=(const const_iterator& other) const; // Less than or equal to operator

        const T& operator[](int i) const; //  Subscript operator for accessing the i-th element

    private:
        T* ptr;
    };
    // for const Vec obj
    using const_itr = const_iterator; // Alias for const_iterator
    const const_itr c_begin() const;  // Returns a const_iterator pointing to the first element
    const const_itr c_end() const;    // Returns a const_iterator pointing one past the last element

public:
    class random_access_itr // nested random access iterator for Vec class
    {
    public:
        random_access_itr();           // Default constructor
        random_access_itr(T* new_ptr); // Parameterized constructor

        random_access_itr& operator=(const random_access_itr& other); // Copy assignment operator

        T& operator*(); // Dereference operator to access the value of the vector
        T* operator->(); // Arrow operator for accessing members of the pointed object

        random_access_itr& operator++();   // Prefix increment operator (++iter)
        random_access_itr operator++(int); // Postfix increment operator (iter++)

        random_access_itr& operator--();   // Prefix decrement operator (--iter)
        random_access_itr operator--(int); // Postfix decrement operator (iter--)

        random_access_itr operator+(const int n); // Addition operator for advancing iterator
        random_access_itr operator-(const int n); // Subtraction operator for moving iterator back

        random_access_itr& operator+=(const int n); // Addition assignment operator for advancing iterator
        random_access_itr& operator-=(const int n); // Subtraction assignment operator for moving iterator back

        bool operator==(const random_access_itr& other) const; // Equality operator
        bool operator!=(const random_access_itr& other) const; // Inequality operator
        bool operator>(const random_access_itr& other) const;  // Greater than operator
        bool operator<(const random_access_itr& other) const;  // Less than operator
        bool operator>=(const random_access_itr& other) const; // Greater than or equal to operator
        bool operator<=(const random_access_itr& other) const; // Less than or equal to operator

        T& operator[](const size_t n); // Subscript operator for accessing the i-th element

    private:
        T* ptr;
    };

public:
    // for nonconst Vec obj
    using itr = random_access_itr; // Alias for non-const Vec obj
    itr begin();                   // Returns an iterator pointing to the first element
    itr end();                     // Returns an iterator pointing one past the last element

public:
    // Member functions

    Vec();                                   // defolt constructor
    ~Vec();                                  // destructor
    Vec(std::initializer_list<T> init_list); // initializer_list constructor
    Vec(size_t new_size, T val = T{});       // parameterized constructor where new_size is Vec m_size,
    Vec(const Vec& other);                   // copy constructor
    Vec(Vec&& other) noexcept;               // move constructor

    Vec& operator=(const Vec& other);     // copy assignment operator overload
    Vec& operator=(Vec&& other) noexcept; // move assignment operator overload

    void assign(int amount, T val = 0); /*amount (the number of elements to assign) and val (the value to assign to each
                                        element). It updates the size of the vector (m_size) to the specified amount */

public:
    // Element access
    T& at(int ind) const;                     // Returns a reference to the element at position ind in the vector.
    const T& operator[](long long ind) const; // subscript operator overload for const vec objects
    T& operator[](long long ind);             // subscript operator overload
    T& front() const;                         // Returns a reference to the first element in the Vec
    T& back() const;                          // Returns a reference to the last element in the vector
    T* data() noexcept;                       // Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
    const T* data() const noexcept;           /*(for const objects) Returns a direct pointer to the memory array used
                                              internally by the vector to store its owned elements.*/

    // Capacity
    bool Empty();                  // return true if empty
    size_t Size() const;           // returns m_size
    size_t Max_size() const;       // Returns the maximum number of elements that the vector can hold
    void Reserve(size_t new_size); // make m_cap ecual to new_size if new_size > m_cap
    size_t Capacity() const;       // return m_cap
    void shrink_to_fit();          // Requests the container to reduce its capacity to fit its size.

    // Modifiers
    void clear();                       // Removes all elements from the vector, leaving the container with a size of 0.
    void insert(int ind, const T& val); // inserts the element(val) at given ind, increasing size by 1

    template <typename... Args>            // Inserts an element constructed in place into the vector at a specified position(ind).
    void emplace(int ind, Args&&... args); // The arguments args... are forwarded to the constructor as
                                           // std::forward<Args>(args)...

    void erase(int ind);          // erase element at given position(ind), decreasing size by 1
    void push_back(const T& val); // Adds a new element(num) at the end of the vector,

    template <typename... Args>        // Adds an element constructed in place to the end of the vector
    void emplace_back(Args&&... args); // The arguments args... are forwarded to the constructor as
                                       // std::forward<Args>(args)...

    void pop_back(); // Removes the last element in the vector, redusing m_size by 1,

    void swap(Vec& other); /*Exchanges the content of the container by the content of other, which is another Vec object
                            of the same type. Sizes may differ.*/
private:
    void realloc(size_t new_cap = 0); // reallocates memory, if no argument passed doubles the cap, else cap is equal to
                                      // new_cap

private:
    size_t m_size;
    size_t m_cap;
    T* m_ptr;
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Vec<T>& obj);


enum
{
    BITCOUNT = (sizeof(size_t) * 8) // for holding amount of bits of size_t( Vec<bool> )
};

template <>
class Vec<bool> // specialization of Vec for the type bool.
{
public:
    class reference // nested class for handling referance
    {
    public:
        reference(size_t* ptr1, size_t index);
        reference(const reference& other);
        reference(reference&& other);

        reference& operator=(const reference& obj);
        reference& operator=(bool flag);
        reference& operator=(reference&& other);

        operator bool() const;

    private:
        void flip();

    private:
        size_t* ptr;
        size_t index;
        bool flag;
    };

public:
    Vec();
    Vec(int new_size);
    Vec(const std::initializer_list<bool>& list);
    ~Vec();
    Vec(const Vec& other);
    Vec(Vec&& other) noexcept;

    reference operator[](size_t index);

public:
    size_t Size() const;
    size_t Capacity() const;
    void push_back(bool val);
    void pop_back();

    friend std::ostream& operator<<(std::ostream& os, const Vec<bool>& other) noexcept;

private:
    void realloc(size_t new_cap = 0);

private:
    size_t m_size;
    size_t m_cap;
    size_t* m_ptr;
};

std::ostream& operator<<(std::ostream& os, const Vec<bool>& other) noexcept;

#include "Vec.hpp"

#endif // VEC_DECLARATION_CPP