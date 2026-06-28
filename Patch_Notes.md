# Patch Notes v1.5.1

## Novas Funcionalidades

* **Sistemas de Cenas Implementado:** Implementação da classe `EditorScene`. A cena agora atua como dona (owner) da Câmera e de um contêiner de múltiplos objetos (utilizando `std::unique_ptr` e semântica de movimento `std::move` para garantir o Memory Safety), renderizando a geometria dinamicamente a cada quadro.

## Refatoração

* **Injeção de Dependências:** O rasterizador (`Renderer`) e o `pipelineContext` agora são emprestados por referência (&) da Aplicação para a Cena a cada quadro, eliminando variáveis globais e acoplamentos.

## TO-DO
* **Sistema de Entindades:** Transformar os objetos hardcoded em Entidades dinâmicas que podem ser adicionadas ou removidas da cena em tempo de execução.
* **Seleção de Objetos:** Implementar lógica matemática para converter o clique do mouse em coordenadas do mundo (World Space) para selecionar objetos na cena.
* **Inspetor de Propriedades:** Fazer o ImGui exibir dinamicamente os dados (Posição, Escala, Cor) do objeto que estiver atualmente selecionado na `EditorScene`.