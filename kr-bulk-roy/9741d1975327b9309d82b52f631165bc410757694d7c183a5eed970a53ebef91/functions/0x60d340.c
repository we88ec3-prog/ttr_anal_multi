
void FUN_0060d340(int param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int unaff_EDI;
  uint uVar7;
  int local_3c;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092df14;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (unaff_EDI == -1) {
    iVar2 = *(int *)(param_1 + 0x248);
    if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
       (iVar5 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar5 == 0xbf6b)) {
      iVar2 = *(int *)(iVar2 + 0x94);
      iVar5 = *(int *)(iVar2 + 0x10);
      if (iVar5 != 0) {
        piVar3 = *(int **)(iVar5 + 8);
        if (piVar3 != (int *)0x0) {
          piVar1 = piVar3 + 0x27;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar3 + 0x28))();
          }
        }
        *(undefined4 *)(iVar2 + 0x10) = 0;
      }
    }
  }
  else {
    uVar7 = uVar4;
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 0;
      FUN_005c3de0(uVar4);
      _atexit((_func_4879 *)&LAB_00bccc30);
    }
    iVar2 = DAT_00f943ec;
    local_8 = 0xffffffff;
    if ((((DAT_00f943ec == 0) || (FUN_0082ef00(&stack0xffffffc8), local_3c == *(int *)(iVar2 + 0xc))
         ) || (*(int *)(local_3c + 0x10) == 0)) && ((DAT_00f94394 & 1) == 0)) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 1;
      FUN_005c3de0(uVar7);
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8 = 0xffffffff;
    }
    FUN_00745060();
  }
  if (param_2 == '\0') {
    FUN_00757710();
  }
  else {
    uVar6 = FUN_00426ec0();
    local_8 = 2;
    FUN_00757800(uVar6);
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar4 ^ (uint)&stack0xfffffffc);
  return;
}

