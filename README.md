<div align="center">

# Universe42 🌌

Central hub of my journey at 42 — all milestones, all projects, one universe.

<!-- Badges -->
<a href="https://github.com/LESdylan/Universe42/stargazers">
  <img alt="GitHub stars" src="https://img.shields.io/github/stars/LESdylan/Universe42?style=for-the-badge">
</a>
<a href="https://github.com/LESdylan/Universe42/network/members">
  <img alt="GitHub forks" src="https://img.shields.io/github/forks/LESdylan/Universe42?style=for-the-badge">
</a>
<a href="https://github.com/LESdylan/Universe42">
  <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/LESdylan/Universe42?style=for-the-badge">
</a>
<a href="LICENSE">
  <img alt="License" src="https://img.shields.io/github/license/LESdylan/Universe42?style=for-the-badge">
</a>

<p>
  <a href="#quick-start">Quick Start</a> •
  <a href="#milestones-overview">Milestones</a> •
  <a href="#partial-clone--sparse-checkout">Partial Clone</a> •
  <a href="#submodule-troubleshooting--advanced">Submodules</a> •
  <a href="#contributing">Contributing</a> •
  <a href="#license">License</a>
</p>
</div>

---

## 👀 Disclaimer

All my work and notes are also curated here:
👉🏽 Community Hub: https://puzzled-basil-cc8.notion.site/Universe42-18352b5682188018accae57b55410ea8
👉🏽 ./Utils42/my_notes

