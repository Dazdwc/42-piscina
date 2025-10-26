# 🦾 Comando `awk`

---

## 🧠 Concepto

El comando **`awk`** es una herramienta muy potente para **procesar texto estructurado línea a línea**.  
Permite **dividir cada línea en columnas**, **filtrar información**, **hacer cálculos** y **dar formato a la salida**.

En la piscina es especialmente útil para **mostrar columnas específicas** o **filtrar líneas según una condición**.

---

## ⚙️ Sintaxis general

```bash
  awk 'patrón {acción}' [archivo]
```

- **`patrón`** → condición que debe cumplirse (por ejemplo, `NR == 1`).  
- **`acción`** → lo que hace `awk` si se cumple la condición (por ejemplo, `print $1`).

---

## 📘 Ejemplos paso a paso

### 1️⃣ Mostrar solo las líneas impares
```bash
  ls -l | awk 'NR % 2 == 1'
```
🔹 `NR` es el número de línea. Imprime solo las impares (1, 3, 5…).

### 2️⃣ Mostrar una columna específica
```bash
  awk '{print $1}' archivo.txt
```
🔹 Imprime la **primera columna** de cada línea.

### 3️⃣ Mostrar varias columnas
```bash
  awk '{print $1, $3}' archivo.txt
```
🔹 Imprime las columnas 1 y 3 separadas por un espacio.

### 4️⃣ Filtrar por una condición
```bash
  awk '$3 > 100 {print $1, $3}' archivo.txt
```
🔹 Muestra solo las líneas donde la tercera columna sea mayor que 100.

### 5️⃣ Cambiar el separador de campos
```bash
  awk -F: '{print $1}' /etc/passwd
```
🔹 Usa `:` como separador y muestra la primera columna.

### 6️⃣ Sumar valores de una columna numérica
```bash
  awk '{s+=$2} END {print s}' archivo.txt
```
🔹 Suma todos los valores de la **segunda columna** y muestra el total.

---

## ⚙️ Variables internas de `awk`

Estas variables se crean automáticamente y controlan tanto el flujo de procesamiento como el formato de salida.  
Saber usarlas bien te permite hacer desde cálculos hasta formatear columnas o cambiar delimitadores.

| Variable | Descripción traducida | Ejemplo |
|-----------|------------------------|----------|
| `$0` | Línea completa actual. | `print $0` → muestra toda la línea. |
| `$1`, `$2`, … | Campos individuales (columnas). | `print $1, $3` → muestra las columnas 1 y 3. |
| `NF` | Número de campos en la línea actual. | `print NF` → muestra cuántas columnas tiene la línea. |
| `NR` | Número de línea actual (total desde el inicio). | `print NR, $0` → imprime número y contenido. |
| `FNR` | Número de línea dentro del archivo actual. | Útil al procesar varios archivos. |
| `FS` | Separador de campos de entrada (por defecto espacio o tab). | `awk -F: '{print $1}' /etc/passwd` |
| `OFS` | Separador de campos de salida. Por defecto `" "`. | `BEGIN {OFS=" - "} {print $1,$2}` |
| `RS` | Separador de registros de entrada. Por defecto salto de línea `"\n"`. | `BEGIN {RS=""}` para procesar párrafos. |
| `ORS` | Separador de registros de salida. Por defecto `"\n"`. | `BEGIN {ORS=";"} {print $1}` |
| `OFMT` | Formato de salida para números (por defecto `"%.6g"`). | `BEGIN {OFMT="%.2f"; print 3.14159}` |
| `RLENGTH` | Longitud del último texto coincidente con `match()`. | `match($0,/42/) {print RLENGTH}` |
| `RSTART` | Posición inicial del texto coincidente con `match()`. | `match($0,/42/) {print RSTART}` |
| `SUBSEP` | Separador para índices múltiples en arrays (por defecto `\034`). | `BEGIN {A[1,2]=10; print A[1 SUBSEP 2]}` |
| `FILENAME` | Nombre del archivo actual que se está procesando. | `print FILENAME, NR, $0` |
| `ARGC` | Número de argumentos pasados a `awk`. | Muestra cuántos parámetros recibió. |
| `ARGV` | Lista de argumentos (`ARGV[1]`, `ARGV[2]`, …). | Accede a cada argumento individual. |
| `ENVIRON` | Acceso a variables de entorno del sistema. | `print ENVIRON["USER"]` muestra el usuario actual. |

---

## ⚙️ Variables útiles en acción

```bash
  awk 'BEGIN {FS=":"; OFS=" - "} {print NR, FILENAME, NF, $1}' /etc/passwd
```
🔹 Muestra: número de línea, nombre del archivo, cantidad de campos y primera columna.  

O para probar variables de entorno:
```bash
  awk 'BEGIN {print "Usuario:", ENVIRON["USER"]}'
```

---

## ⚠️ Errores comunes

| Error | Causa | Solución |
|--------|--------|-----------|
| `awk: syntax error near unexpected token` | Falta de comillas o llaves. | Usa `' '` para envolver la expresión y `{}` para la acción. |
| No imprime nada | No se cumple el patrón. | Revisa la condición o quita el filtro. |
| Columnas incorrectas | Separador diferente. | Usa `-F` para definir el separador correcto. |

---

## 🪄 Tips y buenas prácticas

- Para numerar líneas fácilmente:
  ```bash
    awk '{print NR, $0}' archivo.txt
  ```
- Para ver el número de columnas de cada línea:
  ```bash
    awk '{print NF}' archivo.txt
  ```
- Filtrar texto con expresiones regulares:
  ```bash
    awk '/error/ {print $0}' log.txt
  ```
- Puedes usar condiciones matemáticas:
  ```bash
    awk 'NR % 2 == 0' archivo.txt
  ```
  🔹 imprime solo las líneas pares.

---

## 🎯 Resumen

| Acción | Comando | Resultado |
|--------|----------|-----------|
| Mostrar líneas impares | `awk 'NR % 2 == 1'` | Muestra 1ª, 3ª, 5ª, etc. |
| Mostrar primera columna | `awk '{print $1}'` | Imprime la primera palabra o campo. |
| Filtrar por valor | `awk '$3 > 100 {print $1}'` | Solo muestra líneas que cumplan la condición. |
| Cambiar separador | `awk -F: '{print $1}' /etc/passwd` | Usa “:” como delimitador. |
| Sumar columna numérica | `awk '{s+=$2} END {print s}'` | Muestra la suma total. |
| Ver variables de entorno | `awk 'BEGIN {print ENVIRON["USER"]}'` | Imprime el usuario actual. |

---

> 💬 *Consejo:* Aprender las variables internas de `awk` te permite automatizar tareas que normalmente requerirían scripts completos.  
> Es un mini lenguaje de programación dentro del shell. 🚀
