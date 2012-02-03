#ifndef QTVLCERROR_H
#define QTVLCERROR_H

#include <QObject>

namespace QtVlc
{
    class ErrorHandling : public QObject
    {
        Q_OBJECT

    public:
        explicit ErrorHandling(QObject *parent = 0);
        ~ErrorHandling();

        void clearErr();
        QString errMsg();
    signals:

    public slots:

    };
}

#endif // QTVLCERROR_H
