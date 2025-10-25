# 👤 Comandos `whoami` e `id` — Identidad del usuario en el sistema

## 🧠 Concepto
En Unix/Linux cada acción se ejecuta como *alguien*: un usuario concreto con ciertos permisos.  
Estos dos comandos te dicen exactamente **quién eres** y **qué permisos tienes** en la máquina.

- `whoami` → tu nombre de usuario actual.
- `id` → tu UID, GID y grupos (tu identidad técnica completa).

En la piscina esto es útil para entender permisos, `sudo`, propiedad de archivos (`chown`) y comportamientos raros tipo “¿por qué no puedo modificar esto?”.

---

## ⚙️ Sintaxis general

```bash
whoami
id [opciones]
```

---

## 📘 Ejemplos paso a paso

### 1️⃣ Ver tu usuario actual
```bash
whoami
```
Salida típica:
```
dani
```
🪪 Esto responde a: “¿con qué usuario estoy logueado ahora mismo?”  
Muy útil si has usado `sudo -i` o has cambiado de usuario con `su`.

---

### 2️⃣ Ver información completa del usuario
```bash
id
```
Ejemplo de salida:
```text
uid=1000(dani) gid=1000(dani) groups=1000(dani),27(sudo),100(users)
```
Vamos a desglosar esto 👇

- `uid=1000(dani)` → UID = 1000, nombre de usuario = `dani`.  
- `gid=1000(dani)` → GID principal del usuario `dani`.  
- `groups=...` → lista de todos los grupos a los que perteneces.

📌 Estar en ciertos grupos da permisos extra (por ejemplo, pertenecer a `sudo` te deja usar `sudo`).

---

### 3️⃣ Ver solo el UID numérico
```bash
id -u
```
👉 Devuelve solo tu **UID** (User ID), por ejemplo `1000`.

Esto es útil para scripts que necesitan comparar IDs sin nombres.

---

### 4️⃣ Ver solo el nombre del grupo principal
```bash
id -gn
```
👥 Muestra el nombre del grupo por defecto de tu usuario.

---

### 5️⃣ ¿Cuál es mi usuario *real* si estoy usando sudo?
```bash
whoami
id
```
🔍 `whoami` te dice el usuario efectivo (“qué usuario soy ahora mismo”).  
`id` te da todo el contexto actual de permisos.

Ejemplo clásico:
```bash
sudo whoami
```
Salida:
```text
root
```
Significa que ese comando concreto se ejecutó como `root`.

---

## ⚙️ Opciones comunes de `id`

| Opción | Descripción |
|--------|--------------|
| `-u` | Muestra solo tu UID |
| `-un` | Muestra solo tu nombre de usuario |
| `-g` | Muestra el GID (grupo principal) numérico |
| `-gn` | Muestra el nombre de tu grupo principal |
| `-G` | Muestra todos los GIDs de tus grupos |
| `-Gn` | Muestra los nombres de todos tus grupos |

Ejemplo útil:
```bash
id -Gn
```
Salida:
```text
dani sudo users
```
💡 Traducción: perteneces a los grupos `dani`, `sudo` y `users`. Eso afecta a qué puedes leer/modificar en el sistema.

---

## ⚠️ Errores comunes

🚫 **“command not found: whoami”**  
> En algunas imágenes mínimas de Linux, `whoami` puede no venir instalado.  
💡 Usa `id -un` como alternativa:  
```bash
id -un
```

🚫 **“Permission denied” cambiando cosas aunque seas tú**  
> A veces crees que “eres tú”, pero en realidad estás en otro contexto (ej: `sudo -u otrousuario comando`).  
💡 Comprueba siempre con `whoami` antes de tocar permisos o hacer `chown`.

🚫 **Confusión entre usuario y grupo**  
> Usuario ≠ grupo. Puedes ser `dani`, pero pertenecer al grupo `sudo`. Ese grupo te da más poder.

---

## 🪄 Tips y buenas prácticas

- Antes de hacer algo serio con permisos (`chmod`, `chown`, borrar cosas del sistema...), pregúntale a la máquina:  
  ```bash
  whoami
  id
  ```

- Si estás depurando por qué no puedes escribir en una carpeta:
  ```bash
  ls -ld carpeta/
  id
  ```
  y compara el propietario/grupo de la carpeta con tus grupos.

- Para scripts en shell que se deben ejecutar *solo* como root:
  ```bash
  if [ "$(id -u)" -ne 0 ]; then
      echo "Este script necesita root"
      exit 1
  fi
  ```

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Ver tu usuario actual | `whoami` | Dice qué usuario está activo ahora |
| Ver identidad completa | `id` | UID, GID y grupos |
| Ver solo tu UID | `id -u` | ID numérico del usuario |
| Ver solo tu nombre de usuario | `id -un` | Nombre del usuario actual |
| Ver todos tus grupos por nombre | `id -Gn` | Lista de grupos legibles |
| Comprobar si eres root en este comando | `sudo whoami` | Devuelve `root` si ejecutas con sudo |

---

> 💬 *“whoami es el ‘¿quién soy yo?’ y id es el ‘¿qué puedo hacer?’.”* 👤  
> Úsalos siempre que dudes de tus permisos antes de romper algo en el sistema 😇
