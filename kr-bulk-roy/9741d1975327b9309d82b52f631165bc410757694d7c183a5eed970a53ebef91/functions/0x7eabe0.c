
void FUN_007eabe0(undefined4 param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  undefined4 ***pppuVar6;
  int *_Str1;
  char *pcVar7;
  undefined4 **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917838;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if (param_2 != 0) {
    piVar3 = (int *)FUN_0072e2e0("Object");
joined_r0x007eac2a:
    if (piVar3 != (int *)0x0) {
      iVar4 = (**(code **)(*piVar3 + 0x14))(uVar2);
      if (iVar4 != 0) {
        iVar4 = FUN_007300a0(&DAT_00c0f680);
        if (iVar4 == 0) {
          pcVar7 = (char *)0x0;
        }
        else {
          pcVar7 = (char *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            pcVar7 = *(char **)pcVar7;
          }
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffffff00);
        pcVar5 = pcVar7;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar7,(int)pcVar5 - (int)(pcVar7 + 1));
        local_8 = 0;
        pppuVar6 = (undefined4 ***)local_30[0];
        if (local_1c < 0x10) {
          pppuVar6 = local_30;
        }
        FUN_007b8fd0(pppuVar6);
        local_8 = 0xffffffff;
        if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffffff00);
      }
      for (piVar3 = (int *)piVar3[0x10]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[0x10]) {
        _Str1 = piVar3 + 8;
        if (0xf < (uint)piVar3[0xd]) {
          _Str1 = (int *)*_Str1;
        }
        iVar4 = __stricmp((char *)_Str1,"Object");
        if (iVar4 == 0) goto joined_r0x007eac2a;
      }
      piVar3 = (int *)0x0;
      goto joined_r0x007eac2a;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

