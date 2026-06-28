# Patch Notes v1.6.2

## Novas Funcionalidades

* **Matemática de Mouse Picking:** Implementação do motor matemático para seleção de objetos no mundo. O sistema captura as coordenadas do ecrã (SDL/ImGui), normaliza-as para o espaço de dispositivo (NDC) lidando dinamicamente com o redimensionamento da janela, e aplica transformações matriciais.////////
* **Matrizes Inversas: ** Expansão da biblioteca de álgebra linear `(mat3)` com métodos algébricos espaciais de custo O(1) para calcular a Inversa da Projeção e a Inversa da Visualização (View), permitindo a viagem matemática de volta do ecrã para o World Space.

## Refatoração
* **Separação de Contextos:** Desacoplamento arquitetural do estado da Engine. O antigo contexto monolítico foi dividido em dois
	* `UpdateContext`: Estrutura Read-Only `(const &)` injetada na lógica de atualização, contendo dados do ecrã e estado do mundo. 
	* `PipelineContext`: Máquina de estados mutável injetada no rasterizador, exclusiva para dados de desenho (Draw Calls).

## TO-DO
* **Inspetor de Propriedades:** Fazer o ImGui exibir dinamicamente os dados (Posição, Escala, Cor) do objeto que estiver atualmente selecionado na `EditorScene`.