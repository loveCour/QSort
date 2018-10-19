#pragma once
#include <stack>
using namespace std;

template <typename T>
inline int findMid(int start, int end, T* dstArray) {
	int mid = (end - start) >> 1;
	if (dstArray[start] > dstArray[end]) {
		swap(start, end);
	}
	if (dstArray[mid] > dstArray[end]) {
		swap(mid, end);
	}
	if (dstArray[start] > dstArray[mid]) {
		swap(start, mid);
	}
	return mid;
}

template <typename T>
int QuickSort(int size, T* dstArray) {
	int start = 0;
	int end = size-1;
	int pivotIdx;
	T pivot;
	stack<int> astack;	
	astack.push(end);
	astack.push(start);
	while (astack.size() > 0) {
		int start = astack.top();
		astack.pop();
		int end = astack.top();
		astack.pop();
		int i = start;
		int j = end;
		pivotIdx = i;
		pivot = dstArray[pivotIdx];		
		swap(dstArray[pivotIdx], dstArray[i]);
		pivotIdx = i;
		i++;
		while (i < j) {
			if (pivot < dstArray[i]) {
				swap(dstArray[i], dstArray[j]);
				j--;
			}
			else {
				i++;
			}
		}
		if (pivot > dstArray[i]) {
			swap(dstArray[pivotIdx], dstArray[i]);	
			if (end > i+1) {
				astack.push(end);
				astack.push(i+1);
			}			
		}
		else if (end > i) {
			astack.push(end);
			astack.push(i);
		}
		if (i - 1 > start) {
			astack.push(i - 1);
			astack.push(start);
		}
	}
}
	