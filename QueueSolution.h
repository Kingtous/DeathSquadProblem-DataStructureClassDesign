//
// Created by 金韬 on 2018/12/26.
//

#ifndef DEATHSQUADPROBLEM_QUEUESOLUTION_H
#define DEATHSQUADPROBLEM_QUEUESOLUTION_H


#include "queue.h"
#include <iostream>
#include <QString>
#include <messageoutput.h>
using namespace std;

#define Status int
#define OK 0
#define ERROR -1
#define OUT -1
#define SKIP -2


class QueueSolution{
public:
    QueueSolution();
    Status Input(int num);
    Status Simulator(OutputOrganizer & organizer);
    Status Simulate(MyQue<int> q1,MyQue<int> q2,int length,OutputOrganizer & organizer);
    Status Output();
    MyQue<int> *q;
    int length;
};
#endif //DEATHSQUADPROBLEM_QUEUESOLUTION_H
