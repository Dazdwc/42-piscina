# 📂 Comando `ls` — Listar archivos y directorios

## 🧠 Concepto
El comando **`ls`** (*list*) muestra el contenido de un directorio.  
Es uno de los comandos más usados en Unix, ya que te permite **ver archivos, permisos, tamaños y fechas de modificación**.

En la Piscina, lo usarás constantemente para verificar tus entregas y comprobar permisos, enlaces o estructura de carpetas.

---

## ⚙️ Sintaxis general

```bash
ls [opciones] [ruta]
```

Si no se indica una ruta, muestra el contenido del **directorio actual**.

---

## 📘 Ejemplos paso a paso

### 1️⃣ Mostrar el contenido del directorio actual
```bash
ls
```
📋 Lista los archivos y carpetas del directorio donde te encuentras.

---

### 2️⃣ Mostrar archivos ocultos
```bash
ls -a
```
👀 Muestra todos los archivos, incluyendo los ocultos (los que empiezan con `.` como `.gitignore` o `.bashrc`).

---

### 3️⃣ Mostrar detalles (modo largo)
```bash
ls -l
```
📄 Muestra permisos, propietario, grupo, tamaño y fecha.

Ejemplo:
```
-rw-r--r-- 1 dani staff 1024 Oct 25 10:00 archivo.txt
drwxr-xr-x 2 dani staff 4096 Oct 25 09:59 carpeta
```
📖 Significado de cada columna:

| Campo | Ejemplo | Significado |
|--------|----------|-------------|
| Tipo y permisos | `-rw-r--r--` | Archivo normal, lectura/escritura para el usuario |
| Enlaces | `1` | Número de enlaces duros |
| Propietario | `dani` | Usuario dueño del archivo |
| Grupo | `staff` | Grupo asociado |
| Tamaño | `1024` | Bytes |
| Fecha | `Oct 25 10:00` | Última modificación |
| Nombre | `archivo.txt` | Nombre del archivo |

---

### 4️⃣ Mostrar en formato legible (K, M, G)
```bash
ls -lh
```
📏 Muestra los tamaños en formato legible (ejemplo: `4.0K`, `1.2M`).

---

### 5️⃣ Mostrar por orden de fecha
```bash
ls -lt
```
🕓 Muestra primero los archivos **más recientes**.

---

### 6️⃣ Mostrar carpetas y subcarpetas recursivamente
```bash
ls -R
```
📁 Muestra todo el contenido del directorio actual **y de las subcarpetas**.

---

### 7️⃣ Combinar opciones
```bash
ls -la
```
📦 Lista todos los archivos (incluidos los ocultos) con detalles.  
💡 Muy útil para depurar permisos y estructuras de entrega.

---

### 8️⃣ Mostrar solo directorios
```bash
ls -d */
```
📂 Filtra para mostrar únicamente las carpetas.

---

### 9️⃣ Ordenar por tamaño
```bash
ls -lS
```
⚖️ Muestra los archivos ordenados de mayor a menor tamaño.

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-a` | Muestra todos los archivos, incluidos los ocultos |
| `-l` | Muestra la lista en formato detallado |
| `-h` | Tamaños legibles (K, M, G) |
| `-t` | Ordena por fecha de modificación |
| `-S` | Ordena por tamaño |
| `-r` | Invierte el orden del listado |
| `-R` | Muestra contenido de subcarpetas |
| `-d */` | Muestra solo directorios |

---

## ⚠️ Errores comunes

🚫 **“No such file or directory”**  
> El directorio o archivo no existe.  
💡 Usa `pwd` para confirmar tu ruta actual.

🚫 **“Permission denied”**  
> No tienes permisos para acceder a esa carpeta.  
💡 Usa `sudo` o revisa permisos con `ls -ld carpeta`.

🚫 **Sin color o formato confuso**  
> Tu entorno puede tener colores desactivados.  
💡 Usa `ls --color=auto` para forzarlo.

---

## 🪄 Tips y buenas prácticas

- Usa `ls -lh` casi siempre: es el formato más legible.  
- Para ver permisos en subcarpetas, `ls -lR` es tu amigo.  
- Puedes combinarlo con otros comandos:
  ```bash
  ls -l | grep ".sh"
  ```
  🔍 Filtra solo los scripts.
- Para ver solo nombres ordenados por fecha:
  ```bash
  ls -1t
  ```
  (El `-1` fuerza una línea por archivo.)

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Ver archivos | `ls` | Lista el contenido actual |
| Ver ocultos | `ls -a` | Muestra todos los archivos |
| Ver detalles | `ls -l` | Incluye permisos, tamaños y fechas |
| Tamaño legible | `ls -lh` | Muestra en K, M, G |
| Ordenar por fecha | `ls -lt` | Más recientes primero |
| Mostrar recursivamente | `ls -R` | Incluye subcarpetas |
| Solo directorios | `ls -d */` | Filtra solo carpetas |

---

> 💬 *“ls es como encender la luz del directorio: muestra todo lo que hay, y cómo se comporta.”* 💡  
> Aprende a leer su salida y dominarás el sistema de archivos Unix.
