#include<stdio.h>
#include<string.h>
#include<stdbool.h>

typedef struct
{
    char id_tarefa[11];
    char NomeTarefa[30];
    char Prioridade[7];
    char Status[10];
    double TempoEstimadoConclusao;
} tarefa;

void CadastrarTarefa(tarefa [10], int);
void AtualizarStatus(tarefa [10], int, char [10], int);
bool VerificaId(tarefa [10], int, char [10]);
void LimpaConsulta(char [10]);
bool VerificaSeStatusJaExiste(tarefa [10], int, char [10], int);
void ListarTarefas(tarefa [10], int);
void ListarTarefasPorStatus(int, int, tarefa [10]);
double TempoTotalTarefasPendentes(tarefa [10], int);
void MostrarTempoTotaleTarefasPendentes(double, tarefa [10], int);

int main()
{
    tarefa ListaTarefas[10];
    int opcao, quant_tarefas = 0;
    char id_consulta[10];

    do
    {
        printf("\n\n\n   <<--- Menu das Tarefas --->>");
        printf("\nCadastrar uma nova tarefa [1]");
        printf("\nAtualizar o status da tarefa [2]");
        printf("\nListar todas as tarefas cadastradas [3]");
        printf("\nListar tarefas de acordo com o status [4]");
        printf("\nTempo total estimado para tarefas pendentes [5]");
        printf("\nEncerrar [0]");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1: 
            //-- Chama a função para o cadastro da tarefa e atualiza a quantidade de tarefas existentes
                printf("\n\n<<-- Cadastrar tarefa -->>");
                CadastrarTarefa(ListaTarefas, quant_tarefas);
                quant_tarefas++;
                printf("\nTarefa cadastrada com sucesso!!");
            break;

            case 2:
            //-- Atualiza o status de acordo com o id informado
                LimpaConsulta(id_consulta);
                printf("\n\n<<-- Atualizar status -->>");
                printf("\nInforme o id da tarefa: ");
                scanf(" %10[^\n]", id_consulta);

                if(!VerificaId(ListaTarefas, quant_tarefas, id_consulta))
                {
                    printf("\nERROR =>[Id nao encontrado!!]");
                    printf("\nDeseja tentar novamente [1]");
                    printf("\nDeseja voltar ao menu [2]");
                    printf("\nInforme a opcao: ");
                    scanf("%d", &opcao);

                    if(opcao == 1)
                    {
                        do
                        {
                            LimpaConsulta(id_consulta);
                            printf("\nInforme um Id existente: ");
                            scanf(" %10[^\n]", id_consulta);
                        }while(!VerificaId(ListaTarefas, quant_tarefas, id_consulta));
                    }
                    else
                    {
                        printf("\nVoltando ao menu...");
                        break;
                    }
                }

                printf("\n\n<<-- Opcoes para atualizar -->>");
                printf("\nPendente[1]");
                printf("\nConcluida[2]");
                printf("\nInforme uma opcao: ");
                scanf("%d", &opcao);
                bool sair = false;
                
                    if(VerificaSeStatusJaExiste(ListaTarefas, quant_tarefas, id_consulta, opcao))
                    {
                        do
                        {
                            printf("\nERROR=>[O status informado ja existe]"); 
                            printf("\nVoltar ao menu[1]");
                            printf("\nTentar novamente[2]");
                            printf("\nEscolha uma opcao: ");
                            scanf("%d", &opcao);

                                if(opcao == 1)
                                {
                                    printf("\nVoltando ou menu..");
                                    sair = true;
                                    break;
                                }
                                else
                                {
                                    printf("\n\n<<--Opcoes para atualizar-->>");
                                    printf("\nPendente[1]");
                                    printf("\nConcluida[2]");
                                    printf("\nInforme uma opcao: ");
                                    scanf("%d", &opcao);
                                }
                        } while(VerificaSeStatusJaExiste(ListaTarefas, quant_tarefas,id_consulta, opcao));    
                    }

                    if(sair) break;
                    
                    AtualizarStatus(ListaTarefas, opcao, id_consulta, quant_tarefas);
                    printf("\nStatus atualizado com sucesso!!");
            
            break;

            case 3:
            //-- Mostrar todas as tarefas cadastradas chamando a função
            printf("\n\n<<-- Tarefas -->>");
            ListarTarefas(ListaTarefas, quant_tarefas);
            break;

            case 4:
            //-- Mostrar tarefas por status
            printf("\n\n<<-- Mostrar tarefas -->>");
            printf("\nMostrar tarefas pendentes [1]");
            printf("\nMostrar tarefas concluidas [2]");
            printf("\nEscolha uma opcao: ");
            scanf("%d", &opcao);

            ListarTarefasPorStatus(opcao, quant_tarefas, ListaTarefas);
            break;

            case 5:
            //-- Mostrar tempo total para tarefas pendentes
            
            MostrarTempoTotaleTarefasPendentes(TempoTotalTarefasPendentes(ListaTarefas, quant_tarefas), ListaTarefas, quant_tarefas);
            
            
            /* printf("\n\n<<-- Tempo total para tarefas pendentes -->>");
            if(TempoTotalTarefasPendentes(ListaTarefas, quant_tarefas) < 1)
            {
                printf("\nO tempo total e de %.0f minutos", TempoTotalTarefasPendentes(ListaTarefas, quant_tarefas) * 60);
            }
            else
            {
                printf("\nO tempo total e de %.0f horas", TempoTotalTarefasPendentes(ListaTarefas, quant_tarefas));
            } */

            break;

            case 0: printf("Encerrando..."); break;

            default: printf("ERROR=>[Escolha uma opcao valida!!]"); break;
        }

    }while(opcao != 0);

}

