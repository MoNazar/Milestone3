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


--------------------------------------------------------------------------------------------------------------------------------------------


