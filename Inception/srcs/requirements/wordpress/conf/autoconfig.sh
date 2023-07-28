sleep 10

# wp core download    --allow-root --path='/var/www/wordpress'

wp config create	--allow-root \
                    --dbname=$SQL_DATABASE \
                    --dbuser=$SQL_USER \
                    --dbpass=$SQL_PASSWORD \
                    --dbhost=mariadb:3306 --path='/var/www/wordpress'

wp core install --allow-root \
                --url='https://zharzi.42.fr.com' \
                --title='Simpliest Wordpress Ever' \
                --admin_user='admin' \
                --admin_password='password' \
                --admin_email='zharzi@student.42angouleme.fr' \
                --path='/var/www/wordpress'

wp user create --allow-root new_user new_user@zharzi.42.fr --role=subscriber --path='/var/www/wordpress'

/usr/sbin/php-fpm7.3 -F 