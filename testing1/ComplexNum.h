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

  private:
    int m_real;
    int m_img;
};