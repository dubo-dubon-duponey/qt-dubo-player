ROXEE_PROJECT_NAME = RoxeePlayer
ROXEE_VENDOR_NAME = WebItUp
ROXEE_PROJECT_VERSION_MAJOR = 0
ROXEE_PROJECT_VERSION_MINOR = 7
ROXEE_PROJECT_VERSION_BUGFIX = 0-dev
ROXEE_MINIMUM_QT = 4.8
ROXEE_MIN_OSX = 10.6

# Name of the target
TARGET = roxeeplayer

# Any of the following may also be specified using environment variables

# Wether to build static, plugin or shared library
#ROXEE_LINK_TYPE = plugin
#ROXEE_LINK_TYPE = static
ROXEE_LINK_TYPE = dynamic

# If you want to use the provided mechanism to fetch and link VLC, specify which version you want here
# Otherwise, you must specify ROXEE_EXTERNAL (below)
ROXEE_INTERNAL_VERSION = 2.0.3
# 2.0.5 is crashing - even on a very simple vlc example - likely an upstream bug

# Where to find additional dependencies (include and libs)
# Note this will be used BEFORE any other manually specified source, so, careful with that
ROXEE_EXTERNAL =


# Where to output the final build (will default to buildd/platform/compiler-linktype-production)
ROXEE_DESTDIR =











# XXX private stuff - to be removed

#renvlt=$$(ROXEE_LINK_TYPE)
#isEmpty(renvlt){
#    renvlt=$$ROXEE_LINK_TYPE
#}

#isEmpty(ROXEE_EXTERNAL){
#    CONFIG(debug, debug|release){
#        mac{
#            ROXEE_EXTERNAL = /Users/dmp/buildd/deploy.webitup.org/client/Darwin/debug/$${renvlt}
#        }
#    }else{
#        mac{
#            ROXEE_EXTERNAL = /Users/dmp/buildd/deploy.webitup.org/client/Darwin/release/$${renvlt}
#        }
#    }
#}
