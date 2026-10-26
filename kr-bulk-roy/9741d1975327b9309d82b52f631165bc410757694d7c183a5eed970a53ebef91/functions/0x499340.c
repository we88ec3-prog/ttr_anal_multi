
void FUN_00499340(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  undefined4 in_ECX;
  char *unaff_ESI;
  undefined1 local_42c [12];
  undefined4 local_420;
  undefined4 local_41c;
  char *local_418;
  undefined4 local_414;
  byte local_410 [1028];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((unaff_ESI == (char *)0x0) || (param_1 == 0)) {
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  if ((*unaff_ESI == 'E') && (unaff_ESI[1] == 'X')) {
    local_418 = unaff_ESI + *(int *)(unaff_ESI + 0xc);
    local_420 = in_ECX;
    local_414 = FUN_0087dc3d(*(undefined4 *)(unaff_ESI + 8));
    local_41c = *(undefined4 *)(unaff_ESI + 8);
    if (unaff_ESI[2] == '\x01') {
      local_410[0] = 0x30;
      local_410[1] = 0xe7;
      _memset(local_410 + 2,0,0x3fe);
      iVar2 = 2;
      do {
        cVar4 = *(char *)((int)&local_414 + iVar2 + 2) + *(char *)((int)&local_414 + iVar2 + 3);
        local_410[iVar2] = cVar4 + 0x13;
        if (iVar2 == 0x17c) {
          local_410[0x17c] = cVar4 + -0x43;
        }
        cVar4 = *(char *)((int)&local_414 + iVar2 + 3) + local_410[iVar2];
        local_410[iVar2 + 1] = cVar4 + 0x13;
        if (iVar2 == 0x17b) {
          local_410[0x17c] = cVar4 + -0x43;
        }
        iVar2 = iVar2 + 2;
      } while (iVar2 < 0x400);
      uVar3 = 0;
      if (0 < *(int *)(unaff_ESI + 4)) {
        do {
          local_418[uVar3] = local_418[uVar3] ^ local_410[uVar3 & 0x3ff];
          uVar3 = uVar3 + 1;
        } while ((int)uVar3 < *(int *)(unaff_ESI + 4));
      }
    }
    uVar1 = local_414;
    FUN_00727190(local_414);
    FUN_0071bcf0(local_420,local_42c,*(undefined4 *)(unaff_ESI + 8));
    FUN_00891d3d(uVar1);
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_0071bcf0(in_ECX,local_42c,param_1);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

