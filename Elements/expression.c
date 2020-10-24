#include "elements.c"
#include "../ExpressionGraph/taskQueue.c"

void verbose(Object* rootObj)
{
  assert(rootObj -> root == 1);
  int flows = rootObj -> flowIndex;
  for(int i = 0; i < flows; i++)
  {
    if(rootObj -> flowArray[i] == PROPERTY_FLOW)
    {
      Property* tmp = rootObj -> subflow[i];
      printf("root %s has such property: %s\n",rootObj -> name, tmp -> name);
    }
    if((rootObj -> flowArray)[i] == OBJECT_FLOW)
    {
      Object* tmp = rootObj -> subflow[i];
      printf("root %s has such sub-object: %s\n",rootObj -> name, tmp -> name);
    }   
  }
}

void print_expression_graph(Object* root)
{
  assert(rootObj -> root == 1);
  Queue* eleQ = constructQueue(root -> name);
  //here goes the while bfs
  while(!empty(eleQ))
  {
    int flows = rootObj -> flowIndex;
    for(int i = 0; i < flows; i++)
    {
      if(rootObj -> flowArray[i] == PROPERTY_FLOW)
      {
        
      }
    }
  }
}
