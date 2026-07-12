POJETO FINAL - Prof. Julio S. Domingues Jr

**Aplicativo de execução de músicas**

Funcionamento:
  • O programa carregará no seu início o banco de dados de musicas.txt;
  • Este arquivo conterá em sua primeira linha a quantidade de músicas no acervo;
  • Na sequência, em cada linha, serão descritas as informações sobre cada musica(separados por ponto e virgula “;”);
  • Cada título será transformado em um registro no programa (struct música)
  • Após carregar o acervo para o programa, o programa apresentará um menu de opções:

Busca
– Funcionalidade que permite a buscade uma determinada música e exibesuas informações, a busca será efetuada por meio dos critérios:
  – Código;
  – Titulo;
  – Artista;

Playslist
  – ALEATORIO [FILA]: cria uma fila de músicas de tamanho n(definida pelo usuário) de forma randômica (escolhida pelo programador);
  – PLAYLIST PESSOAL [PILHA]: cria uma pilha com as músicas selecionadas do usuário

Execução
– Incrementa o atributo execuções em uma struct música no Acervo (lista encadeada de structs musicas do programa);
– As músicas criadas na Playlist serão removidas da TAD(Pilha/Fila) após a execução da Playlist;

Impressão:
  – Funcionalidade que mostra as musicas do acervo ou de uma das playlists;

Relatórios:
  – Funcionalidade que gera um arquivo de saída de músicas de cada Playlist
  – Funcionalidade que gera um arquivo com o acervo completo, com o número de execuções;
