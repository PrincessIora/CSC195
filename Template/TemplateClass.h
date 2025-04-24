#pragma once

template<typename T = int>
class TemplateClass
{
private:
	T x, y;
public:
	TemplateClass() : x{ 0 }, y{ 0 } {}
	TemplateClass(T x, T y) : x{ x }, y{ y } {}

};

template<typename T, unsigned int size>
class Array
{
private:
	T m_elements[size];

public:
	T& operator[]( int index) { return m_elements[index];}
	
};