#!/bin/bash
GITHUB_ID_USER="RamonPCUSAC"

URL_GITHUB="https://api.github.com/users/$GITHUB_ID_USER"
JSON_RESPONSE=$(curl -s $URL_GITHUB)

github_user=$(echo $JSON_RESPONSE | jq -r '.login')
id=$(echo $JSON_RESPONSE | jq -r '.id')
created_at=$(echo $JSON_RESPONSE | jq -r '.created_at')

echo "Hola $github_user. User ID: $id. Cuenta fue creada el: $created_at."

fecha=$(date +"%Y%m%d")
log_dir="/tmp/$fecha"
log_file="$log_dir/saludos.log"

mkdir -p $log_dir

echo "Hola $github_user. User ID: $id. Cuenta fue creada el: $created_at." >> $log_file

(crontab -l ; echo "*/5 * * * * /home/ramon/Desktop/usac/so1_actividades_201216022/actividad2/script_github.sh") | crontab -
