#include "./expression_constructor.c"

void main(void)
{
 char* array[10] = {"tree", "1acyclic", "2set", "|", "2edge", "2stuff", "|", "1nontopo", "2vertex", "2bipartite"};
 construct_expression_queue(array, 10); 
}
