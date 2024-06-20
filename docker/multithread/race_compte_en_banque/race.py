import threading
import os
import time


def debit():
    os.system("echo 100 | ./race")
    global debit_reel
    debit_reel += 100

t=time.time()
win=0
for i in range(100):  
	debit_reel=0  
     
	with open('compte.txt') as f: 
		solde1=int(f.read()) #solde initial 
		
	t1 = threading.Thread(target=debit)  
	t2 = threading.Thread(target=debit)

	t1.start()   # débit est lancé sur deux thread
	t2.start()
	t1.join()
	t2.join()

	with open('compte.txt') as f:   
			solde2=int(f.read())  #solde final écrit sur le compte

	debit_compte = solde1-solde2

	print(debit_reel,"€ ont été retiré, le compte affiche un débit de",debit_compte,"€")

	if(debit_compte != debit_reel):
		print("Race condition a fonctionné")
		win+=1
	else:
		print("Race condtion a échoué")
print(win,"% de réussite")
