
void FUN_008bc310(undefined4 param_1,undefined4 param_2,int param_3,int *param_4,int *param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  int local_2c;
  char local_28 [32];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar2 = FUN_008b97e0(param_2,param_3);
  if ((iVar2 == 0) && (iVar2 = FUN_008bab70(param_2,local_28 + 0x10,0x10), iVar2 == 0)) {
    iVar3 = CONCAT31(CONCAT21(CONCAT11(local_28[0x10],local_28[0x11]),local_28[0x12]),local_28[0x13]
                    ) + param_3;
    *param_5 = iVar3;
    iVar2 = CONCAT31(CONCAT21(CONCAT11(local_28[0x14],local_28[0x15]),local_28[0x16]),local_28[0x17]
                    ) + param_3;
    if ((CONCAT31(CONCAT21(CONCAT11(local_28[0x18],local_28[0x19]),local_28[0x1a]),local_28[0x1b]) +
         iVar3 == iVar2) &&
       ((iVar2 != param_3 && (iVar3 = FUN_008b97e0(param_2,iVar2), iVar3 == 0)))) {
      local_28[0xf] = local_28[0x1f] + '\x01';
      iVar3 = FUN_008bab70(param_2,local_28,0x10);
      if (iVar3 == 0) {
        bVar5 = true;
        bVar1 = true;
        iVar3 = 0;
        do {
          if (local_28[iVar3] != '\0') {
            bVar5 = false;
          }
          if (local_28[iVar3] != local_28[iVar3 + 0x10]) {
            bVar1 = false;
          }
          if (local_28[iVar3 + 1] != '\0') {
            bVar5 = false;
          }
          if (local_28[iVar3 + 1] != local_28[iVar3 + 0x11]) {
            bVar1 = false;
          }
          if (local_28[iVar3 + 2] != '\0') {
            bVar5 = false;
          }
          if (local_28[iVar3 + 2] != local_28[iVar3 + 0x12]) {
            bVar1 = false;
          }
          if (local_28[iVar3 + 3] != '\0') {
            bVar5 = false;
          }
          if (local_28[iVar3 + 3] != local_28[iVar3 + 0x13]) {
            bVar1 = false;
          }
          iVar3 = iVar3 + 4;
        } while (iVar3 < 0x10);
        if ((bVar5) || (bVar1)) {
          local_2c = FUN_008b9820(param_2,8);
          uVar4 = FUN_008b9ab0(param_2,&local_2c);
          if ((local_2c == 0) && ((uVar4 & 0xffff) != 0xffffffff)) {
            iVar2 = (uVar4 & 0xffff) + iVar2;
            iVar3 = FUN_008b97e0(param_2,iVar2);
            if (iVar3 == 0) {
              *param_4 = iVar2;
              __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
              return;
            }
          }
        }
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

