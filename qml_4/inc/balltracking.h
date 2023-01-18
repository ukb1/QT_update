#ifndef BALLTRACKING_H
#define BALLTRACKING_H
#include "project_type.h"



class BallTracking: public QObject
{
    Q_OBJECT
public:
    BallTracking();
    Q_INVOKABLE void setBall(int x, int y);
    Q_INVOKABLE void getBall() const;

private:
    int x;
    int y;
};

#endif // BALLTRACKING_H
