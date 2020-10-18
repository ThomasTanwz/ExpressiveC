#include "elements.h"

/*
 *Constructor for object
 * */
Object* constructObject(char* name, int root)
{
  Object* target = malloc(sizeof(Object));
  target -> name = malloc(strlen(name) + 1);
  strcpy(target -> name, name);
  target -> root = root;
  target -> subflow = malloc(sizeof(void*) * MAX_FLOW_SIZE);
  target -> flowIndex = 0;
  return target;
}

/*
 * Constructor for property
 * */
Property* constructProperty(char* name)
{
  Property* target = malloc(sizeof(Property));
  target -> name = malloc(strlen(name) + 1);
  strcpy(target -> name, name);
  return target;
}

/*
 *objectwise operator
 * */
void objectwise(Object* start, Object* end)
{
  int index = start -> flowIndex;
  assert(index < MAX_FLOW_SIZE);
  (start -> subflow)[index] = (Object*)(start -> subflow)[index];
  (start -> subflow)[index] = &(*(end));
  start -> flowIndex += 1;
}

/*
 *object-propertywise operator
 * */
void objectPropertywise(Object* start, Property* end)
{
  int index = start -> flowIndex;
  assert(index < MAX_FLOW_SIZE);
  (start -> subflow)[index] = (Property*)(start -> subflow)[index];
  (start -> subflow)[index] = &(*(end));
  start -> flowIndex += 1;
}

