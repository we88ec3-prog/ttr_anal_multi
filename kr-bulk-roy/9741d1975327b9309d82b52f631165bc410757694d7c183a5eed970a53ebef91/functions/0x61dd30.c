
void FUN_0061dd30(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  int local_24;
  uint local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00946a5c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar8 = (param_2 + 10) * 7 + param_3;
  iVar1 = *(int *)(*(int *)(param_1 + iVar8 * 4) + 0x248);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if (((*(uint *)(param_1 + 0x218) < 10) &&
      (local_1c = *(uint *)(param_1 + 0x218) * 0x210 + DAT_00f94304, *(int *)(local_1c + 0x5c) != 0)
      ) && (local_1c != 0)) {
    if ((DAT_00fb11a8 & 1) == 0) {
      DAT_00fb11a8 = DAT_00fb11a8 | 1;
      local_c = 1;
      FUN_00813890();
      _atexit((_func_4879 *)&LAB_00bccec0);
    }
    local_c = 0xffffffff;
    local_24 = iVar1;
    FUN_0082ef00(&local_24);
    if ((local_20 != DAT_00fb11b0) && (iVar2 = *(int *)(local_20 + 0x10), iVar2 != 0)) {
      if (*(int *)(iVar2 + 0x14) == *(int *)(iVar2 + 0x18)) {
        local_20 = 0;
      }
      else {
        local_20 = (*(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x14) >> 2) - 1;
      }
      local_20 = local_20 & 0xff;
      uVar6 = (uint)*(byte *)(*(int *)(param_1 + iVar8 * 4) + 0x250);
      if (uVar6 < local_20) {
        do {
          uVar6 = uVar6 + 1;
          cVar4 = FUN_0061d1e0(param_1,iVar1,uVar6);
          if (cVar4 == '\0') {
            ExceptionList = local_14;
            return;
          }
          piVar3 = *(int **)(local_1c + 0xfc);
          uVar7 = *(int *)(local_1c + 0x100) - (int)piVar3 >> 3;
          uVar9 = 0;
          piVar10 = piVar3;
          if (uVar7 != 0) {
            do {
              if (*piVar10 == iVar1) {
                uVar5 = (undefined2)piVar3[uVar9 * 2 + 1];
                goto LAB_0061deb9;
              }
              uVar9 = uVar9 + 1;
              piVar10 = piVar10 + 2;
            } while (uVar9 < uVar7);
          }
          uVar5 = 0;
LAB_0061deb9:
          FUN_0061ccf0(param_1,iVar1,uVar5,param_2,param_3);
        } while ((int)uVar6 < (int)local_20);
      }
    }
  }
  ExceptionList = local_14;
  return;
}

