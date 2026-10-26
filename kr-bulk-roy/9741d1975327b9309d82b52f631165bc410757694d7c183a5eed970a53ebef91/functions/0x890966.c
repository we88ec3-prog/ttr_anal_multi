
/* WARNING: Removing unreachable block (ram,0x00890aef) */
/* Library Function - Single Match
    __Stoullx
   
   Library: Visual Studio 2010 Release */

ulonglong __Stoullx(byte *param_1,undefined4 *param_2,size_t param_3,undefined4 *param_4)

{
  byte bVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  longlong lVar10;
  ulonglong uVar11;
  size_t sVar12;
  int local_1c;
  int local_18;
  char local_6;
  byte local_5;
  
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  bVar1 = *param_1;
  pbVar7 = param_1;
  while (iVar4 = _isspace((uint)bVar1), iVar4 != 0) {
    pbVar7 = pbVar7 + 1;
    bVar1 = *pbVar7;
  }
  local_5 = *pbVar7;
  if ((local_5 == 0x2d) || (local_5 == 0x2b)) {
    pbVar7 = pbVar7 + 1;
  }
  else {
    local_5 = 0x2b;
  }
  if ((((int)param_3 < 0) || (param_3 == 1)) || (0x24 < (int)param_3)) goto LAB_00890b5d;
  pbVar8 = pbVar7;
  if ((int)param_3 < 1) {
    if (*pbVar7 == 0x30) {
      if ((pbVar7[1] == 0x78) || (pbVar7[1] == 0x58)) {
        param_3 = 0x10;
        goto LAB_00890a0a;
      }
      param_3 = 8;
    }
    else {
      param_3 = 10;
    }
  }
  else if (((param_3 == 0x10) && (*pbVar7 == 0x30)) && ((pbVar7[1] == 0x78 || (pbVar7[1] == 0x58))))
  {
LAB_00890a0a:
    pbVar7 = pbVar7 + 2;
    pbVar8 = pbVar7;
  }
  for (; *pbVar7 == 0x30; pbVar7 = pbVar7 + 1) {
  }
  local_6 = '\0';
  sVar12 = param_3;
  iVar4 = _tolower((int)(char)*pbVar7);
  pvVar5 = _memchr("0123456789abcdefghijklmnopqrstuvwxyz",iVar4,sVar12);
  pbVar9 = pbVar7;
  uVar11 = 0;
  uVar3 = 0;
  while (uVar2 = uVar11, pvVar5 != (void *)0x0) {
    local_6 = (char)pvVar5 + -0x58;
    lVar10 = __allmul(param_3,(int)param_3 >> 0x1f,uVar2);
    pbVar9 = pbVar9 + 1;
    sVar12 = param_3;
    iVar4 = _tolower((int)(char)*pbVar9);
    pvVar5 = _memchr("0123456789abcdefghijklmnopqrstuvwxyz",iVar4,sVar12);
    uVar11 = lVar10 + (int)local_6;
    uVar3 = uVar2;
  }
  if (pbVar8 != pbVar9) {
    iVar4 = (int)(pbVar9 + -(int)(char)(&DAT_00bd3580)[param_3]) - (int)pbVar7;
    if ((-1 < iVar4) &&
       (((pbVar9 + -(int)(char)(&DAT_00bd3580)[param_3] != pbVar7 && -1 < iVar4 ||
         (uVar2 < uVar2 - (longlong)(int)local_6)) ||
        (uVar11 = __aulldiv(uVar2 - (longlong)(int)local_6,param_3,(int)param_3 >> 0x1f),
        uVar11 != uVar3)))) {
      piVar6 = __errno();
      *piVar6 = 0x22;
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 1;
      }
      uVar2 = 0xffffffffffffffff;
      local_5 = 0x2b;
    }
    local_18 = (int)(uVar2 >> 0x20);
    local_1c = (int)uVar2;
    if (local_5 == 0x2d) {
      uVar2 = CONCAT44(-(local_18 + (uint)(local_1c != 0)),-local_1c);
    }
    if (param_2 == (undefined4 *)0x0) {
      return uVar2;
    }
    *param_2 = pbVar9;
    return uVar2;
  }
LAB_00890b5d:
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_1;
  }
  return 0;
}

