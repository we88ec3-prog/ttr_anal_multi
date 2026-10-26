
void FUN_00442710(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_28 [7];
  undefined1 local_c;
  
  iVar3 = (*param_2 + 8) * 0x20;
  if ((-1 < *(int *)(iVar3 + 8 + param_1)) && (-1 < *(int *)(iVar3 + 0xc + param_1))) {
    puVar4 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar4 != (undefined4 *)0x0) {
      uVar1 = *(undefined4 *)(*param_2 * 0x20 + 0x104 + param_1);
      uVar2 = *(undefined4 *)((*param_2 + 8) * 0x20 + param_1);
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf4369;
      *puVar4 = FoxUI::FXUIEventI2::vftable;
      puVar4[5] = uVar2;
      puVar4[6] = uVar1;
    }
    FUN_004072a0();
    local_28[0] = 0xffffffff;
    local_28[1] = 0xffffffff;
    local_28[2] = 0xffffffff;
    local_28[3] = 0xffffffff;
    local_28[6] = 0xffffffff;
    local_28[4] = 0;
    local_28[5] = 0;
    local_c = 0;
    puVar4 = local_28;
    puVar5 = (undefined4 *)((*param_2 + 8) * 0x20 + param_1);
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  FUN_004429a0();
  return;
}

