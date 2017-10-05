#!/bin/bash
cat queue.txt | tr -s ' ' | grep PD |awk '{print $4,$7}'|sort -r|awk 'BEGIN {sum=0;j=0;id=""}{if($1 ==id){sum=sum+$2;j=j+1}else{if(id !=""){print j," ",id," ",sum};id = $1;sum=$2;j=0} }'|sort -n -r |head -1

#cat queue.txt |tr -s ' ' |grep PD |cut -d ' ' -f 5 | sort|uniq -c|sort -n -r|head -1

cat queue.txt |tr -s ' ' |cut -d ' ' -f 5,6|grep R |cut -d ' ' -f 1 |uniq| awk '{print length, $0}'|sort -n -r|uniq|head -1

cat queue.txt | tr -s ' ' |awk '{print $4,$7}'|sort -r|awk 'BEGIN {sum=0;id=""}{if($1 ==id){sum=sum+$2}else{if(id !=""){print sum," ",id};id = $1;sum=$2} }'|sort -n -r |head -1

cat queue.txt | tr -s ' ' | grep PD |awk '{print $7,$4}'|sort -n -r | head -1

cat queue.txt |tr -s ' ' | grep PD | grep Priority | cut -d ' ' -f 5 | sort | uniq| wc -l
