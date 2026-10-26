
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00804740(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  char cVar4;
  DWORD DVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  code *pcVar10;
  int local_5c [8];
  undefined4 local_3c;
  undefined4 local_38;
  undefined2 local_34;
  undefined **local_30 [3];
  char *local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar2 = param_1;
  puStack_c = &LAB_00909a9c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc10cc & 1) == 0) {
    DAT_00fc10cc = DAT_00fc10cc | 1;
    local_8 = 0;
    FUN_00803ff0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdc90);
  }
  local_8 = 0xffffffff;
  local_14 = (undefined4 *)0x0;
  WaitForSingleObject(DAT_00fc11f0,1);
  piVar8 = param_1 + 0xc;
  piVar9 = param_1;
  for (iVar7 = 0xb; piVar9 = piVar9 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar9 = *piVar8;
    piVar8 = piVar8 + 1;
  }
  local_5c[0] = 0;
  local_5c[1] = 0;
  local_5c[2] = 0;
  local_5c[3] = 0;
  local_5c[4] = 0;
  local_5c[5] = 0;
  local_5c[6] = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  piVar9 = local_5c;
  piVar8 = param_1 + 0xc;
  for (iVar7 = 0xb; pcVar10 = timeGetTime_exref, iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar8 = *piVar9;
    piVar9 = piVar9 + 1;
    piVar8 = piVar8 + 1;
  }
  DVar5 = timeGetTime();
  local_18 = param_1[0x21];
  param_1[0xc] = DVar5;
  if (local_18 - 4 < DVar5 - param_1[4]) {
    local_18 = 4;
    *(undefined1 *)(param_1 + 0x16) = 1;
  }
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  DVar5 = timeGetTime();
  param_1[0xe] = DVar5;
  param_1 = (int *)0x0;
  do {
    if (param_1 == (int *)0x2) {
      iVar7 = (*pcVar10)();
      piVar2[0x10] = iVar7;
      piVar2[0x15] = 0;
    }
    cVar4 = FUN_00804100(&local_14,param_1);
    while (cVar4 != '\0') {
      local_1c = (*pcVar10)();
      puVar3 = local_14;
      local_20 = (**(code **)*piVar2)(*local_14,local_14 + 2,local_14[1],param_1);
      iVar7 = (*pcVar10)();
      uVar6 = iVar7 - local_1c;
      (**(code **)(*piVar2 + 0xc))(param_1,puVar3,uVar6);
      if (0x28 < uVar6) {
        (**(code **)(*piVar2 + 8))(piVar2[0x23],param_1,puVar3,uVar6);
      }
      if ((DAT_00fe3354 & 1) == 0) {
        DAT_00fe3354 = DAT_00fe3354 | 1;
        local_8 = 1;
        FUN_00807120();
        _atexit((_func_4879 *)&LAB_00bd0b90);
        local_8 = 0xffffffff;
      }
      *puVar3 = 0;
      puVar3[1] = 0;
      EnterCriticalSection(DAT_00fe33b0);
      if (((DAT_00fe33a0 + DAT_00fe33a4 & 3U) == 0) && (DAT_00fe339c <= DAT_00fe33a4 + 4U >> 2)) {
        FUN_00636f70(&DAT_00fe3394);
      }
      local_1c = DAT_00fe33a0 + DAT_00fe33a4;
      uVar6 = local_1c >> 2;
      if (DAT_00fe339c <= uVar6) {
        uVar6 = uVar6 - DAT_00fe339c;
      }
      if (*(int *)(DAT_00fe3398 + uVar6 * 4) == 0) {
        iVar7 = FUN_00891268(0x10);
        if (iVar7 == 0) {
          local_24 = (char *)0x0;
          std::exception::exception((exception *)local_30,&local_24);
          local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_30,&DAT_00c857a8);
        }
        *(int *)(DAT_00fe3398 + uVar6 * 4) = iVar7;
      }
      puVar1 = (undefined4 *)(*(int *)(DAT_00fe3398 + uVar6 * 4) + (local_1c & 3) * 4);
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = puVar3;
      }
      DAT_00fe33a4 = DAT_00fe33a4 + 1;
      _DAT_00fe33ac = _DAT_00fe33ac + -1;
      LeaveCriticalSection(DAT_00fe33b0);
      piVar2[0x14] = piVar2[0x14] + 1;
      if (param_1 == (int *)0x2) {
        piVar2[0x15] = piVar2[0x15] + 1;
      }
      pcVar10 = timeGetTime_exref;
      if (local_20 != 0) break;
      cVar4 = FUN_00804100(&local_14,param_1);
      pcVar10 = timeGetTime_exref;
    }
    if (param_1 == (int *)0x2) {
      iVar7 = (*pcVar10)();
      piVar2[0x11] = iVar7;
    }
    param_1 = (int *)((int)param_1 + 1);
    if (5 < (int)param_1) {
      iVar7 = (*pcVar10)();
      piVar2[0xf] = iVar7;
      *(bool *)((int)piVar2 + 0x59) = local_18 < (uint)(iVar7 - piVar2[0xe]);
      ExceptionList = local_10;
      return;
    }
  } while( true );
}

