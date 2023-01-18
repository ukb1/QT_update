#include "balltracking.h"

BallTracking::BallTracking()
{

}

void BallTracking::setBall(int x, int y){
    this->x = x;
    BallTracking::y = y;
}

void BallTracking::getBall() const
{
      qDebug() <<"x: " << x;
      qDebug() <<"y: " << y;
//    int pose[2];
//    pose[0] = x;
//    pose[1] = y;
//    return pose;
}
