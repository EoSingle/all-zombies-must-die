# All Zombies Must Die
Um jogo shooter top-down com mortos vivos, rock e muita ação!

[![Vídeo sobre o projeto](https://img001.prntscr.com/file/img001/KtOwsqO_SZKj3TLzH05-hw.png)](https://www.youtube.com/watch?v=82ofh_CPzE8)


## Grupo 2 | Integrantes: 
- Lucas Albano : @EoSingle
- Mateus Moreira : @MateusMoreira2d

## Sobre o jogo
Em **ALL ZOMBIES MUST DIE** você é um sobrevivente de um apocalipse zumbi lutando pela sua vida. Para sua sorte, você possui diversas armas para lidar com os zumbis. Eles não param de vir até você e só lhe resta **matar todos**!

## Índice
* [Ferramentas](#ferramentas)
* [SFML](#sfml)
* [Instalação](#instalando-o-jogo)
* [Execução](#execução)
* [Tutorial](#como-jogar)
* [Testes](#testes)
* [Cobertura](#cobertura-do-código)
* [Documentação](#documentação)

## Ferramentas
Para o jogo utilizamos as seguintes ferramentas, bibliotecas e linguagem:
- Linguagem: C++11
- Biblioteca: SFML 2.5.1
- Compilação: Make
- Documentação: Doxygem
- Testes Unitários: Doctest
- Cobertura: gcovr

## SFML
Simple and Fast Multimedia Library (SFML) é uma biblioteca multiplataforma, orientada a objetos e open source. É uma API multimedia escrita em C++ por Laurent Gomila, que tem como objetivo fornecer uma interface simples para vários componentes multimédia do computador.
### Mais sobre a biblioteca: 
- https://pt.wikipedia.org/wiki/SFML
- https://www.sfml-dev.org

## Instalando o jogo:
**Primeiro você deve clonar este repositório:**
```
git clone https://github.com/pds2-dcc-ufmg/2022-2-TW-grupo02.git
```

**Selecione seu sistema operacional:**
- Caso esteja usando linux:
```
cd Game-Linux
```

- Caso esteja usando windows:
```
cd Game-Windows
```

### Compilação:

Obs 1: Para compilar é necessário o utilitário make ou MinGW (windows)

Obs 2: Criar antes um diretório *./build/*
- Linux:
```
make
```
- Windows:
```
mingw32-make
```
ou
```
mingw64-make
```

## Execução:
```
make run
```
ou você pode executar o arquivo main diretamente.

## Como jogar:
### Start
Pressione **Enter** para começar o jogo.

### Pause
Dentro do jogo pressione **TAB** para pausar.

Você pode pressionar **ESC** para retornar ao menu.

Enquanto pausado use as setas do teclado para aumentar ou diminuir o volume da música.

### Sair
Feche diretamente a janela ou no menu pressione **ESC** para sair do jogo.

### Movimentação
Pressione **W** para se mover para cima.

Pressione **S** para se mover para baixo.

Pressione **A** para se mover para a esquerda.

Pressione **D** para se mover para a direita.

### Combate
Use o cursor para mirar.

Pressione o **botão esquerdo do mouse** para atirar.

Pressione **R** para recarregar a munição.

### Armas
Pressione **1** para selecionar a *Glock*.

Pressione **2** para selecionar a *Desert Eagle*.

Pressione **3** para selecionar a *Double Barrel*.

Pressione **4** para selecionar a *P90*.

Pressione **5** para selecionar a *M4A1*.

Pressione **6** para selecionar a *AWP*.


## Testes:
**Para compilar os testes usar o comando:**
```
make tests
```

**Para executar os testes:**
```
make run_tests
``` 

## Cobertura do código:
Para imprimir o relatório simplificado no próprio Terminal, utilizar:
```
make coverage
```

Para gerar o relatório em HTML, utilizar:
```
make html_coverage
```
**Atenção: criar antes um diretório *./coverage/***

## Documentação
O projeto já acompanha os arquivos Doxyfile devidamente configurados.

É necessário possuir a ferramenta Doxygen instalada, ela pode ser baixada em: https://www.doxygen.nl/download.html

**Certifique-se de antes criar um diretório ./documentation/**

Para gerar a documentação utilize:
```
make documentation
```

Caso esteja usando windows, abra o aplicativo *doxywizard*, vá em *File>Open* e abra o arquivo *Doxyfile*. Vá em *Run* e clique em *Run doxygen*, depois clique em *Show HTML output*.

## Para remover arquivos auxiliares:
Limpa os object files (.o):
```
make clean
```
Funciona somente em Linux.
