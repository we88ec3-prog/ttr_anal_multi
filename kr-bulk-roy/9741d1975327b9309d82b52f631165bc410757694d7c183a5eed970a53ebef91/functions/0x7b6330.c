
/* WARNING: Removing unreachable block (ram,0x007b63d6) */
/* WARNING: Removing unreachable block (ram,0x007b6434) */
/* WARNING: Removing unreachable block (ram,0x007b6591) */
/* WARNING: Removing unreachable block (ram,0x007b648d) */

void FUN_007b6330(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  uint local_28;
  int local_24;
  int local_20;
  undefined4 *local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009381b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar3 = (undefined4 *)0x0;
  local_8 = 0;
  iVar2 = param_1 + 0x60;
  local_38 = 0;
  local_34 = 0;
  local_20 = iVar2;
  cVar1 = FUN_007b6ba0(iVar2,&local_38);
  while (cVar1 != '\0') {
    if (&local_38 < puVar3) {
      iVar2 = (int)&local_38 >> 3;
      if (puVar3 == (undefined4 *)0x0) {
        FUN_004e7330(1);
        iVar2 = local_20;
      }
      else {
        *puVar3 = *(undefined4 *)(iVar2 * 8);
        puVar3[1] = *(undefined4 *)(iVar2 * 8 + 4);
        iVar2 = local_20;
      }
    }
    else if (puVar3 == (undefined4 *)0x0) {
      FUN_004e7330(1);
    }
    else {
      *puVar3 = local_38;
      puVar3[1] = local_34;
    }
    puVar3 = puVar3 + 2;
    cVar1 = FUN_007b6ba0(iVar2,&local_38);
  }
  local_28 = (int)puVar3 >> 3;
  local_18 = 0;
  if (local_28 != 0) {
    do {
      local_34 = *(undefined4 *)(local_18 * 8 + 4);
      iVar2 = *(int *)(local_18 * 8);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba6d0);
      puVar3 = (undefined4 *)0x0;
      local_1c = (undefined4 *)0x0;
      FUN_0082ef00(iVar2 + 4);
      if (local_24 != *(int *)(param_1 + 0x14)) {
        puVar3 = *(undefined4 **)(local_24 + 0x10);
        local_1c = puVar3;
        FUN_007b6890(param_1 + 0x10,local_2c,local_24);
      }
      FUN_0082ef00(&local_1c);
      if (local_20 == *(int *)(param_1 + 0x24)) {
        FUN_007b5c90(param_1);
      }
      else {
        (**(code **)*puVar3)(iVar2,local_34);
        FUN_007b6890(param_1 + 0x20,local_30,local_20);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba6d0);
      if (iVar2 != 0) {
        if (0xf < *(uint *)(iVar2 + 0x24)) {
          FUN_0089120c(*(undefined4 *)(iVar2 + 0x10));
        }
        *(undefined4 *)(iVar2 + 0x24) = 0xf;
        *(undefined4 *)(iVar2 + 0x20) = 0;
        *(undefined1 *)(iVar2 + 0x10) = 0;
        FUN_0089120c(iVar2);
      }
      local_18 = local_18 + 1;
    } while (local_18 < local_28);
  }
  ExceptionList = local_10;
  return;
}

