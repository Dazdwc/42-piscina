# 🧩 Ex02 - Creación de estructura de archivos y enlaces en Bash

En este ejercicio aprenderemos a **crear, modificar y relacionar archivos y directorios** según las especificaciones del enunciado.  
Trabajaremos con varios comandos fundamentales de bash 🧠

---

## ⚙️ Comandos que utilizaremos

> - 🪶 **`touch`** → crear archivos vacíos y cambiar su fecha.  
> - ⚖️ **`truncate`** → ajustar el tamaño (peso) de un archivo.  
> - 📦 **`tar`** → comprimir el directorio sin perder formato.  
> - 🔐 **`chmod`** → modificar los permisos (derechos) de los archivos.  
> - 📂 **`ls`** → listar los archivos del directorio.  
> - 🧹 **`rm`** → eliminar archivos innecesarios.  
> - 🏗️ **`mkdir`** → crear directorios.  
> - 🔗 **`ln`** → crear enlaces duros (*hard links*) y simbólicos (*soft links*).  

---

## 🚀 Pasos a seguir

### 1️⃣ Crear los directorios `test0` y `test2`
Si nos fijamos en el enunciado, tanto `test0` como `test2` tienen una **d** al principio de los permisos (`drwx--xr-x`), lo que indica que son **directorios**:

```bash
  mkdir test0 test2
```

---

### 2️⃣ Crear los archivos `test1`, `test3` y `test4`
Estos son archivos normales sin dependencias:

```bash
  touch test1 test3 test4
```

---

### 3️⃣ Crear el enlace simbólico (`test6`)
`test6` es un **soft link** que apunta a `test0`, así que lo creamos con:

```bash
  ln -s test0 test6
```

📎 Esto generará un enlace visible como:
```
    lrwxrwxrwx 1 daz daz 5 Jun 1 22:20 test6 -> test0
```

---

### 4️⃣ Ajustar el peso de los archivos
Modificamos el tamaño de los archivos para que coincida con el enunciado:

```bash
    truncate -s 4 test1
    truncate -s 1 test3
    truncate -s 2 test4
```

---

### 5️⃣ Establecer las fechas de modificación
💡 Cuidado: para `test6` (enlace simbólico) usamos `-h` para **no seguir el enlace** y modificar solo su propia fecha.

```bash
    touch -t 202506012047 test0
    touch -t 202506012146 test1
    touch -t 202506012245 test2
    touch -t 202506012344 test3
    touch -t 202506012343 test4
    touch -h -t 202506012220 test6
```

---

### 6️⃣ Asignar los permisos adecuados
Usamos `chmod` con la notación simbólica para que coincida con el formato del enunciado:

```bash
    chmod u=rwx,g=x,o=rx test0
    chmod u=rwx,g=x,o=r test1
    chmod u=rx,g=x,o=r test2
    chmod u=r,g=,o=r test3
    chmod u=rw,g=r,o=x test4
    chmod u=rwx,g=rx,o=rx test6
```

---

### 7️⃣ Crear el hard link (`test5` ← `test3`)
Como `test3` y `test5` comparten el mismo número de enlaces, `test5` debe ser un **hard link** de `test3`:

```bash
    ln test3 test5
```

📎 Ambos apuntarán al mismo contenido físico en disco y tendrán el mismo tamaño y fecha.

---
## ✅ Resultado final esperado

Un `ls -l` debería exactamente lo mismo, a excepción de las XX que no importará el valor:

```bash
    ls -ls | grep test
```

```
drwx--xr-x 2 XX XX XX Jun 1 20:47 test0
-rwx--xr-- 1 XX XX  4 Jun 1 21:46 test1
dr-x---r-- 2 XX XX XX Jun 1 22:45 test2
-r-----r-- 2 XX XX  1 Jun 1 23:44 test3
-rw-r----x 1 XX XX  2 Jun 1 23:43 test4
-r-----r-- 2 XX XX  1 Jun 1 23:44 test5
lrwxrwxrwx 1 XX XX  5 Jun 1 22:20 test6 -> test0
```

### 8️⃣ Comprimir todo en un archivo `.tar`
Comprimimos el contenido de la carpeta actual (todos los `test*`) en un solo archivo `exo2.tar`:

```bash
    tar -cf exo2.tar *
```

💡 `-c` crea el archivo y `-f` indica el nombre del resultado.

---

### 9️⃣ Limpiar el directorio
Una vez comprimido, eliminamos todos los archivos para dejar la carpeta limpia como pide el enunciado:

```bash
    rm -fr test*
```

🧹 Así solo quedará tu archivo comprimido `exo2.tar` listo para subir a la Intra.

---

> 💬 *Consejo:* Si algo no encaja con el enunciado, usa `ls -l` para comprobar permisos, fechas o tamaños antes de volver a empaquetar el `.tar`.  
