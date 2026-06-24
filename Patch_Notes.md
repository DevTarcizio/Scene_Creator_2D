# Patch Notes v1.3.0

## Novas Funcionalidades

* **Câmera Algébrica:** Sistema de câmera refatorado para suportar movimentação fluida e zoom. O cálculo de centralização de tela agora utiliza a Câmera como pivô absoluto, permitindo aproximações corretas de zoom independente da posição global.

## Refatoração

* **Padrão MVP (Model-View-Projection):** Implementação completa da "trindade" da computação gráfica. O pipeline agora converte vértices passando estritamente pelos espaços corretos (*Local Space* -> *World Space* -> *View Space* -> *NDC Space*).
* **Matriz de Visualização (View Matrix):** Adicionado cálculo que alinha o universo em relação à visão do observador usando translação inversa acoplada à escala uniforme.
* **Projeção Ortográfica (Projection Matrix):** Substituição das divisões manuais de tela (*hardcoded*) por uma matriz matemática dedicada que normaliza o *Viewport* da resolução física para as coordenadas de dispositivo normalizadas (NDC: -1 a 1).
* **Limpeza do Vertex Shader:** Remoção de toda a aritmética braçal de cálculo de tela e centralização de câmera do arquivo `vertexShader.cpp`. O shader agora apenas recebe o pacote matemático (`mvpMatrix`) e processa a transformação espacial em uma única instrução matricial.
* **Pré-cálculo da Matriz MVP (Otimização):** A multiplicação das matrizes de *Model*, *View* e *Projection* foi extraída do Vertex Shader e movida para o estágio de *Draw Call* (`Renderer::draw`). O custo de cálculo matricial da CPU deixou de ser linear por vértice O(N) e passou a ser constante por objeto O(1), garantindo alta performance para malhas complexas.

## TO-DO
- Implementar conceito de Cena