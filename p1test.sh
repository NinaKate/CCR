#!/bin/bash
#This prints the number of pending jobs, the username, then the number of nodes for those pending jobs. 
cat queue1.txt | tr -s ' ' | grep PD |awk '{print $4,$7}'|sort -r|awk 'BEGIN {sum=0;j=0;id=""}{if($1 ==id){sum=sum+$2;j=j+1}else{if(id !=""){print j," ",id," ",sum};id = $1;sum=$2;j=0} }'|sort -n -r |head -1

#This is part 3, and I have a ton of people with 8-character usernames, so this is just the first one
cat queue1.txt |tr -s ' ' |cut -d ' ' -f 5,6|grep R |cut -d ' ' -f 1 |uniq| awk '{print length, $0}'|sort -n -r|uniq|head -1

#This is the number of nodes TOTAL being used by a single user, it prints the node count then the user for the top user
cat queue1.txt | tr -s ' ' |awk '{print $4,$7}'|sort -r|awk 'BEGIN {sum=0;id=""}{if($1 ==id){sum=sum+$2}else{if(id !=""){print sum," ",id};id = $1;sum=$2} }'|sort -n -r |head -1

#This is the other interpretation, namely who has the single job that needs the most nodes
cat queue1.txt | tr -s ' ' | grep PD |awk '{print $7,$4}'|sort -n -r | head -1

#and lo this is the last one, how many unique users have pending jobs because of priority
cat queue1.txt |tr -s ' ' | grep PD | grep Priority | cut -d ' ' -f 5 | sort | uniq| wc -l
