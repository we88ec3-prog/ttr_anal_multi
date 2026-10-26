
void FUN_007b65b0(int param_1)

{
  int iVar1;
  void **ppvVar2;
  char cVar3;
  uint uVar4;
  DWORD DVar5;
  int iVar6;
  DWORD DVar7;
  uint uVar8;
  int local_3c;
  uint local_38 [4];
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00938188;
  local_1c = DAT_00d61f20 ^ (uint)&local_3c;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ppvVar2 = &local_14;
  local_14 = ExceptionList;
  local_3c = param_1;
  do {
    ExceptionList = ppvVar2;
    if (DAT_00fba834 == 0) {
      SetEvent(DAT_00d63c70);
      ExceptionList = local_14;
      __security_check_cookie(local_1c ^ (uint)&local_3c);
      return;
    }
    DVar5 = GetTickCount();
    iVar6 = FUN_007b6010(uVar4);
    DVar7 = GetTickCount();
    iVar1 = local_3c;
    uVar8 = DVar7 - DVar5;
    if (iVar6 == 0) {
      while( true ) {
        local_24 = 0xf;
        local_28 = 0;
        local_38[0] = local_38[0] & 0xffffff00;
        local_c = 0;
        cVar3 = FUN_007b6af0(local_38);
        if (cVar3 == '\0') break;
        FUN_007b5c90(iVar1);
        local_c = 0xffffffff;
        if (0xf < local_24) {
          FUN_0089120c(local_38[0]);
        }
        local_24 = 0xf;
        local_28 = 0;
        local_38[0] = local_38[0] & 0xffffff00;
        if (DAT_00fba834 == 0) {
LAB_007b66f2:
          DVar5 = 0x21;
          goto LAB_007b6736;
        }
        if (*(int *)(iVar1 + 8) != 0) {
          Sleep(10);
          goto LAB_007b66f2;
        }
        Sleep(1);
      }
      local_c = 0xffffffff;
      if (0xf < local_24) {
        FUN_0089120c(local_38[0]);
      }
      local_24 = 0xf;
      local_28 = 0;
      local_38[0] = local_38[0] & 0xffffff00;
      DVar5 = 0x21;
    }
    else if (*(int *)(local_3c + 0x90) == 2) {
      DVar5 = 1;
    }
    else if (uVar8 < 10) {
      DVar5 = 1;
    }
    else if (uVar8 < 0x14) {
      DVar5 = 5;
    }
    else if (uVar8 < 0x1e) {
      DVar5 = 10;
    }
    else if (uVar8 < 0x28) {
      DVar5 = 0x14;
    }
    else if (uVar8 < 0x32) {
      DVar5 = 0x19;
    }
    else {
      DVar5 = 0x1e;
    }
LAB_007b6736:
    Sleep(DVar5);
    ppvVar2 = ExceptionList;
  } while( true );
}

