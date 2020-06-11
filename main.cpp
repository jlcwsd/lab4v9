#include <iostream>
#include "heap.h"

using namespace std;

int main()
{
  Heap <int> obj (10);
  int m = 2;
  obj.insert(2);
  obj.insert(4);
  obj.insert(-8);
  obj.insert(16);
  obj.insert(32);
  obj.insert(-64);
  obj.insert(128);
  obj.insert(256);
  obj.insert(11);
  obj.insert(33);
  obj.print();
  while (m>0)
  {
      obj.check(8);
      m--;
  }
  obj.print();
  obj.isEmpty();
  if (obj.isEmpty())
      {
          cout << "True" << endl;
      }
      if (!obj.isEmpty())
      {
          cout << "False" << endl;
      }
  obj.deletee(3);
  obj.print();
  obj.set(9,1);
  obj.print();
  obj.clear();
}
