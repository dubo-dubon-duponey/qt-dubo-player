#!/bin/sh

TP_VERSION=${1:-2.2.8}

curlit(){
    local url=$1
    local artifact=$2
    if [ ! -f $artifact ]; then
        curl -L "$url" > $artifact
        if [[ $? != 0 ]]; then
            echo "FAILED. Cleaning-up."
            rm $artifact
            exit 1
        fi
    fi
}

unpack(){
    local artifact=$1
    local unpacked=$2
    if [ ! -d "$unpacked" ]; then
        mkdir "$unpacked"
        cd "$unpacked"
        # unzip ../$artifact > /dev/null
        7z x ../$artifact > /dev/null
        if [[ $? != 0 ]]; then
            echo "FAILED. Cleaning-up."
            rm -Rf "$unpacked"
            exit 1
        fi
        cd -
    fi
}

undmg(){
    local artifact=$1
    local unpacked=$2
    local version=$3
    if [ ! -d "$unpacked" ]; then
        local volume=$(hdiutil attach $artifact | grep "$version")
        volume=($volume)
        cp -R /Volumes/vlc-$version/VLC.app $unpacked
        hdiutil detach $volume
        if [[ $? != 0 ]]; then
            echo "FAILED. Cleaning-up."
            rm -Rf "$unpacked"
            exit 1
        fi
    fi
}

download_windows(){
    local app=$1
    local platform=$2
    local version=$3
    local url=https://download.videolan.org/pub/videolan/vlc/$version/$platform/vlc-$version-$platform.7z

    local artifact=$version-$platform.7z
    local unpacked=$version-$platform.bin

    echo "Downloading $app for $platform $version into $artifact"
    curlit $url $artifact

    echo "Extracting $app for $platform $version into $unpacked"
    unpack "$artifact" "$unpacked"
}


download_mac(){
    local app=$1
    local platform=$2
    local version=$3
    local url=https://download.videolan.org/pub/videolan/vlc/$version/$platform/vlc-$version.dmg

    local artifact=$version-$platform.dmg
    local unpacked=$version-$platform.app

    echo "Downloading $app for $platform $version into $artifact"
    curlit $url $artifact

    echo "Extracting $app for $platform $version into $unpacked"
    undmg "$artifact" "$unpacked" $version

}

download_windows    VLC     win64   $TP_VERSION
download_mac        VLC     macosx  $TP_VERSION

exit

xxxdownloadNightly(){
    rm -Rf "$TP_VERSION.zip" || echo "Nothing to clean-up"
    curl -o $TP_VERSION.zip "https://nightlies.videolan.org/build/macosx-intel/vlc-$version.zip"
    # Tired of this shit
    rm -Rf vlc-$TP_VERSION
    unzip "$TP_VERSION.zip"
    mv vlc-$TP_VERSION/VLC.app VLC-${TP_VERSION}.app
}
