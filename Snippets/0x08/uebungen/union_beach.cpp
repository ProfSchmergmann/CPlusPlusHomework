//
// Created by Sven on 05.06.2020.
//

#include <iostream>
using namespace std;

template<typename T>
class matrix {
private:
    const int m_dim;
    typedef typename T type;
    int m_m[][];
public:
    matrix(int dim, T type) : m_dim{dim}, m_type{type} {
        m_type[m_dim][m_dim]
    }

};