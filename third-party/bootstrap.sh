#!/bin/sh

TP_VERSION=${1:-2.2.8}

curlit(){
    local url="$1"
    local artifact="$2"
    if [ ! -f $artifact ]; then
        if ! curl -L "$url" > "$artifact"; then
            echo "FAILED downloading. Cleaning-up."
            rm "$artifact"
            exit 1
        fi
    fi
}

unpack(){
    local artifact="$1"
    local unpacked="$2"
    if [ ! -d "$unpacked" ]; then
        mkdir "$unpacked"
        cd "$unpacked"
        if ! 7z x ../$artifact > /dev/null; then
            echo "FAILED extracting ZIP. Cleaning-up."
            cd - >/dev/null
            rm -Rf "$unpacked"
            exit 1
        fi
        cd -
    fi
}

undmg(){
    local artifact="$1"
    local unpacked="$2"
    local version="$3"
    if [ ! -d "$unpacked" ]; then
        local volume="$(hdiutil attach "$artifact" | grep "VLC")"
        # Version 2
        # cp -R "/Volumes/vlc-$version/VLC.app" "$unpacked"
        # Version 3
        cp -R "/Volumes/VLC media player/VLC.app" "$unpacked"
        if ! hdiutil detach "${volume%% *}"; then
            echo "FAILED extracting DMG. Cleaning-up."
            rm -Rf "$unpacked"
            exit 1
        fi
    fi
}

download_windows(){
    local platform="$1"
    local version="$2"
    local url=https://download.videolan.org/pub/videolan/vlc/$version/$platform/vlc-$version-$platform.7z

    local artifact=$version-$platform.7z
    local unpacked=$version-$platform.bin

    echo "Downloading for $platform $version into $artifact"
    curlit "$url" "$artifact"

    echo "Extracting for $platform $version into $unpacked"
    unpack "$artifact" "$unpacked"
}


download_mac(){
    local platform="$1"
    local version="$2"
    # nightlies: "https://nightlies.videolan.org/build/macosx-intel/vlc-$version.zip"
    local url=https://download.videolan.org/pub/videolan/vlc/$version/$platform/vlc-$version.dmg

    local artifact=$version-$platform.dmg
    local unpacked=$version-$platform.app

    echo "Downloading for $platform $version into $artifact"
    curlit "$url" "$artifact"

    echo "Extracting for $platform $version into $unpacked"
    undmg "$artifact" "$unpacked" "$version"

}

download_mac        macosx  $TP_VERSION
download_windows    win64   $TP_VERSION
