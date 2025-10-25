# 🧩 EX08: Aplicar un archivo `patch`

En este ejercicio aprenderemos a **aplicar un archivo de diferencias (`sw.diff`)** a un archivo base (`a`) para generar un nuevo archivo (`b`).  
El objetivo es entender cómo los comandos `cp` y `patch` trabajan juntos para reconstruir archivos a partir de un diff. 🧠

---

## ⚙️ Comandos que utilizaremos

> - 📄 **`cp`** → para crear el archivo `b` copiando el contenido de `a`.  
> - 🧩 **`patch`** → para aplicar las diferencias contenidas en el archivo `sw.diff` al nuevo archivo `b`.

---

## 🚀 Pasos a seguir

### 1️⃣ Crear el archivo `b` con el contenido de `a`

Primero, hacemos una copia exacta de `a` y la llamamos `b`:

```bash
cp a b
```

📘 Explicación:
- `cp` (copy) crea un nuevo archivo idéntico a `a` llamado `b`.  
- Este `b` será el archivo sobre el que aplicaremos el parche.

---

### 2️⃣ Aplicar el parche `sw.diff` sobre el archivo `b`

Usamos el comando `patch` para modificar `b` siguiendo las instrucciones que contiene `sw.diff`:

```bash
patch b < sw.diff
```

📘 Explicación:
- `patch` → aplica los cambios indicados por un archivo `.diff` o `.patch`.  
- `b` → es el archivo sobre el que se aplicarán los cambios.  
- `< sw.diff` → redirige el contenido de `sw.diff` al comando `patch` (es decir, le “entrega” las diferencias).

💡 Si todo va bien, el archivo `b` quedará actualizado y coincidirá con el archivo `b` original que se usó para crear `sw.diff`.

---

### 3️⃣ Verificar que el parche se aplicó correctamente

Podemos comparar los archivos `a` y `b` con el comando `diff`:

```bash
diff a b
```

✅ Si el comando **no muestra nada**, significa que el parche se aplicó correctamente y que `b` está como debe estar.

---

## ⚠️ Errores comunes

| Error | Causa | Solución |
|--------|--------|-----------|
| `Hunk #1 FAILED` | El archivo `a` (o `b`) no coincide con el original usado para generar el diff | Asegúrate de usar el `a` correcto y crear `b` desde cero |
| `No such file or directory` | No existe el archivo `b` o `sw.diff` | Verifica que ambos estén en el mismo directorio |
| `patch unexpectedly ends in middle of line` | El diff está corrupto o incompleto | Descarga o copia de nuevo `sw.diff` |

---

## ✅ Resultado final esperado

Al final del ejercicio deberías tener los siguientes archivos:

```
a
b
sw.diff
```

Y al ejecutar:
```bash
diff a b
```
el resultado debe ser **sin salida**, lo que indica que el parche se aplicó correctamente ✅

---

> 💬 *Consejo:* Este proceso es el inverso a generar un diff.  
> Mientras `diff a b > sw.diff` crea un archivo de diferencias,  
> el comando `patch b < sw.diff` lo **reconstruye**. 🚀
