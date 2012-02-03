#ifndef QTVLCASYNCHRONOUSEVENTS_H
#define QTVLCASYNCHRONOUSEVENTS_H

#include <QObject>

namespace QtVlc
{
    class AsynchronousEvents : public QObject
    {
        Q_OBJECT
    public:
        explicit AsynchronousEvents(QObject *parent = 0);
        ~AsynchronousEvents();

    signals:

    public slots:

    };
}

#endif // QTVLCASYNCHRONOUSEVENTS_H
