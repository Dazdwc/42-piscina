# 🗑️ Comando `rm`

---

## 🧠 Concepto

El comando **`rm`** (de *remove*) se usa para **eliminar archivos o directorios** del sistema de ficheros.  
A diferencia de lo que ocurre en entornos gráficos, **no existe papelera ni recuperación automática**:  
👉 una vez ejecutado, el contenido **desaparece de forma permanente**.

Es uno de los comandos más potentes y peligrosos de la terminal.  
Por eso, en la piscina es fundamental usarlo con precaución, especialmente al trabajar con `*` o `-r`.

---

## ⚙️ Sintaxis general

```bash
rm [opciones] nombre_archivo
```

También puedes eliminar múltiples archivos:
```bash
rm archivo1 archivo2 archivo3
```

---

## 📘 Ejemplos paso a paso

### 1️⃣ Eliminar un archivo simple
```bash
rm test.txt
```
🔹 Elimina el archivo `test.txt`.

---

### 2️⃣ Eliminar varios archivos a la vez
```bash
rm archivo1 archivo2 archivo3
```
🔹 Todos los archivos listados se eliminan.

---

### 3️⃣ Eliminar todos los archivos de una carpeta
```bash
rm *
```
⚠️ **PELIGRO**: Esto eliminará todos los archivos del directorio actual (sin confirmación si no usas `-i`).

---

### 4️⃣ Eliminar directorios y su contenido
```bash
rm -r carpeta
```
🔹 Elimina la carpeta `carpeta` y todo lo que contiene, incluidos subdirectorios y archivos.

---

### 5️⃣ Eliminar sin pedir confirmación
```bash
rm -rf carpeta
```
🔹 Opción muy usada, pero **extremadamente peligrosa**.  
Elimina todo el contenido sin confirmación ni posibilidad de recuperación.  
> 💀 *Jamás uses esto fuera de entornos controlados o sin saber qué haces.*

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-r` | Elimina directorios y su contenido (recursivo). |
| `-f` | Fuerza la eliminación sin pedir confirmación. |
| `-i` | Pide confirmación antes de borrar cada archivo. |
| `-v` | Muestra los archivos que se van eliminando. |

---

## ⚠️ Errores comunes

| Error | Causa | Solución |
|--------|--------|-----------|
| `rm: cannot remove 'archivo': Permission denied` | No tienes permisos suficientes. | Usa `sudo rm archivo` o cambia los permisos con `chmod`. |
| `rm: cannot remove 'carpeta': Is a directory` | Estás intentando eliminar un directorio sin `-r`. | Usa `rm -r carpeta`. |
| `rm: missing operand` | No has indicado qué borrar. | Añade el nombre del archivo o directorio. |

---

## 🪄 Tips y buenas prácticas

- Antes de usar `rm`, **confirma tu ubicación** con `pwd` y el contenido con `ls`.  
- Si tienes dudas, usa la opción `-i` para pedir confirmación antes de borrar.  
- Nunca combines `sudo` con `rm -rf /` o rutas absolutas desconocidas.  
  (Sí, es un clásico de los memes, pero también de los desastres reales 😅).  
- Para “limpiar” carpetas de ejercicios, puedes usar:
  ```bash
  rm -rf ex*/test*
  ```

---

## 🎯 Resumen

| Acción | Comando | Resultado |
|--------|----------|-----------|
| Borrar un archivo | `rm archivo.txt` | Elimina el archivo. |
| Borrar varios archivos | `rm a b c` | Elimina varios archivos a la vez. |
| Borrar una carpeta | `rm -r carpeta` | Elimina carpeta y subcarpetas. |
| Borrar sin confirmación | `rm -rf carpeta` | Elimina todo sin preguntar. |

---

> 💬 *Consejo:* `rm` es el comando más peligroso y más necesario al mismo tiempo.  
> Úsalo como si cada pulsación costara una vida de tu ejercicio. 😅
