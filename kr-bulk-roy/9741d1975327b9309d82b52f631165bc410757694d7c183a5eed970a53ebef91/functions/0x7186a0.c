
void FUN_007186a0(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  undefined4 *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905b58;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  lpCriticalSection_00 = (LPCRITICAL_SECTION)*unaff_EDI;
  EnterCriticalSection(lpCriticalSection_00);
  local_8 = 0;
  if (in_ECX != (int *)0x0) {
    lpCriticalSection = (LPCRITICAL_SECTION)(in_ECX + 0xb);
    EnterCriticalSection(lpCriticalSection);
    if (in_ECX[2] != 0) {
      LeaveCriticalSection(lpCriticalSection);
      LeaveCriticalSection(lpCriticalSection_00);
      ExceptionList = local_10;
      return;
    }
    FUN_00718cb0(uVar1);
    (**(code **)(*(int *)unaff_EDI[9] + 0x10))(*in_ECX * 0x400 + 0x10,0);
    if (unaff_EDI[0x10] == 0) {
      iVar3 = FUN_0087dc3d(in_ECX[0x13]);
      in_ECX[0x12] = iVar3;
      (*(code *)**(undefined4 **)(unaff_EDI[9] + 4))(iVar3,in_ECX[0x13]);
    }
    else {
      uVar2 = FUN_0087dc3d(in_ECX[0x13]);
      (*(code *)**(undefined4 **)(unaff_EDI[9] + 4))(uVar2,in_ECX[0x13]);
      FUN_00891d3d(uVar2);
    }
    in_ECX[3] = 1;
    in_ECX[2] = 1;
    LeaveCriticalSection(lpCriticalSection);
    (*(code *)**(undefined4 **)unaff_EDI[9])(0);
  }
  LeaveCriticalSection(lpCriticalSection_00);
  ExceptionList = local_10;
  return;
}

