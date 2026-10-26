
void FUN_00768490(void)

{
  int in_ECX;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  FUN_0082ef00(&local_8);
  if (local_c != *(int *)(in_ECX + 0x50)) {
    *(undefined4 *)(in_ECX + 0x10c) = *(undefined4 *)(local_c + 0x10);
    return;
  }
  *(undefined4 *)(in_ECX + 0x10c) = 0;
  return;
}

