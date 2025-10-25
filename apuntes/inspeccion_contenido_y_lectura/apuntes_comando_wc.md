# 📊 Comando `wc` — Contar líneas, palabras y caracteres

## 🧠 Concepto
El comando **`wc`** (*word count*) se usa para **contar líneas, palabras y caracteres** de un archivo o de una salida de texto.  
Es un comando básico pero muy poderoso cuando se combina con otros (como `grep`, `cat`, o `find`).  

En la Piscina, `wc` te ayuda a comprobar si la salida de tus programas tiene el número de líneas exacto que pide el enunciado.

---

## ⚙️ Sintaxis general

```bash
wc [opciones] [archivo]
```

Si no se indica archivo, `wc` lee de la **entrada estándar** (por ejemplo, con pipes).

---

## 📘 Ejemplos paso a paso

### 1️⃣ Contar todo (líneas, palabras y caracteres)
```bash
wc texto.txt
```
📄 Ejemplo de salida:
```
5  10  58  texto.txt
```
➡️ Significa:
- `5` → líneas  
- `10` → palabras  
- `58` → caracteres (incluyendo espacios y saltos de línea)

---

### 2️⃣ Contar solo las líneas
```bash
wc -l texto.txt
```
📏 Devuelve solo el número de líneas del archivo.  
Perfecto para comprobar si tu salida tiene el número exacto de líneas que pide un ejercicio.

---

### 3️⃣ Contar solo las palabras
```bash
wc -w texto.txt
```
🧮 Muestra solo el número de palabras.

---

### 4️⃣ Contar solo los caracteres
```bash
wc -m texto.txt
```
🔠 Devuelve la cantidad de caracteres (letras, números, signos, etc.).

---

### 5️⃣ Contar usando un pipe
```bash
echo "Hola mundo" | wc -w
```
📥 Cuenta las palabras de una cadena directamente desde la entrada estándar.  
💡 Ideal para comprobar resultados en una línea sin crear archivos.

---

### 6️⃣ Contar líneas de salida de otro comando
```bash
ls | wc -l
```
📦 Cuenta cuántos archivos o carpetas hay en el directorio actual.  
Un clásico de la terminal.

---

### 7️⃣ Contar coincidencias con `grep`
```bash
grep "hola" archivo.txt | wc -l
```
🔍 Cuenta cuántas líneas contienen la palabra “hola”.  
Muy útil para analizar logs o comparar resultados.

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-l` | Cuenta solo líneas |
| `-w` | Cuenta solo palabras |
| `-m` | Cuenta solo caracteres |
| `-c` | Cuenta bytes (similar a `-m`, pero en bruto) |

---

## ⚠️ Errores comunes

🚫 **“No such file or directory”**  
> El archivo no existe o la ruta es incorrecta.  
💡 Usa `ls` o `pwd` para confirmar la ubicación.

🚫 **Cuenta incorrecta en caracteres**  
> Algunos caracteres especiales o acentos cuentan como más de un byte.  
💡 Usa `wc -m` para contar caracteres en lugar de `-c`.

🚫 **Sin salida visible**  
> Si usas `wc` sin datos ni archivo, esperará entrada hasta que pulses `Ctrl + D`.

---

## 🪄 Tips y buenas prácticas

- Para contar todos los archivos `.c` en tus ejercicios:
  ```bash
  find . -name "*.c" | wc -l
  ```
- Para contar cuántas veces aparece una palabra en un texto:
  ```bash
  grep -o "42" texto.txt | wc -l
  ```
  💡 `-o` muestra solo las coincidencias, una por línea.
- Para ver líneas + palabras + caracteres de forma ordenada:
  ```bash
  wc -lwm archivo.txt
  ```

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Contar todo | `wc archivo.txt` | Muestra líneas, palabras y caracteres |
| Contar líneas | `wc -l archivo.txt` | Solo número de líneas |
| Contar palabras | `wc -w archivo.txt` | Solo número de palabras |
| Contar caracteres | `wc -m archivo.txt` | Solo caracteres |
| Usar con pipe | `ls | wc -l` | Cuenta líneas de salida |
| Buscar y contar | `grep "z" archivo.txt | wc -l` | Cuenta líneas coincidentes |

---

> 💬 *“`wc` es el contador oficial de la terminal: líneas, palabras y letras al servicio de tu control.”*  
> Úsalo para verificar tus salidas y asegurarte de que todo encaja al milímetro. ⚙️
