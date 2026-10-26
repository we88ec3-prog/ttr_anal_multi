
void FUN_0041e640(void)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0xb;
  FUN_0082ef00(&local_8);
  if (local_c == *(int *)(in_ECX + 0x50)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(local_c + 0x10);
  }
  *(undefined4 *)(in_ECX + 0x80) = uVar1;
  iVar2 = 10000;
  do {
    FUN_00615fc0(iVar2);
    iVar2 = iVar2 + 10000;
  } while (iVar2 < 80000);
  return;
}

