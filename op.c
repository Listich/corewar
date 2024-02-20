/*
** op.c for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update Tue Mar 22 16:44:20 2011 Astek
*/

#include "op.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

op_t op_tab[] =
  {
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
  };


void init_header(header_t *header)
{
  strcpy(header->prog_name,"Unknown");
  strcpy(header->comment,"Unknown comment");
  header->prog_size = 0;
}

void read_string(int fd, char *name)
{
  int i = 0; 
  read(fd, &name[i], sizeof(char));
  while (name[i] != 0)
  {
    i++;
    read(fd, &name[i], sizeof(char));
  }
}

void skip_zeroes(int fd)
{
  int i = 0;
  char byte = 0;
  while (byte == 0)
  {
    read(fd, &byte, sizeof(char));
  }
  lseek(fd, -1, SEEK_CUR);
}

void read_header(int fd, header_t *header)
{
  init_header(header);
  //le nom du programe
  header->prog_size = lseek(fd, 0, SEEK_END);
  lseek(fd,0, SEEK_SET); //On revient au debut du programme;
  //recupérer le nom
  int magic = 0xf383ea00; // magic mais à l'envers parce que le programme est en big endian (little endian -> big endian, 0x00ea83f3 -> 0xfe83ea00)
  int potentialMagic = 0;
  read(fd,&potentialMagic,sizeof(int));
  //tant que potentialMagic est different de magic en vas lire
  while(potentialMagic != magic) {
    read(fd,&potentialMagic,sizeof(int));
  }
  read_string(fd, header->prog_name);
  //récupérer le commentaire
  skip_zeroes(fd);
  read_string(fd, header->comment);
  printf("[%s]\n [%s]", header->prog_name, header->comment);

}

int is_valide_instructions(char opcode)
{
  for (int i = 0; op_tab[i].mnemonique != 0; i++) {
    if (op_tab[i].code == opcode) {
      return i;
    }
  }
  return -1;
}

int main (int ac, char **av)
{
  header_t header;
  char *programme_name = av[1];
  int fd = open(programme_name, O_RDONLY);
  if (fd == -1) {
    return -1;
  }
  read_header(fd, &header);
  op_t instructions[1024];
  read_instruction(fd, instructions);
  for (int i = 0; instructions[i].mnemonique != NULL; i++) {
    printf("%s\n", instructions[i].mnemonique);
  }
  close(fd);
}
