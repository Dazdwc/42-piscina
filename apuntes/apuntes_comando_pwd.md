# 📍 Comando `pwd` — Mostrar el directorio actual

## 🧠 Concepto
El comando **`pwd`** (*print working directory*) muestra la **ruta absoluta** del directorio en el que te encuentras actualmente dentro del sistema de archivos.

Es uno de los comandos más sencillos, pero también más usados, ya que en la **piscina** te servirá constantemente para **saber en qué carpeta estás trabajando** antes de crear, mover o ejecutar archivos.

---

## ⚙️ Sintaxis general

```bash
pwd [opciones]
```

Normalmente se usa sin opciones, pero algunas versiones admiten parámetros como `-L` y `-P`.

---

## 📘 Ejemplos paso a paso

### 1️⃣ Ver tu ubicación actual
```bash
pwd
```
📍 Muestra algo como:
```
/home/dani/piscina/shell00/ex00
```
💡 Esto te indica la ruta completa desde la raíz (`/`) hasta tu carpeta actual.

---

### 2️⃣ Diferencia entre rutas absolutas y relativas

| Tipo | Ejemplo | Descripción |
|------|----------|-------------|
| **Absoluta** | `/home/dani/piscina/shell00/ex00` | Empieza desde la raíz `/` |
| **Relativa** | `../ex01` | Relativa al directorio actual |

💡 `pwd` siempre muestra **la ruta absoluta**, sin importar cómo llegaste ahí.

---

### 3️⃣ Verificar desde cualquier ubicación
```bash
cd ~/piscina/shell01
pwd
```
Salida:
```
/home/dani/piscina/shell01
```
🧭 Perfecto para comprobar si estás en la carpeta correcta antes de ejecutar o copiar archivos.

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-L` | Muestra la ruta lógica (sigue enlaces simbólicos) |
| `-P` | Muestra la ruta física (resuelve enlaces simbólicos reales) |

Ejemplo:
```bash
pwd -P
```
📂 Te mostrará la ruta real en disco, no la del enlace simbólico.

---

## ⚠️ Errores comunes

🚫 **“No such file or directory”**  
> Raro en `pwd`, pero puede aparecer si cambiaste a un directorio eliminado.  
💡 Usa `cd ~` para volver a tu carpeta principal.

🚫 **Ruta confusa con enlaces simbólicos**  
> Si ves rutas raras (por ejemplo `/tmp/../piscina`), usa `pwd -P` para resolverlas correctamente.

---

## 🪄 Tips y buenas prácticas

- Usa `pwd` antes de comandos como `cp`, `mv`, `rm` para **asegurarte de no trabajar en la carpeta equivocada** 😅.  
- Si trabajas con scripts, puedes guardar la ruta actual en una variable:
  ```bash
  ruta_actual=$(pwd)
  echo "Estás en: $ruta_actual"
  ```
- Combínalo con `ls` para ver el contexto completo:
  ```bash
  echo "Ubicación actual:" && pwd && ls
  ```

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Mostrar directorio actual | `pwd` | Ruta absoluta del directorio actual |
| Mostrar ruta física | `pwd -P` | Resuelve enlaces simbólicos |
| Mostrar ruta lógica | `pwd -L` | Muestra ruta con enlaces simbólicos |
| Guardar en variable | `ruta=$(pwd)` | Guarda la ubicación actual |

---

> 💬 *“pwd es tu brújula en la terminal. Nunca pierdas el norte antes de ejecutar un comando.”* 🧭
