#include "FastCamel.h"

FastCamel::FastCamel()
{
    _name = "�������-���������";
    _velocityKmh = 40;
    _motionTimeBeforeRestHr = 10;
}

double FastCamel::getRestTimeHr(const int distanceKm) const
{
    const auto restNumber = getRestNumber(distanceKm);
    double result = 0;
    if (restNumber >= 1)
    {
        // ������ ����� 5 �.
        result += 5;
    }

    if (restNumber >= 2)
    {
        // ������ - 6.5 �, ���������  - 8 �.
        result += 6.5 + (restNumber - 2) * 8;
    }

    return result;
}