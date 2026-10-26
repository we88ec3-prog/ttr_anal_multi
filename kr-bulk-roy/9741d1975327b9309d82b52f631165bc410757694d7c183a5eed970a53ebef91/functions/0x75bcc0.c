
void FUN_0075bcc0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int local_c;
  int local_8;
  
  local_8 = 0;
  FUN_0082ef00(&local_8);
  iVar1 = *(int *)(in_ECX + 0x50);
  if (local_c == iVar1) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(local_c + 0x10);
  }
  *(undefined4 *)(in_ECX + 200) = uVar2;
  local_c = 1;
  FUN_0082ef00(&local_c);
  if (local_8 != iVar1) {
    *(undefined4 *)(in_ECX + 0xcc) = *(undefined4 *)(local_8 + 0x10);
    return;
  }
  *(undefined4 *)(in_ECX + 0xcc) = 0;
  return;
}

