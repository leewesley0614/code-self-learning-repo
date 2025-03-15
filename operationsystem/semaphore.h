count = 0 //记录缓冲区数据项个数
// 生产者，写入数据项到缓冲区
item = produce_item();
if(count == N) sleep();
insert_item(item);
count = count + 1;
if(count == 1) wakeup(consumer); // 表示如果缓冲区存在数据项，系统调用唤醒消费者
// 消费者，从缓冲区读取数据项
if(count == 0) sleep();
item = remove_item();
count = count - 1;
if(count == N-1) wakeup(producer); //表示缓冲区可用，系统调用唤醒生产者
consume_item(item);

// 当cpu轮转速度太快，会导致两个进程进入永久睡眠状态
// 使用信号量semaphore解决
full = 0 //semaphore 1,信号量1，代表缓冲区满的个数
empty = 7 //semaphore 2,信号量2，代表缓冲区的个数
mutex = 1 // semaphore 3,信号量3，代表读写互斥操作

// producer
item = produce_item(); // 生产一个数据项
down(&empty); // empty - 1,当empty = 0时，down操作进入睡眠状态
down(&mutex); // mutex - 1，0表示允许访问
insert_item();
up(&mutex); // mutex + 1, 1表示结束访问
up(&full); // full + 1

// consumer
down(&full);
down(&mutex);
item = remove_item();
up(&mutex);
up(&empty);
consume_item(item);