#include "elements.h"

/*
 *Constructor for object
 * */
void constructObject(Object* target, char* name, int root)
{
  target = malloc(sizeof(Object));
  target -> name = malloc(sizeof(char) * MAX_ARG_SIZE);
  strcpy(target -> name, name);
  target -> root = root;
  target -> subflow = malloc(sizeof(void*) * MAX_FLOW_SIZE);
  target -> flowIndex = 0;
}

/*
 * Constructor for property
 * */
void constructProperty(Property* target, char* name)
{
   target -> name = malloc(sizeof(char) * MAX_ARG_SIZE);
   strcpy(target -> name, name);
}

void objectwise(Object* start, Object* end)
{
  int index = start -> flowIndex;
  assert(index < MAX_FLOW_SIZE);
  (start -> subflow)[index] = (Object*)(start -> subflow)[index];
  (start -> subflow)[index] = &(*(end));
  start -> flowIndex += 1;
}

void objectPropertywise(Object* start, Property* end)
{
  int index = start -> flowIndex;
  assert(index < MAX_FLOW_SIZE);
  (start -> subflow)[index] = (Property*)(start -> subflow)[index];
  (start -> subflow)[index] = &(*(end));
  start -> flowIndex += 1;
}

