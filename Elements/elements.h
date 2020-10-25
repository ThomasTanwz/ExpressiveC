#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#ifndef ELEMENTS
#define ELEMENTS

/*
 *Definitions of constants go here
 * */
#define MAX_FLOW_SIZE 10
#define PROPERTY_FLOW 1
#define OBJECT_FLOW 2
#define SEPARATOR_FLOW 3
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
  int flowArray[MAX_FLOW_SIZE];
};

struct property
{
  char* name;
};

/*
 *Declarations of functions go here
 * */
Object* constructObject(char* name, int root);

Property* constructProperty(char* name);

void objectwise(Object* start, Object* end);

void objectPropertywise(Object* start, Property* end);
#endif
