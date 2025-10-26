# ✂️ Comando `sed`

---

## 🧠 Concepto

El comando **`sed`** (*stream editor*) es un editor de texto **no interactivo** que permite **modificar, filtrar o reemplazar texto** mientras pasa por el flujo de entrada.  
Es ideal para automatizar cambios en texto sin abrir los archivos manualmente.

En la piscina se utiliza principalmente para **mostrar líneas específicas**, **reemplazar palabras** o **eliminar líneas** según un patrón.

---

## ⚙️ Sintaxis general

```bash
sed [opciones] 'comando' [archivo]
```

- Si no se indica archivo, `sed` leerá desde la entrada estándar (`|` o redirección).

---

## 📘 Ejemplos paso a paso

### 1️⃣ Mostrar solo las líneas impares
```bash
  ls -l | sed -n 'p;n'
```
🔹 Imprime una línea, salta la siguiente, imprime otra, y así sucesivamente.

### 2️⃣ Mostrar una línea específica
```bash
  sed -n '3p' archivo.txt
```
🔹 Muestra solo la **tercera línea** del archivo.

### 3️⃣ Sustituir una palabra por otra (primera ocurrencia por línea)
```bash
  sed 's/antiguo/nuevo/' archivo.txt
```
🔹 Reemplaza la primera aparición de “antiguo” por “nuevo” en cada línea.

### 4️⃣ Sustituir todas las ocurrencias de una palabra
```bash
  sed 's/antiguo/nuevo/g' archivo.txt
```
🔹 El modificador `g` (*global*) cambia todas las apariciones de “antiguo” a “nuevo”.

### 5️⃣ Eliminar líneas que contengan una palabra
```bash
  sed '/error/d' archivo.txt
```
🔹 Elimina todas las líneas que contengan “error”.

### 6️⃣ Editar directamente el archivo original
```bash
  sed -i 's/antiguo/nuevo/g' archivo.txt
```
⚠️ Modifica el archivo directamente (sin mostrarlo por pantalla).

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-n` | No imprime todo el contenido por defecto (solo lo indicado con `p`). |
| `-i` | Modifica el archivo directamente. |
| `-e` | Permite ejecutar varios comandos en una sola ejecución. |
| `s/patrón/reemplazo/` | Sustituye texto. |
| `/patrón/d` | Elimina líneas que coincidan con el patrón. |

---

## ⚠️ Errores comunes

| Error | Causa | Solución |
|--------|--------|-----------|
| `unterminated 's' command` | Falta un delimitador `/`. | Asegúrate de tener las tres partes del comando `s/antiguo/nuevo/`. |
| No imprime nada | Falta `-n` o `p`. | Añade `-n` o revisa la sintaxis. |
| Cambios no guardados | No se usó `-i`. | Añade `-i` para editar directamente el archivo. |

---

## 🪄 Tips y buenas prácticas

- Combina varios comandos con `-e`:
  ```bash
  sed -e 's/rojo/azul/g' -e '/verde/d' archivo.txt
  ```
- Usa otro delimitador si hay `/` en tu texto:
  ```bash
  sed 's|/home/user|~/|g' rutas.txt
  ```
- Muy útil para limpiar logs o archivos de texto grandes sin abrirlos.

---

## 🎯 Resumen

| Acción | Comando | Resultado |
|--------|----------|-----------|
| Mostrar línea 3 | `sed -n '3p' archivo.txt` | Muestra solo la línea 3. |
| Mostrar líneas impares | `sed -n 'p;n'` | Imprime una y salta otra. |
| Reemplazar palabra | `sed 's/a/b/' archivo.txt` | Sustituye la primera ocurrencia. |
| Reemplazar todas | `sed 's/a/b/g' archivo.txt` | Sustituye todas las ocurrencias. |
| Eliminar líneas con texto | `sed '/texto/d' archivo.txt` | Borra líneas que contengan “texto”. |

---

> 💬 *Consejo:* `sed` es una herramienta imprescindible para editar texto sobre la marcha.  
> Dominarlo te ahorrará muchas líneas de código en futuros scripts. 🚀
