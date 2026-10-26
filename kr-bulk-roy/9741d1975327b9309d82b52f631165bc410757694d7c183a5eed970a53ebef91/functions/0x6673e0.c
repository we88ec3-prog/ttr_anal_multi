
void FUN_006673e0(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 **ppuVar6;
  undefined4 *puVar7;
  undefined1 auStack_54 [4];
  undefined4 *puStack_50;
  int iStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  undefined4 *puStack_40;
  undefined4 *puStack_3c;
  undefined4 local_38;
  uint local_24;
  uint uStack_20;
  uint local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092ccf6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_54;
  puVar4 = (undefined4 *)(DAT_00d61f20 ^ (uint)&stack0xffffffa0);
  ExceptionList = &local_14;
  FUN_00412df0();
  local_c = 0;
  FUN_00757710();
  local_c = 0xffffffff;
  if (7 < local_24) {
    FUN_0089120c(local_38);
  }
  (**(code **)(**(int **)(param_1 + 0x110) + 200))();
  iStack_4c = 0;
  iStack_48 = 0;
  puStack_50 = (undefined4 *)(param_1 + 0x118);
  uStack_44 = CONCAT31(uStack_44._1_3_,*(int *)(*(int *)(param_1 + 0x114) + 100) != 0);
  do {
    piVar1 = (int *)(iStack_48 + 0x80 + *(int *)(param_1 + 0x114));
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_c = 1;
      FUN_0051c120();
      _atexit((_func_4879 *)&LAB_00bccc90);
      local_c = 0xffffffff;
    }
    cVar2 = *(char *)((int)DAT_00f8d91c[1] + 0x15);
    puVar5 = (undefined4 *)DAT_00f8d91c[1];
    puStack_3c = DAT_00f8d91c;
    while (puVar7 = puVar5, cVar2 == '\0') {
      if ((int)puVar7[3] < *piVar1) {
        puVar5 = (undefined4 *)puVar7[2];
        puVar7 = puStack_3c;
      }
      else {
        puVar5 = (undefined4 *)*puVar7;
      }
      cVar2 = *(char *)((int)puVar5 + 0x15);
      puStack_3c = puVar7;
    }
    if ((puStack_3c == DAT_00f8d91c) || (*piVar1 < (int)puStack_3c[3])) {
      puStack_40 = DAT_00f8d91c;
      ppuVar6 = &puStack_40;
    }
    else {
      ppuVar6 = &puStack_3c;
    }
    if ((*ppuVar6 == DAT_00f8d91c) || (iVar3 = (*ppuVar6)[4], iVar3 == 0)) {
      (**(code **)(*(int *)*puStack_50 + 0x1ac))(0xffffffff,0xffffffff,0,0,0);
      FUN_00667610(param_1,0xffffffff,0xffffffff);
    }
    else {
      (**(code **)(*(int *)*puStack_50 + 0x1ac))
                (*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x1c),piVar1[2],piVar1[3],
                 (char)piVar1[4]);
      FUN_00667610(param_1,*(undefined4 *)(iVar3 + 0x1c),piVar1[2]);
    }
    (**(code **)(*(int *)*puVar4 + 200))();
    iStack_4c = iStack_4c + 1;
    iStack_48 = iStack_48 + 0x18;
    puStack_50 = puVar4 + 1;
  } while (iStack_48 < 0x48);
  (**(code **)(**(int **)(param_1 + 0xfc) + 0x90))(uStack_44);
  (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
  ExceptionList = pvStack_18;
  __security_check_cookie(uStack_20 ^ (uint)&stack0xffffffa8);
  return;
}

