/*
============================================================================
Name : 15.c
Author : Saurabh Dubey
Description : 15. Write a program to display the environmental variable of the user (use environ).
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main(){

    extern char **environ;
    
    for(int i =0; environ[i]; i++){
        printf("%s \n",environ[i]);
        
    }

    return 0;
}

// //output
// SHELL=/bin/bash
// SESSION_MANAGER=local/pisces-cetus:@/tmp/.ICE-unix/1192,unix/pisces-cetus:/tmp/.ICE-unix/1192
// QT_ACCESSIBILITY=1
// COLORTERM=truecolor
// XDG_CONFIG_DIRS=/etc/xdg/xdg-cinnamon:/etc/xdg
// XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0
// TERM_PROGRAM_VERSION=1.92.2
// GNOME_DESKTOP_SESSION_ID=this-is-deprecated
// LANGUAGE=en_IN:en
// SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
// CINNAMON_VERSION=6.0.4
// DESKTOP_SESSION=cinnamon
// GTK_MODULES=gail:atk-bridge
// XDG_SEAT=seat0
// PWD=/home/h1n1cov/SS_handson
// XDG_SESSION_DESKTOP=cinnamon
// LOGNAME=h1n1cov
// QT_QPA_PLATFORMTHEME=qt5ct
// XDG_SESSION_TYPE=x11
// GPG_AGENT_INFO=/run/user/1000/gnupg/S.gpg-agent:0:1
// XAUTHORITY=/home/h1n1cov/.Xauthority
// VSCODE_GIT_ASKPASS_NODE=/usr/share/code/code
// XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/h1n1cov
// GJS_DEBUG_TOPICS=JS ERROR;JS LOG
// GDM_LANG=en_US
// HOME=/home/h1n1cov
// LANG=en_US.UTF-8
// LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
// XDG_CURRENT_DESKTOP=X-Cinnamon
// GIT_ASKPASS=/usr/share/code/resources/app/extensions/git/dist/askpass.sh
// XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0
// CHROME_DESKTOP=code-url-handler.desktop
// GJS_DEBUG_OUTPUT=stderr
// VSCODE_GIT_ASKPASS_EXTRA_ARGS=
// LESSCLOSE=/usr/bin/lesspipe %s %s
// XDG_SESSION_CLASS=user
// TERM=xterm-256color
// LESSOPEN=| /usr/bin/lesspipe %s
// USER=h1n1cov
// VSCODE_GIT_IPC_HANDLE=/run/user/1000/vscode-git-f2b6e1f908.sock
// DISPLAY=:0
// SHLVL=1
// XDG_VTNR=7
// XDG_SESSION_ID=c2
// XDG_RUNTIME_DIR=/run/user/1000
// VSCODE_GIT_ASKPASS_MAIN=/usr/share/code/resources/app/extensions/git/dist/askpass-main.js
// GTK3_MODULES=xapp-gtk3-module
// XDG_DATA_DIRS=/usr/share/cinnamon:/usr/share/gnome:/home/h1n1cov/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share
// GDK_BACKEND=x11
// PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
// GDMSESSION=cinnamon
// ORIGINAL_XDG_CURRENT_DESKTOP=X-Cinnamon
// DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
// GIO_LAUNCHED_DESKTOP_FILE_PID=2840
// GIO_LAUNCHED_DESKTOP_FILE=/usr/share/applications/code.desktop
// TERM_PROGRAM=vscode
// _=./a.out