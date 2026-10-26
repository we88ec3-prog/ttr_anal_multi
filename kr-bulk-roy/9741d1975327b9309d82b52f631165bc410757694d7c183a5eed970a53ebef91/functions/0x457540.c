
void FUN_00457540(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092124e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00755e50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_0043c570(10000);
  FUN_00458150();
  FUN_0043c570(32000);
  FUN_0043c570(33000);
  FUN_0043c570(34000);
  FUN_00458240(35000);
  FUN_0043c570(40000);
  FUN_00458240(50000);
  FUN_00458330();
  FUN_00643ce0(76000);
  FUN_00643ce0(77000);
  FUN_00643ce0(78000);
  FUN_00643ce0(79000);
  iVar6 = *(int *)(in_ECX + 0xf8);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar6 + 0xa4) = 1;
  iVar6 = *(int *)(in_ECX + 0xf8);
  if (((*(char *)(iVar6 + 0xa4) != '\0') && (*(int *)(iVar6 + 0x94) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar6 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
    *(undefined1 *)(*(int *)(iVar6 + 0x94) + 0x4c) = 1;
  }
  iVar6 = 71000;
  do {
    FUN_006c09c0(iVar6);
    iVar6 = iVar6 + 1000;
  } while (iVar6 < 76000);
  iVar6 = *(int *)(*(int *)(in_ECX + 0x108) + 0xcc);
  if (iVar6 != 0) {
    FUN_00408920(iVar6,3);
  }
  local_14 = 0;
  while( true ) {
    iVar6 = *(int *)(*(int *)(in_ECX + 0x108) + 0xcc);
    if (iVar6 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(iVar6 + 0xa8);
    }
    if ((uint)(piVar3[1] - *piVar3 >> 2) <= local_14) break;
    iVar6 = *(int *)(*(int *)(in_ECX + 0x108) + 0xcc);
    if (((iVar6 == 0) || ((int)local_14 < 0)) ||
       (*(int *)(iVar6 + 0xac) - *(int *)(iVar6 + 0xa8) >> 2 <= (int)local_14)) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = *(int **)(*(int *)(iVar6 + 0xa8) + local_14 * 4);
    }
    FUN_0046b6f0(0x891c);
    iVar6 = piVar3[0x92];
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar6 + 0xa4) = 1;
    iVar6 = piVar3[0x92];
    if (((*(char *)(iVar6 + 0xa4) != '\0') && (*(int *)(iVar6 + 0x94) != 0)) &&
       (iVar2 = (**(code **)(**(int **)(iVar6 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
      *(undefined1 *)(*(int *)(iVar6 + 0x94) + 0x4c) = 1;
    }
    (**(code **)(*piVar3 + 200))();
    local_14 = local_14 + 1;
  }
  iVar6 = *(int *)(*(int *)(in_ECX + 0x110) + 0xcc);
  if (iVar6 != 0) {
    FUN_00408920(iVar6,10);
  }
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  puVar4 = *(undefined4 **)(*(int *)(DAT_00f943ac + 8) + 4);
  cVar1 = *(char *)((int)puVar4 + 0x15);
  while (cVar1 == '\0') {
    if ((uint)puVar4[3] < 0x36) {
      puVar4 = (undefined4 *)puVar4[2];
    }
    else {
      puVar4 = (undefined4 *)*puVar4;
    }
    cVar1 = *(char *)((int)puVar4 + 0x15);
  }
  uVar5 = FUN_00763360(L"MiniRank_SS");
  *(undefined4 *)(in_ECX + 0x160) = uVar5;
  uVar5 = FUN_00763360(L"MiniRank_S");
  *(undefined4 *)(in_ECX + 0x164) = uVar5;
  uVar5 = FUN_00763360(L"MiniRank_A");
  *(undefined4 *)(in_ECX + 0x168) = uVar5;
  uVar5 = FUN_00763360(L"MiniRank_B");
  *(undefined4 *)(in_ECX + 0x16c) = uVar5;
  uVar5 = FUN_00763360(L"MiniRank_C");
  *(undefined4 *)(in_ECX + 0x170) = uVar5;
  uVar5 = FUN_00763360(L"MiniRank_D");
  *(undefined4 *)(in_ECX + 0x174) = uVar5;
  uVar5 = FUN_00763360(L"MiniRank_E");
  *(undefined4 *)(in_ECX + 0x178) = uVar5;
  uVar5 = FUN_00763360(L"MiniRank_F");
  *(undefined4 *)(in_ECX + 0x17c) = uVar5;
  ExceptionList = local_10;
  return;
}

