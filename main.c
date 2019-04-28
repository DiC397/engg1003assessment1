#include<stdio.h>
#include<string.h>
 
int main(void)
{
    char message[1000], c[1000], ct[1000], m;  //maximum number of code to be entered
	int i; //a variable for alphabets
	int j; //a variable for alphabets
	int index; //to store converted alphabets
	int shift;   //allows input value for number of shift of letters up to 26
	int option;
    printf("1 is decryption with rotation cipher \n2 is encryption with rotation cipher \n3 is decryption with subsitution cipher \n4 is encrpytion with substitution cipher \nChoose from case 1-4: \n");
    fflush(stdout); //allows code to buffer
    scanf(" %d", &option);
        for (i=0; i<26; i++) { //counts i in increments until 26 which are the alphabets
            ct[i]=0;
        }
        
    if(option==1) //decryption using rotation cipher
    {
    	printf("\nEnter a message to decrypt: \n");
    	fflush(stdout); //allows code to buffer
    	scanf(" %[^\n]s",message);  //%[^\n]s allows multiple independent format specifiers
    	printf("Enter number of shift: \n");  //selection of number of rotation
    	fflush(stdout); //allows code to buffer
    	scanf("%d", &shift); //input of integer
    	
    	for(i=0; message[i] !='\0'; ++i) 
    	{
            if (message[i]<='z' && message[i]>='a') // check if code contains lowercases
            {  
                message[i]=message[i]-'a'+'A'; // converts lowercases to uppercases
            }
            
    		m=message[i];
    		
    		if(m>='A' && m<='Z') //checks for uppercases
    		{
    			m=m-shift; //allows shift of alphabets
    			if(m<'A')
    			{
    				m=m+'Z'-'A'+ 1; //keeps the uppercases
    			}
    			message[i]=m;
    		}
    	}
    	
    	printf("\nCiphered message is: %s \n", message);
    	printf("\n\n\n"); //allows three blank paragraph at the end for neatness
    } else if (option==2) //encryption using rotation cipher
    {
    	printf("\nEnter a message to encrypt: \n");
    	fflush(stdout); //allows code to buffer
    	scanf(" %[^\n]s ",message); //%[^\n]s allows multiple independent format specifiers
    	printf("\nEnter number of shift: \n");
    	fflush(stdout); //allows code to buffer
    	scanf("%d", &shift);
    	
    	for(i=0; message[i] !='\0'; ++i)
    	{
            if (message[i]<='z' && message[i]>='a') // check if code contains lowercases
            { 
                message[i]=message[i]-'a'+'A'; // converts lowercases to uppercases
            }

    		m=message[i];
    		
    		if(m>='A' && m<='Z') //checks for uppercases
    		{
    			m=m+shift; //allows shift of alphabets
    			if(m>'Z')
    			{
    				m=m-'Z'+'A'- 1; //keeps the uppercases
    			}
    			message[i]=m;
    		}

    	}
    		
    	printf("\nCiphered message is: %s \n", message);
    	printf("\n\n\n"); //allows three blank paragraph at the end for neatness
    } else if(option==3) //decryption using substitution cipher
    {
        
        printf(" \nEnter decrypted message: \n");
        fflush(stdout); //allows code to buffer
        scanf(" %[^\n]s",message); //%[^\n]s allows multiple independent format specifiers
        
        printf("\nEnter Key From A to Z: \n");
        printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
        fflush(stdout); //allows code to buffer
        scanf(" %[^\n]s", c); //%[^\n]s allows multiple independent format specifiers

        for(i = 0; i < 26; i++) //counts i in increments up to 26 which are the alphabets
        {
            if (c[i]<='z' && c[i]>='a') {  // check if code contains lowercases
                c[i]=c[i]-'a'+'A'; // convert lowercases to uppercases
            }
            
            
        }
      
        for(i = 0; i < strlen(message); i++)
        {
            if (message[i]<='z' && message[i]>='a') { //checks if code contains lowercases
                message[i]=message[i]-'a'+'A'; //converts lowercases into uppercases
            }
          
            index = message[i]- 65; //uses ASCII table to convert lowercases into uppercases
            
            if(0<=index && index<26){
                ct[i] = c[index];   // stores corresponding encypted letter in ct if a capital letter
            } else {
                ct[i] = message[i]; // stores character from message if not a capital letter 
            }
        }
      
        printf("\nCiphered message is: %c", ct[i]);
        for(i = 0; i < strlen(message); i++)
        {
            printf("%c", ct[i]);
        }
        printf("\n\n\n"); //allows three blank paragraph at the end for neatness
    } else if(option==4) //encryption using substitution cipher
    {
        
        printf(" \nEnter encrypted message: \n");
        fflush(stdout); //allows code to buffer
        scanf(" %[^\n]s",message); //%[^\n]s allows multiple independent format specifiers
        
        printf("\nEnter Key From A to Z: \n");
        printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
        fflush(stdout); //allows code to buffer
        scanf(" %[^\n]s", c); //%[^\n]s allows multiple independent format specifiers

        for(i = 0; i < 26; i++)
        {
            if (c[i]<='z' && c[i]>='a') {  // check if code contains lowercases
                c[i]=c[i]-'a'+'A'; // convert lowercases to uppercases
            }
            
        }
        
        for (i=0; i<strlen(message); i++) 
        {
            if (message[i]<='z' && message[i]>='a') {  // check if code contains  lowercases
                message[i]=message[i]-'a'+'A';  //converts lowercases into uppercases
            }
            for (j=0; j<26; j++) 
            {
                if (message[i] == c[j]) 
                {
                    ct[i]=j+ 65;
                }
            }
        }
        
        printf("\nCiphered message is: %c", ct[i]);
        for(i = 0; i < strlen(message); i++)
        {
            printf("%c", ct[i]);
        }
        printf("\n\n\n"); //allows three blank paragraph at the end for neatness
    }
    	return 0;
}

