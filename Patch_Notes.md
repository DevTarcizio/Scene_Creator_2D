# Patch Notes v1.7

## Novas Funcionalidades

* **Sistema de Gizmo Interativo:** Implementada a classe `Gizmo` para controle de transformações em tempo real. O sistema utiliza composição de objetos `(arrowX, arrowY)` para criar uma representação visual dos eixos de movimento, ancorada dinamicamente aos objetos selecionados; A movimentação a partir deles ainda não foi implementada
* **Fábrica de Objetos:** Criação da função `createArrow(Color, Angle)` para suportar customização de cor e orientação angular, eliminando a redundância de código e otimizando a criação de entidades de interface.

## Refatoração
* **Shaders Novos Criados:** Criados 2 shaders novos que possuem a mesma função, são eles: `NormalVertexShader` e `NormalFragmentShader`, cuja possuem função única de passar a transformação adiante, sem transformações adicionais.

## TO-DO
* **Implementação das transformações a partir dos gizmos**. 