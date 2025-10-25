# 👑 Comando `chown` — Cambiar propietario y grupo de archivos

## 🧠 Concepto
El comando **`chown`** (*change owner*) sirve para **cambiar el propietario o el grupo** al que pertenece un archivo o carpeta.  
Es especialmente útil para gestionar permisos cuando trabajas con varios usuarios o cuando el sistema requiere que ciertos archivos pertenezcan a un usuario concreto (como en la Piscina o entornos compartidos).

---

## ⚙️ Sintaxis general

```bash
chown [opciones] [nuevo_usuario][:[nuevo_grupo]] archivo
```

Puedes cambiar solo el usuario, solo el grupo, o ambos a la vez.

---

## 📘 Ejemplos paso a paso

### 1️⃣ Cambiar el propietario de un archivo
```bash
sudo chown dani archivo.txt
```
👤 Cambia el propietario del archivo `archivo.txt` al usuario **dani**.  
💡 Solo el **root** o el propietario actual puede hacerlo.

---

### 2️⃣ Cambiar el grupo
```bash
sudo chown :staff archivo.txt
```
👥 El archivo ahora pertenece al grupo **staff**, pero conserva su propietario actual.

---

### 3️⃣ Cambiar propietario y grupo a la vez
```bash
sudo chown dani:staff archivo.txt
```
📦 Asigna simultáneamente el propietario **dani** y el grupo **staff**.

---

### 4️⃣ Aplicar recursivamente (carpetas completas)
```bash
sudo chown -R dani:staff proyecto/
```
📂 Cambia el propietario y grupo de **todos los archivos y subcarpetas** dentro de `proyecto/`.

---

### 5️⃣ Copiar propiedad de otro archivo
```bash
sudo chown --reference=original.txt copia.txt
```
🪞 `copia.txt` obtiene el mismo usuario y grupo que `original.txt`.

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-R` | Aplica cambios de forma recursiva a subcarpetas |
| `-v` | Muestra los archivos que se van modificando |
| `--reference=archivo` | Copia propietario y grupo de otro archivo |

---

## 🧩 Ejemplo práctico

Supongamos que tenemos esta situación:

```
-rw-r--r-- 1 root staff 1024 Oct 25 12:00 datos.txt
```

Y queremos que **dani** sea el propietario:
```bash
sudo chown dani datos.txt
```

Ahora la salida será:
```
-rw-r--r-- 1 dani staff 1024 Oct 25 12:00 datos.txt
```

Si además queremos que el grupo sea **users**:
```bash
sudo chown dani:users datos.txt
```

Salida final:
```
-rw-r--r-- 1 dani users 1024 Oct 25 12:00 datos.txt
```

---

## ⚠️ Errores comunes

🚫 **“Operation not permitted”**  
> Estás intentando cambiar el propietario sin permisos de administrador.  
💡 Usa `sudo chown` si tienes privilegios, o pide al propietario que te conceda acceso.

🚫 **“Invalid group” o “Invalid user”**  
> El usuario o grupo indicado no existe.  
💡 Comprueba los existentes con:
```bash
cat /etc/passwd
cat /etc/group
```

🚫 **Propiedad incorrecta en carpetas**  
> Si un script o programa no puede acceder a un archivo, puede que el `owner` o `group` sea incorrecto.  
💡 Usa `ls -l` para ver quién es el propietario actual.

---

## 🪄 Tips y buenas prácticas

- Siempre verifica los cambios con `ls -l` antes y después de usar `chown`.  
- En entornos multiusuario, mantén una convención clara de grupos.  
- Usa `--reference` para igualar permisos entre carpetas o backups.  
- No cambies propiedades del sistema (`/bin`, `/usr`, `/lib`) sin saber lo que haces.  

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Cambiar propietario | `chown dani archivo.txt` | Asigna a un nuevo usuario |
| Cambiar grupo | `chown :staff archivo.txt` | Asigna a un nuevo grupo |
| Cambiar ambos | `chown dani:staff archivo.txt` | Propietario y grupo juntos |
| Aplicar recursivo | `chown -R dani:staff carpeta/` | A subarchivos y carpetas |
| Copiar propiedad | `chown --reference=a.txt b.txt` | Igualar propietario y grupo |

---

> 💬 *“chown te da el control de quién manda sobre cada archivo.”* 👑  
> En Unix, la propiedad es poder — y este comando es la llave de ese poder.
