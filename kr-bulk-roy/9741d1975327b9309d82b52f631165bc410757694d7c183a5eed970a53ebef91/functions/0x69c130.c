
void FUN_0069c130(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint local_4c;
  int *local_48;
  int local_3c;
  undefined4 local_38;
  int local_34;
  void *pvStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c88c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffa8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar4 = DAT_00f94300;
  local_c = 0xffffffff;
  uVar2 = *(uint *)(DAT_00f94300 + 0x50d0);
  uVar9 = uVar2 / 0xf + (uint)(uVar2 % 0xf != 0);
  uVar6 = 0;
  *(uint *)(param_1 + 0x148) = uVar9;
  if (uVar2 == 0) {
    *(undefined4 *)(param_1 + 0x144) = 0;
  }
  else if (uVar9 <= *(uint *)(param_1 + 0x144)) {
    *(uint *)(param_1 + 0x144) = uVar9 - 1;
  }
  uVar9 = *(int *)(param_1 + 0x144) * 0xf;
  local_4c = 0;
  if (uVar9 < uVar2) {
    local_48 = (int *)(param_1 + 0xfc);
    do {
      if (0xe < uVar6) goto LAB_0069c381;
      if (uVar9 < *(uint *)(iVar4 + 0x50d0)) {
        uVar6 = uVar9;
        FUN_00542210(uVar9);
        piVar5 = (int *)FUN_0050b4b0(uVar6);
        iVar7 = 0;
        if ((int *)*piVar5 != (int *)0x0) {
          iVar7 = *(int *)*piVar5;
        }
        uVar6 = piVar5[2];
        if (*(uint *)(iVar7 + 8) <= uVar6) {
          uVar6 = uVar6 - *(uint *)(iVar7 + 8);
        }
        iVar7 = *(int *)(*(int *)(iVar7 + 4) + uVar6 * 4);
        uVar6 = local_4c;
        if (iVar7 != 0) {
          if ((DAT_00f8d9a4 & 1) == 0) {
            DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
            local_c = 1;
            FUN_0051c120();
            _atexit((_func_4879 *)&LAB_00bccc90);
            local_c = 0xffffffff;
          }
          local_38 = *(undefined4 *)(iVar7 + 8);
          FUN_008438c0(&local_38);
          if (local_34 == DAT_00f8d91c) {
            iVar8 = 0;
          }
          else {
            iVar8 = *(int *)(local_34 + 0x10);
          }
          iVar3 = *(int *)(iVar7 + 0xc);
          piVar5 = (int *)*local_48;
          bVar1 = *(byte *)(iVar7 + 0x12);
          piVar5[0x9c] = (uint)*(byte *)(iVar7 + 0x11);
          piVar5[0x9d] = iVar3 + 0x93a80;
          *(undefined1 *)((int)piVar5 + 0x269) = 1;
          piVar5[0x9b] = (uint)bVar1;
          (**(code **)(*piVar5 + 0x1ac))
                    (*(undefined4 *)(iVar8 + 0x20),*(undefined4 *)(iVar8 + 0x1c),0,0,
                     *(undefined1 *)(iVar7 + 0x10));
          (**(code **)(*piVar5 + 200))();
          uVar6 = local_4c + 1;
          local_48 = local_48 + 1;
          local_4c = uVar6;
        }
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar2);
  }
  if (uVar6 < 0xf) {
    local_3c = 0xf - uVar6;
    puVar10 = (undefined4 *)(param_1 + 0xfc + uVar6 * 4);
    do {
      piVar5 = (int *)*puVar10;
      (**(code **)(*piVar5 + 0x1ac))(0xffffffff,0xffffffff,0,0,0);
      (**(code **)(*piVar5 + 200))();
      puVar10 = puVar10 + 1;
      local_3c = local_3c + -1;
    } while (local_3c != 0);
  }
LAB_0069c381:
  FUN_007598b0(0);
  FUN_007598b0(1);
  (**(code **)(**(int **)(param_1 + 0x138) + 200))();
  (**(code **)(**(int **)(param_1 + 0x13c) + 0x90))(*(int *)(param_1 + 0x144) != 0);
  (**(code **)(**(int **)(param_1 + 0x140) + 0x90))
            (*(int *)(param_1 + 0x144) + 1U < *(uint *)(param_1 + 0x148));
  ExceptionList = pvStack_1c;
  return;
}

