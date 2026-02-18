# Fundamentos de Seguridad de la Información  

---

> “La seguridad no se trata de eliminar amenazas, sino de gestionar el riesgo de manera inteligente.”

---

## 1. La Triada CIA

La seguridad de la información se fundamenta en tres principios inseparables: **Confidencialidad, Integridad y Disponibilidad (CIA)**.  
Estos pilares definen el estándar mínimo que cualquier sistema debe cumplir.

| Principio | Propósito | Mecanismos Comunes |
|------------|------------|--------------------|
| **Confidencialidad** | Evitar accesos no autorizados | Cifrado, autenticación, segmentación |
| **Integridad** | Prevenir modificaciones indebidas | Hashes, firmas digitales, control de cambios |
| **Disponibilidad** | Garantizar acceso oportuno | Redundancia, respaldos, mitigación DoS |

Un sistema puede ser muy disponible, pero si no es íntegro o confidencial, sigue siendo inseguro.  
La fortaleza real radica en mantener equilibrio entre los tres.

---

## 2. Triángulo FSU

En el diseño de sistemas existe una tensión natural entre:

- **Seguridad**
- **Funcionalidad**
- **Usabilidad**

Aumentar controles puede reducir comodidad.  
Aumentar usabilidad puede abrir vulnerabilidades.  

La seguridad efectiva no consiste en maximizar uno de estos factores, sino en diseñar un balance que permita operar con eficiencia sin comprometer la protección.

---

## 3. Relación entre Amenaza y Vulnerabilidad

La gestión de la seguridad parte de comprender cómo interactúan los siguientes elementos:

- **Vulnerabilidad:** Debilidad explotable en un sistema.
- **Amenaza:** Actor o evento con capacidad de explotar esa debilidad.
- **Impacto:** Consecuencia negativa si la amenaza se materializa.
- **Riesgo:** Probabilidad de que ocurra el impacto.

### Modelo conceptual
Sin vulnerabilidad no hay explotación.  
Sin impacto relevante, el riesgo puede ser aceptable.  

La seguridad moderna no busca eliminar todas las amenazas (lo cual es imposible) sino reducir el riesgo a niveles tolerables.

---

## 4. Autenticación Multifactor (MFA)

La autenticación tradicional basada únicamente en contraseñas es insuficiente.  
La **Autenticación Multifactor (MFA)** introduce redundancia en la verificación de identidad:

| Categoría | Ejemplo | Tipo de Control |
|------------|----------|----------------|
| Algo que sabes | Contraseña, PIN | Conocimiento |
| Algo que tienes | Token, dispositivo móvil | Posesión |
| Algo que eres | Huella, reconocimiento facial | Biometría |

El MFA no fortalece una contraseña; fortalece el sistema de autenticación al reducir la probabilidad de acceso no autorizado incluso si un factor es comprometido.

---

## 5. Relación entre conceptos

Los conceptos analizados no funcionan de manera aislada.  

- La **Triada CIA** define qué proteger.  
- El triángulo de usabilidad define cómo proteger.  
- La gestión del riesgo define cuándo y cuánto proteger.  
- El MFA define cómo controlar el acceso.  

La seguridad de la información no es un conjunto de herramientas, sino una disciplina estratégica basada en principios, análisis y equilibrio operativo.
