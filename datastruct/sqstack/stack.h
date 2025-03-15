template<class T>
class stack
{
public:
    virtual ~stack(){} //析构函数
    virtual bool empty() const=0;
        //返回true，当且仅当栈为空
    virtual int size() const=0;
        //返回栈中元素个数
    virtual T& top() = 0;
        //返回栈顶元素的引用
    virtual void pop() = 0;
        //删除栈顶元素
    virtual void push(const T& ele) = 0;
        //压入元素至栈顶
};

