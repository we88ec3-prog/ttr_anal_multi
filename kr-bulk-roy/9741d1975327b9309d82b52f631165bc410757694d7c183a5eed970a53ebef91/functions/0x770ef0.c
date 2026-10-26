
void FUN_00770ef0(int param_1)

{
  char cVar1;
  undefined4 ******ppppppuVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  char *_Str1;
  int *in_ECX;
  int iVar7;
  char ******_Str2;
  int local_50;
  int local_48;
  undefined4 *****local_44 [4];
  undefined4 local_34;
  uint local_30;
  char *****local_28 [4];
  undefined4 local_18;
  uint local_14;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (param_1 != 0) {
    FUN_004297b0();
    ppppppuVar2 = (undefined4 ******)local_44[0];
    if (local_30 < 0x10) {
      ppppppuVar2 = local_44;
    }
    iVar3 = FUN_0072e2e0(ppppppuVar2);
    if (0xf < local_30) {
      FUN_0089120c(local_44[0]);
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44[0] = (undefined4 *****)((uint)local_44[0] & 0xffffff00);
    while( true ) {
      if (iVar3 == 0) {
        __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
        return;
      }
      local_48 = 0;
      FUN_00429860(&local_48);
      piVar4 = (int *)(**(code **)(*in_ECX + 0x28))(local_48);
      iVar7 = 0;
      if (piVar4 == (int *)0x0) break;
      local_48 = 0;
      FUN_00429860(&local_48);
      iVar5 = (**(code **)(*piVar4 + 4))();
      if ((local_48 != iVar5) || (cVar1 = (**(code **)(*piVar4 + 0x14))(iVar3), cVar1 == '\0'))
      break;
      if (in_ECX[3] != 0) {
        local_48 = in_ECX[2];
        FUN_0053f8a0();
        iVar7 = *(int *)(local_48 + 0xc) + 1;
      }
      local_48 = iVar7;
      FUN_0082ef00(&local_48);
      if (local_50 == in_ECX[2]) {
        uVar6 = FUN_0057ef20();
        FUN_0082f200(in_ECX + 1,uVar6);
      }
      FUN_004297b0();
      _Str2 = (char ******)local_28[0];
      if (local_14 < 0x10) {
        _Str2 = local_28;
      }
      for (iVar3 = *(int *)(iVar3 + 0x40); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x40)) {
        _Str1 = (char *)(iVar3 + 0x20);
        if (0xf < *(uint *)(iVar3 + 0x34)) {
          _Str1 = *(char **)_Str1;
        }
        iVar7 = __stricmp(_Str1,(char *)_Str2);
        if (iVar7 == 0) goto LAB_00771071;
      }
      iVar3 = 0;
LAB_00771071:
      if (0xf < local_14) {
        FUN_0089120c(local_28[0]);
      }
      local_14 = 0xf;
      local_18 = 0;
      local_28[0] = (char *****)((uint)local_28[0] & 0xffffff00);
    }
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

