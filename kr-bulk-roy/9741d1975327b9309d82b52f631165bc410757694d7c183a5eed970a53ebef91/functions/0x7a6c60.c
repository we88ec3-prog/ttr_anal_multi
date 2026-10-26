
void FUN_007a6c60(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 ***pppuVar3;
  int *piVar4;
  undefined4 uVar5;
  int unaff_ESI;
  undefined1 local_3c [12];
  undefined4 **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914bf8;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int **)(unaff_ESI + 0x120) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_ESI + 0x120) + 0x10))(local_14);
    (**(code **)(**(int **)(unaff_ESI + 0x120) + 8))();
    *(undefined4 *)(unaff_ESI + 0x120) = 0;
  }
  if ((DAT_00fba82c != (int *)0x0) && (*(int **)(unaff_ESI + 0xac) != (int *)0x0)) {
    iVar2 = (**(code **)(**(int **)(unaff_ESI + 0xac) + 0x40))();
    if (((int *)(iVar2 + 0x68) != (int *)0x0) && (*(int *)(iVar2 + 0x68) != 0)) {
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffffff00);
      FUN_00403040(iVar2 + 0x6c,0,0xffffffff);
      local_8 = 0;
      FUN_00401ed0(iVar2 + 0x88,0,0xffffffff);
      pppuVar3 = (undefined4 ***)local_30[0];
      if (local_1c < 0x10) {
        pppuVar3 = local_30;
      }
      piVar4 = (int *)(**(code **)(*DAT_00fba82c + 0x1c))(pppuVar3);
      pcVar1 = *(code **)(*(int *)(unaff_ESI + 4) + 8);
      *(int **)(unaff_ESI + 0x120) = piVar4;
      iVar2 = *piVar4;
      uVar5 = (*pcVar1)(local_3c);
      (**(code **)(iVar2 + 0xc))(uVar5);
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

