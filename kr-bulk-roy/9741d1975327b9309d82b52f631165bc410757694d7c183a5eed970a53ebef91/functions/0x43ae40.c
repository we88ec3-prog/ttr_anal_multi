
void FUN_0043ae40(int param_1)

{
  int *piVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int local_58;
  uint local_54;
  int local_50;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00931be4;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(uint *)(in_ECX + 0x2e) < 4) {
    local_54 = CONCAT31(local_54._1_3_,1);
    if (*(uint *)(in_ECX + 0x2e) != 0) goto LAB_0043ae87;
  }
  local_54 = local_54 & 0xffffff00;
LAB_0043ae87:
  local_58 = in_ECX;
  (**(code **)(**(int **)(param_1 + 600) + 0x94))(local_54,local_14);
  (**(code **)(**(int **)(param_1 + 0x248) + 0x94))((char)local_54 == '\0');
  if ((char)local_54 == '\0') {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 2;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_58 = 0x1b;
    FUN_005740f0(&local_58);
    if (local_50 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    uVar5 = FUN_00420070();
    local_8 = 3;
    FUN_00757800(uVar5);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    (**(code **)(**(int **)(param_1 + 0x248) + 200))();
  }
  else {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 0;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8 = 0xffffffff;
    }
    iVar4 = DAT_00f943ac;
    local_54 = 0x10;
    FUN_0082ef00(&local_54);
    if ((local_50 != *(int *)(iVar4 + 8)) && (local_50 = *(int *)(local_50 + 0x10), local_50 != 0))
    {
      puVar3 = (undefined4 *)FUN_00420070();
      local_8 = 1;
      if (7 < (uint)puVar3[5]) {
        puVar3 = (undefined4 *)*puVar3;
      }
      local_50 = FUN_00763360(puVar3);
      if (((*(char *)(*(int *)(param_1 + 600) + 0xa4) != '\0') &&
          (piVar1 = *(int **)(*(int *)(param_1 + 600) + 0x94), piVar1 != (int *)0x0)) &&
         (iVar4 = (**(code **)(*piVar1 + 4))(), iVar4 == 0xbf6b)) {
        FUN_0077b200();
        in_ECX = local_58;
      }
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      (**(code **)(**(int **)(param_1 + 600) + 200))();
    }
  }
  FUN_0043b130(param_1,in_ECX + 0x42);
  uVar5 = FUN_00433f80(local_4c,*(undefined4 *)(in_ECX + 0x32),*(undefined4 *)(in_ECX + 0x36));
  local_8 = 4;
  FUN_00757800(uVar5);
  local_8 = 0xffffffff;
  if (7 < local_38) {
    FUN_0089120c(local_4c[0]);
  }
  local_4c[0] = local_4c[0] & 0xffff0000;
  local_38 = 7;
  local_3c = 0;
  (**(code **)(**(int **)(param_1 + 0x250) + 200))();
  FUN_00757710();
  (**(code **)(**(int **)(param_1 + 0x24c) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

