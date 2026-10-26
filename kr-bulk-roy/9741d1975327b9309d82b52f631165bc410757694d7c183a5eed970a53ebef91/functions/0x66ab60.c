
void FUN_0066ab60(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if (param_2 < 3) {
    iVar1 = param_1 + param_2 * 0x18;
    if ((*(int *)(param_1 + 0x118 + param_2 * 0x18) != 0) && (*(int *)(iVar1 + 0x11c) != 0)) {
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
    }
    puVar4 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf4368;
      *puVar4 = FoxUI::FXUIEventI2::vftable;
      puVar4[5] = param_3;
      puVar4[6] = param_4;
    }
    FUN_004072a0();
    *(undefined4 *)(iVar1 + 0x11c) = param_4;
    *(undefined4 *)(iVar1 + 0x118) = param_3;
    *(undefined4 *)(iVar1 + 0x124) = param_9;
    *(undefined4 *)(iVar1 + 0x120) = param_5;
    *(undefined4 *)(iVar1 + 300) = param_8;
    *(undefined4 *)(iVar1 + 0x128) = param_7;
    (**(code **)(**(int **)(param_1 + 0x10c + param_2 * 4) + 0x1ac))
              (param_6,param_5,param_7,param_8,param_9);
    FUN_0066aca0(param_1,param_5,param_7);
    (**(code **)(**(int **)(param_1 + 0x10c + param_2 * 4) + 200))();
  }
  return;
}

