
void FUN_00656680(int param_1)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  undefined4 *puVar10;
  uint uStack_48;
  undefined4 uStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  void *pvStack_20;
  undefined4 uStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00942e96;
  local_14 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xffffffa8;
  ExceptionList = &local_14;
  *(undefined1 *)(param_1 + 0xa8) = 1;
  (**(code **)(**(int **)(param_1 + 0xac) + 0x94))(1,uVar6);
  (**(code **)(**(int **)(param_1 + 0xb0) + 0x94))(1);
  (**(code **)(**(int **)(param_1 + 0xb4) + 0x94))(0);
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    uStack_18 = 0;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    uStack_18 = 0xffffffff;
  }
  iVar2 = DAT_00fb7258;
  if (DAT_00fb7258 != 0) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      uStack_18 = 1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      uStack_18 = 0xffffffff;
    }
    iVar4 = DAT_00f93930;
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      uStack_18 = 2;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      uStack_18 = 0xffffffff;
    }
    iVar5 = DAT_00fab130;
    uStack_48 = 0;
    uVar6 = 0;
    if (0 < *(int *)(param_1 + 0x138)) {
      puVar10 = (undefined4 *)(param_1 + 0xb8);
      do {
        if ((uVar6 < (uint)(*(int *)(iVar5 + 0x5ebc) - *(int *)(iVar5 + 0x5eb8) >> 3)) &&
           (piVar1 = (int *)(*(int *)(iVar5 + 0x5eb8) + uVar6 * 8), piVar1 != (int *)0x0)) {
          uVar8 = 0;
          uVar7 = *(int *)(iVar2 + 0x2c) - *(int *)(iVar2 + 0x28) >> 2;
          if (uVar7 != 0) {
            piVar9 = *(int **)(iVar2 + 0x28);
            do {
              if ((*(char *)(*piVar9 + 10) != '\0') && (*(int *)*piVar9 == *piVar1)) {
                if (*(int *)(*(int *)(iVar2 + 0x28) + uVar8 * 4) != 0) {
                  if (iVar4 == *piVar1) {
                    uStack_48 = uVar6;
                  }
                  uVar7 = DAT_00fb75b0 & 1;
                  *(uint *)((int)puVar10 + *(int *)(param_1 + 0xb0) + (4 - param_1)) =
                       (uint)*(ushort *)(piVar1 + 1);
                  if (uVar7 == 0) {
                    DAT_00fb75b0 = DAT_00fb75b0 | 1;
                    uStack_18 = 3;
                    FUN_004f3d80();
                    _atexit((_func_4879 *)&LAB_00bcd1e0);
                    uStack_18 = 0xffffffff;
                  }
                  FUN_004f6a30(*piVar1);
                  FUN_00757710();
                  goto LAB_00656950;
                }
                break;
              }
              uVar8 = uVar8 + 1;
              piVar9 = piVar9 + 1;
            } while (uVar8 < uVar7);
          }
        }
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          uStack_18 = 4;
          FUN_00584c40(&DAT_00fe5ac4);
          _atexit((_func_4879 *)&LAB_00bcf390);
          uStack_18 = 0xffffffff;
        }
        uStack_3c = 0x132;
        FUN_005740f0(&uStack_3c);
        if (iStack_38 == DAT_00fe5ac8) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        FUN_00757710();
        *(undefined4 *)(*(int *)(param_1 + 0xb0) + (4 - param_1) + (int)puVar10) = 0;
LAB_00656950:
        (**(code **)(*(int *)*puVar10 + 200))();
        uVar6 = uVar6 + 1;
        puVar10 = puVar10 + 1;
      } while ((int)uVar6 < *(int *)(param_1 + 0x138));
    }
    *(uint *)(*(int *)(param_1 + 0xb0) + 0xcc) = uStack_48;
    iVar2 = *(int *)(param_1 + 0xb0);
    *(undefined1 *)(iVar2 + 0xa8) = 0;
    FUN_00654e70(iVar2);
    if (*(int *)(iVar2 + 0xac + *(int *)(iVar2 + 0xcc) * 4) != 0) {
      FUN_006547e0();
      if (*(int *)(iVar2 + 0xcc) < iStack_30 - iStack_34) {
        *(uint *)(iVar2 + 0xd0) = (uint)*(byte *)(*(int *)(iVar2 + 0xcc) + iStack_34);
      }
      if (iStack_34 != 0) {
        FUN_0089120c(iStack_34);
      }
    }
  }
  ExceptionList = pvStack_20;
  return;
}

