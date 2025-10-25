# 🐈 Comando `cat` — Concatenate & Display Files

El comando **`cat`** (de *concatenate*) se utiliza para **mostrar, crear o combinar archivos** en la terminal.  
Es uno de los comandos más usados en Bash por su simplicidad y versatilidad.

---

## 🧠 Concepto general

`cat` lee el contenido de un archivo y **lo imprime por pantalla (stdout)**.  
También puede **combinar varios archivos** o **redirigir la salida a uno nuevo**.

---

## 🧩 Sintaxis básica

```bash
cat [opciones] [archivo(s)]
```

---

## 📘 Ejemplos esenciales

### 1️⃣ Mostrar el contenido de un archivo
```bash
cat archivo.txt
```
📤 Muestra en pantalla el contenido completo del archivo.

---

### 2️⃣ Crear un archivo nuevo desde la terminal
```bash
cat > nuevo.txt
```
Ahora puedes escribir directamente lo que quieras dentro.  
Cuando termines, pulsa **Ctrl + D** para guardar y salir.

🧩 Ejemplo:
```bash
cat > saludo.txt
Hola Mundo
Ctrl + D
```
Luego puedes comprobarlo:
```bash
cat saludo.txt
Hola Mundo
```

---

### 3️⃣ Añadir contenido al final de un archivo existente
```bash
cat >> archivo.txt
```
Todo lo que escribas se agregará al final del archivo (sin borrar lo anterior).  
Finaliza con **Ctrl + D**.

---

### 4️⃣ Mostrar varios archivos seguidos
```bash
cat archivo1.txt archivo2.txt
```
`cat` mostrará uno detrás del otro, en el orden indicado.

---

### 5️⃣ Combinar varios archivos en uno nuevo
```bash
cat parte1.txt parte2.txt > completo.txt
```
👉 Crea `completo.txt` con el contenido de ambos.

---

### 6️⃣ Mostrar contenido con numeración de líneas
```bash
cat -n archivo.txt
```
📋 Muestra las líneas numeradas, útil para depuración.

---

### 7️⃣ Mostrar contenido con saltos de línea visibles
```bash
cat -e archivo.txt
```
🔍 Añade un símbolo `$` al final de cada línea, mostrando los saltos explícitamente.

---

## ⚙️ Opciones más comunes

| Opción | Descripción |
|--------|--------------|
| `-n` | Numera todas las líneas de salida |
| `-b` | Numera solo las líneas que no están vacías |
| `-E` o `-e` | Muestra los saltos de línea con `$` |
| `-s` | Suprime líneas vacías repetidas |
| `>` | Redirige la salida (sobrescribe archivo) |
| `>>` | Redirige la salida (añade al final del archivo) |

---

## ⚠️ Errores comunes

🚫 **Error: “No such file or directory”**  
> El archivo no existe o estás en otro directorio.

💡 Solución:  
Verifica con `ls` que el archivo esté en la misma ruta o usa la ruta completa.

---

## 🎯 En resumen

| Acción | Comando | Resultado |
|--------|----------|-----------|
| Ver contenido | `cat file.txt` | Muestra el archivo |
| Crear nuevo | `cat > file.txt` | Crea archivo nuevo |
| Añadir texto | `cat >> file.txt` | Agrega al final |
| Combinar | `cat a.txt b.txt > c.txt` | Fusiona en un nuevo archivo |
| Numerar líneas | `cat -n file.txt` | Muestra numeración |

---

> 🧩 **`cat`** es una herramienta fundamental en Bash: simple, directa y muy útil para visualizar o generar archivos rápidamente.  
> En los primeros ejercicios de la Piscina, te servirá sobre todo para **comprobar que los archivos contienen lo que deberían.** 🏊‍♂️
