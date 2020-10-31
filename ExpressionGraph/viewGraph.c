#include "./expression_constructor.c"

/*
 *traverse the expression level by level
 recursion is a bad idea; need to modify 
 task Queue for bfs
 * */
void visualize_expression(void* target, int level)
{
  Object* ptr = (Object*)target;
  if(ptr -> flowIndex == 0)
	  return;
  if(level == 0)
	  printf("%s", ptr -> name);
  
}
