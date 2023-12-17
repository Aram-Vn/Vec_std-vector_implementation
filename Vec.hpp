template <class T>
Vec<T>::const_iterator::const_iterator() :
	ptr(nullptr)
{}

template <class T>
Vec<T>::const_iterator::const_iterator(const T* ptr1) :
	ptr(const_cast<T*>(ptr1))
{}

template <class T>
typename Vec<T>::const_iterator& Vec<T>::const_iterator::operator= (const const_iterator& other)
{
    this->ptr = other.ptr;
    return *this;
}

template <class T>
const T& Vec<T>::const_iterator::operator* () const 
{
	return *ptr;
}

template <class T>
const T* Vec<T>::const_iterator::operator-> () const 
{
	return ptr;
}

template <class T>
typename Vec<T>::const_iterator& Vec<T>::const_iterator::operator++ () 
{
	++ptr;
	return *this;
}

template <class T>
typename Vec<T>::const_iterator Vec<T>::const_iterator::operator++ (int)
{
	const_iterator tmp = *this;
	++ptr;
	return tmp;
}

template <class T>
typename Vec<T>::const_iterator& Vec<T>::const_iterator::operator-- () 
{
	--ptr;
	return *this;
}

template <class T>
typename Vec<T>::const_iterator Vec<T>::const_iterator::operator-- (int)
{
	const_iterator tmp = *this;
	--ptr;
	return tmp;
}

template <class T>
typename Vec<T>::const_iterator Vec<T>::const_iterator::operator+ (const int n) const
{
	const_iterator tmp = *this;

	for (int i = 0; i < n; ++i) {
		++tmp.ptr;
	}

	return tmp;
}

template <class T>
typename Vec<T>::const_iterator Vec<T>::const_iterator::operator- (const int n) const
{
	const_iterator tmp = *this;

	for (int i = 0; i < n; ++i) {
		--tmp.ptr;
	}

	return tmp;
}


template <class T> 
typename Vec<T>::const_iterator& Vec<T>::const_iterator::operator+= (const int n)
{
	for (int i = 0; i < n; ++i) {
		++this->ptr;
	}

	return *this;
}

template <class T>
typename Vec<T>::const_iterator& Vec<T>::const_iterator::operator-= (const int n)
{
	for (int i = 0; i < n; ++i) {
		--this->ptr;
	}

	return *this;
}

template <class T>
bool Vec<T>::const_iterator::operator== (const const_iterator& other) const
{
	return (this->ptr == other.ptr);
}

template <class T>
bool Vec<T>::const_iterator::operator!= (const const_iterator& other) const
{
	return !(this->ptr == other.ptr);
}

template <class T>
bool Vec<T>::const_iterator::operator> (const const_iterator& other) const
{
	return (this->ptr > other.ptr);
}


template <class T>
bool Vec<T>::const_iterator::operator< (const const_iterator& other) const
{
	return (this->ptr < other.ptr);
}

template <class T>
bool Vec<T>::const_iterator::operator>= (const const_iterator& other) const
{
	return !(this->ptr < other.ptr);
}

template <class T>
bool Vec<T>::const_iterator::operator<= (const const_iterator& other) const
{ 
	return !(this->ptr > other.ptr);
}

template <class T>
const T& Vec<T>::const_iterator::operator[] (int i) const
{
	return *(ptr + i);
}

template <class T>
const typename Vec<T>::const_itr Vec<T>::c_begin () const
{
	return const_itr(this->data());
}

/*----------------------------------random_access_itr-----------------------------------------*/

template <class T>
Vec<T>::random_access_itr::random_access_itr() : 
	ptr(nullptr) 
{}

template <class T>
Vec<T>::random_access_itr::random_access_itr(T* new_ptr) :
	ptr(new_ptr)
{}

template <class T>
typename Vec<T>::random_access_itr& Vec<T>::random_access_itr::operator= (const random_access_itr& other)
{
	this->ptr = other.ptr;
	return *this;
}

template <class T>
T& Vec<T>::random_access_itr::operator* ()
{
	return *ptr;
}

template <class T>
T* Vec<T>::random_access_itr::operator-> ()
{
	return ptr;
}

template <class T>
typename Vec<T>::random_access_itr& Vec<T>::random_access_itr::operator++ () 
{
	++ptr;
	return *this;	
}

