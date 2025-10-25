# 🧩 Ex05: git_commit.sh

En este ejercicio aprenderemos a **crear un script ejecutable en Bash** que muestre los identificadores (hash) de los **5 últimos commits** realizados en el repositorio actual.  
Usaremos comandos básicos de Bash y Git. 🧠

---

## ⚙️ Comandos que utilizaremos

> - 📝 **`vim`** → para crear y editar el archivo `git_commit.sh`.  
> - 🧩 **`git`** → para listar los commits con el formato adecuado.

---

## 🚀 Pasos a seguir

###  1️⃣ CCrear el archivo `git_commit.sh` con Vim
Abrimos el editor para crear nuestro script:

```bash
vim git_commit.sh
```

Una vez dentro de **Vim**:
1. Pulsa la tecla `i` para entrar en **modo inserción** ✍️  
2. Escribe el siguiente contenido:

```bash
#!/bin/bash
git log --pretty=format:'%h' -n 5
```

📘 Explicación:
- `#!/bin/bash` → indica que el script debe ejecutarse con Bash.  
- `git log` → muestra el historial de commits.  
- `--pretty=format:'%h'` → muestra solo el **ID corto** (hash) de cada commit.  
- `-n 5` → limita la salida a los **5 últimos commits**.

💡 Con esto obtendrás exactamente lo que pide el enunciado.

---
### 2️⃣ Guardar y salir de Vim
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
chmod +x git_commit.sh
```

💡 Esto convierte el archivo en un script ejecutable.

---
### 4️⃣  Probar el script
Ejecuta el script desde el terminal:

```bash
./git_commit.sh
```

Deberías ver algo como:
```
a1b2c3d
f4e5f6a
b7c8d9e
...
```

Cada línea mostrará el ID corto de los 5 commits más recientes.

---

## ⚠️ Errores comunes

| Error | Causa | Solución |
|--------|--------|-----------|
| `fatal: not a git repository` | Estás fuera de un repositorio Git | Ejecuta el script dentro de una carpeta con `.git` |
| `Permission denied` | El script no tiene permisos de ejecución | Usa `chmod +x git_commit.sh` |
| Sin salida en pantalla | No hay commits todavía | Haz al menos un commit con `git commit -m "mensaje"` |

---

## ✅ Resultado final esperado

El archivo `git_commit.sh` debe verse así:

```bash
#!/bin/bash
git log --pretty=format:'%h' -n 5
```

Y al ejecutar `ls -l`, el resultado debería ser algo como:
```
-rwxr-xr-x 1 daz daz 45 Oct 26 14:02 git_commit.sh
```

---

> 💬 *Consejo:* Si más adelante quieres mostrar también el mensaje o autor del commit, puedes ampliar el formato con:  
> ```bash
> git log --pretty=format:'%h - %an: %s' -n 5
> ```  
> ¡Pero para este ejercicio, basta con mostrar los IDs! 🚀
