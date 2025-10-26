# 🧩 Comando `patch` — Aplicar diferencias entre archivos

## 🧠 Concepto
El comando **`patch`** se utiliza para **aplicar cambios (diferencias) a un archivo base**, generalmente a partir de un archivo generado con `diff`.  
Es una herramienta muy usada en desarrollo, sobre todo para **actualizar versiones de código, aplicar parches o reconstruir archivos**.  

💬 En resumen:
> `diff` crea las diferencias 🧾  
> `patch` las aplica 🔧

---

## ⚙️ Sintaxis general
```bash
patch [archivo_destino] < archivo_diff
```

📘 Ejemplo básico:
```bash
patch b < sw.diff
```
Esto aplica las diferencias contenidas en `sw.diff` sobre el archivo `b`.

---

## 📦 Uso típico en la piscina

En los ejercicios de la piscina, `patch` se usa para **reconstruir un archivo `b`** a partir del original `a` y un archivo `sw.diff`:

```bash
cp a b
patch b < sw.diff
```

✅ Resultado: el archivo `b` pasa a ser idéntico al que se usó para crear `sw.diff` originalmente.

---

## 🧩 Otras formas de uso

### 1️⃣ Aplicar directamente un diff sin especificar el archivo
Si el archivo `.diff` incluye los nombres originales de los archivos:
```bash
patch < sw.diff
```
👉 En este caso, `patch` leerá dentro de `sw.diff` qué archivo debe modificar.

---

### 2️⃣ Aplicar un diff a varios archivos a la vez
Algunos diffs (como los creados con `diff -r`) pueden contener cambios para varios archivos.  
Puedes aplicarlos directamente en su carpeta raíz:
```bash
patch -p1 < update.diff
```
- `-p1` elimina el primer nivel de directorios del diff (para evitar rutas absolutas).

---

## 🧠 Opciones útiles

| Opción | Descripción |
|--------|--------------|
| `-pN` | Ignora N niveles de directorio en las rutas del diff. Ej: `-p1` o `-p0`. |
| `--dry-run` | Simula la aplicación del parche sin modificar nada. Ideal para probar. |
| `-R` | Reversa el parche (revierte los cambios aplicados). |
| `-i archivo.diff` | Permite indicar el diff sin usar redirección (`<`). |
| `-F0` | Fuerza el parche incluso si no encajan exactamente las líneas (tolerante). |

---

## 🔍 Ejemplos prácticos

### ➕ Aplicar un parche
```bash
patch b < sw.diff
```

### 🔄 Revertir un parche
```bash
patch -R b < sw.diff
```

### 🧪 Probar antes de aplicar
```bash
patch --dry-run b < sw.diff
```

### 🧩 Aplicar un parche con nombres internos
```bash
patch < sw.diff
```

### 💪 Forzar aplicación (tolerar diferencias mínimas)
```bash
patch -F0 b < sw.diff
```

---

## ⚠️ Errores comunes

| Error | Causa | Solución |
|--------|--------|-----------|
| `Hunk #1 FAILED` | El archivo no coincide con el original del diff | Asegúrate de usar el mismo `a` que se usó para generar el diff |
| `patch unexpectedly ends in middle of line` | El diff está dañado o incompleto | Descarga o copia nuevamente `sw.diff` |
| `No such file or directory` | Falta el archivo base o el diff | Verifica rutas y nombres |
| `Reversed (or previously applied) patch detected!` | Intentas aplicar dos veces el mismo diff | Usa `-R` para revertirlo o comprueba si ya se aplicó |

---

## 🧾 Verificación

Después de aplicar un parche, puedes comprobar que todo se aplicó correctamente ejecutando:
```bash
diff a b
```
Si no se muestra ninguna salida, ¡todo está correcto! ✅

---

## 🎯 Resumen rápido

| Acción | Comando |
|--------|----------|
| Aplicar un parche | `patch b < sw.diff` |
| Revertir un parche | `patch -R b < sw.diff` |
| Simular sin aplicar | `patch --dry-run b < sw.diff` |
| Aplicar con tolerancia | `patch -F0 b < sw.diff` |
| Aplicar leyendo nombres del diff | `patch < sw.diff` |

---

> 💬 *Recuerda:* En la piscina, el comando `patch` se usa sobre todo para **aprender a reconstruir archivos y entender cómo funcionan los cambios en texto plano**.  
> Dominarlo te prepara para cuando uses herramientas más grandes como `git apply` o `git diff`. 🚀
