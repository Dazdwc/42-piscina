# 🌍 Comandos `env` y `export` — Variables de entorno

## 🧠 Concepto
Los comandos **`env`** y **`export`** sirven para **ver, crear y gestionar variables de entorno**.  
Estas variables son valores que tu sistema o tus programas utilizan para funcionar (por ejemplo, el usuario actual, el PATH donde buscar comandos, etc.).

En la **piscina**, entender `env` y `export` te ayuda a configurar el entorno correctamente y a entender por qué algo “funciona en un sitio pero no en otro”.

---

## ⚙️ Sintaxis general

```bash
env [comando]
export NOMBRE=valor
```

---

## 📘 Ejemplos paso a paso

### 1️⃣ Ver todas las variables de entorno
```bash
env
```
📜 Muestra una lista de todas las variables disponibles.

Ejemplo:
```
USER=dani
HOME=/home/dani
PATH=/usr/local/bin:/usr/bin:/bin
PWD=/home/dani/piscina
```
💡 Son pares `NOMBRE=valor`.

---

### 2️⃣ Mostrar el valor de una variable concreta
```bash
echo $HOME
```
Salida:
```
/home/dani
```
🧠 Las variables se leen anteponiendo el símbolo `$` a su nombre.

---

### 3️⃣ Crear una variable temporal
```bash
export MI_NOMBRE="Dani Z"
```
y luego:
```bash
echo $MI_NOMBRE
```
Salida:
```
Dani Z
```
✨ Esa variable solo existirá **mientras dure la sesión actual** de la terminal.

---

### 4️⃣ Crear una variable y usarla en una línea
```bash
MI_DIR="/home/dani/piscina" && cd $MI_DIR
```
📂 Guarda una ruta en una variable y úsala inmediatamente.

---

### 5️⃣ Eliminar una variable de entorno
```bash
unset MI_NOMBRE
```
💨 Borra la variable actual.

---

### 6️⃣ Ejecutar un comando con una variable temporal
```bash
env VAR_TEMP="valor" comando
```
Ejemplo:
```bash
env USERNAME="tester" echo $USERNAME
```
📦 Ejecuta el comando con esa variable, sin guardarla en el entorno permanente.

---

## ⚙️ Diferencia entre `env` y `export`

| Comando | Descripción |
|----------|--------------|
| `env` | Muestra o ejecuta comandos con variables temporales |
| `export` | Crea o modifica variables persistentes en la sesión actual |
| `unset` | Elimina una variable |

🔹 **`env`** no cambia tu entorno, solo lo usa temporalmente.  
🔹 **`export`** modifica tu entorno de trabajo actual.  

---

## 🧩 Ejemplos prácticos

### Guardar tu carpeta actual
```bash
export PISCINA=$(pwd)
```
Luego puedes volver fácilmente:
```bash
cd $PISCINA
```

### Añadir una ruta al PATH
```bash
export PATH=$PATH:/home/dani/scripts
```
💡 Esto le dice al sistema que busque comandos también en `/home/dani/scripts`.

---

## ⚙️ Variables importantes que deberías conocer

| Variable | Descripción | Ejemplo |
|-----------|--------------|----------|
| `USER` | Usuario actual | `dani` |
| `HOME` | Carpeta principal | `/home/dani` |
| `PWD` | Carpeta actual | `/home/dani/piscina` |
| `PATH` | Rutas donde se buscan los comandos | `/usr/bin:/bin:...` |
| `SHELL` | Shell actual | `/bin/bash` |
| `LANG` | Idioma del sistema | `en_US.UTF-8` |

---

## ⚠️ Errores comunes

🚫 **“command not found”**  
> El comando no está en el PATH.  
💡 Verifica con `echo $PATH` o añade la carpeta correcta con `export PATH=$PATH:/ruta`.

🚫 **Variable no disponible en otro terminal**  
> Las variables creadas con `export` no son permanentes.  
💡 Si cierras la sesión, se borran.  
Para hacerlas permanentes, añádelas al archivo `~/.bashrc`.

🚫 **Espacios sin comillas**  
> Si el valor tiene espacios, usa comillas:  
```bash
export NOMBRE="Dani Z"
```

---

## 🪄 Tips y buenas prácticas

- Usa `env` para **probar valores sin afectar tu sesión**.  
- Añade variables permanentes en tu archivo `~/.bashrc`:
  ```bash
  export EDITOR=vim
  ```
- Comprueba si una variable existe:
  ```bash
  echo ${NOMBRE:-"No definida"}
  ```
- En scripts, siempre cita las variables:
  ```bash
  echo "$MI_VARIABLE"
  ```
  así evitas errores con espacios o saltos.

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Ver entorno completo | `env` | Lista todas las variables |
| Ver una variable | `echo $VAR` | Muestra su valor |
| Crear variable temporal | `export VAR=valor` | Disponible en esta sesión |
| Eliminar variable | `unset VAR` | Borra del entorno |
| Añadir al PATH | `export PATH=$PATH:/nueva/ruta` | Extiende rutas de comandos |
| Crear variable solo para un comando | `env VAR=valor comando` | Variable temporal |

---

> 💬 *“env y export son los arquitectos invisibles de tu sistema: crean el entorno donde todo ocurre.”* 🌍  
> Entenderlos bien te da poder para controlar qué, cómo y dónde se ejecuta cada comando.
