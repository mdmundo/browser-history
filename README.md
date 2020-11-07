# Browser History

## :thinking: O que é?

Este app simula o comportamento de um gerenciador de páginas de um navegador nos seguintes requisitos:

- Armazena o histórico _(As 5 últimas páginas acessadas)_.
- Funções de avançar e voltar páginas.
- Acessar novos links e armazená-los no histórico.

## Como usar?

_Você precisa ter o `Git` instalado para executar o seguinte comando._

### Passo 1

Baixe o repositório usando o comando: `git clone https://github.com/mdmundo/browser-history.git`

### Passo 2

Navegue até o repositório e no terminal execute o comando: `gcc index.c` para gerar o arquivo `a.out`.

### Passo 3

Abra o programa (executando o comando: `./a.out`). Digite uma opção para começar a usar.

```
1 - Abrir Link
2 - Voltar
3 - Avancar
4 - Mostrar History
0 - Sair
```

## Pra que isso?

Esse programa serve para mostrar a utilidade de estruturas de dados como:

- **listas duplamente encadeadas** _(usadas para a funcionalidade de avançar/voltar páginas)_;
- **listas simplesmente encadeadas** _(usadas para guardar o histórico)_.
