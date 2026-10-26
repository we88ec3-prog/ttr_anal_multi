
void FUN_00654980(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 *in_ECX;
  int *piVar3;
  int iVar4;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009162a8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CMissionLadderCanvas::vftable;
  piVar3 = in_ECX + 0x2b;
  local_14 = 4;
  do {
    iVar4 = *piVar3;
    if (iVar4 != 0) {
      FUN_00654430(uVar2);
      FUN_0089120c(iVar4);
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
    local_14 = local_14 + -1;
  } while (local_14 != 0);
  piVar3 = (int *)in_ECX[0x3a];
  if (piVar3 != (int *)0x0) {
    piVar1 = (int *)in_ECX[0x3b];
    for (; piVar3 != piVar1; piVar3 = piVar3 + 4) {
      if (*piVar3 != 0) {
        FUN_0089120c(*piVar3);
      }
      *piVar3 = 0;
      piVar3[1] = 0;
      piVar3[2] = 0;
    }
    FUN_0089120c(in_ECX[0x3a]);
  }
  in_ECX[0x3a] = 0;
  in_ECX[0x3b] = 0;
  in_ECX[0x3c] = 0;
  piVar3 = (int *)in_ECX[0x36];
  if (piVar3 != (int *)0x0) {
    piVar1 = (int *)in_ECX[0x37];
    for (; piVar3 != piVar1; piVar3 = piVar3 + 4) {
      if (*piVar3 != 0) {
        FUN_0089120c(*piVar3);
      }
      *piVar3 = 0;
      piVar3[1] = 0;
      piVar3[2] = 0;
    }
    FUN_0089120c(in_ECX[0x36]);
  }
  in_ECX[0x36] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x38] = 0;
  *in_ECX = FoxUI::FXUIControl::vftable;
  local_8 = 0;
  piVar3 = in_ECX + 0x25;
  iVar4 = 4;
  do {
    if ((int *)*piVar3 != (int *)0x0) {
      (**(code **)(*(int *)*piVar3 + 0x1c))(1);
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIRDTarget::vftable;
  FUN_00745380();
  ExceptionList = local_10;
  return;
}

