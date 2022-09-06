(gdb) r
Starting program: /home/user/Desktop/code/ProgramDebug/catchpoint/catchpoint 

Catchpoint 1 (exception thrown), 0x00007ffff7ae28bd in __cxa_throw ()
   from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1: e = {i = {0, 1127522290}, d = 5805361265115136}
(gdb) up
#1  0x0000000000401013 in func (num1=0, num2=2) at catchpoint.cpp:6
6               throw num1;
(gdb) catch 
Catch requires an event name.
(gdb) catch catch 
Catchpoint 2 (catch)
(gdb) r
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/user/Desktop/code/ProgramDebug/catchpoint/catchpoint 

Catchpoint 1 (exception thrown), 0x00007ffff7ae28bd in __cxa_throw ()
   from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1: e = {i = {0, 1127522290}, d = 5805361265115136}
(gdb) up
#1  0x0000000000401013 in func (num1=0, num2=2) at catchpoint.cpp:6
6               throw num1;
(gdb) c
Continuing.

Catchpoint 2 (exception caught), 0x00007ffff7ae1711 in __cxa_begin_catch ()
   from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1: e = {i = {0, 1127522290}, d = 5805361265115136}
(gdb) up
#1  0x00000000004012aa in main () at catchpoint.cpp:47
47              catch(double e) {
(gdb) c
Continuing.
double e: 0
num: 0

Catchpoint 1 (exception thrown), 0x00007ffff7ae28bd in __cxa_throw ()
   from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1: e = {i = {0, 1127522290}, d = 5805361265115136}
(gdb) up
#1  0x000000000040104b in func (num=1) at catchpoint.cpp:12
12          throw num;
(gdb) c
Continuing.

Catchpoint 2 (exception caught), 0x00007ffff7ae1711 in __cxa_begin_catch ()
   from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1: e = {i = {0, 1127522290}, d = 5805361265115136}
(gdb) up
#1  0x000000000040123b in main () at catchpoint.cpp:42
42              catch(int e)
(gdb) c
Continuing.
int e: 1
num: 1

Catchpoint 1 (exception thrown), 0x00007ffff7ae28bd in __cxa_throw ()
   from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1: e = {i = {0, 1127522290}, d = 5805361265115136}
(gdb) up
#1  0x00007ffff7b0b3f7 in std::__throw_out_of_range_fmt(char const*, ...) ()
   from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
(gdb) c
Continuing.

Catchpoint 2 (exception caught), 0x00007ffff7ae1711 in __cxa_begin_catch ()
   from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1: e = {i = {0, 1127522290}, d = 5805361265115136}
(gdb) up
#1  0x0000000000401395 in main () at catchpoint.cpp:55
55              catch(exception &e) {
(gdb) c
Continuing.
out of range

Catchpoint 1 (exception thrown), 0x00007ffff7ae28bd in __cxa_throw ()
   from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1: e = {i = {0, 1127522290}, d = 5805361265115136}
(gdb) up
#1  0x000000000040114a in main () at catchpoint.cpp:35
35                      throw "num = 3";
(gdb) c
Continuing.

Catchpoint 2 (exception caught), 0x00007ffff7ae1711 in __cxa_begin_catch ()
   from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
1: e = {i = {0, 1127522290}, d = 5805361265115136}
(gdb) up
#1  0x0000000000401325 in main () at catchpoint.cpp:51
51              catch(const char* e) {
(gdb) c
Continuing.
string e: num = 3
num: 3
ch : 
over
[Inferior 1 (process 26343) exited normally]