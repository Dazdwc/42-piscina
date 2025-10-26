# 🧩 explicacion_ex06_skip.md

Este ejercicio consiste en mostrar el listado de archivos y directorios con `ls -l`, aplicando un filtro para mostrar **solo las líneas impares** mediante el uso de `awk`.

---

## 🧠 Objetivo

Utilizar el comando `ls` para listar el contenido de un directorio y aplicar un filtrado que muestre únicamente las **líneas impares** del resultado.

---

## 🧰 Herramientas utilizadas

| Comando | Función |
|----------|----------|
| `ls` | Muestra el contenido del directorio actual |
| `awk` | Permite aplicar filtros y manipular el formato del texto |

---

## 🧩 Desarrollo paso a paso

### 1️⃣ Mostrar el contenido del directorio
```bash
  ls -l
```
Esto muestra una lista detallada con permisos, propietario, grupo, tamaño y nombre de cada archivo o carpeta.

### 2️⃣ Filtrar las líneas impares
Con `awk`, podemos seleccionar solo las líneas con número impar de registro (`NR`):
```bash
  awk 'NR%2!=0'
```
- `NR` es el número de línea actual.  
- `NR%2!=0` significa “si el número de línea módulo 2 es distinto de 0”, es decir, **línea impar**.

---

## ⚙️ Script completo

Creamos el script con **vim** y lo hacemos ejecutable:

```bash
  vim skip.sh
```

Contenido del archivo:

```bash
  #!/bin/bash
  ls -l | awk 'NR%2!=0'
```

Damos permisos de ejecución:

```bash
  chmod +x skip.sh
```

Y lo ejecutamos con:

```bash
  ./skip.sh
```

---

## ✅ Resultado esperado

Muestra solo las líneas impares del listado generado por `ls -l`.

**Ejemplo:**
```
total 8
drwxr-xr-x 2 user user 4096 Oct 26 09:00 carpeta1
-rw-r--r-- 1 user user  512 Oct 26 09:01 archivo.txt
```
*(Las líneas pares quedan omitidas)*
