# Patch Notes v1.6.3

## Novas Funcionalidades

* **Sistema de Seleção:** Implementação final da lógica de colisão ponto-retângulo (AABB), permitindo a seleção interativa de objetos no World Space via clique do rato.
* **Inspetor de Propridades:** Adição de um painel de controlo no ImGui que se liga dinamicamente ao objeto selecionado, permitindo a edição de transformações (Posição X/Y) em tempo real, sem necessidade de recompilação.
* **Detecção de Colisão:** criação do método de colisão com a introdução do método `Object::contains()`, encapsulando a lógica geométrica e promovendo o princípio de coesão na classe `Object`.

## TO-DO
* **Inspetor de Propriedades:** Fazer o ImGui exibir dinamicamente os dados (Posição, Escala, Cor) do objeto que estiver atualmente selecionado na `EditorScene`.