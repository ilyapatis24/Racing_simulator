#pragma once
#include "RaceResult.h"

class RaceResultReport
{
	friend class Race;
public:
	~RaceResultReport();
	RaceResult* const* const getItems() const;
	int getCount() const;
	RaceResult* const operator[](const int i) const;
protected:
	RaceResultReport(RaceResult** items, int count);
private:
	RaceResult** _items;
	int _count;
	// упорядочивает элементы
	void orderItems();
	// Функция сравнения элементов отчета, используемая для упорядочивания
	int compareItems(RaceResult* item1, RaceResult* item2) const;
};
