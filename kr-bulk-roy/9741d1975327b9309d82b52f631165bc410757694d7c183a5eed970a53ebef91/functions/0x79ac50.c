
void FUN_0079ac50(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00932572;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  local_18 = DAT_00fb76a8;
  local_14 = (int *)0x0;
  iVar4 = FUN_00714550("Panel/PanelMesh.gb3");
  if (iVar4 == 0) {
    iVar4 = FUN_007cc280(*param_1,&local_14);
  }
  else {
    iVar4 = FUN_007cc0a0();
  }
  piVar5 = local_14;
  if (iVar4 != 0) {
    FUN_0084d9e0(local_14);
    local_24 = FUN_00891268(0xc0);
    local_8 = 1;
    if (local_24 == 0) {
      local_14 = (int *)0x0;
    }
    else {
      local_14 = (int *)FUN_00845c60(local_24);
    }
    piVar3 = local_14;
    local_8 = 0xffffffff;
    puVar2 = (undefined4 *)local_14[0x1e];
    if (puVar2 != (undefined4 *)0x0) {
      piVar6 = puVar2 + 1;
      *piVar6 = *piVar6 + -1;
      if (*piVar6 == 0) {
        (**(code **)*puVar2)(1);
      }
    }
    piVar3[0x1e] = (int)piVar5;
    if (piVar5 != (int *)0x0) {
      iVar4 = (**(code **)(*piVar5 + 8))();
      if (iVar4 == 0) {
        iVar4 = (**(code **)(*(int *)piVar3[0x1e] + 0xc))();
        piVar3[0x1e] = iVar4;
      }
      *(int *)(piVar3[0x1e] + 4) = *(int *)(piVar3[0x1e] + 4) + 1;
    }
    piVar3[0x2e] = 0;
    local_24 = FUN_00891268(0x1d0);
    local_8 = 2;
    if (local_24 == 0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_00854c30(local_24);
    }
    local_8 = 0xffffffff;
    local_1c = 0x3f800000;
    local_20 = 0x3f800000;
    local_24 = 0x3f800000;
    FUN_008551d0();
    local_24 = 0x3f800000;
    local_20 = 0x3f800000;
    local_1c = 0x3f800000;
    FUN_00855110();
    local_24 = 0x3f800000;
    local_20 = 0x3f800000;
    local_1c = 0x3f800000;
    FUN_00855050();
    piVar5[0x73] = 0x3f800000;
    (**(code **)(*local_18 + 0xa0))(&local_28,"panel");
    piVar5[0x59] = local_28;
    local_24 = FUN_00891268(0xbc);
    local_8 = 3;
    if (local_24 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_00856910();
    }
    local_8 = 0xffffffff;
    *(undefined4 *)(iVar4 + 0xb8) = 0;
    FUN_00843fa0(piVar5,1);
    piVar6 = (int *)(**(code **)(*piVar5 + 0xc))();
    piVar3 = local_14;
    puVar2 = (undefined4 *)local_14[0x1d];
    if (puVar2 != (undefined4 *)0x0) {
      piVar1 = puVar2 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)*puVar2)(1);
      }
    }
    piVar3[0x1d] = (int)piVar6;
    if (piVar6 != (int *)0x0) {
      iVar4 = (**(code **)(*piVar6 + 8))();
      if (iVar4 == 0) {
        iVar4 = (**(code **)(*(int *)piVar3[0x1d] + 0xc))();
        piVar3[0x1d] = iVar4;
      }
      *(int *)(piVar3[0x1d] + 4) = *(int *)(piVar3[0x1d] + 4) + 1;
    }
    (**(code **)*piVar5)(1);
    local_24 = FUN_00891268(0xe8);
    local_8 = 4;
    if (local_24 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = FUN_0077ebb0();
    }
    param_1[3] = uVar7;
    piVar3[1] = piVar3[1] + 1;
    local_8 = 5;
    FUN_0077f8f0();
    local_8 = 0xffffffff;
    if (piVar3 != (int *)0x0) {
      piVar5 = piVar3 + 1;
      *piVar5 = *piVar5 + -1;
      if (*piVar5 == 0) {
        (**(code **)*piVar3)(1);
      }
    }
    (**(code **)(*(int *)param_1[3] + 0x58))(local_18);
    ExceptionList = local_10;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_006edc70(&DAT_00c4f38c);
}

