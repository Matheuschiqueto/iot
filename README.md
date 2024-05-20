# Promoção da Saúde Mental e Bem-Estar através da IoT

## Descrição do Projeto

Este projeto tem como objetivo monitorar a frequência cardíaca dos usuários em tempo real, detectar possíveis crises de ansiedade e fornecer intervenções imediatas utilizando a tecnologia IoT.

## Funcionamento e Uso

O sistema utiliza um NodeMCU (ESP8266) conectado a um sensor de frequência cardíaca MAX30102 para monitorar os batimentos cardíacos. Quando os batimentos ultrapassam 100 BPM, um buzzer é acionado e uma notificação é enviada via protocolo MQTT para um broker na nuvem. O usuário recebe a notificação em seu smartphone.

## Vídeo-Demonstração

[Assista ao vídeo-demonstração no YouTube](link_do_video)

---

### Arquivos:

- `main.ino`: Código principal do projeto, incluindo a configuração do sensor, buzzer e comunicação MQTT.

## Descrição do Hardware Utilizado

### Componentes:

- **NodeMCU (ESP8266)**: Microcontrolador com conectividade Wi-Fi.
- **Sensor de Frequência Cardíaca MAX30102**: Sensor para monitoramento de batimentos cardíacos e oxigenação do sangue.
- **Buzzer Piezoelétrico**: Atuador para alertas sonoros.

### Esquema de Montagem

O esquema eletrônico está disponível no arquivo `hardware/esquema_fritzing.fzz`.

![Esquema de Montagem](imagens/diagramas.png)
