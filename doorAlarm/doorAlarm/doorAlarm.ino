const int songLength = 18;
char notes[] = "cdfda ag cdfdg gf ";
int beats[] = {1,1,1,1,1,1,4,4,2,1,1,1,1,1,1,4,4,2};
int tempo = 113;
int sensorPin=10;
int buzzPin=5;
int prevState=LOW;
int state=LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin,INPUT_PULLUP); // sensor
  pinMode(buzzPin,OUTPUT);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  state=digitalRead(sensorPin);
  if(state!=prevState && state==HIGH){
    int i, duration;
    for (i = 0; i < songLength; i++) // step through the song arrays
    {
      duration = beats[i] * tempo;  // length of note/rest in ms
      if (notes[i] == ' ')          // is this a rest? 
      {
        delay(duration);            // then pause for a moment
      }
      else                          // otherwise, play the note
      {
        tone(buzzPin, frequency(notes[i]), duration);
        delay(duration);            // wait for tone to finish
      }
      delay(tempo/10);              // brief pause between notes
    }

    state=LOW;
  }
  prevState=state;
  
}


int frequency(char note) 
{
  int i;
  const int numNotes = 8;  // number of notes we're storing
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency
    }
  }
  return(0);  
}
