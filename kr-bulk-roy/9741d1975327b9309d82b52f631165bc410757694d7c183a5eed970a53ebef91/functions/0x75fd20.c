
void FUN_0075fd20(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  int local_8;
  
  iVar2 = param_1;
  if (*(int *)(param_1 + 0x10) == 0x76c) {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
    iVar3 = *(int *)(in_ECX + 0xd8);
    param_1 = uVar1;
    FUN_0082ef00(&param_1);
    if (local_8 == *(int *)(iVar3 + 0xbc)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(local_8 + 0x10);
    }
    if (*(int *)(in_ECX + 0xcc) != iVar3) {
      FUN_0040b5b0(uVar1);
      puVar4 = (undefined4 *)FUN_00891268(0x18);
      if (puVar4 != (undefined4 *)0x0) {
        uVar1 = *(undefined4 *)(iVar2 + 0x14);
        puVar4[1] = 0xffffffff;
        puVar4[2] = 0xffffffff;
        puVar4[3] = 0;
        puVar4[4] = 0x76c;
        *puVar4 = FoxUI::FXUIEventI1::vftable;
        puVar4[5] = uVar1;
        FUN_00748900();
        return;
      }
      FUN_00748900();
    }
  }
  return;
}

