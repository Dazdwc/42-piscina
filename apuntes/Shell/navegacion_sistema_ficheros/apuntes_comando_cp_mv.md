# 📂 Comandos `cp` y `mv` — Copiar y mover archivos o carpetas

## 🧠 Concepto
Los comandos **`cp`** (*copy*) y **`mv`** (*move*) se usan para **duplicar o mover archivos y directorios** dentro del sistema.  
En la piscina los usarás constantemente para organizar tus ejercicios, copiar plantillas o renombrar archivos sin perder tu progreso 🏊‍♂️.

- `cp` → copia archivos o carpetas (el original se mantiene).  
- `mv` → mueve o renombra archivos o carpetas (el original desaparece de su ubicación anterior).

---

## ⚙️ Sintaxis general

```bash
cp [opciones] origen destino
mv [opciones] origen destino
```

💡 Si `destino` es un **directorio**, el archivo se copia o mueve dentro de él.  
Si `destino` es un **nombre nuevo**, el archivo se copia/mueve y renombra.

---

## 📘 Ejemplos paso a paso

### 🧱 `cp` — Copiar archivos

#### 1️⃣ Copiar un archivo
```bash
cp hola.txt copia.txt
```
📄 Crea un duplicado de `hola.txt` llamado `copia.txt` en el mismo directorio.

#### 2️⃣ Copiar un archivo a otra carpeta
```bash
cp hola.txt ~/piscina/shell00/ex01/
```
📦 Copia `hola.txt` dentro de la carpeta `ex01`.

#### 3️⃣ Copiar una carpeta completa
```bash
cp -r shell00 shell00_backup
```
🗂️ La opción `-r` (o `--recursive`) copia todo el contenido de la carpeta, incluyendo subcarpetas y archivos.

#### 4️⃣ Copiar múltiples archivos a la vez
```bash
cp archivo1.txt archivo2.txt ~/piscina/shell01/
```
📂 Todos los archivos indicados se copian al destino.

---

### 🚚 `mv` — Mover o renombrar archivos

#### 1️⃣ Mover un archivo
```bash
mv hola.txt ~/piscina/shell01/
```
🏃‍♂️ Mueve `hola.txt` a la carpeta `shell01` (ya no estará en el lugar original).

#### 2️⃣ Renombrar un archivo
```bash
mv hola.txt adios.txt
```
✏️ Cambia el nombre de `hola.txt` a `adios.txt` sin moverlo de sitio.

#### 3️⃣ Mover una carpeta completa
```bash
mv shell00 shell_backup
```
📦 Cambia el nombre de la carpeta `shell00` o la mueve si `shell_backup` ya existe.

#### 4️⃣ Mover varios archivos
```bash
mv *.txt ~/piscina/shell02/
```
📁 Mueve todos los archivos `.txt` al directorio indicado.

---

## ⚙️ Opciones comunes

| Opción | Descripción | Disponible en |
|--------|--------------|----------------|
| `-r` | Copia/mueve carpetas de forma recursiva | `cp`, `mv` |
| `-i` | Pide confirmación antes de sobrescribir archivos | ambos |
| `-f` | Fuerza la acción sin preguntar | ambos |
| `-v` | Muestra qué está haciendo | ambos |
| `-u` | Copia/mueve solo si el origen es más nuevo | `cp` |

Ejemplo:
```bash
cp -vi hola.txt ~/piscina/shell00/
```
📋 Verás mensajes tipo:
```
'hola.txt' -> '/home/dani/piscina/shell00/hola.txt'
```

---

## ⚠️ Errores comunes

🚫 **“No such file or directory”**  
> El archivo o carpeta no existe, o escribiste mal la ruta.  
💡 Usa `ls` para comprobar y autocompleta con `TAB`.

🚫 **“Permission denied”**  
> No tienes permisos para leer o escribir en esa ruta.  
💡 Verifica con `ls -l` o usa `sudo` (si procede).

🚫 **“Omitting directory” (en `cp`)**  
> Estás intentando copiar una carpeta sin `-r`.  
💡 Añade la opción recursiva:
```bash
cp -r carpeta destino/
```

🚫 **Sobrescribir sin querer**  
> Si copias o mueves sobre un archivo con el mismo nombre, se sobrescribe.  
💡 Usa `-i` para que te pida confirmación antes.

---

## 🪄 Tips y buenas prácticas

- Usa `cp -r` y `mv -i` por seguridad mientras aprendes.  
- Combínalos con `pwd` y `ls` para confirmar ubicaciones antes de mover nada.  
- Usa `cp -v` o `mv -v` para ver en pantalla lo que está ocurriendo.  
- En scripts o ejercicios:
  ```bash
  cp ex00/test.txt ex01/
  mv ex01/test.txt ex01/test_final.txt
  ```
  así controlas el flujo del trabajo.

- Si estás haciendo copias de seguridad, incluye la fecha:
  ```bash
  cp -r shell00 shell00_$(date "+%Y%m%d_%H%M")
  ```

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Copiar archivo | `cp origen destino` | Duplica un archivo |
| Copiar carpeta | `cp -r carpeta destino` | Copia todo su contenido |
| Copiar varios archivos | `cp archivo1 archivo2 destino/` | Copia múltiples |
| Mover archivo | `mv origen destino` | Lo traslada o renombra |
| Renombrar archivo | `mv viejo.txt nuevo.txt` | Cambia su nombre |
| Evitar sobrescribir | `cp -i` o `mv -i` | Pide confirmación |
| Ver progreso | `cp -v` o `mv -v` | Muestra qué hace |

---

> 💬 *“cp es el duplicador, mv el transportista. Juntos, te ayudarán a mantener tus ejercicios ordenados y seguros.”* 📦
