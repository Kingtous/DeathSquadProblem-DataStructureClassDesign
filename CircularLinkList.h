//
// Created by 金韬 on 2018/12/26.
//

#include <sys/malloc.h>
#include <iostream>
#include <QString>
#include <messageoutput.h>

using namespace std;
#ifndef DEATHSQUADPROBLEM_CIRCULARLINKLIST_H
#define DEATHSQUADPROBLEM_CIRCULARLINKLIST_H
#define Status int
#define OK 0
#define ERROR -1
#define OUT -1
#define SKIP -2

enum Position{
    chief,//排长
    sodier//战士
};

typedef class CNode{
public:
    CNode(Position pos,int id);
    Position position;
    int id;
    CNode * next;
}CNode;

typedef class CPoint{
public:
    CPoint();
    Status Insert(int Kind);
    Status Traverse();
    Status Simulator(OutputOrganizer & organizer);
    Status Input(int num);
    Status InitLabel();
    CNode * head;
    CNode * tail;
    int length;
}CLink;
#endif //DEATHSQUADPROBLEM_CIRCULARLINKLIST_H
