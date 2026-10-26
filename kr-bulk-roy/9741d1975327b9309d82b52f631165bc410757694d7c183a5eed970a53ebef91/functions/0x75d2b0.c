
void FUN_0075d2b0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 in_ECX;
  
  if ((*(int *)(param_1 + 0x10) == 0x5e6) && (*(int *)(param_1 + 8) == 1)) {
    FUN_005f6700(in_ECX);
  }
  iVar2 = *(int *)(param_1 + 0x10);
  if (((iVar2 == 0x709) || (iVar2 == 0x70a)) || (iVar2 == 0x70b)) {
    puVar1 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xffffffff;
      *puVar1 = FoxUI::FXUIEventI1P1::vftable;
      puVar1[5] = 0;
      puVar1[6] = 0;
      goto LAB_0075d334;
    }
  }
  else {
    if (iVar2 != 0x70c) {
      return;
    }
    iVar2 = FUN_00891268(0x1c);
    if (iVar2 != 0) {
      puVar1 = (undefined4 *)FUN_005f62d0();
      goto LAB_0075d334;
    }
  }
  puVar1 = (undefined4 *)0x0;
LAB_0075d334:
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 8);
  puVar1[3] = *(undefined4 *)(param_1 + 0xc);
  puVar1[4] = *(undefined4 *)(param_1 + 0x10);
  puVar1[5] = *(undefined4 *)(param_1 + 0x14);
  puVar1[6] = *(undefined4 *)(param_1 + 0x18);
  FUN_00748900();
  return;
}

