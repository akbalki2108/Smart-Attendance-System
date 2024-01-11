char card_no[13]; // Increased array size to accommodate null terminator '\0'
char prev_card_no[13]; // Increased array size to accommodate null terminator '\0'

int isNewCardPresent();

void cardReaderSetup(){
  Serial.println("\nEM-18 Reader Module");
  
  for(int i=0;i<12;i++){
    card_no[i]='\0';
    prev_card_no[i]='\0';
  }

}

void cardReaderLoop(){

   // Reset the loop if no new card present on the sensor/reader.
  if(!isNewCardPresent()) return;

  if (Serial.available()) {
    int count = 0;
    while (Serial.available() && count < 12) {
      card_no[count] = Serial.read();
      count++;
      delay(5);
    }
    card_no[count] = '\0'; // Adding null terminator to mark the end of the string

    // Check if the current card number matches the previous one
    if (strcmp(card_no, prev_card_no) == 0) {
      Serial.println("Card already used");
      onRedLed();
    } else {

      // If not the same card, update previous card number and perform other actions
      Serial.println("\nNew card detected !!");
      strcpy(prev_card_no, card_no); // Update previous card number
      Serial.print("Code : ");Serial.println(card_no);

      String cardNumberString = String(card_no);
      sendCardNo(cardNumberString);
    }
  }
  delay(500);

  offWhiteLed();
  offRedLed();

}

int isNewCardPresent(){
   if (strcmp(card_no, prev_card_no) == 0) {
      // Serial.println("Card already used");
      return 1;
    }
  return 0;
}

