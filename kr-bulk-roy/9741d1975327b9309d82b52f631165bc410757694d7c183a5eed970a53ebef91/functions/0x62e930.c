
void FUN_0062e930(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0x70c) {
    if (uVar1 == 0x70b) {
      iVar2 = *(int *)(*(int *)(in_ECX + 0x110) + 0xcc);
      if (iVar2 == 0) {
        FUN_0062f3c0();
        return;
      }
      if (*(int *)(iVar2 + 0xdc) == 0) {
        FUN_0062f3c0();
        return;
      }
      FUN_0062f3c0();
      return;
    }
    if (uVar1 == 900) {
      puVar3 = (undefined4 *)FUN_00891268(0x14);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = FoxUI::FXUIEvent::vftable;
        puVar3[1] = 0xffffffff;
        puVar3[2] = 0xffffffff;
        puVar3[3] = 0;
        puVar3[4] = 0xf43b0;
        FUN_004072a0();
        return;
      }
      FUN_004072a0();
      return;
    }
    if (uVar1 == 0x387) {
      FUN_006304b0();
      return;
    }
    if (uVar1 == 0x578) {
      FUN_0062eb70();
      return;
    }
  }
  else if (uVar1 == 0xf438d) {
    FUN_0062ec20(in_ECX);
  }
  else if ((uVar1 == 0xf438e) && (*(int *)(param_1 + 0x14) == 0x6a7)) {
    FUN_006306a0();
    return;
  }
  return;
}

