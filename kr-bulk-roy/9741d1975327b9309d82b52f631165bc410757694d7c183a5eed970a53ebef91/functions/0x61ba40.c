
void FUN_0061ba40(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = 0x13ee;
  do {
    iVar1 = 7;
    iVar2 = local_8;
    do {
      if (param_1 == iVar2) {
        FUN_004129f0();
      }
      iVar2 = iVar2 + 100;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    local_8 = local_8 + 1000;
  } while (local_8 < 0x1fa6);
  if (param_1 == 0xbbb) {
    FUN_0061dff0();
  }
  return;
}

