
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056f130(int param_1)

{
  uint *puVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int unaff_EBX;
  int *piVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int *piVar11;
  uint uStack_6c;
  float local_58;
  float fStack_54;
  float fStack_50;
  uint uStack_4c;
  int iStack_48;
  int iStack_44;
  float fStack_40;
  float fStack_3c;
  undefined4 uStack_38;
  float fStack_2c;
  float fStack_28;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009362a8;
  local_14 = ExceptionList;
  uStack_6c = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
  local_58 = 0.0;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  if (DAT_00fab134 != 0) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 1;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    if ((*(char *)(DAT_00fab134 + 0x36) == '\x05') ||
       (local_58 = 0.0, *(char *)(DAT_00fab134 + 0x36) == '\0')) {
      local_58 = 1.4013e-45;
    }
    _DAT_00d6a24c = 1.0;
  }
  local_c = 0xffffffff;
  if ((*(int *)(param_1 + 0x1c) != 0) && (*(int *)(param_1 + 0x3c) != 0)) {
    piVar7 = *(int **)(param_1 + 0x1c);
    iVar4 = **(int **)(param_1 + 0x60);
    uVar3 = (**(code **)(*piVar7 + 0x18))();
    uVar3 = (**(code **)(*piVar7 + 0x14))(uVar3);
    iVar4 = (**(code **)(iVar4 + 0x38))(uVar3);
    if (iVar4 != 0) {
      if ((local_58 == 0.0) &&
         (*(undefined4 *)(param_1 + 0x6c) = 0, *(float *)(param_1 + 100) == 1024.0)) {
        _DAT_00d6a24c = 1.2;
        fStack_50 = (float)(**(code **)(**(int **)(param_1 + 0x1c) + 0x18))();
        iVar4 = FUN_008fed10();
        iVar5 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x18))();
        *(int *)(param_1 + 0x6c) = (iVar4 - iVar5) / 2;
      }
      iVar5 = -1;
      fStack_50 = _DAT_00d6a24c * _DAT_00e4f89c;
      fStack_54 = _DAT_00d6a24c * _DAT_00e4f8a0;
      fStack_2c = fStack_50;
      fStack_28 = fStack_54;
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x24))
                (*(undefined4 *)(param_1 + 0x6c),*(undefined4 *)(param_1 + 0x6c),0,&fStack_2c,0,0);
      iVar4 = FUN_0043ffa0();
      uVar3 = *(undefined4 *)(param_1 + 0x70);
      fStack_54 = *(float *)(iVar4 + 0x20);
      FUN_0043ffa0(fStack_54,uVar3);
      FUN_007358b0(uVar3);
      FUN_0056fb40();
      piVar7 = *(int **)(param_1 + 0x54);
      if (piVar7 != (int *)*piVar7) {
        do {
          puVar1 = *(uint **)(piVar7[1] + 8);
          fStack_50 = (float)puVar1[4];
          uStack_4c = puVar1[5];
          uStack_6c = *puVar1;
          piVar11 = piVar7;
          FUN_005704f0(&uStack_6c);
          if ((iVar5 == *(int *)(param_1 + 0x48)) ||
             (FUN_008438c0(&stack0xffffff9c), unaff_EBX == *(int *)(iVar5 + 0x34))) {
            uStack_6c = 0;
          }
          else {
            uStack_6c = *(uint *)(unaff_EBX + 0x10);
          }
          iVar4 = FUN_0056fd60(*puVar1);
          if (iVar4 != 0) {
            FUN_004fc620();
          }
          if ((char)puVar1[3] != '\0') {
            FUN_0056f7a0(fStack_50,uStack_4c);
            iStack_48 = iStack_48 + *(int *)(param_1 + 0x6c);
            iStack_44 = iStack_44 + *(int *)(param_1 + 0x6c);
            local_58 = (float)iStack_48;
            fStack_3c = (float)iStack_44;
            uStack_38 = 0;
            fStack_40 = local_58;
            FUN_00739230(local_58,fStack_3c,0,(float)puVar1[6] - *(float *)(param_1 + 0x68),
                         uStack_6c,(int)(float)puVar1[0x11],0x3f800000,0x3f800000,0x3f800000,
                         0x3f800000);
            piVar7 = piVar11;
            if ((DAT_00fb7bc8 & 1) == 0) {
              DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
              fStack_28 = 2.8026e-45;
              FUN_00734ef0();
              _atexit((_func_4879 *)&LAB_00bcd4f0);
              fStack_28 = -NAN;
              piVar7 = piVar11;
            }
            uVar10 = 0xff000000;
            uVar9 = 0xffffffff;
            uVar8 = 0x100;
            uVar3 = FUN_008fed10(0x100,0xffffffff,0xff000000);
            uVar6 = FUN_008fed10(uVar3);
            FUN_00735ba0(uVar6,uVar3,uVar8,uVar9,uVar10);
          }
          piVar7 = (int *)piVar7[1];
        } while (piVar7 != (int *)**(undefined4 **)(param_1 + 0x54));
      }
      if ((DAT_00fb7bc8 & 1) == 0) {
        DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
        fStack_28 = 4.2039e-45;
        FUN_00734ef0();
        _atexit((_func_4879 *)&LAB_00bcd4f0);
        fStack_28 = -NAN;
      }
      fVar2 = fStack_54;
      FUN_00736180(&fStack_54);
      if ((local_58 == DAT_00fb7b80) || (local_58 == -NAN)) {
        DAT_00fb7b90 = DAT_00fb7b8c;
      }
      else {
        DAT_00fb7b90 = fVar2;
      }
      (**(code **)(**(int **)(param_1 + 0x60) + 0x3c))();
    }
  }
  ExceptionList = local_14;
  return;
}

