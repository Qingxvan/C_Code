#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

int Date::GetMonthDay(int year, int month)
{
	assert(month < 13 && month > 0);
	int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	else
	{
		return monthArray[month];
	}
}

Date::Date(int year, int month, int day)
{
	if (month < 13 && month > 0 && (day > 0 && day <= GetMonthDay(year, month)))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "���ڲ��Ϸ�" << endl;
	}
}

void Date::Print()
{
	cout << _year << "��" << _month << "��" << _day << "��" << endl;
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}


bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
bool Date::operator>(const Date& d)
{
	return _year > d._year || (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day);
}
bool Date::operator >= (const Date& d)
{
	return *this > d || *this == d;
}
bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}
bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}
bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

// ����+=����
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= -day;
		return *this;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}

// ����+����
Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}

// ����-=����
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		*this += -day;
		return *this;
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

// ����-����
Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

// ����-���� ��������
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int falg = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		falg = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n * falg;
}

// ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// ����++
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

// ǰ��--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// ����--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}