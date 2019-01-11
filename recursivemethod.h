#ifndef RECURSIVEMETHOD_H
#define RECURSIVEMETHOD_H

#include "messageoutput.h"

#define Status int
#define OK 0
#define ERROR -1
#define OUT -1
#define SKIP -2


class Recursive
{
public:
    Recursive();

    Status Input(int num);
    Status Simulator(OutputOrganizer & organizer);

    int num;//战士的数量
};

#endif // RECURSIVEMETHOD_H
