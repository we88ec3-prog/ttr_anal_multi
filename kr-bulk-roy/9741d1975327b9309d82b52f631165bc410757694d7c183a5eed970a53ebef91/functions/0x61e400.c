
void FUN_0061e400(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_8;
  
  local_8 = 0x44c;
  do {
    iVar1 = 6;
    uVar2 = local_8;
    do {
      if (param_1 == uVar2) {
        FUN_006160b0();
      }
      uVar2 = uVar2 + 100;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    local_8 = local_8 + 1000;
  } while (local_8 < 0x1004);
  if (param_1 == 0x1f42) {
    FUN_0061ea90();
  }
  if (param_1 == 0x1fae) {
    FUN_004129f0();
  }
  return;
}

