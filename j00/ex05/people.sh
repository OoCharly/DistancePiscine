ldapsearch -Q uid="z*" cn|grep cn:|sed 's/cn: //'|sort -f -r
