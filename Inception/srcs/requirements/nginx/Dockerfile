FROM		debian:buster

RUN			apt update
RUN         apt upgrade -y
RUN         apt install nginx -y
RUN         apt install vim -y
RUN         apt install curl -y
RUN         mkdir -p /etc/nginx/ssl
RUN         apt install openssl -y
RUN         openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=Nouvelle-Aquitaine/L=Angouleme/O=42/OU=42Angouleme/CN=zharzi.42.fr/UID=zharzi"
RUN         mkdir -p /var/run/nginx

# 	sudo

RUN			rm -f /etc/nginx/nginx.conf

COPY		./conf/nginx.conf /etc/nginx/nginx.conf
# COPY		scripts/setup_nginx.sh /setup_nginx.sh

# RUN			chmod -R +x /setup_nginx.sh

# EXPOSE		443

# ENTRYPOINT	["sh", "setup_nginx.sh"]
