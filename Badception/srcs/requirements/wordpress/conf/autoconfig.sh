#!/bin/bash
#sleep 10
cd /var/www/wordpress;
wp core download    --allow-root

wp config create	--allow-root \
                    --dbname=$SQL_DATABASE \
                    --dbuser=$SQL_USER \
                    --dbpass=$SQL_PASSWORD \
                    --dbhost='mariadb' \

wp core install --allow-root \
                --url='https://zharzi.42.fr' \
                --title='Simpliest Wordpress Ever' \
                --admin_user='admin' \
                --admin_password='password' \
                --admin_email='zharzi@student.42angouleme.fr' \
            

wp user create --allow-root new_user new_user@zharzi.42.fr --role=subscriber

/usr/sbin/php-fpm7.3 -F -R