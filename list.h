#ifndef LIST_H
#define LIST_H

//Links make up the elements in the Queue
template<class T>
class Link
{
      public:
             Link();                     //default constructor
             Link(T x, Link* inlink);    //2 argument constructor
             T value;                    //the value of the link
             Link* next;                 //pointer to the next value
};


//Linked list, now with queue abilities!
template<class T>
class List
{
      private:
              int size;        //The size of the Queue
              Link<T>* head;   //Pointer to the front of the Queue
              Link<T>* tail;   //Pointer to the end of the Queue
              Link<T>* fence;   //Pointer to the end of the Queue              
              
      public:
             List();                  //default constructor
             int length();             //returns the size of the list
             bool append(T& inval);   //puts an item at the end of the line
             bool dequeue(T& outval);  //removes an item from the front of the list
             bool insert(T& inval);   //inserts a new item at the fence
             bool remove(T& outval); //remove an item at the fence
             void next();            //move the fence to the right
             void prev();            //move the fence to the left
             void setstart();        //move the fence to the beginning
             void setend();          //move the fence to the end
             bool getvalue(T& outval); //return current value at the fence
             void clear();             //removes all items from the list
};

#endif //queue.h
