# Introdução ao problema
- Este programa foi desenvolvido diante da necessidade da equipe de densolvimento de software para organizar e gerenciar suas tarefas, oferecendo funcionalidades como cadastro, atualização de status, listagem e cálculo de tempo estimado para tarefas pendentes. O objetivo é oferecer uma solução simples e prática que facilite o acompanhamento de progresso e a priorização de atividades.

# Descrição das estruturas

## Typedef: 
- Eu usei para criar um alias para o tipo struct. No caso, o tipo tarefa passa a ser o nome direto do tipo, sem a necessidade de dentro da minha função main eu usar struct para definir o tipo da minha variável.

## Struct:
- Foi a strutura escolhida para representar uma tarefa, pois ela consegue ter tipos de dados diferentes em um única representação.
- Nela são armazenados dados como:
    - Identificador único da tarefa.
    - Nome da tarefa.
    - Prioridade da tarefa com os possíveis valores: "baixo", "medio" ou "alto".
    - Status da tarefa com os possíveis valores: "pendente" ou "concluída".
    - Tempo estimado para a conclusão da tarefa em horas.

## Lista de tarefas
- Conforme pedido, foi usado um vetor fixo com o tamanho para armazenar até 50 tarefas.
- O armazenamento das tarefas funciona da seguinte maneira: 
    - Para cada posição do vetor ou cada número do vetor começando em 0, uma tarefa é armazenada com toda a sua estrutura, e ela á armazenada na ordem em que foi criada a struct.

## Variáveis
- A variável "opcao" tem o controle de armazenar as opções que o usuário escolhe no menu.
- A variável "quant_tarefas" é responsável por controlar a quantidade de tarefas que estão sendo armazenadas, incrementando sempre que uma nova tarefa é atualizada.
- A variável "id_consulta" é responsável por armazenar o id da tarefa quando é exigido ao usuário para informar um id da tarefa existente.


# Funções utilizadas

## void CadastrarTarefa(tarefa [10], int);
- Essa função permite ao usuário adicionar uma nova tarefa fornecendo os detalhes necessários.
- Essa função não retorna nenhum valor, mas armazena diretamente as informações passadas pelo usuário, através da lista de tarefas e a quantidade de tarefas que são passados como argumento para essa função.
- O valor da quantidade de tarefas é atualizado assim que os dados são armazenados no vetor.

## void AtualizarStatus(tarefa [10], int, char [10], int);
- Essa função atualiza o status de uma tarefa de acordo com a opção fornecida.
- A opção fornecida é passada como argumento junto com a lista de tarefas, o id da tarefa e a quantidade de tarefas.

## bool VerificaId(tarefa [10], int, char [10]);
- Essa função exige o uso da biblioteca stdbool, e verifica se o id fornecido pelo usuário é válido ou não.
- O id fornecido pelo usuário é passado como argumento junto com a lista de tarefas e a quantidade de tarefas.

## void LimpaConsulta(char [10]);
- Essa função é usada para limpar a string que armazena o id fornecido pelo usuário para consulta. 
- A função é utilizada mais como uma boa prática.

## bool VerificaSeStatusJaExiste(tarefa [10], int, char [10], int);
- Essa função é usada para impedir que o usuário atualize o status para um status já existente e retorna se o status informado para atualização já existe ou não.
- É passado como argumento para a função a lista de tarefas, a quantidade de tarefas, o id fornecido e a opção de status fornecido no menu.

## void ListarTarefas(tarefa [10], int);
- Essa função é usada para mostrar todas as terafas cadastradas existentes.
- É passado como argumento para a função a lista de tarefas e a quantidade de tarefas.

## void ListarTarefasPorStatus(int, int, tarefa [10]);
- Essa função mostra todas as tarefas cadastradas de acordo com o status escolhido pelo usuário.
- É passado como argumento para a função a opção escolhida pelo usuário de acordo com o menu, a quantidade de tarefas e a lista de tarefas.

## double TempoTotalTarefasPendentes(tarefa [10], int);
- Essa função calcula  e retorna o tempo total para as tarefas pendentes.
- É passado como argumento para a função a lista de tarefas, e a quantidade de tarefas.

## void MostrarTempoTotaleTarefasPendentes(double, tarefa [10], int);
- Essa função mostra o tempo total estimado para a conclusão das tarefas pendentes.
- Dentro da função é feito um calculo para extrair o tempo em horas e minutos, pois o tempo para as atividades foi armazenado em horas.
- Se o valor total das atividades resultar menor do que 1, significa que o tempo total não passou de 1 hora então o valor é convertido para minutos.
- Se o valor total das atividades for maior do que 1, significa que o tempo total passou de 1 hora e para cada valor decimal do tempo total em horas será convertido em minutos e armazenado em outra variável. Deixando assim as informações sobre o tempo total mais claro para o usuário.


# Instuções para compilar e executar o programa
## Pré-requisitos
- Verifique se o compilador MinGW está instalado e devidamente configurado no PATH do sistema.
- Para verificar, abra o Prompt de digite:
    - gcc --version
    - Se o comando retornar a versão do GCC, a configuração está correta. Caso contrário, será 
    necessário instalar e configurar o MinGW.

## Preparação do arquivo:
    - Certifique-se de que o arquivo do tipo .c está salvo em um diretório acessível, como C:\Projetos.

## Compilação e execução do programa: 
    - Abra o prompt de comando e navegue até o diretório onde está o arquivo .c com o seguinte comando: 
        - cd C:\\Nome_pasta
    - Para compilar o programa(gerar um arquivo executável) siga o seguinte comando: 
        - gcc -o nome_do_arquivo nome_do_arquivo.c
    - Para executar o programa siga o seguinte comando: 
        - (Linux/Mac) `./nome_do_arquivo`
        - (Windows) `nome_do_arquivo.exe`
    - Observação: Para compilar o arquivo, primeiro será informado o nome do arquivo sem o tipo .c, pois esse será o arquivo executável e em seguida será informado o arquivo do tipo .c.
