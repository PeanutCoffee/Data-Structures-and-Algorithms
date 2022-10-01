import discord
import os
import requests
import json
import random
from replit import db
from keep_alivelol import keep_alivelol


client = discord.Client()



sad_words = ["sad" , "depressed" , "miserable" , "angry" , "unhappy" , "depressing" , "unlucky" , "what is the best subject?", "coloured text ploxx",'starexit']

starter_encouragements = ["cheer up!","Dont worry, everything will be fine!","You are a great person!","starexit"]

if "responding" not in db.keys():
  db["responding"] = True

def get_quote():
  response = requests.get("https://zenquotes.io/api/random")
  json_data = json.loads(response.text)
  quote = json_data[0]["q"] + " -" + json_data[0]["a"]
  return (quote)

def update_encouragements(encouraging_message):
  if "encouragements" in db.keys():
    encouragements = db["encouragements"]
    encouragements.append(encouraging_message)
    db["encouragements"] = encouragements
  else:
    db["encouragements"] = [encouraging_message]

def delete_encouragement(index):
  encouragements = db["encouragements"]
  if len(encouragements) > index:
    del encouragements[index]
  db["encouragements"] = encouragements

@client.event

async def on_ready():
    await client.change_presence(activity=discord.Streaming(name='LEGION COMMANDER', url='https://www.youtube.com/watch?v=-LReNkc7KUg&t=1s&ab_channel=LIEGEMAXIMO-LEGIONCOMMANDER'))
    
    print('Connected to bot: {}'.format(client.user.name))
    print('Bot ID: {}'.format(client.user.id))


@client.event
async def on_message(message):
  if message.author == client.user:
    return

  msg = message.content  


  if message.content.startswith("$inspire"):
    quote = get_quote()
    await message.delete()
    await message.channel.send(quote, delete_after=20)
  

  if message.content.endswith("$hello"):
    await message.channel.send("Hello World!")

  if message.content.startswith("$help"):
    await message.channel.send("The commands are - ```$inspire``` ```$quotes``` ```To add new encouraging message, use- $new [enter ur message here] .``` ```To view all added messages , use - $list``` ```To delete an encouraging message, use- $del [insert value from 0-(number of elements in list - 1]``` ```To turn on or off this kewl feature of encouraging you , use - $responding['true' or 'false'] ``` ```Transformers - $transformers```")
  

  if message.content.startswith("$quotes"):
    await message.channel.send("To get the most famous quotes said by **OPTIMUS PRIME** , type - ```$orionquote[choose from 1-9 or from 010-015]```")
  
  if message.content.startswith("$orionquote1"):
    await message.channel.send("```Autobots, Transform And Roll Out!```")  

  if message.content.startswith("$orionquote2"): 
    await message.channel.send("```One Shall Stand, One Shall Fall!```") 

  if message.content.startswith("$orionquote3"):
    await message.channel.send("```One Day, An Autobot Will Rise From Our Ranks And Use The Power Of The Matrix To Light Our Darkest Hour. Until That Day, Til' All Are One.```")
  
  if message.content.startswith("$orionquote4"):
    await message.channel.send("```There's A Thin Line Between Being A Hero, And Being A Memory.```")
 
  if message.content.startswith("$orionquote5"):
    await message.channel.send("```Sometimes Even The Wisest Of Man Or Machine Can Make An Error.```")

  if message.content.startswith("$orionquote6"):
    await message.channel.send("```Thrones Are For Decepticons. Besides, I'd Rather Roll!```")

  if message.content.startswith("$orionquote7"):
    await message.channel.send("```Stick It In Neutral, Megatron.```")

  if message.content.startswith("$orionquote8"):
    await message.channel.send("```We Must Have Courage. We Can't Ignore The Danger. We Must Conquer It.```")

  if message.content.startswith("$orionquote9"):
    await message.channel.send("```We Can't Stand By And Watch The Destruction Of This Beautiful Planet.```")
 
  if message.content.startswith("$orionquote010"):
    await message.channel.send("```Freedom Is The Right Of All Sentient Beings.```")

  if message.content.startswith("$orionquote011"):
    await message.channel.send("```Even If You Defeat Me, Megatron. Others Will Rise To Defeat Your Tyranny.```")

  if message.content.startswith("$orionquote012"):
    await message.channel.send("```I Will Never Stop Fighting For Our Freedom.```")

  if message.content.startswith("$orionquote013"):
    await message.channel.send("```We've Suffered Losses, But We've Not Lost The War.```")

  if message.content.startswith("$orionquote014"):
    await message.channel.send("```Now, All We Need Is A Little Energon, And A Lot Of Luck!```")

  if message.content.startswith("$youtube"):
    await message.channel.send("**New video out! - 5 Canada Student Visa Rejection Reasons. How to Reapply for Study Permit for International Students:**\nhttp://bit.ly/iamcanada")

  if message.content.startswith("$transformers"):  
    await message.channel.send("1.Transformers : Rescue Bots - <https://anime-world.in/series/transformers-rescue-bots> \n\n2.Transformers : War For Cybertron - <https://anime-world.in/series/transformers-war-for-cybertron/> \n\n3.Transformers Prime Beast Hunters: Predacons Rising (Movie) - <https://anime-world.in/movies/transformers-prime-beast-hunters-predacons-rising/> \n\n4.Transformers: Robots In Disguise - <https://anime-world.in/series/transformers-robots-in-disguise/> \n\n5.Transformers: Prime - <https://anime-world.in/series/transformers-prime/>")  
    
  
  if db["responding"]:
   options = starter_encouragements
   if "encouragements" in db.keys():
     options = options + db["encouragements"]

   if any(word in msg for word in sad_words):
     await message.channel.send(random.choice(options))

  if msg.startswith("$new"):
    encouraging_message = msg.split("$new ",1)[1]
    update_encouragements(encouraging_message)
    await message.channel.send("New encouraging message has been added.")

  if msg.startswith("$del"):
    encouragements = []  
    if "encouragements" in db.keys():
      index = int(msg.split("$del",1)[1])
      delete_encouragement(index)
      encouragements = db["encouragements"]
    await message.channel.send(encouragements)  

  if msg.startswith("$list"):
    encouragements = []
    if "encouragements" in db.keys():
      encouragements = db["encouragements"]
    await message.channel.send(encouragements)


  if msg.startswith("$responding"):
    value = msg.split("$responding ",1)[1]

    if value.lower() == "true":
      db["responding"] = True
      await message.channel.send("Responding is on.")

    else: 
      db["responding"] = False
      await message.channel.send("Responding is off.") 




keep_alivelol()
client.run(os.getenv("TOKENORION"))    