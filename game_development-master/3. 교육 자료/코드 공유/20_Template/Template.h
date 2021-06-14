#pragma once

template <typename T>
class Template
{
public:
	Template(T name);

	template<typename E>
	Template(const Template<E>& src);

	template<typename E>
	Template<T>& operator=(const Template<E>& rhs);

	~Template();

	T& GetName() { return name; }

private:
	T name;

};

template<typename T>
inline Template<T>::Template(T name)
	:name(name)
{
}

template<typename T>
template<typename E>
inline Template<T>::Template(const Template<E>& src)
{
	name = src.name;
}

template<typename T>
template<typename E>
inline Template<T>& Template<T>::operator=(const Template<E>& rhs)
{
	name = rhs.name;
}

template<typename T>
inline Template<T>::~Template()
{

}
