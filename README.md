# AutoAccess: Sistema de Control de Acceso y Barrera Automatizada

## 1. Información general del proyecto y equipo

- **Nombre del equipo:** Los Techies de San Isidro
- **Nombre del proyecto:** AutoAccess
- **Descripción:** Sistema automatizado de control de acceso vehicular mediante Arduino UNO.
- **Scrum Master:** Israel Fuentes

### Integrantes del equipo

- **Integrante 1:** Israel Fuentes
- **Integrante 2:** Tiziana Fioramonti

---

## 2. Problemática y justificación

En la actualidad, los accesos vehiculares a estacionamientos privados y complejos residenciales que funcionan de manera manual pueden generar demoras, congestión vehicular y dificultades para controlar el ingreso de automóviles.

Ante esta problemática, se propone desarrollar AutoAccess, un prototipo de barrera automatizada que permita gestionar el acceso mediante un sistema electrónico programado con Arduino UNO.

El sistema utiliza un sensor PIR para detectar movimiento y activar un servomotor encargado de levantar la barrera. Además, incorpora indicadores luminosos LED y un buzzer para comunicar el estado del sistema.

El objetivo es demostrar cómo la automatización puede mejorar la organización y la eficiencia de los accesos vehiculares.

**Solución propuesta:** desarrollar un prototipo funcional que detecte movimiento, levante y baje una barrera automáticamente, e informe mediante señales visuales y sonoras cuándo se habilita el paso.

---

## 3. Historia de usuario

**Historia de usuario:**

"Como conductor de un vehículo, quiero que la barrera de acceso se levante automáticamente al detectar mi presencia y que el sistema indique el estado del acceso mediante señales luminosas y sonoras, para ingresar al estacionamiento de manera rápida y sencilla".

### Criterios de aceptación

- El sistema debe detectar movimiento mediante el sensor PIR.
- El servomotor debe levantar la barrera cuando se detecte movimiento.
- El LED verde debe indicar que el paso está habilitado.
- El LED rojo debe indicar que la barrera está cerrada.
- El buzzer debe emitir una señal sonora durante la operación, según la programación.
- La barrera debe permanecer abierta durante el tiempo establecido y luego cerrarse automáticamente.

---

## 4. Requerimientos del sistema

### 4.1. Requerimientos funcionales

Los requerimientos funcionales describen las acciones que debe realizar el sistema.

- **RF1. Detección de movimiento:** el sistema debe detectar movimiento mediante el sensor PIR HC-SR501.
- **RF2. Apertura de la barrera:** el servomotor SG90 debe levantar la barrera hasta un ángulo aproximado de 90° cuando se detecte movimiento.
- **RF3. Señalización visual:** el sistema debe apagar el LED rojo y encender el LED verde cuando la barrera esté abierta.
- **RF4. Señalización sonora:** el buzzer debe emitir un aviso sonoro durante la apertura, de acuerdo con la lógica programada.
- **RF5. Cierre automático:** la barrera debe permanecer abierta durante aproximadamente 5 segundos y después regresar a su posición inicial.
- **RF6. Restablecimiento del estado:** al cerrarse la barrera, el LED verde debe apagarse y el LED rojo debe encenderse.

### 4.2. Requerimientos no funcionales

Los requerimientos no funcionales establecen las condiciones de calidad y funcionamiento del sistema.

- **RNF1. Tiempo de respuesta:** el sistema debe responder rápidamente a la detección de movimiento, procurando accionar el servomotor en menos de un segundo.
- **RNF2. Seguridad mecánica:** el movimiento del servomotor debe limitarse al rango establecido para evitar daños en el mecanismo.
- **RNF3. Visibilidad:** los indicadores LED deben permitir reconocer fácilmente el estado de la barrera en condiciones normales de iluminación.
- **RNF4. Mantenibilidad:** el código debe estar organizado y comentado para facilitar su comprensión y modificación.
- **RNF5. Confiabilidad:** el sistema debe completar correctamente los ciclos de apertura y cierre durante las pruebas realizadas.

---

