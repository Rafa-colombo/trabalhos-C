# Sistema de Cadastros com Árvore Trie (C)

[cite_start]Este projeto consiste na implementação, em C, de um sistema de cadastros[cite: 3]. [cite_start]Os dados dos usuários são gerenciados através de uma estrutura de dados de Árvore de Prefixos (Trie), permitindo operações eficientes de busca, inserção e remoção[cite: 85]. [cite_start]O sistema possui persistência de dados, lendo e salvando as informações em um arquivo de texto chamado `banco.txt`[cite: 3, 28].

## 📌 Estrutura de Dados

[cite_start]Os cadastros devem ser armazenados e manipulados em uma árvore de prefixos (trie) de acordo com seus IDs[cite: 85]. 
* [cite_start]O campo ID é uma string aleatória única com letras minúsculas [cite: 6][cite_start], possuindo no máximo 30 caracteres[cite: 116].
* [cite_start]Cada nodo terminal contém um ponteiro para uma struct contendo o cadastro completo[cite: 86].
* [cite_start]O cadastro completo armazena o Nome Completo (string com maiúsculas, minúsculas e espaços [cite: 7][cite_start], de até 1000 caracteres [cite: 117][cite_start]) e a Idade (inteiro [cite: 7] [cite_start]de até 99 anos [cite: 117]).

## ⚙️ Funcionalidades e Comandos

[cite_start]Todo comando deve ser processado a partir da trie[cite: 113]. [cite_start]O programa deve ser uma sequência de comandos do usuário, onde cada comando pode ser[cite: 18]:

* **`? [cite_start][ID]` (Busca):** Busca na estrutura de dados o cadastro com dado ID[cite: 19]. [cite_start]Imprime os dados caso encontrado ou uma mensagem de erro indicando que não foi encontrado[cite: 20].
* [cite_start]**`+ [ID] [Nome Completo] [Idade]` (Inserção):** Insere um novo cadastro na estrutura de dados[cite: 21].
* [cite_start]**`- [ID]` (Remoção):** Remove da estrutura de dados o cadastro com dado ID[cite: 24]. [cite_start]Imprime mensagem confirmando a remoção ou erro se não existir[cite: 25, 26].
* [cite_start]**`P` (Impressão):** Imprime todos os cadastros na estrutura de dados, um por linha[cite: 27].
* [cite_start]**`S` (Salvar):** Salva todos os cadastros que estão na estrutura de dados no arquivo `banco.txt`[cite: 28]. [cite_start]O arquivo é reconstruído "do zero", apenas com os cadastros que estão na estrutura no momento em que o comando é lido[cite: 29].
* [cite_start]**`F` (Finalizar):** Termina a execução[cite: 31]. [cite_start]O programa libera toda a memória utilizada ao final da execução[cite: 118].

## 📂 Formato do Arquivo de Dados (`banco.txt`)

[cite_start]O arquivo contém uma coleção de cadastros de usuários[cite: 3]. [cite_start]A primeira linha do arquivo contém um inteiro indicando a quantidade de usuários cadastrados[cite: 4]. [cite_start]Cada uma das próximas linhas contém um cadastro, no formato `[ID] [Nome Completo] [Idade]`[cite: 5].

**Exemplo de formatação inicial do `banco.txt`:**
  ```text
  5
  afd James Paul McCartney 81
  dwiz Richard Starkey 83
  afdg John Winston Ono Lennon 40
  dafd Larissa de Macedo Machado 30
  dwiop George Harrison 58
  ```

##  🚀 Como Executar
Clone o repositório.

Certifique-se de ter um compilador C (como o gcc) instalado.

Compile o código-fonte principal.

Crie um arquivo banco.txt no mesmo diretório do executável, seguindo a formatação exigida.

Execute o programa e insira os comandos no terminal.
