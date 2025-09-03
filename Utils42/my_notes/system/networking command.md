Networking is the **lifeblood** of any Linux system. Whether you're troubleshooting, monitoring, or securing your connection, these **must-know** commands will turn you into a **networking pro!** ⚡🖥️

---

## **📡 Checking Network Connectivity**

|Command|What It Does|
|---|---|
|`ping <host>`|Check if a host is reachable (`ping google.com`).|
|`traceroute <host>`|Show the **path** packets take to a host (`traceroute google.com`).|
|`whois <domain>`|Get domain information (`whois example.com`).|
|`dig <domain>`|Perform **DNS lookups** (`dig google.com`).|
|`nslookup <domain>`|Another way to check DNS records (`nslookup google.com`).|
|`arping <IP>`|Check if an **IP address** is reachable on the local network.|

🔹 **Example:**

```bash
ping -c 4 google.com   # Send 4 packets instead of infinite
traceroute -I google.com  # Use ICMP instead of UDP
dig +short google.com  # Get only the IP address
```

---

## **📊 Monitoring Network Activity**

|Command|What It Does|
|---|---|
|`netstat -tulnp`|Show open ports and listening services.|
|`ss -tulnp`|Modern `netstat` alternative (`ss` is faster).|
|`bmon`|**Real-time** bandwidth monitoring (`bmon` must be installed).|
|`w`|Show logged-in users and their **network activity**.|
|`who`|Show who is **logged into the system**.|

🔹 **Example:**

```bash
netstat -tulnp  # List open ports and services
ss -tanp | grep LISTEN  # Find only listening ports
```

---

## **🛠️ Managing IP Addresses & Interfaces**

|Command|What It Does|
|---|---|
|`ip a`|Show all network interfaces (`ip addr show`).|
|`ip r`|Display **routing table** (`ip route show`).|
|`ip link set <interface> up/down`|Enable or disable an interface.|
|`ifconfig`|Deprecated, but still used for IP management.|

🔹 **Example:**

```bash
ip addr show eth0  # Show details of eth0
ip link set eth0 up  # Enable eth0
ip link set eth0 down  # Disable eth0
```

---

## **🌍 Downloading Files via Network**

|Command|What It Does|
|---|---|
|`curl -O <url>`|Download a file (`curl -O <https://example.com/file.txt`>).|
|`wget <url>`|Another way to download files (`wget <https://example.com/file.txt`>).|
|`ftp <server>`|Connect to an **FTP server**.|

🔹 **Example:**

```bash
wget -c <https://example.com/largefile.iso>  # Resume download
curl -I <https://google.com>  # Fetch only headers
```

---

## **🔐 Securing the Network (Firewall & SSH)**

|Command|What It Does|
|---|---|
|`iptables -L -v`|List firewall rules.|
|`ufw enable/disable`|Enable or disable **UFW firewall**.|
|`ufw allow <port>`|Allow traffic on a port (`ufw allow 22/tcp`).|
|`firewalld --state`|Check if **firewalld** is running.|
|`fail2ban-client status`|Check **Fail2Ban** (protects against brute force attacks).|

🔹 **Example:**

```bash
ufw allow 80/tcp  # Allow HTTP traffic
iptables -A INPUT -p tcp --dport 22 -j ACCEPT  # Allow SSH
fail2ban-client status sshd  # Check SSH bans
```

---

## **🔑 SSH Key Management**

|Command|What It Does|
|---|---|
|`ssh-keygen -t rsa -b 4096`|Generate a **new SSH key**.|
|`ssh-copy-id user@host`|Copy **SSH key** to a remote server.|

🔹 **Example:**

```bash
ssh-keygen -t ed25519 -C "my_email@example.com"  # Generate key
ssh-copy-id -i ~/.ssh/id_rsa.pub user@server  # Copy key to server
```

---

## **📡 Advanced Network Scanning & Security**

|Command|What It Does|
|---|---|
|`nmap -sS <IP>`|Perform a **stealth scan** on an IP.|
|`nmap -A <IP>`|Get OS and service versions.|

🔹 **Example:**

```bash
nmap -p 1-65535 -T4 -A -v target.com  # Full scan
nmap -sP 192.168.1.0/24  # Ping scan a subnet
```

---

## **👀 Final Thoughts**

These commands give you **full control** over networking on Linux. Whether you're testing **connectivity, monitoring traffic, configuring firewalls, or securing SSH**, you now have the **ultimate toolbox**. 🚀

💻 **Happy networking, and may your pings always return!** 🎯