mkdir /home/ec2-user/lcj/ansible_install
mkdir /home/ec2-user/lcj/gcc_install
mkdir /home/ec2-user/lcj/packer_install
mkdir /home/ec2-user/lcj/git_install
mkdir /home/ec2-user/lcj/python_install
mkdir /home/ec2-user/lcj/boto3_install
mkdir /home/ec2-user/lcj/aws_cli_install

dnf install tree 

yum update

yum upgrade


현재 인스톨된 프로그램 중에 업데이트 된 것을 체크해줍니다.
yum check-update


-> yum 패키지에 대한 의존성 테스트
yum deplist

yum grouplist

yum list
