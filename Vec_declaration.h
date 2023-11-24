#ifndef VEC_DECLARATION_CPP
#define VEC_DECLARATION_CPP

#include <iostream>
#include <limits>
#include <initializer_list>

template <class T>
class Vec
{
public:
	Vec(); // defolt constructor
	~Vec(); // destructor
	Vec(std::initializer_list<T> init_list); // initializer_list constructor
	Vec(size_t new_size, T val = T{});// parameterized constructor where new_size is Vec m_size,
	Vec(const Vec& other); // copy constructor 
	Vec(Vec&& other) noexcept; //move constructor

	T& operator[](int ind) const; //subscript operator overload
	Vec& operator=(const Vec& other); // copy assignment operator overload
	Vec& operator=(Vec&& other) noexcept; // move assignment operator overload

public:
	size_t Size() const; //returns m_size
	size_t Max_size() const; //Returns the maximum number of elements that the vector can hold
	size_t Capacity() const; //return m_cap
	bool Empty() const; // return true if empty	
	void Reserve(size_t new_size);// make m_cap ecual to new_size if new_size > m_cap
	void shrink_to_fit();//Requests the container to reduce its capacity to fit its size.
	
	T& at(int ind) const; // Returns a reference to the element at position ind in the vector.
	T& front() const; // Returns a reference to the first element in the Vec
	T& back() const; // Returns a reference to the last element in the vector
	T* data()  noexcept; //Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
	const T* data() const noexcept; /*(for const objects) Returns a direct pointer to the memory array used 
					internally by the vector to store its owned elements.*/
	void assign(int amount, T val = 0); /*amount (the number of elements to assign) and val (the value to assign to each element).
					     It updates the size of the vector (m_size) to the specified amount */
	void push_back(const T& val); // Adds a new element(num) at the end of the vector,
	void pop_back(); // Removes the last element in the vector, redusing m_size by 1,
	void insert(int ind, const T& val); // inserts the element(val) at given ind, increasing size by 1
	void erase(int ind); // erase element at given position(ind), decreasing size by 1 	
	void swap (Vec& other); /*Exchanges the content of the container by the content of other, which is another Vec object of the same 
				type. Sizes may differ.*/
	void clear(); //Removes all elements from the vector, leaving the container with a size of 0.


	template <typename... Args>         //Appends a new element to the end of the container. 
    	void emplace_back(Args&&... args);  //The arguments args... are forwarded to the constructor as std::forward<Args>(args)...
     					   


	template <typename... Args>             //Appends a new element at the given index(ind) the end of the container. 
    	void emplace(int ind, Args&&... args);  //The arguments args... are forwarded to the constructor as std::forward<Args>(args)...
	
private:	
	void realloc(size_t new_cap = 0); // reallocates memory, if no argument passed doubles the cap, else cap is equal to new_cap

private:
	size_t m_size;
	size_t m_cap;
	T* m_ptr;
};

//specialization of Vec for the type bool.
//still working on it!!!
template <class T>
std::ostream& operator<<(std::ostream& os, const Vec<T>& obj);

template <>
class Vec<bool>
{
public:
	Vec();
	Vec(int new_size, bool val = false);
	/* Vec(const std::initializer_list<bool> list); */
	~Vec();
	Vec(const Vec& other);
	Vec(Vec&& other) noexcept;

public:
	size_t Size() const;	
	size_t Capacity() const;
	void push_back(bool val);
	void pop_back();		     

private:
	void realloc(size_t new_cap = 0);

private:
	size_t m_size;
	size_t m_cap;
	size_t* m_ptr;
};

#include "Vec.hpp"

#endif //VEC_DECLARATION_CPP