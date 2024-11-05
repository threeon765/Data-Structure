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
	//currentptr Ȱ���Ͽ� ����Ʈ �ջ� ���� ������ ȹ��
	void getnextitem(itemtype& item);
	void resetlist();
private:
	nodetype<itemtype>* listptr;
	nodetype<itemtype>* currentptr;
	int length;
};
