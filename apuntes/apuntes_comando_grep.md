# 🔍 Comando `grep` — Buscar texto dentro de archivos

## 🧠 Concepto
El comando **`grep`** (de *Global Regular Expression Print*) se usa para **buscar texto dentro de archivos o salidas de comandos**.  
Es una de las herramientas más poderosas de la terminal: te permite filtrar información, encontrar patrones y analizar resultados de forma rápida.

En la Piscina, `grep` te servirá para buscar nombres, comprobar resultados o validar tus archivos antes de entregarlos.

---

## ⚙️ Sintaxis general

```bash
grep [opciones] "texto_a_buscar" [archivo]
```

---

## 📘 Ejemplos paso a paso

### 1️⃣ Buscar una palabra en un archivo
```bash
grep "hola" texto.txt
```
🔎 Muestra las líneas de `texto.txt` que contienen la palabra **hola**.

💡 Si la palabra no aparece, no mostrará nada.

---

### 2️⃣ Ignorar mayúsculas/minúsculas
```bash
grep -i "hola" texto.txt
```
🔤 `-i` hace que la búsqueda **no distinga entre mayúsculas y minúsculas**.

Ejemplo: coincidirá con *Hola*, *HOLA* o *hola*.

---

### 3️⃣ Mostrar número de línea donde aparece el texto
```bash
grep -n "z" ./ex00/z
```
📋 Añade el número de línea al resultado.  
Útil para localizar fácilmente dónde aparece algo dentro de un archivo.

---

### 4️⃣ Buscar en varios archivos a la vez
```bash
grep "42" ./ex*/z
```
🔍 Busca la cadena “42” en todos los archivos `z` de tus ejercicios.  
Muestra el nombre del archivo y la línea donde lo encuentra.

---

### 5️⃣ Mostrar solo el nombre de los archivos que contienen coincidencias
```bash
grep -l "main" *.c
```
📂 Lista solo los archivos que **contienen** la palabra “main”, sin mostrar las líneas.

---

### 6️⃣ Buscar en el resultado de otro comando (pipe)
```bash
ls -l | grep ".sh"
```
🧩 Filtra los resultados del `ls`, mostrando solo las líneas que contienen `.sh`.

💡 Esto es lo que hace `grep` tan útil: puede trabajar **sin necesidad de archivos**, leyendo directamente de otros comandos.

---

### 7️⃣ Invertir la búsqueda (mostrar lo que *no* coincide)
```bash
grep -v "z" lista.txt
```
🚫 Muestra todas las líneas de `lista.txt` que **no** contienen la letra “z”.

---

### 8️⃣ Contar cuántas veces aparece una coincidencia
```bash
grep -c "error" log.txt
```
🔢 Muestra el número de líneas que contienen la palabra “error”.  
Perfecto para revisar logs o salidas largas.

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-i` | Ignora mayúsculas/minúsculas |
| `-n` | Muestra el número de línea |
| `-v` | Muestra las líneas que **no** coinciden |
| `-c` | Muestra el número de coincidencias |
| `-l` | Muestra solo los nombres de los archivos coincidentes |
| `-r` | Busca de forma recursiva en subcarpetas |
| `-E` | Usa expresiones regulares extendidas |

---

## ⚠️ Errores comunes

🚫 **“No such file or directory”**  
> El archivo o ruta no existe.  
💡 Usa `ls` para comprobar el nombre o prueba con una ruta relativa (`./ex00/z`).

🚫 **“Binary file matches”**  
> Estás buscando dentro de un archivo binario (no de texto).  
💡 Usa `grep -a` para forzar la lectura como texto si lo necesitas.

🚫 **No muestra nada**  
> Puede que el texto no exista o lo estés escribiendo con mayúsculas/minúsculas distintas.  
💡 Añade `-i` para hacer la búsqueda insensible al caso.

---

## 🪄 Tips y buenas prácticas

- Combina `grep` con otros comandos para crear filtros poderosos:
  ```bash
  cat texto.txt | grep "hola" | wc -l
  ```
  📊 Cuenta cuántas líneas contienen la palabra “hola”.
- Usa `grep -r` para buscar en todo un proyecto:
  ```bash
  grep -r "main" ./
  ```
- Resalta coincidencias en color automáticamente:
  ```bash
  grep --color=auto "z" archivo.txt
  ```
- Puedes usar **expresiones regulares** para búsquedas más avanzadas:
  ```bash
  grep -E "^[A-Z]" archivo.txt
  ```
  🔠 Muestra líneas que empiezan con una mayúscula.

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Buscar texto | `grep "hola" archivo.txt` | Busca líneas que contengan “hola” |
| Ignorar mayúsculas | `grep -i "hola" archivo.txt` | Búsqueda sin distinción de caso |
| Mostrar número de línea | `grep -n "texto" archivo.txt` | Añade numeración |
| Buscar en varios archivos | `grep "main" *.c` | Busca coincidencias en múltiples archivos |
| Mostrar solo archivos con coincidencia | `grep -l "main" *.c` | Lista nombres de archivos |
| Invertir búsqueda | `grep -v "error" archivo.txt` | Excluye líneas con la palabra |
| Buscar recursivamente | `grep -r "42" ./` | Busca en subcarpetas |

---

> 💬 *“Grep es como el radar de la terminal: encuentra lo que buscas aunque esté escondido entre miles de líneas.”*  
> Dominarlo te convertirá en un verdadero ninja de la línea de comandos. 🥷
