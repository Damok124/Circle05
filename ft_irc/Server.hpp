/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:50:31 by zharzi            #+#    #+#             */
/*   Updated: 2023/08/15 17:08:05 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef typename std::string str;

class Server
{
    private:
    public:
};

bool check_port(str text);
bool check_password(str text);
int get_port(str text);
str get_password(str text);