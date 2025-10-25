# ✍️ Comando `vim` — Editar archivos como un pro en la piscina

## 🧠 Concepto
**Vim** es un editor de texto modal muy usado en sistemas Unix.  
Su nombre viene de *Vi IMproved* (una versión mejorada del editor `vi`).  
Es el editor principal en la **piscina de 42**, así que dominarlo desde el principio es esencial 🏊‍♂️.

Lo que lo hace diferente es que **tiene modos**:  
- **Modo normal** → navegar, borrar, copiar, pegar.  
- **Modo inserción** → escribir texto.  
- **Modo comando** → guardar, salir, buscar, ejecutar acciones.

---

## ⚙️ Sintaxis general
```bash
vim [opciones] archivo
```
Ejemplo:
```bash
vim ex00/hello.sh
```

---

## 📘 Ejemplos paso a paso

### 1️⃣ Abrir un archivo
```bash
vim ex00/hello.sh
```
Abre el archivo (o lo crea si no existe).  
Por defecto entrarás en **modo normal**.

---

### 2️⃣ Entrar en modo inserción
Pulsa `i`  
📝 Ahora puedes escribir texto libremente.  
Cuando termines, presiona `Esc` para volver al modo normal.

---

### 3️⃣ Guardar y salir
En modo normal, escribe:
```vim
:wq
```
💾 Guarda (*write*) y sale (*quit*).  
También puedes usar `:x` o `ZZ` (mayúsculas).

---

### 4️⃣ Salir sin guardar
```vim
:q!
```
❌ Sale sin guardar los cambios.

---

### 5️⃣ Navegar dentro del archivo
| Movimiento | Acción |
|-------------|---------|
| `h` | izquierda |
| `j` | abajo |
| `k` | arriba |
| `l` | derecha |
| `w` | salto al inicio de la siguiente palabra |
| `$` | final de línea |
| `0` | inicio de línea |
| `gg` | inicio del archivo |
| `G` | final del archivo |

---

### 6️⃣ Copiar, cortar y pegar
| Acción | Comando | Descripción |
|--------|----------|-------------|
| Copiar línea | `yy` | copia la línea actual |
| Cortar línea | `dd` | corta la línea actual |
| Pegar después del cursor | `p` | pega el texto copiado |
| Pegar antes del cursor | `P` | pega antes del cursor |

---

### 7️⃣ Buscar texto
En modo normal:
```vim
/palabra
```
🔍 Busca hacia adelante la palabra indicada.  
Usa `n` para siguiente coincidencia, `N` para anterior.

---

### 8️⃣ Deshacer y rehacer
```vim
u       # deshacer
Ctrl + r  # rehacer
```

---

## ⚙️ Opciones comunes al abrir
| Opción | Descripción |
|--------|-------------|
| `-R` | abre en modo solo lectura |
| `+n` | abre directamente en la línea n |
| `+` | abre al final del archivo |
| `-c 'comando'` | ejecuta un comando al abrir |

Ejemplo:
```bash
vim +10 script.sh
```
📍 Abre directamente en la línea 10.

---

## ⚠️ Errores comunes

🚫 **“¿Por qué no puedo escribir?”**  
> Estás en modo normal. Pulsa `i` para entrar en modo inserción.

🚫 **“He escrito cosas raras sin querer”**  
> Probablemente pulsaste teclas en modo normal. Presiona `Esc` para volver a un estado seguro.

🚫 **“No se guardaron mis cambios”**  
> Debes usar `:w` o `:wq` para guardar antes de salir.

---

## 🪄 Tips y buenas prácticas

- Activa números de línea con:
  ```vim
  :set number
  ```
- Activa colores de sintaxis:
  ```vim
  :syntax on
  ```
- Guarda sin salir:
  ```vim
  :w
  ```
- Abre varios archivos:
  ```bash
  vim file1 file2
  ```
  Usa `:n` y `:prev` para moverte entre ellos.

- Personaliza tu entorno en `~/.vimrc` (cuando avances).

💡 En este [**Vim Cheat Sheet**](https://vim.rtorr.com/lang/es_es) encontrarás todos los atajos y comandos visuales de Vim, perfectamente organizados.

---

## 🎯 Resumen rápido

| Acción | Comando |
|--------|----------|
| Entrar en modo inserción | `i` |
| Salir al modo normal | `Esc` |
| Guardar y salir | `:wq` |
| Salir sin guardar | `:q!` |
| Copiar línea | `yy` |
| Cortar línea | `dd` |
| Pegar | `p` |
| Buscar texto | `/palabra` |
| Deshacer | `u` |
| Rehacer | `Ctrl + r` |

---

> 💬 *“Vim no es difícil, solo diferente. Cuando lo dominas, se convierte en una extensión de tus manos.”* 🖐️