template <class T>
typename Vec<T>::random_access_itr Vec<T>::random_access_itr::operator++ (int)
{
	random_access_itr tmp = *this;
	++ptr;
	return tmp; 
}

template <class T>
typename Vec<T>::random_access_itr& Vec<T>::random_access_itr::operator-- ()
{
	--ptr;
	return *this;
}

template <class T>
typename Vec<T>::random_access_itr Vec<T>::random_access_itr::operator-- (int)
{
	random_access_itr tmp = *this;
	--ptr;
	return *this;
}

template <class T>
typename Vec<T>::random_access_itr Vec<T>::random_access_itr::operator+ (const int n)
{
	random_access_itr tmp = *this;

	for (size_t i = 0; i < n; i++)
	{
		++tmp.ptr;
	}

	return tmp;
}

template <class T>
typename Vec<T>::random_access_itr Vec<T>::random_access_itr::operator- (const int n)
{
	random_access_itr tmp = *this;

	for (size_t i = 0; i < n; i++)
	{
		--tmp.ptr;
	}

	return tmp;
}
template <class T>
typename Vec<T>::random_access_itr& Vec<T>::random_access_itr::operator+= (const int n)
{
	for (int i = 0; i < n; ++i) {
        ++this->ptr;
    }

    return *this;
}

template <class T>
typename Vec<T>::random_access_itr& Vec<T>::random_access_itr::operator-= (const int n)
{
	for (int i = 0; i < n; ++i) {
        --this->ptr;
    }

    return *this;
}

template <class T>
bool Vec<T>::random_access_itr::operator== (const random_access_itr& other) const
{
	return this->ptr == other.ptr;
}

template <class T>
bool Vec<T>::random_access_itr::operator!= (const random_access_itr& other) const 
{
	return !(this->ptr == other.ptr);
}

template <class T>
bool Vec<T>::random_access_itr::operator> (const random_access_itr& other) const
{
	return (this->ptr > other.ptr);
}

template <class T>
bool Vec<T>::random_access_itr::operator< (const random_access_itr& other) const
{
	return (this->ptr < other.ptr);
}

template <class T>
bool Vec<T>::random_access_itr::operator>= (const random_access_itr& other) const
{
	return (this->ptr >= other.ptr);
}

template <class T>
bool Vec<T>::random_access_itr::operator<= (const random_access_itr& other) const
{
	return (this->ptr <= other.ptr);
}

template <class T>
T& Vec<T>::random_access_itr::operator[] (const size_t n) 
{
	return *(ptr + n);
}

template <class T>
typename Vec<T>::itr Vec<T>::begin()
{
	return itr(this->data());
}

template <class T>
typename Vec<T>::itr Vec<T>::end()
{
	return itr(this->data() + this->Size());
}

template <class T>
Vec<T>::Vec() :
	m_size{0},
	m_cap{0},
	m_ptr{nullptr}
{}


template <class T>
Vec<T>::Vec(std::initializer_list<T> init_list) : 
	m_size{0}, m_cap{0}, m_ptr{nullptr}
{
	this->Reserve(init_list.size());

        for (const auto& elem : init_list) {
            this->push_back(elem);
        }
}

template <class T>
Vec<T>::~Vec()
{
	delete[] m_ptr;
	m_size = 0;
	m_cap = 0;
}

template <class T>
Vec<T>::Vec(size_t new_size, T val) :
	m_size{new_size},
	m_cap{2 * m_size},
	m_ptr{new T[m_cap]}
{
	for(int i = 0; i < m_size; ++i){
		m_ptr[i] = val;
	}
}

template <class T>
Vec<T>::Vec(const Vec& other) :
	m_size{other.m_size},
	m_cap{other.m_cap}, 
	m_ptr{new int[m_cap]} 
{
	for(int i = 0; i < m_size; ++i){
		this->m_ptr[i] = other.m_ptr[i]; 
	}
}

template <class T>
Vec<T>::Vec(Vec&& other) noexcept :
	m_size{other.m_size},
	m_cap{other.m_cap}, 
	m_ptr{other.m_ptr} 
{
	other.m_size = 0;
	other.m_cap = 0;
	other.m_ptr = nullptr;
}

