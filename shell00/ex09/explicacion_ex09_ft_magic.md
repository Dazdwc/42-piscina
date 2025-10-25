# 🧙‍♂️ EX09: ft_magic

En este ejercicio vamos a crear un **archivo mágico** llamado `ft_magic`, que permitirá al comando `file` detectar archivos especiales que contengan la cadena `"42"` en el **byte 42** (recordando que empieza a contar desde el 0).  
Este tipo de archivos se utilizan para definir **tipos de archivo personalizados**.

---

## ⚙️ Comando que utilizaremos

> - 🔮 **`file`** → utiliza una base de datos de descriptores llamada “magic file” para identificar tipos de archivo en función de su contenido.  
> Nosotros crearemos el nuestro propio: `ft_magic`.

---

## 🚀 Pasos a seguir

### 1️⃣ Crear el archivo mágico con `vim`

Abrimos el editor para crear nuestro archivo `ft_magic`:

```bash
  vim ft_magic
```

Una vez dentro de Vim:
1. Presiona la tecla `i` para entrar en **modo inserción** ✍️  
2. Escribe el siguiente contenido exactamente:

   ```bash
   41    string    42    42 file
   ```

Luego presiona `Esc` y escribe `:wq` para guardar y salir.

---

## 📘 Explicación línea por línea

| Campo | Significado |
|--------|-------------|
| `41` | Es la **posición de byte** en la que empieza a buscar (`41` → el byte 42, ya que empieza desde 0) |
| `string` | Indica el **tipo de dato** que esperamos encontrar (una cadena de texto) |
| `42` | Es el **contenido** que debe encontrarse en esa posición |
| `42 file` | Es el **texto descriptivo** que mostrará el comando `file` al detectar una coincidencia |

---

## 🧪 Probar el archivo mágico

1️⃣ Creamos un archivo de prueba con algo de contenido:  
```bash
  echo "------------------------------------------42" > test42
```

2️⃣ Usamos el comando `file` con nuestro archivo mágico personalizado:  
```bash
  file -m ft_magic test42
```

📜 Resultado esperado:
```
test42: 42 file
```

---

## ⚠️ Errores comunes

| Error | Causa | Solución |
|--------|--------|-----------|
| No muestra “42 file” | La cadena “42” no está exactamente en el byte 42 | Añade o quita caracteres antes del “42” |
| “Invalid magic entry” | Hay tabulaciones o espacios mal colocados | Usa tabulaciones (`\t`), no espacios |
| No se reconoce el magic file | Falta indicar `-m ft_magic` en el comando | Usa `file -m ft_magic test42` |

---

## ✅ Resultado final esperado

El archivo `ft_magic` debe contener **una sola línea** y verse así:

```bash
  41    string    42    42 file
```

Y el comando:
```bash
  file -m ft_magic test42
```
Debe devolver:
```
test42: 42 file
```

---

> 💬 *Consejo:* el número de byte se empieza a contar desde **0**, así que el byte “42” corresponde al **offset 41**.  
> Puedes verificarlo con `od -c` o `xxd` si quieres visualizar las posiciones exactas. 🧠
