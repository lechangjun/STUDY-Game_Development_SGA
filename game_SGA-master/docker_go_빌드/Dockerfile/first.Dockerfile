FROM golang
LABEL maintainer=tkddlf59@gmail.com
COPY server /usr/bin/server
CMD "server"