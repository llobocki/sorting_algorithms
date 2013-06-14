/*
 * quick_sort.h
 *
 *  Created on: 14-06-2013
 *      Author: lukasz
 */

#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

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

template <class T> int partition ( std::vector<T> &v, int a, int b )
{
	int i = a;
	int j = b + 1;
	int x = v[a];

	while ( true ) {


		while ( v[++i] < x );



		while ( x < v[--j] );



		if ( i >= j ) break;


		exch ( v, i, j );
	}
	exch ( v, a, j );

	return j;
}

template <class T> void quick_sort ( std::vector<T> &v, int a, int b )
{
	if ( b <= a ) return;
	int j = partition ( v, a, b );
	quick_sort ( v, a, j-1 );
	quick_sort ( v, j+1, b );
}

template <class T> void quick_sort ( std::vector<T> &v)
{
	sentinel(v);
	quick_sort ( v, 0, v.size()-1 );

}


#endif /* QUICK_SORT_H_ */
