#include "coreinstance.h"

LRPCoreInstance* LRPCoreInstance::m_Instance = 0;

// 1.1
//    // Convert arguments
//    std::string stdStrings[args.size()];
//    const char *vlcArgs[args.size()];
//    for(int i = 0; i < args.size(); i++) {
//            stdStrings[i] = args[i].toStdString();
//            vlcArgs[i] = stdStrings[i].c_str();
//    }

//    // libvlc_instance_t * 	libvlc_new (int argc, const char *const *argv)
//    // Create and initialize a libvlc instance.
//    _vlc = libvlc_new(sizeof(vlcArgs) / sizeof(*vlcArgs), vlcArgs);
