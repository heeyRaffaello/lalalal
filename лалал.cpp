//
//  лалал.cpp
//  лалалала
//
//  Created by Macbook Air 13 on 29.09.15.
//  Copyright (c) 2015 Macbook Air 13. All rights reserved.
//

#include "лалал.h"

TBitField::TBitField(const int _BitSize)
{
    BitSize = _BitSize;
    Size=BitSize/(sizeof(TELEM)*8)+1;
    mass=new TELEM[Size];
    for (int i=0; i<Size; i++)
        mass[i]=0;
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    Size=bf.Size;
    BitSize=bf.BitSize;
    delete[]mass;
    mass=new TELEM[bf.Size];
    for (int i=0; i<bf.Size; i++)
        mass[i]=bf.mass[i];
}

TBitField::~TBitField()
{
    delete [] mass;
}

int TBitField::GetIndex(const int BitPos) const // индекс Мем для бита n
{
    return (BitPos/(sizeof(TELEM)*8));
}

TELEM TBitField::GetMask(const int BitPos) const // битовая маска для бита n
{
    int Pos = BitPos%32;
    int temp=1;
    temp<<=Pos;
    return temp;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitSize;
}

void TBitField::SetBit(const int BitPos) // установить бит
{
    int Index=GetIndex(BitPos);
    TELEM mask = GetMask(BitPos);
    mass[Index]=mass[Index]|mask;

}

void TBitField::ClrBit(const int BitPos) // очистить бит
{
    int Index =GetIndex(BitPos);
    TELEM mask=~GetMask(BitPos);
    mass[Index]=mass[Index]&mask;
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if ((n>-1) && (n<BitSize))
        return mass[Index];
}


// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    return 0;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    if ((Size==bf.Size)&&(BitSize==bf.BitSize))
      for (int i=0;i<bf.Size; i++)
          if (mass[i]==bf.mass[i]) break;
    if (i<bf.Size - 1) return 1;
        else return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    int len=BitSize;
    if (bf.BitSize > len) len=bf.BitSize;
    TBitField temp(len);
    for (int i=0; i<Size; i++)
        temp.mass[i]=mass[i]/bf.mass[i];
    return temp;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
}

TBitField TBitField::operator~(void) // отрицание
{
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i=0; i<bf.BitSize; i++)
        if (GetBit(i)) os<<1;
        else os<<0;
    return os;
}