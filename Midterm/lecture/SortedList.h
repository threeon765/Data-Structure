//### Unsorted List ADT ¸í¼¼¼­ ###
#pragma once

class fulllist {};
class emptylist {};
template <class itemtype>
class sl { //LinkedUnSortedList
public:
	sl();
	bool isfull() const;
	int lengthis() const;
	void retrieveitem(itemtype& item, bool& found);
	void insertitem(itemtype item);
	void deleteitem(itemtype item);
	void getnextitem(itemtype& item);
	void resetlist();
	void binretrieveitem(itemtype& item, bool& found);
private:
	int max = 20;
	itemtype info[20];
	int length;
	int currentpos;
};
