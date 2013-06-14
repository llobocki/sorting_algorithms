/*
 * merge_sort.h
 *
 *  Created on: 14-06-2013
 *      Author: lukasz
 */

#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

#include <vector>

template <class T> void merge ( std::vector<T> &v, std::vector<T> &d, int lo, int mid, int hi )
{

	int i = lo;
	int j = mid+1;

	for ( int k = lo; k <= hi; ++k ) {
		d[k] = v[k];
	}

	for ( int k = lo; k <= hi; ++k ) {
		if ( i > mid )             	v[k] = d[j++];
		else if ( j > hi )         	v[k] = d[i++];
		else if ( d[j] < d[i] ) 	v[k] = d[j++];
		else                           v[k] = d[i++];
	}
}

template <class T> void merge_sort ( std::vector<T> &v, std::vector<T> &d, int lo, int hi )
{
	if ( hi <= lo ) return;
	int mid = lo + ( hi - lo ) / 2;
	merge_sort ( v, d, lo, mid );
	merge_sort ( v,d,  mid + 1, hi );
	if ( v[mid] > v[mid+1] ) merge ( v, d, lo, mid, hi );
}

template <class T> void merge_sort ( std::vector<T> &v )
{
	std::vector<T> d ( v.size() );
	merge_sort ( v,d, 0, v.size()-1 );
}



#endif /* MERGE_SORT_H_ */
