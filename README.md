## Este Git tem como proposito testar a utilização da biblioteca SDL2 no Xcode.

Foram acompanhados do [Canal Sonar Systems no Youtube](https://www.youtube.com/watch?v=uvxV1xlApm4).

Para a instalação dos pacotes sdl2, sdl2_image, sdl2_mixer, sdl2_ttf, sdl2_net, sdl2_gfx, foi utilizado o [Homebrew](https://brew.sh) que gerencia a instalação de bibliotecas e aplicativos via terminal.

### Instalando o Homebrew

```
  $~ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

### Instalando os Pacotes do SDL2

```
  $~ brew install sdl2
  $~ brew install sdl2_mixer
  $~ brew install sdl2_image
  $~ brew install sdl2_ttf
  $~ brew install sdl2_net
  $~ brew install sdl2_gfx  
```

### 1. linkando a SDL2 com o Xcode 9.2


Abra o Xcode e selecione a opção de criar um novo projeto.

![1.1 criando novo projeto](https://i.imgur.com/2czseQm.gif "Criar Novo Projeto")

Selecione a plataforma como **macOS** e o template de **Command Line Tool**

![1.2 macOS -> Command Line Tool](https://i.imgur.com/2czseQm.gif "Selecionar Tipo do Projeto macOS -> Command Line Tool")

Informe o nome do projeto e selecione a linguagem como **C++**

![1.3 Linguagem C++](https://i.imgur.com/2czseQm.gif "Nome do Projeto -> Linguagem C++")

Com o projeto recem aberto clique na aba **Build Settings** procure o campo **Header Search Paths** e adicione a entrada **"/usr/local/include"**

![1.4 Header Search Paths](https://i.imgur.com/2czseQm.gif "adicione em Header Search Paths a entrada /usr/local/include")

Em seguida vá para aba **Build Phases** na seção **Link Binary With Libraries** e clique no **+** 

![1.5.1 Header Search Paths](https://i.imgur.com/2czseQm.gif "adicione em Header Search Paths a entrada /usr/local/include")

No pop over clique em **Add Other...** 

![1.5.2 Header Search Paths](https://i.imgur.com/2czseQm.gif "adicione em Header Search Paths a entrada /usr/local/include")

Na janela que abriu pressione as teclas **cmd** + **shift** + **g** para abrir a tela de navegar para e digite o caminho **"/usr/local/cellar"**

![1.5.3 Header Search Paths](https://i.imgur.com/2czseQm.gif "adicione em Header Search Paths a entrada /usr/local/include")

Na pasta em que paramos encontre a pasta do sdl2 navegue dentro dela até encontrar uma pasta chamada lib e nela inclua o arquivo **libSDL2-2.0.0.dylib**

![1.5.4 Header Search Paths](https://i.imgur.com/2czseQm.gif "adicione em Header Search Paths a entrada /usr/local/include")

Repita o processo para as demais bibliotecas da sdl2 com **cuidado para não adicionar os arquivos que são atalhos com a extensão .dylib**.


Feito isso o seu projeto do Xcode já é capaz de encontrar as bibliotecas da SDL2 basta adicionar as linhas

```
	#include <SDL2/SDL.h>
    #include <SDL2/SDL_pacote.h>
```
a sua main onde "SDL_pacote.h" é o pacote especifico (SDL_mixer, SDL_ttf, SDL_net, SDL_image, SDL_...);
