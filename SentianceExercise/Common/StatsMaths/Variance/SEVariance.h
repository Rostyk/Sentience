//
//  SEStatsMath.h
//  SentianceExercise
//
//  Created by Apple on 7/28/18.
//  Copyright © 2018 Maliwan. All rights reserved.
//
#include "math.h"

#ifndef _SEVariance_
#define _SEVariance_

template <class T>
class SEVariance {
public:
    
    SEVariance<T>() {
        
    }
    
    void clear() {
        m_n = 0;
    }
    
    void push(T x) {
        if (x > max) {
            max = x;
        }
        
        if (x < min) {
            min = x;
        }
        
        m_n++;
        
        // See Knuth TAOCP vol 2, 3rd edition, page 232
        if (m_n == T(1))
        {
            m_oldM = m_newM = x;
            m_oldS = 0.0;
        }
        else
        {
            m_newM = m_oldM + (x - m_oldM)/m_n;
            m_newS = m_oldS + (x - m_oldM)*(x - m_newM);
            
            m_oldM = m_newM;
            m_oldS = m_newS;
        }
    }
    
    int numDataValues() const {
        return m_n;
    }
    
    T mean() const {
        return (m_n > 0) ? m_newM : 0.0;
    }
    
    T variance() const {
        return ( (m_n > 1) ? m_newS/(m_n - 1.0) : T(0.0) );
    }
    
    T standardDeviation() const {
        return sqrt(variance());
    }
    
    T allTimeMax() const {
        return max;
    }
    
    double allTimeMin() const {
        return min;
    }
    
private:
    T m_n;
    T m_oldM, m_newM, m_oldS, m_newS;
    
    T max, min;
};

#endif
