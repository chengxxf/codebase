#ifndef TEST_H
#define TEST_H

typedef void (*PFn)() ;

PFn g_PrintTrace=0;
void setPrintTrace(PFn fn);
void func();
void func1();
void func2();
void func3();
void exeTrace();


#endif
