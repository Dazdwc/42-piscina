# 🧭 Comando `find` — Buscar archivos y carpetas

## 🧠 Concepto
El comando **`find`** se usa para **buscar archivos o carpetas** dentro de un directorio (y sus subcarpetas).  
Es una herramienta potentísima: permite filtrar por nombre, tipo, tamaño, fecha, permisos, y hasta ejecutar comandos sobre los resultados.

En la Piscina, `find` te ayudará a localizar tus archivos rápidamente, comprobar nombres o limpiar temporales antes de entregar.

---

## ⚙️ Sintaxis general

```bash
find [ruta] [condición] [acción]
```

Por defecto, `find` empieza a buscar en la ruta actual (`.`).

---

## 📘 Ejemplos paso a paso

### 1️⃣ Buscar un archivo por nombre
```bash
find . -name "z"
```
🔍 Busca en el directorio actual (`.`) cualquier archivo o carpeta llamada **exactamente** “z”.

💡 Usa comillas siempre que haya mayúsculas o caracteres especiales.

---

### 2️⃣ Buscar archivos por extensión
```bash
find . -name "*.sh"
```
📂 Encuentra todos los archivos que terminen en `.sh` (scripts de shell).

---

### 3️⃣ Buscar solo archivos o solo carpetas
```bash
find . -type f    # solo archivos
find . -type d    # solo directorios
```
🧩 `-type f` significa “file” y `-type d` “directory”.

---

### 4️⃣ Buscar y eliminar archivos
```bash
find . -name "*.tmp" -delete
```
🗑️ Borra todos los archivos con extensión `.tmp` dentro de tu carpeta actual y subcarpetas.  
⚠️ **Cuidado:** No te pedirá confirmación.

---

### 5️⃣ Buscar y ejecutar un comando sobre los resultados
```bash
find . -name "*.txt" -exec cat {} \;
```
📖 Busca todos los `.txt` y ejecuta `cat` sobre cada uno.  
`{}` representa el nombre del archivo encontrado.  
`\;` indica el final del comando.

---

### 6️⃣ Buscar en un nivel concreto
```bash
find . -maxdepth 1 -name "*.c"
```
🔎 Busca solo en el directorio actual, sin entrar en subcarpetas.  
Esto evita listados muy largos.

---

### 7️⃣ Buscar archivos vacíos
```bash
find . -empty
```
📂 Muestra todos los archivos o carpetas que están vacíos (sin contenido).

---

### 8️⃣ Buscar por fecha de modificación
```bash
find . -mtime -1
```
📅 Muestra los archivos modificados en las últimas 24 horas.

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-name "patrón"` | Buscar por nombre o extensión |
| `-type f` | Solo archivos |
| `-type d` | Solo directorios |
| `-delete` | Eliminar archivos encontrados |
| `-exec comando {} \;` | Ejecutar un comando sobre cada archivo |
| `-maxdepth N` | Limitar niveles de subcarpetas |
| `-empty` | Mostrar archivos o carpetas vacíos |
| `-mtime N` | Buscar por fecha de modificación (en días) |

---

## ⚠️ Errores comunes

🚫 **“Permission denied”**  
> Estás buscando en carpetas del sistema sin permisos.  
💡 Limita la búsqueda a tus carpetas (`.` o `~/`).

🚫 **“Argument list too long”**  
> Has intentado usar `rm` con muchos archivos a la vez.  
💡 Usa `find` con `-delete` o `-exec rm {} \;` en su lugar.

🚫 **“find: paths must precede expression”**  
> El orden del comando está mal.  
💡 Recuerda: primero la ruta (`.`), luego las condiciones.

---

## 🪄 Tips y buenas prácticas

- Combínalo con otros comandos usando pipes:
  ```bash
  find . -name "*.c" | sort
  ```
  Ordena alfabéticamente los resultados.
- Para contar cuántos archivos cumplen una condición:
  ```bash
  find . -name "*.c" | wc -l
  ```
  🔢 Devuelve solo el número total.
- Si usas `-exec`, pon `\;` al final del comando o dará error.

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Buscar por nombre | `find . -name "z"` | Busca archivos o carpetas |
| Buscar por extensión | `find . -name "*.c"` | Filtra por tipo de archivo |
| Solo archivos | `find . -type f` | Excluye carpetas |
| Eliminar archivos | `find . -name "*.tmp" -delete` | Borra directamente |
| Ejecutar comando | `find . -exec cat {} \;` | Aplica acción a cada archivo |
| Limitar profundidad | `find . -maxdepth 1 -name "*.sh"` | Solo en carpeta actual |

---

> 💬 *“Find es como un radar dentro de tu terminal: te muestra lo que hay, aunque esté bien escondido.”*  
> Una vez lo domines, buscarás archivos más rápido que el mismísimo `Ctrl + F`.
