# 🧩 EX06: git_ignore.sh

En este ejercicio aprenderemos a **crear un script ejecutable en Bash** que muestre **los archivos ignorados por Git** dentro del repositorio actual.  
Usaremos `vim` para crear el script y `git` para obtener la información necesaria. 🧠

---

## ⚙️ Comandos que utilizaremos

> - 📝 **`vim`** → para crear y editar el archivo `git_ignore.sh`.  
> - 🧩 **`git`** → para listar los archivos ignorados en el repositorio.  

---

### 1️⃣ Crear el archivo `git_ignore.sh` con Vim
Abrimos el editor para crear nuestro script:

```bash
  vim git_ignore.sh
```

Una vez dentro de **Vim**:
1. Pulsa la tecla `i` para entrar en **modo inserción** ✍️  
2. Escribe el siguiente contenido:

```bash
  #!/bin/bash
  git status --ignored -s | grep '!!' | cut -c 4-
```

📘 Explicación:
- `#!/bin/bash` → indica que el script debe ejecutarse con Bash.  
- `git status --ignored -s` → muestra el estado de los archivos **incluyendo los ignorados**, en formato corto (`-s`).  
- `grep '!!'` → filtra solo las líneas marcadas con `!!`, que representan los archivos **ignorados**.  
- `cut -c 4-` → elimina los primeros 3 caracteres (`!! `) para mostrar solo el nombre del archivo.  

💡 El resultado será una lista limpia con todos los archivos ignorados.

---

### 2️⃣  Guardar y salir de Vim
Presiona `Esc`, luego escribe:
```vim
:wq
```
y presiona **Enter**.

Esto guardará los cambios y cerrará el archivo.

---

### 3️⃣ Dar permisos de ejecución al script
Para poder ejecutarlo, dale permisos con:

```bash
  chmod +x git_ignore.sh
```

💡 Esto convierte el archivo en un script ejecutable.

---

### 4️⃣ Probar el script
Ejecuta el script desde el terminal dentro de un repositorio con `.gitignore`:

```bash
  ./git_ignore.sh
```

📜 Resultado esperado:
```
archivo_temporal.log
node_modules/
.env
```
Cada línea corresponde a un archivo o carpeta **ignorados** por Git.

---

## ⚠️ Errores comunes

| Error | Causa | Solución |
|--------|--------|-----------|
| `fatal: not a git repository` | Estás fuera de un repositorio Git | Ejecuta el script dentro de un repo válido |
| No muestra nada | No tienes archivos ignorados | Crea un `.gitignore` con algunos patrones |
| `Permission denied` | El script no tiene permisos de ejecución | Usa `chmod +x git_ignore.sh` |

---

## ✅ Resultado final esperado

El archivo `git_ignore.sh` debe verse así:

```bash
  #!/bin/bash
  git status --ignored -s | grep '!!' | cut -c 4-
```

Y al ejecutar `ls -l`, el resultado debería ser algo como:
```
-rwxr-xr-x 1 daz daz 60 Oct 26 14:35 git_ignore.sh
```

---

> 💬 *Consejo:* Este script es muy útil para revisar rápidamente qué archivos está ignorando Git sin tener que abrir el `.gitignore`. 🚀
