# Sistema de Cadastros com Árvore Trie (C)

Este projeto apresenta um sistema de gerenciamento de perfis desenvolvido em C. A aplicação utiliza uma Árvore de Prefixos (Trie) para armazenar os dados em memória, garantindo alta performance nas operações de manipulação. Além disso, o programa conta com um mecanismo de persistência que sincroniza o estado atual da árvore com um arquivo de texto local.

## 📌 Estrutura de Dados

A arquitetura do projeto baseia-se na alocação dinâmica de nós em uma Trie.
* **Chave de Busca (ID):** String exclusiva formada por letras minúsculas (limite de 30 caracteres) que define o caminho na árvore.
* **Nó Terminal:** Aponta para uma estrutura de dados que guarda as informações do usuário.
* **Dados do Usuário:** Compreendem o Nome Completo (string de até 1000 caracteres, aceitando espaços e variação de caixa) e a Idade (valor numérico até 99).

## ⚙️ Funcionalidades e Comandos

A interação com o sistema ocorre via terminal, utilizando uma série de comandos específicos:

* **`? [ID]` (Consultar):** Varre a Trie em busca do identificador. Retorna os dados do usuário ou avisa se o registro for inexistente.
* **`+ [ID] [Nome Completo] [Idade]` (Adicionar):** Aloca um novo usuário na estrutura em memória.
* **`- [ID]` (Excluir):** Apaga o registro correspondente ao identificador informado.
* **`P` (Listar):** Percorre toda a árvore e exibe todos os usuários ativos no momento.
* **`S` (Sincronizar):** Sobrescreve o arquivo de banco de dados, salvando exclusivamente os registros que estão na memória durante a execução do comando.
* **`F` (Sair):** Encerra o programa de forma segura, acionando a liberação total da memória alocada dinamicamente.

## 📂 Formato do Banco de Dados (`banco.txt`)

O armazenamento persistente é feito em um arquivo de texto simples. A primeira linha deve obrigatoriamente informar o número total de registros. As linhas subsequentes contêm os dados separados por espaço.

**Modelo de estruturação:**
```text
5
afd James Paul McCartney 81
dwiz Richard Starkey 83
afdg John Winston Ono Lennon 40
dafd Larissa de Macedo Machado 30
dwiop George Harrison 58
```

##  🚀 Como Executar
1. Clone o repositório.

2. Certifique-se de ter um compilador C (como o gcc) instalado.

3. Compile o código-fonte principal.

4. Crie um arquivo banco.txt no mesmo diretório do executável, seguindo a formatação exigida.

5. Execute o programa e insira os comandos no terminal.
