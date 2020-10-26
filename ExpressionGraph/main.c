#include "./expression_constructor.c"

void main(void)
{
 char* array[14] = {"tree", "1acyclic", "2set", "|", "2edge", "2stuff", "|", "1nontopo", "2vertex", "2bipartite", "|", "2misc.", "|", "1hasSet"};
 Queue* graphQ = construct_expression_queue(array, 14);
 Object* rootObj = construct_expression_graph(graphQ); 
}
