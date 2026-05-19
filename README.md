# Scene_Creator_2D
Um renderizador 2D, com algumas features (iluminação, texturas...), com capacidade de criar cenas 2D



## Como desenhar:
usando um objeto do tipo Renderer, chama o método draw, que recebe 3 vertices em coordenadas NDC como argumentos,
cujo o tipo vertexNDC, possui dois membros -> position X,Y e color dada em RGBA de 0.0f a 1.0f

### Método draw:
chama o objeto do tipo Rasterizer, e chama o método drawTriangle, passando os mesmos vertices, e o próprio objeto 
Renderer

### Método drawTriangle: 
usa o objeto VertexStage para converter os vertices em NDC para vertex em screen space, após isso calcula a bounding
box desses vertices, para então calcular a area, e logo após calcular os pesos de cada vertice, para a verificação 
se o pixel está dentro ou fora da triangle, onde caso esteja, fazemos a interpolação das cores e ligamos o pixel através 
do objeto Renderer que o rasterizer tem instanciado

## Pipeline Atual
input de vertices em NDC -> conversão de NDC para screen space no VertexStage -> Definição de posição e cor no rasterizer
-> Desenho dos vertices no Renderer