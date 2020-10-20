#include "./taskQueue.c"

void main(void)
{
  Queue* testQ = constructQueue("ellingham graph");
  addTask(testQ, "snake graph");
  addTask(testQ, "dijkstra's theorem");
  printQ(testQ);
}
