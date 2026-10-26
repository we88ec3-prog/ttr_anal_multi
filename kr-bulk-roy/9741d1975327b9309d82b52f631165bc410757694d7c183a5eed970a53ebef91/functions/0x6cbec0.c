
void FUN_006cbec0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0xb;
  FUN_0082ef00(&local_8);
  if (local_c == *(int *)(in_ECX + 0x50)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(local_c + 0x10);
  }
  *(undefined4 *)(in_ECX + 0x80) = uVar2;
  FUN_00671d70();
  iVar1 = *(int *)(*(int *)(in_ECX + 0xec) + 0xcc);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0xe0) = 0;
  }
  return;
}

