# Parte 1: Gestión de Usuarios

1. **Creación de Usuarios:**
   ```bash
   sudo useradd usuario1
   sudo useradd usuario2
   sudo useradd usuario3

2. **Asignación de contraseñas:**
    ```bash
    sudo passwd usuario1
    sudo passwd usuario2
    sudo passwd usuario3

Salida:

New password: 
...

Retype new password:

passwd: password updated successfully

3.  **Información de Usuarios:**
    ```bash
    id usuario1
Salida:

uid=1001(usuario1) gid=1001(usuario1) groups=1001(usuario1)


4.  **Eliminación de Usuarios:**
    ```bash
    sudo userdel usuario3

# Parte 2: Gestión de Grupos

1. **Creación de grupos:**
    ```bash
    sudo groupadd grupo1
    sudo groupadd grupo2

2. **Agregar usuarios a grupo**
    ```bash
    sudo usermod -aG grupo1 usuario1
    sudo usermod -aG grupo2 usuario2

3. **Verificar membresía:**
    ```bash
    groups usuario1
    groups usuario2

Salida:

usuario1 : usuario1 grupo1

usuario2 : usuario2 grupo2

4. **Eliminar grupo**
    ```bash
    sudo groupdel grupo2

# Parte 3: Gestión de permisos

1. **Creación de archivos y directorios:**
    ```bash
    touch ~/archivo1.txt
    echo "Contenido del archivo 1" > ~/archivo1.txt
    mkdir ~/directorio1
    touch ~/directorio1/archivo2.txt

2. **Verificar permisos**
    ```bash
    ls -l ~/archivo1.txt
    ls -ld ~/directorio1

Salida: 
-rw-rw-r-- 1 ramon ramon 24 ago  9 19:18 /home/ramon/archivo1.txt

drwxrwxr-x 2 ramon ramon 4096 ago  9 19:19 /home/ramon/directorio1

3. **Modificar Permisos usando chmod con Modo Numérico**
    ```bash
    chmod 640 ~/archivo1.txt

4. **Modificar Permisos usando chmod con Modo simbólico**
    ```bash
    chmod u+x ~/directorio1/archivo2.txt

5. **Cambiar el grupo propietario**
    ```bash
    sudo chown :grupo1 ~/directorio1/archivo2.txt
6. **Configurar permisos de directorio**
    ```bash
    chmod 750 ~/directorio1

7. **Comprobación de acceso**
    ```bash
    cat ~/archivo1.txt
    cat ~/directorio1/archivo2.txt

Salida: 
cat: /home/usuario1/directorio1/archivo2.txt: Permiso denegado

8. **Verificación final**
    ```bash
    ls -l ~/archivo1.txt
    ls -ld ~/directorio1

Salida:

-rw-r----- 1 ramon ramon 24 ago  9 19:18 /home/ramon/archivo1.txt

drwxr-x--- 2 ramon ramon 4096 ago  9 19:19 /home/ramon/directorio1
