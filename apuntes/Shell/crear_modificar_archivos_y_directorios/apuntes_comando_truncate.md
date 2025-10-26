# ✂️ Comando `truncate` — Ajustar el tamaño de un archivo

## 🧠 Concepto
El comando **`truncate`** se usa para **cambiar el tamaño de un archivo** sin necesidad de abrirlo.  
Puedes **reducirlo (borrando contenido)** o **ampliarlo (rellenando con bytes vacíos)**.  
Es ideal para crear archivos de un tamaño exacto o vaciar su contenido rápidamente.

En la Piscina, puede ayudarte a preparar archivos de prueba o limpiar su contenido sin borrarlos.

---

## ⚙️ Sintaxis general

```bash
truncate [opciones] -s tamaño archivo
```

- `-s`: define el tamaño nuevo del archivo.
- El tamaño puede expresarse en **bytes**, **kilobytes (K)**, **megabytes (M)** o **gigabytes (G)**.

---

## 📘 Ejemplos paso a paso

### 1️⃣ Vaciar un archivo sin borrarlo
```bash
truncate -s 0 archivo.txt
```
🗑️ El archivo se queda con **0 bytes**, es decir, vacío.

💡 Muy útil cuando no quieres borrar el archivo, solo su contenido.

---

### 2️⃣ Reducir un archivo a un tamaño concreto
```bash
truncate -s 100 archivo.txt
```
✂️ Corta el archivo a **100 bytes**.  
Si era más grande, se elimina el contenido sobrante.

---

### 3️⃣ Ampliar un archivo
```bash
truncate -s 1K archivo.txt
```
📦 Aumenta su tamaño a **1 kilobyte (1024 bytes)**, rellenando con espacios vacíos (`\0`).

---

### 4️⃣ Crear un archivo nuevo de un tamaño fijo
```bash
truncate -s 5M test.bin
```
📂 Crea un archivo de **5 megabytes** de tamaño exacto, incluso si no existía antes.

---

### 5️⃣ Verificar el tamaño del archivo
```bash
ls -lh archivo.txt
```
📏 Muestra el tamaño en formato legible (K, M, G…).

---

## ⚙️ Unidades de tamaño

| Unidad | Ejemplo | Tamaño aproximado |
|--------|----------|------------------|
| `B` | `-s 512B` | 512 bytes |
| `K` | `-s 1K` | 1 kilobyte (1024 bytes) |
| `M` | `-s 10M` | 10 megabytes |
| `G` | `-s 1G` | 1 gigabyte |

---

## ⚠️ Errores comunes

🚫 **“Invalid size argument”**  
> El tamaño no tiene formato válido.  
💡 Usa un número seguido de una unidad (`100K`, `1M`, `0`).

🚫 **“No such file or directory”**  
> El archivo o carpeta no existe.  
💡 Crea el archivo antes con `touch` o indica la ruta correcta.

🚫 **“Permission denied”**  
> No tienes permisos para modificar el archivo.  
💡 Usa `ls -l` para revisar los permisos o ejecuta con `sudo` si es necesario.

---

## 🪄 Tips y buenas prácticas

- Para vaciar rápidamente un archivo de logs:
  ```bash
  truncate -s 0 log.txt
  ```
- Para crear archivos de prueba de gran tamaño:
  ```bash
  truncate -s 100M test_file.bin
  ```
- Puedes combinarlo con `ls -lh` para comprobar el tamaño inmediatamente:
  ```bash
  truncate -s 2K file && ls -lh file
  ```
- Es más rápido y limpio que usar `echo > archivo` o `cat /dev/null > archivo`.

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Vaciar un archivo | `truncate -s 0 archivo.txt` | Borra contenido sin eliminar el archivo |
| Reducir tamaño | `truncate -s 100 archivo.txt` | Corta a 100 bytes |
| Ampliar tamaño | `truncate -s 1K archivo.txt` | Rellena hasta 1KB |
| Crear archivo de tamaño fijo | `truncate -s 10M test.bin` | Archivo de 10MB lleno de ceros |
| Comprobar tamaño | `ls -lh archivo.txt` | Muestra el tamaño actual |

---

> 💬 *“Truncate no borra tus archivos… solo los hace adelgazar o engordar según tus órdenes.”* ⚖️  
> Es una herramienta precisa para manipular el tamaño sin tocar el contenido restante.
