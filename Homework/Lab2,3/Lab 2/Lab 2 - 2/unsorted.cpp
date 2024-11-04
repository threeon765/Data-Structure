// Implementation file for Unsorted.h
#include "unsorted.h"

UnsortedType::UnsortedType()
{
  length = 0;
}
bool UnsortedType::IsFull() const
{
  return (length == MAX_ITEMS);
}

int UnsortedType::LengthIs() const
{
  return length;
}
void UnsortedType::RetrieveItem(ItemType& item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged. 
{
  bool moreToSearch;
  int location = 0;
  found = false;

  moreToSearch = (location < length);

  while (moreToSearch && !found) 
  {
    switch (item.ComparedTo(info[location]))
    {
      case LESS    : 
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
}
void UnsortedType::InsertItem(ItemType item)
// Post: item is in the list.
{
  info[length] = item;
  length++;
}
void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL)
    location++;

  info[location] = info[length - 1];
  length--;
}
void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}
void UnsortedType::GetNextItem(ItemType& item)
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  item = info[currentPos];
}
void UnsortedType::DeleteItem_a(ItemType item)
// Function: Deletes the element whose key matches item's key.
 // Pre:  List has been initialized.
 //       Key member of item is initialized.
 //       삭제할 요소는 리스트에 하나만 존재하거나, 아에 없을 수 있다.
 // Post: No element in list has a key matching item's key.
 //	   삭제할 요소가 리스트 내에 없으면 리스트는 변하지 않는다.
{   
    bool deleted = false;
    for (int i = 0; i < length && !deleted; i++) {
        if (item.ComparedTo(info[i]) == EQUAL) {
            info[i] = info[length - 1];
            length--;
            deleted = true;
        }
    }
}
void UnsortedType::DeleteItem_c(ItemType item)
// Function: Deletes the element whose key matches item's key.
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  //       삭제할 요소가 하나 이상 존재한다.
  // Post: No element in list has a key matching item's key.
  //	   삭제할 요소가 리스트 내에 있으면 삭제될 모든 요소를 삭제한다.
{
    int location = 0;
    while (location < length) {
        if (item.ComparedTo(info[location]) == EQUAL) {
            info[location] = info[length - 1];
            length--;
        }
        else {
            location++;
        }
    }
}