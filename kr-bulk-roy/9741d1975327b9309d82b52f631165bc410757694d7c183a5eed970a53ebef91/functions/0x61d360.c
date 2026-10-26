
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_0061d360(int param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined1 auStack_103c [4];
  uint local_1038;
  int local_1034;
  int local_1030;
  undefined1 local_102c [4];
  undefined4 local_1028;
  char acStack_1024 [4092];
  uint local_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093dd8e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_103c;
  ExceptionList = &local_14;
  iVar7 = **(int **)(param_1 + 0xf8);
  local_1028._2_1_ = *(undefined1 *)(param_1 + 0x218);
  local_1030 = param_1;
  local_1028._0_2_ = 0xd4;
  local_28 = 3;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffefb8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (*(uint *)(param_1 + 0x218) < 10) {
    local_1038 = DAT_00f94304 + *(uint *)(param_1 + 0x218) * 0x210;
    local_1038 = -(uint)(*(int *)(local_1038 + 0x5c) != 0) & local_1038;
    local_1034 = 0;
  }
  else {
    local_1038 = 0;
    local_1034 = 0;
  }
  do {
    if (iVar7 == *(int *)(param_1 + 0xf8)) break;
    piVar3 = *(int **)(local_1038 + 0xfc);
    uVar2 = *(int *)(local_1038 + 0x100) - (int)piVar3 >> 3;
    uVar5 = 0;
    if (uVar2 != 0) {
      piVar6 = piVar3;
      do {
        param_1 = local_1030;
        if (*piVar6 == *(int *)(iVar7 + 0xc)) {
          cVar4 = (char)(short)piVar3[uVar5 * 2 + 1];
          goto LAB_0061d496;
        }
        uVar5 = uVar5 + 1;
        piVar6 = piVar6 + 2;
      } while (uVar5 < uVar2);
    }
    cVar4 = '\0';
LAB_0061d496:
    cVar1 = *(char *)(iVar7 + 0x10);
    if (local_28 + 5 < 0x1001) {
      *(undefined4 *)((int)&local_1028 + local_28) = *(undefined4 *)(iVar7 + 0xc);
      acStack_1024[local_28] = cVar1 - cVar4;
      local_28 = local_28 + 5;
    }
    piVar3 = (int *)FUN_007b6890(param_1 + 0xf4,local_102c,iVar7);
    iVar7 = *piVar3;
    local_1034 = local_1034 + 1;
  } while (local_1034 < 10);
  if (3 < local_28) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1028,local_28);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_103c);
  return;
}

