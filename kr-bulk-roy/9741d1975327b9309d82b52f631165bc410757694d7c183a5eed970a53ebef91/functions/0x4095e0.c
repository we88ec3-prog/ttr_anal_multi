
void FUN_004095e0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined4 local_210;
  int local_20c;
  WCHAR local_208 [256];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_210 = param_1;
  iVar2 = (**(code **)(*in_ECX + 0x14))();
  FUN_0082ef00(&local_210);
  if (((local_20c != *(int *)(iVar2 + 8)) && (iVar2 = *(int *)(local_20c + 0x10), iVar2 != 0)) &&
     (*(int **)(iVar2 + 0x60) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar2 + 0x60) + 0x74))(iVar2);
  }
  piVar3 = (int *)(**(code **)(*in_ECX + 0x14))();
  cVar1 = (**(code **)(*piVar3 + 0x30))(param_1);
  if (cVar1 == '\0') {
    uVar4 = (**(code **)(*in_ECX + 0x1c))(param_1);
    FUN_0040aeb0(L"Can\'t Load Resource : [%d] %s",param_1,uVar4);
    MessageBoxW((HWND)0x0,local_208,L"Error",0);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

