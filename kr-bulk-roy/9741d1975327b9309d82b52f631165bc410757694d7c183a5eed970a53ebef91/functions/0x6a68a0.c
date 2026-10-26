
void FUN_006a68a0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0xf0) + 0x20)) {
      FUN_006a6970(in_ECX);
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0xf4) + 0x20)) {
      FUN_006a6f20();
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
      FUN_006a6a60();
      return;
    }
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20)) {
      FUN_006a6ab0(in_ECX);
    }
  }
  else if (iVar1 == 0x709) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xec) + 0x20)) {
      FUN_006a6c80(in_ECX);
      return;
    }
  }
  else if (iVar1 == 0xf43e8) {
    iVar1 = FUN_004068c0();
    iVar2 = FUN_0040afc0();
    if (*(int *)(iVar1 + 0x14) == 0x6a7) {
      uVar4 = *(undefined4 *)(iVar2 + 0x14);
      uVar3 = FUN_0044fd50(uVar4);
      FUN_004ecd10(uVar3,uVar4);
      return;
    }
  }
  return;
}

