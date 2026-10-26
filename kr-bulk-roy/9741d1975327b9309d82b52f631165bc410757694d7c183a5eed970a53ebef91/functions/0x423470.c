
void FUN_00423470(int param_1)

{
  int iVar1;
  int in_ECX;
  
  FUN_005b7f80(param_1);
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0xf439e) {
    FUN_00423600();
  }
  else {
    if (iVar1 == 0xf4404) {
      FUN_006b2f40(*(undefined4 *)(in_ECX + 0x2fc));
      return;
    }
    if (iVar1 == 0xf4441) {
      FUN_004236e0();
      return;
    }
  }
  return;
}

