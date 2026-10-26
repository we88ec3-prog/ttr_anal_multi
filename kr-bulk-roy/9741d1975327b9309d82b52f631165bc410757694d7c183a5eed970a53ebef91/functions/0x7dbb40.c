
void FUN_007dbb40(int *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int *unaff_ESI;
  uint uVar5;
  uint uVar6;
  int iVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905b58;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 2));
  local_8 = 0;
  iVar7 = *unaff_ESI;
  if ((iVar7 != 0) && (param_1 != (int *)0x0)) {
    iVar3 = FUN_008fed10(uVar2);
    if (iVar3 == 0) {
      uVar2 = (**(code **)(*param_1 + 0x34))();
      uVar5 = 0;
      if (uVar2 != 0) {
        do {
          piVar1 = (int *)*unaff_ESI;
          uVar6 = uVar5;
          uVar4 = (**(code **)(*param_1 + 0x30))(uVar5);
          uVar4 = (**(code **)(*piVar1 + 0x30))(uVar5,uVar4);
          FUN_007db870(uVar4,uVar6);
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar2);
      }
    }
    else {
      FUN_00780150(iVar7,iVar3);
      uVar2 = (**(code **)(*(int *)*unaff_ESI + 0x34))();
      uVar5 = 0;
      if (uVar2 != 0) {
        do {
          piVar1 = (int *)*unaff_ESI;
          uVar6 = uVar5;
          iVar7 = iVar3;
          uVar4 = (**(code **)(*param_1 + 0x30))(uVar5,iVar3);
          uVar4 = (**(code **)(*piVar1 + 0x30))(uVar5,uVar4);
          FUN_007db520(uVar4,uVar6,iVar7);
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar2);
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 2));
  ExceptionList = local_10;
  return;
}

