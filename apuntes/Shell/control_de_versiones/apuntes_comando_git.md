# 🧬 Comando `git` — Control de versiones distribuido

## 🧠 Concepto
`git` es un sistema de control de versiones que permite **guardar el historial de cambios**, comparar versiones y trabajar en equipo.  
En 42 y en cualquier entorno profesional, es esencial para mantener tu progreso organizado y seguro.

---

## ⚙️ Sintaxis general

```bash
git [comando] [opciones]
```

---

## 📘 Ejemplos esenciales

### 1️⃣ Iniciar un repositorio
```bash
git init
```
Crea un repositorio en el directorio actual.  
Git comenzará a rastrear los cambios dentro de esa carpeta.

---

### 2️⃣ Ver el estado actual
```bash
git status
```
Muestra los archivos modificados, nuevos o eliminados desde el último commit.

---

### 3️⃣ Añadir archivos al área de preparación
```bash
git add archivo.txt
git add .
```
El primer comando añade un archivo concreto.  
El segundo (`.`) añade todos los cambios del directorio actual.

---

### 4️⃣ Confirmar los cambios (commit)
```bash
git commit -m "mensaje descriptivo"
```
Guarda una versión del proyecto con un mensaje identificativo.  
Ejemplo:
> `git commit -m "añadido script de comprobación para ex04"`

---

### 5️⃣ Ver historial de commits
```bash
git log
```
📜 Muestra los commits realizados con fecha, autor y hash.  
Pulsa `q` para salir del historial.

---

### 6️⃣ Clonar un repositorio existente
```bash
git clone https://github.com/usuario/repositorio.git
```
Copia un repositorio remoto a tu máquina local.

---

### 7️⃣ Descargar actualizaciones (pull)
```bash
git pull
```
Descarga los cambios más recientes desde el repositorio remoto.

---

### 8️⃣ Subir tus cambios (push)
```bash
git push
```
Envía tus commits locales al repositorio remoto.

---

### 9️⃣ Ignorar archivos con `.gitignore`
Crea un archivo `.gitignore` para excluir archivos temporales o de sistema.

📄 Ejemplo de `.gitignore`:
```
*.o
*.out
temp/
```

---

## ⚙️ Opciones comunes

| Comando | Descripción |
|----------|--------------|
| `init` | Inicializa un repositorio nuevo |
| `add` | Añade archivos al área de preparación |
| `commit` | Guarda los cambios con un mensaje |
| `status` | Muestra el estado actual |
| `log` | Muestra el historial de commits |
| `clone` | Copia un repositorio remoto |
| `pull` | Descarga actualizaciones |
| `push` | Sube tus cambios |
| `diff` | Muestra diferencias entre commits |
| `ls-files` | Lista los archivos rastreados |

---

## ⚠️ Errores comunes

🚫 **“nothing to commit, working tree clean”**  
> No hay cambios nuevos para guardar.  
💡 Asegúrate de haber modificado o añadido archivos antes de hacer `git commit`.

🚫 **“fatal: not a git repository”**  
> No estás en una carpeta inicializada con `git init`.  
💡 Usa `cd` para entrar en tu proyecto o ejecuta `git init`.

🚫 **“Updates were rejected because...”**  
> Tu rama local está detrás del remoto.  
💡 Ejecuta:
```bash
git pull --rebase
git push
```

---

## 🪄 Tips y buenas prácticas

- Haz **commits pequeños y frecuentes**.  
- Usa mensajes claros y descriptivos.  
- Nunca subas archivos binarios (usa `.gitignore`).  
- Antes de subir cambios (`push`), revisa con `git status` y `git diff`.  
- Usa `git log --oneline` para ver un historial más limpio.

> 💡 **TIP – Cómo empezar un proyecto en 42 con Git**
>
> En la 42 **no necesitas ejecutar `git init`**, porque el repositorio ya está creado automáticamente en la Intra.  
> Lo que haremos será **clonarlo**, trabajar dentro de él y subir los cambios cuando terminemos.  
>
> 🧩 **Pasos para empezar y subir tu trabajo:**
>
> 1️⃣ **Clona el repositorio del proyecto:**
> ```bash
> git clone REPOSITORIO_DE_LA_INTRA_DEL_PROYECTO nombre_que_le_quieras_dar_al_directorio
> ```
> 📎 Te aparecerá un aviso de que el repositorio está vacío — ¡eso es normal!
>
> 2️⃣ **Accede al directorio del proyecto:**
> ```bash
> cd nombre_del_directorio
> ```
>
> 3️⃣ **Crea la carpeta del ejercicio:**
> ```bash
> mkdir ex00
> ```
> (o la que toque en ese momento, por ejemplo `ex01`, `ex02`, etc.)
>
> 4️⃣ **Añade los archivos al “paquete” de cambios:**
> ```bash
> git add .
> ```
>
> 5️⃣ **Crea un commit con un mensaje descriptivo:**
> ```bash
> git commit -m "mensaje explicando lo que hiciste"
> ```
> 💬 Ejemplo: `"resuelto ex00 con z creado correctamente"`
>
> 6️⃣ **Comprueba que todo está correcto:**
> ```bash
> git status
> ```
> Si no aparecen archivos pendientes, todo está listo para subir.
>
> 7️⃣ **Sube los cambios al repositorio remoto:**
> ```bash
> git push
> ```
>
> 8️⃣ **(Opcional)**: Verifica que tus cambios se subieron correctamente.  
> Puedes hacerlo clonando el repo en otra carpeta y comprobando que ya contiene tus ejercicios:
> ```bash
> git clone REPOSITORIO_DE_LA_INTRA_DEL_PROYECTO comprobacion_repo
> ```
>
> 🚀 ¡Listo! Ya tienes tu proyecto sincronizado y tus progresos guardados en el repositorio de la Intra.


## 🎯 Resumen

| Acción | Comando |
|--------|----------|
| Iniciar repo | `git init` |
| Ver estado | `git status` |
| Añadir cambios | `git add .` |
| Confirmar cambios | `git commit -m "msg"` |
| Ver historial | `git log` |
| Clonar repo | `git clone URL` |
| Descargar cambios | `git pull` |
| Subir cambios | `git push` |
| Ignorar archivos | `.gitignore` |

---

> 💬 *“Git no solo guarda tu código, guarda tu historia como programador.”*  
> — Dominarlo desde la Piscina te prepara para cualquier entorno real.

