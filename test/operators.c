#include "elements.h"

int main(void)
{
  int arr1[5] = {1, 2, 3, 4, 5};
  int arr2[6] = {1, 2, 3, 4, 5, 6};
  struct object obj1 = {arr1, 5};
  struct object obj2 = {arr2, 6};
  printf("%d", hasSubset(obj2, obj1));
  return 0;
}

int hasSubset(struct object obj1, struct object obj2){
  if(obj1.pNum >= obj2.pNum)
  {
    int* i2 = obj2.properties;
    for(int* i1 = obj1.properties; i1 < obj1.properties + obj2.pNum; i1++)
    {
      if(*i1 != *i2)
      {
        return 0;
      }
    }
    return 1;
  }
  return 1;
}

