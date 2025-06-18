#pragma once

class ComplexNum
{
  public:
    ComplexNum();
    ComplexNum(const int a, const int b);
    int getReal() const;
    int getImg() const;
    void setReal(const int a);
    void setImg(const int b);
    void printNum();
    ComplexNum operator+(const ComplexNum& other) const;
    ComplexNum operator-(const ComplexNum& other) const;
    ComplexNum operator*(const ComplexNum& other) const;

  private:
    int m_real;
    int m_img;
};

const int DEFAULT_REAL_PART = 0;
const int DEFAULT_IMAGINARY_PART = 0;