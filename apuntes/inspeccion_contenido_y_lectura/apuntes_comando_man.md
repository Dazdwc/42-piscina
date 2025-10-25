# 📖 Comando `man` — Consultar los manuales del sistema

## 🧠 Concepto
El comando **`man`** (de *manual*) muestra la documentación oficial de cualquier comando disponible en el sistema Unix.  
Es el **manual de instrucciones integrado del sistema**, y en la piscina será tu mejor amigo 🏊‍♂️ para entender opciones, sintaxis y ejemplos sin salir de la terminal.

Cada comando, archivo o función tiene una *página del manual*, llamada *man page*.

---

## ⚙️ Sintaxis general

```bash
man [sección] comando
```

- `sección` es opcional (sirve para especificar el tipo de manual).
- `comando` es el nombre del programa, archivo o función que quieres consultar.

---

## 📘 Ejemplos paso a paso

### 1️⃣ Consultar la ayuda de un comando
```bash
man ls
```
📄 Abre el manual del comando `ls`.

Dentro del manual:
- Usa `↑` y `↓` para moverte.
- Pulsa `q` para salir.

---

### 2️⃣ Buscar una palabra dentro del manual
Mientras estás leyendo:
- Pulsa `/` y escribe la palabra que quieres buscar, luego presiona `Enter`.

Ejemplo:
```
/option
```
🔍 Buscará la palabra “option” en la página actual.

---

### 3️⃣ Ver qué secciones tiene un tema
```bash
man -f printf
```
📚 Muestra las secciones donde aparece `printf`:
```
printf (1)  - format and print data
printf (3)  - formatted output conversion
```
💡 La sección `(1)` es para comandos del sistema, `(3)` para funciones de C, etc.

---

### 4️⃣ Abrir una sección específica
```bash
man 3 printf
```
🧩 Abre la documentación de la función `printf` de la biblioteca de C, no el comando shell.

---

### 5️⃣ Buscar manuales que contengan una palabra
```bash
man -k copy
```
🔍 Busca todos los comandos relacionados con “copy”.

Ejemplo:
```
cp (1) - copy files and directories
scp (1) - secure copy (remote file copy program)
```

---

## ⚙️ Secciones comunes de `man`

| Sección | Contenido |
|----------|------------|
| **1** | Comandos ejecutables del sistema |
| **2** | Llamadas al sistema (funciones del kernel) |
| **3** | Funciones de biblioteca (como `printf`) |
| **4** | Archivos especiales (como `/dev`) |
| **5** | Formatos de archivos y configuraciones |
| **6** | Juegos y demostraciones 😄 |
| **7** | Convenciones y miscelánea |
| **8** | Comandos de administración del sistema |

---

## ⚠️ Errores comunes

🚫 **“No manual entry for comando”**  
> No existe documentación para ese comando.  
💡 Puede que no esté instalado o el paquete `man-pages` falte en tu sistema.

🚫 **Texto cortado o sin formato**  
> Tu terminal puede no tener configurado el *pager* (`less` o `more`).  
> 
💡 Usa:
```bash
man comando | cat
```
para ver el texto completo sin formato.

---

## 🪄 Tips y buenas prácticas

- Usa `man -k palabra` para explorar comandos desconocidos.  
- Puedes combinarlo con `grep` para filtrar:

  ```bash
  man ls | grep "option"
  ```
- Algunos comandos tienen su versión corta con `--help`, pero **`man` es más completo**.  
- Para copiar texto desde el manual, usa `man comando | tee salida.txt`.

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Abrir manual | `man comando` | Muestra la documentación |
| Buscar palabra | `/palabra` | Busca dentro del manual |
| Ver secciones disponibles | `man -f comando` | Lista versiones del manual |
| Buscar comandos relacionados | `man -k palabra` | Encuentra comandos por tema |
| Manual de una sección específica | `man 3 printf` | Abre manual de funciones C |

---

> 💬 *“man es el sabio de la terminal: lo sabe todo, pero hay que saber preguntarle.”* 📚  
> En la piscina, si no sabes algo, escribe `man algo` antes de buscar en Google.
