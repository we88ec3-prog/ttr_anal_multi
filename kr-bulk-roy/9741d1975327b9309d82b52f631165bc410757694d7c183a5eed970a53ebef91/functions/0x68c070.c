
void FUN_0068c070(void)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  int *piVar5;
  int iVar6;
  int local_3c;
  undefined4 local_38;
  int *local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092c756;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00755e50(local_14);
  FUN_0063b9e0();
  local_34 = (int *)(in_ECX + 0xf8);
  FUN_0068c390();
  FUN_00615fc0(30000);
  FUN_00615fc0(40000);
  FUN_006a9e80(51000);
  FUN_006a9e80(52000);
  *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x144) = 0x10;
  if ((*(int *)(*local_34 + 0x24c) != 0) &&
     (iVar6 = *(int *)(*(int *)(*local_34 + 0x24c) + 0xcc), iVar6 != 0)) {
    FUN_006438f0(iVar6);
  }
  FUN_00757710();
  iVar6 = 0;
  local_38 = 0x14b;
  do {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    FUN_005740f0(&local_38);
    if (local_3c == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    iVar6 = iVar6 + 1;
    uVar3 = FUN_004068f0();
    local_8 = 1;
    iVar1 = *local_34;
    iVar4 = *(int *)(iVar1 + 0x24c);
    if (iVar4 != 0) {
      iVar4 = *(int *)(iVar4 + 0xcc);
      if (iVar4 == 0) {
        iVar4 = -1;
      }
      else {
        iVar4 = FUN_0075d370(*(undefined4 *)(iVar4 + 0xe4));
      }
      iVar1 = *(int *)(*(int *)(iVar1 + 0x24c) + 0xcc);
      if (iVar1 != 0) {
        for (piVar5 = *(int **)(iVar1 + 0xa8);
            (piVar5 != *(int **)(iVar1 + 0xac) && (*(int *)(*piVar5 + 0x20) != iVar4));
            piVar5 = piVar5 + 1) {
        }
      }
      FUN_00757800(uVar3);
    }
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    piVar5 = local_34;
    local_1c = 7;
    local_20 = 0;
    local_30 = local_30 & 0xffff0000;
  } while (iVar6 < 4);
  if (*(int *)(*local_34 + 0x24c) != 0) {
    FUN_00749920(*(int *)(*local_34 + 0x24c));
  }
  (**(code **)(*(int *)*piVar5 + 200))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

