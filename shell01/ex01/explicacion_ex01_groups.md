# 🧩 explicacion_ex01_groups.md

Este ejercicio consiste en mostrar los grupos a los que pertenece el usuario `FT_USER`, con el formato pedido por el subject: separados por comas y sin salto de línea final.

---

## 🧠 Objetivo

A partir del usuario definido en la variable de entorno `FT_USER`, obtener su lista de grupos sin información adicional, eliminando duplicados innecesarios como el propio usuario o `root`, y dejando el resultado final con comas.

---

## 🧰 Herramientas utilizadas

| Comando | Función |
|--------|---------|
| `ls` | Para mostrar directorios (herramienta básica del módulo, aunque no se usa en el comando final) |
| `awk` | Para aplicar filtros y formatear a nuestro antojo |
| `tr` | Para sustituir caracteres o eliminarlos (`-d`) |

---

## 🧩 Desarrollo paso a paso

### 1️⃣ Listar los grupos del usuario
```bash
  groups $FT_USER
```
Esto devuelve algo como:
```text
FT_USER : group1 group2 group3 ...
```

### 2️⃣ Quitar la parte del nombre de usuario y los dos puntos
Usamos `awk` para partir la línea por ": " y quedarnos solo con la segunda parte (los grupos):
```bash
  groups $FT_USER | awk -F': ' '{print $2}'
```

Aquí `-F': '` indica que el separador de campos es `: ` (dos puntos y espacio).  
`$2` es la lista de grupos.

### 3️⃣ Cambiar espacios por comas y eliminar el salto de línea
```bash
  groups $FT_USER | awk -F': ' '{print $2}' | tr ' ' ',' | tr -d '\n'
```

- `tr ' ' ','` → convierte todos los espacios en comas.  
  Ejemplo: `group1 group2 group3` → `group1,group2,group3`  
- `tr -d '\n'` → elimina el salto de línea final para que el output sea todo seguido, sin línea nueva al final.

---

## ⚙️ Script final

Creamos el script:

```bash
  vim print_groups.sh
```

Contenido del archivo:

```bash
  #!/bin/bash
  groups $FT_USER | awk -F': ' '{print $2}' | tr ' ' ',' | tr -d '\n'
```

Le damos permisos y lo ejecutamos:

```bash
  chmod +x print_groups.sh
  ./print_groups.sh
```
