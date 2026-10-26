
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00581300(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  float fVar5;
  int *piVar6;
  undefined2 in_FPUControlWord;
  int iStack_90;
  int *piStack_8c;
  int *piStack_88;
  undefined4 uStack_84;
  int *piStack_80;
  uint uStack_7c;
  int *piStack_78;
  int iStack_60;
  int *piStack_5c;
  undefined4 *puStack_58;
  uint uStack_54;
  float fStack_50;
  float fStack_4c;
  int *piVar7;
  void *pvStack_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093383a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  fStack_4c = 8.088421e-39;
  FUN_00580fe0();
  fStack_4c = 8.088442e-39;
  FUN_0055ed60();
  fStack_4c = 8.088463e-39;
  FUN_0055ed60();
  fStack_4c = 8.088504e-39;
  iVar2 = FUN_0055ed60();
  if (iVar2 != 0) {
    *(int *)(in_ECX + 0x40) = *(int *)(in_ECX + 0x40) + 1;
    iVar2 = *(int *)(*(int *)(in_ECX + 4) + 0x68);
    if ((uint)((*(int *)(iVar2 + 0x28) - *(int *)(iVar2 + 0x24)) / 0x1c) < *(uint *)(in_ECX + 0x40))
    {
      *(int *)(in_ECX + 0x40) = (*(int *)(iVar2 + 0x28) - *(int *)(iVar2 + 0x24)) / 0x1c;
      *(undefined4 *)(in_ECX + 0x44) = 1;
    }
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0();
    fStack_4c = 8.088667e-39;
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_c = 0xffffffff;
  }
  fStack_4c = 8.088697e-39;
  piVar3 = (int *)FUN_0079a5f0();
  piVar7 = (int *)0xffffffff;
  fStack_4c = -NAN;
  fStack_50 = 8.088736e-39;
  iVar2 = (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 8) + 0x38))();
  if (iVar2 != 0) {
    fStack_50 = 0.0;
    uStack_54 = 0x3f800000;
    puStack_58 = (undefined4 *)0x0;
    piStack_5c = (int *)0x1;
    iStack_60 = 0;
    (**(code **)(*piVar3 + 0xac))();
    piVar7 = *(int **)(in_ECX + 0x28);
    fStack_50 = ((float)piVar7 * 0.125 + 1.0) * 1.5;
    fStack_4c = ((float)piVar7 * 0.125 + 1.0) * 1.3 * 1.5;
    uStack_7c = 0x581492;
    piStack_78 = piVar3;
    (**(code **)(*piVar3 + 0x114))();
    uVar1 = *(uint *)(*(int *)(in_ECX + 4) + 0x80);
    puStack_58 = (undefined4 *)(((uVar1 >> 8 & 0xff) + 0x1fe) / 3);
    uStack_54 = (uint)ROUND((1.0 - *(float *)(in_ECX + 0x28)) * 255.0);
    uStack_7c = (((uStack_54 & 0xff) << 8 | ((uVar1 >> 0x10 & 0xff) + 0x1fe) / 3) << 8 |
                (uint)puStack_58) << 8 | ((uVar1 & 0xff) + 0x1fe) / 3;
    piStack_80 = (int *)0x0;
    uStack_84 = 1;
    piStack_88 = &iStack_60;
    piStack_8c = (int *)0x0;
    iStack_90 = 0x200;
    (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0x10) + 0x24))(0x180);
    (**(code **)(_DAT_00000000 + 0x28))(0);
    piStack_88 = (int *)CONCAT22(piStack_88._2_2_,in_FPUControlWord);
    uVar4 = FUN_00580f20((int)ROUND(*(float *)(in_ECX + 0x28) * 255.0) & 0xff);
    (**(code **)(*piVar3 + 0x114))(piVar3,0,8,*(undefined4 *)(in_ECX + 0x18));
    (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0x10) + 0x24))
              (0x180,0x200,0,&iStack_90,1,0,uVar4);
    (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 8) + 0x3c))();
  }
  fStack_50 = -NAN;
  uStack_54 = 0xffffffff;
  puStack_58 = (undefined4 *)0x58160d;
  iVar2 = (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0xc) + 0x38))();
  if (iVar2 != 0) {
    puStack_58 = (undefined4 *)0x0;
    piStack_5c = (int *)0x3f800000;
    iStack_60 = 0;
    (**(code **)(*piVar3 + 0xac))();
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      FUN_00734ef0();
      piStack_78 = (int *)0x581656;
      _atexit((_func_4879 *)&LAB_00bcd4f0);
    }
    iVar2 = *(int *)(*(int *)(in_ECX + 4) + 0x18);
    piStack_78 = (int *)0x58167e;
    fStack_4c = (float)iVar2;
    FUN_00736180();
    if ((fStack_50 == (float)DAT_00fb7b80) || (DAT_00fb7b90 = iVar2, fStack_50 == -NAN)) {
      DAT_00fb7b90 = DAT_00fb7b8c;
    }
    fStack_50 = 0.0;
    piVar6 = (int *)0x80;
    if (*(int *)(in_ECX + 0x40) != 0) {
      fStack_4c = 0.0;
      do {
        iVar2 = *(int *)(*(int *)(in_ECX + 4) + 0x68);
        iStack_60 = 0;
        piStack_5c = (int *)0x0;
        uVar1 = (*(int *)(iVar2 + 0x28) - *(int *)(iVar2 + 0x24)) / 0x1c;
        puStack_58 = (undefined4 *)0x0;
        while( true ) {
          fVar5 = fStack_50;
          if (uVar1 <= (uint)fStack_50) {
            fVar5 = (float)uVar1;
          }
          if ((uint)fVar5 <= piStack_5c) break;
          if (*(uint *)(*(int *)(iVar2 + 0x24) + 0x10 + (int)puStack_58) < 2) {
            iStack_60 = iStack_60 + 0x20;
            piStack_5c = (int *)((int)piStack_5c + 1);
            puStack_58 = (undefined4 *)((int)puStack_58 + 0x1c);
          }
          else {
            iStack_60 = iStack_60 + 0x40;
            piStack_5c = (int *)((int)piStack_5c + 1);
            puStack_58 = (undefined4 *)((int)puStack_58 + 0x1c);
          }
        }
        iVar2 = *(int *)(*(int *)(in_ECX + 4) + 0x68);
        piVar6 = (int *)(*(int *)(iVar2 + 4) + iStack_60);
        puStack_58 = (undefined4 *)(*(int *)(iVar2 + 0x24) + (int)fStack_4c);
        if (7 < (uint)puStack_58[5]) {
          puStack_58 = (undefined4 *)*puStack_58;
        }
        piStack_5c = piVar6;
        if ((DAT_00fb7bc8 & 1) == 0) {
          DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
          FUN_00734ef0();
          piStack_78 = (int *)0x581779;
          _atexit((_func_4879 *)&LAB_00bcd4f0);
        }
        uStack_84 = **(undefined4 **)(*(int *)(in_ECX + 4) + 0x68);
        piStack_78 = (int *)0xff000000;
        uStack_7c = 0;
        piStack_88 = (int *)0x5817a5;
        piStack_80 = piVar6;
        FUN_00735ba0();
        fStack_4c = (float)((int)fStack_4c + 0x1c);
        fStack_50 = (float)((int)fStack_50 + 1);
        piVar6 = piStack_5c;
      } while ((uint)fStack_50 < *(uint *)(in_ECX + 0x40));
    }
    piStack_78 = (int *)0x5817cc;
    (**(code **)(*piVar7 + 0x28))();
    if (*(int *)(in_ECX + 0x44) == 0) {
      piStack_78 = (int *)0x3;
      uStack_7c = 0xd1;
      uStack_84 = 0x5817e4;
      piStack_80 = piVar3;
      (**(code **)(*piVar3 + 0xe4))();
      iStack_90 = (int)*(float *)(in_ECX + 0x38);
      uStack_84 = 0xffffffff;
      piStack_88 = (int *)0x0;
      piStack_8c = piVar6;
      (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0x14) + 0x20))();
      (**(code **)(_DAT_00000000 + 0x28))(0);
      (**(code **)(*piVar3 + 0xe4))(piVar3,0xd1,1);
    }
    piStack_78 = (int *)0x581827;
    (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0xc) + 0x3c))();
  }
  ExceptionList = pvStack_24;
  return;
}

