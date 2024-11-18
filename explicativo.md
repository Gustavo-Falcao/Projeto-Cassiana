## O PROGRAMA DEVE CUMPRIR:
- Cadastrar uma nova tarefa
- Atualizar o status de uma tarefa
- Listar todas as tarefas cadastradas
- Listar tarefas com status "pendentes" ou "concluída"
- Exibir o tempo total estimado para tarefas pendentes

## CADA TAREFA DEVE POSSUIR: 
- Identificador único
- Nome da tarefa
- Prioridade(baixo, médio, alto)
- Status(pendentes ou concluído)
- Tempo estimado para conclusão(em horas)

## REGRAS DE IMPLEMENTAÇÃO:
- Utilize structs para representar as tarefas
- Separar as funcionalidades em funções distintas
- Use um array fixo de tamanho 50 para armazenar as tarefas
- Evite a utilização de bibliotecas avançadas ou técnicas não abordadas em sala de aula.

## INSTRUÇÕES DE ENTREGA:
- Arquivos a serem entreges:
	- Arquivo fonte do código: sistema tarefas.c
	- Documento explicativo (PDF ou DOC) contendo:
        - Introdução ao problema
		- Descrição das estruturas e funções utilizadas
		- Instruções para compilar e executar o programa
		- Teste realizados com o programa(prints ou descrição dos testes).
- Formato de entrega:
    - O trabalho deve ser compactado em um arquivo.zip contendo:
		- sistemas.c
		- Documento explicativo (PDF ou DOC)
		- Prints de tela mostrando o funcionamento de programa.
- Prazo de entrega:
	- Data 25/11/2024
- Formas de entrega:
	- O trabalho deve ser enviado via Modie

## CRITÉRIOS DE AVALIAÇÃO
- Funcionalidades do programa(60%)
	- Todas as operações do sistema devem funcionar corretamente
	- A separação de funcionalidades em funções será avaliada
- Documentação(20%)
	- Clareza na explicação do problema da solução
	- Qualidade do texto e formatação
- Organizações do código(20%)
	- Uso adequado de indentação e comentários no código
- A nota será convertida para 1.5 pontos.


## FUNÇÕES:
- CadastrarTarefa()
- AtualizaStatus()
- ListarTarefas()
- ListarPendentes()
- ListarConcluidas()
- VerificaId()

## MELHORIAS
- Encontrar um jeito de fornecer a posição da tarefa na matriz quando for verificar o Status

## ONDE PAREI
- Verifica Status, verificando se o status escolhido para atualizar já existe na string
- Opção 2 para atualizar o status com a condição else