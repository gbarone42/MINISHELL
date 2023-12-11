# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    create_type_list.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 13:12:34 by fcorri            #+#    #+#              #
#    Updated: 2023/08/21 17:29:53 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

#dir=$1_lists
#if [ -d $dir ]; then
#	echo "Lista già creata"
#	exit 1
#fi
#header=../../../build/inc/libft/libft.h
#makefile=../../../Makefile
#clear
#
## COPY, SUBSTITUE, PASTE IN LIBFT.H
#awk -v replacement="$1" '{
#	if (96 <= NR && NR <= 113) {
#		print ;
#		gsub("BONUS", toupper(replacement) "_LISTS") ;
#		gsub("list", replacement "_list") ;
#		gsub("ft_lst", "ft_" replacement "_lst") ;
#		gsub("void \*", replacement " ") ;
#		gsub("void\t\t\t\*", replacement "\t\t\t\t") ;
#		lines_to_add = lines_to_add "\n" $0 ;
#	} else if (NR == 114) {
#		lines_to_add = lines_to_add "\n" $0 ;
#		print lines_to_add ;
#	} else
#		print ;
#}' $header > tmp.h
#c_formatter_42 < tmp.h > tmp2.h
#rm tmp.h
#mv tmp2.h $header
#
## COPY, SUBSTITUE, PASTE IN MAKEFILE
#awk -v replacement="$1" -v dir="$dir" '{
#	if (NR == 71) {
#		print ;
#		gsub("BONUS_SRCS", toupper(replacement) "_LISTS_SRCS") ;
#		gsub("\t\t", "\t") ;
#		gsub("ft_lst", dir "/ft_" replacement "_lst") ;
#		lines_to_add = lines_to_add "\n" $0 ;
#	} else if (72 <= NR && NR <= 79) {
#		print ;
#		gsub("ft_lst", dir "/ft_" replacement "_lst") ;
#		lines_to_add = lines_to_add "\n" $0 ;
#	} else if (NR == 80) {
#		lines_to_add = lines_to_add "\n" $0 ;
#		print lines_to_add ;
#	} else if (NR == 96) {
#		print ;
#		gsub("BONUS_SRCS", toupper(replacement) "_LISTS_SRCS") ;
#		print ;
#	} else
#		print ;
#}' $makefile > tmp
#mv tmp $makefile
#
#
#mkdir -p $dir
#for file in *.c
#do
#	new=ft_$1_${file:3}
#	awk -v replacement="$1" '{
#		gsub("t_list", "t_" replacement "_list") ;
#		gsub("void \*", replacement " ") ;
#		gsub("ft_lst", "ft_" replacement "_lst") ;
#		print ;
#	}' $file > $dir/$new
#done
