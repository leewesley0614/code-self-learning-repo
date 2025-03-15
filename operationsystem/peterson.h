// peterson算法，用于解决进程间互斥问题
int other = 1 - process // 另一个进程
intrested[porcess] = true; //警告变量，记录每个进程的警告
turn = process; //锁变量，轮到的进程编号
while(turn == process && intrested[other]==true);//忙等待，导致cpu空转，更好的方法是使用系统调用，将进程挂起
... // 临界区（进程的竞争区域）
intrested[porcess] = false;