
void FUN_005a9f40(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 extraout_EDX;
  int *unaff_EDI;
  undefined8 uVar4;
  WCHAR local_208 [256];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar1 = (**(code **)(*in_ECX + 0x10))();
  uVar2 = (**(code **)(*in_ECX + 4))();
  uVar4 = FUN_005a3840(uVar2,param_1);
  uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
  if ((int)uVar4 == 0) {
    uVar3 = (**(code **)(*unaff_EDI + 0x1c))(uVar2);
    FUN_0040aeb0(L"Can\'t Load Resource : [%d] %s",uVar2,uVar3);
    MessageBoxW((HWND)0x0,local_208,L"Error",0);
    uVar3 = extraout_EDX;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,uVar3,uVar1);
  return;
}

