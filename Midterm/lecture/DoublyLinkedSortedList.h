//### Doubly LInked Unsorted List ADT ���� ###
#pragma once
template <class itemtype> //template���� ������ ���
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
	void finditem(itemtype& item, nodetype<itemtype>* locaptr, bool& found); //��ġ���� ����
	void makeempty();
	void insertitem(itemtype item); //find�� insert delete ��� �����ϴ�
	void deleteitem(itemtype item);
	void getnextitem(itemtype& item);
	void resetlist();
private:
	nodetype<itemtype>* listptr;
	nodetype<itemtype>* currentptr;
	int length;
};
