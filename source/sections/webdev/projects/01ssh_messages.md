# Asymmetric Encryption Activity

#### Part 1: Prepare the Public and Private Keys

1. **Create a new folder in your Git repository:**
   Start by creating a new folder in your GitHub repository to store all the files for this activity. Inside of that folder, you'll make a folder for messages that you are sending and messages that you are receiving.

   ```bash
   mkdir rsa_encryption_activity
   cd rsa_encryption_activity
   mkdir send
   mkdir receive
   ```

2. **Access your partner's public key from GitHub:**
   Visit the GitHub `.keys` URL for your partner's account (e.g., `https://github.com/partner_username.keys`) and download their public key.

   Use the following command to save your partner's public key:
   ```bash
   curl https://github.com/partner_username.keys > partner_key.pub
   ```

3. **Convert your partner’s public key to PEM format:**
   By default, GitHub SSH public keys are in OpenSSH format. To use this key with OpenSSL, you need to convert it to PEM format using `ssh-keygen`:

   ```bash
   ssh-keygen -f partner_key.pub -e -m PEM > partner_key.pem
   ```

   Commit the PEM-formatted public key to your Git repository:
   ```bash
   git add partner_key.pub
   git add partner_key.pem
   git commit -m "Converted partner's public key to PEM format"
   ```

4. **Convert your private key to PEM format (if necessary):**
   On your local computer, convert your own SSH private key to PEM format to ensure it works with OpenSSL.

   Run the following command:
   ```bash
   ssh-keygen -p -m PEM -f ~/.ssh/id_rsa
   ```

   **Important:** **Do NOT commit your private key to your Git repository!** Your private key should remain secret.

#### Part 2: Write and Encrypt a Secret Message

1. **Write your secret message to a file using Vim:**
   Open a new file and write your secret message:
   ```bash
   vim send/secret_message.txt
   ```
   After writing your message, save and close the file.

2. **Encrypt the secret message using your partner's public key:**
   Use your partner’s PEM-formatted public key to encrypt your message. You'll put the encrypted message into a folder called 'send' Run the following command:

   ```bash
   cat send/secret_message.txt | openssl pkeyutl -encrypt -pubin -inkey partner_key.pem | base64 > send/encrypted_message.b64
   ```

   This command reads the content of the secret message, encrypts it using your partner's public key, and then saves it to a file.

   Commit the encrypted message to your repository:
   ```bash
   git add send/encrypted_message.b64
   git commit -m "Added encrypted message for my partner"
   ```

   (don't commit the plaintext version yet - that would spoil the fun for your partner!)

3. **Push the changes to your Git repository:**
   Push the commits so your partner can access your encrypted message:
   ```bash
   git push
   ```

#### Part 3: Decrypt the Received Message

1. **Access your partner's repository and download their encrypted message:**
   Visit your partner's github repo and download their file `send/encrypted_message.b64` into your `receive` folder. You can do this with curl, or you can use the browser.


2. **Decrypt the received message:**
   Use your private key to decrypt the received message:
   ```bash
   base64 -d -i receive/encrypted_message.b64 | openssl pkeyutl -decrypt -inkey ~/.ssh/id_rsa > receive/decrypted_message.txt
   ```
   This command loads the encrypted message that you received from your partner and then decodes it using your secret key.

   Once your partner has decrypted, compare and make sure they got it right! After you've confirmed, go ahead and commit all of the remaining files to your repository:
   ```bash
   git add receive/encrypted_message.b64 
   git add receive/decrypted_message.txt 
   git add send/secret_message.txt
   git commit -m "adding plaintext secret message, and both versions of secret message"
   ```

3. **Push the changes to your Git repository:**
   Push the updated repository:
   ```bash
   git push
   ```

### Final GitHub Repository Structure

At the end of this activity, your `rsa_encryption_activity` folder in your GitHub repository should contain:

- `partner_key.pub`: Your partner's original public key (downloaded from GitHub).
- `partner_key.pem`: Your partner's public key converted to PEM format.
- `secret_message.txt`: The plaintext of the message you sent to your partner.
- `encrypted_message.b64`: The encrypted message you sent to your partner.
- `encrypted_message.b64` (from partner): The encrypted message you received from your partner.
- `decrypted_message.txt`: The decrypted message you received from your partner.

**Important:** **Do NOT commit your private key (`id_rsa`) to your repository!**

