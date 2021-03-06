----------------------------Eintrag 16.01.2019(Zied)---------------------------------------------------------------------
Save() Funktion in Neural_net speichert das Netz in einem text Datei.
Ich habe ein KonsoleProgramm erstellt, man kann etweder ein Netz erstellen oder Datei importieren oder lesen.
Man sollte der Anzahl von Neuronen und die Gewichte eingeben, das Programm speichert das Ergebnis in ouput.txt automatisch.
Ouput.txt hat diese Form z.B : 
4 Neurons Input  Layer : 0.660000 || 0.330000 || 0.440000 || 0.270000 ||  
4 Neurons Hidden Layer : -0.135469 || 0.901697 || 0.009880 || -0.006568 ||  
3 Neurons Output Layer : -0.183544 || -0.332628 || -0.727383 || 
----------------------------Eintrag 16.01.2019(Mascha)-------------------------------------------------------------------------------------
Hi Leute, 

Momo, sehr gut gemacht! Das tut was es soll, nur noch ein paar kleine Änderungen müssen wir machen:
1. die Berechnung des nachsten Layers wird nicht nur durch die addition aller Produkte von Neuron und Kantengewicht erstellt, das Ergebnis davon ist dann der Input für die Aktivierungsfunktion. das heißt es muss in der neural_net klasse in der connect und connect1 methode noch die Variable Influence in die Aktivierungsfunktion gesteckt werden, das ist dann das output für das layer.

2. Im hiddenlayer und im input layer muss jeweils noch ein neuron für den bias in den vektor rein gespeichert werden. auch in der matrix für die kantengweichte muss eine spalte und zeile für den bias hinzugefügt werden.


außerdem todo:
// vektor erstellen für die target-werte, das heißt welcher Wert bei einem bestimmten Input als Output rauskommen soll (braucht man für backpropagation)
// funktion back implementieren für die backpropagation
// evtl koennten wir eine if-abfrage machen, ob die topologie ein zweites hidden layer vorsieht und dann ein zweites implementieren

----------------------------Eintrag 15.01.2019(momo)-------------------------------------------------------------------------------------
Hallo leute, 

die Connection.h datei entfällt und die funktion wird in der klasse neural_net.h festgehalten. 

bis jetzt gibt es ein hiddenlayer. d.h. wir berechnen (1): inputlayer -> hiddenlayer ; (2): hiddenlayer -> outputlayer
(1): funktion connected() in neural_net.h berechnet dies mit der matrix "matrix_of_edgeweights_between_layers" 
(2): funktion connected1() in neural_net.h berechnet dies mit der matrix "matrix_of_edgeweights_between_hiddenlayer_and_outputlayer"

