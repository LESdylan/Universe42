norminette | awk '
/^[^ ]+\.[a-zA-Z0-9]+/ {file=$0; ok=0; next}
/: OK!$/ {ok=1; next}
NF && !ok {print file; print; ok=2}
!/: OK!$/ && ok==2 {print}
'
