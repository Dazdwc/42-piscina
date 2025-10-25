# 🧱 Comando `ln` — Crear enlaces entre archivos

## 🧠 Concepto
El comando **`ln`** sirve para crear **enlaces** entre archivos o directorios.  
Un enlace no es una copia del archivo, sino **otra referencia al mismo contenido**.  

Hay dos tipos principales:

| Tipo | Qué es | Analogía |
|------|--------|-----------|
| **Hard link** | Copia directa del contenido, apuntando al mismo *inode* | 📂 Dos puertas hacia el mismo archivo |
| **Symbolic (soft) link** | Acceso directo que apunta al archivo original | 🪞 Un espejo del archivo real |

---

## ⚙️ Sintaxis general

```bash
ln [opciones] archivo_origen enlace_destino
```

---

## 📘 Ejemplos paso a paso

### 1️⃣ Crear un **hard link**
```bash
ln original.txt copia.txt
```
📎 Ahora `original.txt` y `copia.txt` son **idénticos a nivel de sistema de archivos**.  
Comparten el mismo contenido físico.

- Si modificas uno, el otro cambia también.  
- Si borras `original.txt`, `copia.txt` sigue funcionando.

📖 Compruébalo con:
```bash
ls -li
```
Verás que ambos tienen el mismo **inode**, algo así:
```
12345 -rw-r--r-- 2 dani dani 12 Oct 25 10:00 original.txt
12345 -rw-r--r-- 2 dani dani 12 Oct 25 10:00 copia.txt
```

---

### 2️⃣ Crear un **enlace simbólico (soft link)**
```bash
ln -s original.txt acceso.txt
```
🪞 Crea un acceso directo que apunta a `original.txt`.

- Si borras `original.txt`, el enlace queda **roto** (no funcional).  
- Los soft links **no comparten inode**.

📖 Verifica con `ls -l`:
```
lrwxrwxrwx 1 dani dani 13 Oct 25 10:05 acceso.txt -> original.txt
```

---

### 3️⃣ Enlazar un directorio
```bash
ln -s ~/Documentos ./docs
```
📁 Crea un enlace simbólico llamado `docs` que apunta a tu carpeta `Documentos`.

---

### 4️⃣ Sobrescribir un enlace existente
```bash
ln -sf original_nuevo.txt acceso.txt
```
⚙️ `-f` fuerza la creación aunque `acceso.txt` ya exista.

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-s` | Crea un enlace simbólico (soft link) |
| `-f` | Sobrescribe el enlace si ya existe |
| `-v` | Muestra los enlaces creados |
| `-n` | Evita seguir enlaces simbólicos existentes |

---

## ⚠️ Errores comunes

🚫 **“File exists”**  
> Intentas crear un enlace con un nombre que ya existe.  
💡 Usa `ln -f` para sobrescribir o elimina el antiguo.

🚫 **“No such file or directory”**  
> El archivo de origen no existe.  
💡 Asegúrate de usar rutas correctas o absolutas.

🚫 **Enlace roto (sólo soft links)**  
> El destino fue borrado o movido.  
💡 Verifica con `ls -l`: los enlaces rotos suelen aparecer en rojo o con error al abrirlos.

---

## 🪄 Tips y buenas prácticas

- Verifica los **inodes** con `ls -li`: los hard links comparten número.  
- Usa enlaces simbólicos para proyectos o rutas largas (por ejemplo, `ln -s ~/42/piscina ~/piscina`).  
- Usa rutas **absolutas** (`/home/dani/...`) en soft links si el enlace debe funcionar fuera del directorio actual.  
- En entornos de desarrollo, `ln -s` es muy útil para hacer alias de carpetas.

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Crear hard link | `ln a.txt b.txt` | Ambos archivos apuntan al mismo contenido |
| Crear soft link | `ln -s a.txt enlace.txt` | Enlace simbólico hacia otro archivo |
| Forzar sobrescritura | `ln -sf nuevo.txt enlace.txt` | Reemplaza el enlace existente |
| Enlace a directorio | `ln -s ~/dir ./enlace` | Alias de una carpeta |
| Verificar inodes | `ls -li` | Muestra si dos archivos comparten el mismo inode |

---

> 💬 *“ln es como conectar cables entre archivos: elige si quieres un espejo (soft) o una copia real (hard).”* 🔗  
> Entenderlo te ayudará a moverte como un pro en el sistema de archivos Unix.
