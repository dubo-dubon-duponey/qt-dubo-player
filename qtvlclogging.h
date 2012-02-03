#ifndef QTVLCLOGGING_H
#define QTVLCLOGGING_H

#include <QObject>

namespace QtVlc
{
    class Logging : public QObject
    {
        Q_OBJECT
    public:
        explicit Logging(QObject *parent = 0);
        ~Logging();

    signals:

    public slots:

    };
}

#endif // QTVLCLOGGING_H
