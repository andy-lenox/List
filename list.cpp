#include "list.h"

//default constructor for Link class
template<class T>
Link<T>::Link()
{
   next = NULL;
}

//2 argument constructor for Link class
template<class T>
Link<T>::Link(T x, Link* inlink)
{
   value = x;
   next = inlink;
}

//default constructor for Queue class
template<class T>
List<T>::List()
{
   //create dummy header
   tail = head = fence = new Link<T>();
   
   //set size
   size = 0;
}

//returns the total sixe of the Queue
template<class T>
int List<T>::length()
{
   return size;
}

//places a new item at the back of the Queue
template<class T>
bool List<T>::append(T& inval)
{
   //append list with new item
   tail = tail -> next = new Link<T>(inval, head -> next);
   //increase the size of the queue
   size++;
   return true;
}

template<class T>
bool List<T>::insert(T& inval)
{
   //append list with new item
   fence -> next = new Link<T>(inval, head -> next);
   //increase the size of the queue
   size++;
   //if the fence was at the end, move the tail to the new end.
   if ( tail == fence ) tail = fence -> next;
   return true;
}

template<class T>
bool List<T>::remove(T& outval)
{
     //Empty on the right
     if ( fence -> next == NULL ) return false;
     //Remember the value
     outval = fence -> next -> value;
     //Remember link node
     Link<T>* tmp = fence -> next;
     //Remove from the list
     fence -> next = tmp -> next;
     //Resest the tail
     if ( tail == tmp ) tail = fence;
     //Reclaim memory
     delete tmp;
     return true;
}

//remove an item from the front of the queue
template<class T>
bool List<T>::dequeue(T& outval)
{
   //if there is only one item in the queue
   //put the tail and head both on the dummy node
   if (head -> next == tail)
   {
      tail = head;
   }
   
   //if there is an element in the stack
   if (size > 0)
   {
      //create tmp pointer to the first variable
      Link<T>* tmp = head -> next;
      
      //make the dummy node point to the second
      //link in the list
      head -> next = head -> next -> next;
      
      //return the value of the removed value
      //through the reference variable
      outval = tmp -> value;
      
      //delete the first variable
      delete tmp;
      
      //decrement the size of the list
      size--;
      return true;
   }
   //otherwise, fail!
   else
   {
      return false;
   }  
}

template<class T>
void List<T>::next()
{
     if ( fence != tail )
     {
          fence = fence -> next;
     }
}

template<class T>
void List<T>::prev()
{
     Link<T>* tmp = head;
     if (fence == head) return;
     while ( tmp -> next != fence ) tmp = tmp -> next;
     fence = tmp;
}

template<class T>
void List<T>::setstart()
{
     fence = head;
}

template<class T>
void List<T>::setend()
{
     fence = tail;
}

template<class T>
bool List<T>::getvalue(T& outval)
{
     if ( fence == tail ) return false;
     
     outval = fence -> next -> value;
     return true;
}

template<class T>
void List<T>::clear()
{
   T tmp;
   while(dequeue(tmp))
   {
      //intentionally empty
   }
}
