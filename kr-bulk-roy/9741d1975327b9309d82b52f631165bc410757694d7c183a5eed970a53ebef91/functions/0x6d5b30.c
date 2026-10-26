
void FUN_006d5b30(void)

{
  int in_ECX;
  
  if ((((*(int *)(in_ECX + 0x78) != 0) && (*(int *)(in_ECX + 0x34) != 0)) &&
      (*(int *)(in_ECX + 4) != 0)) && (*(int *)(in_ECX + 8) != 0)) {
    (**(code **)(**(int **)(in_ECX + 0x54) + 0x98))(*(int **)(in_ECX + 0x54),0,in_ECX + 0x58);
    (**(code **)(**(int **)(in_ECX + 0x54) + 0xa0))(*(int **)(in_ECX + 0x54),in_ECX + 0x5c);
    (**(code **)(**(int **)(in_ECX + 0x54) + 0xc0))(*(int **)(in_ECX + 0x54),in_ECX + 0x60);
    (**(code **)(**(int **)(in_ECX + 0x54) + 0x94))
              (*(int **)(in_ECX + 0x54),0,*(undefined4 *)(in_ECX + 0x18));
    (**(code **)(**(int **)(in_ECX + 0x54) + 0x9c))
              (*(int **)(in_ECX + 0x54),*(undefined4 *)(in_ECX + 0x10));
    (**(code **)(**(int **)(in_ECX + 0x54) + 0xac))
              (*(int **)(in_ECX + 0x54),0,0,7,0xff2d3232,0x3f800000,0);
  }
  return;
}

