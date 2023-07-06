FROM		debian:buster

RUN			apt update \
RUN         apt upgrade -y \
RUN         apt install nginx -y \
RUN         apt install vim -y \
RUN         apt install curl -y \
# 	openssl			\
# 	sudo

# RUN			rm -f /etc/nginx/nginx.conf

# COPY		./config/nginx.conf /etc/nginx/nginx.conf
# COPY		scripts/setup_nginx.sh /setup_nginx.sh

# RUN			chmod -R +x /setup_nginx.sh

# EXPOSE		443

# ENTRYPOINT	["sh", "setup_nginx.sh"]
