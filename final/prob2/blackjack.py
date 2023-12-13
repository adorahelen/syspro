import cards, games
# 클래스 총 5개 생성 1.포지션카드 2.덱 3. 플레이어 4. 딜러 5. 게임


class Positionable_Card (cards.Card)
 ACE_VALUE = 1
 @property
 def value (self):
     if self.is_face_up:
        v = Positionable_Card.RANKS.index (self.rank) + 1
        if v > 10:
             v = 10

         else:
            v = None
          return v
#블랙잭 카드 클래스 생성 

class Deck (cards.Deck):
     def populate (self):
        for suit in Positionable_Card.SUITS:
           for rank in Positionable_Card.RANK:
              self.cards.append (Positionable_Card(rank, suit))


class Player (Delar):
 
   def is_hitting(self):
       response = games.ask_yes_no ("\n" + self.name + ", do you wnat to hit? (Y/N): \t")
       return response == "y"


   def bust (self):
       print (self.name, "busts!")
       self.lose ()
 
   def lose (self):
       print (self.name, "loses!")

   def win (self):
       print (self.name, "win")

   def push (self):
       print (self.name, "pushes.")


class Dealer (Player)
  
   def is_hitting (self):
       return self.total < 17

   def bust (self):
       print (self.name, "busts!\t Table win!")


   def flip_first_card (self):
       first_card = self.cards[0]
       first_card.flip ()


class BJ_Game (object):


   def __init__ (self, names):
        self.players = []
        for name in names:
            player = Player (name)
            self.players.append (player)

        self.dealer = Dealer ("Dealer")

        self.deck = Deck()
        self.deck.populate ()
        self.deck. shuffle ()


   @property
    def still_playing (self):
        sp = []
        for player in self.players:
        .
        .
        .


def main ():
    print ("\t\t Welcome to BlackJAck\n")

    names = []
    number = games.ask_number("             ")

    for i in range (number):
    name = input 
    names.append (name)

  
   game = BJ_Game (names)



   again = None


   while again!

# main 함수 정의

main () # call main 
input ("\n\nPress Enter to eixt")

















 

    




     

      
