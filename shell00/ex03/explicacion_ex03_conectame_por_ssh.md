# 🧩 Ex03: ¡Conéctame por SSH!

En este ejercicio aprenderemos a **crear y usar claves SSH** para conectarnos de forma segura con el servidor de 42.  
Esto nos permitirá **subir nuestros proyectos sin tener que escribir usuario y contraseña cada vez**. 🔐

---

## ⚙️ Comandos que utilizaremos

> - 🔐 **`ssh`** → para generar la clave ssh y poder subir archivos a la intra de 42.  
> - 📂 **`cp`** → para copiar el ssh y subirlo al repositorio.
---

## 🧠 Objetivo
Crea tu propia clave SSH y configura tu entorno para poder conectarte a los servidores de 42.  
Cuando termines, deberás tener un archivo `id_rsa_pub` con tu **clave pública** dentro de tu repositorio.

---

## 🚀 Pasos a seguir

### 1️⃣ Generar tu clave SSH
Para crear un nuevo par de claves SSH (una pública y otra privada), ejecuta:

```bash
  ssh-keygen -t rsa -b 4096 -C "tu_email@42.fr"
```

📘 Explicación:
- `-t rsa` → tipo de clave.  
- `-b 4096` → tamaño de la clave (4096 bits = más seguridad).  
- `-C` → comentario identificativo (usa tu email de 42).  

Presiona **Enter** para aceptar la ruta por defecto (`~/.ssh/id_rsa`).  
Luego, si quieres, puedes dejar vacía la *passphrase* (contraseña de la clave).

---

### 2️⃣ Comprobar que la clave se generó correctamente
Mira el contenido de tu carpeta `.ssh`:
```bash
  ls ~/.ssh
```
Deberías ver al menos dos archivos:
```
id_rsa      # 🔒 clave privada (NO se comparte)
id_rsa.pub  # 🔑 clave pública (esta sí se comparte)
```

---

### 3️⃣ Crear el archivo `id_rsa_pub` dentro del ejercicio
El enunciado te pide que subas tu clave pública al repositorio, así que copia el contenido de `id_rsa.pub` dentro de tu carpeta `ex03`:

```bash
cat ~/.ssh/id_rsa.pub > ~/shell00/ex03/id_rsa_pub
```
💡 El nombre del archivo **no es aleatorio**: el evaluador buscará exactamente `id_rsa_pub`.

---

### 4️⃣ Añadir tu clave pública a la Intranet de 42
Esto permitirá que el servidor reconozca tu equipo al hacer `git push` sin pedir credenciales.

1. Muestra el contenido de tu clave pública:
   ```bash
   cat ~/.ssh/id_rsa.pub
   ```
2. Copia todo el texto (comienza con `ssh-rsa` o `ssh-ed25519`).  
3. Entra en la **Intranet de 42** → *Settings* → *seguridad* → *SSH Keys*.  
4. Pega la clave y guarda los cambios.

✅ Ahora tu ordenador está vinculado a tu cuenta de 42.

---

### 5️⃣ Probar la conexión con el servidor de 42
Para confirmar que todo funciona correctamente:
```bash
ssh -T git@student.42barcelona.fr
```
Si tu clave está bien configurada, verás un mensaje parecido a:
```
Welcome to 42 Barcelona Git service!
```

---

## ⚠️ Errores comunes

| Error | Causa | Solución |
|--------|--------|-----------|
| `Permission denied (publickey)` | El servidor no reconoce tu clave | Añádela correctamente en la Intra |
| `No such file or directory` | No tienes claves generadas | Ejecuta `ssh-keygen` |
| `Agent admitted failure to sign using the key` | El agente SSH no está activo | Ejecuta `eval $(ssh-agent)` y `ssh-add ~/.ssh/id_rsa` |

---

## 💡 Consejos importantes

- 🧱 **No confundas las claves:**  
  Tu `id_rsa` (privada) nunca debe subirse ni compartirse.  
  Solo tu `id_rsa.pub` es la que puedes usar en el repositorio o en la Intra.

- 🧠 **Entiende la diferencia:**  
  La clave privada **demuestra tu identidad**, la pública **sirve para verificarla**.

- 👥 **Pregunta a tus compañeros:**  
  Si tienes dudas, comparte pantalla o compáralo con alguien que ya lo haya hecho.

---

## ✅ Resultado final esperado

Tu carpeta `ex03` debería contener:
```
ex03/
└── id_rsa_pub
```

Y al ejecutar:
```bash
cat id_rsa_pub
```
Deberías ver algo parecido a:
```
ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAACAQDez2n7nYd+... tu_email@42.fr
```

---

> 💬 *Consejo final:* una vez entiendas bien SSH, estarás un paso más cerca de moverte como pez en el agua dentro de los entornos Linux y servidores remotos. 🐧
