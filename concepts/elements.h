#include <assert.h>
#include <stdlib.h>
#include <string.h>
#ifndef ELEMENTS
#define ELEMENTS

/*
 *Definitions of constants go here
 * */
#define MAX_ARG_SIZE 256
#define MAX_FLOW_SIZE 5


/*
 *typedefs go here
 * */
typedef struct object Object;
typedef struct property Property;


/*
 *Definitions of elements go here
 * */
struct object
{
  char* name;
  int root;
  void** subflow;
  int flowIndex;
};

struct property{
  char* name;
};

/*
 *Declarations of functions go here
 * */

void constructObject(Object* target, char* name, int root);

void constructProperty(Property* target, char* name);

void objectwise(Object* start, Object* end);

void objectPropertywise(Object* start, Property* end);
#endif
