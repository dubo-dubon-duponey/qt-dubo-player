ROXEE_PROJECT_NAME = RoxeePlayer
ROXEE_VENDOR_NAME = WebItUp
ROXEE_PROJECT_VERSION_MAJOR = 0
ROXEE_PROJECT_VERSION_MINOR = 6
ROXEE_PROJECT_VERSION_BUGFIX = 0

# Wether to build static, shared, or plugin
ROXEE_LINK_TYPE = static
#ROXEE_LINK_TYPE = plugin
#ROXEE_LINK_TYPE = dynamic
#ROXEE_DEPEND_LINK = dynamic

ROXEE_DEPEND_LINK = static

# Where to find additional dependencies (eg: external (win)-sparkle)
# This will take precedence over the provided third-party builds
CONFIG(debug, debug|release){
    ADDITIONAL_DEPENDENCIES_DIR = /Users/dmp/buildd/deploy.webitup.org/client/Darwin/debug/$${ROXEE_DEPEND_LINK}
}else{
    ADDITIONAL_DEPENDENCIES_DIR = /Users/dmp/buildd/deploy.webitup.org/client/Darwin/release/$${ROXEE_DEPEND_LINK}
}
# Where to output the final build
ROXEE_DESTDIR =

TARGET = roxeeplayer