## 5. Componentes, conexiones y presupuesto

Los siguientes valores son estimaciones de referencia y deben actualizarse según los precios reales de compra.

| Componente           | Cantidad | Conexión o función        |  Costo estimado |
| -------------------- | -------: | ------------------------- | --------------: |
| Arduino UNO          |        1 | Controlador principal     |     $12.000 ARS |
| Sensor PIR HC-SR501  |        1 | Salida digital al pin 2   |      $3.000 ARS |
| Servomotor SG90      |        1 | Señal de control al pin 9 |      $4.500 ARS |
| LED rojo y LED verde |        2 | Pines digitales 4 y 3     |      $1.000 ARS |
| Buzzer               |        1 | Pin digital 5             |      $1.500 ARS |
| Protoboard y cables  |    1 kit | Montaje y conexiones      |      $3.000 ARS |
| **Total estimado**   |          |                           | **$25.000 ARS** |

### 5.1. Conexiones principales

- **Sensor PIR HC-SR501:** alimentación a 5 V y GND; salida de señal al pin digital 2.
- **Servomotor SG90:** señal de control al pin digital 9; alimentación y tierra según las especificaciones del componente.
- **LED rojo:** conectado al pin digital 4 mediante una resistencia limitadora de corriente.
- **LED verde:** conectado al pin digital 3 mediante una resistencia limitadora de corriente.
- **Buzzer:** conectado al pin digital 5 y a GND, respetando las especificaciones del componente.
- **Arduino UNO :** recibe y procesa las señales del sensor y controla los dispositivos de salida.

**Importante:** cada LED debe contar con su resistencia limitadora. La alimentación del servomotor debe ser adecuada para su consumo y todas las tierras deben compartir una referencia común. Se deben verificar las conexiones antes de energizar el circuito.

---

## 6. Diagrama de flujo lógico

El funcionamiento general del sistema sigue esta secuencia:

1. Inicio del programa.
2. Configuración de los pines de entrada y salida.
3. Inicialización del servomotor y de los indicadores.
4. Lectura del sensor PIR.
5. Si no se detecta movimiento, la barrera permanece cerrada y el LED rojo encendido.
6. Si se detecta movimiento, se activa el buzzer según la programación y el servomotor levanta la barrera.
7. Se apaga el LED rojo y se enciende el LED verde.
8. La barrera permanece abierta durante aproximadamente 5 segundos.
9. El servomotor devuelve la barrera a su posición inicial.
10. Se apaga el LED verde y se enciende el LED rojo.
11. El sistema vuelve a leer el sensor y repite el ciclo.

### Diagrama de flujo

Insertar en esta sección una imagen del diagrama de flujo que represente la secuencia de funcionamiento del sistema.

---

## 7. Desarrollo del proyecto por sprints

### Sprint 1: Ideación, análisis y configuración

**Período:** del 23/09 al 01/10.

**Objetivo:** definir la problemática, establecer los requisitos del sistema y organizar el trabajo del equipo.

**Actividades realizadas:**

- Identificación de la problemática relacionada con el control manual de accesos vehiculares.
- Definición de la propuesta de solución mediante un sistema automatizado.
- Elaboración de la historia de usuario.
- Redacción de los requerimientos funcionales y no funcionales.
- Identificación de los componentes electrónicos necesarios.
- Elaboración del presupuesto inicial.
- Creación del repositorio de GitHub.
- Organización de las ramas de trabajo para los integrantes.
- Presentación y revisión inicial de los avances con la docente.

**Resultado esperado:** contar con una propuesta definida, los requisitos documentados y el entorno de trabajo preparado.

### Sprint 2: Diseño, simulación y programación en Wokwi

**Período:** del 07/10 al 08/10.

**Objetivo:** diseñar el circuito, desarrollar el código y verificar el funcionamiento lógico mediante simulación.

**Actividades realizadas:**

