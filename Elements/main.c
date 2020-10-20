#include "expression.c"

/*
 *This driver program is mainly used for testing element constructing
 * */
void main(void){
  char* a1 = "tree";
  char* b1 = "acyclic";
  char* b2 = "connected";
  char* a2 = "vertex set";
  Object* obj1 = constructObject(a1, 1);
  Object* obj2 = constructObject(a2, 0);
  Property* prop1 = constructProperty(b1);
  Property* prop2 = constructProperty(b2);
  objectwise(obj1, obj2);
  objectPropertywise(obj1, prop1);
  objectPropertywise(obj1, prop2);
  verbose(obj1);
}

