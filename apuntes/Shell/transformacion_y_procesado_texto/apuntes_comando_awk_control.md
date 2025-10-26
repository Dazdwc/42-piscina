# 🧩 Control de flujo en `awk`

---

## 🧠 Concepto

El lenguaje `awk` no solo sirve para filtrar o mostrar texto:  
también incluye **estructuras de control** (condicionales, bucles, y bloques especiales) que permiten ejecutar acciones complejas sobre cada línea o conjunto de datos.

Estas estructuras hacen que `awk` funcione casi como un lenguaje de programación completo dentro del shell.

---

## ⚙️ Sintaxis general

Las principales estructuras de control en `awk` son:

```awk
if (condición) {acción}
else if (otra_condición) {acción}
else {acción}

while (condición) {acción}

for (inicialización; condición; incremento) {acción}

break
continue
exit
```

Además, `awk` tiene **bloques especiales**:

```awk
BEGIN {acciones antes de procesar datos}
{acciones que se ejecutan para cada línea}
END {acciones después de procesar todos los datos}
```

---

## 📘 Ejemplos paso a paso

### 1️⃣ Usar `if` para filtrar condicionalmente
```bash
awk '{if ($3 > 50) print $1, $3}' archivo.txt
```
🔹 Imprime solo las líneas donde la tercera columna sea mayor que 50.

---

### 2️⃣ `if` con `else`
```bash
awk '{if ($3 >= 10) print $1, "✅"; else print $1, "❌"}' archivo.txt
```
🔹 Muestra una marca según si el valor cumple la condición.

---

### 3️⃣ Bucle `while`
```bash
ls -l | awk '{i=0; while (i < 3) {if (NR % 2 == 1) print NR, $9; i++}}'
```
🔹 Ejecuta un bucle dentro de cada línea: imprime tres veces las líneas impares.

📘 Más útil: contar líneas hasta una condición y detenerse:
```bash
awk '{if (NR % 2 == 1) {print NR, $9; i++; if (i == 3) exit}}' 
```
🔹 Muestra solo las **tres primeras líneas impares** y luego sale.

---

### 4️⃣ Bucle `for`
```bash
awk 'BEGIN {for (i=1; i<=5; i++) print "Iteración", i}'
```
🔹 Ejemplo simple que imprime 5 iteraciones antes de leer datos.

---

### 5️⃣ Uso de `break` y `continue`
```bash
awk 'BEGIN {for (i=1; i<=10; i++) {if (i==5) continue; if (i>8) break; print i}}'
```
🔹 Salta el número 5 (`continue`) y detiene el bucle al llegar a 9 (`break`).

---

### 6️⃣ Bloques `BEGIN` y `END`

#### `BEGIN`
Se ejecuta **antes** de procesar el archivo o la entrada.
```bash
awk 'BEGIN {print "Inicio del procesamiento"} {print $0}'
```
🔹 Muestra un mensaje antes de leer el contenido.

#### `END`
Se ejecuta **una sola vez al final**.
```bash
awk '{total += $2} END {print "Suma total:", total}' archivo.txt
```
🔹 Calcula la suma de la segunda columna y la imprime al terminar.

---

## ⚙️ Ejemplos avanzados

### 🧮 Calcular promedio con `BEGIN` y `END`
```bash
awk '{suma += $2; contador++} END {print "Promedio:", suma/contador}'
```

### 🔍 Filtrar y contar líneas que contienen una palabra
```bash
awk '/error/ {n++} END {print "Errores encontrados:", n}'
```

### 🧠 Usar `for` para recorrer columnas dinámicamente
```bash
awk '{for (i=1; i<=NF; i++) print "Columna", i ":", $i}' archivo.txt
```

---

## ⚠️ Errores comunes

| Error | Causa | Solución |
|--------|--------|-----------|
| `awk: syntax error near unexpected token` | Falta un `{}` o comillas. | Usa comillas simples `' '` y agrupa acciones entre llaves. |
| Bucle infinito | Condición nunca cambia. | Asegúrate de incrementar el contador dentro del bucle. |
| Variables no inicializadas | No se definieron antes del uso. | Inicialízalas en `BEGIN` o antes del bucle. |

---

## 🪄 Tips y buenas prácticas

- Usa `BEGIN` para inicializar variables o imprimir cabeceras.  
- Usa `END` para mostrar totales o resúmenes finales.  
- Si quieres salir del script antes de terminar, usa `exit`.  
- Usa **indentación** dentro de las llaves `{}` para legibilidad.  
- Combina condiciones con operadores lógicos:  
  `&&` (y), `||` (o), `!` (no).  

Ejemplo:
```bash
awk '{if ($2 > 10 && $3 < 5) print $1, $2, $3}'
```

---

## 🎯 Resumen

| Estructura | Descripción | Ejemplo |
|-------------|--------------|----------|
| `if` / `else` | Ejecuta código condicionalmente. | `if ($3>10) print $1` |
| `while` | Repite mientras la condición sea verdadera. | `while (i<3) {print i; i++}` |
| `for` | Bucle con contador. | `for (i=1;i<=5;i++) print i` |
| `break` | Sale del bucle. | `if (i>8) break` |
| `continue` | Salta a la siguiente iteración. | `if (i==5) continue` |
| `exit` | Termina el script `awk`. | `if (i==3) exit` |
| `BEGIN` | Se ejecuta antes de leer datos. | `BEGIN {print "Inicio"}` |
| `END` | Se ejecuta al finalizar. | `END {print "Fin"}` |

---

> 💬 *Consejo:* Las estructuras de control convierten `awk` en una mini herramienta de scripting.  
> Con `BEGIN`, `END`, bucles y condiciones, puedes automatizar cálculos o filtrados sin salir de la terminal. 🚀
