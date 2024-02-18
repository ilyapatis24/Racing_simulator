#include "AllTerrainBoots.h"

AllTerrainBoots::AllTerrainBoots()
{
    _name = "�������-���������";
    _velocityKmh = 6;
    _motionTimeBeforeRestHr = 60;
}

double AllTerrainBoots::getRestTimeHr(const int distanceKm) const
{
    const auto restNumber = getRestNumber(distanceKm);
    double result = 0;
    if (restNumber > 0)
    {
        // ������ ����� 10, ��������� 5 �����
        result += 10 + (restNumber - 1) * 5;
    }

    return result;
}