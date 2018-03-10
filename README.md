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

### [macOS] Tutorial SDL2 no Xcode 9.2


#### 1. Criando o projeto no Xcode.

**1.1 -** Abra o Xcode e selecione a opção de criar um novo projeto.

![1.1 criando novo projeto](https://github.com/girayaThiago/sdl_tests/blob/master/sdlsonar2/Screenshots/1.1%20Novo%20Projeto.png?raw=true "Criar Novo Projeto")

**1.2 -** Selecione a plataforma como **macOS** e o template de **Command Line Tool**

![1.2 macOS -> Command Line Tool](https://github.com/girayaThiago/sdl_tests/blob/master/sdlsonar2/Screenshots/1.2%20macOS%20command%20line.png?raw=true "Selecionar Tipo do Projeto macOS -> Command Line Tool")

**1.3 -** Informe o nome do projeto e selecione a linguagem como **C++**

![1.3 Linguagem C++](https://github.com/girayaThiago/sdl_tests/blob/master/sdlsonar2/Screenshots/1.3%20linguagem%20e%20nome.png?raw=true "Nome do Projeto -> Linguagem C++")

#### 2. Linkando bibliotecas SDL2.

**2.1 -** Com o projeto recem aberto clique na aba **Build Settings** procure o campo **Header Search Paths** e adicione a entrada **"/usr/local/include"**

![2.1 Header Search Paths](https://github.com/girayaThiago/sdl_tests/blob/master/sdlsonar2/Screenshots/1.4%20Search%20paths.png?raw=true "adicione em Header Search Paths a entrada /usr/local/include")

**2.2 -** Em seguida vá para aba **Build Phases** na seção **Link Binary With Libraries** e clique no **+** 

![2.2 Build Phases > Link Binary with Libraries > +](https://github.com/girayaThiago/sdl_tests/blob/master/sdlsonar2/Screenshots/1.5.1%20+.png?raw=true "adicione em Header Search Paths a entrada /usr/local/include")

**2.3 -** No pop over procure por SDL2 caso não encontre clique em **Add Other...** 

![2.3 Procure SDL2 caso não encontre clique em Add Other...](https://github.com/girayaThiago/sdl_tests/blob/master/sdlsonar2/Screenshots/1.5.2%20add%20other.png?raw=true "adicione em Header Search Paths a entrada /usr/local/include")

**2.3.1 -** [Add Other...] Na janela que abriu pressione as teclas **cmd** + **shift** + **g** para abrir a tela de navegar para e digite o caminho **"/usr/local/cellar"** e aperte enter.

![2.3.1 cmd + shift + g "/usr/local/cellar" procure a pasta SDL2](https://github.com/girayaThiago/sdl_tests/blob/master/sdlsonar2/Screenshots/1.5.3%20go%20to.png?raw=true "adicione em Header Search Paths a entrada /usr/local/include")

**2.3.2 -** Na pasta em que paramos encontre a pasta do sdl2 navegue dentro dela até encontrar uma pasta chamada lib e nela inclua o arquivo **libSDL2-2.0.0.dylib**

![2.3.2 navegue na pasta SDL2 até encontrar a pasta lib nela adicione o arquivo libSDL2-2.0.0.dylib](https://github.com/girayaThiago/sdl_tests/blob/master/sdlsonar2/Screenshots/1.5.4%20sdl%20dylib%20path.png?raw=true "adicione em Header Search Paths a entrada /usr/local/include")

Repita o processo para as demais bibliotecas da sdl2 com **cuidado para não adicionar os arquivos que são atalhos com a extensão .dylib**.


Feito isso o seu projeto do Xcode já é capaz de encontrar as bibliotecas da SDL2 basta adicionar as linhas

```
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_pacote.h>
```
a sua main onde "SDL_pacote.h" é o pacote especifico (SDL_mixer, SDL_ttf, SDL_net, SDL_image, SDL_...);

