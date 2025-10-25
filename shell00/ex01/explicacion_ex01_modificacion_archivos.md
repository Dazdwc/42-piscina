# 🧩 Ex01 - Creación, modificación y compresión de archivos en Bash

En este ejercicio aprenderemos varios conceptos fundamentales de **bash**:  
cómo crear, modificar, comprimir y preparar un archivo según las especificaciones del enunciado.  

Para ello, nos serviremos de varios comandos esenciales 👇  

> 🪶 **`touch`** → crea archivos vacíos o cambia su fecha de modificación.  
> ⚖️ **`truncate`** → ajusta el tamaño (peso) de un archivo.  
> 📦 **`tar`** → comprime archivos sin perder formato.  
> 🔐 **`chmod`** → cambia los derechos (permisos) del archivo.  
> 📂 **`ls`** → lista los archivos del directorio.  
> 🧹 **`rm`** → elimina los archivos que no deben entregarse.  

---

## 🚀 Pasos a seguir

### 1️⃣ Crear el archivo `testShell00`
```bash
  touch testShell00
```
🆕 Crea un archivo vacío con ese nombre.

---

### 2️⃣ Cambiar el peso del archivo a 40 bytes
```bash
  truncate -s 40 testShell00
```
⚙️ Modifica el tamaño del archivo a exactamente **40 bytes**.

---

### 3️⃣ Cambiar la fecha de modificación
Si lo hiciéramos antes, `truncate` volvería a modificarla, así que lo hacemos ahora:
```bash
  touch -t 202506012342 testShell00
```
📅 Establece la fecha y hora del archivo:  
> Año **2025**, mes **06**, día **01**, hora **23:42**.

---

### 4️⃣ Cambiar los permisos del archivo
```bash
  chmod u=r,g=rx,o=rx testShell00
```
🔐 Define los permisos:  
- 👤 Usuario: lectura (`r`)  
- 👥 Grupo: lectura y ejecución (`r`, `x`)  
- 🌍 Otros: lectura y ejecución (`r`, `x`)

📘 *Recuerda: en `chmod` los permisos se separan con comas, no con espacios.*  

---

### 5️⃣ Comprimir el archivo en formato `.tar`
```bash
  tar -cf testShell00.tar testShell00
```
📦 Crea un archivo comprimido llamado `testShell00.tar` que contiene `testShell00`.

💡 El parámetro `-c` crea un nuevo archivo y `-f` indica el nombre del `.tar` resultante.

---

### 6️⃣ Borrar el archivo original  
Una vez comprimido, eliminamos el archivo suelto para dejar el directorio limpio:
```bash
  rm testShell00
```
🧹 Solo debe quedar el archivo `testShell00.tar` en tu carpeta `ex01`.

---

## ✅ Resultado final
Si haces:
```bash
  ls -l
```
Deberías ver algo así:
```
-rw-r--r-- 1 tu_usuario tu_grupo 10240 Oct 26 12:34 testShell00.tar
```

---

> 💬 *Consejo:* revisa el contenido de tu `.tar` con `tar -tf testShell00.tar` antes de subirlo a la Intra. Así te aseguras de que todo está correcto. 🧠  
