#include "RaceResultReport.h"

RaceResultReport::RaceResultReport(RaceResult** items, int count)
{
    _items = items;
    _count = count;
    orderItems();
}

RaceResultReport::~RaceResultReport()
{
    
    for (int i = 0; i < _count; ++i)
    {
        delete _items[i];
    }

    delete[] _items;
}

RaceResult* const* const RaceResultReport::getItems() const
{
    return _items;
}

int RaceResultReport::getCount() const
{
    return _count;
}

RaceResult* const RaceResultReport::operator[](const int i) const
{
    return _items[i];
}

void RaceResultReport::orderItems()
{
    // взял обратный пузырек из одного из прошлых заданий
    bool swapped;
    do {
        swapped = false;
        for (int i = _count - 1; i > 0; --i) {
            if (compareItems(_items[i], _items[i - 1]) < 0) {
                swapped = true;
                RaceResult* tmp = _items[i];
                _items[i] = _items[i - 1];
                _items[i - 1] = tmp;
            }
        }
    } while (swapped);
}

int RaceResultReport::compareItems(RaceResult* item1, RaceResult* item2) const
{
    auto raceTime1 = item1->getRaceTimeHr();
    auto raceTime2 = item2->getRaceTimeHr();
    return raceTime1 > raceTime2 ? 1
        : (raceTime1 < raceTime2 ? -1 : 0);
}