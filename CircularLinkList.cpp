//
// Created by 金韬 on 2018/12/26.
//
#include "CircularLinkList.h"
#include <vector>
CNode::CNode(Position pos,int id)
{
    this->position=pos;
    this->id=id;
    this->next=NULL;
}


CPoint::CPoint()
{
    Position pos=sodier;
    //初始节点，赋值0，不调用length
    this->head=new CNode(pos,0);
    //
    this->tail=this->head;
    //
    this->length=0;
}



Status CPoint::Input(int num)
{
    //插入排长
    this->Insert(0);
    while (--num)
    {
        this->Insert(1);
    }
    return OK;
}

Status CPoint::Insert(int Kind)
{
    Position pos;
    switch(Kind) {
        case 0://排长
            pos = chief;
            break;
        default:
            pos = sodier;
    }
    this->tail->next=new CNode(pos,++this->length);
    this->tail->next->next=this->head;
    this->tail=this->tail->next;
    return OK;
}

Status CPoint::Traverse()
{
    CNode* point=this->head->next;
    if(point==NULL)
    {
        return OK;
    }
    cout<<"编号 职位"<<endl;
    while (point->id!=0)
    {
        cout<<point->id<<" ";
        if(point->position==0)cout<<"排长"<<endl;
        else cout<<"战士"<<endl;
        point=point->next;
    }
    return OK;
}


Status Simulate(CNode * node,int length,OutputOrganizer & organizer)//链表长度
{
    int cnt=0;
    if(node==NULL)
        return ERROR;
    else
    {
        while (true)
        {
            if(length==1)
                return OK;
            if(node->id==OUT || node->id==0)
            {
                //已经出战了,或者是链表头
                node=node->next;
                continue;
            }
            cnt++;
            if(cnt==5){
                cnt=0;
                if(node->position==chief)
                {
                    //output+="排长出战了!此次失败\n";
                    //cout<<"大快人心！排长出战了!"<<endl;
                    organizer.resetFileOutput();//清空输出
                    return SKIP;
                } else
                {
                    organizer.AddFileOutput("编号为"+QString::number(node->id).toStdString()+"的战士出队了");
                    //cout<<"编号为"<<node->id<<"的战士出队了"<<endl;
                    node->id=OUT;
                    node=node->next;
                    length--;
                    continue;
                }
            }
            node=node->next;
        }
    }
}


Status CPoint::InitLabel()
{
    CNode *p=this->head->next;
    if(p==NULL)
        return ERROR;
    int n=1;//编号
    while (p!=this->head)
    {
        p->id=n;
        n++;
        p=p->next;
    }
    return OK;
}

Status CPoint::Simulator(OutputOrganizer & organizer)
{
    //初始化编号
    vector<int> v;
    v.clear();
    CNode * p=this->head->next;
    while (p!=this->head)
    {
        InitLabel();
        organizer.AddFileOutput("从战士 "+QString::number(p->id).toStdString()+" 开始报数：");
        //cout<<endl;
        if(Simulate(p,this->length,organizer)==OK)
        {
            //找到了
            InitLabel();
            v.push_back(p->id);
            organizer.isSuccess=true;
            break;
        }
        //output+="\n";
        p=p->next;
    }
    if(v.empty())
    {
        organizer.AddWidgetOutput("没有可用的解决方案",true);
        //cout<<"没有可用的解决方案"<<endl;
    }
    else
    {
        organizer.AddWidgetOutput("可让编号为 ");
        //cout<<"可让编号为 ";
        vector<int>::iterator i=v.begin();
        while (i!=v.end())
        {
            organizer.AddWidgetOutput(QString::number(*i,10)+" ");
            //cout<<*i<<" ";
            ++i;
        }
        organizer.AddWidgetOutput(" 的战士先报数，使得排长留下",true);
        //cout<<" 的战士先报数，使得排长留下"<<endl;
    }
    return OK;
}

