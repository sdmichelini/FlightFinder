//
//  BitMatrix.cpp
//  FlightFinder
//
//  Created by Steve Michelini on 9/24/15.
//  Copyright © 2015 sdmichelini. All rights reserved.
//

#include "BitMatrix.hpp"
#include <cassert>
#include <cmath>

char GetMask(uint32_t bit){
    switch(bit){
        case 0:
            return 0x1;
            break;
        case 1:
            return (0x1 <<1);
            break;
        case 2:
            return (0x1 <<2);
            break;
        case 3:
            return (0x1 <<3);
            break;
        case 4:
            return (0x1 <<4);
            break;
        case 5:
            return (0x1 <<5);
            break;
        case 6:
            return (0x1 <<6);
            break;
        case 7:
            return (0x1 <<7);
            break;
        default:
            return 0x00;
            
    }
}

BitMatrix::BitMatrix(){
    m_rows = 0;
    m_columns = 0;
}

void BitMatrix::AddRow(){
    if(!m_rows && !m_columns){
        m_matrixData.push_back((char)0x00);
        m_rows = 1;
        m_columns = 1;
        return;
    }
    m_rows++;
    //Do we need to resize the data structure holding the matrix?
    if((m_columns * m_rows) > (m_matrixData.size() * 8)){
        m_matrixData.push_back((char)0x00);
    }
}

void BitMatrix::AddColumn(){
    if(!m_rows && !m_columns){
        m_matrixData.push_back((char)0x00);
        m_rows = 1;
        m_columns = 1;
        return;
    }
    m_columns++;
    //Do we need to resize the data structure holding the matrix?
    if((m_columns * m_rows) > (m_matrixData.size() * 8)){
        m_matrixData.push_back((char)0x00);
    }
}

void BitMatrix::SetDataAt(uint32_t row, uint32_t column, bool value){
    assert((row < m_rows)&&(column < m_columns));
    uint32_t bitRequested = (column * m_rows) + row;
    uint32_t byteRequested = floor(bitRequested/8);
    
    bitRequested = bitRequested % 8;
    if(value){
        m_matrixData[byteRequested] |= GetMask(bitRequested);
    }else{
        m_matrixData[byteRequested] &= ~GetMask(bitRequested);
    }
}

bool BitMatrix::GetDataAt(uint32_t row, uint32_t column) const {
    assert((row < m_rows)&&(column < m_columns));
    uint32_t bitRequested = (column * m_rows) + row;
    uint32_t byteRequested = floor(bitRequested/8);
    bitRequested = bitRequested % 8;
    
    return m_matrixData[byteRequested] & GetMask(bitRequested);
}

MatrixSize BitMatrix::GetSize() const {
    MatrixSize m;
    m.rows = m_rows;
    m.columns = m_columns;
    return m;
}