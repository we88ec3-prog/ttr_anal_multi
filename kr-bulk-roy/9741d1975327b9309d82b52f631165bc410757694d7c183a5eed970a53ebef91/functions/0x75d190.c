
void FUN_0075d190(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *in_ECX;
  
  if (*(int *)(param_1 + 0x10) != 0x641) {
    if (*(int *)(param_1 + 0x10) == 0x640) {
      (**(code **)(*in_ECX + 200))();
    }
    return;
  }
  puVar2 = (undefined4 *)FUN_00891268(0x18);
  if (puVar2 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[3] = 0;
    puVar2[4] = 0x641;
    *puVar2 = FoxUI::FXUIEventI1::vftable;
    puVar2[5] = uVar1;
  }
  FUN_00748900();
  iVar3 = FUN_00408810();
  if (iVar3 != 0) {
    FUN_00405300(in_ECX + 0x3a);
    in_ECX[0x55] = *(int *)(iVar3 + 0x154);
  }
  (**(code **)(*in_ECX + 200))();
  return;
}

