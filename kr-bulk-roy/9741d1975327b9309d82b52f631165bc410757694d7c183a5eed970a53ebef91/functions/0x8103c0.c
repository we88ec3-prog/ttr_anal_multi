
undefined4 FUN_008103c0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  if (iVar1 != 1) {
    return 0;
  }
  alSourcei(*(undefined4 *)(in_ECX + 0x10),0x202,0);
  alSourcef(*(undefined4 *)(in_ECX + 0x10),0x1021,0x3f800000);
  *(undefined4 *)(in_ECX + 0x2001c) = 1;
  return 1;
}

