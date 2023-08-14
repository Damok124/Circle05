FROM        debian:buster

ARG         NAME
ARG         USER
ARG         PASSWORD

RUN         apt-get update -y && apt-get upgrade -y

RUN         apt-get install -y mariadb-server

RUN         service mysql start && \
            mysql -e "CREATE DATABASE IF NOT EXISTS \`${NAME}\`;" && \
            mysql -e "CREATE USER IF NOT EXISTS \`${USER}\`@'%' IDENTIFIED BY '${PASSWORD}';" && \
            mysql -e "GRANT ALL PRIVILEGES ON \`${NAME}\`.* TO \`${USER}\`@'%' IDENTIFIED BY '${PASSWORD}';" && \
            mysql -e "FLUSH PRIVILEGES;"
            
ENTRYPOINT  [ "mysqld", "--bind-address=0.0.0.0" ]