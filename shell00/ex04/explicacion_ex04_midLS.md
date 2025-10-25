# 🧩 Ex04: midLS

En este ejercicio aprenderemos a **crear un script ejecutable en Bash** que liste los archivos y directorios del directorio actual, **sin mostrar archivos ocultos**, y ordenados de una forma específica.  
También entenderemos cómo usar `vim` y `ls` dentro de un script. 🧠

---

## 📦 Archivos del ejercicio
- **Directorio de entrega:** `ex04/`
- **Archivo a entregar:** `midLS`
- **Funciones autorizadas:** *Ninguna*

---

## ⚙️ Comandos que utilizaremos

> - 📝 **`vim`** → para crear el archivo `midLS` y editar su contenido.  
> - 📂 **`ls`** → para listar los archivos según las condiciones del enunciado.

---

## 🚀 Pasos a seguir

### 1️⃣ Crear la carpeta del ejercicio
```bash
  mkdir ex04
  cd ex04
```

---

### 2️⃣ Crear el archivo `midLS` con Vim
Abrimos el editor para crear nuestro script:

```bash
    vim midLS
```

Una vez dentro de **Vim**:
1. Pulsa la tecla `i` para entrar en **modo inserción** ✍️  
2. Escribe el siguiente contenido:

```bash
    #!/bin/bash
    ls -mtp
```

📘 Explicación:
- `#!/bin/bash` → indica que el script debe ejecutarse con Bash.  
- `ls` → lista archivos y directorios.  
- `-m` → muestra los resultados separados por comas.  
- `-t` → ordena por fecha de modificación (del más reciente al más antiguo).  
- `-p` → añade una barra `/` al final de los directorios.  

💡 Juntos (`-mtp`) cumplen exactamente lo que pide el enunciado.

---

### 3️⃣ Guardar y salir de Vim
Presiona `Esc`, luego escribe:
```vim
:wq
```
y presiona **Enter**.

Esto guardará los cambios y cerrará el archivo.

---

### 4️⃣ Dar permisos de ejecución al archivo
Para poder ejecutar tu script, dale permisos con:

```bash
  chmod +x midLS
```

💡 Esto convierte el archivo en un script ejecutable.

---

### 5️⃣ Probar el script
Ahora ejecuta tu script para comprobar que funciona correctamente:

```bash
  ./midLS
```

Deberías ver algo parecido a:
```
archivo1, archivo2, carpeta1/, carpeta2/
```

Los directorios aparecerán con `/` al final y todo separado por comas y espacios.

---

## ⚠️ Errores comunes

| Error | Causa | Solución |
|--------|--------|-----------|
| `Permission denied` | No tiene permisos de ejecución | Usa `chmod +x midLS` |
| `command not found` | No añadiste la cabecera `#!/bin/bash` | Añádela al principio del archivo |
| Archivos ocultos visibles | Usaste `ls -a` por error | Elimina la `-a` y usa solo `-mtp` |

---

## ✅ Resultado final esperado

El archivo `midLS` debe verse así:
```bash
  #!/bin/bash
  ls -mtp
```

Y al ejecutar `ls -l`, el resultado debería ser algo como:
```
-rwxr-xr-x 1 daz daz 20 Oct 26 12:34 midLS
```

---

> 💬 *Consejo:* asegúrate de entender **qué hace cada opción de `ls`** y cómo se combinan.  
> Con esto, estarás dominando uno de los comandos más usados en bash. 💪
