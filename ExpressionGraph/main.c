#include "./taskQueue.c"

void main(void)
{
  Queue* testQ = constructQueue("ellingham graph");
  Task* a = constructTask("name1", 1);
  Task* b = constructTask("name2", 1);
  addTask(testQ, a);
  addTask(testQ, b);
  printQ(testQ);
}
