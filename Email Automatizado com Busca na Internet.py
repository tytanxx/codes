""" 
Crie este código para enviar email com busca na internet automático
Para funcionar corretamente é necessário estar conectado com um email no OUTLOOK do seu PC
No conteúdo do email coloquei o índice BOVESPA e o IPCA como exemplo
Este código foi criado por João Augusto Carrascoza
Data 27/07/2022 

"""
#Biblioteca para enviar o email por meio do outlook
import win32com.client as win32

#Bibliotecas responsáveis pela busca de informações na internet
import requests
from bs4 import BeautifulSoup

#---------------------------------------------
#Agora irei buscar as informações na internet|
#---------------------------------------------

#Aqui você precisa digitar o headers
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/101.0.4951.67 Safari/537.36'}
    
#Busca da informação: BOVESPA na internet
page0 = requests.get('https://br.investing.com/indices/bovespa',headers=headers)
soup0 = BeautifulSoup(page0.content, 'html.parser')
bovespa = soup0.find_all('span', class_= 'text-2xl')[0]

#Busca da informação: IPCA acumulado em 12 meses na internet
page1 = requests.get('https://www.ibge.gov.br/explica/inflacao.php', headers=headers)
soup1 = BeautifulSoup(page1.content, 'html.parser')
ipca = soup1.find_all('p', class_= 'variavel-dado')[1]


#------------------------------
#Agora irei configurar o email|
#------------------------------

#Aqui estou chamando a aplicação do outlook
outlook = win32.Dispatch('outlook.application')
email = outlook.CreateItem(0)

#No comando abixo fica o email que você deseja enviar uma mensagem
#'email@email.com; outro@email.com' - caso queiro colocar mais de 1 email
email.To = 'email@email.com'

#No comando abaixo fica o Com Cópia (Cc) do email
#'email@email.com; outro@email.com' - caso queiro colocar mais de 1 email
email.CC = 'email@email.com'

#No comando abixo digite o assunto desejado
#'email@email.com; outro@email.com' - caso queiro colocar mais de 1 email
email.Subject = 'Assunto do email'

#No comando abaixo você pode digitar o corpo do email
#Coloque <p> e </p> para iniciar e terminar uma frase respectivamente
email.HTMLBody = f""" 
<p>Olá, sou o João Augusto!</p>

<p>Segue abaixo os dados solicitados:</p>
<p>Bovespa: {bovespa.text}</p>
<p>IPCA em 12 meses: {ipca.text}

<p>Atenciosamente,</p>
<p>João Augusto Carrascoza.</p>
"""

#Caso queira colocar um anexo digite o comando abaixo
anexo = "path"
#Comando para anexar o arquivo
email.Attachments.Add(anexo)

#No comando abaixo é enviado o email
email.Send()

print('O email foi enviado com sucesso!')