//
// Created by 金韬 on 2018/12/26.
//

#include "MethodList.h"

Status CircularLinkListMethod(int num,OutputOrganizer & organizer)
{
    CLink linklist;
    linklist.Input(num);
    organizer.AddWidgetOutput("---------------循环链表------------------",true);
    //cout<<"---------------循环链表------------------"<<endl;
    unsigned long long st=clock();
    linklist.Simulator(organizer);
    unsigned long long ed=clock();
    organizer.AddWidgetOutput("执行时间："+QString::number(ed-st,10)+"\n");
    organizer.storeFileOutput();
    //cout<<endl<<"执行时间："<<ed-st<<endl;
    return OK;
}

Status QueueMethod(int num,OutputOrganizer & organizer)
{
    organizer.AddWidgetOutput("-----------------队列--------------------",true);
    //cout<<"-----------------队列--------------------"<<endl;
    QueueSolution solution;
    solution.Input(num);
    unsigned long long st=clock();
    solution.Simulator(organizer);
    unsigned long long ed=clock();
    organizer.AddWidgetOutput("执行时间："+QString::number(ed-st,10));
    //cout<<endl<<"执行时间："<<ed-st<<endl;
    organizer.storeFileOutput();
    return OK;
}


Status RecursiveMethod(int num,OutputOrganizer & organizer)
{
    Recursive recursive;
    recursive.Input(num);
    organizer.AddWidgetOutput("---------------递归运算------------------",true);
    //cout<<"---------------递归运算------------------"<<endl;
    unsigned long long st=clock();
    recursive.Simulator(organizer);
    unsigned long long ed=clock();
    organizer.AddWidgetOutput("执行时间："+QString::number(ed-st,10)+"\n");
    organizer.storeFileOutput();
    //cout<<endl<<"执行时间："<<ed-st<<endl;
    return OK;
}

Status ArrayMethod(int num,OutputOrganizer & organizer)
{
    ArraySolution arraysolution;
    arraysolution.Input(num);
    organizer.AddWidgetOutput("---------------顺序表------------------",true);
    //cout<<"---------------顺序表------------------"<<endl;
    unsigned long long st=clock();
    arraysolution.Simulator(organizer);
    unsigned long long ed=clock();
    organizer.AddWidgetOutput("执行时间："+QString::number(ed-st,10)+"\n");
    organizer.storeFileOutput();
    //cout<<endl<<"执行时间："<<ed-st<<endl;
    return OK;
    return OK;
}

//控制台输入接口
int InputNumber()
{
    //增加一个InputNumber，防止控制台下输入数据异常
    int n;
    INPUTLOOP:
    cout<<"请输入有多少个敢死队员：";
    cin>>n;
    if(n<=0)
    {
        cout<<"输入错误，请重新输入"<<endl;
        goto INPUTLOOP;
    }
    return n;
}
