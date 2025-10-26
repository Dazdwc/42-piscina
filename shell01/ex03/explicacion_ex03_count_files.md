# 🧩 explicacion_ex03_count_files.md

Este ejercicio consiste en contar cuántos archivos y directorios hay en el directorio actual y en todas sus subcarpetas.

---

## 🧠 Objetivo

Usar los comandos `find` y `wc` para realizar un conteo total de elementos (archivos y carpetas) dentro del árbol de directorios actual.

---

## 🧰 Herramientas utilizadas

| Comando | Función |
|----------|----------|
| `find` | Busca archivos y directorios dentro de una jerarquía |
| `wc` | Cuenta líneas, palabras o caracteres según la opción utilizada |

---

## 🧩 Desarrollo paso a paso

### 1️⃣ Buscar archivos y directorios
Usamos `find` para listar todo lo que sea **archivo** (`-type f`) o **directorio** (`-type d`) dentro del directorio actual (`.`):

```bash
  find . -type f -o -type d
```

Esto mostrará algo como:
```
.
./archivo.txt
./carpeta
./carpeta/otro.sh
```

### 2️⃣ Contar los resultados
Conectamos el resultado a `wc -l`, que cuenta las **líneas** recibidas como entrada:

```bash
  find . -type f -o -type d | wc -l
```

🔹 Cada línea del `find` representa un archivo o carpeta.  
🔹 `wc -l` cuenta cuántas hay en total.

---

## ⚙️ Script final

Creamos el script:

```bash
  vim count_files.sh
```

Contenido del archivo:

```bash
  #!/bin/bash
  find . -type f -o -type d | wc -l
```

Le damos permisos y lo ejecutamos:

```bash
  chmod +x count_files.sh
  ./count_files.sh
```

---

## ✅ Resultado esperado

El número total de archivos y directorios encontrados.

**Ejemplo:**
```
7
```
