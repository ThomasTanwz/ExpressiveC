#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#ifndef ELEMENTS
#define ELEMENTS

/*
 *Definitions of constants go here
 * */
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
