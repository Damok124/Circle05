FROM debian:buster

RUN apt-get update -y \
    && apt-get upgrade -y \
    && apt-get install wget -y \
    && apt-get install php7.3 -y \
    && apt-get install php-fpm -y \
    && apt-get install php-mysqli -y \
    && apt-get install mariadb-client -y

COPY /conf/www.conf /etc/php/7.3/fpm/pool.d/

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

RUN chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp \
    && wp cli update

COPY /tools/autoconfig.sh .

RUN chmod 755 autoconfig.sh \
    && mkdir -p /run/php \
    && mkdir -p /var/www/wordpress

ENTRYPOINT ["./autoconfig.sh"]
