#ifndef ELEMENTS
#define ELEMENTS

struct object
{
  int* properties;
  unsigned int pNum;
}

void constructObjec(struct object* o, int* propertyList, unsigned int propertyNum);


#endif
