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

class SEVariance {
public:
    SEVariance() : m_n(0) {
        max = 0;
        min = 0;
    }
    
    void clear() {
        m_n = 0;
    }
    
    void push(double x) {
        
        if (x > max) {
            max = x;
        }
        
        if (x < min) {
            min = x;
        }
        
        m_n++;
        
        // See Knuth TAOCP vol 2, 3rd edition, page 232
        if (m_n == 1)
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
    
    double mean() const {
        return (m_n > 0) ? m_newM : 0.0;
    }
    
    double variance() const {
        return ( (m_n > 1) ? m_newS/(m_n - 1) : 0.0 );
    }
    
    double standardDeviation() const {
        return sqrt(variance());
    }
    
    double allTimeMax() const {
        return max;
    }
    
    double allTimeMin() const {
        return min;
    }
    
private:
    int m_n;
    double m_oldM, m_newM, m_oldS, m_newS;
    
    double max, min;
};

#endif
