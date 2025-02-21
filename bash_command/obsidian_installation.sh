#!/bin/bash

set -e  # Exit immediately if a command exits with a non-zero status
set -o pipefail  # Prevent errors in pipelines from being masked

INSTALL_DIR="/opt/Obsidian"
BIN_LINK="/usr/local/bin/obsidian"
DESKTOP_ENTRY="$HOME/.local/share/applications/obsidian.desktop"
TEMP_DIR="/tmp/obsidian-installer"

# Ensure required dependencies are installed
echo -e "\e[34m> Checking for required dependencies...\e[0m"
sudo apt update

# Check architecture and install the correct version of libasound2
if dpkg --print-architecture | grep -q "amd64"; then
    sudo apt install -y libnss3 libgtk-3-0 libx11-xcb1 libasound2t64
else
    sudo apt install -y libnss3 libgtk-3-0 libx11-xcb1 libasound2
fi

echo -e "\e[34m> Fetching the latest Obsidian release...\e[0m"
download_url=$(curl -s https://api.github.com/repos/obsidianmd/obsidian-releases/releases/latest |
    grep "browser_download_url.*AppImage" |
    grep -v "arm64" |
    cut -d '"' -f 4)

if [[ -z "$download_url" ]]; then
    echo -e "\e[31mError: Failed to fetch download URL. Exiting.\e[0m"
    exit 1
fi

filename=$(basename "$download_url")
version=$(echo "$filename" | sed -n 's/Obsidian-\(.*\)\.AppImage/\1/p')

echo -e "\e[34m> Downloading '$filename' (version $version) from '$download_url'...\e[0m"
wget -q --show-progress "$download_url" -O "$filename"
echo -e "\e[32m> Download complete.\e[0m"

chmod +x "$filename"
echo -e "\e[34m> Extracting AppImage...\e[0m"
"./$filename" --appimage-extract

if [[ -d "$INSTALL_DIR" ]]; then
    read -p "Error: Directory '$INSTALL_DIR' already exists. Do you want to remove it and reinstall? (y/N): " choice
    case "$choice" in
        y|Y )
            echo "Removing existing installation..."
            sudo rm -rf "$INSTALL_DIR"
            ;;
        * )
            echo "Installation aborted."
            exit 1
            ;;
    esac
fi

echo -e "\e[34m> Moving extracted files to '$INSTALL_DIR'...\e[0m"
sudo mv squashfs-root "$INSTALL_DIR"
sudo chown -R root:root "$INSTALL_DIR"
sudo chmod 4755 "$INSTALL_DIR/chrome-sandbox"
sudo find "$INSTALL_DIR" -type d -exec chmod 755 {} \;

if [[ ! -e "$BIN_LINK" ]]; then
    echo -e "\e[34m> Creating symbolic link at '$BIN_LINK'...\e[0m"
    sudo ln -s "$INSTALL_DIR/AppRun" "$BIN_LINK"
fi

echo -e "\e[34m> Creating desktop entry at '$DESKTOP_ENTRY'...\e[0m"
mkdir -p "$(dirname "$DESKTOP_ENTRY")"
cat << EOF > "$DESKTOP_ENTRY"
[Desktop Entry]
Name=Obsidian
Comment=A powerful knowledge base that works on top of a local folder of plain text Markdown files
Exec=$BIN_LINK
Icon=$INSTALL_DIR/obsidian.png
Terminal=false
Type=Application
Version=$version
Categories=Office;Utility;
MimeType=x-scheme-handler/obsidian;text/html;
EOF

echo -e "\e[32mObsidian $version installed successfully!\e[0m"
echo -e "\e[33mTo launch Obsidian, use:\e[0m"
echo -e "\e[36m  obsidian\e[0m"
echo -e "\e[33mOr find it in your application menu under 'Obsidian'.\e[0m"
