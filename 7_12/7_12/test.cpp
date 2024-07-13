#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

void TestDate1()
{
	Date d1(2023, 7, 23);
	Date d2;

	d1.Print();
	d2.Print();

	Date d3(2010, 2, 29);
	d3.Print();

	Date d4(2023, 13, 29);
	d4.Print();
}

void TestDate2()
{
	Date d1(2023, 8, 6);
	// �������죬һ���Ѿ����ڵĶ���ȥ��ʼ����һ��Ҫ��������
	Date d2(d1);

	d1.Print();
	d2.Print();

	Date d3(2023, 8, 13);
	// ��ֵ�������Ѿ����ڶ�����п���
	//d1 = d3;  // d1.operator=(d3)
	d1 = d2 = d3;
	d1.Print();
	d2.Print();
	d3.Print();

	d1 = d1;

	int i, j;
	i = j = 10;
	cout << (j = 10) << endl;
}

void TestDate3()
{
	Date d1(2023, 7, 27);
	d1 += 20000;
	d1.Print();

	Date d2(2023, 7, 27);
	//Date ret = d2;
	//Date ret(d2 + 20000);
	// ��������
	//Date ret = d2 + 20000;

	Date ret;
	// ��ֵ
	ret = d2 + 20000;

	ret.Print();
}

void TestDate4()
{
	Date d1(2023, 7, 27);
	d1 -= 20000;
	d1.Print();

	Date d2(2023, 7, 27);
	d2 += -200;
	d2.Print();

	Date d3(2023, 7, 27);
	d3 -= -200;
	d3.Print();
}

void TestDate5()
{
	Date d1(2023, 7, 27);
	Date ret1 = d1++;
	//Date ret1 = d1.operator++(0);
	ret1.Print();
	d1.Print();

	Date ret2 = ++d1;
	//Date ret2 = d1.operator++();
	ret2.Print();
	d1.Print();
}

void TestDate6()
{
	Date d1(2023, 7, 27);
	Date d2(2003, 1, 1);

	cout << d1 - d2 << endl;
}

void TestDate7()
{
	const Date d1(2023, 7, 27);
	// d1.Print(&d1);
	d1.Print();

	Date d2(2023, 7, 27);
	// d2.Print(&d2);
	d2.Print();

	cout << (d1 < d2) << endl;
	cout << (d1.operator<(d2)) << endl;
	// cout << (d1.operator<(&d1, d2)) << endl;
}

void TestDate8()
{
	const Date d1(2023, 7, 27);
	d1.Print();

	cout << &d1 << endl;

	Date d2(2023, 7, 27);
	d2.Print();

	cout << &d2 << endl;
}

void TestDate9()
{
	Date d1(2023, 7, 27);
	Date d2(2023, 7, 27);
	//d1.Print();
	cout << d1 << d2;
	//d1 << cout;

	cin >> d1;
	cout << d1;

	int i = 0;
	double d = 1.1;
	cout << i << endl;
	cout << d << endl;
}

int main()
{
	TestDate9();

	return 0;
}

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		cout << "Stack()" << endl;
//
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//			return;
//		}
//
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	// s1(s)
//	Stack(const Stack& s)
//	{
//		cout << "Stack(Stack& s)" << endl;
//		// ���
//		_array = (DataType*)malloc(sizeof(DataType) * s._capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//			return;
//		}
//
//		memcpy(_array, s._array, sizeof(DataType) * s._size);
//		_size = s._size;
//		_capacity = s._capacity;
//	}
//
//	Stack& operator=(const Stack& st)
//	{
//		if (this != &st)
//		{
//			// ...
//		}
//
//		return *this;
//	}
//
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		free(_array);
//		_array = nullptr;
//		_size = _capacity = 0;
//	}
//private:
//	// ��������
//	DataType* _array;
//	int _capacity;
//	int _size;
//};

//class MyQueue
//{
//	// ��������
//	// ��������͸�ֵ��д
//	// ������Ҫд��Ĭ�����ɵľͿ�����
//	Stack _st1;
//	Stack _st2;
//};

//void Func1(const Stack& st)
//{
//
//}
//
//Stack& Func2()
//{
//	Stack st;
//	return st;
//}
//
//int main()
//{
//	Stack st1;
//	Func1(st1);
//
//	Stack st2 = Func2();
//
//	return 0;
//}

//#include<assert.h>

//struct SeqList
//{
//public:
//	void PushBack(int x)
//	{
//		// ... ����
//		_a[_size++] = x;
//	}
//
//	size_t size() const
//	{
//		return _size;
//	}
//	
//	// ��
//	const int& operator[](size_t i) const 
//	{
//		assert(i < _size);
//
//		return _a[i];
//	}
//	
//	// ��/д
//	int& operator[](size_t i)
//	{
//		assert(i < _size);
//
//		return _a[i];
//	}
//
//private:
//	// C++11
//	int*   _a    = (int*)malloc(sizeof(int)*10);
//	size_t _size = 0;
//	size_t _capacity = 0;
//};
//
//
//void Print(const SeqList& sl)
//{
//	for (size_t i = 0; i < sl.size(); i++)
//	{
//		//sl[i]++;
//		cout << sl[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	SeqList s;
//	s.PushBack(1);
//	s.PushBack(2);
//	s.PushBack(3);
//	s.PushBack(4);
//
//	Print(s);
//
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		s[i]++;
//	}
//
//	Print(s);
//
//	return 0;
//}