#!/bin/bash

#루프 짜자
#sudo groupadd docker
#sudo usermod -aG docker $USER
#newgrp docker
#docker run hello-world

yum -y update
yum -y install docker docker-registry

cat > /etc/yum.repos.d/docker.repo
if [ "$?" -eq "0" ]; then
echo -e "$green" ""
sudo yum-config-manager \ --add-repo \ https://download.docker.com/linux/centos/docker-ce.repo
else
echo -e "$red" ""
sudo yum install docker-ce docker-ce-cli containerd.io
sudo yum install -y yum-utils
sudo yum-config-manager \ --add-repo \ https://download.docker.com/linux/centos/docker-ce.repo
fi

wget http://dl.fedoraproject.org/pub/epel/epel-release-latest-7.noarch.rpm
if [ "$?" -eq "0" ]; then
echo -e "$green" ""
sudo yum install docker-ce docker-ce-cli containerd.io
else
echo -e "$red" ""
fi

#docker engine 작동하지 않는 경우 특정 버전을 확인하여 설치바람
#sudo yum install docker-ce-<VERSION_STRING> docker-ce-cli-<VERSION_STRING> containerd.io

sudo yum install docker-ce docker-ce-cli containerd.io
if [ "$?" -eq "0" ]; then
echo -e "$green" ""
sudo systemctl start docker

else
echo -e "$red" ""
yum erase docker-ce docker-ce-cli containerd.io
yum install docker-ce docker-ce-cli containerd.io
fi


sudo docker run hello-world



yum -y upgrade



#많이 발생하는 오류 

## 오류 – containerd.io-1.2.10-3.2.el7.x86_64

## 해결법 
#yum install -y https://download.docker.com/linux/centos/7/x86_64/stable/Packages/containerd.io-1.2.13-3.1.el7.x86_64.rpm
##sudo systemctl start docker && sudo docker run hello-world

#퍼미션 에러 발생시 
#WARNING: Error loading config file: /home/user/.docker/config.json - stat /home/user/.docker/config.json: permission denied
# sudo chown "$USER":"$USER" /home/"$USER"/.docker -R 
# sudo chmod g+rwx "$HOME/.docker" -R

#마지막 점검
sudo yum install -y yum-utils
systemctl enable docker.service
systemctl start docker.service
systemctl status docker.service
docker pull centos
rpm -ivh epel-release-latest-7.noarch.rpm
yum install docker-ce
service docker start
docker -v 
