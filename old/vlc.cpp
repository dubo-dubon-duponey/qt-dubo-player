#include "vlc.h"

#include <vlc/vlc.h>

class Private
{
    public:
        libvlc_instance_t* instance;
        libvlc_media_player_t * player;
};


vlc::vlc(QObject *parent) :
    QObject(parent)
{
    vlcHide = new Private();
    const char * const vlcArgs[] = {
        "-I", "dummy", /* Don't use any interface */
        "--ignore-config", /* Don't use VLC's config */
        "--no-osd" };
    if((vlcHide->instance = libvlc_new(sizeof(vlcArgs) / sizeof(*vlcArgs), vlcArgs)) == NULL) {
        qDebug() << QString::fromAscii("Could not init libVLC");
    }
}

vlc::~vlc()
{
    libvlc_release(vlcHide->instance);
    delete vlcHide;
}


//// Convert arguments to required format
//std::string stdStrings[args.size()];
//const char *vlcArgs[args.size()];
//for(int i = 0; i < args.size(); i++) {
//    stdStrings[i] = args[i].toStdString();
//    vlcArgs[i] = stdStrings[i].c_str();
//}

//// Create new libvlc instance
//_vlcInstance = libvlc_new(sizeof(vlcArgs) / sizeof(*vlcArgs), vlcArgs);



//// QVarLengthArray by default allocates 256 elements, it should be enough
//Q_ASSERT(args.size() <= 256);

//QList<QByteArray> argvList;
//QVarLengthArray<const char*> argv;
//foreach (QString arg, args) {
//    argvList.append(arg.toUtf8());
//    argv.append(argvList.last().constData());
//}

//m_vlcInstance = libvlc_new(argv.size(), argv.constData());
