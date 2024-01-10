#ifndef VEC_DECLARATION_CPP
#define VEC_DECLARATION_CPP

#include <iostream>
#include <limits>
#include <initializer_list>

template <class T>
class Vec
{
public:
	// nested iterator class for const Vec objects
	class const_iterator 
	{
	public:
		const_iterator(); //
		const_iterator(const T* ptr1); //

		const_iterator& operator= (const const_iterator& other); //

		const T& operator* () const; //
		const T* operator-> () const; //

		const_iterator& operator++ (); // 
		const_iterator operator++ (int); //

		const_iterator& operator-- (); //
		const_iterator operator-- (int); //

		const_iterator operator+ (const int n) const; //
		const_iterator operator- (const int n) const; //

		const_iterator& operator+= (const int n); //
		const_iterator& operator-= (const int n); //

		bool operator== (const const_iterator& other) const; //
		bool operator!= (const const_iterator& other) const; //
		bool operator> (const const_iterator& other) const; //
		bool operator< (const const_iterator& other) const; //
		bool operator>= (const const_iterator& other) const; //
		bool operator<= (const const_iterator& other) const; //

		const T& operator[] (int i) const; //

	private:
		T* ptr;
	};

public:
	//nested random access iterator for Vec class
	class random_access_itr
	{
	public:
		random_access_itr(); //
		random_access_itr(T* new_ptr); //

		random_access_itr& operator= (const random_access_itr& other); //
		
		T& operator* (); //
		const T& operator* () const;

		T* operator-> (); // 
		const T& operator-> () const;

		random_access_itr& operator++ (); //
		random_access_itr operator++ (int); //

		random_access_itr& operator-- (); //
		random_access_itr operator-- (int); //

		random_access_itr operator+ (const int n); // 
		random_access_itr operator- (const int n); //

		random_access_itr& operator+= (const int n); //
		random_access_itr& operator-= (const int n); // 

		bool operator== (const random_access_itr& other) const; //
		bool operator!= (const random_access_itr& other) const;//
		bool operator> (const random_access_itr& other) const; //
		bool operator< (const random_access_itr& other) const; //
		bool operator>= (const random_access_itr& other) const; //
		bool operator<= (const random_access_itr& other) const; //

		T&  operator[] (const size_t n); //


	private:
		T* ptr;
	};

public:
	// Iterators

	// for const Vec obj 
	using const_itr = const_iterator; //
	const const_itr c_begin() const; //
	const const_itr c_end() const; //

	// for nonconst Vec obj
	using itr = random_access_itr;
	itr begin(); //
	itr end(); //

public:
	// Member functions

	Vec(); // defolt constructor
	~Vec(); // destructor
	Vec(std::initializer_list<T> init_list); // initializer_list constructor
	Vec(size_t new_size, T val = T{});// parameterized constructor where new_size is Vec m_size,
	Vec(const Vec& other); // copy constructor 
	Vec(Vec&& other) noexcept; //move constructor

	Vec& operator=(const Vec& other); // copy assignment operator overload
	Vec& operator=(Vec&& other) noexcept; // move assignment operator overload

	void assign(int amount, T val = 0); /*amount (the number of elements to assign) and val (the value to assign to each element).
										It updates the size of the vector (m_size) to the specified amount */


public:
	// Element access
	T& at(int ind) const; // Returns a reference to the element at position ind in the vector.
	T& operator[](long long ind) const; //subscript operator overload
	T& front() const; // Returns a reference to the first element in the Vec
	T& back() const; // Returns a reference to the last element in the vector
	T* data()  noexcept; //Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
	const T* data() const noexcept; /*(for const objects) Returns a direct pointer to the memory array used 
									internally by the vector to store its owned elements.*/

	// Capacity
	bool Empty() ; // return true if empty	
	size_t Size() const; //returns m_size
	size_t Max_size() const; //Returns the maximum number of elements that the vector can hold
	void Reserve(size_t new_size);// make m_cap ecual to new_size if new_size > m_cap
	size_t Capacity() const; //return m_cap
	void shrink_to_fit();//Requests the container to reduce its capacity to fit its size.
	
	//Modifiers
	void clear(); //Removes all elements from the vector, leaving the container with a size of 0.
	void insert(int ind, const T& val); // inserts the element(val) at given ind, increasing size by 1
	
	template <typename... Args>             //Inserts an element constructed in place into the vector at a specified position(ind).
    	void emplace(int ind, Args&&... args);  //The arguments args... are forwarded to the constructor as std::forward<Args>(args)...

	void erase(int ind); // erase element at given position(ind), decreasing size by 1 	
	void push_back(const T& val); // Adds a new element(num) at the end of the vector,

	template <typename... Args>         //Adds an element constructed in place to the end of the vector
    	void emplace_back(Args&&... args);  //The arguments args... are forwarded to the constructor as std::forward<Args>(args)...

	void pop_back(); // Removes the last element in the vector, redusing m_size by 1,


	void swap (Vec& other); /*Exchanges the content of the container by the content of other, which is another Vec object of the same 
				type. Sizes may differ.*/		
private:	
	void realloc(size_t new_cap = 0); // reallocates memory, if no argument passed doubles the cap, else cap is equal to new_cap

private:
	size_t m_size;
	size_t m_cap;
	T* m_ptr;
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Vec<T>& obj);


//for holding amount of bits of size_t( Vec<bool> )
enum { BITCOUNT = (sizeof(size_t) * 8) };


//specialization of Vec for the type bool.
//line 718 in Vec.hpp
template <>
class Vec<bool>
{
public:
	//nested class for handling referance
	class reference
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

#endif //VEC_DECLARATION_CPP