template <class T>
T& Vec<T>::operator[](long long ind) const
{
	if(m_ptr == nullptr){
		std::cout << "for[]\nnullptr" << std::endl;
		exit(0);
	}

	if(ind >= 0 && ind < m_size){
		return *(m_ptr + ind);	
	} else {
		std::cout << "in Vec[ind] ind must be >=0 && < size" << std::endl;
		exit(0);
	}
	
}

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& other) 
{
	if(this != &other){
    		if(other.m_size > m_cap){
        		delete[] this->m_ptr;
            		this->m_ptr = new T[other.m_size];
            		this->m_cap = other.m_size;
        	}

        	this->m_size = other.m_size;

        	for (size_t i = 0; i < m_size; ++i) {
            		this->m_ptr[i] = other.m_ptr[i];
          	}
    	}	

	return *this;
}

template <class T>
Vec<T>& Vec<T>::operator=(Vec&& other) noexcept 
{
	if(this != &other){
        	delete[] m_ptr;

        	this->m_size = other.m_size;
        	this->m_cap = other.m_cap;
        	this->m_ptr = other.m_ptr;

        	other.m_size = 0;
        	other.m_cap = 0;
    		other.m_ptr = nullptr;
  	 }

	return *this;
}

template <class T>
size_t Vec<T>::Size() const
{
	return m_size;
}

template <class T>
size_t Vec<T>::Max_size() const
{
	return std::numeric_limits<size_t>::max() / sizeof(T);
}

template <class T>
size_t Vec<T>::Capacity() const
{
	return m_cap;
}	

template <class T>
bool Vec<T>::Empty() 
{
	return m_size == 0;
}

template <class T>
void Vec<T>::realloc(size_t new_cap)
{
	if(new_cap == 0){
		m_cap = (m_cap) ? 2 * m_cap : 1;
	} else {
		m_cap = new_cap;
	}	

	T* tmp_ptr = new T[m_cap];

		for(size_t i = 0; i < m_size; ++i){
			tmp_ptr[i] = m_ptr[i]; 
		}

	delete[] m_ptr;
	m_ptr = tmp_ptr;
}

template <class T>
void Vec<T>::Reserve(size_t new_cap)
{
	if(m_ptr == nullptr){
		realloc();
	}

	if(m_cap < new_cap){
		realloc(new_cap);
	}
}

template <class T>
void Vec<T>::shrink_to_fit()
{
	if(m_ptr != nullptr){
		realloc(m_size);
	}

}

template <class T>
T& Vec<T>::at(int ind) const
{
	if(m_ptr != nullptr){
		if(ind >= 0	&& ind < m_size){
			return m_ptr[ind];
		} else {
			std::cout << "(at)\nind must be >= 0 and less than Vec size!!" << std::endl;
			exit(0);
		}
	} else {
		std::cout << "(at)\nnullptr" << std::endl;
		exit(0);
	}
}

template <class T>
T& Vec<T>::front() const
{
	if(m_ptr != nullptr){
		return m_ptr[0];
	} else {
		std::cout << "(front)\nnullptr" << std::endl;
	}

}

template <class T>
T& Vec<T>::back() const
{
	if(m_ptr != nullptr){ 
		return m_ptr[m_size - 1];
	} else {
		std::cout << "(back)\nnullptr" << std::endl;
	}
}

template <class T>
T* Vec<T>::data() noexcept
{
	return m_ptr;
}

template <class T>
const T* Vec<T>::data() const noexcept
{
	return m_ptr;
}

template <class T>
void Vec<T>::assign(int amount, T val)
{

	if(amount < 0){
		std::cout << "in assign function first argument must be >= 0" << std::endl;
		exit(0);
	}

	if(amount > m_cap){
		realloc(amount);
	}

	m_size = amount;
	
	for(int i = 0; i < m_size; ++i){
		m_ptr[i] = val;
	}
}


template <class T>
void Vec<T>::push_back(const T& val)
{
	if(m_size == m_cap){ 
		realloc();
	}
	
	m_ptr[m_size++] = val;
}

template <class T>
void Vec<T>::pop_back(){
	if(m_ptr != nullptr && m_size > 0){
		--m_size;
	} else {
		std::cout << "(pop_back)\nVec is empty can't pop_back" << std::endl;
		exit(0);
	}
}

