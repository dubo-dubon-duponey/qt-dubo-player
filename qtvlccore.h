#ifndef QTVLCPLAYER_H
#define QTVLCPLAYER_H

#include <QObject>
#include <QStringList>
#include <QMutex>

#include <vlc/vlc.h>

struct libvlc_instance_t;

namespace QtVlc
{
    class Core : public QObject
    {
        Q_OBJECT
    public:
        explicit Core(QObject *parent = 0);
        ~Core();

        static Core* instance();

        void setUserAgent(const QString &appName, const QString &appVersion);
        QString getVersion();
        QString getChangeset();
        QString getCompiler();
        QStringList audioFilterList();
        QStringList videoFilterList();

        // Allow access to the actual vlc instance
        friend class MediaPlayer;

    protected:
        libvlc_instance_t* _vlc;

    signals:

    public slots:


    private:
        static Core* m_Instance;

    };

}
#endif // QTVLCPLAYER_H
