# ✨ Comando `touch` — Crear archivos o actualizar fechas

## 🧠 Concepto
El comando **`touch`** se usa para **crear archivos vacíos** o **actualizar su fecha de modificación y acceso**.  
Es una de las formas más rápidas de generar archivos nuevos o de “tocar” archivos existentes para cambiar su timestamp.

En la Piscina, `touch` se usa constantemente para preparar archivos antes de trabajar con ellos.

---

## ⚙️ Sintaxis general

```bash
touch [opciones] archivo
```

Si el archivo no existe, se crea vacío.  
Si ya existe, su fecha de modificación se actualiza al momento actual.

---

## 📘 Ejemplos paso a paso

### 1️⃣ Crear un archivo vacío
```bash
touch archivo.txt
```
📄 Crea un archivo vacío llamado `archivo.txt`.

---

### 2️⃣ Crear varios archivos a la vez
```bash
touch ex00 ex01 ex02
```
🧩 Crea tres archivos vacíos al instante.

---

### 3️⃣ Actualizar la fecha de modificación
```bash
touch archivo.txt
```
🕓 Si el archivo ya existía, su contenido no cambia, pero su **fecha de última modificación** sí.

---

### 4️⃣ Cambiar la fecha y hora manualmente
```bash
touch -t 202510251230 archivo.txt
```
🗓️ Cambia la fecha de modificación a **25 de octubre de 2025, 12:30h**.

---

### 5️⃣ Copiar la fecha de otro archivo
```bash
touch -r original.txt copia.txt
```
📋 `copia.txt` pasará a tener la misma fecha y hora que `original.txt`.

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-c` | No crea el archivo si no existe |
| `-r archivo` | Copia la fecha de otro archivo |
| `-t AAAAMMDDhhmm` | Asigna una fecha y hora concretas |

---

## ⚠️ Errores comunes

🚫 **“Permission denied”**  
> No tienes permiso para crear archivos en esa carpeta.  
💡 Usa una carpeta de usuario o comprueba permisos con `ls -l`.

🚫 **“touch: cannot touch”**  
> La ruta o el nombre del archivo no existe.  
💡 Usa `mkdir` antes si la carpeta no existe.

🚫 **Fecha inválida con `-t`**  
> El formato de fecha no es correcto.  
💡 Debe ser `AAAAMMDDhhmm` (ejemplo: `202510251230`).

---

## 🪄 Tips y buenas prácticas

- Para crear una estructura de ejercicios rápidamente:
  ```bash
  touch ex{00..09}
  ```
  🔁 Crea `ex00` hasta `ex09` automáticamente.
- Puedes combinarlo con `truncate` si necesitas crear un archivo con tamaño específico.
- Usa `ls -l` o `stat archivo.txt` para comprobar el cambio de fecha.

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Crear archivo vacío | `touch archivo.txt` | Crea o actualiza archivo |
| Crear varios archivos | `touch ex00 ex01 ex02` | Múltiples archivos |
| Cambiar fecha manualmente | `touch -t 202510251230 archivo.txt` | Establece fecha y hora |
| Copiar fecha de otro archivo | `touch -r a.txt b.txt` | Igualar timestamps |
| Evitar crear si no existe | `touch -c archivo.txt` | Solo actualiza si existe |

---

> 💬 *“Touch es como un clic en la terminal: crea o actualiza sin hacer ruido.”* 🕓  
> Apréndelo bien, porque lo usarás en casi todos los proyectos.
