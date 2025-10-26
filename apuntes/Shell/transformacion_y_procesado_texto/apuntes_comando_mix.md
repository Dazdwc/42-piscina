# 🧩 Combinaciones de comandos — El poder del Shell

## 🧠 Concepto
En Bash, el verdadero poder está en **combinar comandos**.  
Cada comando por separado hace una tarea concreta, pero cuando los unes con **pipes (`|`)**, **redirecciones (`>`, `<`)** o **subcomandos**, puedes resolver problemas complejos en una sola línea.

En la Piscina y en cualquier entorno Unix, esto es lo que marca la diferencia entre “usar comandos” y “pensar en Shell”.

---

## ⚙️ Recordatorio clave: el Pipe `|`

`|` **envía la salida de un comando como entrada del siguiente.**  
Ejemplo simple:

```bash
ls | grep ".sh"
```
➡️ Muestra solo los archivos `.sh` del directorio actual.  
`ls` genera una lista → `grep` filtra esa lista.

---

## 📘 Ejemplos paso a paso

### 1️⃣ Buscar texto en archivos y contar coincidencias
```bash
grep "42" *.txt | wc -l
```
🔍 Busca la palabra “42” en todos los `.txt` y cuenta cuántas líneas la contienen.

---

### 2️⃣ Ordenar y eliminar duplicados
```bash
cat nombres.txt | sort -u
```
📋 Muestra los nombres ordenados alfabéticamente y sin repeticiones.

---

### 3️⃣ Buscar archivos, mostrar solo nombres y contarlos
```bash
find . -type f -name "*.c" | wc -l
```
📦 Busca todos los archivos `.c` en tu carpeta actual y subcarpetas, y muestra cuántos hay.

---

### 4️⃣ Buscar archivos con cierto contenido
```bash
grep -r "main" ./ | cut -d ":" -f1 | sort -u
```
🧠 Busca “main” en todo tu proyecto, muestra solo los nombres de los archivos y elimina duplicados.

- `grep -r` → búsqueda recursiva  
- `cut -d ":" -f1` → corta el nombre del archivo antes de los `:`  
- `sort -u` → los ordena y limpia duplicados

---

### 5️⃣ Transformar texto y contar palabras
```bash
cat texto.txt | tr 'A-Z' 'a-z' | tr -d '[:punct:]' | wc -w
```
📊 Convierte todo a minúsculas, elimina signos de puntuación y cuenta las palabras.  
💡 Muy útil para procesar texto limpio.

---

### 6️⃣ Extraer datos estructurados
Supón que tienes un archivo con formato:
```
nombre:edad:ciudad
dani:30:barcelona
claudia:27:madrid
```
Puedes listar solo las ciudades:
```bash
cut -d ":" -f3 datos.txt
```
Y si quieres contar cuántas veces aparece cada ciudad:
```bash
cut -d ":" -f3 datos.txt | sort | uniq -c
```

---

### 7️⃣ Buscar archivos y analizar su tipo
```bash
find . -type f | while read file; do file "$file"; done
```
🧩 Analiza todos los archivos y muestra su tipo usando `file`.  
💡 Esto combina `find`, `file` y un bucle shell.

---

### 8️⃣ Crear, comprimir y verificar archivos con `tar`
```bash
tar -czf backup.tar.gz ./ex00/ && file backup.tar.gz
```
📦 Crea un archivo comprimido de `ex00` y verifica que se generó correctamente.  
💡 `&&` asegura que el segundo comando solo se ejecute si el primero fue exitoso.

---

### 9️⃣ Buscar un texto en todos los `.c` y mostrar solo los nombres únicos
```bash
grep -rl "malloc" ./ | sort -u
```
🔍 Lista los archivos donde aparece “malloc”, sin repeticiones.

---

### 🔟 Contar líneas totales de código
```bash
find . -type f -name "*.c" | xargs cat | wc -l
```
📏 Suma el total de líneas en todos tus archivos `.c`.  
💡 `xargs` permite pasar los resultados de `find` a `cat` incluso si hay muchos archivos.

---

## ⚙️ Redirecciones útiles

| Operador | Ejemplo | Descripción |
|-----------|----------|-------------|
| `>` | `ls > lista.txt` | Guarda salida en un archivo (sobrescribe) |
| `>>` | `echo "nueva línea" >> archivo.txt` | Añade al final del archivo |
| `<` | `cat < archivo.txt` | Usa un archivo como entrada |
| `2>` | `comando 2> errores.txt` | Redirige los errores |
| `&>` | `./script.sh &> log.txt` | Guarda salida y errores juntos |

---

## ⚠️ Errores comunes

🚫 **“Broken pipe”**  
> Uno de los comandos del pipe terminó antes de tiempo.  
💡 Revisa que todos los comandos reciban la entrada esperada.

🚫 **“Permission denied”**  
> Estás redirigiendo a una carpeta o archivo sin permisos.  
💡 Usa rutas dentro de tu proyecto o añade permisos con `chmod`.

🚫 **Resultados vacíos**  
> Alguno de los comandos anteriores filtró todo.  
💡 Añade partes intermedias (`| cat`) para depurar el flujo.

---

## 🪄 Tips y buenas prácticas

- Empieza siempre **probando cada comando por separado** antes de encadenarlos.  
- Usa `| cat -n` al final para **ver las líneas numeradas** y depurar.  
- Si un pipe falla, prueba con `set -x` para ver la ejecución paso a paso.  
- Guarda combinaciones útiles en alias dentro de tu `~/.bashrc`.  
  ```bash
  alias countc='find . -name "*.c" | xargs cat | wc -l'
  ```

---

## 🎯 Resumen

| Objetivo | Combinación | Descripción |
|-----------|-------------|-------------|
| Buscar y contar | `grep "42" *.txt | wc -l` | Líneas que contienen “42” |
| Ordenar y limpiar | `cat lista | sort -u` | Ordena y elimina duplicados |
| Buscar archivos `.c` | `find . -name "*.c"` | Lista todos los `.c` |
| Buscar texto y mostrar archivos únicos | `grep -rl "main" ./ | sort -u` | Archivos con “main” |
| Contar líneas de todos los `.c` | `find . -name "*.c" | xargs cat | wc -l` | Total de líneas |
| Comprimir y verificar | `tar -czf backup.tar.gz ./ && file backup.tar.gz` | Empaqueta y comprueba |

---

> 💬 *“Un solo comando puede ser útil, pero cuando los combinas, creas herramientas.”*  
> Este es el lenguaje real de los desarrolladores Unix. 🧠⚙️
