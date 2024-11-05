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
class lusl { //LinkedUnSortedList
public:
	lusl();
	~lusl();
	bool isfull() const;
	int lengthis() const;
	void retrieveitem(itemtype& item, bool& found);
	void makeempty();
	void insertitem(itemtype item);
	void deleteitem(itemtype item);
	//currentptr 활용하여 리스트 손상 없이 아이템 획득
	void getnextitem(itemtype& item);
	void resetlist();
private:
	nodetype<itemtype>* listptr;
	nodetype<itemtype>* currentptr;
	int length;
};
