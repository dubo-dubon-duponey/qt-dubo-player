#ifndef QTVLCLOGGING_H
#define QTVLCLOGGING_H

#include <QtCore/QObject>

namespace RoxeePlayer
{
    class Logging : public QObject
    {
        Q_OBJECT
    public:
        explicit Logging(QObject *parent = 0);
        ~Logging();

        Q_PROPERTY(uint DEBUG READ getDebug)
        Q_PROPERTY(uint NOTICE READ getNotice)
        Q_PROPERTY(uint WARNING READ getWarning)
        Q_PROPERTY(uint ERROR READ getError)

//        Q_PROPERTY(uint verbosity READ getVerbosity WRITE setVerbosity)

        uint getDebug(){return 0;}
        uint getNotice(){return 2;}
        uint getWarning(){return 3;}
        uint getError(){return 4;}

        void LogCb(void * data, int level, const char *fmt, va_list args);

//        uint getVerbosity();
//        void setVerbosity(uint verbosity);

    signals:

    public slots:

    };
}

#endif // QTVLCLOGGING_H
