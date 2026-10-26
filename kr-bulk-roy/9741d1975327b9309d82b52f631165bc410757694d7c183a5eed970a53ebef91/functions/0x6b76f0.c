
void FUN_006b76f0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *local_21c;
  int local_218;
  undefined1 local_214 [512];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091f5fe;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0(local_14);
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  iVar5 = DAT_00f943ac;
  local_8 = 0xffffffff;
  local_21c = (int *)0x2f;
  FUN_0082ef00(&local_21c);
  if (local_218 == *(int *)(iVar5 + 8)) {
    local_218 = 0;
  }
  else {
    local_218 = *(undefined4 *)(local_218 + 0x10);
  }
  iVar5 = 0;
  piVar4 = (int *)(in_ECX + 0xa4);
  piVar6 = piVar4;
  local_21c = piVar4;
  do {
    FUN_0040aeb0(L"Num01_%d",iVar5);
    iVar2 = FUN_00763360(local_214);
    *piVar6 = iVar2;
    iVar5 = iVar5 + 1;
    piVar6 = piVar6 + 1;
  } while (iVar5 < 10);
  piVar6 = (int *)(in_ECX + 0x90);
  local_218 = 3;
  do {
    iVar5 = piVar6[-3];
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar5 + 0xa4) = 1;
    iVar5 = piVar6[-3];
    iVar2 = *piVar4;
    if ((((*(char *)(iVar5 + 0xa4) != '\0') && (*(int *)(iVar5 + 0x94) != 0)) &&
        (iVar3 = (**(code **)(**(int **)(iVar5 + 0x94) + 4))(), iVar3 == 0xbf6b)) &&
       (iVar5 = *(int *)(iVar5 + 0x94), *(int *)(iVar5 + 0x10) != iVar2)) {
      if (((iVar2 != 0) && (piVar4 = *(int **)(iVar2 + 8), piVar4 != (int *)0x0)) &&
         (piVar4[0x27] = piVar4[0x27] + 1, piVar4[0x27] == 1)) {
        (**(code **)(*piVar4 + 0x24))();
      }
      if ((*(int *)(iVar5 + 0x10) != 0) &&
         (piVar4 = *(int **)(*(int *)(iVar5 + 0x10) + 8), piVar4 != (int *)0x0)) {
        piVar1 = piVar4 + 0x27;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)(*piVar4 + 0x28))();
        }
      }
      *(int *)(iVar5 + 0x10) = iVar2;
    }
    (**(code **)(*(int *)piVar6[-3] + 200))();
    iVar5 = *piVar6;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar5 + 0xa4) = 1;
    iVar5 = *piVar6;
    iVar2 = *local_21c;
    if ((((*(char *)(iVar5 + 0xa4) != '\0') && (*(int *)(iVar5 + 0x94) != 0)) &&
        (iVar3 = (**(code **)(**(int **)(iVar5 + 0x94) + 4))(), iVar3 == 0xbf6b)) &&
       (iVar5 = *(int *)(iVar5 + 0x94), *(int *)(iVar5 + 0x10) != iVar2)) {
      if (((iVar2 != 0) && (piVar4 = *(int **)(iVar2 + 8), piVar4 != (int *)0x0)) &&
         (piVar4[0x27] = piVar4[0x27] + 1, piVar4[0x27] == 1)) {
        (**(code **)(*piVar4 + 0x24))();
      }
      if ((*(int *)(iVar5 + 0x10) != 0) &&
         (piVar4 = *(int **)(*(int *)(iVar5 + 0x10) + 8), piVar4 != (int *)0x0)) {
        piVar1 = piVar4 + 0x27;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)(*piVar4 + 0x28))();
        }
      }
      *(int *)(iVar5 + 0x10) = iVar2;
    }
    (**(code **)(*(int *)*piVar6 + 200))();
    piVar6 = piVar6 + 1;
    local_218 = local_218 + -1;
    piVar4 = local_21c;
  } while (local_218 != 0);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

