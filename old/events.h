#ifndef QTVLCASYNCHRONOUSEVENTS_H
#define QTVLCASYNCHRONOUSEVENTS_H

#include <QtCore/QObject>

namespace RoxeePlayer
{
    class Events : public QObject
    {
        Q_OBJECT
    public:
        explicit Events(QObject *parent = 0);
        ~Events();

    signals:

    public slots:

    };
}

#endif // QTVLCASYNCHRONOUSEVENTS_H
