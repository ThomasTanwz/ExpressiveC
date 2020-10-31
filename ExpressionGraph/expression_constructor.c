#include "../Elements/elements.c"
#include "taskQueue.c"

/*
 An expression graph is constructed by a taskQueue that fills in the tasks
 A task can be:
 1. An object
 2. A property
 3. A level separator that signals the construction of a new level
 * */


/*
 An array of string that looks like:
 [root, "1prop1", "2obj1", "|", ...]
 "|" is the separator between levels

 This function parses an array of strings into a task queue, where
 each task is identified by the first char of the string.
 * */
Queue* construct_expression_queue(char** flowArr, int arrSize)
{
  assert(arrSize >= 1);
  int index = 0;
  char** arrReader = flowArr;
  //put the root task and get the queue started
  Queue* graphQ = constructQueue(*arrReader);
  *arrReader ++;
  index ++;
  //here we go
  while(index < arrSize)
  {
    int flowType = (*arrReader)[0] - '0'; //convert the first character to int
    int sepSig = '|' - '0'; //define the value of a separator
    Task* newTask;
    if(flowType == PROPERTY_FLOW)
    {
      newTask = constructTask((*arrReader+1), PROPERTY_FLOW);
      *arrReader ++;
      addTask(graphQ, newTask);
    }
    else if(flowType == OBJECT_FLOW)
    {
      newTask = constructTask((*arrReader+1), OBJECT_FLOW);
      *arrReader ++;
      addTask(graphQ, newTask);
    }
    else if(flowType == sepSig)
    {
      newTask = constructTask(*arrReader, SEPARATOR_FLOW); 
      *arrReader ++;
      addTask(graphQ, newTask);
    }
    index ++;
  }
  //testing Queue
  //printQ(graphQ);
  
  return graphQ;
}

/*
 Construct expression graph with the Queue.
 element-wise construction and level-wise
 construction
 * */
Object* construct_expression_graph(Queue* graphQ)
{
  Object* objArray[graphQ -> taskCount];
  memset(objArray, 0, sizeof(Object*) * graphQ -> taskCount);
  int objCount = 0;
  int objIndex = 0;
  Object* objPtr;
  Object* exprGraph = constructObject(graphQ -> tail -> name, 1);
  Object* parent = exprGraph;
  popTask(graphQ);
  while(!empty(graphQ))
  {
    int eletype = graphQ -> tail -> element;
    char* elename = graphQ -> tail -> name;
    if(eletype == PROPERTY_FLOW)
    {
      Property* newProp = constructProperty(elename);
      objectPropertywise(parent, newProp);
      printf("constructing between ");
      printf("\033[1;33m");
      printf("%s, %s\n", parent -> name, newProp -> name);
      printf("\033[0m");
    }
    else if(eletype == OBJECT_FLOW)
    {
      Object* newObj = constructObject(elename, 0);
      objArray[objCount] = newObj;
      objCount ++;
      //for debug purpose
      printf("constructing between ");
      printf("\033[1;36m");
      printf("%s, %s\n", parent -> name, newObj -> name);
      printf("\033[0m"); 
      objectwise(parent, newObj); 
    }
    else if(eletype == SEPARATOR_FLOW)
    {
      assert(objCount >= 1);
      objPtr = objArray[objIndex];
      parent = objPtr;
      objIndex ++;
    }
    popTask(graphQ);
  }
  return exprGraph;
}
