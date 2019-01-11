//
// Created by 金韬 on 2018/12/26.
//
#ifndef DEATHSQUADPROBLEM_METHODLIST_H
#define DEATHSQUADPROBLEM_METHODLIST_H

#include <QString>
#include <ctime>  //计算运行时间
//-----------------------------
#include "CircularLinkList.h"
#include "QueueSolution.h"
#include "recursivemethod.h"
#include "messageoutput.h"
#include "arraymethod.h"
//-----------------------------


//循环链表
Status CircularLinkListMethod(int num,OutputOrganizer & organizer);


//循环队列
Status QueueMethod(int num,OutputOrganizer & organizer);


//顺序表：数组
Status ArrayMethod(int num,OutputOrganizer & organizer);

//递归
Status RecursiveMethod(int num,OutputOrganizer & organizer);


//下面是一些主函数用到的基础函数
int InputNumber();

#endif //DEATHSQUADPROBLEM_METHODLIST_H
