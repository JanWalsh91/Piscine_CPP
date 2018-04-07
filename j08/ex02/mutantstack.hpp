#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <stack>
#include <iostream>

template< typename T >
class MutantStack : public std::stack< T >{
	typedef std::stack<T> base;

	public:
		MutantStack() {}
		MutantStack(MutantStack const &m) : base(m) {}
		using base::operator=;
		~MutantStack() {}

		typedef typename base::container_type::iterator iterator;
		iterator begin() { return base::c.begin(); }
		iterator end() { return base::c.end(); }
};

/* === TOUT LE BEAU TRAVAIL QUE J'AI FAIT AVANT DE TROUVER CETTE SOLUTION CONNE === */

// template< typename T >
// class MutantStack : public std::stack< T >{

// 	private:
// 		std::stack< T >	tmp;

// 	public:
// 		MutantStack< T >( void ) {};
// 		MutantStack< T >( MutantStack const & MutantStack ) {
// 			(void)MutantStack;
// 		};
// 		virtual ~MutantStack< T >( void ) {};

// 		MutantStack &    operator=( MutantStack const & rhs ) {
// 			std::stack<T>::operator=(rhs);
// 			return *this;
// 		};

// 		class iterator {
// 			private:
// 				//pointer to int
// 				MutantStack<T>
// 				T *	ptr;
// 				size_t	index;

// 			public:
// 				iterator( void ) {};
// 				iterator( T & t, size_t i ) {
// 					this->ptr = &t;
// 					this->index = i;
// 				};
// 				~iterator( void ) {};
// 				iterator & operator=( const iterator & rhs ) {
// 					this->ptr = rhs.ptr;
// 					return *this;
// 				};
// 				iterator & operator++( void ) {
// 					std::cout << "++++++++" << std::endl;
// 					// check if position OK
// 					return (*this)[this->index + 1];
// 				};
// 				iterator & operator--( void ) {
					
// 					return *this;
// 				};
// 				operator T() {
// 					return *(this->ptr);
// 				};
// 				T operator*( void ) {
// 					return *(this->ptr);
// 				};
// 				iterator operator[] (int x) {
// 					std::cout << "=-=-=-=-=-=-=-" << std::endl;
// 					// handle out of bounds exeptions
// 					int i = x;
// 					while ( this->size() - 1 ) {
// 						this->tmp.push( this->top() );
// 						this->pop();
// 					}
// 					while ( x-- && this->tmp.size() ) {
// 						this->push( this->tmp.top() );
// 						this->tmp.pop();
// 					}
// 					iterator result(this->top(), i);
// 					while ( this->tmp.size() ) {
// 						this->push( this->tmp.top() );
// 						this->tmp.pop();
// 					}
// 					return result;
// 				};
// 		};


// 		iterator begin( void ) {
// 			return iterator( (*this)[0] );
// 		}

// 		iterator end( void  ) {
// 			return iterator( (*this)[this->size()] );
// 		}

// 		iterator operator[] (int x) {
// 			// handle out of bounds exeptions
// 			std::cout << "*******" << std::endl;
// 			int i = x;
// 			while ( this->size() - 1 ) {
// 				this->tmp.push( this->top() );
// 				this->pop();
// 			}
// 			while ( x-- && this->tmp.size() ) {
// 				this->push( this->tmp.top() );
// 				this->tmp.pop();
// 			}
// 			iterator result(this->top(), i);
// 			while ( this->tmp.size() ) {
// 				this->push( this->tmp.top() );
// 				this->tmp.pop();
// 			}
// 			return result;
// 		}

// };

#endif