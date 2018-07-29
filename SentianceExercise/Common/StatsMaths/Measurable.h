//
//  MeasurableDouble.h
//  SentianceExercise
//
//  Created by Apple on 7/29/18.
//  Copyright © 2018 Maliwan. All rights reserved.
//

#ifndef _Measurable_h_
#define _Measurable_h_

#include <iostream>
#include "OperatorCallsCountHolder.h"

class Measurable
{    
public:
    
    Measurable() {
        value = 0.0;
    }
    
    Measurable(double Measurable) : value(Measurable)
    {
    }
    
    Measurable& operator= (const Measurable &measurable);
    
    friend bool operator== (const Measurable &m1, const Measurable &m2);
    friend bool operator!= (const Measurable &m1, const Measurable &m2);
    
    friend bool operator> (const Measurable &m1, const Measurable &m2);
    friend bool operator<= (const Measurable &m1, const Measurable &m2);
    
    friend bool operator< (const Measurable &m1, const Measurable &m2);
    friend bool operator>= (const Measurable &m1, const Measurable &m2);
    
    friend Measurable operator+(const Measurable &m1, const Measurable &m2);
    friend Measurable operator+(const Measurable &m1, const Measurable &m2);
    friend Measurable operator-(const Measurable &m1, const Measurable &m2);
    
    friend Measurable operator*(const Measurable &m1, const Measurable &m2);
    friend Measurable operator/(const Measurable &m1, const Measurable &m2);
    
    friend std::ostream & operator << (std::ostream &out, const Measurable &m);
    friend std::istream & operator >> (std::istream &in,  Measurable &m);
    
    Measurable& operator+=(const Measurable& right);
    Measurable& operator-=(const Measurable& right);
    Measurable& operator*=(const Measurable& right);
    Measurable& operator/=(const Measurable& right);
    
    Measurable& operator++();
    Measurable operator++(int);
    
    operator double() { return value; }
    
    double value;
};

static long long operatorCallsCount = 0;

static void incrementOperatorCalls() {
    operatorCallsCount++;
}

static long getOperatorCallsCount() {
    return operatorCallsCount;
}


inline double operator+(double value, const Measurable& m)
{
    return value + m.value;
}

inline Measurable& Measurable::operator= (const Measurable &measurable)
{
    value = measurable.value;
    return *this;
}

inline bool operator== (const Measurable &m1, const Measurable &m2)
{
    incrementOperatorCalls();
    return (m1.value == m2.value);
}

inline bool operator!= (const Measurable &m1, const Measurable &m2)
{
    incrementOperatorCalls();
    return !(m1== m2);
}

inline bool operator> (const Measurable &m1, const Measurable &m2)
{
    incrementOperatorCalls();
    return m1.value > m2.value;
}

inline bool operator>= (const Measurable &m1, const Measurable &m2)
{
    incrementOperatorCalls();
    return m1.value >= m2.value;
}

inline bool operator< (const Measurable &m1, const Measurable &m2)
{
    incrementOperatorCalls();
    return m1.value < m2.value;
}

inline bool operator<= (const Measurable &m1, const Measurable &m2)
{
    //Measurable::comparisonOperatorsCount++;
    return m1.value <= m2.value;
}

inline Measurable operator+(const Measurable &m1, const Measurable &m2)
{
    return Measurable(m1.value + m2.value);
}

inline Measurable operator-(const Measurable &m1, const Measurable &m2)
{
    return Measurable(m1.value - m2.value);
}

inline Measurable operator*(const Measurable &m1, const Measurable &m2)
{
    return Measurable(m1.value * m2.value);
}

inline Measurable operator/(const Measurable &m1, const Measurable &m2)
{
    return Measurable(m1.value / m2.value);
}

inline Measurable& Measurable::operator+=(const Measurable& right)
{
    this->value += right.value;
    return *this;
}

inline Measurable& Measurable::operator-=(const Measurable& right)
{
    this->value -= right.value;
    return *this;
}

inline Measurable& Measurable::operator*=(const Measurable& right)
{
    this->value *= right.value;
    return *this;
}

inline Measurable& Measurable::operator/=(const Measurable& right)
{
    this->value /= right.value;
    return *this;
}

inline std::ostream & operator << (std::ostream &out, const Measurable &c)
{
    out << c.value;
    return out;
}

inline std::istream & operator >> (std::istream &in,  Measurable &c)
{
    in >> c.value;
    return in;
}

inline Measurable& Measurable::operator++()
{
    value++;
    return *this;
}

inline Measurable Measurable::operator++(int)
{
    Measurable temp = *this;
    ++*this;
    return temp;
}

#endif
