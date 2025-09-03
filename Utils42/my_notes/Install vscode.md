# Running VS Code from a `.deb` Package in User Space (No `sudo` Required)

This guide explains how to run Visual Studio Code from a downloaded `.deb` package **without root or sudo privileges**, by extracting and launching it from your own space (e.g., `sgoinfre`). Each step is described with its purpose and command.

---

## 1. **Download the `.deb` Package**

Download the official VS Code `.deb` package from [code.visualstudio.com](https://code.visualstudio.com/).

---

## 2. **Extract the Contents of the `.deb` Package**

A `.deb` file is an archive containing the application and metadata.

- **Extract the core files:**
  ```bash
  ar x code_1.103.2-1755709794_amd64.deb
  ```
  This produces files like `data.tar.xz`, `control.tar.xz`, and `debian-binary`.

- **Extract the actual application data:**
  ```bash
  tar -xf data.tar.xz
  ```
  This creates directories such as `usr/share/code/` containing the VS Code binary and dependencies.

---

## 3. **Locate the VS Code Binary**

- The main executable is typically at:
  ```
  usr/share/code/code
  ```
- Other libraries, like `libffmpeg.so`, are also in this directory.

---

## 4. **Create a Wrapper Script to Launch VS Code**

Running the binary directly may fail if its resources aren’t found. A wrapper script ensures VS Code starts with correct resource paths.

- **Create the script in your `~/bin` directory:**
  ```bash
  echo -e '#!/bin/bash\nexec /home/dlesieur/sgoinfre/dlesieur/usr/share/code/code "$@"' > ~/bin/codex
  chmod +x ~/bin/codex
  ```
  - This script calls the VS Code binary with all provided command-line arguments (`"$@"`).
  - Replace the path with your actual extracted location.

---

## 5. **Add `~/bin` to Your PATH (if not already done)**

This lets you run `codex` from any terminal.

- **Add to your shell config:**
  ```bash
  export PATH="$HOME/bin:$PATH"
  ```
- **Reload your shell:**
  ```bash
  source ~/.bashrc
  # or
  source ~/.zshrc
  ```

---

## 6. **Run VS Code**

Now you can launch VS Code by running:
```bash
codex
```
This starts the application using the binary and its resources from your user space.

---

## **Explanation of Each Step**

- **Extracting with `ar` and `tar`:** Unpacks the contents of the `.deb` package so you can access the binary and resources without installing system-wide.
- **Wrapper script:** Ensures all VS Code dependencies are where the binary expects them (solves resource errors).
- **Setting PATH:** Lets you launch VS Code with a simple command.
- **No sudo needed:** Everything runs from your user folder, perfect for environments with restricted permissions.

---

## **Troubleshooting**

- If you see errors about missing libraries (`libffmpeg.so`), make sure they exist in the same directory as the binary or are accessible from the extracted folder.
- Always run the binary from within its original extracted folder if you encounter resource errors (ICU, locales, etc.).
- The wrapper script helps by always launching VS Code from the correct location.

---

**This workflow lets you use the latest VS Code release, even on locked-down systems, without needing admin privileges.**