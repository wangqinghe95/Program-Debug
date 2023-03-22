# GDB Command

![GDB命令大全](https://www.gdbtutorial.com/gdb_commands)
## 启动/退出
1. run/r: 启动程序
    + run [arguments...] : 以 [arguments] 的参数启动程序，其中 [arguments...] 可选
    + run > [file_name]: 启动程序，程序的输入保存到 file_name 文件中
2. start : 运行程序到 main 函数的第一行代码
    + start [arguments...]: 以参数列表 [arguments] 运行程序，其中 [arguments...] 可选
3. args
    + show args : 查看当前程序启动时的参数列表
    + set args : 设置程序启动时的参数列表，run/r 启动后才会生效
4. kill: 停止程序
5. quit/q: 退出程序

## 日志
1. logging
    + set logging on/off: 打开/关闭日志文件
    + set logging file [file_name]: 日志输出到 file_name 中，默认文件名为 gdb.txt
# 执行
1. step/s: 单步运行（可以执行到函数内部）
    + step [number]: 逐语句执行 [number] 步
2. next/n: 同上，但是不会进入到函数内部
    + next [number]: 逐语句执行 [number] 步
3. continue/c: 继续运行直到断点处
    + continue [number]: 继续执行，忽略 [number] 次的命中
4. where: 显示当前执行的具体函数和代码行

## 断点
1. breakpoints: 断点
    + break/b : 在下一指令出设置断点
    + break [file_name]:[line_number]/[line_number]: 在指定文件的行/行处设置断点
    + break [function_name] / [class_name]:[function_name] / [file_name]:[function_name]: 在函数、指定类的成员函数、指定文件的函数处设置断点
    + break *[address]: 在指定地址设置断点
    + break +/- [offset]: 在当前代码行 加上/减去 偏移量的位置设置断点
    + break [line_number] if [condition]: 设置条件变量
    + tbreak: 设置临时变量
2. watchpoints: 观察断点
    + watch [variable]: 监控变量 [variable] 当变量的值发生变化时命中该断点
    + watch [varibale_1] + [variable_2]: 监控两个变量值
    + watch *(type*)[address]: 通过内存地址间接设置断点
    + watch [variable] thread [thread_number]: 监控线程[number]修改变量时触发中断
    + info watchpoints: 查看数据断点类型列表
3. catchpoints: 捕获断点
    + catch throw: 捕获 C++ 抛出异常事件
    + catch catch: 捕获 C++ 捕获到异常事件
    + catch exec: 捕获 exec 函数被调用（进程替换函数）
    + catch fork: 捕获 fork 函数被调用
    + catch vfork: 捕获 vfork 函数被调用（创建子进程，并且子进程先执行，退出或者被替换后再执行父进程）
    + catch load/unload [libname]: 捕获加载/卸载 [libname] 动态库事件，[libname] 可选
4. 显示/删除断点
    + info break/b: 显示所有类型断点
    + info watchpoints/catchpoints: 显示数据断点类型/捕获断点类型列表
    + clear [line]/[file]:[line]/[function]: 清除指定位置的所有断点，如果有多个同名函数的断点，则也会被全部删除
    + delete/d [Num]: 删除编号为 Num 的断点, [Num]可选，如果没有该参数，则是删除所有断点
    + delete/d [num1]-[num2] [num3]-[num4]: 删除编号区域内的断点
    + enable/disable [Num]: 启用/禁用编号为 Num 的断点
    + save break/b [file_name]: 保存断点信息到 [file_name] 文件中
    + source [file_name]: 导入文件 [file_name] 中的断点信息
    + delete 删除断点是全局的，clear删除当前函数内部的断点，不加参数则表示删除的是将要执行的下一处断点，clear不能删除观察点和捕获点

## 程序栈
1. backtrace:打印栈帧
    + backtrace/bt [number]: 打印 [number] 个栈帧，参数可选
    + bt full [n]: 从内到外显示 n 个栈帧及其局部变量，参数 n 可选
    + bt full -[n]: 从外到内显示 n 个栈帧及其局部变量
2. frame: 切换栈帧
    + frame/f [number]: 切换到第 [number] 个栈帧，如果不存在，则打印当前栈帧
    + up [number]: 选择当前栈帧编号 + [number]的栈帧
    + down [number]: 选择当前栈帧编号 - [number]的栈帧
    + info frame [addr]: 描述当前选择的栈帧, [addr]可选
3. info
    + info args: 显示当前栈帧的参数列表
    + info locals: 显示当前栈帧的局部变量
4. finish: 执行完当前函数，并打印返回值，然后触发断点
6. return 0: 不再执行当前函数后面的指令，直接返回。可以指定返回值
7. call/print [function_name]: 调用函数
8. set var [variable]=[value]: 给变量[variable]赋值

## 多进程
+ attach [pid]: 绑定进程 pid
+ info inferiors: 显示进程列表
+ inferior [num]: 切换到编号为 num 的进程上调试
+ set follow-fork-mode child/parent: 追踪子进程/父进程
+ set detach-on-fork on/off: fork 调用时只追踪其中一个进程/同时追踪父子进程
+ set schedule-multiple on: 默认调试当前进程时，其他进程处于挂起状态。该命令设置调试时所有进程都在执行

## 多线程
+ info threads: 查看线程列表
+ thread [num]: 切换到线程编号为 num 的线程进行调试
+ set scheduler-locking on/off: 调试一个线程时，其他线程暂停执行/同步执行
+ set scheduler-locking step: 仅用step调试线程时其他线程不执行，用其他命令如 next 调试时执行

## 显示打印
1. print
    + print *[array]@[number]: 打印数组 [array] 从开头连续的 [number] 个元素的值
    + print [array][index]@[number]: 打印数组 [array] 以 [index] 为起点的 [number] 个元素
         + print array[10]@10: 答应数组 arrray 的第 10~19个元素
    + print [variable]=[value]: 修改查看到的变量的值，结构体或者类对象的成员值也可以用这种发那是修改
    + set print array-indexes on: 打印数组的同时打印数组的下标
    + print *(struct [struct_name]*)[ptr]: 查看指针 [ptr] 指向的结构体的内容
    + print [ptr]: 查看该指针指向的类型及指针地址
    + print/p [struct_name]: 直接显示结构体
    + set print pretty on: 每行只显示结构的一名成员
    + set print null-stop: 不显示 "\000"
2. display
    + info display: 查看显示列表
    + display [variable]/*[ptr]/[struct_name]: 每次触发命中都会打印对应的内容
3. x/s: 打印 ASCII 字符串
    + x [ptr]: 显示16进制内容
    + x/s [ptr]: 显示十进制内容，
    + x/[number]d [prt]: 以宽度为 number 显示内容 
    + x 可以用来查看结构体如何存储的
        + x/16s [ptr]
4. ptype
    + ptype [optional arguments] [variable]/[type]
        + 可选参数中:
            - /r: 以原始数据的方式显示
            - /M,/m: 显示类的方法
            - /t: 不打印类中的 typedef 数据
            - /o: 打印结构体字段的偏移量和大小
5. whatis: 打印变量的类型
    + whatis [/flags] [arg]

## 寄存器
    + info/i registers/r: 查看寄存器
    + info all-registers: 显示所有寄存器
    + info r [register_name]: 查看指定的寄存器
        + i r rdi/rsi

## 调试和保存core文件
1. file [file_exec]: 加载可执行文件符号表信息
2. core [core_file]: 加载 core-dump 文件
3. gcore [core_file]: 生成 core-dumo 文件，记录当前进程的状态

## 汇编
1. disassemble [function_name]: 查看函数的汇编代码
2. disassemble /mr [function_name]: 同时比较函数源代码和汇编代码 

## 图形化界面

## GDB
1. gdb -q [program]: 参数 q 可以去掉其他不必要的输出。
2. 调试带 core 文件方法
    + 方法1: gdb [program_name] [program_core_file]
    + 方法2: 
        1. gdb [program_name] 进入到 GDB 调试页面
        2. core [program_core_file]
3. 在 GDB 命令行可以运行 shell 命令
    + ![shell_cmd]
4. GDB 命令行中可以使用一些内嵌的函数，比如C语言的函数
    + strcmp
    + sizeof
    + fopen
        - set $f1 = fopen("test.txt","w+")
        - set $str = "this is a test string\n"4str
        - set $write_size = fwrite($str,1,strlen($str),$f1)
        - set $res = fclose($f1)
5. GDB 中支持搜索源码，且支持正则表达式搜索
    + reverse-search [regular_expression]
