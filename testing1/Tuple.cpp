#include <iostream>

#include "Tuple.h"

template <typename T1, typename T2> Tuple<T1, T2>::Tuple(T1 key, T2 val) : m_key(key), m_val(val)
{
    // left blank intentionally
}

template <typename T1, typename T2> T1 Tuple<T1, T2>::getKey() const
{
    return m_key;
}

template <typename T1, typename T2> T2 Tuple<T1, T2>::getVal() const
{
    return m_val;
}

template <typename T1, typename T2> void Tuple<T1, T2>::setKey(T1 key)
{
    m_key = key;
}

template <typename T1, typename T2> void Tuple<T1, T2>::setVal(T2 val)
{
    m_val = val;
}

template <typename T1, typename T2> bool Tuple<T1, T2>::operator==(const Tuple<T1, T2>& other) const
{
    return ((m_key == other.m_key) && (m_val == other.m_val));
}

template <typename T1, typename T2> Tuple<T1, T2>::Tuple(const Tuple<T1, T2>& other)
{
    m_key = other.m_key;
    m_val = other.m_val;
}

template <typename T1, typename T2> Tuple<T1, T2>& Tuple<T1, T2>::operator=(const Tuple<T1, T2>& other)
{
    m_key = other.m_key;
    m_val = other.m_val;
    return *this;
}

template <typename T1, typename T2> Tuple<T1, T2>::~Tuple()
{
    delete m_key;
    delete m_val;
}