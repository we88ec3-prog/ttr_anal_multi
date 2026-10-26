
void FUN_00452910(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092124e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00755e50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_0043c570(21000);
  FUN_00453190();
  FUN_0043c570(34000);
  FUN_0043c570(35000);
  FUN_0043c570(36000);
  FUN_00453280();
  FUN_00453370();
  iVar1 = *(int *)(in_ECX + 0x108);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  iVar1 = *(int *)(in_ECX + 0x108);
  if (((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
    *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0x100) + 0xcc);
  if (iVar1 != 0) {
    FUN_00408920(iVar1,3);
  }
  local_14 = 0;
  while( true ) {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x100) + 0xcc);
    if (iVar1 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(iVar1 + 0xa8);
    }
    if ((uint)(piVar3[1] - *piVar3 >> 2) <= local_14) break;
    iVar1 = *(int *)(*(int *)(in_ECX + 0x100) + 0xcc);
    if (((iVar1 == 0) || ((int)local_14 < 0)) ||
       (*(int *)(iVar1 + 0xac) - *(int *)(iVar1 + 0xa8) >> 2 <= (int)local_14)) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = *(int **)(*(int *)(iVar1 + 0xa8) + local_14 * 4);
    }
    FUN_0046b6f0(0x5654);
    local_18 = piVar3[0x92];
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(local_18 + 0xa4) = 1;
    iVar1 = piVar3[0x92];
    if (((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) &&
       (iVar2 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
      *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
    }
    (**(code **)(*piVar3 + 200))();
    local_14 = local_14 + 1;
  }
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  local_18 = 0x36;
  FUN_0082ef00(&local_18);
  uVar4 = FUN_00763360(L"Rank_SS");
  *(undefined4 *)(in_ECX + 0x10c) = uVar4;
  uVar4 = FUN_00763360(L"Rank_S");
  *(undefined4 *)(in_ECX + 0x110) = uVar4;
  uVar4 = FUN_00763360(L"Rank_A");
  *(undefined4 *)(in_ECX + 0x114) = uVar4;
  uVar4 = FUN_00763360(L"Rank_B");
  *(undefined4 *)(in_ECX + 0x118) = uVar4;
  uVar4 = FUN_00763360(L"Rank_C");
  *(undefined4 *)(in_ECX + 0x11c) = uVar4;
  uVar4 = FUN_00763360(L"Rank_D");
  *(undefined4 *)(in_ECX + 0x120) = uVar4;
  uVar4 = FUN_00763360(L"Rank_E");
  *(undefined4 *)(in_ECX + 0x124) = uVar4;
  uVar4 = FUN_00763360(L"Rank_F");
  *(undefined4 *)(in_ECX + 0x128) = uVar4;
  ExceptionList = local_10;
  return;
}

