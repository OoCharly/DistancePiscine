cat /etc/passwd | grep -v ^# | sed '2n;N;s/.*\n//g' | tail -r |rev|head -n $FT_LINE2|tail -n +$FT_LINE1| cut -d ":" -f7|awk '{printf("%s,",$1);}'|sed 's/,$/./'|tr -d '\n'
