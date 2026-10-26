
void FUN_004405c0(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  LPCSTR ***lpFileName;
  int in_ECX;
  uint local_74 [4];
  undefined4 local_64;
  uint local_60;
  LPCSTR **local_58 [5];
  uint uStack_44;
  int iStack_3c;
  undefined4 local_38;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00917b28;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)local_74;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff80;
  ExceptionList = &local_14;
  iVar1 = *(int *)(in_ECX + 8);
  if (iVar1 == 0x40) {
    FUN_006edd50();
    local_c = 0;
    FUN_00440850(0,0,uVar2);
    local_c._0_1_ = 1;
    uVar3 = FUN_006ede70(local_58);
    local_c = CONCAT31(local_c._1_3_,2);
    FUN_00402bb0(uVar3);
    if (0xf < local_60) {
      FUN_0089120c(local_74[0]);
    }
    local_60 = 0xf;
    local_64 = 0;
    local_74[0] = local_74[0] & 0xffffff00;
    if (0xf < local_24) {
      FUN_0089120c(local_38);
    }
    if (iStack_3c != 0) {
      lpFileName = (LPCSTR ***)local_58[0];
      if (uStack_44 < 0x10) {
        lpFileName = local_58;
      }
      WritePrivateProfileStringA((LPCSTR)0x0,(LPCSTR)0x0,(LPCSTR)0x0,(LPCSTR)lpFileName);
    }
    if (0xf < uStack_44) {
      FUN_0089120c(local_58[0]);
    }
  }
  else if (iVar1 == 0x52) {
    uVar3 = FUN_00440850(0x23,0xf4,uVar2);
    local_c = 3;
    FUN_00402bb0(uVar3);
    if (0xf < local_24) {
      FUN_0089120c(local_38);
    }
  }
  else if (iVar1 == 0x54) {
    uVar3 = FUN_00440850(0xda,4,uVar2);
    local_c = 4;
    FUN_00402bb0(uVar3);
    if (0xf < local_60) {
      FUN_0089120c(local_74[0]);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)local_74);
  return;
}

