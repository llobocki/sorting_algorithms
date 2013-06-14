/*
 * insertion_sort.h
 *
 *  Created on: 14-06-2013
 *      Author: lukasz
 */

#ifndef INSERTION_SORT_H_
#define INSERTION_SORT_H_

#include <vector>

template <class T> void exch ( std::vector<T> &v, int a, int b )
{
	T x = v[a];
	v[a] = v[b];
	v[b] = x;
}

template <class T> void sentinel ( std::vector<T> &v )
{
	T x = v[0];
	int j = 0;
	for ( int i = 1; i < v.size(); ++i )
		if ( x > v[i] ) {
			x = v[i];
			j = i;
		}
	exch ( v,0,j );
}


template <class T> void insertion_sort ( std::vector<T> &v )
{
	sentinel ( v );
	T x;
	int j;



	for ( int i = 2; i < v.size(); ++i ) {
		x = v[i];
		for (j = i; j > 0 && x < v[j-1]; j-- ) {
			v[j] = v[j-1];
		}
		if ( x != v[i] )
			v[j] = x;
	}
}



#endif /* INSERTION_SORT_H_ */
