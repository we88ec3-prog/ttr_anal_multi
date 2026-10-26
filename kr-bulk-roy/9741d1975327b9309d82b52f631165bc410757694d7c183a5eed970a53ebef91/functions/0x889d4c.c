
void FUN_00889d4c(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined4 param_5,double param_6)

{
  int iVar1;
  char *_Format;
  undefined4 in_ECX;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  uint local_8c;
  uint local_88;
  uint local_84;
  char local_7c [112];
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = *(int *)(param_4 + 0x1c);
  uVar2 = *(uint *)(param_4 + 0x18);
  if ((iVar1 < 1) && (((iVar1 < 0 || (uVar2 == 0)) && ((*(uint *)(param_4 + 0x14) & 0x2000) == 0))))
  {
    uVar2 = 6;
    iVar1 = 0;
  }
  local_8c = uVar2;
  if ((-1 < iVar1) && ((0 < iVar1 || (0x24 < uVar2)))) {
    local_8c = 0x24;
  }
  uVar3 = uVar2 - local_8c;
  local_c = (iVar1 - ((int)local_8c >> 0x1f)) - (uint)(uVar2 < local_8c);
  local_84 = 0;
  local_88 = 0;
  if (((*(uint *)(param_4 + 0x14) & 0x3000) == 0x2000) && (param_6 != param_6 * 0.5)) {
    bVar5 = param_6 < 0.0;
    if (bVar5) {
      param_6 = -param_6;
    }
    if (!NAN(param_6) && 1e+35 < param_6 != (param_6 == 1e+35)) {
      do {
        if (4999 < local_84) break;
        param_6 = param_6 / 10000000000.0;
        local_84 = local_84 + 10;
      } while (1e+35 < param_6 != (param_6 == 1e+35));
    }
    if ((0.0 < param_6) && (-1 < local_c)) {
      if (0 < local_c) goto LAB_00889e64;
      while (9 < uVar3) {
LAB_00889e64:
        do {
          if ((1e-35 < param_6) || (4999 < local_88)) goto LAB_00889e92;
          bVar4 = 9 < uVar3;
          uVar3 = uVar3 - 10;
          param_6 = param_6 * 10000000000.0;
          local_c = local_c + -1 + (uint)bVar4;
          local_88 = local_88 + 10;
        } while (0 < local_c);
        if (local_c < 0) break;
      }
    }
LAB_00889e92:
    if (bVar5) {
      param_6 = -param_6;
    }
  }
  _Format = (char *)Ffmt();
  iVar1 = _sprintf_s(local_7c,0x6c,_Format,local_8c,param_6);
  Fput(in_ECX,param_1,param_2,param_3,param_4,param_5,local_7c,local_84,local_88,uVar3,iVar1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

