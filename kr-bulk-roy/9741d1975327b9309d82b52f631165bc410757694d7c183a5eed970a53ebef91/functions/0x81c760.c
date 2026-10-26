
void FUN_0081c760(int param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  char *_Str1;
  int iVar6;
  undefined4 uVar7;
  undefined **local_90 [19];
  uint local_44;
  undefined4 local_34;
  uint local_30;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092610b;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar3;
  FUN_0072ee30(local_90);
  local_8 = 0;
  cVar2 = FUN_0072f110(0);
  if (cVar2 == '\0') {
    local_8 = 0xffffffff;
    local_90[0] = TiXmlDocument::vftable;
    if (0xf < local_30) {
      FUN_0089120c(local_44);
    }
  }
  else {
    iVar4 = FUN_0072e360(uVar3);
    if ((iVar4 != 0) && (iVar4 = FUN_0072e360(uVar3), iVar4 != 0)) {
      do {
        iVar4 = FUN_007300a0(&DAT_00bfb82c);
        if (iVar4 != 0) {
          puVar5 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 != (undefined4 *)0x0) {
            FUN_008917b4(puVar5);
          }
        }
        iVar4 = FUN_0072e360();
        while (iVar4 != 0) {
          for (iVar1 = *(int *)(iVar4 + 0x94); iVar1 != iVar4 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)
              ) {
            _Str1 = (char *)(iVar1 + 0x14);
            if (0xf < *(uint *)(iVar1 + 0x28)) {
              _Str1 = *(char **)_Str1;
            }
            iVar6 = __stricmp(_Str1,"ID");
            if (iVar6 == 0) {
              if (iVar1 != 0) {
                puVar5 = (undefined4 *)(iVar1 + 0x30);
                if (0xf < *(uint *)(iVar1 + 0x44)) {
                  puVar5 = (undefined4 *)*puVar5;
                }
                if (puVar5 != (undefined4 *)0x0) {
                  FUN_008917b4(puVar5);
                }
              }
              break;
            }
          }
          iVar4 = FUN_0072e3c0();
        }
        uVar7 = FUN_0081e1b0();
        FUN_0081dad0(param_1 + 0x10,uVar7);
        iVar4 = FUN_0072e3c0();
      } while (iVar4 != 0);
    }
    local_90[0] = TiXmlDocument::vftable;
    local_8 = 0xffffffff;
    if (0xf < local_30) {
      local_8 = 0xffffffff;
      local_90[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_44);
    }
  }
  local_34 = 0;
  local_30 = 0xf;
  local_44 = local_44 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

