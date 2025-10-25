# 🔐 Comando `chmod` — Cambiar permisos de archivos y directorios

## 🧠 Concepto
El comando **`chmod`** (*change mode*) permite **modificar los permisos** de acceso de archivos y carpetas.  
En sistemas Unix, cada archivo tiene tres tipos de permisos:

| Tipo de usuario | Significado |
|------------------|-------------|
| **u** | Usuario (el propietario del archivo) |
| **g** | Grupo (usuarios del mismo grupo) |
| **o** | Otros (todos los demás) |

Y tres tipos de permisos:

| Permiso | Letra | Significado |
|----------|--------|-------------|
| **Lectura** | `r` | Ver el contenido del archivo |
| **Escritura** | `w` | Modificar o borrar el archivo |
| **Ejecución** | `x` | Ejecutar el archivo (si es script o binario) |

---

## ⚙️ Sintaxis general

```bash
chmod [opciones] modo archivo
```

El **modo** puede expresarse de dos formas:  
1. **Simbólica:** usando letras (`u`, `g`, `o`, `+`, `-`, `=`).  
2. **Numérica:** usando valores binarios (`r=4`, `w=2`, `x=1`).

---

## 📘 Ejemplos paso a paso

### 1️⃣ Añadir permisos simbólicamente

#### Dar permiso de ejecución al usuario
```bash
chmod u+x script.sh
```
➡️ El propietario ahora puede ejecutar el archivo.

#### Quitar permiso de lectura al grupo
```bash
chmod g-r archivo.txt
```
➡️ El grupo ya no podrá leerlo.

#### Asignar permisos exactos
```bash
chmod u=rwx,g=rx,o=r archivo.txt
```
📋 Usuario con todos los permisos, grupo con lectura y ejecución, otros solo lectura.

---

### 2️⃣ Asignar permisos con valores numéricos

| Permiso | Valor |
|----------|--------|
| `r` | 4 |
| `w` | 2 |
| `x` | 1 |

Se suman los valores de cada categoría (**u**, **g**, **o**).

| Permisos | Modo numérico |
|-----------|----------------|
| `rwx` | 7 |
| `rw-` | 6 |
| `r-x` | 5 |
| `r--` | 4 |
| `---` | 0 |

Ejemplo:
```bash
chmod 755 script.sh
```
🔢 Equivale a:
- Usuario → `rwx` (7)  
- Grupo → `r-x` (5)  
- Otros → `r-x` (5)

Salida con `ls -l`:
```
-rwxr-xr-x 1 dani dani 1234 Oct 25 11:00 script.sh
```

---

### 3️⃣ Quitar todos los permisos a otros
```bash
chmod o= archivo.txt
```
🚫 El resto de usuarios no podrá ni leer, ni escribir, ni ejecutar.

---

### 4️⃣ Permisos de carpetas
```bash
chmod 700 carpeta/
```
📁 Solo el propietario puede acceder.  
💡 Sin `x`, no podrás entrar (`cd carpeta/` dará error).

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-R` | Aplica permisos de forma recursiva a todas las subcarpetas |
| `-v` | Muestra detalles de los cambios |
| `--reference=archivo` | Copia los permisos de otro archivo |

Ejemplo:
```bash
chmod -R 755 proyecto/
```

---

## ⚠️ Errores comunes

🚫 **“Permission denied”**  
> Intentas cambiar permisos de un archivo sin ser su propietario.  
💡 Usa `sudo chmod` si tienes privilegios.

🚫 **“Operation not permitted”**  
> Algunos archivos del sistema están protegidos.  
💡 No fuerces permisos en rutas del sistema (`/usr`, `/bin`, etc.).

🚫 **Carpetas sin permiso de ejecución (`x`)**  
> Sin `x`, no puedes entrar ni listar contenido.  
💡 Asegúrate de usar `rwx` al menos para ti (`u`).

---

## 🪄 Tips y buenas prácticas

- Usa `ls -l` para ver permisos actuales antes y después del cambio.  
- Evita usar `chmod 777` (todos los permisos para todos). Es inseguro.  
- Para carpetas privadas, usa `chmod 700 carpeta`.  
- Para proyectos compartidos en 42, `chmod 755` suele ser el valor estándar.  
- Para scripts ejecutables, recuerda:
  ```bash
  chmod +x nombre_del_script.sh
  ```

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Dar ejecución al usuario | `chmod u+x archivo` | Usuario puede ejecutar |
| Quitar lectura al grupo | `chmod g-r archivo` | Grupo no puede leer |
| Permisos completos para todos | `chmod 777 archivo` | ⚠️ Todos pueden todo |
| Modo común de scripts | `chmod 755 archivo` | Ejecución segura estándar |
| Aplicar recursivamente | `chmod -R 755 carpeta` | A carpetas y subarchivos |
| Copiar permisos de otro archivo | `chmod --reference=a.txt b.txt` | Igualar permisos |

---

> 💬 *“chmod es la llave que abre (o cierra) las puertas de tus archivos.”* 🔑  
> Dominarlo te ayuda a mantener seguridad y control en cualquier entorno Unix.
