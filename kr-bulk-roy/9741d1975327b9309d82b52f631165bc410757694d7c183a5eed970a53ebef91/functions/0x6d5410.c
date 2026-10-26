
void FUN_006d5410(void)

{
  int in_ECX;
  
  if ((((*(int *)(in_ECX + 0x74) != 0) && (*(int *)(in_ECX + 0x34) != 0)) &&
      (*(int *)(in_ECX + 4) != 0)) && (*(int *)(in_ECX + 8) != 0)) {
    (**(code **)(**(int **)(in_ECX + 0x50) + 0x98))(*(int **)(in_ECX + 0x50),0,in_ECX + 0x54);
    (**(code **)(**(int **)(in_ECX + 0x50) + 0xa0))(*(int **)(in_ECX + 0x50),in_ECX + 0x58);
    (**(code **)(**(int **)(in_ECX + 0x50) + 0xc0))(*(int **)(in_ECX + 0x50),in_ECX + 0x5c);
    (**(code **)(**(int **)(in_ECX + 0x50) + 0x94))
              (*(int **)(in_ECX + 0x50),0,*(undefined4 *)(in_ECX + 0x18));
    (**(code **)(**(int **)(in_ECX + 0x50) + 0x9c))
              (*(int **)(in_ECX + 0x50),*(undefined4 *)(in_ECX + 0x10));
    (**(code **)(**(int **)(in_ECX + 0x50) + 0xac))
              (*(int **)(in_ECX + 0x50),0,0,7,0xff2d3232,0x3f800000,0);
  }
  return;
}

