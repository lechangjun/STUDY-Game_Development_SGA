#!/bin/bash
cyan='\033[0;36m'
green='\033[0;32m'
lightgreen='\e[0;32m'
white='\e[0;37m'
red='\e[0;31m'
yellow='\033[0;33m'
blue='\033[0;34m'
orange='\e[38;5;166m'
## wget install
sudo yum -y install wget
######ansible_install_check
cd /etc/ansible
if [ "$?" -eq "0" ]; then
echo -e "$green" "[ ✔ ] Ensable installation completed ......................[ found ]"
sleep 1
else
echo -e "$red" "[ X ] NO ansible -> not found"
echo "ansible-installin>>>>>>>> "
cd /home/ec2-user/lcj/ansible_install
./install.sh
fi
######gcc-make_install_check
gcc -v
if [ "$?" -eq "0" ]; then
echo -e "$green" "[ ✔ ] Ensable installation completed ......................[ found ]"
sleep 1
else
echo -e "$red" "[ X ] NO gcc - make -> not found"
echo " gcc - make >>>>>>>> "
cd /home/ec2-user/lcj/gcc_install
./install.sh
fi
echo -e "$orange" "+-------------------------------------------------+"
echo -e "$orange" "|$white [$green Confirm$white ]$yellow ansible check complete $orange |"
echo -e "$orange" "|$white [$green Confirm$white ]$yellow gccmake check complete $orange |"
echo -e "$orange" "+-------------------------------------------------+"
clear
echo -e "$yellow" ">>>>packer_install_check>>>>"
sudo yum install -y yum-utils
sudo yum-config-manager --add-repo https://rpm.releases.hashicorp.com/RHEL/hashicorp.repo
sudo yum -y install packer
echo ">>>>packer_install_check>>>"
packer --version
if [ "$?" -eq "0" ]; then
echo -e "$green" "[ ✔ ] Ensable installation completed ......................[ found ]"
sleep 1
else
echo -e "$red" "[ X ] NO ansible -> not found"
echo "ansible-installin>>>>>>>> "
d /home/ec2-user/lcj/packer_install
./install.sh
fi
echo -e "$orange" "+-------------------------------------------------+"
echo -e "$orange" "|$white [$green Confirm$white ]$yellow packer check complete $orange |"
echo -e "$orange" "+-------------------------------------------------+"
clear
echo -e "$yellow" ">>>>tree_install_check>>>>"
yum install tree
git --version
if [ "$?" -eq "0" ]; then
echo -e "$green" "[ ✔ ] Ensable installation completed ......................[ found ]"
sleep 1
else
echo -e "$red" "[ X ] NO git && git hub -> not found"
echo " gcc - make >>>>>>>> "
cd /home/ec2-user/lcj/git_install
./install.sh
fi
echo -e "$orange" "+-------------------------------------------------+"
echo -e "$orange" "|$white [$green 1$white ]$yellow tree rescue check complete $orange |"
Type :qa! and press <Enter> to abandon all changes and exit Vim
echo -e "$orange" "+-------------------------------------------------+"
echo -e "$orange" "|$white [$green 1$white ]$yellow tree rescue check complete $orange |"
echo -e "$orange" "|$white [$green 2$white ]$yellow git hub git check complete$orange |"
echo -e "$orange" "|$white [$green 3$white ]$yellow General environment check complete$orange |"
echo -e "$orange" "+-------------------------------------------------+"
clear
##python_install
cd /home/ec2-user/lcj/python_install
./install.sh
##boto3_install
cd /home/ec2-user/lcj/boto3_install
./install.sh
## aws cli
cd /home/ec2-user/lcj/aws_cli_install
./install.sh
echo -e "$orange" "+-------------------------------------------------+"
echo -e "$orange" "|$white [$green 1$white ]$yellow Full upload complete $orange |"
echo -e "$orange" "+-------------------------------------------------+"
cd
clear
echo -e "$orange" "+-------------------------------------------------+"
echo -e "$orange" "+-------------------------------------------------+"
echo -e "$orange" "|$white [$green 1$white ]$yellow ansible check complete $orange |"
echo -e "$orange" "|$white [$green 2$white ]$yellow aws cli check complete$orange |"
echo -e "$orange" "|$white [$green 3$white ]$yellow aws boto3 check complete$orange |"
echo -e "$orange" "|$white [$green 4$white ]$yellow packer check complete$orange |"
echo -e "$orange" "|$white [$green 5$white ]$yellow in normal operation $orange |"
echo -e "$orange" "+-------------------------------------------------+"
aws ec2 describe-instances
clear
cd
cd project/
cd packer/
clear
packer build aws_ec2_build.json
