# Patch Notes v1.5

## Novas Funcionalidades

* **Núcleo da Engine (App Core):** Criação da classe `App` para gerenciar o estado global, o tempo (Delta Time) e o ciclo de vida da aplicação de forma orientada a objetos.

## Refatoração

* **Isolamento da `main`:** Todo o código procedural de configuração do SDL3 e ImGui foi removido da função principal, que agora apenas instancializa e roda a `App`.
* **Arquitertura do GameLoop:** O laço principal foi rigidamente fatiado seguindo o padrão da indústria: `processInput()` (Eventos), `update()` (Lógica) e `renderScene()` (Desenho).
* **Fundação da Scene:** Criação da classe base abstrata `Scene`, preparando o terreno para gerenciar múltiplos objetos.

## TO-DO
- Implementar a classe Concreta `EditorScene`