//
// Created by 金韬 on 2018/12/26.
//

#include "QueueSolution.h"


QueueSolution::QueueSolution()
{
    this->length=0;
}

Status QueueSolution::Input(int num)
{
    this->q = new MyQue<int>(num);
    this->length=num;
    int cnt=1;
    //this->q.push(cnt);
    //cnt++;
    while (num--)
    {
        q->push(cnt);
        ++cnt;
    }
    return OK;
}

Status QueueSolution::Simulate(MyQue<int> q1,MyQue<int> q2,int length,OutputOrganizer & organizer)
{
    //从q2开始数数
    int cnt=0;
    organizer.AddFileOutput("从战士 "+QString::number(q2.front()).toStdString()+" 开始报数：");
    LOOPLABEL:
    while (!q2.IsEmpty())
    {
        int tmp=q2.front();
        q2.pop();
        if(++cnt==5)
        {
            cnt=0;
            if(tmp==1)
            {
                organizer.resetFileOutput();
                return SKIP;
            }
            //出队
            else {
                organizer.AddFileOutput("编号为 "+QString::number(tmp).toStdString()+" 的士兵出队列");
                length--;
            }
        }
        else
        {
            q1.push(tmp);
        }
    }
    while (!q1.IsEmpty())
    {
        int tmp=q1.front();
        q1.pop();
        if(++cnt==5)
        {
            cnt=0;
            if(tmp==1)
            {
                organizer.resetFileOutput();
                return SKIP;
            }
            else
            {
                organizer.AddFileOutput("编号为 "+QString::number(tmp).toStdString()+" 的士兵出队列");
                length--;
            }
        }
        else
        {
            q2.push(tmp);
        }
    }
    if(length==1)
        return OK;
    else goto LOOPLABEL;
}


Status QueueSolution::Simulator(OutputOrganizer & organizer)
{
    MyQue<int> q2=this->q->Copy();

    vector<int> v;
    v.clear();

    MyQue<int> q1(this->length);

    while (true)
    {
        if(q2.IsEmpty())
            break;
        if(Simulate(q1.Copy(),q2.Copy(),this->length,organizer)==OK)
        {
            v.push_back(q2.front());
            //organizer.AddWidgetOutput("\n");
            organizer.isSuccess=true;
            break;
        }
        int tmp=q2.front();
        q1.push(tmp);
        q2.pop();
    }
    if(v.empty() || this->length==1)
    {
        organizer.AddWidgetOutput("没有可用的解决方案",true);
        //cout<<"没有可用的解决方案"<<endl;
    }
    else
    {
        vector<int>::iterator i =v.begin();
        organizer.AddWidgetOutput("可让编号为 ");
        //cout<<"可让编号为 ";
        while (i!=v.end())
        {
            organizer.AddWidgetOutput(QString::number(*i)+" ");
            //cout<<*i<<" ";
            ++i;
        }
        organizer.AddWidgetOutput("的战士先报数，使得排长留下",true);
        //cout<<"的战士先报数，使得排长留下"<<endl;
    }
    return OK;
}

Status QueueSolution::Output()
{
    MyQue<int> QCopy=this->q->Copy();
    while (!QCopy.IsEmpty())
    {
        int tmp=QCopy.front();
        QCopy.pop();
        cout<<tmp<<" ";
    }
    cout<<endl;
    return OK;
}
