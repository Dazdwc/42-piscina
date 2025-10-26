# 🧭 Comando `basename` — Obtener el nombre base de un archivo o ruta

## 🧠 Concepto
El comando **`basename`** se utiliza para **extraer el nombre de archivo o directorio de una ruta completa**, eliminando todo el camino anterior.  
Opcionalmente, también puede **quitar una extensión o sufijo** específico del nombre.

Es muy útil en scripts cuando necesitas mostrar o manipular nombres de archivo sin sus rutas completas.

---

## ⚙️ Sintaxis general

```bash
  basename [ruta] [sufijo_opcional]
```

### Parámetros
| Parámetro | Descripción |
|------------|--------------|
| `ruta` | Ruta completa o relativa de un archivo o directorio |
| `sufijo_opcional` | Texto o extensión que se eliminará del final si coincide (por ejemplo `.sh` o `.txt`) |

---

## 📘 Ejemplos paso a paso

### 1️⃣ Mostrar solo el nombre del archivo
```bash
  basename /home/user/scripts/start.sh
```
📄 **Salida:**
```
start.sh
```
🧩 Quita toda la ruta y deja solo el nombre del archivo.

---

### 2️⃣ Quitar también la extensión
```bash
  basename /home/user/scripts/start.sh .sh
```
📄 **Salida:**
```
start
```
🧠 Además de eliminar la ruta, elimina el sufijo `.sh`.

---

### 3️⃣ Usar variables dentro de un script
```bash
  FILE="/usr/local/bin/python3"
  basename "$FILE"
```
📄 **Salida:**
```
python3
```
💡 Ideal para obtener solo el nombre del archivo a partir de rutas almacenadas en variables.

---

### 4️⃣ En combinación con `find`
```bash
  find . -type f -name "*.sh" -exec basename {} .sh \;
```
📂 Este comando busca todos los archivos `.sh` en el directorio actual y muestra solo sus nombres sin ruta ni extensión.

📄 **Salida:**
```
start
deploy
cleanup
```

🧠 `basename` trabaja sobre cada resultado individual que le pasa `find`.

---

## ⚙️ Opciones comunes

Aunque `basename` es un comando muy simple, existen algunas variantes y usos comunes:

| Opción | Descripción |
|--------|--------------|
| `[sufijo]` | Elimina el sufijo o extensión del nombre |
| `--help` | Muestra ayuda rápida |
| `--version` | Muestra la versión del comando |

---

## ⚠️ Errores comunes

🚫 **"No such file or directory"**  
> `basename` no necesita que el archivo exista; pero si la ruta contiene caracteres especiales sin comillas, el shell puede interpretarlos mal.  
💡 Usa siempre comillas: `basename "$ruta"`

🚫 **Sufijo no coincide**  
> Si el sufijo no está al final del nombre, no se elimina.  
💡 Ejemplo: `basename archivo.txt .sh` → devuelve `archivo.txt`, no `archivo`.

---

## 🪄 Trucos y combinaciones útiles

### 🔹 Obtener nombre y ruta por separado
```bash
  RUTA="/home/user/scripts/start.sh"
  echo "Ruta: $(dirname "$RUTA")"
  echo "Archivo: $(basename "$RUTA" .sh)"
```
📄 **Salida:**
```
Ruta: /home/user/scripts
Archivo: start
```

### 🔹 Quitar extensión sin `basename`
También puedes hacerlo solo con Bash:
```bash
  file="archivo.txt"
  echo "${file%.txt}"
```
📄 **Salida:**
```
archivo
```

---

## 🎯 Resumen

| Acción | Comando | Resultado |
|--------|----------|-----------|
| Mostrar solo el nombre | `basename /path/to/file.txt` | `file.txt` |
| Mostrar sin extensión | `basename /path/to/file.txt .txt` | `file` |
| Usar con `find` | `find . -name "*.sh" -exec basename {} .sh \;` | Lista de nombres limpios |

---

> 💬 *“Cuando quieras el nombre, olvida el camino. `basename` te da justo eso: lo esencial.”* 🧭

---
