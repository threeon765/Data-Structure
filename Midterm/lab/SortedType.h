#pragma once
#include <new>
template<class itemtype>
struct nodetype {
	itemtype info;
	nodetype* next;
};

template<class itemtype>
class SortedType {
	nodetype<itemtype>* listptr;
	int length;
public:
	void insertitem(itemtype item) {
		nodetype<itemtype>* locaptr = listptr, predloca = NULL;
		bool found = false;
		nodetype<itemtype>* newptr = new nodetype<itemtype>;
		newptr->info = item;
		if (locaptr == NULL) { //ÅÖ 
			newptr->next = NULL;
			listptr = newptr;
		}
		else { //!ÅÖ
			while (locaptr != NULL && (!found)) {
				if (locaptr->info < item) {
					predloca = locaptr;
					locaptr = locaptr->next;
				}
				else {
					found = true;
				}
			} //¸ø Ã£À¸¸é NULL
		}
		if (predloca == NULL) { //ÆÛ½ºÆ®
			newptr->next = locaptr;
			listptr = newptr;
		}
		else if (locaptr == NULL) { //¶ó½ºÆ® (& ³´¶ò)
			newptr->next = NULL;
			predloca->next = newptr;
		}
		else { //Á¦³Ê·² (& µàÇÃ)
			predloca->next = newptr;
			newptr->next = locaptr;
		}
		length++;
	}
	template <class itemtype>
	void deleteitem(itemtype item) {
		nodetype<itemtype>* locaptr = listptr;
		nodetype<itemtype>* tempptr = listptr;
		if (locaptr != NULL) { //ÅÖ
			if (listptr->info == item) { //ÆÛ½ºÆ®, ÆÛ½ºÆ®&¶ó½ºÆ®
				tempptr = locaptr->next;
				listptr = tempptr;
				item = locaptr->info; //³Ö¾îÁÖ´Â°Å ±î¸ÔÁö¸¶
				delete locaptr;
				length--;
			}
			else {
				while (locaptr != NULL) { //³´¶ò - NULL, ¶ó½ºÆ®&Á¦³Ê·² - ´ë»óÀ§Ä¡
					if (item == locaptr->info) {
						break;
					}
					else {
						tempptr = locaptr;
						locaptr = locaptr->next;
					}
				}
				if (locaptr != NULL) { //!³´¶ò
					tempptr->next = locaptr->next;
					item = locaptr->info;
					delete locaptr;
					length--;
				}
			}
		}
	}
};