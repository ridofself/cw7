#!/bin/bash

# sudo ln -s /etc/apache2/mods-available/cgi.load /etc/apache2/mods-enabled 
# sudo mkdir /usr/lib/cgi-bin/cw_users
# sudo chmod -R www-data:www-data /usr/lib/cgi-bin/cw_users

sudo cp ./html/* /var/www/html
sudo cp ./cgi-bin/* /usr/lib/cgi-bin
