FROM		debian:buster

RUN			apt update -y
RUN         apt upgrade -y
RUN         apt install vim -y
RUN         apt-get install mariadb-server -y

COPY        conf/50-server.cnf  /etc/mysql/mariadb.conf.d/50-server.cnf
COPY        tools/script.sh     /tmp/script.sh

RUN         chmod +x /tmp/script.sh
ENTRYPOINT  ["/bin/bash", "/tmp/script.sh"]
