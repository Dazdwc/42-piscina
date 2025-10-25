# 🔐 Comando `ssh` — Conexión segura y gestión de claves

## 🧠 Concepto
**SSH (Secure Shell)** es un protocolo que permite conectarse de forma segura a otro equipo a través de una red.  
Se usa para **administrar servidores, intercambiar archivos o autenticarte en repositorios** (como los de 42 o GitHub).  

Durante la piscina, lo usarás para subir tus ejercicios y comunicarte con los servidores de 42.  

---

## ⚙️ Sintaxis general
```bash
ssh [usuario]@[host]
```
Por ejemplo:
```bash
ssh dani@student.42barcelona.fr
```
👉 Esto abrirá una sesión remota en el servidor de 42, si tu clave pública está autorizada.

---

## 🪄 Generar tu propia clave SSH
Antes de poder conectarte sin contraseña, necesitas crear un **par de claves SSH**:

```bash
ssh-keygen -t rsa -b 4096 -C "tu_email@ejemplo.com"
```

📜 Explicación:
- `-t rsa` → tipo de algoritmo (RSA es el más común).  
- `-b 4096` → tamaño de la clave (más bits = más seguridad).  
- `-C` → comentario para identificar la clave (normalmente tu email).  

💡 Cuando se te pregunte dónde guardar la clave, pulsa `Enter` para aceptar la ruta por defecto:
```
/home/tu_usuario/.ssh/id_rsa
```

Después te pedirá una **passphrase opcional** (una contraseña que protege la clave privada).  
Puedes dejarla vacía si quieres evitar tener que escribirla cada vez.

---

## 📁 Archivos generados
| Archivo | Descripción |
|----------|--------------|
| `~/.ssh/id_rsa` | 🔒 Clave **privada** (¡no la compartas nunca!) |
| `~/.ssh/id_rsa.pub` | 🔑 Clave **pública** (esta sí puedes subir o compartir) |

---

## 🚀 Añadir tu clave pública a la Intranet de 42
1. Abre tu clave pública:
   ```bash
   cat ~/.ssh/id_rsa.pub
   ```
2. Copia su contenido completo (empieza por `ssh-rsa` o `ssh-ed25519`).  
3. Entra en tu perfil de la **Intranet de 42** → “Settings” → “SSH Key”.  
4. Pega la clave en el campo y guarda los cambios.  

💡 Esto permite que el servidor reconozca tu máquina cuando uses `git clone` o `git push` desde el terminal.

---

## 📦 Añadir la clave pública al repositorio
Crea un archivo llamado `id_rsa_pub` dentro de tu carpeta del proyecto y añade dentro tu clave pública:

```bash
cat ~/.ssh/id_rsa.pub > id_rsa_pub
```

Así, el evaluador podrá verificar que generaste correctamente tus claves SSH.

---

## 🔗 Conectar a un servidor remoto con tu clave
Una vez configurada la clave en tu Intra o GitHub, podrás conectarte sin contraseña:

```bash
ssh -T git@student.42barcelona.fr
```
Si todo está correcto, verás un mensaje como:
```
Welcome to 42 Barcelona Git service!
```

---

## 🧹 Administrar y probar tus claves
Ver qué claves SSH están cargadas actualmente:
```bash
ssh-add -l
```
Añadir una clave manualmente al agente:
```bash
ssh-add ~/.ssh/id_rsa
```
Probar una conexión detallada (para debug):
```bash
ssh -v git@student.42barcelona.fr
```

---

## ⚠️ Errores comunes

| Error | Causa | Solución |
|--------|--------|-----------|
| `Permission denied (publickey)` | El servidor no reconoce tu clave pública | Añádela correctamente en la Intra o GitHub |
| `No such file or directory` | No tienes claves generadas | Ejecuta `ssh-keygen` |
| `Agent admitted failure to sign using the key` | El agente SSH no está activo | Usa `eval $(ssh-agent)` y `ssh-add` |

---

## 🎯 Resumen rápido

| Acción | Comando |
|--------|----------|
| Generar clave | `ssh-keygen -t rsa -b 4096 -C "email"` |
| Mostrar clave pública | `cat ~/.ssh/id_rsa.pub` |
| Probar conexión | `ssh -T git@servidor` |
| Añadir clave al agente | `ssh-add ~/.ssh/id_rsa` |
| Copiar clave pública al repo | `cat ~/.ssh/id_rsa.pub > id_rsa_pub` |

---

> 💬 *Recuerda:* Tu clave privada **nunca** debe compartirse.  
> La pública es tu “identidad digital segura” — quien tenga tu privada, puede hacerse pasar por ti. 🔥
