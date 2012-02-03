#ifndef QTVLC2_H
#define QTVLC2_H

#include <QObject>
#include "qtvlcmediaplayer.h"
#include "qtvlc_global.h"
#include <QVBoxLayout>
#include <QStackedLayout>

using namespace QtVlc;

class QTVLCSHARED_EXPORT qtvlc2 : public QWidget
{
    Q_OBJECT
public:
    explicit qtvlc2(const QString & appPath, QWidget *parent = 0);
    ~qtvlc2();
    MediaPlayer * mediaPlayer();

signals:
    
public slots:

private:
    MediaPlayer * _vp;

};

#endif // QTVLC2_H




