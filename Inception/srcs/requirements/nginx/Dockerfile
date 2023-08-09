FROM		debian:buster

RUN         apt-get update -y && apt-get upgrade -y
RUN         apt install nginx -y

RUN         mkdir -p /etc/nginx/ssl
RUN         apt install openssl -y

RUN         openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=Nouvelle-Aquitaine/L=Angouleme/O=42/OU=42Angouleme/CN=${DOMAIN}/UID=zharzi"

RUN         mkdir -p /var/run/nginx

RUN			rm -f /etc/nginx/nginx.conf
COPY		./conf/nginx.conf /etc/nginx

RUN         chmod 755 /var/www/html
RUN         chown -R www-data:www-data /var/www/html

CMD         [ "nginx", "-g", "daemon off;" ]