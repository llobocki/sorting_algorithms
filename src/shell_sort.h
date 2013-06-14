/*
 * shell_sort.h
 *
 *  Created on: 14-06-2013
 *      Author: lukasz
 */

#ifndef SHELL_SORT_H_
#define SHELL_SORT_H_


#include <vector>

template <class T> void exch ( std::vector<T> &v, int a, int b )
{
	T x = v[a];
	v[a] = v[b];
	v[b] = x;
}

template <class T> void shell_sort (std::vector<T> &v)
{
	int h = 1;
	int d = 3;
	while ( h < v.size()/d ) h = d*h + 1;
	while ( h >= 1 ) {
		for ( int i = h; i < v.size(); i++ ) {
			for ( int j = i; j >= h && ( v[j] < v[j-h] ); j -= h ) {
				exch ( v, j, j-h );
			}
		}
		h /= d;
	}
}

#endif /* SHELL_SORT_H_ */
