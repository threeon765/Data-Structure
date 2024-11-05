//### LInked Unsorted List ADT ���� ###
#pragma once
template <class itemtype> //template���� ������ ���
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
	void retrieveitem(itemtype& item, bool& found); //Unsorted�� �ٸ�
	void makeempty();
	void insertitem(itemtype item); //Unsorted�� �ٸ�
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
