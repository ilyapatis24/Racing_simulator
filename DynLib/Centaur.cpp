#include "Centaur.h"

Centaur::Centaur()
{
    _name = "�������";
    _velocityKmh = 15;
    _motionTimeBeforeRestHr = 8;
}

double Centaur::getRestTimeHr(const int distanceKm) const
{
    // �������� 2 �.
    return 2 * getRestNumber(distanceKm);
}