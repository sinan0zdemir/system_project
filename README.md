# Soccer World Cup Data System

A C program for processing and querying FIFA World Cup data (1954-2014).

## Project Structure
- **src:** Contains the source code files.
  - `main.c`: Main program file.
  - `match.c`: Reads matches from csv and contains various query methods.
  - `squads.c`: Reads squads from csv and contains various query methods.
  - `goals.c`: Reads goals from csv and contains various query methods.

- **datasets:** Includes World Cup squads, matches, and goals datasets.

## Getting Started
1. Clone the repository.
   ```bash
   git clone https://github.com/berkayozcann/soccerworldcup_data_system.git
   cd soccerworldcup_data_system

2.Use makefile to build the project.

3.Run the executable.

## Usage
- The program provides a text-based menu for various functionalities related to World Cup data.
- Follow the on-screen instructions to perform data processing and queries.

## Contributing
If you'd like to contribute to this project, please follow these steps:
1. Fork the repository.
2. Create a new branch (`git checkout -b initial-setup`).
3. Commit your changes (`git commit -m 'Add initial setup'`).
4. Push to the branch (`git push origin initial-setup`).
5. Create a new pull request.

## License
This project is licensed under the [MIT License](LICENSE).

## Acknowledgments

Dataset sources: FIFA World Cup Archive and https://github.com/tugraz-isds/datasets/blob/master/soccer_world_cup_1954_2014
