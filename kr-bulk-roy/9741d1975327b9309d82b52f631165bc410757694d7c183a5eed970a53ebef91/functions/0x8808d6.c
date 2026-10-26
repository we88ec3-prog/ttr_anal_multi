
/* Library Function - Single Match
    __Stoulx
   
   Library: Visual Studio 2010 Release */

uint __Stoulx(byte *param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  char cVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  uint local_10;
  uint local_c;
  byte local_5;
  
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  bVar1 = *param_1;
  pbVar6 = param_1;
  while (iVar2 = _isspace((uint)bVar1), iVar2 != 0) {
    pbVar6 = pbVar6 + 1;
    bVar1 = *pbVar6;
  }
  local_5 = *pbVar6;
  if ((local_5 == 0x2d) || (local_5 == 0x2b)) {
    pbVar6 = pbVar6 + 1;
  }
  else {
    local_5 = 0x2b;
  }
  if ((((int)param_3 < 0) || (param_3 == 1)) || (0x24 < (int)param_3)) {
    if (param_2 == (undefined4 *)0x0) {
      return 0;
    }
    *param_2 = param_1;
    return 0;
  }
  pbVar7 = pbVar6;
  if ((int)param_3 < 1) {
    if (*pbVar6 != 0x30) {
      param_3 = 10;
      goto LAB_00880983;
    }
    if ((pbVar6[1] != 0x78) && (pbVar6[1] != 0x58)) {
      param_3 = 8;
      goto LAB_00880983;
    }
    param_3 = 0x10;
  }
  else if (((param_3 != 0x10) || (*pbVar6 != 0x30)) || ((pbVar6[1] != 0x78 && (pbVar6[1] != 0x58))))
  goto LAB_00880983;
  pbVar6 = pbVar6 + 2;
  pbVar7 = pbVar6;
LAB_00880983:
  for (; *pbVar6 == 0x30; pbVar6 = pbVar6 + 1) {
  }
  local_c = 0;
  local_10 = 0;
  uVar9 = param_3;
  iVar2 = _tolower((int)(char)*pbVar6);
  pvVar3 = _memchr("0123456789abcdefghijklmnopqrstuvwxyz",iVar2,uVar9);
  pbVar8 = pbVar6;
  if (pvVar3 == (void *)0x0) {
    cVar5 = param_3._3_1_;
  }
  else {
    do {
      cVar5 = (char)pvVar3 + 'x';
      local_10 = local_c;
      local_c = local_c * param_3 + (int)cVar5;
      pbVar8 = pbVar8 + 1;
      uVar9 = param_3;
      iVar2 = _tolower((int)(char)*pbVar8);
      pvVar3 = _memchr("0123456789abcdefghijklmnopqrstuvwxyz",iVar2,uVar9);
    } while (pvVar3 != (void *)0x0);
  }
  if (pbVar7 == pbVar8) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_1;
    }
    return 0;
  }
  iVar2 = (int)(pbVar8 + -(int)(char)(&DAT_00bd2eb0)[param_3]) - (int)pbVar6;
  if ((-1 < iVar2) &&
     (((pbVar8 + -(int)(char)(&DAT_00bd2eb0)[param_3] != pbVar6 && -1 < iVar2 ||
       (local_c < local_c - (int)cVar5)) || ((local_c - (int)cVar5) / param_3 != local_10)))) {
    piVar4 = __errno();
    *piVar4 = 0x22;
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 1;
    }
    local_c = 0xffffffff;
    local_5 = 0x2b;
  }
  if (local_5 == 0x2d) {
    local_c = -local_c;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = pbVar8;
    return local_c;
  }
  return local_c;
}

