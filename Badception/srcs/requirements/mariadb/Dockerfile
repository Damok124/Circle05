# FROM		debian:buster

# RUN			apt update -y
# RUN         apt upgrade -y
# RUN         apt install vim -y
# RUN         apt-get install mariadb-server -y

# COPY        conf/50-server.cnf  /etc/mysql/mariadb.conf.d/50-server.cnf
# COPY        tools/script.sh     /tmp/script.sh

# RUN         chmod +x /tmp/script.sh
# ENTRYPOINT  ["/bin/bash", "/tmp/script.sh"]


FROM debian:buster
ARG NAME
ARG USER
ARG PASSWORD

EXPOSE 3306

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y mariadb-server

RUN service mysql start && mysql -e "CREATE DATABASE IF NOT EXISTS \`${NAME}\`;" \
&& mysql -e "CREATE USER IF NOT EXISTS \`${USER}\`@'%' IDENTIFIED BY '${PASSWORD}';" \
&& mysql -e "GRANT ALL PRIVILEGES ON \`${NAME}\`.* TO \`${USER}\`@'%' IDENTIFIED BY '${PASSWORD}';" \
&& mysql -e "FLUSH PRIVILEGES;"
ENTRYPOINT [ "mysqld", "--bind-address=0.0.0.0" ]