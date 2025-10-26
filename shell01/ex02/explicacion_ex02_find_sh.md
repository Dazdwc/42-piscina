# 🧩 explicacion_ex02_find_sh.md

Este ejercicio consiste en buscar todos los archivos con extensión `.sh` en el directorio actual y sus subdirectorios, y mostrar solo sus nombres sin la ruta ni la extensión `.sh`.

---

## 🧠 Objetivo

Usar el comando `find` para localizar archivos, y `basename` para mostrar únicamente el nombre de cada uno, eliminando la parte de la ruta y la extensión `.sh`.

---

## 🧰 Herramientas utilizadas

| Comando | Función |
|----------|----------|
| `find` | Busca archivos y directorios dentro de una jerarquía |
| `basename` | Elimina la ruta y opcionalmente la extensión del nombre del archivo |

---

## 🧩 Desarrollo paso a paso

### 1️⃣ Buscar archivos `.sh`
Usamos `find` para buscar en el directorio actual (`.`) todos los archivos (`-type f`) que terminen en `.sh`:
```bash
find . -type f -name "*.sh"
```

Esto devolverá rutas completas, por ejemplo:
```
./start.sh
./scripts/deploy.sh
./scripts/old/cleanup.sh
```

### 2️⃣ Quitar la ruta y la extensión
Para mostrar solo el nombre del archivo sin su ruta ni `.sh`, usamos `basename` dentro de `-exec`:

```bash
find . -type f -name "*.sh" -exec basename {} .sh \;
```

Desglose:
- `-exec` → ejecuta un comando por cada archivo encontrado.
- `{}` → se sustituye por la ruta del archivo encontrado.
- `basename {} .sh` → elimina la ruta y la extensión `.sh`.
- `\;` → marca el final del comando.

El resultado será algo como:
```
start
deploy
cleanup
```

---

## ⚙️ Script final

Creamos el script con:

```bash
vim find_sh.sh
```

Contenido del archivo:

```bash
#!/bin/bash
find . -type f -name "*.sh" -exec basename {} .sh \;
```

Le damos permisos y lo ejecutamos:

```bash
chmod +x find_sh.sh
./find_sh.sh
```

---

📘 *Archivo de explicación práctica — 42 Barcelona*  
✍️ **Autor:** Daniel Zafra (Dazdwc)
