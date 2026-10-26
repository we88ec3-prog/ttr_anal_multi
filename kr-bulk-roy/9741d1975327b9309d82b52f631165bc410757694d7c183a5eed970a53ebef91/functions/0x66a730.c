
void FUN_0066a730(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  iVar1 = param_1 + param_2 * 0x18;
  if ((*(int *)(iVar1 + 0x118) != 0) && (*(int *)(iVar1 + 0x11c) != 0)) {
    puVar4 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar4 != (undefined4 *)0x0) {
      uVar2 = *(undefined4 *)(iVar1 + 0x11c);
      uVar3 = *(undefined4 *)(iVar1 + 0x118);
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf4369;
      *puVar4 = FoxUI::FXUIEventI2::vftable;
      puVar4[5] = uVar3;
      puVar4[6] = uVar2;
    }
    FUN_004072a0();
    *(undefined4 *)(iVar1 + 0x118) = 0;
    *(undefined4 *)(iVar1 + 0x11c) = 0;
    *(undefined4 *)(iVar1 + 0x124) = 0;
    *(undefined4 *)(iVar1 + 0x120) = 0;
    *(undefined4 *)(iVar1 + 0x128) = 0;
    *(undefined4 *)(iVar1 + 300) = 0;
    (**(code **)(**(int **)(param_1 + 0x10c + param_2 * 4) + 0x1ac))
              (0xffffffff,0xffffffff,0,0,0xffffffff);
    FUN_0066aca0(param_1,0xffffffff,0xffffffff);
    (**(code **)(**(int **)(param_1 + 0x10c + param_2 * 4) + 200))();
  }
  return;
}

