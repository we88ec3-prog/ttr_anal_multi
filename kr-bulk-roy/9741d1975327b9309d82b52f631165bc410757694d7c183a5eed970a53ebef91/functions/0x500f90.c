
int FUN_00500f90(void)

{
  int iVar1;
  int in_ECX;
  int local_c;
  undefined1 local_8 [4];
  
  iVar1 = *(int *)(in_ECX + 0x5eac);
  FUN_00503d20(local_8);
  if (local_c != *(int *)(iVar1 + 4)) {
    return local_c + 0x10;
  }
  return 0;
}

