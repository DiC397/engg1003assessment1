#include<stdio.h>
#include<conio.h>
 
void main()
{
    char message[1000], c[27], ct[1000], m;  //maximum number of code to be entered
	int i;
	int j;
	int index;
	int shift;   //allows input value for number of shift of letters up to 26
	int option;
    printf("1 is decryption with rotation cipher \n2 is encryption with rotation cipher \n3 is decryption with subsitution cipher \n4 is encrpytion with substitution cipher \nChoose from case 1-6: ");
    scanf("%d", &option);
    getchar();    //allows use of gets rather than just scanf

    if(option==1)
    {
    	printf("\nEnter a message to decrypt: ");
    	gets(message);  //gets allows readings of single strings on keyboard
    	printf("\nEnter number of shift: ");  //selection of number of rotation
    	scanf("%d", &shift);
    	
    	for(i=0; message[i] !='\0'; ++i)
    	{
            if (message[i]<='z' && message[i]>='a') // check if lowercase
            {  
                message[i]=message[i]-'a'+'A'; // convert to uppercase
            }
            
    		m=message[i];
    		
    		if(m>='A' && m<='Z')
    		{
    			m=m-shift;
    			if(m<'A')
    			{
    				m=m+'Z'-'A'+ 1;
    			}
    			message[i]=m;
    		}
    	}
    	
    	printf("\nDecrypted message: %s", message);
    	
    } else if (option==2)
    {
    	printf("\nEnter a message to encrypt: ");
    	gets(message);
    	printf("\nEnter number of shift: ");
    	scanf("%d", &shift);
    	
    	for(i=0; message[i] !='\0'; ++i)
    	{
            if (message[i]<='z' && message[i]>='a') // check if lowercase
            { 
                message[i]=message[i]-'a'+'A'; // convert to uppercase
            }

    		m=message[i];
    		
    		if(m>='A' && m<='Z')
    		{
    			m=m+shift;
    			if(m>'Z')
    			{
    				m=m-'Z'+'A'- 1;
    			}
    			message[i]=m;
    		}

    	}
    		
    	printf("\nEncrpyted message: %s", message);
    } else if(option==3)
    {
        printf("\nEnter decrypted message: ");
        gets(message);
        
        printf("\nEnter Key From A to Z: \n");
        
        for(i = 0; i < 26; i++)
        {
            printf("%c-", i + 65);  //%c is character and 65 is from ASCII table for letters from decimal.
            c[i] = getch(); //getch() changes numbers into letters and allows no buffer
            printf("%c , ", c[i]);  //for input of substitution letters
 
            if (c[i]<='z' && c[i]>='a') {  // check if lowercase
                c[i]=c[i]-'a'+'A'; // convert to uppercase
            }
            
            
        }
      
        for(i = 0; i < strlen(message); i++)
        {
            if (message[i]<='z' && message[i]>='a') {  // check if lowercase
                message[i]=message[i]-'a'+'A'; // convert to uppercase
            }
          
            index = message[i]- 65;
            
            if(0<=index && index<26){
                ct[i] = c[index];   // stores corresponding encypted letter in ct if a capital letter
            } else {
                ct[i] = message[i]; // stores character from message if not a capital letter 
            }
            
            //printf("%d", index);
            //printf("%c\n", c[index]);
        }
      
        printf("\nCipher message is: %c", ct[i]);
        for(i = 0; i < strlen(message); i++)
        {
            printf("%c", ct[i]);
        }
        
    } else if(option==4)
    {
        printf("\nEnter encrypted message: ");
        gets(message);
        
        printf("\nEnter Key From A to Z: \n");
        for(i = 0; i < 26; i++)
        {
            printf("%c-", i + 65);  //%c is character and 65 is from ASCII table for letters from decimal.
            c[i] = getch(); //getch() changes numbers into letters and allows no buffer
            printf("%c , ", c[i]);  //for input of substitution letters
            
            if (c[i]<='z' && c[i]>='a') {  // check if lowercase
                c[i]=c[i]-'a'+'A'; // convert to uppercase
            }
            
        }
        
        for (i=0; i<strlen(message); i++) 
        {
            if (message[i]<='z' && message[i]>='a') {  // check if lowercase
                message[i]=message[i]-'a'+'A';  // convert to uppercase
            }
            for (j=0; j<26; j++) 
            {
                if (message[i] == c[j]) 
                {
                    ct[i]=j+ 65;
                }
            }
        }
        
        printf("\nCipher message is: %c", ct[i]);
        for(i = 0; i < strlen(message); i++)
        {
            printf("%c", ct[i]);
        }
    }
    	return 0;
}