> **ℹ️ To view these notes:**  
> Open [Obsidian](https://obsidian.md/) and set `./Utils42/my_notes` as your vault directory.  
> This setup works best on Linux distributions. For Windows, use [WSL](https://learn.microsoft.com/en-us/windows/wsl/) or a Linux VM (e.g., Ubuntu) for full compatibility.  
> Cross-platform use is possible, but may require advanced tweaks.

---

## About the Project

Universe42 gathers all projects developed during my 42 curriculum. Each project lives as a Git submodule, organized by milestone from Milestone 0 to Milestone 6. Browse projects independently, clone everything, or even fetch a single file — your choice.

- Languages and domains: C, algorithms, data structures, Unix, systems programming, networking, graphics, and more.
- Goal: show progression from fundamentals to advanced software engineering.

---

## Project Structure (high level)

- Milestone_0/, Milestone_1/, ..., Milestone_6/
- Utils42/ (e.g., bash_command/)
- docs/
- LICENSE, README.md, .gitmodules

Note: Each project is a submodule. See Quick Start and Submodule sections for proper cloning.

---

## Quick Start

Use this if you want the whole repository with all submodules:

```bash
# Fresh clone with all submodules
git clone --recursive -j$(nproc) https://github.com/LESdylan/Universe42.git
cd Universe42

# If you cloned without --recurse-submodules, run:
git submodule update --init --recursive
```

Keep submodules synced to their tracked branches:

```bash
git submodule update --remote --merge
```

Download a single file without cloning (example):

```bash
# Replace username/repo/path/file as needed
wget https://raw.githubusercontent.com/LESdylan/Universe42/main/Utils42/bash_command/backup.sh -O backup.sh
```

---

## Partial Clone / Sparse Checkout

Clone only what you need (faster, lighter):

```bash
git clone --filter=blob:none --sparse https://github.com/LESdylan/Universe42.git
cd Universe42

# Select only the project(s) you want, e.g., Milestone_0/ft_printf
git sparse-checkout set Milestone_0/ft_printf

# Initialize submodules only for selected paths (depth 1 is optional)
git submodule update --init --recursive --depth 1 Milestone_0/ft_printf
```

Tip: You can add or remove paths with git sparse-checkout set <path...> anytime.

---

## Milestones Overview

- Milestone 0 — Foundations: C basics, memory, file handling, CLI tools, Git.
- Milestone 1 — Algorithms: recursion, sorting/searching, performance basics.
- Milestone 2 — Systems: Unix tools, file descriptors, syscalls, processes.
- Milestone 3 — Design & Concurrency: multithreading, design patterns, advanced algorithms.
- Milestone 4 — Higher-level Topics: ML basics, graphics/game dev, databases.
- Milestone 5 — Scale & Networks: sockets, protocols, distributed systems, performance.
- Milestone 6 — Capstones: full-stack/large-scale projects, team/open-source work.

---

## Submodule Tips (Everyday)

- After pulling new commits in the main repo:

```bash
git submodule update --init --recursive
```

- Bring submodules up to their remote-tracking branches:

```bash
git submodule update --remote --merge
```

---

## Submodule Troubleshooting (Advanced)

<details>
  <summary>Click to expand</summary>

Check submodule status:

```bash
git submodule status
```

See the commit recorded for a submodule:

```bash
git ls-tree HEAD <path_to_submodule>
```

Update a submodule to the latest remote commit (merge into current):

```bash
git submodule update --remote --merge <path_to_submodule>
```

Diff changes inside a submodule:

```bash
git diff --submodule=log <path_to_submodule>
# or within the submodule directory:
cd <path_to_submodule> && git status && git log --oneline -n 5
```

Force init/update (if something got stuck):

```bash
git submodule update --init --force --recursive <path_to_submodule>
```

Reset a submodule to the commit referenced by the superproject:

```bash
cd <path_to_submodule>
git fetch
git checkout <commit_hash>   # the one shown by the superproject
```

Remove a submodule cleanly:

```bash
git submodule deinit -f -- <path_to_submodule>
git rm -f <path_to_submodule>
rm -rf .git/modules/<path_to_submodule>
# Also edit .gitmodules and .git/config if entries remain
```

Note about GitHub submodule display:
GitHub shows submodules as <name> @ <commit-hash> for clarity and reproducibility; this display cannot be customized.

</details>

---

## Contributing

Contributions are welcome!

- Fork the repo and create a feature branch.
- Make changes with clear commit messages.
- Ensure code builds/tests (if applicable).
- Open a Pull Request with a concise description.

---

## License

Distributed under the MIT License. See LICENSE for details.

---

## Acknowledgements

- Project42 for the curriculum and challenges.
- Open-source community for tools, docs, and inspiration.

---

<div align="center">
<strong>Let’s explore the universe of coding together! 🚀🌍</strong>
</div>
## Features
- 🌟 Feature 1
- 🔒 Feature 2
- 🚀 Feature 3

## Features

- 🌟 Easy-to-use
- 📦 Modular
- 💬 Multilingual Support

## Screenshots

![Screenshot](./assets/screenshot.png)

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/username/repo.git
   ```

## License

Distributed under the MIT License. See `LICENSE` for more information.

### 8. **Contributing Guidelines**

- Encourage others to contribute by providing guidelines.

Example:

`````markdown
## Contributing

Contributions are welcome! Please follow the [contribution guidelines](CONTRIBUTING.md).

## Usage

To run the application:

````bash
npm run start

## Installation
1. Clone the repo:
   ```bash
   git clone https://github.com/username/repo.git
````
`````

````

2. Install dependencies:
   ```bash
   npm install
   ```
3. Start the application:

   ```bash
   npm start
   ```

   ## 📚 Documentation

- [Introduction](docs/introduction.md)
- [Setting Up Dual Repositories](docs/setup-dual-repo.md)
- [Contributing Guidelines](docs/contributing.md)
- [Project Structure Guide](docs/project-structure.md)
- [FAQ](docs/faq.md)

## Submodule utilities to debug

Given that submodules can sometimes be tricky to manage, here are some useful Git commands to help you debug and manage submodules effectively:

```bash
git submodule status
## Check what commits are recorded for these submdodules
git ls-tree HEAD <path_to_submodule>
## When submodule is not up to date
git submodule update --remote --merge
## To see the changes in the submodule
git diff <path_to_submodule>
## To force the submodule to a specific commit
git checkout <commit_hash>
## To force the checkout of the submodule
git submodule update --init --force --recursive <path_to_submodule>
## To remove a submodule
git submodule deinit -f -- <path_to_submodule>
## Then remove the submodule entry from .gitmodules and .git/config
git rm -f <path_to_submodule>

```

In GitHub's display of submodules, the naming convention includes both the submodule directory name and the specific commit hash (e.g., libft @ 9c61f8c). Unfortunately, you cannot change this display format directly on GitHub because it's how submodules are intended to work: they are designed to show the exact commit being referenced for clarity and reproducibility.
````
