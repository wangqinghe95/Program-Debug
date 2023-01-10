(gdb) catch load share
Catchpoint 1 (load)
(gdb) b 6
Breakpoint 2 at 0x400d6e: file main.cpp, line 6.
(gdb) r
Starting program: /home/user/Desktop/code/ProgramDebug/shared/main 

Catchpoint 1
  Inferior loaded ./libshared.so
    /usr/lib/x86_64-linux-gnu/libstdc++.so.6
    /lib/x86_64-linux-gnu/libgcc_s.so.1
    /lib/x86_64-linux-gnu/libc.so.6
    /lib/x86_64-linux-gnu/libm.so.6
dl_main (phdr=<optimized out>, phnum=<optimized out>, 
    user_entry=<optimized out>, auxv=<optimized out>) at rtld.c:2206
2206    rtld.c: No such file or directory.
(gdb) c
Continuing.

Breakpoint 2, main () at main.cpp:6
6           Fish salmon("salmon", 3, 10);
(gdb) s
Fish::Fish (this=0x7fffffffde20, str="", num=3, size=10) at shared.cpp:3
3       Fish::Fish(std::string  str, uint num, uint size):m_strType(str),animal(num,size)
(gdb) 
animal::animal (this=0x7fffffffde20, num=3, size=10) at animal.cpp:11
11      animal::animal(uint num, uint size):m_number(num),m_size(size)
(gdb) 
13          std::cout << "this is a construct function with two param for animal" << std::endl;
(gdb) 
this is a construct function with two param for animal
14          std::cout << "func = " <<  __func__ << " line = " << __LINE__ << std::endl;
(gdb) 
func = animal line = 14
15          std::cout << "m_number = " <<  m_number << " m_size = " << m_size << std::endl;
(gdb) 
m_number = 3 m_size = 10
17      }
(gdb) 
Fish::Fish (this=0x7fffffffde20, str="", num=3, size=10) at shared.cpp:5
5           std::cout << "the function with two paramr for Fish" << std::endl;
(gdb) 
the function with two paramr for Fish
6           std::cout << "func = " <<  __func__ << " line = " << __LINE__ << std::endl;
(gdb) 
func = Fish line = 6
7           std::cout << "str = " << str << " num = " << num << " size = " << size <<  std::endl;
(gdb) 
str = salmon num = 3 size = 10
8       }
(gdb) 
main () at main.cpp:7
7           std::cout << "------------" << std::endl;
(gdb) 
------------
8           Fish whale;
(gdb) 
Fish::Fish (this=0x7fffffffde50) at shared.cpp:10
10      Fish::Fish()
(gdb) 
animal::animal (this=0x7fffffffde50) at animal.cpp:4
4       animal::animal():m_number(0),m_size(0)
(gdb) 
6           std::cout << "this is no param construct functio for animal" << std::endl;
(gdb) c
Continuing.
this is no param construct functio for animal
func = animal line = 7
m_number = 0 m_size = 0
the function with no paramr for Fish
func = Fish line = 13
[Inferior 1 (process 4855) exited normally]
(gdb) info sharedlibrary 
From                To                  Syms Read   Shared Object Library
0x00007ffff7dd7ac0  0x00007ffff7df57c0  Yes         /lib64/ld-linux-x86-64.so.2
0x00007ffff7bd4fc0  0x00007ffff7bd56ae  Yes         ./libshared.so
0x00007ffff78dbd20  0x00007ffff7987cc9  Yes (*)     /usr/lib/x86_64-linux-gnu/libstdc++.so.6
0x00007ffff763ea70  0x00007ffff764e8b5  Yes (*)     /lib/x86_64-linux-gnu/libgcc_s.so.1
0x00007ffff72918b0  0x00007ffff73e4c04  Yes         /lib/x86_64-linux-gnu/libc.so.6
0x00007ffff6f6e600  0x00007ffff6fdfd2a  Yes         /lib/x86_64-linux-gnu/libm.so.6
(*): Shared library is missing debugging information.