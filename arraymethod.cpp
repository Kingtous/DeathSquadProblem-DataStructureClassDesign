#include "arraymethod.h"


ArraySolution::ArraySolution()
{

}


Status ArraySolution::Input(int num)
{
    this->num=num;
}


Status initIDArray(bool * id,int length)
{
    for (int point=1;point<=length;++point) {
        id[point]=false;
    }
    return OK;
}


Status Simulate(bool * id,int length,int AnnouncePoint,OutputOrganizer & organizer)
{
    //id第0个被舍弃
    int AnnounceNow=1;
    int PeopleInCircle=length;

        while(true) {
        if(AnnouncePoint>length)
        {
            //循环
            AnnouncePoint=1;
        }
        if(id[AnnouncePoint]==true)
        {
            //标明已经出队，跳过
            ++AnnouncePoint;
            continue;
        }
        if(PeopleInCircle==1)
        {
            //只剩下排长，成功
            return OK;
        }
        if(AnnounceNow==5)
        {
            //喊到了5,出列

            //如果是排长就失败
            if(AnnouncePoint==1)
            {
                organizer.resetFileOutput();
                return SKIP;
            }
            //出列
            else {
                organizer.AddFileOutput("编号为 "+QString::number(AnnouncePoint).toStdString()+" 的战士出列了。");
                id[AnnouncePoint]=true;
                PeopleInCircle--;
            }
            AnnounceNow=1;
        }
        else {
            ++AnnounceNow;
        }
        ++AnnouncePoint;
    }
}


Status ArraySolution::Simulator(OutputOrganizer & organizer)
{
    //建立一个数组存储id,从1开始，舍弃0号元素
    bool * id = (bool*)malloc(sizeof (bool) * (num+1));
    if(id==NULL)
        return ERROR;
    //
    if(this->num<=1){
        organizer.AddWidgetOutput("没有可行的解决方案",true);
        return SKIP;
    }
    for(int announce=1;announce<=this->num;++announce)
    {
        initIDArray(id,this->num);//初始化数组
        //从announce处开始报数
        if(Simulate(id,this->num,announce,organizer)==OK)
        {
            //如果成功，则停止
            organizer.AddWidgetOutput("可以从编号为 "+QString::number(announce)+" 的战士开始报数，"
                                                                          "使得排长留下。",true);
            organizer.isSuccess=true;
            return OK;
        }
    }
    organizer.AddWidgetOutput("没有可行的解决方案",true);
    return SKIP;
}
