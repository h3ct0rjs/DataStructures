#!/bin/bash 
#hfjimenez@utp.edu.co 
#Purpouse: Delete all the accents, uppers to lowercase. 
#Recomendations: Please remove the guttember prolog
#usage ./converterbooks.sh book.txt filtered.txt
file="$1"
file2="$2"
cat $file |tr -d [[:punct:]]> $file2                                    #Avoid modification to the original book.
sed -i 'y/áÁàÀãÃâÂéÉêÊíÍóÓõÕôÔúÚñÑçÇ/aAaAaAaAeEeEiIoOoOoOuUnNcC/' $file2 #Delete the accent using Awk :)
tr '[A-Z]' '[a-z]' < $file2
