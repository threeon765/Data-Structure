//### Doubly LInked Unsorted List ADT 명세서 ###
#pragma once
template <class itemtype> //template으로 구현할 경우
struct nodetype {
	itemtype info;
	nodetype* next;
	nodetype* back;
};

class fulllist {};
class emptylist {};
template <class itemtype>
class dlsl { //Doubly LinkedUnSortedList
public:
	dlsl();
	~dlsl();
	bool isfull() const;
	int lengthis() const;
	void finditem(itemtype& item, nodetype<itemtype>* locaptr, bool& found); //위치까지 포착
	void makeempty();
	void insertitem(itemtype item); //find와 insert delete 모두 유사하다
	void deleteitem(itemtype item);
	void getnextitem(itemtype& item);
	void resetlist();
private:
	nodetype<itemtype>* listptr;
	nodetype<itemtype>* currentptr;
	int length;
};
