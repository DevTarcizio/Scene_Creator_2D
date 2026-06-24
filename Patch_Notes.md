# Patch Notes v1.2.2
### Novas Funcionalidades
- Suporte a Múltiplos Objetos
	- A engine agora permite a renderização de N entidades simultâneas na mesma cena, com cada objeto operando de forma independente.

### Refatoração
- Desacoplamento de Estado Global
	- Transform, VertexShader e FragmentShader foram removidos do pipelineContext global para evitar vazamento de estado (State Bleeding).
- Encapsulamento de Instância
	- A responsabilidade de armazenar transformações espaciais (transform) e materiais (shaders) foi delegada diretamente à classe Object.
- Máquina de Estados no Rasterizador
	- O Rasterizador agora acopla o Fragment Shader dinamicamente durante o Draw Call, seguindo o padrão de máquina de estados da indústria.


## TO-DO
- Implementar conceito de Cena