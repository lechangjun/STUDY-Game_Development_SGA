#!/bin/bash
sudo  yum clean all
sudo yum install -y epel-release
sudo yum -y update
sudo yum -y install gcc
## 루트 권환이어야 실행됨
rpm --import https://packages.microsoft.com/keys/microsoft.asc
#sudo vi /etc/yum.repos.d/google-chrome.repo

##[google-chrome]
##name=google-chrome
##baseurl=http://dl.google.com/linux/chrome/rpm/stable/$basearch
##enabled=1
##gpgcheck=1
##gpgkey=https://dl-ssl.google.com/linux/linux_signing_key.pub

##sudo yum install google-chrome-stable

sudo yum -y update
sudo yum check-update
sudo yum install code
code () { VSCODE_CWD="$PWD" cmd //c code $* ;}


systemctl get-default