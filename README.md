# Estrutura de Dados I – Trabalho Prático

**Data de entrega: 19/11/2023**

> ⚠️ Atenção: O estoque de uma filial deve ser implementado utilizando uma **árvore binária de busca**. Caso seja utilizada outra estrutura, a nota será **zero**.

---

## 1. Livraria Brooks

A livraria Brooks possui filiais em várias cidades do Espírito Santo. Cada filial possui seu próprio sistema de gerenciamento de estoque, sem padronização ou comunicação entre os sistemas. O presidente da empresa deseja centralizar o controle de estoques na matriz.

Você deverá implementar um sistema com as seguintes características:

1. Os dados de estoque de uma filial não se misturam com os de outras.
2. Cada filial pode ter títulos diferentes.
3. Ao encerrar as atividades de uma filial, seu estoque será transferido para outra, informada pelo usuário.
4. É possível listar os dados de todas as filiais cadastradas ou de uma filial específica.

---

## 2. Objetivo do Trabalho

### Dados da Filial:
- `id`: número inteiro
- `endereço`: string
- `gerente`: string

### Dados do Livro:
- `isbn`: string (chave de busca)
- `título`: string
- `autor`: string
- `quantidade em estoque`: inteiro

### Regras:
- Cada livro é identificado por seu `isbn`.
- Pode haver 0 ou mais exemplares de um livro.
- O estoque de livros deve ser armazenado em **árvore binária de busca (ABB)**.
- Quando uma filial é encerrada, seu estoque deve ser **unido** ao de outra filial.

---

## 3. Menu Principal

1. Listar os dados de **todas as filiais**
2. Listar os dados de **uma filial específica**
3. **Criar nova filial**
4. **Encerrar atividades** de uma filial (transferência de estoque)
5. **Operações no estoque** de uma filial
6. **Sair**

---

## 4. Menu de Operações no Estoque de uma Filial

> Antes de acessar este menu, o usuário deve informar o `id` da filial desejada.

### Opções:

a) **Imprimir a lista de livros** em ordem crescente de `isbn`  
b) **Inserir um novo livro**  
   - Se o `isbn` já existir, mostrar os dados do livro existente.  
c) **Buscar um livro** pelo `isbn`  
d) **Imprimir a estrutura da ABB** com os `isbn`  
e) **Excluir um livro** do estoque  
f) **Retornar ao menu principal**

---

## 5. Entrega do Trabalho

- A avaliação será feita em sistema **Linux**.
- O programa deve **compilar e executar via linha de comando** com uso de `make`.
- Os arquivos devem ser compactados no formato:


