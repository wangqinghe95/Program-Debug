# process of testing

```

(gdb) watch p   //监控指针 p
Hardware watchpoint 5: p    // 监控的实现是硬件
(gdb) watch count           // 监控变量 count
Hardware watchpoint 6: count
(gdb) c
Continuing.

Hardware watchpoint 5: p    // p值发生变化

Old value = (int *) 0x0
New value = (int *) 0x7fffffffde70
main () at watchpoint.cpp:20    // 监控的表达式有变化后，停留在变化后行的下一行
20              if( i == 2) {
(gdb) p q
$5 = (int *) 0x7fffffffde70
(gdb) c
Continuing.

Hardware watchpoint 6: count    // count 发生变化（*p 被赋值为1，p 指向的是 count 变量的地址

Old value = 3
New value = 1
main () at watchpoint.cpp:16
16              if(i == 0) {
(gdb) p *q
$6 = 1
(gdb) c
Continuing.

Hardware watchpoint 6: count    // count 变量发生了变化

Old value = 1
New value = 2
main () at watchpoint.cpp:11
11          for (int i = 0; i < 3; ++i) {
```