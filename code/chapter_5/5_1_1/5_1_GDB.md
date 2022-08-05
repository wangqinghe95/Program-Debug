(gdb) b 13
Breakpoint 1 at 0x4016c0: file 5_1.cpp, line 13.
(gdb) b 21
Breakpoint 2 at 0x4017ec: file 5_1.cpp, line 21.
(gdb) run this is run arglist
Starting program: /home/user/Desktop/GDB/5_1/5_1 this is run arglist
argc : 5
argv[0] = /home/user/Desktop/GDB/5_1/5_1
argv[1] = this
argv[2] = is
argv[3] = run
argv[4] = arglist

Breakpoint 1, main (argc=5, argv=0x7fffffffd9c8) at 5_1.cpp:13
13          int breakPoint = 0;
(gdb) set args this is set arglist
(gdb) show args
Argument list to give program being debugged when it is started is "this is set arglist".
(gdb) c
Continuing.
argc : 5
argv[0] = /home/user/Desktop/GDB/5_1/5_1
argv[1] = this
argv[2] = is
argv[3] = run
argv[4] = arglist

Breakpoint 2, main (argc=5, argv=0x7fffffffd9c8) at 5_1.cpp:21
21          return 0;
(gdb) r
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/user/Desktop/GDB/5_1/5_1 this is set arglist
argc : 5
argv[0] = /home/user/Desktop/GDB/5_1/5_1
argv[1] = this
argv[2] = is
argv[3] = set
argv[4] = arglist

Breakpoint 1, main (argc=5, argv=0x7fffffffd9c8) at 5_1.cpp:13
13          int breakPoint = 0;
(gdb) 