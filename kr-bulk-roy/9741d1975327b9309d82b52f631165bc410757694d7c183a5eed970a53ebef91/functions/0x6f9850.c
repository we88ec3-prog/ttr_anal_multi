
/* WARNING: Type propagation algorithm not settling */

void FUN_006f9850(undefined4 param_1,double *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int local_80 [30];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_80[1] = 0;
  local_80[2] = 0;
  local_80[3] = 0;
  local_80[4] = 0;
  local_80[5] = 0;
  local_80[6] = 0;
  local_80[7] = 0;
  local_80[8] = 0;
  local_80[9] = 0;
  local_80[10] = 0;
  local_80[0xb] = 0;
  local_80[0xc] = 0;
  local_80[0xd] = 0;
  local_80[0xe] = 0;
  local_80[0xf] = 0;
  local_80[0x10] = 0;
  local_80[0x11] = 0;
  local_80[0x12] = 0;
  local_80[0x13] = 0;
  local_80[0x14] = 0;
  local_80[0x15] = 0;
  local_80[0x16] = 0;
  local_80[0x17] = 0;
  local_80[0x18] = 0;
  local_80[0x19] = 0;
  local_80[0x1a] = 0;
  local_80[0x1b] = 0;
  iVar1 = FUN_006f93c0();
  local_80[0] = iVar1;
  iVar2 = FUN_006f9440(local_80 + 1,local_80);
  if ((((*(int *)(param_2 + 1) == 3) && (iVar4 = (int)ROUND(*param_2), *param_2 == (double)iVar4))
      && (0 < iVar4)) && (iVar4 < 0x4000001)) {
    iVar5 = -1;
    for (uVar3 = iVar4 - 1; 0xff < uVar3; uVar3 = uVar3 >> 8) {
      iVar5 = iVar5 + 8;
    }
    local_80[(uint)(byte)(&DAT_00c0bfd8)[uVar3] + iVar5 + 2] =
         local_80[(uint)(byte)(&DAT_00c0bfd8)[uVar3] + iVar5 + 2] + 1;
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
  local_80[0] = local_80[0] + iVar4;
  iVar4 = FUN_006f9340(local_80 + 1,local_80);
  FUN_006f9630(param_1,local_80[0],((iVar1 + iVar2) - iVar4) + 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

