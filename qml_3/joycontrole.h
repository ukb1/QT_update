#ifndef JOYCONTROLE_H
#define JOYCONTROLE_H
#include "project_type.h"

class JoyControle: public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool  x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(bool rec READ rec WRITE setRec NOTIFY recChanged)
    Q_PROPERTY(bool tri READ tri WRITE setTri NOTIFY triChanged)
    Q_PROPERTY(bool cir READ cir WRITE setCir NOTIFY cirChanged)
    Q_PROPERTY(bool up READ up WRITE setUp NOTIFY upChanged)
    Q_PROPERTY(bool up READ up WRITE setUp NOTIFY upChanged)
    Q_PROPERTY(bool down READ down WRITE setDown NOTIFY downChanged)
    Q_PROPERTY(bool left READ left WRITE setLeft NOTIFY leftChanged)
    Q_PROPERTY(bool right READ right WRITE setRight NOTIFY rightChanged)


public:

    JoyControle();
    bool x() const;
    void setX(bool newX);
    bool rec() const;
    void setRec(bool newRec);

    bool tri() const;
    void setTri(bool newTri);

    bool cir() const;
    Q_INVOKABLE void setCir(bool newCir);

    bool up() const;
    void setUp(bool newUp);

    bool down() const;
    void setDown(bool newDown);

    bool left() const;
    void setLeft(bool newLeft);

    bool right() const;
    void setRight(bool newRight);

signals:
    void xChanged();
    void recChanged();

    void triChanged();

    void cirChanged();

    void upChanged();

    void downChanged();

    void leftChanged();

    void rightChanged();

private:
    bool m_x;
    bool m_rec;
    bool m_tri;
    bool m_cir;
    bool m_up;
    bool m_down;
    bool m_left;
    bool m_right;
};



#endif // JOYCONTROLE_H
