// =====================================
// One task on the StackCalc project
// (C) rdmr, 2k6
// Unautorized Duplication Appreciated!
// =====================================

//
// Stack Calculator (non-graphic version)
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "RealStack.h"

static void onAdd();
static void onSub();
static void onMul();
static void onDiv();
static void onNod();
static void onCos();
static void onSin();
static void onTan();
static void onACos();
static void onASin();
static void onATan();
static void onPower();
static void onPush(const char* line);
static void onPop();
static void onInit();
static void display();
static void printHelp();
static void onShow();

static RealStack * Stack = 0;

int main()
{
    printHelp();
    char line[256];
    Stack = new RealStack();
    scanf("%s", line);
    while (*line != 0)
  {
        int linelen = (int) strlen(line);
        try
    {
            if (strcmp(line, "+") == 0) onAdd();
            else if (strcmp(line, "-") == 0) onSub();
            else if (strcmp(line, "*") == 0) onMul();
            else if (strcmp(line, "/") == 0) onDiv();
      else if (strcmp(line, "d") == 0) onNod(); 
            else if (strcmp(line, "=") == 0) display();
            else if (strcmp(line, "cos") == 0) onCos();
            else if (strcmp(line, "sin") == 0) onSin();
            else if (strcmp(line, "tan") == 0) onTan();
            else if (strcmp(line, "acos") == 0) onACos();
            else if (strcmp(line, "asin") == 0) onACos();
            else if (strcmp(line, "atan") == 0) onACos();
      else if (strcmp(line, "^") == 0) onPower();
            else if ((linelen > 0 && isdigit(line[0])) || (linelen > 1 && (line[0] == '-' || line[0] == '+') && isdigit(line[1]))) onPush(line);
            else if (strcmp(line, "pop") == 0) onPop();
            else if (strcmp(line, "init") == 0) onInit();
            else if (strcmp(line, "show") == 0) onShow();
            else if (strcmp(line, "") == 0 || (linelen > 0 && (line[0] == 'q' || line[0] == 'Q'))) break;
            else printHelp();
        }
    catch (StackException& e) { printf("Stack Exception: %s\n", e.reason); }
        scanf("%s", line);
    }
  delete Stack; 
    return 0;
}

static void onAdd() { double y = Stack->pop(); double x = Stack->pop(); Stack->push(x + y); display(); }
static void onSub() { double y = Stack->pop(); double x = Stack->pop(); Stack->push(x - y); display(); }
static void onMul() { double y = Stack->pop(); double x = Stack->pop(); Stack->push(x * y); display(); }
static void onDiv() { double y = Stack->pop(); double x = Stack->pop(); Stack->push(x / y); display(); }

static void onNod()
{
    int y = (int) Stack->pop();
    int x = (int) Stack->pop();
    if (y > x) { int tmp = x; x = y; y = tmp; }
    while (y) { int r = x % y; x = y; y = r; }
    Stack->push(x);
    display();
}

static void onCos() { double x = Stack->pop(); Stack->push(cos(x)); display(); }
static void onACos() { double x = Stack->pop(); Stack->push(acos(x)); display(); }
static void onSin() { double x = Stack->pop(); Stack->push(sin(x)); display(); }
static void onASin() { double x = Stack->pop(); Stack->push(asin(x)); display(); }
static void onTan() { double x = Stack->pop(); Stack->push(tan(x)); display(); }
static void onATan() { double x = Stack->pop(); Stack->push(atan(x)); display(); }

static void onPower()
{
  double Result = 1;
  int Power = (int) Stack->pop();
  double Base = Stack->pop();
  while(Power)
  {
    if (Power % 2) Result *= Base;
    Base *= Base;
    Power /= 2;
  }
  Stack->push(Result);
  display();
}

static void onPush(const char* line) { double x = atof(line); Stack->push(x); }
static void onPop() { Stack->pop(); }
static void onInit() { Stack->init(); }
static void display() { if (!Stack->empty()) printf("=%lf\n", Stack->top()); else printf("stack empty\n"); }
static void onShow()
{
    int d = Stack->depth();
    printf("Depth of stack = %d.", d);
    if (d > 0) printf(" Stack elements:\n"); else printf("\n");
    for (int i = 0; i < d; i++) printf("\t%lf\n", Stack->elementAt(i));
}

static void printHelp()
{
    printf("Stack Calculator commands:\n\t<number>\tPush to stack\n"
        "\t+, -, *, /, ^\tAriphmetic operations\n\td\t\tLargest common divider\n"
        "\t=\t\tDisplay the stack top\n\tpop\t\tRemove the stack top\n"
        "\tshow\t\tShow the stack\n\tinit\t\tErase the stack\n\tquit\t\tEnd the program\n"
    );
}
