# ✂️ Comando `cut` — Extraer columnas o fragmentos de texto

## 🧠 Concepto
El comando **`cut`** se usa para **extraer partes específicas de texto** de cada línea de un archivo o de una salida.  
Normalmente se usa para seleccionar **campos o columnas** separadas por un carácter (como `:` o `,`), o para cortar **rangos de caracteres**.

En la Piscina, `cut` te ayuda a separar nombres, extensiones, o datos de líneas complejas de texto.

---

## ⚙️ Sintaxis general

```bash
cut [opciones] [archivo]
```

Por defecto, `cut` lee de la **entrada estándar**, por lo que puedes combinarlo con `cat` o `grep` mediante pipes (`|`).

---

## 📘 Ejemplos paso a paso

### 1️⃣ Cortar una columna delimitada por un carácter
```bash
cut -d ":" -f1 usuarios.txt
```
📄 Si el archivo `usuarios.txt` contiene:
```
daniel:42barcelona
claudia:42madrid
```
➡️ Salida:
```
daniel
claudia
```
🧩 `-d ":"` indica el delimitador y `-f1` selecciona la primera columna.

---

### 2️⃣ Seleccionar varias columnas
```bash
cut -d ":" -f1,2 usuarios.txt
```
📋 Muestra las columnas 1 y 2, separadas por el mismo delimitador.

---

### 3️⃣ Cortar un rango de caracteres
```bash
cut -c 1-5 archivo.txt
```
✂️ Muestra solo los **primeros 5 caracteres** de cada línea.

---

### 4️⃣ Mostrar desde un carácter en adelante
```bash
cut -c 6- archivo.txt
```
📖 Empieza a mostrar desde el carácter 6 hasta el final de la línea.

---

### 5️⃣ Extraer campos de un comando con pipe
```bash
ls -l | cut -d " " -f9
```
📦 Muestra solo el nombre de los archivos listados por `ls -l`.  
💡 A veces puede haber varios espacios seguidos, por lo que `awk` puede ser más fiable, pero `cut` funciona bien para texto simple.

---

### 6️⃣ Combinar con `grep` o `sort`
```bash
cat datos.txt | grep "Barcelona" | cut -d "," -f2 | sort -u
```
🔍 Busca líneas que contengan “Barcelona”, extrae la segunda columna y las ordena sin duplicados.

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-d 'X'` | Define el delimitador de campos |
| `-f N` | Selecciona el campo (columna) número N |
| `-c N-M` | Selecciona los caracteres del rango N a M |
| `--complement` | Muestra todo excepto los campos seleccionados |

---

## ⚠️ Errores comunes

🚫 **“cut: the delimiter must be a single character”**  
> Solo puedes usar **un carácter** como delimitador (no palabras ni cadenas).  
💡 Usa `awk` si necesitas delimitadores más complejos.

🚫 **Columnas vacías**  
> Si hay espacios dobles o líneas irregulares, `cut` puede dar resultados raros.  
💡 Usa un delimitador consistente o combínalo con `tr -s ' '` para limpiar.

🚫 **No hay salida**  
> Puede que el archivo no tenga el delimitador indicado.  
💡 Revisa el contenido con `cat archivo.txt`.

---

## 🪄 Tips y buenas prácticas

- Ver los primeros N caracteres de cada línea:
  ```bash
  cat archivo.txt | cut -c 1-10
  ```
- Ver la extensión de una lista de archivos:
  ```bash
  ls | cut -d "." -f2
  ```
- Eliminar la primera columna y dejar el resto:
  ```bash
  cut -d ":" --complement -f1 archivo.txt
  ```
- Combinarlo con `grep` y `wc` para analizar resultados:
  ```bash
  cat usuarios.txt | grep "42" | cut -d ":" -f2 | wc -l
  ```

---

## 🎯 Resumen

| Acción | Comando                                   | Descripción |
|--------|-------------------------------------------|-------------|
| Extraer primera columna | `cut -d ":" -f1 archivo.txt`              | Muestra el primer campo |
| Varias columnas | `cut -d ":" -f1,3 archivo.txt`            | Muestra columnas 1 y 3 |
| Rango de caracteres | `cut -c 1-5 archivo.txt`                  | Primeros 5 caracteres |
| Desde un carácter | `cut -c 6- archivo.txt`                   | Desde el 6 en adelante |
| Eliminar una columna | `cut -d ":" --complement -f1 archivo.txt` | Muestra todas menos la primera |
| Con pipes | `grep "txt" \| cut -d ":" -f2`            | Procesa salidas encadenadas |

---

> 💬 *“Cut es como unas tijeras para tus archivos: te deja quedarte solo con la parte que necesitas.”* ✂️  
> Ideal para filtrar, limpiar y preparar datos antes de combinarlos con otros comandos.
