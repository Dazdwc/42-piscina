# 📝 Comando `history` — Historial de comandos en la terminal

## 🧠 Concepto
El comando **`history`** muestra una lista de los comandos que has ejecutado recientemente en tu terminal.  
Es tu “memoria” en la línea de comandos y puede ahorrarte mucho tiempo durante la piscina 🏊‍♂️.

Cada comando ejecutado se guarda con un número, lo que te permite repetirlo o buscarlo fácilmente.

---

## ⚙️ Sintaxis general

```bash
history [opciones] [número]
```

---

## 📘 Ejemplos paso a paso

### 1️⃣ Ver el historial completo
```bash
history
```
📜 Muestra una lista numerada de todos los comandos que has ejecutado en esta sesión.

Ejemplo:
```
  1  pwd
  2  ls
  3  cd shell00
  4  vim ex00/hello.sh
  5  bash hello.sh
```

---

### 2️⃣ Ver las últimas N líneas del historial
```bash
history 10
```
📄 Muestra solo los **últimos 10 comandos** ejecutados.

---

### 3️⃣ Repetir un comando anterior
```bash
!n
```
🔁 Repite el comando con el número `n` del historial.

Ejemplo:
```bash
!4
```
Ejecutará el comando número 4 (por ejemplo `vim ex00/hello.sh`).

---

### 4️⃣ Repetir el último comando
```bash

!!
```
😎 Ejecuta de nuevo el último comando.  
Perfecto si olvidaste poner `sudo`:
```bash
apt install vim
sudo !!
```

---

### 5️⃣ Buscar comandos anteriores
Puedes usar `grep` para buscar en el historial:
```bash
history | grep vim
```
🔍 Muestra todos los comandos anteriores que contengan la palabra “vim”.

---

### 6️⃣ Borrar el historial
```bash
history -c
```
🧹 Limpia completamente el historial actual de la sesión.  
💡 Útil en entornos compartidos o antes de enviar tu terminal para evaluación.

---

### 7️⃣ Guardar tu historial en un archivo
```bash
history > mis_comandos.txt
```
💾 Crea un archivo con todos los comandos que has usado. Perfecto para documentar tu progreso o repasar tu trabajo en la piscina.

---

## ⚙️ Dónde se guarda el historial

Tu historial no se pierde al cerrar la terminal: se guarda en un archivo oculto llamado:

```bash
~/.bash_history
```

Cada vez que cierras tu sesión, los comandos nuevos se escriben ahí.  
Puedes abrirlo con:
```bash
cat ~/.bash_history
```

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-c` | Borra el historial actual |
| `-d n` | Borra una entrada específica del historial (por número) |
| `-a` | Añade los comandos actuales al archivo de historial |
| `-r` | Lee el historial desde el archivo |
| `-w` | Escribe el historial actual en el archivo |

---

## ⚠️ Errores comunes

🚫 **“Event not found”**  
> Usas `!comando` sin que exista un evento con ese nombre.  
💡 Usa `history | grep palabra` para buscar el número correcto.

🚫 **No guarda historial entre sesiones**  
> A veces la shell no escribe en `~/.bash_history` hasta cerrarla.  
💡 Cierra la sesión correctamente o fuerza la escritura con `history -w`.

🚫 **Archivos enormes de historial**  
> Si usas la terminal mucho, el archivo puede crecer.  
💡 Limpia con `history -c` o edítalo con `vim ~/.bash_history`.

---

## 🪄 Tips y buenas prácticas

- Usa `Ctrl + R` para buscar en el historial en tiempo real:  
  escribe una parte del comando y presiona `Ctrl + R` repetidamente.  
  Ejemplo:
  ```bash
  (reverse-i-search)`vim': vim ex00/hello.sh
  ```

- Puedes usar el historial para aprender de tus errores (qué hiciste bien o mal en un ejercicio).  
- Exporta tu historial antes de cerrar la piscina para repasar después:
  ```bash
  history > historial_piscina.txt
  ```
- En scripts o evaluaciones, `!!` te ahorra muchísimo tiempo.  

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Ver historial | `history` | Lista todos los comandos ejecutados |
| Ver últimos N | `history 20` | Muestra los últimos 20 |
| Repetir comando N | `!N` | Repite un comando específico |
| Repetir último | `!!` | Ejecuta de nuevo el último comando |
| Buscar en historial | `history | grep palabra` | Filtra por palabra clave |
| Limpiar historial | `history -c` | Borra todos los registros |
| Guardar en archivo | `history > archivo.txt` | Exporta tu historial |
| Ver historial persistente | `cat ~/.bash_history` | Ver el archivo histórico |

---

> 💬 *“history es tu espejo: te muestra el pasado, para que no repitas los mismos errores.”* 🪞  
> En la piscina, dominarlo te ayuda a ahorrar tiempo, corregir errores y aprender de cada comando que ejecutas.
