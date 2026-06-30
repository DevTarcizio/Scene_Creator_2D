# Patch Notes v1.7.1.2

## Bug Fixes
* **Corrigido Bug da seleção de multiplos objetos:** Antes, não era possível selecionar um objeto e depois deselecionar, agora está resolvido, pois ele sempre assume que não tem objeto e depois ele faz o loop de verificação
* **Corrigido posição da arrowY:** Removido conversão de graus para radianos dentro do createArrow, deixado apenas na mat3
* **Corrigido rotação do objeto:** o SliderAngle do ImGui trabalhava em radianos, como agora o amt3 converte de gruas para radianos, precisamos de valores em graus, por isso substitui por um sliderfloat com intervalo de 0.0f a 360.0f
 
## TO-DO
* **Implementação das transformações a partir dos gizmos**. 