
void FUN_00763630(int param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *****pppppuVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  char *_Str1;
  int *in_ECX;
  char *****_Str2;
  undefined1 auStack_94 [4];
  int iStack_90;
  int iStack_8c;
  int *local_88;
  int iStack_84;
  int iStack_80;
  int *piStack_7c;
  char ****local_70 [4];
  undefined4 uStack_60;
  uint local_5c;
  undefined4 ****appppuStack_54 [4];
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 local_38 [5];
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = -1;
  puStack_10 = &LAB_00920b18;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_94;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff60;
  ExceptionList = &local_14;
  if (param_1 != 0) {
    local_88 = in_ECX;
    FUN_00764d80(local_38,L"UNKNOWN",uVar2);
    local_c = 0;
    uVar3 = FUN_0044fa80(local_70,in_ECX + 0xb,local_38);
    local_c._0_1_ = 1;
    FUN_00402800(uVar3);
    local_c._0_1_ = 0;
    if (7 < local_5c) {
      FUN_0089120c(local_70[0]);
    }
    uVar3 = FUN_00764d80(local_70,&DAT_00bed1fc,uVar2);
    local_c._0_1_ = 2;
    FUN_00402800(uVar3);
    local_c = (uint)local_c._1_3_ << 8;
    if (7 < local_5c) {
      FUN_0089120c(local_70[0]);
    }
    FUN_004297b0();
    pppppuVar4 = (undefined4 *****)appppuStack_54[0];
    if (uStack_40 < 0x10) {
      pppppuVar4 = appppuStack_54;
    }
    iVar5 = FUN_0072e2e0(pppppuVar4);
    if (0xf < uStack_40) {
      FUN_0089120c(appppuStack_54[0]);
    }
    uStack_40 = 0xf;
    uStack_44 = 0;
    appppuStack_54[0] = (undefined4 ****)((uint)appppuStack_54[0] & 0xffffff00);
    while (iStack_8c = iVar5, iVar5 != 0) {
      iStack_90 = 0;
      FUN_00429860(&iStack_90);
      piVar6 = (int *)(**(code **)(*in_ECX + 0x20))(iStack_90);
      if (piVar6 == (int *)0x0) {
joined_r0x007638f5:
        if (7 < uStack_24) {
          FUN_0089120c(local_38[0]);
        }
        goto LAB_00763906;
      }
      iStack_90 = 0;
      FUN_00429860(&iStack_90);
      iVar7 = (**(code **)(*piVar6 + 4))();
      if ((iStack_90 != iVar7) || (cVar1 = (**(code **)(*piVar6 + 0x14))(iVar5), cVar1 == '\0'))
      goto joined_r0x007638f5;
      iVar5 = 0;
      if (in_ECX[0x14] != 0) {
        iStack_90 = in_ECX[0x13];
        FUN_0053f8a0();
        iVar5 = *(int *)(iStack_90 + 0xc) + 1;
      }
      iStack_90 = iVar5;
      FUN_0082ef00(&iStack_90);
      if (iStack_84 == local_88[0x13]) {
        piVar6[2] = (int)local_88;
        iStack_80 = iVar5;
        piStack_7c = piVar6;
        uVar3 = FUN_0057ef20();
        FUN_0082f200(in_ECX + 0x12,uVar3);
      }
      FUN_004297b0();
      _Str2 = (char *****)local_70[0];
      if (local_5c < 0x10) {
        _Str2 = local_70;
      }
      for (iVar5 = *(int *)(iStack_8c + 0x40); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x40)) {
        _Str1 = (char *)(iVar5 + 0x20);
        if (0xf < *(uint *)(iVar5 + 0x34)) {
          _Str1 = *(char **)_Str1;
        }
        iVar7 = __stricmp(_Str1,(char *)_Str2);
        if (iVar7 == 0) goto LAB_007638b4;
      }
      iVar5 = 0;
LAB_007638b4:
      if (0xf < local_5c) {
        FUN_0089120c(local_70[0]);
      }
      local_5c = 0xf;
      uStack_60 = 0;
      local_70[0] = (char ****)((uint)local_70[0] & 0xffffff00);
      in_ECX = local_88;
    }
    if (7 < uStack_24) {
      FUN_0089120c(local_38[0]);
    }
  }
LAB_00763906:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_94);
  return;
}

