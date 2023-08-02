# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 22:22:05 by zharzi            #+#    #+#              #
#    Updated: 2023/06/29 14:28:31 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	mkdir /home/zharzi/data/mariadb -p
	mkdir /home/zharzi/data/wordpress -p
	docker compose -f ./srcs/docker-compose.yml up -d --build

clean :
	docker compose -f ./srcs/docker-compose.yml down

cleandata :
	docker compose -f ./srcs/docker-compose.yml down -v
	sudo rm -rf /home/zharzi/data/mariadb
	sudo rm -rf /home/zharzi/data/wordpress

fclean : cleandata
	docker system prune -af

logs :	
	docker compose  -f ./srcs/docker-compose.yml logs

ref : fclean all

red : cleandata all

re : clean all

.PHONY : all clean cleandata fclean re
