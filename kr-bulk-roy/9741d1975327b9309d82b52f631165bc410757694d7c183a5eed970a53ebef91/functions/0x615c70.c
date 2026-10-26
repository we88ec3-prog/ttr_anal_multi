
void FUN_00615c70(int param_1,undefined4 param_2,uint param_3,int param_4,int param_5)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  int unaff_EBX;
  int iStack_2c;
  uint uStack_28;
  char *local_24 [2];
  void *pvStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093e16c;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  local_24[0] = (char *)(param_3 & 0xff);
  *(char *)(param_1 + 0x188) = (char)param_2;
  cVar5 = (char)param_3;
  *(char *)(param_1 + 0x189) = cVar5;
  uStack_28 = (uint)(uint3)uStack_28;
  (**(code **)(**(int **)(param_1 + 0xfc + (int)local_24[0] * 4) + 0x19c))(param_2,param_3,uVar2);
  if ((DAT_00fab278 & 1) == 0) {
    DAT_00fab278 = DAT_00fab278 | 1;
    local_14 = (void *)0x0;
    FUN_00817da0();
    _atexit((_func_4879 *)&LAB_00bcced0);
    local_14 = (void *)0xffffffff;
  }
  cVar4 = *(char *)(param_1 + 0x189);
  local_24[0] = (char *)(uint)*(byte *)(param_1 + 0x188);
  FUN_008195e0(local_24);
  if (uStack_28 != DAT_00fab280) {
    FUN_008196d0();
    if (*(char **)(uStack_28 + 0x14) == local_24[0]) {
      if (cVar4 != '\0') {
        ExceptionList = pvStack_1c;
        return;
      }
      if (*(int *)(uStack_28 + 0x18) == 0) {
        ExceptionList = pvStack_1c;
        return;
      }
      local_24[0] = *(char **)*(char **)(uStack_28 + 0x14);
    }
    if (*(int *)(local_24[0] + 0x14) != 0) {
      pcVar1 = (char *)(*(int *)(local_24[0] + 0x14) + 4);
      local_24[0] = pcVar1;
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_14 = (void *)0x1;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_14 = (void *)0xffffffff;
      }
      if (((*(byte *)(param_1 + 0x188) < 10) &&
          (iVar3 = (uint)*(byte *)(param_1 + 0x188) * 0x210 + DAT_00f94304,
          *(int *)(iVar3 + 0x5c) != 0)) && (iVar3 != 0)) {
        uStack_28 = iVar3 + 500;
      }
      else {
        uStack_28 = 0;
      }
      if (pcVar1 == (char *)0x0) {
        cVar4 = (char)((uint)unaff_EBX >> 0x18);
      }
      else {
        cVar4 = *pcVar1;
      }
      if (uStack_28 == 0) {
LAB_00615e4b:
        if (cVar5 != '\0') {
          (**(code **)(**(int **)(param_1 + 0x14c + iStack_2c * 4) + 0x90))(1);
        }
        if (param_4 < (int)(uint)(byte)local_24[0][1]) {
          (**(code **)(**(int **)(param_1 + 0x118 + iStack_2c * 4) + 0x90))(0);
        }
        else {
          iVar3 = FUN_00404ba0();
          (**(code **)(**(int **)(param_1 + 0x118 + iStack_2c * 4) + 0x90))
                    (*(int *)(local_24[0] + 4) <= *(int *)(iVar3 + 0x6874));
        }
      }
      else {
        uVar2 = 0;
        if (*(int *)(uStack_28 + 8) != *(int *)(uStack_28 + 4)) {
          do {
            if (*(char *)(*(int *)(uStack_28 + 4) + uVar2) == cVar4) goto LAB_00615e4b;
            uVar2 = uVar2 + 1;
          } while (uVar2 < (uint)(*(int *)(uStack_28 + 8) - *(int *)(uStack_28 + 4)));
        }
        if (cVar5 != '\0') {
          (**(code **)(**(int **)(param_1 + 0x14c + iStack_2c * 4) + 0x90))(0);
        }
        (**(code **)(**(int **)(param_1 + 0x118 + iStack_2c * 4) + 0x90))(0);
        unaff_EBX = iStack_2c;
      }
      if (uStack_28 != 0) {
        uVar2 = 0;
        if (*(int *)(uStack_28 + 8) != *(int *)(iStack_2c + 4)) {
          do {
            if (*(char *)(*(int *)(iStack_2c + 4) + uVar2) == *(char *)(param_1 + 0x189))
            goto LAB_00615f5f;
            uVar2 = uVar2 + 1;
          } while (uVar2 < (uint)(*(int *)(uStack_28 + 8) - *(int *)(iStack_2c + 4)));
        }
        if (cVar5 != '\0') {
          (**(code **)(**(int **)(param_1 + 0x164 + unaff_EBX * 4) + 0x90))(0);
        }
        if ((param_5 == 0) &&
           ((**(code **)(**(int **)(param_1 + 0x118 + unaff_EBX * 4) + 0x90))(0), cVar5 != '\0')) {
          (**(code **)(**(int **)(param_1 + 0x14c + unaff_EBX * 4) + 0x90))(0);
        }
        (**(code **)(**(int **)(param_1 + 0x134 + unaff_EBX * 4) + 0x90))(0);
        ExceptionList = local_24[0];
        return;
      }
LAB_00615f5f:
      if (cVar5 != '\0') {
        (**(code **)(**(int **)(param_1 + 0x164 + unaff_EBX * 4) + 0x90))(1);
      }
      (**(code **)(**(int **)(param_1 + 0x134 + unaff_EBX * 4) + 0x90))
                ((int)(uint)*(byte *)(uStack_28 + 1) <= param_4);
    }
  }
  ExceptionList = pvStack_1c;
  return;
}

