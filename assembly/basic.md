```
# 案例
int Y;
int X = (Y + 4) * 3

equal

mov eax, Y;
add eax, 4;
mov ebx, 3;
imul ebx;
mov X,eax;
```
寄存器register是在CPU中被命名的存储位置，用于保存操作的中间结果。

**微机框图**
![micro](./image/micro.png)

register： CPU中保存操作的中间结果的存储单元
ALU：算数逻辑单元，对操作数执行算数运算以及逻辑运算
CU：控制单元，协调参与机器指令执行的步骤序列
CLOCK：时钟，对CUP内部操作与其他系统组件进行同步。

**指令执行周期**
指令执行周期：CPU需要经过一系列预先定义好的步骤才能执行完成一条机器指令。
三个步骤：取址（fetch）、译码（decode）和执行（execute）。
操作数（operand）：操作的输入或输出的值。
