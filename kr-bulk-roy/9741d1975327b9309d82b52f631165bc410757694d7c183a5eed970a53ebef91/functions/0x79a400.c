
void FUN_0079a400(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int *unaff_EDI;
  undefined1 local_1c [4];
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009325ba;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = (int *)unaff_EDI[0x27];
  uVar3 = 0;
  uVar4 = local_14[1] - *local_14 >> 2;
  if (uVar4 != 0) {
    do {
      (**(code **)(**(int **)(*local_14 + uVar3 * 4) + 0x14))(uVar1);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
  }
  (**(code **)(*(int *)unaff_EDI[0x28] + 8))();
  piVar5 = (int *)unaff_EDI[0x23];
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 8))(piVar5);
    unaff_EDI[0x23] = 0;
  }
  if ((undefined4 *)unaff_EDI[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)unaff_EDI[5])(1);
    unaff_EDI[5] = 0;
  }
  if ((undefined4 *)unaff_EDI[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)unaff_EDI[4])(1);
    unaff_EDI[4] = 0;
  }
  if ((undefined4 *)unaff_EDI[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)unaff_EDI[3])(1);
    unaff_EDI[3] = 0;
  }
  if ((DAT_00fe1df8 & 1) == 0) {
    DAT_00fe1df8 = DAT_00fe1df8 | 1;
    local_8 = 0;
    FUN_00716be0();
    _atexit((_func_4879 *)&LAB_00bcf1a0);
    local_8 = 0xffffffff;
  }
  iVar2 = FUN_00716830();
  local_18 = iVar2;
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x11));
  piVar5 = (int *)**(int **)(iVar2 + 4);
  if (piVar5 != *(int **)(iVar2 + 4)) {
    do {
      iVar2 = piVar5[9];
      if (*(uint *)(iVar2 + 0x30) < 0x10) {
        iVar2 = iVar2 + 0x1c;
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x1c);
      }
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 1;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      local_14 = (int *)0x0;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 2;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      local_14 = (int *)(**(code **)(*DAT_00fb76a8 + 0x54))(local_1c,iVar2);
      local_14 = (int *)*local_14;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
      (**(code **)(*(int *)*unaff_EDI + 0x5c))(&local_14);
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)*(int *)(local_18 + 4));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x11));
  if ((undefined4 *)*unaff_EDI != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*unaff_EDI)(1);
    *unaff_EDI = 0;
  }
  ExceptionList = local_10;
  return;
}

