
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_007bad20(int param_1,undefined4 *param_2,float param_3)

{
  int iVar1;
  undefined4 *in_ECX;
  int extraout_ECX;
  uint uVar2;
  int iStack_187c;
  undefined4 *local_1878;
  undefined4 *local_1874;
  undefined4 uStack_1870;
  undefined4 uStack_186c;
  undefined4 uStack_1868;
  int local_1864;
  int local_1860;
  undefined4 local_185c;
  undefined4 local_1858;
  undefined4 local_1854;
  undefined1 local_1850 [64];
  undefined1 auStack_1810 [6148];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&iStack_187c;
  local_1878 = param_2;
  if (*(int *)(param_1 + 0x40) != 0) {
    local_1864 = *(int *)(*(int *)(param_1 + 0x40) + 0x16c);
    local_1860 = *(int *)(*(int *)(param_1 + 0x40) + 0x170);
    if ((local_1864 != 0) && (local_1860 != 0)) {
      local_185c = 0x3f800000;
      local_1858 = 0;
      local_1854 = 0;
      local_1874 = in_ECX;
      if (param_3 != 0.0) {
        D3DXMatrixRotationZ(local_1850,param_3);
        D3DXVec3TransformCoord(&local_1864,&local_1864,&local_1858);
      }
      iStack_187c = FUN_00891268(0x3ed0);
      if (iStack_187c == 0) {
        iStack_187c = 0;
      }
      else {
        *(undefined4 *)(iStack_187c + 0x3ec4) = 0xf;
        *(undefined4 *)(iStack_187c + 0x3ec0) = 0;
        *(undefined1 *)(iStack_187c + 0x3eb0) = 0;
        *(undefined4 *)(iStack_187c + 0x3ecc) = 0;
      }
      uStack_1870 = 0;
      uStack_186c = 0;
      uStack_1868 = 0x3f800000;
      FUN_007d7360(local_1878,&uStack_1870,*in_ECX,*in_ECX,*in_ECX);
      uStack_1870 = *local_1878;
      uStack_186c = local_1878[1];
      FUN_007e76b0(auStack_1810,0xc00,&local_1874);
      FUN_007d7740(local_1874,auStack_1810,local_1860);
      uVar2 = 0;
      if (*(int *)(param_1 + 0xcc) - *(int *)(param_1 + 200) >> 2 != 0) {
        do {
          iVar1 = FUN_007e97b0(*local_1878,local_1878[1]);
          if (iVar1 != 0) {
            FUN_007d7740((*(int *)(extraout_ECX + 0x38) - *(int *)(extraout_ECX + 0x34)) / 6,
                         *(int *)(extraout_ECX + 0x34),*(undefined4 *)(extraout_ECX + 0x24));
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < (uint)(*(int *)(param_1 + 0xcc) - *(int *)(param_1 + 200) >> 2));
      }
      __security_check_cookie(local_c ^ (uint)&iStack_187c);
      return;
    }
  }
  __security_check_cookie(local_c ^ (uint)&iStack_187c);
  return;
}