template <class T>
void Vec<T>::insert(int ind, const T& val)
{
	if(m_ptr != nullptr){
		if(ind >= 0 && ind < m_size){
			if(m_size == m_cap){ 
				realloc();
			}
	
			for (size_t i = m_size; i > ind; --i) {
	           		m_ptr[i] = m_ptr[i - 1];
        		}		
		
			m_ptr[ind] = val;
			++m_size;	

		} else {
			std::cout << "in insert function first argument must be >= 0 and less than size" << std::endl;
			exit(0);
		}
	} else {
		std::cout << "(insert)\nnullptr" << std::endl;
		exit(0);
	}
}

template <class T>
void Vec<T>::erase(int ind)
{
	if(m_ptr != nullptr){
		if(ind >= 0 && ind < m_size){
			for(int i = ind; i < m_size; ++i){
				m_ptr[i] = m_ptr[i + 1];
			}

			--m_size;
		} else {
			std::cout << "in erase function must get argument which is >= 0 and less than size" << std::endl;
			exit(0);
		}
	} else {
		std::cout << "(erase)\nnullptr" << std::endl;
		exit(0);
	}
	
}
	
template <class T>
void Vec<T>::swap (Vec& other)
{
	size_t tmp_Size = m_size;
        m_size = other.m_size;
        other.m_size = tmp_Size;

        size_t tmp_Cap = m_cap;
        m_cap = other.m_cap;
        other.m_cap = tmp_Cap;

        T* tmp_Ptr = m_ptr;
        m_ptr = other.m_ptr;
        other.m_ptr = tmp_Ptr;
}

template <class T>
void Vec<T>::clear()
{
	m_size = 0;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Vec<T>& obj)
{
	for(size_t i = 0; i < obj.Size(); ++i){
		os << obj[i] << " ";   
	}
	
	return os;
}

template <typename T>
	template <typename... Args>
		void Vec<T>::emplace_back(Args&&... args) 
		{
			if(m_ptr != nullptr){
				++m_size;	
	
					if(m_size >= m_cap){
						realloc();	
					}

      	  		m_ptr[m_size - 1] = T(std::forward<Args>(args)...);

			} else {
				std::cout << "for (emplace_back)\nnullptr" << std::endl;
				exit(0);		
    			}
		}

template <typename T>
	template <typename... Args>
    	void Vec<T>::emplace(int ind, Args&&... args)
		{
			if(m_ptr != nullptr){
				if(ind >= 0 && ind < m_size){
					if(m_size == m_cap){ 
						realloc();
					}
	
					for (size_t i = m_size; i > ind; --i) {
	           			m_ptr[i] = m_ptr[i - 1];
        			}		
		
					m_ptr[ind] = T(std::forward<Args>(args)...);
					++m_size;	

				} else {
					std::cout << "in emplace function first argument must be >= 0 and less than size" << std::endl;
					exit(0);
				}			
			} else {
				std::cout << "(emplace)\nnullptr" << std::endl;
				exit(0);
			}
		}

//***********************************************************
//************************* bool ****************************
//***********************************************************

//BITCOUNT is enum const equal to (sizeof(size_t) * 8) 


Vec<bool>::Vec() :
	m_size{0},
	m_cap(BITCOUNT)
{
	m_ptr = new size_t[1];
	m_ptr[0] = 0; 
}

Vec<bool>::Vec(int new_size)
{
	int ind = new_size / BITCOUNT;
	
	m_size = new_size;


	if(ind == 0){
		m_ptr = new size_t[1] { 0 }; 
		m_cap = BITCOUNT;
	} else {
		m_cap = ind * BITCOUNT;
		m_ptr = new size_t[ind];
	}
	
	for(int i = 0; i < ind; ++i){
		m_ptr[i] = 0;
	}
		
}

Vec<bool>::Vec(const std::initializer_list<bool>& list) : 
	m_size(0), 
	m_cap{BITCOUNT}, 
	m_ptr{new size_t[1]} 
{
    for (const bool& val : list) {
        push_back(val);
    }
}

size_t Vec<bool>::Size() const
{
	return m_size;
}

size_t Vec<bool>::Capacity() const
{
	return m_cap;
}

Vec<bool>::~Vec()
{
	delete[] m_ptr;
	m_size = 0;
	m_cap = 0;
}

