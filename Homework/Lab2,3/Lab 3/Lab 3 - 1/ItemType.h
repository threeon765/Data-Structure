// The following declarations and definitions go into file 
// ItemType.h. 
#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <fstream>

const int MAX_ITEMS = 500;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType 
{ 
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print(std::ostream&) const;
  void Initialize(int number);
  int GetValue();
private:
  int value;
};

#endif
 
