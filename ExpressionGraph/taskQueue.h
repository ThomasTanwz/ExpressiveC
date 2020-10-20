#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#ifndef TASK_QUEUE
#define TASK_QUEUE
typedef struct task Task;
typedef struct taskQueue Queue;

struct task
{
  char* name;
  int element;
  struct task* next;
};

struct taskQueue
{
  int taskCount;
  struct task* head;
  struct task* tail;
};

Task* constructTask(char* taskName, int element);

/*Explanation of rootName:
 *Any nontrivial expression graph must have at least a root;
 */
Queue* constructQueue(char* rootName);
void addTask(Queue* TQ, Task* newTask);
void popTask(Queue* TQ);
int empty(Queue* TQ);
void printQ(Queue* TQ);
#endif