//-- Procedimento para o cadastro da tarefa
void CadastrarTarefa(tarefa lista[10], int quantidade)
{

    printf("\nInforme o id para esta tarefa: ");
    scanf(" %10[^\n]", lista[quantidade].id_tarefa);

    printf("Informe o nome da tarefa: ");
    scanf(" %29[^\n]", lista[quantidade].NomeTarefa);

    printf("Informe a prioridade da tarefa (baixo, medio, alto): ");
    scanf(" %6[^\n]", lista[quantidade].Prioridade);

    printf("Informe o status da tarefa (pendente, concluida): ");
    scanf(" %9[^\n]", lista[quantidade].Status);

    printf("Informe o tempo em horas para a conclusao da tarefa: ");
    scanf("%lf", &lista[quantidade].TempoEstimadoConclusao);

}

//-- Procedimento para atualizar o status da tarefa
void AtualizarStatus(tarefa lista[10], int valor, char id[10], int quant)
{
    char status[10];

    valor == 1 ? strcpy(status, "pendente") : strcpy(status, "concluida");

    for(int i = 0; i < quant; i++)
    {
        if(strcmp(lista[i].id_tarefa, id) == 0)
        {
            strcpy(lista[i].Status, status);
            break;
        }
    }

}

//-- Procedimento para mostrar todas as tarefas cadastradas
void ListarTarefas(tarefa lista[10], int quant)
{
    if(quant == 0)
    {
        printf("\nNenhuma tarefa cadastrada!!");
    }
    else
    {
        for(int i = 0; i < quant; i++)
        {
            printf("\n\nId tarefa: %s", lista[i].id_tarefa);
            printf("\nNome da tarefa: %s", lista[i].NomeTarefa);
            printf("\nPrioridade: %s", lista[i].Prioridade);
            printf("\nStatus: %s", lista[i].Status);
            printf("\nTempo para a tarefa: %.2f", lista[i].TempoEstimadoConclusao);
        }
    }
}

//-- Procedimento para listar as tarefas de acordo com o status escolhido pelo usuário
void ListarTarefasPorStatus(int valor, int quant, tarefa lista[10])
{
    char status[10];
    int quantstatus = 0;

    valor == 1 ? sprintf(status, "%s", "pendente") : sprintf(status, "%s", "concluida");

    if(quant == 0)
    {
        printf("\nERROR=>[Nenhuma tarefa cadastrada!!]");
    }
    else
    {
        printf("\n\n<<-- Tarefas com o status %s -->>", status);
        for(int i = 0; i < quant; i++)
        {
            if(strcmp(lista[i].Status, status) == 0)
            {
                printf("\n\nId tarefa: %s", lista[i].id_tarefa);
                printf("\nNome da tarefa: %s", lista[i].NomeTarefa);
                printf("\nPrioridade: %s", lista[i].Prioridade);
                printf("\nStatus: %s", lista[i].Status);
                printf("\nTempo estimado para conclusao: %.2f", lista[i].TempoEstimadoConclusao);
                quantstatus++;
            }
        }

        if(quantstatus == 0)
        {
            printf("\n  >> No momento nenhuma tarefa %s", status);
        }
    }
}

double TempoTotalTarefasPendentes(tarefa lista[10], int quant)
{
    double total = 0.0;

    for(int i = 0; i < quant; i++)
    {
        if(strcmp(lista[i].Status, "pendente") == 0)
        {
            total += lista[i].TempoEstimadoConclusao;
        }
    }

    return total;
}

//-- Função para verificar se o id consultado é válido
bool VerificaId(tarefa lista[10], int quantidade, char id[10])
{

    bool id_igual = false;

    for(int i = 0; i < quantidade; i ++)
    {
        if(strcmp(lista[i].id_tarefa, id) == 0)
        {
            id_igual = true;
            break;
        }
    }
    return id_igual;
}

//-- Procedimento para limpar string que recebe o id consultado
void LimpaConsulta(char str[10])
{
    str[0] = '\0';
}

//-- Função para prevenir o usuário de inserir um status já existente
bool VerificaSeStatusJaExiste(tarefa lista[10], int quantidade, char id[10], int valor)
{
    char status[10];

    valor == 1 ? strcpy(status, "pendente") : strcpy(status, "concluida");

    bool status_existe = false;

    for(int i = 0; i < quantidade; i++)
    {
        if(strcmp(lista[i].id_tarefa, id) == 0)
        {
            if(strcmp(lista[i].Status, status) == 0)
            {
                status_existe = true;
                break;
            }
        }
    }
    return status_existe;
}

//-- Procedimento para mostrar o tempo total e tarefas pendentes
void MostrarTempoTotaleTarefasPendentes(double tempo_total, tarefa lista[10], int quant)
{

    printf("\n\n<<-- Tempo total para as tarefas pendentes -->>");
        if(tempo_total < 1)
        {
            printf("\n   >> %.0f minutos", tempo_total * 60);//se o valor na somatoria for menor do que 1, o tempo é convertido para minutos.
        }
        else
        {// tempo convertido para horas e minutos.
            int horas = (int)tempo_total;// horas recebe o valor inteiro de tempo_total.
            int minutos = (tempo_total - (int)tempo_total) * 60;// minutos recebe o tempo total menos a parte inteira de tempo total, multiplicando a parte decimal para calcular os minutos.

            printf("\n   >> %d horas e %d minutos", horas, minutos);
        }

    
    printf("\n\n##TAREFAS");
    for(int i = 0; i < quant; i++)
    {
        if(strcmp(lista[i].Status, "pendente") == 0)
        {
            printf("\n   >>Nome: %s", lista[i].NomeTarefa);
            printf("\n   >>Tempo: %.2f horas\n", lista[i].TempoEstimadoConclusao);
        }
    }

}


