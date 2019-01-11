#include "recursivemethod.h"

Recursive::Recursive()
{

}

Status Recursive::Input(int num)
{
    //传入的为战士的数量
    this->num=num;
    return OK;
}


int recurse(int m,int k,int i){
    //m个人，数到k退出，第i次
    if(i==1)
    {
        return (m+k-1)%m;
    }
    else
    {
        return (recurse(m-1,k,i-1)+k)%m;
    }
}

Status Recursive::Simulator(OutputOrganizer & organizer)
{
    //organizer.AddWidgetOutput("递归：",true);
    int times=0;
    while(++times)
    {
        if(times<=this->num)
        {
            int result=recurse(this->num,5,times)+1;
            if(times==num)
            {
                int outputnum=(this->num-result+2);
                if(outputnum>this->num)
                    outputnum=outputnum%this->num;
//                if(outputnum==0)
//                {
//                    //无解决方案
//                    organizer.AddWidgetOutput("无可行的解决方案",true);
//                    //organizer.resetFileOutput();
//                    //organizer.isSuccess=true;
//                    return SKIP;
//                }
                //把排长安排到最后一个出队位置上去,注意这个result是以0开始的
                   organizer.AddWidgetOutput("可用从编号为 "+QString::number(outputnum)+
                                             " 的战士开始报数，从而使得排长留在队伍中。",true);
                   organizer.isSuccess=true;
                   organizer.AddFileOutput("编号为"+QString::number(result).toStdString()+ "出列");
                   organizer.AddFileOutput("计算方法："+QString::number(this->num).toStdString()+"-"+
                                           QString::number(result).toStdString()+"+2="+
                                           QString::number(num-result+2).toStdString()
                                           );
            }
            else {
                organizer.AddFileOutput("编号为"+QString::number(result).toStdString()+ "出列");
            }
        }
        else {
            break;
        }
    }
    return OK;
}
