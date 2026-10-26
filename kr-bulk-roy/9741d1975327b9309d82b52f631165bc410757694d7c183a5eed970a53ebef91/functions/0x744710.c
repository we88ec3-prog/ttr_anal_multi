
void FUN_00744710(void)

{
  char cVar1;
  undefined4 ******ppppppuVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  char *_Str1;
  int in_ECX;
  char ******_Str2;
  int local_4c;
  int local_48;
  int local_44;
  char *****local_40 [4];
  undefined4 local_30;
  uint local_2c;
  undefined4 *****local_24 [4];
  undefined4 local_14;
  uint local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_48 = in_ECX;
  FUN_00429860(in_ECX + 0x8c);
  FUN_00429860(in_ECX + 0x90);
  FUN_004297b0();
  ppppppuVar2 = (undefined4 ******)local_24[0];
  if (local_10 < 0x10) {
    ppppppuVar2 = local_24;
  }
  iVar3 = FUN_0072e2e0(ppppppuVar2);
  if (0xf < local_10) {
    FUN_0089120c(local_24[0]);
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24[0] = (undefined4 *****)((uint)local_24[0] & 0xffffff00);
  do {
    if (iVar3 == 0) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_44 = 0;
    local_4c = 0;
    FUN_00429860(&local_44);
    FUN_00429860(&local_4c);
    piVar4 = (int *)FUN_0076f140(local_44);
    if (piVar4 != (int *)0x0) {
      local_44 = 0;
      FUN_00429860(&local_44);
      iVar5 = (**(code **)(*piVar4 + 4))();
      if ((local_44 != iVar5) || (cVar1 = (**(code **)(*piVar4 + 0x14))(iVar3), cVar1 == '\0')) {
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      *(int **)(local_48 + 0x94 + local_4c * 4) = piVar4;
    }
    FUN_004297b0();
    _Str2 = (char ******)local_40[0];
    if (local_2c < 0x10) {
      _Str2 = local_40;
    }
    for (iVar3 = *(int *)(iVar3 + 0x40); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x40)) {
      _Str1 = (char *)(iVar3 + 0x20);
      if (0xf < *(uint *)(iVar3 + 0x34)) {
        _Str1 = *(char **)_Str1;
      }
      iVar5 = __stricmp(_Str1,(char *)_Str2);
      if (iVar5 == 0) goto LAB_00744871;
    }
    iVar3 = 0;
LAB_00744871:
    if (0xf < local_2c) {
      FUN_0089120c(local_40[0]);
    }
    local_2c = 0xf;
    local_30 = 0;
    local_40[0] = (char *****)((uint)local_40[0] & 0xffffff00);
  } while( true );
}

