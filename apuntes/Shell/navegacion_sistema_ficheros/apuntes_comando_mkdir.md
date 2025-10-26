# 📁 Comando `mkdir` — Crear directorios en la terminal

## 🧠 Concepto
El comando **`mkdir`** (*make directory*) sirve para **crear carpetas (directorios)** en tu sistema.  
Es uno de los primeros comandos que usarás en la piscina 🏊‍♂️, ya que muchos ejercicios te pedirán crear estructuras de directorios con nombres específicos.

---

## ⚙️ Sintaxis general

```bash
mkdir [opciones] nombre_directorio
```

Puedes crear **una o varias carpetas a la vez**, y con opciones para generar rutas completas.

---

## 📘 Ejemplos paso a paso

### 1️⃣ Crear un solo directorio
```bash
mkdir ex00
```
📂 Crea una carpeta llamada `ex00` en el directorio actual.

---

### 2️⃣ Crear varios directorios a la vez
```bash
mkdir ex01 ex02 ex03
```
🗂️ Crea tres carpetas al mismo tiempo: `ex01`, `ex02`, `ex03`.

---

### 3️⃣ Crear una estructura de carpetas anidadas
```bash
mkdir -p proyectos/shell00/ex00
```
🏗️ La opción `-p` (*parents*) crea todas las carpetas intermedias si no existen.  
Sin `-p`, este comando daría error si `proyectos/` no existiera.

---

### 4️⃣ Crear una carpeta en otra ubicación
```bash
mkdir ~/piscina/shell01
```
📦 Crea la carpeta `shell01` dentro de la ruta absoluta `/home/tu_usuario/piscina/`.

---

### 5️⃣ Comprobar el resultado
```bash
ls -l
```
🔍 Lista el contenido y verás la carpeta recién creada.

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-p` | Crea rutas intermedias automáticamente |
| `-v` | Muestra un mensaje por cada carpeta creada |
| `-m` | Define permisos específicos al crearla |

Ejemplo con permisos:
```bash
mkdir -m 755 ex04
```
📜 Crea `ex04` con permisos `rwxr-xr-x`.

---

## ⚠️ Errores comunes

🚫 **“File exists”**  
> Ya existe una carpeta o archivo con ese nombre.  
💡 Usa `ls` para comprobar antes o `-p` si estás creando una ruta.

🚫 **“Permission denied”**  
> No tienes permisos para crear en esa ubicación.  
💡 Verifica con `pwd` que estás en tu carpeta de trabajo o usa `sudo` si es necesario (aunque en la piscina no deberías).

🚫 **Rutas con espacios sin comillas**  
> Si el nombre de la carpeta tiene espacios, usa comillas:
```bash
mkdir "Mi Carpeta"
```

---

## 🪄 Tips y buenas prácticas

- Usa **rutas relativas** mientras trabajas dentro de tu carpeta de ejercicios (`~/piscina/shell00`).  
- Usa **rutas absolutas** (`/home/...`) solo si sabes bien dónde estás creando la carpeta.  
- Para evitar errores, combina `pwd` + `ls` antes de crear.  
- Si necesitas crear toda la estructura de un proyecto:
  ```bash
  mkdir -pv proyecto/{docs,src,tests}
  ```
  📦 Crea varias carpetas con estructura interna (usa llaves `{}` y `-p`).

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Crear carpeta | `mkdir nombre` | Crea una carpeta |
| Crear varias | `mkdir dir1 dir2` | Crea varias carpetas |
| Crear estructura completa | `mkdir -p ruta/larga/ex00` | Genera todas las carpetas intermedias |
| Ver mensajes | `mkdir -v nombre` | Muestra confirmación |
| Crear con permisos | `mkdir -m 755 nombre` | Define permisos al crear |

---

> 💬 *“mkdir es el primer ladrillo de tu edificio digital: úsalo para dar forma a tus proyectos desde cero.”* 🧱
