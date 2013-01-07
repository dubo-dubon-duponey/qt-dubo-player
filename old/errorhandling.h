#ifndef ROXEEPLAYER_ERRORHANDLING_H
#define ROXEEPLAYER_ERRORHANDLING_H

#include <QtCore/QObject>

namespace RoxeePlayer
{
    class ErrorHandling : public QObject
    {
        Q_OBJECT

    public:
        explicit ErrorHandling(QObject *parent = 0);
        ~ErrorHandling();

        Q_PROPERTY(const QString error READ getErrMsg())
        Q_INVOKABLE void clearErr();

        QString getErrMsg();
    signals:

    public slots:

    };
}

#endif // ROXEEPLAYER_ERRORHANDLING_H
