
void FUN_006505c0(void)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  int local_10;
  undefined4 local_c [2];
  
  local_c[0] = 0xb;
  FUN_0082ef00(local_c);
  if (local_10 == *(int *)(in_ECX + 0x50)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(local_10 + 0x10);
  }
  *(undefined4 *)(in_ECX + 0x80) = uVar1;
  iVar2 = 100;
  do {
    FUN_00615fc0(iVar2);
    FUN_0043c570(iVar2 + 2);
    iVar2 = iVar2 + 100;
  } while (iVar2 < 0x578);
  FUN_0043c570(2000);
  return;
}

