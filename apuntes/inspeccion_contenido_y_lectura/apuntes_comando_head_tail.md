# 📜 Comandos `head` y `tail` — Leer el inicio o el final de un archivo

## 🧠 Concepto
Los comandos **`head`** y **`tail`** sirven para **ver rápidamente el contenido de un archivo** sin necesidad de abrirlo entero.

- `head` → muestra las primeras líneas.  
- `tail` → muestra las últimas líneas.

Son especialmente útiles en la **piscina**, cuando necesitas comprobar archivos largos, logs o salidas generadas por tus programas.

---

## ⚙️ Sintaxis general

```bash
head [opciones] [archivo]
tail [opciones] [archivo]
```

---

## 📘 Ejemplos paso a paso

### 1️⃣ Ver las primeras líneas de un archivo
```bash
head archivo.txt
```
📄 Muestra las **primeras 10 líneas** (por defecto).

---

### 2️⃣ Ver las últimas líneas de un archivo
```bash
tail archivo.txt
```
📜 Muestra las **últimas 10 líneas**.

---

### 3️⃣ Especificar el número de líneas
```bash
head -n 5 archivo.txt
tail -n 3 archivo.txt
```
📏 Controlas exactamente cuántas líneas ver.

---

### 4️⃣ Ver bytes en lugar de líneas
```bash
head -c 20 archivo.txt
tail -c 50 archivo.txt
```
🔢 Muestra los primeros o últimos bytes del archivo.

---

### 5️⃣ Ver en tiempo real (solo `tail`)
```bash
tail -f log.txt
```
🕒 Muestra las últimas líneas y sigue actualizándose **en tiempo real**.  
Perfecto para monitorear logs o ver cómo tu programa escribe resultados.

Deténlo con `Ctrl + C`.

---

### 6️⃣ Usar con pipes (`|`)
```bash
cat archivo.txt | head -n 3
```
💡 Muestra las tres primeras líneas de la salida de `cat`.

También puedes ver el final de una salida:
```bash
ls -l | tail -n 5
```

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-n N` | Muestra N líneas |
| `-c N` | Muestra N bytes |
| `-v` | Muestra el nombre del archivo antes del contenido |
| `-f` | Sigue el archivo en tiempo real (solo `tail`) |

---

## ⚠️ Errores comunes

🚫 **“No such file or directory”**  
> El archivo no existe o la ruta es incorrecta.  
💡 Usa `ls` o `pwd` para verificar tu ubicación.

🚫 **Sin permisos de lectura**  
> No puedes leer el archivo.  
💡 Usa `ls -l` para ver los permisos o `sudo` si es necesario.

🚫 **Archivo vacío**  
> Si no ves nada, el archivo está vacío o las líneas que pides no existen.

---

## 🪄 Tips y buenas prácticas

- Usa `head` o `tail` con `grep` para filtrar parte del contenido:  
  ```bash
  grep "error" log.txt | tail -n 5
  ```
- Para revisar varios archivos a la vez:
  ```bash
  head -n 2 ex*/resultado.txt
  ```
- Cuando tu programa genera un log, usa:
  ```bash
  tail -f salida.log
  ```
  y verás la ejecución “en vivo”.

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Ver primeras líneas | `head archivo.txt` | Muestra 10 primeras líneas |
| Ver últimas líneas | `tail archivo.txt` | Muestra 10 últimas líneas |
| Especificar líneas | `head -n 5 archivo.txt` | Controla cuántas líneas ver |
| Ver bytes | `head -c 50 archivo.txt` | Muestra primeros bytes |
| Seguir archivo | `tail -f log.txt` | Lectura en tiempo real |
| Usar con pipe | `cat archivo | head` | Ver parte de una salida |

---

> 💬 *“head y tail son tus ojos rápidos: leen justo lo que necesitas, sin perder tiempo en lo que no importa.”* 👀
