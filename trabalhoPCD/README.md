# Sistema de Cadastros com Árvore Trie (C)

Este projeto consiste na implementação, em C, de um sistema de cadastros. Os dados dos usuários são gerenciados através de uma estrutura de dados de Árvore de Prefixos (Trie), permitindo operações eficientes de busca, inserção e remoção. O sistema possui persistência de dados, lendo e salvando as informações em um arquivo de texto chamado banco.txt.

## 📌 Estrutura de Dados

Os cadastros devem ser armazenados e manipulados em uma árvore de prefixos (trie) de acordo com seus IDs. 

* O campo ID é uma string aleatória única com letras minúsculas, possuindo no máximo 30 caracteres.
* Cada nodo terminal contém um ponteiro para uma struct contendo o cadastro completo.
* O cadastro completo armazena o Nome Completo (string com maiúsculas, minúsculas e espaços, de até 1000 caracteres) e a Idade (inteiro de até 99 anos).

## ⚙️ Funcionalidades e Comandos

Todo comando deve ser processado a partir da trie. O programa deve ser uma sequência de comandos do usuário, onde cada comando pode ser:

* **`? [ID]` (Busca):** Busca na estrutura de dados o cadastro com dado ID. Imprime os dados caso encontrado ou uma mensagem de erro indicando que não foi encontrado.
* **`+ [ID] [Nome Completo] [Idade]` (Inserção):** Insere um novo cadastro na estrutura de dados.
* **`- [ID]` (Remoção):** Remove da estrutura de dados o cadastro com dado ID. Imprime mensagem confirmando a remoção ou erro se não existir.
* **`P` (Impressão):** Imprime todos os cadastros na estrutura de dados, um por linha.
* **`S` (Salvar):** Salva todos os cadastros que estão na estrutura de dados no arquivo `banco.txt`. O arquivo é reconstruído "do zero", apenas com os cadastros que estão na estrutura no momento em que o comando é lido.
* **`F` (Finalizar):** Termina a execução. O programa libera toda a memória utilizada ao final da execução.

## 📂 Formato do Arquivo de Dados (banco.txt)

O arquivo contém uma coleção de cadastros de usuários. A primeira linha do arquivo contém um inteiro indicando a quantidade de usuários cadastrados. Cada uma das próximas linhas contém um cadastro, no formato `[ID] [Nome Completo] [Idade]`.

**Exemplo de formatação inicial do banco.txt:**
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
