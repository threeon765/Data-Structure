#include "SortedList.h"
#include <new>
template <class itemtype>
bool sl<itemtype>::isfull() const {
	return (length == max);
}
template <class itemtype>
int sl<itemtype>::lengthis() const {
	return length;
}
template <class itemtype>
sl<itemtype>::sl() {
	length = 0;
}
template <class itemtype>
void sl<itemtype>::retrieveitem(itemtype& item, bool& found) {
	bool moreToSearch, found = false;
	int loca = 0;
	moreToSearch = (loca < length);
	while (moreToSearch && !found) { //��ġ ã��
		if (item > info[loca]) {
			loca++;
			moreToSearch; = (loca < length);
		}
		else if (item == info[loca]) { //ã��
			moreToSearch = false;
			found = true;
		}
		else { //����
			moreToSearch = false;
		}
	}
}
template <class itemtype>
void sl<itemtype>::insertitem(itemtype item) {
	bool moreToSearch;
	int loca = 0;
	moreToSearch = (loca < length);
	while (moreToSearch) { //��ġ ã��
		if (item >= info[loca]) {
			loca++;
			moreToSearch; = (loca < length);
		}
		else {
			moreToSearch = false;
		}
	}
	for (int i = length; i > loca; i--) { //���� ������ �� ĭ�� ������
		info[i] = info[i - 1];
	}
	info[loca] = item; //������~
	length++;
}
template <class itemtype>
void sl<itemtype>::deleteitem(itemtype item) {
	bool moreToSearch;
	int loca = 0;
	moreToSearch = (loca < length);
	while (moreToSearch) { //��ġ ã��
		if (item >= info[loca]) {
			loca++;
			moreToSearch; = (loca < length);
		}
		else {
			moreToSearch = false;
		}
	}
	if (loca < length) { //���� ���̽� �ĳ���
		for (int i = loca; i < length - 1; i++) { //���� ������ �� ĭ�� ������
			info[i] = info[i + 1];
		}
		length--;
	}
	if (info[loca + 1] == item) { //������ ���̽�
		deleteitem(item); //�ð� ���⵵ O(N^2)
	}
}
template<class itemtype>
void sl<itemtype>::getnextitem(itemtype& item) {
	currentpos++;
	item = info[currentpos];
}
template <class itemtype>
void sl<itemtype>::resetlist() {
	currentptr = -1;
}
template <class itemtype> //binary search
void sl<itemtype>::binretrieveitem(itemtype& item, bool& found) {
	bool moreToSearch;
	found = false;
	int mid;
	int first = 0;
	int last = length - 1;
	moreToSearch = (first <= last);
	while (moreToSearch && !found) { //��ġ ã��
		mid = (first + last) / 2;
		if (item == info[mid]) {
			found = true;
		}
		else if (item > info[mid]) {
			first = mid;
			moreToSearch = (first <= last);
		}
		else if (item < info[mid]) {
			last = mid;
			moreToSearch = (first <= last);
		}
	}
}

