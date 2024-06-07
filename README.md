# Blu - Combatendo a Poluição Marinha

![Logo Blu](https://i.ibb.co/cFmz538/logo-blu.png)
![Circuito](https://i.ibb.co/HPVbtNw/GS-Edge.png)

## Integrantes

- [Gabriel Matiolli](https://github.com/m4tiolli) 
- [Leonardo Taschin](https://github.com/leoctaschin) 

## Descrição do Projeto
Blu é uma solução de monitoramento ambiental marinho desenvolvida para ajudar na identificação e combate à poluição marinha. Utilizando a plataforma Arduino, Blu monitora e exibe parâmetros críticos da água, como temperatura, pH, níveis de oxigênio dissolvido e salinidade. Este projeto é fundamental para garantir a saúde dos habitats marinhos, fornecendo dados em tempo real e alertando sobre condições adversas que podem prejudicar a vida marinha.

## Importância do Projeto
O monitoramento constante dos parâmetros da água é crucial para:

- Detectar e prevenir a poluição marinha.
- Manter a biodiversidade e a saúde dos ecossistemas marinhos.
- Auxiliar em pesquisas científicas e na tomada de decisões ambientais.
- Sensibilizar sobre a importância da conservação marinha.

## Componentes Utilizados
- Arduino Uno
- Sensor de Temperatura (TMP36)
- Sensor de pH (simulado com potenciômetro)
- Sensor de Oxigênio Dissolvido (simulado com potenciômetro)
- Sensor de Salinidade (simulado com potenciômetro)
- Display LCD I2C
- Buzzer
- Potenciômetros
- Fios de Conexão

## Instruções de Uso

### Montagem do Hardware:

- Conecte o sensor de temperatura TMP36 ao pino A0 do Arduino.
- Conecte os potenciômetros aos pinos A1, A2 e A3 para simular os sensores de pH, oxigênio dissolvido e salinidade, respectivamente.
- Conecte o display LCD I2C ao Arduino (SDA ao pino A4 e SCL ao pino A5).
- Conecte o buzzer ao pino digital 8 do Arduino.
- Certifique-se de que todos os componentes estão devidamente alimentados e conectados à terra.

## Instalação do Software:

- Certifique-se de ter a IDE Arduino instalada.
- Adicione a biblioteca LiquidCrystal_I2C na IDE Arduino.
- Adione o código disponibilizado acima.
- Carregue o código do projeto no Arduino.

## Operação:

- O sistema lerá continuamente os valores dos sensores e exibirá uma informação por vez no LCD.
- O buzzer emitirá um som de alerta se algum valor estiver fora do intervalo aceitável.
- O LCD exibirá os valores medidos e indicará se estão dentro dos limites aceitáveis (OK) ou fora dos limites (Alta/Baixa).
