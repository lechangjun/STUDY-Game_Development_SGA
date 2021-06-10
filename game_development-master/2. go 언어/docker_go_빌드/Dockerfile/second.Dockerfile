FROM golang
LABEL maintainer=tkddlf59@gmail.com
COPY server /usr/bin/server
# 수정된 부분
CMD ["server"]