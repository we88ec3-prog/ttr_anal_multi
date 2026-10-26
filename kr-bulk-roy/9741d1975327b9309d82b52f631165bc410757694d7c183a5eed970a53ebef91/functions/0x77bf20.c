
void FUN_0077bf20(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 ******ppppppuVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  char *_Str1;
  int *in_ECX;
  int iVar7;
  char ******_Str2;
  undefined1 auStack_64 [4];
  int local_60;
  int *local_5c;
  int iStack_58;
  int iStack_54;
  int *piStack_50;
  undefined4 *****local_44 [4];
  undefined4 local_34;
  uint local_30;
  char *****apppppcStack_28 [4];
  undefined4 uStack_18;
  uint uStack_14;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_64;
  if (param_1 == 0) {
LAB_0077c132:
    __security_check_cookie(local_c ^ (uint)auStack_64);
    return;
  }
  local_5c = in_ECX;
  iVar2 = FUN_00764fb0(in_ECX[2]);
  in_ECX[2] = iVar2;
  FUN_004297b0();
  ppppppuVar3 = (undefined4 ******)local_44[0];
  if (local_30 < 0x10) {
    ppppppuVar3 = local_44;
  }
  iVar2 = FUN_0072e2e0(ppppppuVar3);
  if (0xf < local_30) {
    FUN_0089120c(local_44[0]);
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44[0] = (undefined4 *****)((uint)local_44[0] & 0xffffff00);
  do {
    if (iVar2 == 0) {
      __security_check_cookie(local_c ^ (uint)auStack_64);
      return;
    }
    local_60 = 0;
    FUN_00429860(&local_60);
    piVar4 = (int *)(**(code **)(*in_ECX + 0x20))(local_60);
    iVar7 = 0;
    if (piVar4 != (int *)0x0) {
      local_60 = 0;
      FUN_00429860(&local_60);
      iVar5 = (**(code **)(*piVar4 + 4))();
      if ((local_60 != iVar5) || (cVar1 = (**(code **)(*piVar4 + 0x14))(iVar2), cVar1 == '\0'))
      goto LAB_0077c132;
      if (local_5c[5] != 0) {
        local_60 = local_5c[4];
        FUN_0053f8a0();
        iVar7 = *(int *)(local_60 + 0xc) + 1;
      }
      local_60 = iVar7;
      FUN_0082ef00(&local_60);
      if (iStack_58 == local_5c[4]) {
        iStack_54 = iVar7;
        piStack_50 = piVar4;
        uVar6 = FUN_0057ef20();
        FUN_0082f200(local_5c + 3,uVar6);
      }
    }
    FUN_004297b0();
    _Str2 = (char ******)apppppcStack_28[0];
    if (uStack_14 < 0x10) {
      _Str2 = apppppcStack_28;
    }
    for (iVar2 = *(int *)(iVar2 + 0x40); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x40)) {
      _Str1 = (char *)(iVar2 + 0x20);
      if (0xf < *(uint *)(iVar2 + 0x34)) {
        _Str1 = *(char **)_Str1;
      }
      iVar7 = __stricmp(_Str1,(char *)_Str2);
      if (iVar7 == 0) goto LAB_0077c0e4;
    }
    iVar2 = 0;
LAB_0077c0e4:
    if (0xf < uStack_14) {
      FUN_0089120c(apppppcStack_28[0]);
    }
    uStack_14 = 0xf;
    uStack_18 = 0;
    apppppcStack_28[0] = (char *****)((uint)apppppcStack_28[0] & 0xffffff00);
    in_ECX = local_5c;
  } while( true );
}

