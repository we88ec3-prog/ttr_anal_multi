
void FUN_0067cd90(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_40 [8];
  undefined1 local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  puVar3 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar3 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(in_ECX + 0x124 + param_1 * 0x38);
    uVar2 = *(undefined4 *)(in_ECX + param_1 * 0x38 + 0x120);
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = 0xf4369;
    *puVar3 = FoxUI::FXUIEventI2::vftable;
    puVar3[5] = uVar2;
    puVar3[6] = uVar1;
  }
  FUN_004072a0();
  local_40[0] = 0xffffffff;
  local_40[1] = 0xffffffff;
  local_40[2] = 0xffffffff;
  local_40[3] = 0xffffffff;
  local_40[6] = 0xffffffff;
  local_40[7] = 0xffffffff;
  local_40[4] = 0;
  local_40[5] = 0;
  local_20 = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  puVar3 = local_40;
  puVar5 = (undefined4 *)(in_ECX + 0x120 + param_1 * 0x38);
  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  FUN_0067c470();
  return;
}

