# 🗜️ Comando `tar` — Archivar y comprimir archivos

## 🧠 Concepto
El comando **`tar`** (de *tape archive*) sirve para **agrupar varios archivos o carpetas en uno solo**.  
Por sí mismo **no comprime**, solo los empaqueta, pero combinado con otras opciones (como `-z`) puede **comprimir y descomprimir**.

Es muy útil para **guardar tus ejercicios** o **enviar proyectos completos** a otra persona o servidor sin perder estructura.

---

## ⚙️ Sintaxis general

```bash
tar [opciones] nombre_del_paquete.tar [archivos_o_carpetas]
```

---

## 📘 Ejemplos paso a paso

### 1️⃣ Crear un archivo `.tar`
```bash
tar -cf backup.tar ./ex00/
```
🧩 Crea un paquete llamado `backup.tar` con el contenido de la carpeta `ex00`.  
No borra los archivos originales, solo los **agrupa** dentro del `.tar`.

---

### 2️⃣ Crear un archivo `.tar.gz` (comprimido)
```bash
tar -czf proyecto.tar.gz ./ex01/
```
💨 Igual que antes, pero esta vez **comprime** el paquete con `gzip`.  
El resultado ocupa menos espacio.

- `-c` → crear un nuevo paquete  
- `-z` → comprimir con gzip  
- `-f` → nombre del archivo resultante

📦 Resultado: un solo archivo `proyecto.tar.gz` con todo el contenido de `ex01/`.

---

### 3️⃣ Extraer el contenido de un `.tar` o `.tar.gz`
```bash
tar -xf proyecto.tar.gz
```
📂 Desempaqueta el archivo y recupera todos los archivos originales en el directorio actual.

---

### 4️⃣ Ver qué contiene un archivo `.tar` sin extraerlo
```bash
tar -tf proyecto.tar.gz
```
👀 Muestra una lista con todos los archivos que hay dentro del paquete.

---

### 5️⃣ Extraer en una carpeta concreta
```bash
tar -xf proyecto.tar.gz -C ./backup/
```
📁 Extrae el contenido dentro de la carpeta `backup/` (debe existir previamente).

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-c` | Crear un archivo nuevo |
| `-x` | Extraer archivos |
| `-f` | Especifica el nombre del archivo |
| `-v` | Muestra el proceso en pantalla (*verbose*) |
| `-t` | Lista el contenido de un archivo tar |
| `-z` | Comprimir o descomprimir con gzip |
| `-C` | Extraer en una carpeta concreta |

---

## ⚠️ Errores comunes

🚫 **Error: “Cannot open: No such file or directory”**  
> Intentas empaquetar una carpeta o archivo que no existe.  
💡 Verifica con `ls` antes de ejecutar el comando.

🚫 **Error: “Not found in archive”**  
> Estás intentando extraer un archivo que no está dentro del `.tar`.  
💡 Usa `tar -tf archivo.tar` para comprobar qué contiene realmente.

🚫 **El archivo se ha creado pero no se comprime mucho**  
> Recuerda que `tar` agrupa, pero solo comprime si usas `-z` o `-j`.

---

## 🪄 Tips y buenas prácticas

- Usa `-v` para ver qué archivos se están incluyendo o extrayendo:  
  ```bash
  tar -cvf backup.tar ./ex00/
  ```  
  Verás cada archivo listado durante la creación.
- Siempre incluye la extensión correcta (`.tar` o `.tar.gz`) para que otros sepan qué tipo de archivo es.
- Si vas a mover tu proyecto entre máquinas o compartirlo, `tar` es la forma más limpia de empaquetarlo todo.

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Crear paquete | `tar -cf archivo.tar carpeta/` | Agrupa archivos sin comprimir |
| Comprimir | `tar -czf archivo.tar.gz carpeta/` | Agrupa y comprime con gzip |
| Extraer | `tar -xf archivo.tar.gz` | Recupera los archivos |
| Listar contenido | `tar -tf archivo.tar` | Muestra los archivos del paquete |
| Extraer en carpeta | `tar -xf archivo.tar -C ./destino/` | Desempaqueta en otra ruta |

---

> 💬 *“Tar es como una caja: metes cosas dentro, las cierras bien y puedes abrirla donde quieras.”* 📦  
> Aprende a usarla desde el principio, y tendrás siempre tu trabajo seguro y ordenado.
