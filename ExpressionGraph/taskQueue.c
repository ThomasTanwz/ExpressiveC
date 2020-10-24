#include "taskQueue.h"

Task* constructTask(char* taskName, int element)
{
  Task* newTask = malloc(sizeof(Task));
  newTask -> name = malloc(strlen(taskName) + 1);
  strcpy(newTask -> name, taskName);
  newTask -> element = element;
  newTask -> next = NULL;
}

Queue* constructQueue(char* rootName)
{
  Task* rootTask = constructTask(rootName, 2);
  Queue* newQueue = malloc(sizeof(Queue));
  newQueue -> taskCount = 1;
  newQueue -> head = rootTask;
  newQueue -> tail = rootTask;
}

void addTask(Queue* TQ, Task* newTask)
{
  newTask -> next = TQ -> head;
  TQ -> head = newTask;
  TQ -> taskCount ++;
}

void popTask(Queue* TQ)
{
  assert(TQ -> taskCount > 0);
  if(TQ -> taskCount == 1)
  {
    free(TQ -> head);
    TQ -> head = NULL;
    TQ -> tail = NULL;
    TQ -> taskCount = 0;
  }
  else
  {
    for(Task* it = TQ -> head; it != TQ -> tail; it = it -> next)
    {
      if(it -> next == TQ -> tail)
      {
        Task* tmp = it -> next;
	free(tmp);
	TQ -> tail = it;
	it -> next = NULL;
	TQ -> taskCount --;
	break;
      }
    }
  }
}

int empty(Queue* TQ)
{
  return TQ -> taskCount == 0;
}

void printQ(Queue* TQ)
{
  for(Task* it = TQ -> head; it != NULL; it = it -> next)
  {
    printf("%s\n", it -> name);
  }
}

