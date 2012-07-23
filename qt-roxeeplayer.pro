# Enforce recent QT
lessThan(QT_VERSION, 4.8) {
    error("RoxeePlayer is tested only with Qt 4.8 or greater")
}

# Explore subdirs in order
TEMPLATE = subdirs
CONFIG = ordered
SUBDIRS = src demo

OTHER_FILES += vars.pri.in \
    res/doxygen.tpl \
    res/redist/AUTHORS \
    res/redist/ChangeLog \
    res/redist/LICENSE.LGPL \
    README

# Existing implementations:
# https://bitbucket.org/trollixx/qtvlc/
# https://github.com/ntadej/vlc-qt/tree/master/src/core
