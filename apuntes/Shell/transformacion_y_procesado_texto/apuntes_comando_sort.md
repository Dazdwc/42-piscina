# 🔤 Comando `sort` — Ordenar líneas de texto o archivos

## 🧠 Concepto
El comando **`sort`** se usa para **ordenar líneas de texto** de un archivo o de la salida de otro comando.  
Puede hacerlo alfabéticamente, numéricamente o según una columna concreta.  
En la Piscina, te servirá para analizar resultados, comprobar listados o preparar salidas ordenadas antes de entregarlas.

---

## ⚙️ Sintaxis general

```bash
sort [opciones] [archivo]
```

Si no se indica archivo, `sort` lee desde la **entrada estándar**, es decir, puedes enviarle datos con `|` (pipe).

---

## 📘 Ejemplos paso a paso

### 1️⃣ Ordenar un archivo alfabéticamente
```bash
sort nombres.txt
```
🔡 Ordena las líneas de `nombres.txt` en orden alfabético (A → Z).

Ejemplo:
```
Claudia
Daniel
Alberto
```
➡️ Salida:
```
Alberto
Claudia
Daniel
```

---

### 2️⃣ Ordenar ignorando mayúsculas/minúsculas
```bash
sort -f nombres.txt
```
🔤 La opción `-f` hace que `Sort` no distinga entre mayúsculas y minúsculas.  
Ideal para archivos donde hay nombres mezclados (como *Dani* y *dani*).

---

### 3️⃣ Ordenar numéricamente
```bash
sort -n numeros.txt
```
🔢 Ordena los números por valor en lugar de alfabéticamente.

Ejemplo:  
```
2
10
1
```
➡️ Salida con `-n`:
```
1
2
10
```

---

### 4️⃣ Ordenar de forma inversa
```bash
sort -r lista.txt
```
🔁 Ordena los resultados **al revés** (Z → A o mayor → menor).

---

### 5️⃣ Ordenar por una columna concreta
Supón un archivo con este contenido:
```
Dani 25
Claudia 27
Alex 19
```
Puedes ordenar por la **segunda columna (edad)** con:
```bash
sort -k2 numeros.txt
```
📊 La opción `-k` indica la **columna** usada como referencia.

---

### 6️⃣ Eliminar líneas duplicadas
```bash
sort -u lista.txt
```
♻️ Ordena el archivo y elimina las líneas repetidas.

💡 Si solo quieres eliminar duplicados (sin ordenar), puedes combinar con `uniq`, pero `sort -u` suele bastar.

---

### 7️⃣ Ordenar la salida de otro comando
```bash
ls | sort
```
🧩 Ordena alfabéticamente el resultado de `ls`.  
Puedes usarlo con cualquier comando que devuelva varias líneas.

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-f` | Ignora mayúsculas/minúsculas |
| `-n` | Ordena numéricamente |
| `-r` | Orden inverso |
| `-k N` | Usa la columna N para ordenar |
| `-u` | Elimina duplicados |
| `-t` | Define un delimitador de columnas (por defecto es espacio) |

Ejemplo con delimitador:  
```bash
sort -t ":" -k2 usuarios.txt
```
🔹 Si el archivo separa campos con “:”, usará la segunda columna para ordenar.

---

## ⚠️ Errores comunes

🚫 **“Broken pipe” o sin salida**  
> Puede ocurrir al combinar mal con otros comandos.  
💡 Asegúrate de usar `|` correctamente (por ejemplo, `cat archivo | sort`).

🚫 **Resultados inesperados con números**  
> Sin la opción `-n`, los ordena alfabéticamente: “10” < “2”.  
💡 Usa `sort -n` para orden numérico real.

🚫 **Orden extraño por columnas**  
> Si las columnas no están separadas por espacios o tabulaciones normales.  
💡 Usa `-t` para definir tu propio separador.

---

## 🪄 Tips y buenas prácticas

- Para ordenar y eliminar duplicados rápidamente:
  ```bash
  sort -u lista.txt
  ```
- Si trabajas con CSVs o archivos delimitados:
  ```bash
  sort -t "," -k3 data.csv
  ```
  📊 Ordena por la tercera columna del CSV.
- Combínalo con `grep` o `find`:
  ```bash
  find . -name "*.c" | sort
  ```
  🔎 Obtén una lista ordenada de tus archivos .c.

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Ordenar texto | `sort archivo.txt` | Ordena líneas alfabéticamente |
| Ignorar mayúsculas | `sort -f archivo.txt` | No diferencia entre mayúsculas/minúsculas |
| Orden numérico | `sort -n archivo.txt` | Ordena números correctamente |
| Orden inverso | `sort -r archivo.txt` | Invierte el orden |
| Por columna | `sort -k2 archivo.txt` | Usa la columna 2 como referencia |
| Eliminar duplicados | `sort -u archivo.txt` | Ordena y elimina repeticiones |

---

> 💬 *“Sort pone orden en el caos de tus archivos.”*  
> Domínalo y podrás organizar cualquier resultado de forma precisa y limpia.
