Reading symbols from main...done.
(gdb) l
1       #include<iostream>
2       #include"static_lib.h"
3       int main()
4       {
5           staticlib CMyStaticLib;
6           int a = 5;
7           int b = 2;
8           std::cout << "a/b = " << CMyStaticLib.division(2,5) << std::endl;
9           std::cout << "a+b = " << CMyStaticLib.add(2,5) << std::endl;
10          return 0;
(gdb) b 8
Breakpoint 1 at 0x400a38: file main.cpp, line 8.
(gdb) r
Starting program: /home/user/Desktop/code/ProgramDebug/staticlib/main 

Breakpoint 1, main () at main.cpp:8
8           std::cout << "a/b = " << CMyStaticLib.division(2,5) << std::endl;
(gdb) s
staticlib::division (this=0x7fffffffde5f, divisor=2, 
    dividend=5) at static_lib.cpp:31
warning: Source file is more recent than executable.
31          if(divisor == 0) {
(gdb) 
36          return (int)(dividend/divisor);
(gdb) 
37      }(gdb) 
a/b = 2
main () at main.cpp:9
9           std::cout << "a+b = " << CMyStaticLib.add(2,5) << std::endl;
(gdb) 
staticlib::add (this=0x7fffffffde5f, num1=2, num2=5)
    at static_lib.cpp:25
25          cout << __func__ << " " << __LINE__ << " " << endl;
(gdb) 
add25
26          int result = num1 + num2;
(gdb) 
27          return result;
(gdb) 
28      }
(gdb) 
a+b = 7
main () at main.cpp:10
10          return 0;
(gdb) 
5           staticlib CMyStaticLib;
(gdb)