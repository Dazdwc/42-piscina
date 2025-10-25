# 🔠 Comando `tr` — Traducir o eliminar caracteres

## 🧠 Concepto
El comando **`tr`** (de *translate*) sirve para **sustituir, eliminar o comprimir caracteres** en una secuencia de texto.  
No trabaja con archivos directamente, sino con **flujos de texto**, por lo que suele usarse junto a `cat`, `echo` o pipes (`|`).

En la Piscina y otros ejercicios shell, `tr` es muy útil para **convertir mayúsculas/minúsculas**, **eliminar caracteres no deseados** o **limpiar salidas** antes de compararlas con `diff`.

---

## ⚙️ Sintaxis general

```bash
tr [opciones] 'conjunto1' ['conjunto2']
```

- `conjunto1`: caracteres a buscar.  
- `conjunto2`: caracteres con los que reemplazar.

Si no se indica `conjunto2`, `tr` normalmente elimina los caracteres del primer conjunto (según las opciones).

---

## 📘 Ejemplos paso a paso

### 1️⃣ Convertir minúsculas a mayúsculas
```bash
echo "hola mundo" | tr 'a-z' 'A-Z'
```
➡️ Resultado:
```
HOLA MUNDO
```
🧠 Convierte cada letra minúscula en su equivalente mayúscula.

---

### 2️⃣ Convertir mayúsculas a minúsculas
```bash
echo "HOLA 42" | tr 'A-Z' 'a-z'
```
➡️ Resultado:
```
hola 42
```

---

### 3️⃣ Sustituir un carácter por otro
```bash
echo "42 Barcelona" | tr ' ' '_'
```
➡️ Resultado:
```
42_Barcelona
```
🔁 Sustituye todos los espacios por guiones bajos.

---

### 4️⃣ Eliminar caracteres específicos
```bash
echo "42!! Piscina!!" | tr -d '!'
```
➡️ Resultado:
```
42 Piscina
```
🗑️ Con la opción `-d`, elimina todos los caracteres indicados en el conjunto.

---

### 5️⃣ Comprimir repeticiones de un mismo carácter
```bash
echo "aaaabbbccc" | tr -s 'a-c'
```
➡️ Resultado:
```
abc
```
♻️ La opción `-s` (“squeeze”) elimina repeticiones consecutivas de los mismos caracteres.

---

### 6️⃣ Sustituir tabulaciones o saltos de línea
```bash
cat archivo.txt | tr '\t' ' '
```
🧩 Convierte todas las tabulaciones (`\t`) en espacios.  
Muy útil para normalizar texto antes de procesarlo.

---

### 7️⃣ Eliminar saltos de línea
```bash
tr -d '\n' < texto.txt
```
➡️ Une todo el contenido del archivo en una sola línea.

---

### 8️⃣ Mantener solo ciertos caracteres
```bash
echo "abc123XYZ" | tr -cd '0-9'
```
➡️ Resultado:
```
123
```
📊 Con `-c`, se invierte el conjunto: elimina todo excepto los caracteres numéricos (`0-9`).

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-d` | Elimina los caracteres del conjunto1 |
| `-s` | Comprime repeticiones consecutivas |
| `-c` | Usa el complemento del conjunto1 (elimina todo menos esos caracteres) |

---

## ⚠️ Errores comunes

🚫 **“tr: missing operand”**  
> Falta uno de los conjuntos de caracteres.  
💡 Si solo quieres eliminar, usa `-d`. Ejemplo: `tr -d 'a'`

🚫 **“Range-endpoints of 'A-Z' collate incorrectly”**  
> En algunos sistemas, los rangos dependen del *locale*.  
💡 Usa `LC_ALL=C` antes del comando para forzar orden ASCII:
```bash
LC_ALL=C tr 'A-Z' 'a-z'
```

🚫 **Sin cambios visibles**  
> `tr` solo actúa sobre el flujo de entrada.  
💡 Si usas `tr` solo, no hará nada: debe recibir datos con `echo`, `cat`, o `< archivo`.

---

## 🪄 Tips y buenas prácticas

- Para limpiar un archivo de caracteres no imprimibles:
  ```bash
  cat archivo | tr -cd '\11\12\40-\176' > limpio.txt
  ```
  (mantiene solo tabulaciones, saltos de línea y caracteres visibles)
- Para normalizar texto antes de usar `diff`:
  ```bash
  cat salida.txt | tr -d '[:space:]'
  ```
  elimina todos los espacios y saltos.
- Convertir texto rápido dentro de scripts:
  ```bash
  VAR=$(echo "$VAR" | tr 'a-z' 'A-Z')
  ```

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Mayúsculas → minúsculas | `tr 'A-Z' 'a-z'` | Convierte todo a minúsculas |
| Minúsculas → mayúsculas | `tr 'a-z' 'A-Z'` | Convierte todo a mayúsculas |
| Sustituir | `tr ' ' '_'` | Reemplaza espacios por guiones bajos |
| Eliminar | `tr -d '!'` | Borra los caracteres “!” |
| Comprimir repeticiones | `tr -s ' '` | Quita espacios repetidos |
| Mantener solo números | `tr -cd '0-9'` | Elimina todo excepto los dígitos |

---

> 💬 *“tr es como un mini traductor: toma un flujo de texto y lo limpia, transforma o simplifica.”*  
> Dominarlo te da control total sobre el contenido de tus archivos y salidas.
