# Trabalho-ED1
A livraria Brooks possui filiais em várias cidades do Espírito Santo. Atualmente, cada filial
possui seu próprio sistema de gerenciamento de estoque de livros de modo que não há uma
padronização dos sistemas e não há uma comunicação entre os sistemas. O presidente da
empresa decidiu centralizar o controle dos estoques na matriz da empresa. Para alcançar tal
objetivo, ele lhe pediu que implementasse um sistema com as seguintes características:
1. Os dados de estoque de uma filial não se misturam aos dados de outras filiais. Desta
forma, é possível escolher uma filial e (para a filial escolhida) realizar busca por um livro,
listar todos os livros em estoque, incluir novo título, atualizar a quantidade de exemplares
em estoque de um determinado livro, excluir um título do estoque.
2. No estoque de uma filial pode ter títulos que outras filiais não possuem.
3. Quando as atividades de uma filial são encerradas, todos os livros em seu estoque devem
ser tranferidos para outra filial. Esta será informada pelo usuário (o usuário informará o
id da filial que será fechada e o id da filial que receberá o estoque).
4. O sistema deve permitir a listagem de todos os dados de todas as filiais cadastradas (id,
endereço, gerente). Além disso, ao usuário deve ser permitido listar os dados de uma filial
específica (o id será informado para a busca).
2 Objetivo de trabalho
Implemente o sistema descrito na Seção 1 considerando que:
1. Os dados de uma filial são:
• id: número inteiro
• endereço: string
• gerente: string
2. Os dados de um livro são:
• isbn: string (chave de busca)
• título: string
• autor: string
• quantidade em estoque: inteiro
3. Cada livro será identificado pelo seu isbn.
4. Um livro pode ter 0 (zero) ou mais exemplares em estoque.
5. Os dados de estoque de uma filial (dados dos livros no estoque da filial) devem
ser armazenados em uma árvore binária de busca.
6. Quando uma filial x encerra suas atividades, o sistema deve realizar a união do estoque de x com o estoque da filial que irá receber os livros de x.
7. O sistema deve apresentar um menu principal com as seguintes opções:
(1) Listar os dados de todas as filiais (para cada filial os seguintes serão impressos: id, endereço, gerente.)
(2) Listar os dados de uma filial (caso o usuário escolha esta opção, o sistema deve solicitar o id da filial para realizar a busca)
(3) Criar nova filial (o usuário deverá informar os seguintes dados: id, endereço e nome do gerente. Quando uma filial é criada, seu estoque começa vazio. Para inserir dados do estoque de uma filial recém criada, o usuário deverá fazer a inclusão de cada livro pela opção “Realizar operações no estoque de uma filial”.)
(4) Encerrar atividades de uma filial (caso o usuário escolha esta opção, o sistema deve solicitar o id da filial a ser fechada e o id da filial que receberá o estoque da primeira. Ao final do processo, o sistema deve imprimir os dados da filial que recebeu o estoque e a árvore binária de busca (no formato de árvore) com os isbn’s dos livros em seu estoque.)
(5) Realizar operações no estoque de uma filial (caso o usuário escolha esta opção, o sistema deve solicitar o id da filial e abrir o menu de operações possíveis para uma filial.)
(6) Sair (o sistema será encerrado apenas se o usuário escolher esta opção.)
8. Uma vez que o usuário escolhe a opção (4) do menu principal e, em seguida, informa o id de uma filial, o sistema deve permitir que ele faça as seguintes operações no estoque
da filial escolhida:
(a) Imprimir a lista de livros em ordem crescente de isbn: A impressão da lista
deve ser em ordem crescente de isbn. Para cada livro deve ser impresso todas as
informações referentes a ele, uma por linha, sendo que a primeira informação deve
ser o isbn.
(b) Inserir um novo livro: Ao escolher esta opção o sistema deve requerir as informações referentes ao livro (isbn, título, autor e quantidade de exemplares). Caso o isbn já exista no sistema, o programa deve imprimir na tela a mensagem informando a existência do isbn e as informações do livro ao qual o isbn se refere.
(c) Buscar um livro no sistema: Quando o usuário escolher esta opção o sistema deve imprimir na tela, para o livro encontrado, o isbn, o título, o autor e a quantidade de exemplares, uma informação por linha. Quando o livro não existir no sistema, o programa deve imprimir uma mensagem informando a inexistência do livro com o isbn passado.
(d) Imprimir a estrutura da árvore binária de busca, utilizando apenas o isbn dos livros: A impressão da estrutura deve ser feita de modo que seja possível a identificação visual dos níveis da árvore (utilize número de tabulações distintas para distinguir um nível de outro).
(e) Excluir um livro: Quando esta opção é escolhida, o programa deve excluir todos os dados do elemento do sistema (ou seja, excluir o nó da árvore).
(f) Retornar ao menu principal: O programa retorna para o menu principal apenas quando o usuário escolher esta opção.
