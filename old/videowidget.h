#ifndef ROXEEPLAYER_VIDEOWIDGET_H
#define ROXEEPLAYER_VIDEOWIDGET_H

#include "libroxeeplayer_global.h"

#include <QWidget>
#include <QDebug>

class LIBROXEEPLAYERSHARED_EXPORT VideoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VideoWidget(QWidget *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *)
    {
        qDebug() << "Got keyboard shit";
    }

    void keyReleaseEvent(QKeyEvent *)
    {
        qDebug() << "Key release";
    }

    void focusInEvent(QFocusEvent *)
    {
        qDebug() << "Focus in";
    }

    void focusOutEvent(QFocusEvent *)
    {
        qDebug() << "Focus out";
    }

signals:
    
public slots:
    
};

#endif // ROXEEPLAYER_VIDEOWIDGET_H
