//
// Created by 金韬 on 2018/12/29.
//

#ifndef CLASS3_MYQUEUE_H
#define CLASS3_MYQUEUE_H

#endif //CLASS3_MYQUEUE_H

template<class T>
class MyQue{
public:
    MyQue(int size) ;
    bool pop(T &num);
    bool pop();
    bool push(T num);//写入
    void Clear();
    bool IsFull();
    bool IsEmpty();
    int Size();
    T front();
    MyQue<T> Copy();

    int len;
    int SIZE;
    int w_ptr;
    int r_ptr;
    T* Que;
};

template<class T>
MyQue<T>::MyQue(int size)
{
    len = 0;
    w_ptr = 0;
    r_ptr = 0;
    SIZE = size;
    Que = new T[SIZE];
}

template<class T>
bool MyQue<T>::IsEmpty()
{
    if(len == 0)
        return true;
    else
        return false;
}

template<class T>
bool MyQue<T>::IsFull()
{
    if(len == SIZE)
        return true;
    else
        return false;
}

template<class T>
int MyQue<T>::Size()	 //获取队列长度
{
    return len;
}
//int 的字符长度有限制，如果重复使用一直增加的话可能会导致数组指针错误	超出int 最大值变为负数
template<class T>
bool MyQue<T>::push(T num)
{
    if(len == SIZE) //满了
        return false;

    w_ptr = w_ptr%SIZE;	//这样就不超出int范围，大小一直保持在 0-SIZE 之间

    Que[w_ptr] = num; //循环使用数组

    len +=1;		//长度加1
    w_ptr += 1;		//下标+1
    return true;
}

template<class T>
bool MyQue<T>::pop(T & num)
{
    if(len == 0)
        return false;
    r_ptr = r_ptr%SIZE;
    num = Que[r_ptr];
    r_ptr += 1;
    len --;
    return true;
}

template<class T>
bool MyQue<T>::pop()
{
    if(len == 0)
        return false;
    r_ptr += 1;
    len --;
    return true;
}



template<class T>
void MyQue<T>::Clear()	//清空指针 使其复用即可
{
    len = 0;
    r_ptr = 0;
    w_ptr = 0;
    return;
}

template<class T>
T MyQue<T>::front()
{
    if(len == 0)
        return false;
    int pos=r_ptr%SIZE;
    return Que[pos];
}

template<class T>
MyQue<T> MyQue<T>::Copy()
{
    MyQue<T> Q(this->SIZE);
    Q.len=this->len;
    Q.SIZE=this->SIZE;
    Q.w_ptr=this->w_ptr;
    Q.r_ptr=this->r_ptr;
    for (int i=0;i<this->SIZE;++i) {
        Q.Que[i]=this->Que[i];
    }
    return Q;
}


