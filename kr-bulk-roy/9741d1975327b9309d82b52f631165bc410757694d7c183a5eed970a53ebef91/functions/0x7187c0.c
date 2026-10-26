
void FUN_007187c0(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915f38;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  lpCriticalSection = (LPCRITICAL_SECTION)*unaff_EDI;
  EnterCriticalSection(lpCriticalSection);
  local_8 = 0;
  if ((unaff_EDI[0x10] == 0) && (unaff_EDI[0xe] == 0)) {
    FUN_00718cb0(uVar2);
    for (iVar3 = unaff_EDI[0xb]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x28)) {
      if ((((*(int *)(iVar3 + 0x24) == 0) && (*(int *)(iVar3 + 8) != 0)) &&
          (*(undefined4 *)(iVar3 + 8) = 0, *(int *)(iVar3 + 0xc) != 0)) &&
         (*(int *)(iVar3 + 0x48) != 0)) {
        FUN_00891d3d(*(int *)(iVar3 + 0x48));
        *(undefined4 *)(iVar3 + 0x48) = 0;
      }
    }
    (**(code **)(*(int *)unaff_EDI[9] + 0x10))(0x10,0);
    iVar3 = (**(code **)(*(int *)unaff_EDI[9] + 0xc))();
    if (iVar3 != 0) {
      uVar4 = FUN_0087dc3d(iVar3 + -0x10);
      unaff_EDI[0xe] = uVar4;
      (*(code *)**(undefined4 **)(unaff_EDI[9] + 4))(uVar4,iVar3 + -0x10);
      for (piVar1 = (int *)unaff_EDI[0xb]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[10]) {
        iVar3 = unaff_EDI[0xe];
        piVar1[2] = 1;
        piVar1[0x12] = *piVar1 * 0x400 + iVar3;
        piVar1[3] = 0;
      }
      (*(code *)**(undefined4 **)unaff_EDI[9])(0);
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_10;
  return;
}

