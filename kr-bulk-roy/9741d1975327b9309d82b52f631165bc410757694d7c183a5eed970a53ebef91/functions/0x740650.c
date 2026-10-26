
int FUN_00740650(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = 0;
  if (*(int *)(in_ECX + 0x2c) != 0) {
    FUN_00891d3d(*(int *)(in_ECX + 0x2c));
    *(undefined4 *)(in_ECX + 0x2c) = 0;
    *(undefined4 *)(in_ECX + 0x30) = 0;
    iVar1 = *(int *)(in_ECX + 0xc) * *(int *)(in_ECX + 8) * 4;
  }
  return iVar1;
}

