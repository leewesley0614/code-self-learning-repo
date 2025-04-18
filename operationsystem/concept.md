**第1章：导论**

## 1.1 操作系统的功能
- 操作系统控制硬件，并协调各个用户应用程序的硬件使用
- 当计算机系统运行时，操作系统提供正确手段以便使用这些资源
  
从系统视角看，操作系统可以看作资源分配器（resource allocator）。另外，操作系统可以视作一个控制程序，管理用户程序的执行，以防止计算资源的错误或不当使用。

定义：OS是一直运行在计算机上的程序——称为内核（kernel）。除了内核外，还有其他两类程序：系统程序和应用程序。前者是与系统有关的程序，但不是内核的一部分；后者是与系统运行无关的所有其他程序

## 1.2 计算机系统的组成
![picture1](./image/p1.png)
### 1.2.1 计算机系统的运行
按下电源，cpu运行初始程序（引导程序）。该程序位于计算机固件（firmware）或只读内存中。它初始化系统的各个组件，并且知道如何加载操作系统并且开始执行系统。为了完成这一目标，引导程序必须能够定位操作系统内核并加载到内存中。
![picture2](./image/p2.png)

事件发生通常通过硬件或软件的中断来通知。硬件中断通过总线发送信号到CPU触发中断。软件通过系统调用（system call）触发中断。

中断机制：触发中断后，中断将控制转移给合适的中断处理程序。处理这一转移的直接方法是：调用一个通用程序来检查中段信息。接着该程序会调用特定的中断处理程序。不过，中断处理应当快捷。由于只有少量预先定义的中断，所以可以通过中断处理程序的指针表来提高速度。这样通过指针表可以间接调用中断处理程序，而无需通过其他中介程序。
### 1.2.2 存储结构
所有形式的内存都提供字节数组，每个子节都有地址。交互通过针对特定内存地址，执行一系列load或store指令实现：
指令load将内存字节保存到CPU寄存器；
指令store将寄存器内容保存到内存中。

![picture3](./image/p3.png)
- 理想情况下，内存中的数据应该是永久的。然而不可能做到，原因有两点：1.内存的空间通常太小；2.内存是是易失性的，断电之后数据便会丢失
- 完整的存储系统应当只使用必须的昂贵存储，而提高尽可能便宜的、非易失的存储。当两个存储组件的访问时间或传输速率具有明显差异时，可以通过高速缓存来改善性能

### 1.2.3 I/O结构
- 在通用计算机中，CPU与多个I/O设备控制器通过总线连接在一起
- 每个设备控制器管理某一特定类型的设备。
- 根据设备控制器的特性，可以允许多个设备与其相连
- 每个设备控制器维护一定量的本地缓存和一组特定用途的寄存器
- 设备控制器负责在所控制的外围设备与本地缓存之间进行数据传递
- 操作系统为每个设备控制器提供一个设备驱动程序device driver,该设备驱动程序负责设备控制器，并且为操作系统的其他部分提供统一的设备访问接口
![picture4](./image/p4.png)
