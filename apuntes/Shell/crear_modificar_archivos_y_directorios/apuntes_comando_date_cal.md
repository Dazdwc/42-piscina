# ⏰ Comandos `date` y `cal` — Fecha, hora y calendario en la terminal

## 🧠 Concepto
Estos dos comandos son muy sencillos pero muy útiles tanto en la piscina como en scripting:

- `date` → Muestra la **fecha y hora actuales** del sistema. También puede mostrarlas en el formato que tú quieras.
- `cal` → Muestra un **calendario** directamente en la terminal.

Sirven para dejar marcas de tiempo en logs, generar nombres de archivos únicos, o simplemente saber en qué día vives cuando llevas demasiadas horas picando código 😵‍💫.

---

## ⚙️ Sintaxis general

```bash
date [opciones] [+formato]
cal [opciones] [mes] [año]
```

---

## 📘 `date` paso a paso

### 1️⃣ Ver la fecha y hora actuales
```bash
date
```
Ejemplo de salida:
```text
Sat Oct 25 14:37:12 CET 2025
```

Te da:
- Día de la semana (`Sat`)
- Mes (`Oct`)
- Día del mes (`25`)
- Hora (`14:37:12`)
- Zona horaria (`CET`)
- Año (`2025`)

---

### 2️⃣ Formatear la salida de `date`
Puedes decirle exactamente cómo quieres que muestre la fecha/hora usando `+` seguido de códigos de formato.

Ejemplo:
```bash
date "+%Y-%m-%d %H:%M:%S"
```
Salida:
```text
2025-10-25 14:37:12
```

Esto es súper útil para logs.  
Desglose:
- `%Y` → año (2025)
- `%m` → mes (01-12)
- `%d` → día (01-31)
- `%H` → hora en 24h (00-23)
- `%M` → minutos (00-59)
- `%S` → segundos (00-59)

---

### 3️⃣ Usar `date` para crear nombres únicos
```bash
echo "backup datos piscina" > backup_$(date "+%Y%m%d_%H%M%S").txt
```
Genera un archivo con marca de tiempo en el nombre, por ejemplo:
```text
backup_20251025_143712.txt
```

Muy útil para no machacar archivos anteriores.

---

### 4️⃣ Ver solo una parte concreta
```bash
date "+%H:%M"
```
🕒 Solo la hora y minutos.

```bash
date "+%A %d/%m/%Y"
```
📅 Día de la semana y fecha completa legible, ej: `Saturday 25/10/2025` (el idioma depende de tu locale).

---

## ⚙️ Códigos de formato comunes de `date`

| Código | Significado | Ejemplo |
|--------|-------------|---------|
| `%Y` | Año completo | `2025` |
| `%m` | Mes (01-12) | `10` |
| `%d` | Día (01-31) | `25` |
| `%H` | Hora (00-23) | `14` |
| `%I` | Hora (01-12) | `02` |
| `%M` | Minutos | `37` |
| `%S` | Segundos | `12` |
| `%A` | Día de la semana (texto) | `Saturday` |
| `%a` | Día de la semana corto | `Sat` |
| `%Z` | Zona horaria | `CET` |

---

## 📘 `cal` paso a paso

### 1️⃣ Ver el calendario del mes actual
```bash
cal
```
Te muestra el mes actual en forma de calendario.

Ejemplo (ficticio):
```text
    October 2025
Su Mo Tu We Th Fr Sa
          1  2  3  4
 5  6  7  8  9 10 11
12 13 14 15 16 17 18
19 20 21 22 23 24 25
26 27 28 29 30 31
```

---

### 2️⃣ Ver un mes y año concretos
```bash
cal 12 2025
```
📅 Muestra diciembre de 2025.

Formato:
```bash
cal [mes] [año]
```

---

### 3️⃣ Ver todo el año
```bash
cal -y
```
📆 Muestra el calendario de todo el año actual en bloque.

Puedes hacerlo para un año concreto:
```bash
cal -y 2026
```

---

## ⚠️ Errores comunes

🚫 **“date: invalid date”**  
> Ocurre si intentas usar `date` para *cambiar* la hora del sistema sin permisos, o le pasas un formato extraño sin `+`.  
💡 Recuerda:  
```bash
date "+%Y-%m-%d"
```  
y no  
```bash
date %Y-%m-%d
```

🚫 **`cal: command not found`**  
> En algunas distros muy mínimas `cal` no está instalado.  
💡 En Debian/Ubuntu se instala con:
```bash
sudo apt install ncal
```

🚫 **Locale raro**  
> Si ves los nombres de días/meses en inglés y quieres otro idioma, es por la configuración regional (`locale`). Eso ya es más avanzado, tranquilo 😉.

---

## 🪄 Tips y buenas prácticas

- Para registrar en logs en tus scripts de shell:
  ```bash
  echo "$(date '+%Y-%m-%d %H:%M:%S') -> empezando script..." >> log.txt
  ```

- Para saber qué día cae una entrega:
  ```bash
  cal 11 2025
  ```

- Para ver rápidamente solo la fecha (sin la hora):
  ```bash
  date "+%d/%m/%Y"
  ```

- Para ver cuánto llevas vivo en la piscina nocturna 😵‍💫:
  ```bash
  echo "Hora actual: $(date '+%H:%M')"
  ```

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Ver fecha y hora | `date` | Hora actual del sistema |
| Formato personalizado | `date "+%Y-%m-%d %H:%M:%S"` | Fechas limpias para logs |
| Nombre único con fecha | `archivo_$(date "+%Y%m%d_%H%M%S").txt` | Versionado rápido |
| Calendario del mes | `cal` | Vista rápida del mes actual |
| Calendario de un mes concreto | `cal 12 2025` | Mes/año específico |
| Calendario de todo el año | `cal -y` | 12 meses a la vez |

---

> 💬 *“date te dice en qué momento estás. cal te dice cuánto te queda para la entrega.”* ⏰📅  
> Son básicos para debugging, scripting y… para no perder la noción del tiempo en la piscina 😅.
