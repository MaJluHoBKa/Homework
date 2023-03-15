#include<type_traits>
#include<iostream>

template<typename vt> class smart_ptr
{
private:
	vt* _ptr;

public:
	smart_ptr() noexcept(std::is_nothrow_constructible_v<vt>)
	{
		_ptr = new(std::nothrow) vt;
	}
	smart_ptr(smart_ptr&& other) noexcept
	{
		_ptr = other._ptr;
		other._ptr = nullptr;
	}
	smart_ptr(const smart_ptr& other) = delete;
	smart_ptr& operator=(const smart_ptr& other) = delete;


	smart_ptr& operator=(smart_ptr&& other) noexcept(std::is_nothrow_destructible_v<vt>)
	{
		delete[] this->_ptr;
		this->_ptr = std::move(other._ptr);
		other._ptr = nullptr;
		return *this;
	}


	vt* get() const noexcept
	{
		return _ptr;
	}
	vt* operator->() const noexcept
	{
		return _ptr;
	};
	vt& operator*() const noexcept
	{
		return *_ptr;
	};
	~smart_ptr() noexcept(std::is_nothrow_destructible_v<vt>)
	{
		_ptr->~vt();
		operator delete(_ptr, std::nothrow);
	};
};
