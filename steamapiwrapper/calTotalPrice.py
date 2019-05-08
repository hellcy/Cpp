from steamapiwrapper.SteamGames import Games
games = Games()

# for calculate total price and multiple game ids per request
# full_price = 0.0
# discounted_price = 0.0
# for game in games.get_all('US'):
# 	if game['initial'] != 0:
# 		discounted_price += game['final']
# 		full_price += game['initial']
# 		#print(full_price, discounted_price)
# 	print(game['currency'], game['final_formatted'])

for game in games.get_all('CN'):
	if 'price_overview' not in game:
            continue
	print(game['name'], game['steam_appid'], game['price_overview']['final_formatted'])