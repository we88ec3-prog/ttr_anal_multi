
void FUN_00774d50(int *param_1,short *param_2)

{
  short sVar1;
  char cVar2;
  undefined4 ******ppppppuVar3;
  int iVar4;
  int *piVar5;
  short *psVar6;
  int iVar7;
  undefined4 uVar8;
  char *_Str1;
  int in_ECX;
  char ******_Str2;
  int local_54;
  int local_44;
  undefined4 *****local_40 [4];
  undefined4 local_30;
  uint local_2c;
  char *****local_24 [4];
  undefined4 local_14;
  uint local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (in_ECX != 0) {
    FUN_004297b0();
    ppppppuVar3 = (undefined4 ******)local_40[0];
    if (local_2c < 0x10) {
      ppppppuVar3 = local_40;
    }
    iVar4 = FUN_0072e2e0(ppppppuVar3);
    if (0xf < local_2c) {
      FUN_0089120c(local_40[0]);
    }
    local_2c = 0xf;
    local_30 = 0;
    local_40[0] = (undefined4 *****)((uint)local_40[0] & 0xffffff00);
    while( true ) {
      if (iVar4 == 0) {
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      local_44 = 0;
      FUN_00429860(&local_44);
      piVar5 = (int *)(**(code **)(*param_1 + 0x2c))(local_44);
      if (piVar5 == (int *)0x0) break;
      psVar6 = param_2;
      do {
        sVar1 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar1 != 0);
      FUN_00402160(param_2,(int)psVar6 - (int)(param_2 + 1) >> 1);
      local_44 = 0;
      FUN_00429860(&local_44);
      iVar7 = (**(code **)(*piVar5 + 4))();
      if ((local_44 != iVar7) || (cVar2 = (**(code **)(*piVar5 + 0x14))(iVar4), cVar2 == '\0'))
      break;
      local_44 = 0;
      if (param_1[3] != 0) {
        local_44 = param_1[2];
        FUN_0053f8a0();
        local_44 = *(int *)(local_44 + 0xc) + 1;
      }
      FUN_0082ef00(&local_44);
      if (local_54 == param_1[2]) {
        uVar8 = FUN_0057ef20();
        FUN_0082f200(param_1 + 1,uVar8);
      }
      FUN_004297b0();
      _Str2 = (char ******)local_24[0];
      if (local_10 < 0x10) {
        _Str2 = local_24;
      }
      for (iVar4 = *(int *)(iVar4 + 0x40); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x40)) {
        _Str1 = (char *)(iVar4 + 0x20);
        if (0xf < *(uint *)(iVar4 + 0x34)) {
          _Str1 = *(char **)_Str1;
        }
        iVar7 = __stricmp(_Str1,(char *)_Str2);
        if (iVar7 == 0) goto LAB_00774f01;
      }
      iVar4 = 0;
LAB_00774f01:
      if (0xf < local_10) {
        FUN_0089120c(local_24[0]);
      }
      local_10 = 0xf;
      local_14 = 0;
      local_24[0] = (char *****)((uint)local_24[0] & 0xffffff00);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