- Diseño del circuito en Wokwi.
- Incorporación del Arduino UNO, el sensor PIR, el servomotor, los LED con sus resistencias y el buzzer.
- Programación del sistema mediante el entorno de desarrollo de Arduino.
- Utilización de la biblioteca `Servo.h` para controlar el servomotor.
- Configuración de los pines de entrada y salida.
- Pruebas de detección de movimiento.
- Verificación de la apertura y el cierre automático de la barrera.
- Ajuste de los tiempos de funcionamiento.
- Comprobación de los indicadores luminosos y sonoros.

**Evidencia del sprint:** insertar una captura de pantalla de la simulación funcionando en Wokwi.

**Resultado esperado:** disponer de un circuito simulado y un programa que cumpla con la lógica prevista.

### Sprint 3: Montaje físico, pruebas y documentación final

**Período:** del 14/10 al 15/10.

**Objetivo:** preparar el prototipo físico, realizar las pruebas finales y completar la documentación del proyecto.

**Actividades realizadas:**

- Verificación de los componentes electrónicos necesarios.
- Adquisición de los componentes disponibles para el montaje.
- Armado del circuito sobre una protoboard.
- Construcción de la maqueta de la barrera vehicular.
- Carga del programa en el Arduino UNO .
- Pruebas de funcionamiento con los componentes físicos.
- Verificación del sensor, el servomotor, los LED y el buzzer.
- Corrección de errores detectados durante las pruebas.
- Registro de evidencias del montaje y del funcionamiento.
- Actualización de la bitácora de avances.
- Redacción y revisión final del archivo `README.md`.
- Preparación del prototipo para la presentación y defensa del proyecto.

**Evidencias del sprint:** insertar fotografías reales del circuito físico, la maqueta y las pruebas de funcionamiento.

**Resultado esperado:** obtener un Producto Mínimo Viable (MVP) que permita demostrar el funcionamiento básico de AutoAccess.

---

## 8. Bitácora de avances

La bitácora permite registrar las tareas realizadas, los resultados obtenidos y los problemas identificados durante el desarrollo.

| Etapa    | Actividad                                              | Resultado o evidencia                |
| -------- | ------------------------------------------------------ | ------------------------------------ |
| Sprint 1 | Análisis de la problemática y definición de requisitos | Documento inicial del proyecto       |
| Sprint 1 | Organización del equipo y creación del repositorio     | Repositorio y ramas de trabajo       |
| Sprint 2 | Diseño del circuito en Wokwi                           | Simulación del sistema               |
| Sprint 2 | Desarrollo y prueba del código                         | Programa y pruebas de funcionamiento |
| Sprint 3 | Montaje del circuito físico                            | Fotografías del prototipo            |
| Sprint 3 | Pruebas del sistema completo                           | Registro de resultados               |
| Sprint 3 | Elaboración de la documentación final                  | README.md actualizado                |

Los resultados y las evidencias deben corresponder a las tareas efectivamente realizadas por el equipo.

---

## 9. Organización del equipo y roles

Para facilitar la organización del trabajo, se propone la siguiente distribución de responsabilidades:

- **Scrum Master:** coordina las actividades del equipo, organiza las reuniones y realiza el seguimiento de las tareas.
- **Responsable de programación:** desarrolla y mantiene el código del sistema.
- **Responsable de hardware:** organiza las conexiones, el montaje físico y las pruebas de los componentes.
- **Responsable de documentación:** mantiene actualizados el README, la bitácora y las evidencias del proyecto.

Los integrantes pueden asumir más de una responsabilidad según las necesidades del equipo.

### Organización del trabajo con GitHub

- **`main`:** contiene la versión principal y estable del proyecto.
- **`integrante-1`:** rama de trabajo del primer integrante.
- **`integrante-2`:** rama de trabajo del segundo integrante.
- **`integrante-3`:** rama de trabajo del tercer integrante.

Cada integrante debe trabajar en su rama, registrar los cambios mediante commits y coordinar la integración de las modificaciones en la rama principal.

---

## 10. Pruebas y validación del sistema

Para verificar el funcionamiento de AutoAccess, se deben realizar las siguientes pruebas:

