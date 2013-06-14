/*
 * selection_sort.h
 *
 *  Created on: 14-06-2013
 *      Author: lukasz
 */

#ifndef SELECTION_SORT_H_
#define SELECTION_SORT_H_

#include <iostream>
#include <vector>

template <class T> void exch ( std::vector<T> &v, int a, int b )
{
	T x = v[a];
	v[a] = v[b];
	v[b] = x;
}

template <class T> void selection_sort ( std::vector<T> &v )
{
	T x;
	int y;
	for ( int i = 0; i < v.size()-1; ++i ) {
		x = v[i];
		y = i;
		for ( int j = i+1; j < v.size(); ++j )
			if ( x > v[j] ) {
				x = v[j];
				y = j;
			}
		exch ( v,i,y );
	}
}


#endif /* SELECTION_SORT_H_ */
