#include <iostream>

#include "Tuple.h"

Tuple::Tuple(unsigned char key, unsigned char val) : m_key(key), m_val(val)
{
    // left blank intentionally
}

unsigned char Tuple::getKey() const
{
    return m_key;
}

unsigned char Tuple::getVal() const
{
    return m_val;
}

void Tuple::setKey(unsigned char key)
{
    m_key = key;
}

void Tuple::setVal(unsigned char val)
{
    m_val = val;
}

bool Tuple::operator==(const Tuple& other) const
{
    return ((m_key == other.m_key) && (m_val == other.m_val));
}

Tuple::Tuple(const Tuple& other)
{
    m_key = other.m_key;
    m_val = other.m_val;
}

Tuple& Tuple::operator=(const Tuple& other)
{
    m_key = other.m_key;
    m_val = other.m_val;
    return *this;
}

Tuple::~Tuple()
{
    //delete &m_key;
    //delete &m_val;
}
