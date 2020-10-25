#include "./expression_constructor.c"

void main(void)
{
 char* array[10] = {"tree", "1acyclic", "2set", "|", "2edge", "2stuff", "|", "1nontopo", "2vertex", "2bipartite"};
 Queue* graphQ = construct_expression_queue(array, 10);
 Object* rootObj = construct_expression_graph(graphQ);
 
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
      printf("%d", tmp -> flowIndex);
    }   
  }
}
