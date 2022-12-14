# C tutorial

## 从helloworld程序认识计算机

### helloworld.c

```c
#include <stdio.h>

int main(void)
{
  printf("hello world!\n");
  return 0;
}
```

helloworld.c ---> 源文件；

a.out ---> 可执行程序；

```
源程序 ---> 可执行程序 ---> 计算机执行 
```

程序就是一组计算机能识别和执行的指令的有序集合，是将人的逻辑和旨意传给计算机去执行，仅仅是磁盘的一个文件。

编译过程：

```
源程序 ---> 编译 ---> 目标文件 ---> 链接 ---> 可执行文件 
```

```
hello.c ---- 预处理器 ----> hello.i;
hello.i ---- 编译器 ----> hello.s;
hello.s ---- 汇编 ----> hello.o;
hello.o ---- 链接 ----> hello;
```

C程序执行环境：

```
CPU --- 加载器（exec函数）---> 加载程序到内存 ---> 程序在内存中运行 ---> 进程 ---> 链接
未执行的程序叫程序，执行的程序叫进程；
```

ELF文件头：

程序头

数据段

代码段

==内存为什么要分段？==

```
1. 指令与数据可以区分开来；
2. 可以对不同的段施加不同的属性：代码段是r/o;数据段是r/w.可以防止代码段中的指令被有意或无意的破坏，提高了程序的局部性，有利于缓存；
3. 多个代码可以共享，共享存储器中的数据或代码，可以减少内存使用。
```

链接：

```
链接脚本可以决定程序的入口地址，链接的过程是将.o文件与库文件合并，对符号重定位
LMA 加载内存地址
VMA 虚拟存储地址
对于PC程序来说，LMA = VMA
对于嵌入式程序来说，LMA不一定等于VMA
```



贯穿整个系统的一组电子管道称为总线：

片内总线：CPU;

系统总线：

数据总线DB：传输数据

地址总线AB：传输地址

控制总线CB：传输信号、时序指令

```
CPU <--- AB + CB ---> 内存；
```

外部总线：与外部设备沟通的桥梁。



内存：是一个重要部件，它是与CPU沟通的桥梁，它是用来存放程序以及程序要处理的数据，磁盘中的程序要加载到内存中才能运行。



中央处理器（CPU），主要由运算器、控制器、寄存器组成。

取址

译码

执行

转回

跳转



## 数据表示

十进制、二进制、八进制、十六进制

```c
123 = 1x10^2 + 2x10^1 + 3x10^0 = 100 + 20 + 3;
1010(二进制) = 1x2^3 + 0x2^2 + 1x2^1 + 0x2^0 = 8+2 = 10;
2f(十六进制) = 2x16^1 + fx16^0 = 32+15 = 47;
```

原码、补码、反码：

计算机中都是以补码存储的。

正数的原码、补码和反码均相同；

负数的原码、补码和反码如下：

```c
10 = 00001010 = 00001010 = 00001010; (正数)
-10 = 10001010 = 11110101 =11110110；（负数）
```



```markdown
1. 通常，一个字节占8位，从左向右依次 7～0；7是高位，0是低位；
```











## 数组

定义：数组是若干相同类型的变量在有序内存空间的集合。

1. 数组存储一组数据；
2. 数组每个元素类型相同；
3. 数组在内存中开辟一段连续的空间。

### 一维数组

**语法：**

```c
typeName arrName[size]; 
typeName: 数组元素的类型;
arrName:数组的名称;
size:数组的大小，元素的个数;

int arr[3] = {1, 2, 3};
int arr[] = {1,2,3};
数组的个数可以不写，但是不写必须初始化。
```

**示例：**

```c
#include <stdio.h>

int main()
{
    int arr[10];
    printf("sizeof(arr) = %ld %ld\n", sizeof(arr), 10 * sizeof(int));
    int b[] = { 1,2,3 };
    printf("sizeof(b) = %ld\n", sizeof(b));
    return 0;
}
```

**结果：**

```c
C-C-Tutorial/C [ ./a.out angus.li * ] 12:05 上午
sizeof(arr) = 40 40
sizeof(b) = 12
```

### 二维数组

**语法：**

```c
数组类型 数组名[行数][列数]
```

### 指针

指针：就是地址的代名词；
指针变量：就是存储地址或者指针的变量。

C编译器针对指针需要解决两个疑问：
1. 分配一个内存空间，空间需要多大？---> 在32位系统中，指针就4个字；64位系统中，8个字节。
2. 空间里存放的地址所指向的内存读取方法是什么？

指针指向内存空间一定要保证合法性。

**指针和修饰符：**

const：常量、只读；

```c
const char* p || char* const p; ---> 指针所指向的内容是不可变的;
char * const p || char* p const; ---> 指针变量本身不可变，所指向的内容可以变;
const char* const p; 指针变量本身以及所指向的内容皆不可变。
```









