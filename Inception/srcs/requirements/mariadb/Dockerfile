FROM		debian:buster

RUN			apt update -y
RUN         apt upgrade -y
RUN         apt install vim -y
RUN         apt-get install mariadb-server -y

COPY        conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf

# Rendons ensuite visite au fichier de configuration de MySQL, appelé  50-server.cnf  et se trouvant dans  etc/mysql/mariadb.conf.d/50-server.cnf
