# 🧩 EX08: clean

En este ejercicio vamos a crear un script llamado **clean** que buscará y eliminará archivos temporales o de respaldo en el directorio actual y sus subdirectorios.  
Estos archivos suelen ser creados por editores de texto (como Vim o Emacs) y no deben incluirse en los commits. 🧹

---

## ⚙️ Comando que utilizaremos

> - 🔍 **`find`** → buscará los archivos que terminen con `~` o que empiecen y terminen con `#`, y los eliminará.

---

## 🚀 Pasos a seguir

### 1️⃣ Crear el archivo `clean` con Vim

Abrimos el editor para crear nuestro script:
```bash
  vim clean
```

Una vez dentro de **Vim**:
1. Pulsa la tecla `i` para entrar en **modo inserción** ✍️  
2. Escribe el siguiente contenido:
   ```bash
   #!/bin/bash
   find . -type f \( -name "*~" -o -name "#*#" \) -print -delete
   ```

📘 Explicación del comando:

| Parte | Significado |
|--------|-------------|
| `find .` | Busca a partir del directorio actual (`.`) |
| `-type f` | Limita la búsqueda solo a archivos (no carpetas) |
| `\( ... \)` | Agrupa las condiciones (importante escaparlo con `\` en el script) |
| `-name "*~"` | Busca archivos que terminen en `~` |
| `-o` | Significa “o” (operador OR) |
| `-name "#*#"` | Busca archivos que empiecen y terminen con `#` |
| `-print` | Muestra por pantalla los archivos encontrados |
| `-delete` | Los elimina directamente |

💡 Se pide hacerlo **en una sola línea** y **sin usar `;` ni `&&`**, por eso todo se resuelve dentro del mismo comando `find`.

---

### 2️⃣ Guardar y salir de Vim

Presiona `Esc`, luego escribe:
```vim
:wq
```
y presiona **Enter**.

---

### 3️⃣ Dar permisos de ejecución al archivo

```bash
    chmod +x clean
```

💡 Esto convierte el archivo en un script ejecutable.

---

### 4️⃣ Probar el script

Puedes crear algunos archivos de prueba y luego ejecutar el script:

```bash
  touch test~
  touch #backup#
  ./clean
```

Resultado esperado:
```
./test~
./#backup#
```
✅ Los archivos listados se eliminan automáticamente.

---

## ⚠️ Errores comunes

| Error | Causa | Solución |
|--------|--------|-----------|
| `Permission denied` | No tiene permisos de ejecución | Usa `chmod +x clean` |
| `find: missing argument to -exec` | Faltan paréntesis o comillas | Revisa los `\(` y `\)` en el script |
| No borra nada | No hay archivos que coincidan o estás en la carpeta equivocada | Comprueba con `ls -a` |

---

## ✅ Resultado final esperado

El archivo `clean` debe verse así:

```bash
  #!/bin/bash
  find . -type f \( -name "*~" -o -name "#*#" \) -print -delete
```

Y al ejecutar `ls -l`, debería verse algo como:
```
-rwxr-xr-x 1 daz daz 65 Oct 26 16:12 clean
```

---

> 💬 *Consejo:* este tipo de scripts son muy útiles para mantener tu entorno limpio antes de hacer un commit.  
> Puedes ejecutarlo rápido con `./clean` siempre que quieras limpiar tu carpeta. 🚀
