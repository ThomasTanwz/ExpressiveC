#include "elements.c"

main(){
  char* a = "tree";
  char* b1 = "acyclic";
  char* b2 = "connected";
  Object* obj1 = constructObject(a, 0); 
  Property* prop1 = constructProperty(b1);
  objectPropertywise(obj1, prop1);
  objectPropertywise(obj1, prop1); 
  Property* alpha = obj1 -> subflow[0];
  printf((alpha -> name));
}

