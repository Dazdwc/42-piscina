# 🧰 Comando `sudo` — Ejecutar comandos como administrador

## 🧠 Concepto
El comando **`sudo`** (*superuser do*) permite ejecutar comandos con **privilegios de administrador (root)**.  
Se usa cuando necesitas realizar acciones que afectan al sistema: instalar programas, cambiar permisos globales, editar configuraciones o acceder a archivos protegidos.

En la **Piscina 42** y en Linux en general, `sudo` te da acceso temporal a tareas que requieren control total del sistema.

---

## ⚙️ Sintaxis general

```bash
sudo [comando]
```

💡 Al ejecutar un comando con `sudo`, el sistema te pedirá tu **contraseña de usuario** para confirmar que tienes permiso para hacerlo.

---

## 📘 Ejemplos paso a paso

### 1️⃣ Ejecutar un comando como administrador
```bash
sudo apt update
```
🔧 Actualiza la lista de paquetes del sistema.  
Este tipo de acción requiere permisos de superusuario.

---

### 2️⃣ Editar un archivo del sistema
```bash
sudo nano /etc/hosts
```
📄 Abre el archivo `/etc/hosts` con permisos de administrador, permitiéndote editarlo.

---

### 3️⃣ Instalar un programa
```bash
sudo apt install vim
```
🧱 Instala el paquete `vim` usando `apt`.  
Sin `sudo`, recibirías un error de permisos.

---

### 4️⃣ Ejecutar múltiples comandos como root
```bash
sudo bash
```
💡 Abre una nueva shell con privilegios de root (⚠️ úsalo con cuidado).  
Puedes reconocerlo porque el prompt suele cambiar a `#`.

---

### 5️⃣ Verificar si un usuario puede usar sudo
```bash
sudo -l
```
🔍 Muestra los comandos que tienes permiso para ejecutar con `sudo`.

---

### 6️⃣ Ejecutar un comando como otro usuario
```bash
sudo -u usuario comando
```
👥 Ejecuta un comando con los permisos de otro usuario (por ejemplo, `root` o `www-data`).

Ejemplo:
```bash
sudo -u root whoami
```
➡️ Devuelve `root`.

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-l` | Lista los comandos permitidos con sudo |
| `-u usuario` | Ejecuta el comando como otro usuario |
| `-v` | Renueva la sesión sudo sin ejecutar nada |
| `-k` | Revoca los privilegios actuales (vuelve a pedir contraseña) |
| `-s` | Abre una shell con permisos sudo |

---

## ⚠️ Errores comunes

🚫 **“user is not in the sudoers file”**  
> Tu usuario no tiene permiso para usar `sudo`.  
💡 Solo un administrador puede añadirte al archivo `/etc/sudoers` o al grupo `sudo`.

🚫 **“Permission denied” incluso con sudo**  
> Estás intentando acceder a un recurso del sistema bloqueado (por ejemplo, `/root`).  
💡 Asegúrate de usar la ruta correcta o la opción `-i` para abrir una sesión root temporal.

🚫 **“sudo: unable to resolve host”**  
> Tu nombre de host no coincide con el de `/etc/hosts`.  
💡 Edita el archivo `/etc/hosts` para que coincida con el nombre del sistema (`hostname`).

---

## 🪄 Tips y buenas prácticas

- No uses `sudo` de forma automática: **piensa antes de ejecutarlo**.  
- Si necesitas varios comandos seguidos, abre una sesión temporal:
  ```bash
  sudo -i
  ```
- Usa `sudo !!` para repetir el último comando con permisos de administrador.
  ```bash
  apt update
  sudo !!
  ```
  (Ejecutará `sudo apt update` automáticamente.)
- Para cerrar la sesión sudo temporal, usa:
  ```bash
  sudo -k
  ```

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Ejecutar como root | `sudo comando` | Ejecuta con permisos de administrador |
| Abrir shell root | `sudo -i` | Entra en modo administrador |
| Ejecutar como otro usuario | `sudo -u usuario comando` | Usa otro perfil |
| Ver comandos permitidos | `sudo -l` | Lista privilegios sudo |
| Repetir último comando como root | `sudo !!` | Reejecuta con permisos |

---

> 💬 *“Con sudo viene gran poder… y gran responsabilidad.”* ⚡  
> Es la herramienta más potente de Linux, pero también la más peligrosa si se usa sin cuidado.
