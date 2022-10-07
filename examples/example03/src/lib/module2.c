#include <stdio.h>
#include "module1.h"
#include "module2.h"

void fun2() {
  fun1();
  puts("Hello from module 2!");
}
