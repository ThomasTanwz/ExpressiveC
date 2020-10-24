#include "../Elements/elements.c"
#include "taskQueue.c"

/*
 An expression graph is constructed by a taskQueue that fills in the tasks
 A task can be:
 1. An object
 2. A property
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
  int level = 0;
  char** arrReader = flowArr;
  //put the root task and get the queue started
  Queue* graphQ = constructQueue(*arrReader);
  *arrReader ++;
  index ++;
  //here we go
  while(index < arrSize)
  {
    int flowType = (*arrReader)[0] - '0'; //convert the first character to int
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
    else //else it is a '|' separator
    {
      //need more implementation of separator section.
      //How to represent it in the Queue to create graph levels?
      level += 1;
      *arrReader ++;
    }
    index ++;
  }
  //testing Queue
  printQ(graphQ);
  
  return graphQ;
}

Object* construct_expression_graph(Queue* graphQ)
{
  Object* exprGraph = constructObject(graphQ -> tail -> name, 1);
  popTask(graphQ);
  Object* parent = exprGraph;
  while(!empty(graphQ))
  {
    int eletype = graphQ -> tail -> element;
    char* elename = graphQ -> tail -> name;
    if(eletype == PROPERTY_FLOW)
    {
      Property* newProp = constructProperty(elename);
      objectPropertywise(parent, newProp);
    }
    else if(eletype == OBJECT_FLOW)
    {
      Object* newObj = constructObject(elename, 0);
      objectwise(parent, newObj);
    }
  }
  return exprGraph;
}
