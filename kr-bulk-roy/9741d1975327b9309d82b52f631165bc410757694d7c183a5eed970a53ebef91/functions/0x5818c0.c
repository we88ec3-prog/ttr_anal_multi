
void FUN_005818c0(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int aiStack_48 [2];
  int *piStack_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009337ea;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  aiStack_48[1] = 0x5818fa;
  FUN_00580fe0();
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0();
    aiStack_48[1] = 0x581921;
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_c = 0xffffffff;
  }
  aiStack_48[1] = 0x581936;
  piVar2 = (int *)FUN_0079a5f0();
  aiStack_48[1] = 0xffffffff;
  aiStack_48[0] = 0x58194d;
  iVar3 = (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 8) + 0x38))();
  if (iVar3 != 0) {
    aiStack_48[0] = 0;
    (**(code **)(*piVar2 + 0xac))(piVar2,0,0,1,0,0x3f800000);
    iVar3 = *(int *)(in_ECX + 4);
    aiStack_48[0] = 0x3fc00000;
    aiStack_48[1] = 0x3ff99999;
    (**(code **)(**(int **)(iVar3 + 0x10) + 0x24))
              (0x180,0x200,0,aiStack_48,1,0,
               (((*(byte *)(iVar3 + 0x82) + 0x1fe) / 3 | 0xffffff00) << 8 |
               (*(byte *)(iVar3 + 0x81) + 0x1fe) / 3) << 8 | (*(byte *)(iVar3 + 0x80) + 0x1fe) / 3);
    (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 8) + 0x3c))();
    piVar2 = piStack_24;
  }
  aiStack_48[0] = -1;
  iVar3 = (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0xc) + 0x38))(0xffffffff);
  if (iVar3 != 0) {
    iVar3 = 0;
    (**(code **)(*piVar2 + 0xac))(piVar2,0,0,1,0,0x3f800000);
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
    }
    iVar6 = *(int *)(*(int *)(in_ECX + 4) + 0x18);
    aiStack_48[0] = iVar6;
    FUN_00736180(aiStack_48);
    if ((iVar3 == DAT_00fb7b80) || (DAT_00fb7b90 = iVar6, iVar3 == -0x10)) {
      DAT_00fb7b90 = DAT_00fb7b8c;
    }
    iVar3 = *(int *)(*(int *)(in_ECX + 4) + 0x68);
    iVar4 = *(int *)(iVar3 + 0x28) - *(int *)(iVar3 + 0x24);
    iVar6 = iVar4 >> 0x1f;
    uVar8 = 0;
    if (iVar4 / 0x1c + iVar6 != iVar6) {
      aiStack_48[0] = 0;
      do {
        uVar1 = (*(int *)(iVar3 + 0x28) - *(int *)(iVar3 + 0x24)) / 0x1c;
        iVar4 = 0;
        uVar7 = 0;
        iVar6 = 0;
        while( true ) {
          uVar5 = uVar8;
          if (uVar1 <= uVar8) {
            uVar5 = uVar1;
          }
          if (uVar5 <= uVar7) break;
          if (*(uint *)(iVar6 + 0x10 + *(int *)(iVar3 + 0x24)) < 2) {
            uVar7 = uVar7 + 1;
            iVar4 = iVar4 + 0x20;
            iVar6 = iVar6 + 0x1c;
          }
          else {
            uVar7 = uVar7 + 1;
            iVar4 = iVar4 + 0x40;
            iVar6 = iVar6 + 0x1c;
          }
        }
        iVar3 = *(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x68) + 4);
        if ((DAT_00fb7bc8 & 1) == 0) {
          DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
          FUN_00734ef0();
          _atexit((_func_4879 *)&LAB_00bcd4f0);
        }
        FUN_00735ba0(**(undefined4 **)(*(int *)(in_ECX + 4) + 0x68),iVar3 + iVar4,0,0xff000000,0);
        iVar3 = *(int *)(*(int *)(in_ECX + 4) + 0x68);
        aiStack_48[0] = aiStack_48[0] + 0x1c;
        uVar8 = uVar8 + 1;
      } while (uVar8 < (uint)((*(int *)(iVar3 + 0x28) - *(int *)(iVar3 + 0x24)) / 0x1c));
    }
    (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0xc) + 0x3c))();
  }
  ExceptionList = piStack_24;
  return;
}

