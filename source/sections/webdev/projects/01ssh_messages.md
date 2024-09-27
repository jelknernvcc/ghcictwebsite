# Asymmetric Encryption Activity

### Part 1: Encrypt a message

1. **Make sure you're working inside your git repository:**
   Start by making sure that you're in your GitHub repository where you'll store all the files for this activity.

   (You might need to change this line to match your GitHub repository folder name)
      ```bash
      cd ~/Desktop/website 
      ```

2. **Download and run the encryption script:**
   I wrote a command line tool that will encrypt messages for you. To download it, there are two steps:

      - Use the `curl` command to download the script:
         ```bash
         curl -s -O https://ict.gctaa.net/sections/webdev/goals/resources/ssh_activity/encrypt_message.sh
         ```

      - To protect your computer, by default downloaded scripts aren't allowed to run. This code makes the script executable:

         ```bash
         chmod +x encrypt_message.sh
         ```

3. **Run the encryption script:**
   
      Execute the script, which will:
      - Prompt for your partner’s GitHub username.
      - Automatically download your partner's public key from GitHub.
         - If your partner has multiple public keys, it will ask you to choose which one to use.
      - Prompt you to enter a secret message.
      - Encrypt the message and save the encrypted message to your computer.

      ```bash
      ./encrypt_message.sh
      ```

4. **Verify that the script ran successfully:**
   When the script finishes, you should see a new folder called `rsa_encryption_activity`. Inside that folder, you should see:
      - two other new folders called `send` and `receive`
      - a file called `partners_public_key.pem`
      - In the `send` folder, a file called `encrypted_message.b64`

5. **Commit these files to your Git repository:**
   Once the message is encrypted, share it with you partner by committing to your repository. This code will add all of the new files you created in the previous step.
      ```bash
      git add .
      git commit -m "Added public key and encrypted message"
      ```

6. **Push the changes to your Git repository:**
   Push the commits so your partner can access your encrypted message:

      ```bash
      git push
      ```

### Part 2: Decrypt the Received Message

7. **Download and run the decryption script:**
   Download the provided `decrypt_message.sh` script, which will decrypt the message sent to you by your partner.

      - Use the `curl` command to download my decryption script, and then make it executable:

         ```bash
         curl -s -O https://ict.gctaa.net/sections/webdev/goals/resources/ssh_activity/decrypt_message.sh
         
         chmod +x decrypt_message.sh
         ```



8. **Download your partner's encrypted message:**
   Visit your partner's GitHub repository and download their file `send/encrypted_message.b64` into your `receive` folder. You can use `curl` or download it manually through your browser.

9. **Run the decryption script:**
   Execute the decryption script, which will:
      - Ask for the location of your private key (you should be able to accept the default: `~/.ssh/id_rsa`).
      - Decrypt the received message and save the decrypted file to the `receive` folder.

      ```bash
      ./decrypt_message.sh
      ```

10. **Verify the decrypted message**
   After running the script, it will output the decrypted message to your screen. It will also save the decrypted file `receive/decrypted_message.txt`.

11. **Commit the decrypted message to your Git repository:**
   Once you have successfully decrypted your partner’s message, commit all the remaining files to your repository:

      ```bash
      git add .
      git commit -m "Added decrypted message and plaintext secret message"
      git push
      ```

### Part 3: Reflection

13. **Write a README:**
Add a README.md file to your rsa_encryption_activity folder. In this file, use Markdown to answer these prompts:
      - What is the difference between symmetric and asymmetric encryption?
      - Explain the steps of the encryption and decryption process
      - Why is it important that you never share your secret key?

This journal entry, and the files in your rsa_encryption_activity repo, are due by the beginning of next class. I'll count this as a quiz grade.

### Final GitHub Repository Structure

At the end of this activity, your `rsa_encryption_activity` folder in your GitHub repository should contain:

- `partners_public_key.pub`: Your partner's original public key (downloaded from GitHub).
- `README.md`: with answers to the journal prompts.
- `send/encrypted_message.b64`: The encrypted message you sent to your partner.
- `receive/encrypted_message.b64` (from partner): The encrypted message you received from your partner.
- `receive/decrypted_message.txt`: The decrypted message you received from your partner.

**Important:** **NEVER commit your private key (`~/.ssh/id_rsa`) to your repository or share it with anyone!**
