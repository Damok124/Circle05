#!/bin/bash

cd /var/www/wordpress;

wp core download    --allow-root

wp config create	--allow-root \
                    --dbname=$DB \
                    --dbuser=$DB_USER \
                    --dbpass=$DB_PASSWORD \
                    --dbhost='mariadb'

wp core install     --allow-root \
                    --url='https://'$DOMAIN_NAME \
                    --title='Ziedest Wordpress Ever' \
                    --admin_user=$ADMIN_USER \
                    --admin_password=$ADMIN_PASSWORD \
                    --admin_email=$ADMIN_EMAIL \
                    --skip-email
            
wp user create      --allow-root "$USER_NAME" "$USER_NAME@$DOMAIN_NAME" --user_pass=$USER_PWD --role=subscriber

/usr/sbin/php-fpm7.3 -F -R