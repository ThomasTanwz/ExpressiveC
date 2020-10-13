#ifndef ELEMENTS
#define ELEMENTS

/*
 *Definitions of elements go here
 * */

struct object
{
  int* properties;
  unsigned int pNum;
}

void constructObject(int* propertyList, unsigned int propertyNum);
void destructObject(Object* o);

#endif
