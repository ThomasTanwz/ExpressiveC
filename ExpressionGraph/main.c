#include "./taskQueue.c"

void main(void)
{
  Queue* testQ = constructQueue("ellingham graph");
  Task* a = constructTask("name1", 1);
  Task* b = constructTask("name2", 1);
  Task* c = constructTask("name3", 1);
  addTask(testQ, a);
  addTask(testQ, b);
  addTask(testQ, c);
  printQ(testQ);
  popTask(testQ);
  printf(testQ -> tail -> name);
  printQ(testQ);
}
