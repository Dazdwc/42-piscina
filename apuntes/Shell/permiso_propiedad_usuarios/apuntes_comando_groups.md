# 👥 Comando `groups`

---

## 🧠 Concepto

El comando `groups` muestra **a qué grupos pertenece un usuario** dentro del sistema.  
Cada usuario puede formar parte de varios grupos, y esto determina los **permisos de acceso** a archivos y directorios.  
En la piscina, suele usarse para comprobar configuraciones de permisos o identificar el grupo principal del usuario actual.  

---

## ⚙️ Sintaxis general

```bash
groups [usuario]
```

- Si no se especifica ningún usuario, mostrará los grupos del usuario actual.  

---

## 📘 Ejemplos paso a paso

### 1️⃣ Ver los grupos del usuario actual
```bash
groups
```
🔹 Resultado:
```
student wheel staff
```
Esto indica que el usuario pertenece a los grupos `student`, `wheel` y `staff`.

### 2️⃣ Ver los grupos de otro usuario
```bash
groups nombre_usuario
```
🔹 Resultado (ejemplo):
```
nombre_usuario : users admin
```

### 3️⃣ Mostrar solo los nombres de los grupos de forma compacta
```bash
id -Gn
```
🔹 Resultado:
```
student wheel staff
```

---

## ⚙️ Comandos relacionados

| Comando | Descripción |
|----------|--------------|
| `id` | Muestra el ID de usuario, grupo principal y secundarios. |
| `whoami` | Indica el nombre del usuario actual. |
| `cat /etc/group` | Muestra todos los grupos del sistema. |

---

## ⚠️ Errores comunes

| Error | Causa | Solución |
|--------|--------|-----------|
| `no such user` | El usuario indicado no existe. | Comprueba el nombre de usuario. |
| Sin salida visible | Comando no instalado (muy raro). | Usa `id -Gn` como alternativa. |

---

## 🪄 Tips y buenas prácticas

- Usa `groups` sin argumentos para conocer tu grupo principal.  
- Conocer los grupos es esencial para entender por qué ciertos archivos no te dejan modificarlos.  
- En entornos de red o servidores, pertenecer al grupo correcto define tus permisos de ejecución o lectura.  

---

## 🎯 Resumen

| Acción | Comando | Resultado |
|--------|----------|-----------|
| Ver mis grupos | `groups` | Muestra los grupos del usuario actual. |
| Ver grupos de otro usuario | `groups usuario` | Lista los grupos de ese usuario. |
| Alternativa equivalente | `id -Gn` | Muestra solo los nombres de los grupos. |

---

> 💬 *Consejo:* Entender cómo funcionan los grupos te ayudará a dominar los permisos en los ejercicios de la piscina, especialmente cuando empieces a trabajar con `chmod` y `chown`. 😉