| Prueba                  | Procedimiento                 | Resultado esperado                      |
| ----------------------- | ----------------------------- | --------------------------------------- |
| Detección de movimiento | Activar el sensor PIR         | El sistema reconoce la señal del sensor |
| Apertura de la barrera  | Provocar una detección válida | El servomotor levanta la barrera        |
| Señalización verde      | Abrir la barrera              | Se enciende el LED verde                |
| Señalización roja       | Cerrar la barrera             | Se enciende el LED rojo                 |
| Aviso sonoro            | Activar el ciclo de apertura  | El buzzer emite la señal programada     |
| Cierre automático       | Esperar el tiempo configurado | La barrera vuelve a su posición inicial |

Los resultados deben registrarse después de ejecutar cada prueba. Si alguna prueba no se completa correctamente, se debe documentar el problema y la corrección aplicada.

---

## 11. Alcance y limitaciones del prototipo

### Alcance

AutoAccess tiene como finalidad demostrar el funcionamiento básico de un sistema automatizado de control de acceso vehicular.

El prototipo permite:

- Detectar movimiento mediante un sensor PIR.
- Accionar una barrera mediante un servomotor.
- Indicar el estado del acceso mediante LED.
- Emitir avisos sonoros mediante un buzzer.
- Ejecutar un ciclo automático de apertura y cierre.

### Limitaciones

- El sensor PIR detecta cambios en la radiación infrarroja asociados al movimiento, pero no identifica específicamente vehículos.
- El prototipo no verifica matrículas ni reconoce usuarios autorizados.
- El sistema no incorpora un mecanismo de detección de obstáculos debajo de la barrera.
- La maqueta no está diseñada para soportar el peso de una barrera vehicular real.
- El tiempo de apertura y cierre depende de la programación y de las condiciones de funcionamiento del hardware.

Por estas razones, el proyecto constituye un prototipo educativo y no un sistema de seguridad listo para instalar en un estacionamiento real.

---

## 12. Posibles mejoras futuras

En futuras versiones del proyecto se podrían incorporar las siguientes mejoras:

- Un sensor ultrasónico para detectar la presencia y la distancia de los vehículos.
- Un sistema de identificación de usuarios mediante tarjetas RFID.
- Una pantalla LCD para mostrar mensajes informativos.
- Un contador de vehículos que registre las entradas y salidas.
- Un mecanismo de detección de obstáculos para evitar el cierre de la barrera cuando exista un objeto debajo.
- Un sistema de comunicación inalámbrica para supervisar el acceso de forma remota.
- Una estructura mecánica más resistente para una maqueta de mayor tamaño.

Estas mejoras permitirían ampliar las funcionalidades del prototipo y acercarlo a un sistema de control de acceso más completo.

---

## 13. Conclusión

El proyecto AutoAccess propone una solución educativa a la problemática del control manual de accesos vehiculares mediante la aplicación de conceptos de electrónica, programación y automatización.

A través de Arduino UNO, un sensor PIR, un servomotor, indicadores LED y un buzzer, se busca demostrar cómo diferentes componentes pueden integrarse para ejecutar una secuencia automática de detección, apertura, señalización y cierre.

El desarrollo del proyecto también permite poner en práctica el trabajo en equipo, la planificación mediante sprints, la organización de tareas y el uso de GitHub para administrar versiones del código y la documentación.

En conclusión, AutoAccess constituye una base para comprender el funcionamiento de los sistemas automatizados y desarrollar futuras soluciones tecnológicas.

---

## 14. Recursos y herramientas utilizadas

- **Arduino UNO :** plataforma de desarrollo electrónico.
- **Arduino IDE:** entorno para escribir, compilar y cargar el programa.
- **Wokwi:** plataforma de simulación de circuitos electrónicos.
- **GitHub:** alojamiento del repositorio y control de versiones.
- **Markdown:** formato utilizado para estructurar la documentación.
- **Markdown Live Preview:** herramienta para visualizar el formato del archivo README.

---

**Proyecto Integrador de Automatización con Arduino UNO **

**Equipo:** Los Techies de San Isidro

**Proyecto:** AutoAccess
