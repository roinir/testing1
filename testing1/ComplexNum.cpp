#include <iostream>

#include "ComplexNum.h"

ComplexNum::ComplexNum() : m_real(DEFAULT_REAL_PART), m_img(DEFAULT_IMAGINARY_PART)
{
    // Left blank intentionally
}

ComplexNum::ComplexNum(const int a, const int b) : m_real(a), m_img(b)
{
    // Left blank intentionally
}

int ComplexNum::getReal() const
{
    return m_real;
}

int ComplexNum::getImg() const
{
    return m_img;
}

void ComplexNum::setReal(int a)
{
    m_real = a;
}

void ComplexNum::setImg(int b)
{
    m_img = b;
}

void ComplexNum::printNum()
{
    std::cout << m_real << " + " << m_img << "i\n";
}

ComplexNum ComplexNum::operator+(const ComplexNum& other) const
{
    return ComplexNum(m_real + other.m_real, m_img + other.m_img);
}

ComplexNum ComplexNum::operator-(const ComplexNum& other) const
{
    return ComplexNum(m_real - other.m_real, m_img - other.m_img);
}

ComplexNum ComplexNum::operator*(const ComplexNum& other) const
{
    return ComplexNum(m_real * other.m_real - m_img * other.m_img, m_real * other.m_img + m_img * other.m_real);
}