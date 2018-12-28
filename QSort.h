#pragma once
#include <stack>
using namespace std;

template <typename T>
bool comp(const T a, const T b) {
	return a < b;
}

template <typename T>
inline int findMid(int start, int end, T* dstArray) 
{//최악의 경우의 수를 피하기 위해, 범위의 처음, 가운데, 마지막 값 중에서
//크기가 중간인 값을 피벗으로 사용하기 위한 함수  
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
void QuickSort(int size, T* dstArray, bool(*compf)(const T, const T) = comp) {
	int start = 0;
	int end = size-1;
	int pivotIdx;
	T pivot;
	stack<int> rangeStack;	//소팅범위를 저장하는 스택
	rangeStack.push(end);
	rangeStack.push(start);
	while (rangeStack.size() > 0) {
		int start = rangeStack.top();
		rangeStack.pop();
		int end = rangeStack.top();
		rangeStack.pop();
		int i = start;
		int j = end;
		pivotIdx = findMid(start, end, dstArray);
		pivot = dstArray[pivotIdx];		
		swap(dstArray[pivotIdx], dstArray[i]);
		pivotIdx = i;
		i++;
		while (i < j) 
		{//i가 j보다 같거나 커지면 크기에 따른 분류를 마침
			if (compf(pivot, dstArray[i])) {
				swap(dstArray[i], dstArray[j]);
				j--;
			}
			else {
				i++;
			}
		}
		//이제 인덱스 i에 들어있는 값과 피벗을 비교하여,
		if (!compf(pivot, dstArray[i]))
		{//피벗이 더 크면 인덱스 i가 피벗값이 위치해야하는 곳이므로 스왑한다.
			swap(dstArray[pivotIdx], dstArray[i]);	
			if (end > i+1)
			{//이제 i+1 ~ end를 정렬해야하기에 스텍에 소팅범위를 등록한다.
			//만약 i+1이 end와 같다면 나머지의 범위의 크기는 1이하이고 이것은 이미 정렬되었다는 의미이미로 스텍에 넣지 않는다.
				rangeStack.push(end);
				rangeStack.push(i+1);
			}			
		}
		else if (end > i)
		{//피벗이 더 작고, end보다 i가 작으면  i ~ end 까지 정렬해야 하므로 스텍에 등록한다.
			rangeStack.push(end);
			rangeStack.push(i);
		}
		if (i - 1 > start)
		{//start ~ i-1 까지 스텍에 등록한다.
		//만약 i - 1 <= start라면 i이전의 범위의 크기는 1이하이고 이것은 이미 정렬되었다는 의미이므로 스텍에 넣지 않는다.
			rangeStack.push(i - 1);
			rangeStack.push(start);
		}
	}
}
	