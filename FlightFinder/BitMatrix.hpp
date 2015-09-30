//
//  BitMatrix.hpp
//  FlightFinder
//
//  Created by Steve Michelini on 9/24/15.
//  Copyright © 2015 sdmichelini. All rights reserved.
//

#ifndef BitMatrix_hpp
#define BitMatrix_hpp

#include <vector>

typedef struct{
    uint32_t rows;
    uint32_t columns;
} MatrixSize;

class BitMatrix{
public:
    BitMatrix();
    void AddRow();
    void AddColumn();
    void SetDataAt(uint32_t row, uint32_t column, bool value);
    bool GetDataAt(uint32_t row, uint32_t column) const;
    MatrixSize GetSize() const;
private:
    std::vector<char> m_matrixData;
    
    uint32_t m_rows;
    uint32_t m_columns;
};
#endif /* BitMatrix_hpp */
