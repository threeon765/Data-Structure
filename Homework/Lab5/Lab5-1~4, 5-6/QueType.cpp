#include "QueType.h"
#include <limits>

QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = max + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = 501;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
}
QueType::~QueType()         // Class destructor
{
  delete [] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = maxQue - 1;
  rear = maxQue - 1;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return (rear == front);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return ((rear + 1) % maxQue == front);
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
    bool min_case = false;
    for (int i = 0; i < maxQue; i++) {
        if (items[i] == -1) {
            items[i] = newItem;
            min_case = true;
        }
    }
    if (min_case == false) {
        if (IsFull())
            throw FullQueue();
        else
        {
            rear = (rear + 1) % maxQue;
            items[rear] = newItem;
        }
    }
}

void QueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    front = (front + 1) % maxQue;
    item = items[front];
  }
}

void ReplaceItem(QueType& queue, ItemType oldItem, ItemType newItem) {
    ItemType checker;
    QueType newQueue;
    while (!queue.IsEmpty()) {
        queue.Dequeue(checker);
        if (oldItem == checker) {
            newQueue.Enqueue(newItem);
        }
        else {
            newQueue.Enqueue(checker);
        }
    }
    while (!newQueue.IsEmpty()) {
        newQueue.Dequeue(checker);
        queue.Enqueue(checker);
    }
}

void QueType::ReplaceItem(ItemType oldItem, ItemType newItem) {
    for (int i = 0; i < maxQue; i++) {
        if (items[i] == oldItem) {
            items[i] = newItem;
        }
    }
}

bool Identical(QueType& one, QueType& another) {
    ItemType cfo; //checker_for_one
    ItemType cfa; //checker_for_another
    QueType to; //temp_one
    QueType ta; //temp_another
    bool result;
    while (!one.IsEmpty() || !another.IsEmpty()) { //둘 중 하나라도 남아있으면 반복
        if (!one.IsEmpty()) {
            one.Dequeue(cfo);
            to.Enqueue(cfo);
        }
        if (!another.IsEmpty()) {
            another.Dequeue(cfa);
            ta.Enqueue(cfa);
        }
        if ((!one.IsEmpty() && another.IsEmpty()) || (one.IsEmpty() && !another.IsEmpty())) {
            result = false;
        }
        else if (cfo != cfa) {
            result = false;
        }
        else {
            result = true;
        }
    }

    while (!to.IsEmpty() || !ta.IsEmpty()) { //원본 복원
        if (!to.IsEmpty()) {
            to.Dequeue(cfo);
            one.Enqueue(cfo);
        }
        if (!ta.IsEmpty()) {
            ta.Dequeue(cfa);
            another.Enqueue(cfa);
        }
    }

    return result;
}

bool QueType::Identical(QueType& another) {
    ItemType cft; //checker_for_this
    ItemType cfa; //checker_for_another
    QueType tt; //temp_this
    QueType ta; //temp_another
    bool result;
    while (!this->IsEmpty() || !another.IsEmpty()) { //둘 중 하나라도 남아있으면 반복
        if (!this->IsEmpty()) {
            this->Dequeue(cft);
            tt.Enqueue(cft);
        }
        if (!another.IsEmpty()) {
            another.Dequeue(cfa);
            ta.Enqueue(cfa);
        }
        if ((!this->IsEmpty() && another.IsEmpty()) || (this->IsEmpty() && !another.IsEmpty())) {
            result = false;
        }
        else if (cft != cfa) {
            result = false;
        }
        else {
            result = true;
        }
    }

    while (!tt.IsEmpty() || !ta.IsEmpty()) { //원본 복원
        if (!tt.IsEmpty()) {
            tt.Dequeue(cft);
            this->Enqueue(cft);
        }
        if (!ta.IsEmpty()) {
            ta.Dequeue(cfa);
            another.Enqueue(cfa);
        }
    }

    return result;
}

int Length(QueType& q) {
    QueType tq; //temporary_queue
    int count = 0;
    int item;
    while (!q.IsEmpty()) {
        q.Dequeue(item);
        count++;
        tq.Enqueue(item);
    }
    while (!tq.IsEmpty()) {
        tq.Dequeue(item);
        q.Enqueue(item);
    }
    return count;
}

void QueType::MinDequeue(ItemType& item) {
    int measure = std::numeric_limits<int>::max();
    for (int i = 0; i < maxQue; i++) {
        if (items[i] >= 0 && items[i] < measure) {
            measure = items[i];
            this->min_pos = i;
        }
    }
    item = items[min_pos];
    items[min_pos] = -1;
}
