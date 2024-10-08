#pragma once
namespace bit
{
	template<class T>
	class auto_ptr
	{
	public:
		// RAII
		// 像指针一样
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~auto_ptr()
		{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// ap3(ap1)
		// 管理权转移
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

	private:
		T* _ptr;
	};

	template<class T>
	class unique_ptr
	{
	public:
		// RAII
		// 像指针一样
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// ap3(ap1)
		// 管理权转移
		// 防拷贝
		unique_ptr(unique_ptr<T>& ap) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete;
	private:
		T* _ptr;
	};

	template<class T>
	class shared_ptr
	{
	public:
		// RAII
		// 像指针一样
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new int(1))
		{}

		~shared_ptr()
		{
			if (--(*_pcount) == 0)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				delete _pcount;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// sp3(sp1)
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
		{
			++(*_pcount);
		}

		// sp1 = sp5
		// sp6 = sp6
		// sp4 = sp5
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr == sp._ptr)
				return *this;

			if (--(*_pcount) == 0)
			{
				delete _ptr;
				delete _pcount;
			}

			_ptr = sp._ptr;
			_pcount = sp._pcount;
			++(*_pcount);

			return *this;
		}

		int use_count() const
		{
			return *_pcount;
		}

		T* get() const
		{
			return _ptr;
		}

	private:
		T* _ptr;
		int* _pcount;
	};


	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{}

		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			_ptr = sp.get();
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};
}