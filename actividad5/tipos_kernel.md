# Conceptos de Sistemas Operativos

## Tipos de Kernel y sus diferencias

### 1. **Monolithic Kernel**
- Arquitectura donde todo el sistema operativo se ejecuta en el espacio del kernel.
- Es rápido debido a la comunicación directa entre componentes del kernel.
- Es menos seguro y más propenso a errores, ya que un fallo en un módulo puede colapsar todo el sistema.

### 2. **Microkernel**
- Solo contiene los componentes esenciales del sistema operativo, como la gestión de memoria y la planificación de procesos; otros servicios se ejecutan en el espacio de usuario.
- Es más seguro y estable, ya que un fallo en un módulo no afecta directamente al kernel.
- Es más lento que los kernels monolíticos debido a la sobrecarga de la comunicación entre procesos (IPC).

### 3. **Hybrid Kernel**
- Combina características de kernels monolíticos y microkernels.
- Permite que algunos servicios se ejecuten en el espacio del kernel para mejorar el rendimiento, mientras que otros se ejecutan en el espacio de usuario para mejorar la seguridad y estabilidad.
- Ejemplos de sistemas con hybrid kernel son Windows NT y macOS.

### 4. **Exokernel**
- Es un tipo de kernel que permite a las aplicaciones tener más control sobre el hardware.
- El kernel solo proporciona una interfaz mínima y permite que las aplicaciones administren recursos directamente.
- Esto puede proporcionar un mejor rendimiento, pero es más difícil de programar y mantener.

## User Mode vs Kernel Mode

- **User Mode**: Es el modo en el que se ejecutan las aplicaciones de usuario. No tienen acceso directo al hardware ni a la memoria del sistema. Cualquier intento de realizar operaciones privilegiadas resulta en una excepción. Esto proporciona una capa de seguridad, evitando que las aplicaciones dañen el sistema operativo o el hardware.

- **Kernel Mode**: Es el modo en el que se ejecuta el kernel del sistema operativo. Tiene acceso completo al hardware del sistema y puede ejecutar cualquier instrucción de la CPU. Las operaciones críticas del sistema, como la gestión de memoria y la planificación de procesos, se ejecutan en el modo kernel.

## Interruptions vs Traps

- **Interruptions**: Son señales generadas por hardware o software que interrumpen la ejecución normal del flujo de instrucciones de la CPU para atender eventos importantes (por ejemplo, una solicitud de E/S completada). Las interrupciones son asíncronas y pueden ocurrir en cualquier momento, activando una rutina de servicio de interrupción (ISR).

- **Traps**: Son un tipo de interrupción específica que ocurre debido a una condición de error o una solicitud explícita del programa en ejecución (por ejemplo, una división por cero o una llamada al sistema). A diferencia de las interrupciones, las traps son sincrónicas y ocurren debido a la ejecución de instrucciones específicas del programa.

En resumen, las interrupciones suelen ser asíncronas y están generadas por eventos externos, mientras que las traps son sincrónicas y están relacionadas con la ejecución del código del programa.

