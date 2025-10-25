# 🔗 Redirecciones y Pipes — Control del flujo en la terminal

## 🧠 Concepto
Cuando escribes comandos en Bash, puedes **controlar cómo entra y sale la información**.  
Esto se hace con **redirecciones** y **pipes (|)**.  
Entender esto es esencial, porque toda la shell se basa en cómo **los comandos se comunican entre sí**.

En 42, estos operadores te ayudarán a conectar programas, crear archivos de salida y comprobar resultados.

---

## 📘 Redirecciones de salida

### 1️⃣ `>` — Redirigir salida (crear o sobrescribir)
```bash
echo "Hola 42" > saludo.txt
```
🧩 Crea un archivo `saludo.txt` con el texto `"Hola 42"`.  
Si ya existe, **lo sobrescribe**.

---

### 2️⃣ `>>` — Redirigir salida (añadir al final)
```bash
echo "Nuevo texto" >> saludo.txt
```
📄 Añade la línea `"Nuevo texto"` al final del archivo, sin borrar lo anterior.

---

## 📥 Redirecciones de entrada

### 3️⃣ `<` — Leer desde un archivo
```bash
cat < saludo.txt
```
📖 En lugar de escribir el texto directamente, `cat` leerá su entrada desde `saludo.txt`.

---

### 4️⃣ `<<` — *Here Document*
Permite escribir **bloques de texto directamente en el comando**.

```bash
cat << FIN
Hola
Este texto se escribe
directamente en la terminal
FIN
```
🧠 Todo lo que escribas entre `<< FIN` y la palabra `FIN` se enviará como entrada al comando.

📦 Útil para tests o para crear archivos temporales rápidamente.

---

## 🔗 Pipes — El poder de `|`

### 5️⃣ `|` — Conectar la salida de un comando con la entrada de otro
```bash
ls | grep ex
```
🔍 Envía la lista generada por `ls` directamente al comando `grep`, que filtra las líneas que contienen “ex”.

📥 Lo que sale de un comando entra en el siguiente.

Ejemplo más completo:
```bash
cat archivo.txt | grep "hola" | wc -l
```
➡️ Lee el archivo, busca las líneas con “hola” y cuenta cuántas hay.

---

## ⚙️ Operadores lógicos

### 6️⃣ `&&` — Ejecutar solo si el comando anterior fue exitoso
```bash
mkdir backup && echo "Carpeta creada con éxito"
```
🟢 Si `mkdir` funciona, se ejecuta el `echo`.  
Si falla, no se ejecuta nada más.

---

### 7️⃣ `||` — Ejecutar solo si el comando anterior falla
```bash
mkdir backup || echo "Error al crear la carpeta"
```
🔴 Si `mkdir` da error (por ejemplo, porque ya existe), entonces se ejecuta el `echo`.

---

## ⚠️ Errores comunes

🚫 **“Permission denied”**  
> Estás intentando escribir en un archivo o carpeta sin permisos.  
💡 Usa rutas donde tengas acceso (como tu carpeta de usuario o proyecto).

🚫 **“No such file or directory”**  
> El archivo de entrada no existe.  
💡 Comprueba con `ls` o `pwd` que estás en la ruta correcta.

🚫 **Sobrescribir sin querer con `>`**  
> Si usas `>`, borrarás el contenido anterior del archivo.  
💡 Usa `>>` si solo quieres añadir sin perder lo anterior.

---

## 🪄 Tips y buenas prácticas

- Puedes combinar todo esto para crear cadenas complejas:
  ```bash
  cat < archivo.txt | grep "hola" > resultado.txt
  ```
  🔁 Lee de `archivo.txt`, filtra las líneas con “hola” y guarda el resultado.
- Usa `2>` para redirigir **errores** (stderr):
  ```bash
  comando_invalido 2> errores.txt
  ```
  Guardará los mensajes de error sin afectar la salida normal.
- Redirige **todo (stdout + stderr)** con `&>`:
  ```bash
  ./script.sh &> log.txt
  ```

---

## 🎯 Resumen

| Operador | Función | Ejemplo                      | Descripción |
|--------|----------|------------------------------|--------------|
| `>`    | Redirige salida (sobrescribe) | `echo hola > file.txt`       | Crea o reemplaza archivo |
| `>>`   | Redirige salida (añade) | `echo hola >> file.txt`      | Añade al final |
| `<`    | Entrada desde archivo | `cat < file.txt`             | Lee datos de un archivo |
| `<<`   | *Here document* | `cat << FIN`                 | Texto escrito directo en terminal |
| `\|`   | Pipe | `ls \| grep ex`              | Pasa salida al siguiente comando |
| `&&`   | Si éxito | `mkdir test && echo OK`      | Ejecuta siguiente solo si el primero va bien |
| `\|\|` | Si error | `mkdir test \|\| echo Error` | Ejecuta siguiente si el primero falla |
| `2>`   | Redirigir errores | `comando 2> errores.txt`     | Guarda mensajes de error |
| `&>`   | Redirigir todo | `script &> log.txt`          | Guarda salida y errores juntos |

---

> 💬 *“Los pipes y redirecciones son como tuberías: conectan el flujo de información entre tus comandos.”*  
> Si entiendes esto, ya dominas la esencia de la terminal. 💧
