# sock.py
# Ori P
# 15.2.23 
# 
# This script is a server-side code that connects to a socket,
# recives CMD commannds, and sends thier output to the client.

# imports
import socket
import subprocess

# constants
PORT        = 2525
IP          = '127.0.0.1'
EXIT        = 'bye' 
MESSEGE     = f'Connected to {IP}. Type "{EXIT}" to exit\n'

def main():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind((IP,PORT))
    sock.listen(1)
    conn, addr = sock.accept()
    with conn:
        conn.send(MESSEGE.encode('utf-8'))
        command = (conn.recv(1024)).decode('utf-8')
        
        # Recivieng commands until user decides to stop
        while(command.strip() != EXIT):
            output = subprocess.run(command, stdout=subprocess.PIPE, shell=True)
            conn.send(output.stdout)
            command = (conn.recv(1024)).decode('utf-8')

    conn.close()
    
if __name__ == "__main__":
    main()
