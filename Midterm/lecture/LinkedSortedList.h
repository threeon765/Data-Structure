//### LInked Unsorted List ADT 명세서 ###
#pragma once
template <class itemtype> //template으로 구현할 경우
struct nodetype {
	itemtype info;
	nodetype* next;
};

class fulllist {};
class emptylist {};
template <class itemtype>
class lsl { //LinkedUnSortedList
public:
	lsl();
	~lsl();
	bool isfull() const;
	int lengthis() const;
	void retrieveitem(itemtype& item, bool& found); //Unsorted와 다름
	void makeempty();
	void insertitem(itemtype item); //Unsorted와 다름
	void deleteitem(itemtype item);
	void getnextitem(itemtype& item);
	void resetlist();
	void reverse();
	lsl(const lsl<itemtype>& another);
	void merge(lsl<itemtype> another, lsl<itemtype>& result);
	void deleteitem_ver2(itemtype item);
private:
	nodetype<itemtype>* listptr;
	nodetype<itemtype>* currentptr;
	int length;
};
