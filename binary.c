/*
** EPITECH PROJECT, 2022
** B-CPE-200-TLS-2-1-corewar-serena.kifoula
** File description:
** binary.c
*/
#include "op.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

char get_arg_type(char type)
{
    switch (type)
    {
    case 0:
        return 0;
        break;
    case 1:
        return T_REG;
        break;
    case 2:
        return T_DIR;
        break;
    case 3:
        return T_IND;
        break;
    default:
        return 0;
        break;
    }

}

int get_type_size(char type)
{
  switch (type)
  {
  case 0:
    return 0;
    break;
  case 1:
    return 1;
    break;
  case 2:
    return 4;
    break;
  case 3:
    return 2;
    break;
  default:
    return 0;
    break;
  }
}

int process_parameters(char opcode, char coding, args_type_t *types)
{
    unsigned char tmp = coding;
    types[0] = get_arg_type(tmp>>6);
    unsigned char p1_size = get_type_size(tmp>>6);
    tmp <<= 2;
    tmp >>= 6;
    types[1] = get_arg_type(tmp);
    unsigned char p2_size = get_type_size(tmp);
    tmp = coding;
    tmp = tmp << 4;
    tmp = tmp >> 6;
    types[2] =  get_arg_type(tmp);
    unsigned char p3_size = get_type_size(tmp);
    if (opcode == 0x0b) {
        return (p1_size +min(p2_size, 2)+ min(p3_size, 2));
    }
    return p1_size + p2_size + p3_size;
}


void read_instruction(int fd,op_t *instructions)
{
    int pose = lseek(fd,0,SEEK_CUR);
    int size = lseek(fd, 0,SEEK_END);
    lseek(fd, pose, SEEK_SET);
    skip_zeroes(fd);
    int current_pose = lseek(fd, 0, SEEK_CUR);
    int i = 0;
    while (current_pose < size)
    {
        char byte = 0;
        read(fd, &byte, sizeof(char));
        int index = is_valide_instructions(byte);
        if (index != -1) {
            instructions[i].mnemonique = op_tab[index].mnemonique;
            i++;
        }
        int gap = 0;
        char coding = 0;
        int parameter = 0;
        switch (byte)
        {
            case 0x01:/*Live*/
            /*read(fd, &parameter, 4);*/
            instructions[i].nbr_args = 1;
            instructions[i].type[0] = T_DIR;
            gap = 4;
            break;
            case 0x09:/*zjump*/
            instructions[i].nbr_args = 1;
            /*pas sur du type*/
            instructions[i].type[0] = T_IND;
            gap = 2;
            break;
            case 0x0c:/*fork*/
            instructions[i].nbr_args = 1;
            instructions[i].type[0] = T_IND;
            gap = 2;
            break;
            case 0x0f:/*lfork*/
            instructions[i].nbr_args = 1;
            instructions[i].type[0] = T_IND;
            gap = 2;
            break;
            case 0x0b:/*sti*/
            instructions[i].nbr_args = 3;
            read(fd, &coding,sizeof(char));
            gap = process_parameters(byte, coding,instructions[i].type);
            break;
            case 0x02:/*ld*/
            instructions[i].nbr_args = 2;
            process_parameters(byte,coding,instructions[i].type);
            gap = 6;
            /* segfault quand en read getparameter_size*/
            break;
            case 0x04:/*add*/
            instructions[i].nbr_args = 3;
            read(fd, &coding,sizeof(char));
            gap =  process_parameters(byte, coding,instructions[i].type);
            break;
            case 0x05:/*sub*/
            instructions[i].nbr_args  = 3;
            read(fd, &coding,sizeof(char));
            gap = process_parameters(byte, coding,instructions[i].type);
            break;
            case 0x10:/*ldi*/
            instructions[i].nbr_args = 3;
            instructions[i].type[0] = T_IND;
            instructions[i].type[1] = T_IND;
            instructions[i].type[2] = T_REG;
            gap = 2;
            break;
            case 0x03:/*st*/
            instructions[i].nbr_args = 2;
            read(fd, &coding,sizeof(char));
            gap = process_parameters(byte, coding,instructions[i].type);
            break;
            default:
            break;
        }
        current_pose = lseek(fd, gap, SEEK_CUR);
    }
  
}

