#pragma once
#include <stack>
using namespace std;

template <typename T>
bool comp(const T a, const T b) {
	return a < b;
}

template <typename T>
inline int findMid(int start, int end, T* dstArray) 
{//�־��� ����� ���� ���ϱ� ����, ������ ó��, ���, ������ �� �߿���
//ũ�Ⱑ �߰��� ���� �ǹ����� ����ϱ� ���� �Լ�  
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
	stack<int> rangeStack;	//���ù����� �����ϴ� ����
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
		{//i�� j���� ���ų� Ŀ���� ũ�⿡ ���� �з��� ��ħ
			if (compf(pivot, dstArray[i])) {
				swap(dstArray[i], dstArray[j]);
				j--;
			}
			else {
				i++;
			}
		}
		//���� �ε��� i�� ����ִ� ���� �ǹ��� ���Ͽ�,
		if (!compf(pivot, dstArray[i]))
		{//�ǹ��� �� ũ�� �ε��� i�� �ǹ����� ��ġ�ؾ��ϴ� ���̹Ƿ� �����Ѵ�.
			swap(dstArray[pivotIdx], dstArray[i]);	
			if (end > i+1)
			{//���� i+1 ~ end�� �����ؾ��ϱ⿡ ���ؿ� ���ù����� ����Ѵ�.
			//���� i+1�� end�� ���ٸ� �������� ������ ũ��� 1�����̰� �̰��� �̹� ���ĵǾ��ٴ� �ǹ��̷̹� ���ؿ� ���� �ʴ´�.
				rangeStack.push(end);
				rangeStack.push(i+1);
			}			
		}
		else if (end > i)
		{//�ǹ��� �� �۰�, end���� i�� ������  i ~ end ���� �����ؾ� �ϹǷ� ���ؿ� ����Ѵ�.
			rangeStack.push(end);
			rangeStack.push(i);
		}
		if (i - 1 > start)
		{//start ~ i-1 ���� ���ؿ� ����Ѵ�.
		//���� i - 1 <= start��� i������ ������ ũ��� 1�����̰� �̰��� �̹� ���ĵǾ��ٴ� �ǹ��̹Ƿ� ���ؿ� ���� �ʴ´�.
			rangeStack.push(i - 1);
			rangeStack.push(start);
		}
	}
}
	