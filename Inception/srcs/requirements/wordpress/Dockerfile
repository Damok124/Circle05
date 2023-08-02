FROM debian:buster

RUN apt-get update -y
RUN apt-get upgrade -y

RUN apt-get install wget -y

RUN apt-get install php7.3 -y
RUN apt-get install php-fpm -y
RUN apt-get install php-mysqli -y
RUN apt-get install mariadb-client -y
RUN apt-get install vim -y

EXPOSE 9000
# RUN wget https://fr.wordpress.org/wordpress-6.2.2-fr_FR.tar.gz -P /var/www
# RUN cd /var/www && tar -xzf wordpress-6.2.2-fr_FR.tar.gz && rm wordpress-6.2.2-fr_FR.tar.gz

#RUN	chown -R root:root /var/www/wordpress

COPY /conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar 
RUN mv wp-cli.phar /usr/local/bin/wp && wp cli update

COPY /conf/autoconfig.sh .
RUN chmod 777 autoconfig.sh
RUN mkdir -p /run/php
RUN mkdir -p /var/www/wordpress

ENTRYPOINT ["./autoconfig.sh"]