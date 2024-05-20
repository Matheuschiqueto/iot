# Promoção da Saúde Mental e Bem-Estar através da IoT

## Descrição do Projeto

Este projeto tem como objetivo monitorar a frequência cardíaca dos usuários em tempo real, detectar possíveis crises de ansiedade e fornecer intervenções imediatas utilizando a tecnologia IoT.

## Funcionamento e Uso

O sistema utiliza um NodeMCU (ESP8266) conectado a um sensor de frequência cardíaca MAX30102 para monitorar os batimentos cardíacos. Quando os batimentos ultrapassam 100 BPM, um buzzer é acionado e uma notificação é enviada via protocolo MQTT para um broker na nuvem. O usuário recebe a notificação em seu smartphone.

### Passos para Reproduzir

1. Clone este repositório: `git clone https://github.com/seu-usuario/nome-do-repositorio.git`
2. Carregue o código `src/main.ino` no NodeMCU utilizando a IDE do Arduino.
3. Monte o circuito conforme o esquema em `hardware/esquema_fritzing.fzz`.
4. Configure seu broker MQTT e insira as credenciais no código.
5. Conecte o NodeMCU à rede Wi-Fi e execute o sistema.

## Vídeo-Demonstração

[Assista ao vídeo-demonstração no YouTube](link_do_video)

---

## 2. Software Desenvolvido e Documentação de Código

O código-fonte do projeto está localizado na pasta `src/`. 

### Arquivos:

- `main.ino`: Código principal do projeto, incluindo a configuração do sensor, buzzer e comunicação MQTT.

## 3. Descrição do Hardware Utilizado

### Componentes:

- **NodeMCU (ESP8266)**: Microcontrolador com conectividade Wi-Fi.
- **Sensor de Frequência Cardíaca MAX30102**: Sensor para monitoramento de batimentos cardíacos e oxigenação do sangue.
- **Buzzer Piezoelétrico**: Atuador para alertas sonoros.

### Esquema de Montagem

O esquema eletrônico está disponível no arquivo `hardware/esquema_fritzing.fzz`.

![Esquema de Montagem](imagens/diagramas.png)

### Lista de Componentes

A lista detalhada de componentes pode ser encontrada em `hardware/lista_componentes.md`.

## 4. Documentação das Interfaces, Protocolos e Módulos de Comunicação

### Interfaces

As interfaces de comunicação entre os componentes são detalhadas em `doc/interfaces.md`.

### Protocolos

A documentação dos protocolos utilizados, incluindo o protocolo MQTT, está em `doc/protocolos.md`.

### Módulos de Comunicação

Os detalhes sobre os módulos de comunicação (NodeMCU e broker MQTT) estão em `doc/modulos_comunicacao.md`.

---

## 5. Comunicação e Controle via Internet

O projeto utiliza o protocolo MQTT para comunicação e controle via internet, permitindo o envio de notificações em tempo real quando os batimentos cardíacos ultrapassam um limite pré-definido.

---

### Estrutura Detalhada dos Arquivos do Repositório

#### README.md

```markdown
# Promoção da Saúde Mental e Bem-Estar através da IoT

## Descrição do Projeto

Este projeto tem como objetivo monitorar a frequência cardíaca dos usuários em tempo real, detectar possíveis crises de ansiedade e fornecer intervenções imediatas utilizando a tecnologia IoT.

## Funcionamento e Uso

O sistema utiliza um NodeMCU (ESP8266) conectado a um sensor de frequência cardíaca MAX30102 para monitorar os batimentos cardíacos. Quando os batimentos ultrapassam 100 BPM, um buzzer é acionado e uma notificação é enviada via protocolo MQTT para um broker.


## Vídeo-Demonstração

[Assista ao vídeo-demonstração no YouTube](link_do_video)
