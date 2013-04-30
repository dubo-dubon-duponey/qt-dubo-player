#!/bin/sh

VERSION=$1
FORCE_CLEAN=$2
if [[ "$VERSION" == "" ]]; then
    VERSION='2.0.3'
fi

SRC_DIR=VLC-${VERSION}.app

extDMG(){
    VOLUME=`hdiutil attach $VERSION.dmg | grep "$VERSION"`
    VOLUME=($VOLUME)
    cp -R /Volumes/vlc-$VERSION/VLC.app $SRC_DIR
    hdiutil detach $VOLUME
}


download(){
    rm -Rf "$VERSION.dmg" || echo "Nothing to clean-up"
    curl -o "$VERSION.dmg" "http://download.videolan.org/pub/videolan/vlc/$VERSION/macosx/vlc-$VERSION.dmg"
    extDMG
}

downloadNightly(){
    rm -Rf "$VERSION.zip" || echo "Nothing to clean-up"
    curl -o $VERSION.zip "http://nightlies.videolan.org/build/macosx-intel/vlc-$VERSION.zip"
    # Tired of this shit
    rm -Rf vlc-2.0.7
    unzip "$VERSION.zip"
    mv vlc-2.0.7/VLC.app VLC-${VERSION}.app
}



if [[ "$FORCE_CLEAN" != "" ]]
then
    rm -Rf $SRC_DIR || echo "Nothing to clean-up"
fi

if [ ! -d "$SRC_DIR" ]; then
    echo "Downloading"
    downloadNightly
else
    echo "Already there. If you want to force redownload, use ./bootstrap.sh $VERSION clean"
fi

rm -f VLC.app || echo "Nothing to clean-up"
ln -s VLC-${VERSION}.app VLC.app
