#include "elements.h"

/*
 *typedefs go here
 * */
typdef struct object Object;

/*
 *Constructor for object
 * */
void constructObject(int* propertyList, unsigned int propertyNum)
{
  assert(propertyNum != 0);
  Object* newObject = malloc(sizeof(Object));
  newObject -> properties = malloc(sizeof(int) * propertyNum);
  newObject -> properties = propertyList;
  newObject -> pNum = propertyNum;
}

/*
 * Destructor for object
 * */
void destructObject(Object* o)
{
  free(o);
}