Vec<bool>::Vec(const Vec& other) :
	m_size{other.m_size},
	m_cap{other.m_cap}, 
	m_ptr{new size_t[m_cap]} 
{
	int ind = m_cap / BITCOUNT;	
	
	m_ptr[0] = other.m_ptr[0];
	
	for(int i = 1; i < ind; ++i){
		m_ptr[i] = other.m_ptr[i];
	}	
}

Vec<bool>::Vec(Vec&& other) noexcept :
	m_size{other.m_size},
	m_cap{other.m_cap}, 
	m_ptr{other.m_ptr}
{
	other.m_size = 0;
	other.m_cap = 0;
	other.m_ptr = nullptr;
}

void Vec<bool>::realloc(size_t new_cap)
{

	if(new_cap == 0){
		m_cap = (m_cap) ? 2 * m_cap : BITCOUNT;
	} else {
		m_cap = new_cap;
	}	

	int ind = m_cap / BITCOUNT;

	size_t* tmp_ptr = new size_t[ind];

		for(int i = 0; i < ind; ++i){
			tmp_ptr[i] = m_ptr[i];
		}

	delete[] m_ptr;
	m_ptr = tmp_ptr;
}

void Vec<bool>::push_back(bool val)
{
	if(m_size == m_cap){
		realloc();
	}

	int ind = m_size / BITCOUNT;
	int at = m_size % BITCOUNT;
	size_t one = 1;
	
	if(val){
		m_ptr[ind] |= (one << at);
	} else {
		if(bool( m_ptr[ind] & (one << at)) ){
			m_ptr[ind] ^= (one << at);
		}

		++m_size;
		return;
	}

	++m_size;
}

void Vec<bool>::pop_back()
{
	if(m_ptr != nullptr){
		if(m_size != 0){
			--m_size;
		} else {
			std::cout << "for pop_back\nm_size is 0" << std::endl;
		}
	} else {
		std::cout << "for pop_back\nnullptr" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Vec<bool>& other) noexcept
{
		size_t one = 1;

        for (size_t i = 0; i < other.Size(); ++i)
        {
			os << bool((other.m_ptr[i / BITCOUNT] & (one << (i % BITCOUNT)) ));

            if (i + 1 != other.Size()){
                os << ", ";
			}
        }
        return os;
}


Vec<bool>::reference Vec<bool>::operator[](size_t index)
{
	if(m_ptr != nullptr){
		if(index >= 0 && index < m_size){
			return Vec<bool>::reference(m_ptr, index);
		} else {
			std::cout << "in [" << index << "] for Vec<bool>" << std::endl;
			std::cout << "index must be >= 0 && < Vec.Size()" << std::endl;
			exit(0);
		}
	} else {
		std::cout << "in [index] for Vec<bool>" << std::endl;
		std::cout << "nullptr" << std::endl;
		exit(0);
	}
}


Vec<bool>::reference::reference(size_t* ptr1, size_t index1) :
	ptr(ptr1), index(index1)
{
	flag = ptr[index / BITCOUNT] & ( 1 << index % BITCOUNT);
}

Vec<bool>::reference::reference(const reference& other) :
	index{other.index},	
	flag{other.flag}
{

	size_t amount = index / BITCOUNT;
	ptr = new size_t[amount];

	for(size_t i = 0; i <= (index / BITCOUNT); ++i){
		ptr[i] = other.ptr[i]; 
	}
}

Vec<bool>::reference::reference(reference&& other) :
	index{other.index},
	flag{other.flag}   
{
	size_t amount = index / BITCOUNT;
	ptr = new size_t[amount];

	for(size_t i = 0; i <= (index / BITCOUNT); ++i){
		ptr[i] = other.ptr[i]; 
	}

	delete[] other.ptr;
	other.index = -1;	
}

Vec<bool>::reference& Vec<bool>::reference::operator=(const reference& obj)
{
	if(this != &obj){
		flip();	
	}

	return *this;	
}

Vec<bool>::reference& Vec<bool>::reference::operator=(bool flag)
{
	if(this->flag != flag){
		flip();
	}
 
	return *this;
}

Vec<bool>::reference& Vec<bool>::reference::operator=(reference&& other)
{
	if(this != &other){
		flip();
	}
	
	delete[] other.ptr;
	
	return *this;	
}

Vec<bool>::reference::operator bool() const
{
	return flag;
}


void Vec<bool>::reference::flip()
{
	this->ptr[index / BITCOUNT] ^= 1 << (index % BITCOUNT);	
}
