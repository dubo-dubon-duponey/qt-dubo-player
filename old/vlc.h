#ifndef VLC_H
#define VLC_H

#include <QObject>
#include "core.h"

namespace RoxeePlayer{

class vlc : public QObject
{
    Q_OBJECT
public:
    explicit vlc(QObject *parent = 0);
    Core * core;

signals:
    
public slots:
    
private:
    class Private;
    Private* vlcHide;

};

}

#endif // VLC_H