mit void get_outputlayer(); ist die aufgabe 2.b erledigt sein. 
mit dem Manöwer in meilenstein3.cpp (ganz unten ab //-------------------NeuralNet----------------------------) ist die 2.c erledigt sein

----------------------------EINTRAG 13.01.2019(momo)----------------------------------------------------------------------------------------
Hi, 

es ist jetzt die neue datei connection.h dazugekommen. Diese erwartet als eingabe ein inputlayer, ein Hiddenlayer(hier haben die Neuronen noch kein gewicht), und die entsprechende Matrix, die zwischen den layers erstellt wird mithilfe der klasse weight.h. Nachdem die Funktion aufgerufen wurde, wird den Neuronen aus hiddenlayer die neuen werte zugeordnet. Aufrufbeispiel: connect(inputlayer, matrix, hiddenlayer);

In neural_net.h sind drei neue funktionen dazugekommen. generate_inputlayer(); generate_hiddenlayer(); generate_outputlayer(); 
Die layer werden mit neuronen gefüllt, welche bereits mithilfe von bereits erstellten layer aus layer.h gefüllt werden. 

So dürften folgende dinge klappen: 
- neuronales netz erstellen mit einer vorgegebenen Topologie
- die verbindung der Layer 
----------------------------EINTRAG 13.01.2019 --------------------------------------------------------------------------------------------

Hallo Leute, 

ich habe die Datei, um die Gradienten zu berechnen jetzt erstellt. damit sollte Aufgabe 1 tatsächlich ganz fertig sein, und wir können mit der Berechnung der Output Werte und der Backpropagation anfangen. 

Mascha

----------------------------EINTRAG 12.01.2019 --------------------------------------------------------------------------------------------

Hallo, 

die Änderrungen dürften jetzt gelten. 

ACHTUNG!
- wegen der Übersichtlichkeit habe ich nun eine layer.h datei eingefügt. Die Layers werden also da definiert.
- typedef vector<neuron> vectorneurons ist ein Vektor aus allen neuronen aus dem bestimmten layer (wichtig für die Verbindung und viele andere coole Dinge)
- Die Eingabeaggregation wie auf den Folien beschrieben habe ich auch in der meilenstein3.cpp unten definiert. 
- Mein Ansatz für die Verbindung (Aufgabe 1c) ist jetzt nicht optimal, aber er klappt ! für jede neu entstandene weight klasse und jedes Layer dazu, muss die Verbindung auf dieser Art folgen. (wie gesagt: es klappt und ist nicht die geschickteste Lösung.) 


----------------------------EINTRAG 11.01.2019 --------------------------------------------------------------------------------------------
Hallo Leute, 

die Änderungen, wie mascha sie vorgeschlagen hat wurden übernommen. Jetzt sollten keine doppelten Datein und überflüssige Datein vorhanden sein.
----------------------------EINTRAG 09.01.2019 --------------------------------------------------------------------------------------------

Habe gerade meine main.cpp gelöscht, die einzige main datei ist jetzt meilenstein3.cpp. Zur Übersichtlichkeit sind folgende Veränderungen vorgenommen worden:

- meilenstein3.cpp enthält jetzt die Definitionen von der Funktion f und der Ableitung. aktivierungsfunktion.h löschen?
- meilenstein3.cpp enthält jetzt auch die definition der Typen für die Vektoren der Layer - VektorMatrix.h löschen?
- die klasse "neuron" gibt es auch zweimal, ich würde die eine die Momo gemacht hat weglassen, 
weil da teilweise mit Kantengewichten arbeitet, und das braucht man ander Stelle gar nicht. Und sonst sind die Klassen auch völlig gleich

außerdem steht in den headern der Dateien manchmal #include "inputoutput.h", aber es gibt keine datei die so heißt, fehlt da was?


----------------------------EINTRAG 09.01.2019 --------------------------------------------------------------------------------------------
Ein Zwischenbericht. 

Hallo Leute, ich habe jetzt einige Änderungen vorgenommen an dem Code und bitte euch diese zu beachten. 

Bisher habe ich das Inputlayer fertig gemacht und die Klasse neuron.h sollte soweit auch ganz gut aussehen. 
in der Datei vektormatrix.h findet ihr drei angelegte Datentypen, welche ich definiert habe für die Layer. 
(Inputlayer, Hiddenlayer, Outputlayer). 

In der main.cpp datei, habe ich ein inputlayer schon angelegt. Bitte beachtet, dass beim inputlayer die Aktivierungsfunktion nicht berücksichtigt wird und diese erst ab den nachkommenden Layers wichtig wird. 

Welche Aufgaben wären als nächstes sinvoll ? 
- wir brauchen jetzt die Matrix, welche die zufällig generierten, standart normalverteilten Zufallszahlen beinhaltet. (Zied seine aufgabe !).

- In Aufgabe c ist nach der Verbindung der Kantengewichten gefragt, welches ein Neuron von Layer i-1 zu allen anderen Neuronen von Layer i 
  hate. die Spalte1 der Matrix entspricht die Kantengewichte vom ersten Neuron in Layer i-1 zu allen Neuronen in Layer i usw...
Meine bisherige Idee hierzu: 
Alle Neuronen im Hiddenlayer besitzen ein Inputvector, dieser entspricht die Zeile der Matrix. Wir brauchen also einen Ansatz, indem wir die Zeile aus der Generierten Matrix extrahieren und als Vector einem Neuron im Hiddenlayer übergeben. 

VORSICHT ! Wir haben 2 main.cpp dateien, einmal von Mascha (main.cpp), und einmal von mir(meilenstein3.cpp)


Hallo Leute, 

Bitte importiert neue Bibliotheken in der Datei bibliotheken.h und importiert anschließend immer diese in eurer neuer datei. 

Bisher habe ich die Aktivierungsfunktion implementiert. 

Wichtige Aufgaben : 

- Zufallszahlen generieren und diese in das Input Layer reinladen. (die Vektoren und Matrizen sind in VektorMatrix.h. 
--> zufallszahlen sollen nicht in das input layer, sondern als kantengewichte eingegeben werden als Standardnormalverteilte Zahlen. diese Funktion müsste gehen:
http://www.cplusplus.com/reference/random/normal_distribution/
mit den parametern (0.0,1.0) für 0.0 = mean = Erwartungswert und 1.0 = standart deviation = Varianz 


Unklarheiten: 

- Wie genau läuft die Berechnung von Layer 1 -> Layer 2 ab ? 
--> jedes Neuron des ersten Layer hat einen Wert (output des Neurons). Von diesem Neuron gehen Kanten zu jedem Knoten des nächsten Layers, und die Kanten haben unterschiedliche Gewichte (die wir vorher randomly vergeben haben). 
Die Berechnung läuft dann so:
für jeden Knoten in Layer 2 wird jeweils der Wert, multipliziert mit dem Knatengewicht des Knoten aus Layer 1, der auf den zu bestimmenden Knoten aus Layer 2 zeigt aufaddiert und am ende uU noch ein Bias addiert. der wert der dabei rauskommt, ist der wert, der in die Funktion gesteckt wird. Das Ergebnis ist der output für den Knoten in Layer 2.

die Matrix mit den Kantengewichten wird also mit dem Vektor der Werte für Layer 1 multipliziert und jeder Eintrag des Ergebnisvektors dann in die Funktion gesteckt. das Ergebnis ist der output-vektor




/*

Wichtige Notizen zum Projekt. 

Was macht die Aktivierungsfunktion ? -- Bestimmt die Ausgabe des Neurons. 

Wichtige Aufgaben: 
Das Eingabe Layer : anfangs mit dem startvektor und einer Matrix, in dem die Gewichte von Layer i zu Layer i + 1 gespeichert werden. 
Eingabeaggregation: bestimmt den neuen Ausgabevektor.

----------------------------------------------------------------------------------------------------------------------------------------------------------------
Berechnung des Hidden Layers:
Für jedes Layer entsteht ein neues Ausgabenvektor pvec. Die Einträge in pvec sind die neuen koeffizienten zur bestimmung der neuen gewichte.
Wie wird dieses neue pvec bestimmt ? pvec(i) = f(xi) (die Berechnung des neuen Vektors entsteht koeffizient für koeffizient.
Bestimmung der neuen Gewichte für Layer i + 1 : Hierzu wird der Ausgabevektor aus Layer i mit der Matrix von Layer i multipliziert. 

----------------------------------------------------------------------------------------------------------------------------------------------------------------
Output des Neuronalen Netzes: 

Der Outpout des neuronalen Netzes ist ein Vektor !. 
*/






--------------------------------------------------------------------------------------------------------------------------------------------


