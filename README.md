*EcoSave*
-
***

**Nosso objetivo:**

O objetivo deste projeto é criar um aplicativo que utiliza inteligência artificial para monitorar e otimizar o consumo de energia dos usuários. Por meio de um sistema interativo de pontos e recompensas, o aplicativo incentiva práticas sustentáveis, ajudando os consumidores a reduzirem seus gastos energéticos e contribuírem para a preservação do meio ambiente. Além de promover economia doméstica, o app oferece dicas personalizadas baseadas nos hábitos de consumo de cada usuário, possibilitando ajustes eficientes e conscientes. Com relatórios detalhados sobre padrões de uso, o aplicativo se torna uma ferramenta essencial para transformar o consumo de energia em uma experiência responsável e engajante.

***

**Integrantes:**
- Gabriell Hernandes Dassi RM98361 - 2TDSPH
- Luigi Exposito Uchiyama - 99520 – 2TDSPY
- Luis Augusto de Petta Didonato RM99433 - 2TDSPH
- Pedro Antunes Ferreira RM551409 - 2TDSPH
- Pedro Henrique Nobrega de Castro Paterno RM99726 - 2TDSPH
    
***

**Instruções para rodar a aplicação Java:**

Para rodas a aplicação entre na IDE eclipse e baixe através do marketplace o Spring Tools 4. 
Após a instalação abra o boot dashboard, e com o mouse em cima do projeto, aperte o botao direito e (Re)start. 
Após isso abra seu navegador e acesse localhost:8080/index e escolha um dos usuarios para logar

***

**Usuarios do Sistema**
- Usuario Normal
- login: user
- senha: user

- Usuario Administrador
- login: admin
- senha: admin

***

**Link para o video pitch:**

    https://www.youtube.com/watch?v=G8SNC-25LB4

***
## 1. Criação do Projeto

- Crie um projeto privado no Azure DevOps.
- Importe o repositório do GitHub para o repositório do Azure DevOps.
- No repositório importado, vá `application.properties` e adicione ao codigo a api key em

## 2. Criação da Pipeline

1. Acesse o editor de pipelines e selecione a opção **Classic Editor**.
   - Clique em **Continuar** e selecione o template **Maven**.
   
2. Configurações da Pipeline:
   - Escolha um nome para a pipeline.
   - Defina **Windows-latest** como especificação do agente (Agent Specification).
   - Indique o caminho para o arquivo `pom.xml` na pasta do projeto
   
3. Configurações de Build:
   - Selecione a versão `4.*` na **task version**.
   - Nas configurações avançadas da build, defina o JDK como **jdk17**.
   
4. Copiar a Aplicação:
   - Mantenha todas as configurações como padrão.
   
5. Publicar Artefato do Build:
   - Em **Control Options**, selecione **Run this task**.
   - Escolha a opção **Only when all previous tasks have succeeded**.
   
6. Trigger (Gatilho):
   - Marque a opção **Enable continuous integration**.
   
7. Finalize:
   - Clique em **Save & Queue** e depois em **Save and Run**.

## 3. Criação do App Service

Para o próximo passo, será necessário criar um App Service no Azure.

1. No portal do Azure, busque por **App Services** e selecione essa opção.
2. Clique em **New** e, em seguida, em **New Web App**.
3. Configurações do Web App:
   - Selecione o grupo de recursos desejado.
   - Insira o nome para a instância do App Service.
   - Defina a versão do Java como **Java 17**.
   - Escolha **Windows** como sistema operacional.
   - Defina a região como **Brazil South**.
   - Escolha o plano de serviço conforme sua necessidade.
   
4. Clique em **Review + Create** para finalizar a criação do App Service.

## 4. Criação de Releases

1. Após criar a pipeline, selecione a opção **Releases** e clique em **New pipeline**.
2. Escolha a opção **Empty Job**.
3. Adicione um artefato:
   - Escolha a build pipeline criada anteriormente e clique em **Adicionar**.
   - No símbolo do raio acima de **Add an artifact**, ative a opção **Continuous deployment trigger**.
4. Salve as alterações clicando em **Save**.
5. Clique em **1 job, 0 tasks** na seção **Stages**:
   - Na barra de pesquisa, digite **Azure Web App** e selecione essa opção.
   - Configure o **Azure Web App Deploy**:
     - Escolha sua assinatura do Azure.
     - No campo **App type**, selecione **Web App on Windows**.
     - Selecione o nome do seu App Service criado anteriormente.
     - Em **Package or folder**, selecione o arquivo `.jar` na pasta **target** do projeto.
   
6. Salve novamente e clique em **Create release**.

## 5. Teste da Aplicação

- Após criar a release, clique na URL disponibilizada pelo seu App Service para ver sua aplicação rodando na nuvem.

***

**Link para o video demonstrativo (DEVOPS):**

    https://www.youtube.com/watch?v=niSOvSuDJjU

***
