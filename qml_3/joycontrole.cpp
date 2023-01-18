#include "joycontrole.h"

JoyControle::JoyControle()
{

}

bool JoyControle::x() const
{
    return m_x;
}

void JoyControle::setX(bool newX)
{
    if (m_x == newX)
        return;
    m_x = newX;
    emit xChanged();
}

bool JoyControle::rec() const
{
    return m_rec;
}

void JoyControle::setRec(bool newRec)
{
    if (m_rec == newRec)
        return;
    m_rec = newRec;
    emit recChanged();
}

bool JoyControle::tri() const
{
    return m_tri;
}

void JoyControle::setTri(bool newTri)
{
    if (m_tri == newTri)
        return;
    m_tri = newTri;
    emit triChanged();
}

bool JoyControle::cir() const
{
    return m_cir;
}

void JoyControle::setCir(bool newCir)
{
    qDebug() << "meerhaba";
    if (m_cir == newCir)
        return;
    m_cir = newCir;
    emit cirChanged();
}

bool JoyControle::up() const
{
    return m_up;
}

void JoyControle::setUp(bool newUp)
{
    if (m_up == newUp)
        return;
    m_up = newUp;
    emit upChanged();
}

bool JoyControle::down() const
{
    return m_down;
}

void JoyControle::setDown(bool newDown)
{
    if (m_down == newDown)
        return;
    m_down = newDown;
    emit downChanged();
}

bool JoyControle::left() const
{
    return m_left;
}

void JoyControle::setLeft(bool newLeft)
{
    if (m_left == newLeft)
        return;
    m_left = newLeft;
    emit leftChanged();
}

bool JoyControle::right() const
{
    return m_right;
}

void JoyControle::setRight(bool newRight)
{
    if (m_right == newRight)
        return;
    m_right = newRight;
    emit rightChanged();
}
