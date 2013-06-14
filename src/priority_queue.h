/*
 * priority_queue.h
 *
 *  Created on: 14-06-2013
 *      Author: lukasz
 */

#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_


#include <iostream>
#include <vector>

template <class T> void exch ( std::vector<T> &v, int a, int b )
{
	T x = v[a];
	v[a] = v[b];
	v[b] = x;
}

template <class T> class priority_queue {
private:
	std::vector<T> v;
	void swim ( int N );
	void sink ( int N );
public:
	priority_queue();
	priority_queue ( std::vector<T> vec );

	void add ( T t );
	void add ( std::vector<T> t );

	T remove();

	int size() const;
	void print();
};

template <class T> priority_queue<T>::priority_queue()
{

}

template <class T> priority_queue<T>::priority_queue ( std::vector<T> vec )
{
	for ( int i = 0; i < vec.size(); ++i ) {
		v.push_back ( vec[i] );
		swim ( v.size()-1 );
	}
};

template <class T> void priority_queue<T>::add ( T t )
{
	v.push_back ( t );
}

template <class T> void priority_queue<T>::add ( std::vector<T> t )
{
	for ( int i = 0; i < t.size(); ++i )
		v.push_back ( t[i] );
};

template <class T> T priority_queue<T>::remove()
{
	T b = v[0];
	exch<T> ( v,0,v.size()-1 );
	v.pop_back();
	sink ( 0 );
	return b;
}

template <class T> void priority_queue<T>::print()
{
	for ( int i = 0; i < v.size(); ++i )
		std::cout << v[i] << '\n';
}

template <class T> int priority_queue<T>::size() const
{
	return v.size();
}

template <class T> void priority_queue<T>::swim ( int N )
{
	int k = N;
	while ( v[k] > v[ ( k-1 ) /2] && k >= 0 ) {
		exch<T> ( v, k, ( k-1 ) /2 );
		k = ( k-1 ) /2;
	}
}

template <class T> void priority_queue<T>::sink ( int N )
{

	int j = N;
	while ( ( j+1 ) *2 <= v.size() ) {

		if ( ( j+1 ) *2 == v.size() && v[j] < v[ ( j+1 ) *2-1] ) {
			exch ( v, j, ( j+1 ) *2-1 );
			break;
		} else if ( ( j+1 ) *2 == v.size() && v[j] > v[ ( j+1 ) *2-1] ) {
			break;
		} else if ( v[ ( j+1 ) *2-1] > v[ ( j+1 ) *2] && v[ ( j+1 ) *2-1] > v[j] ) {
			exch ( v, j, ( j+1 ) *2-1 );
			j = ( j+1 ) *2-1;
		} else if ( v[ ( j+1 ) *2-1] < v[ ( j+1 ) *2] && v[ ( j+1 ) *2] > v[j] ) {
			exch ( v, j, ( j+1 ) *2 );
			j = ( j+1 ) *2;
		} else
			break;
	}

}


#endif /* PRIORITY_QUEUE_H_ */
